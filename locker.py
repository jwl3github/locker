import random
import time
import pygame
from pygame import *
from xml.dom import minidom

COLORS = { 0: pygame.Color("black"),       # Correct
           1: pygame.Color("blue"),
           2: pygame.Color("green"),       # Correct
           3: pygame.Color("cyan"),        # Correct
           4: pygame.Color("red"),         # Correct
           5: pygame.Color("magenta"),
           6: pygame.Color("yellow"),      # Correct
           7: pygame.Color("white"),       # Correct
           37: pygame.Color("darkGray"),   # Correct, but looks same as gray?
           40: pygame.Color("gray"),       # Correct
           42: pygame.Color("lightGray") } # Correct

SCREEN_X         = 640
SCREEN_Y         = 480
GRID_X_SCALE     = 100.0
GRID_Y_SCALE     = 100.0
X_TRANSLATE_TEXT = -2.0
Y_TRANSLATE_TEXT = -9.0
locker           = None

# ==============================================================================
class Locker(object):
# ------------------------------------------------------------------------------
    def __init__(self, xml_file):
        pygame.init()
        self.DISPLAY    = None
        self.shapes     = []
        self.curr_group = 999   # Force next_group to show 0 at first call.
        self.all_groups = []
        self.load_xml_file(xml_file)
# ------------------------------------------------------------------------------
    def init_display(self):
        pygame.display.set_mode((SCREEN_X, SCREEN_Y), 0, 24)
        self.DISPLAY  = pygame.display.get_surface()
        self.font = { '':              pygame.font.SysFont("monospace", 15),
                      'Verdana Small': pygame.font.SysFont("Verdana Small", 15) }
# ------------------------------------------------------------------------------
    def redraw(self):
        if not self.DISPLAY:
            self.init_display()
        for s in self.shapes:
            stype = s[0]
            if COLORS.has_key(s[1]):
                color = COLORS[s[1]]
            else:
                print('missing color %d' % s[1])
                color = pygame.Color("pink")
            if stype == 'polygon':
                linew, points = s[2], s[3]
                ppoints = []
                for p in points:
                    ppoints.append(self.compute_point(p))
                pygame.draw.polygon(self.DISPLAY, color, ppoints, linew)
            elif stype == 'circle':
                linew, point, xrad, yrad = s[2:]
                display_pt  = self.compute_point(point)
                display_rad = self.compute_xlength(xrad)
                pygame.draw.circle(self.DISPLAY, color, display_pt, display_rad, linew)
            elif stype == 'text':
                linew, rot, font, scale, name, value, point, xjust, yjust = s[2:]
                if not self.font.has_key(font):
                    font = ''
                display_text = name if value.startswith('%') else value
                display_pt   = self.compute_text_point(point)
                label        = self.font[font].render(display_text, 1, color)
                #print 'text %15s @ (%s)' % (display_text, str(display_pt))
                self.DISPLAY.blit(label, display_pt)
            else:
                print('Do not yet support stype ' + stype)
        print('Number of shapes drawn: %d' % len(self.shapes))
        pygame.display.update()
# ------------------------------------------------------------------------------
    def compute_ylength(self, yscaled):
        return int(yscaled * GRID_Y_SCALE)
# ------------------------------------------------------------------------------
    def compute_xlength(self, xscaled):
        return int(xscaled * GRID_X_SCALE)
# ------------------------------------------------------------------------------
    def compute_point(self, point):
        xx           = abs((point[0] - self.grid_L) * GRID_X_SCALE)
        yy           = abs((point[1] - self.grid_T) * GRID_Y_SCALE)
        return (int(xx), int(yy))
# ------------------------------------------------------------------------------
    def compute_text_point(self, point):
        xx, yy = self.compute_point(point)
        xx += X_TRANSLATE_TEXT  # TODO fix hack
        yy += Y_TRANSLATE_TEXT  # TODO fix hack
        return (xx, yy)
# ------------------------------------------------------------------------------
    def load_xml_file(self, xml_file):
        self.curr_group = 0
        try:
            grid = self.xml_doc.getElementsByTagName('grid')
            self.grid_L = float(grid.getAttribute('left'))
            self.grid_R = float(grid.getAttribute('right'))
            self.grid_T = float(grid.getAttribute('top'))
            self.grid_B = float(grid.getAttribute('bottom'))
        except Exception as ex:
            print('Failed to load "grid"... applying defaults.')
            self.grid_L = -4.0
            self.grid_R =  4.0
            self.grid_T =  3.0
            self.grid_B = -3.0

        global GRID_X_SCALE, GRID_Y_SCALE

        grid_w       = abs(self.grid_L - self.grid_R)
        GRID_X_SCALE = SCREEN_X / grid_w
        grid_h       = abs(self.grid_T - self.grid_B)
        GRID_Y_SCALE = SCREEN_Y / grid_h

        try:
            self.xml_doc = minidom.parse(xml_file)
            self.all_groups = self.xml_doc.getElementsByTagName('group')
            print('all_groups = <%d>' % len(self.all_groups))
            #for grp in self.all_groups:
            #    if grp.hasAttribute('name'): print('attr<%s>' % grp.getAttribute('name'))
        except Exception as ex:
            print('Exception while loading XML file: ')
            print(ex)
# ------------------------------------------------------------------------------
    def get_group_by_name(self, group_name):
        for grp in self.all_groups:
            if grp.hasAttribute('name') and grp.getAttribute('name') == group_name:
                return grp
        return None
# ------------------------------------------------------------------------------
    def blit_group_by_name(self, group_name):
        grp = self.get_group_by_name(group_name)
        if grp:
            self.blit_group(grp)
        else:
            print('No such group: <%s>' % group_name)
# ------------------------------------------------------------------------------
    def blit_group(self, grp):
        #print(dir(grp))
        nodes = grp.childNodes
        group_shapes = []
        for n in nodes:
            tagName = getattr(n, 'tagName', '')
            shape   = None
            if   tagName == 'quad':       shape = self.process_polygon(n)
            elif tagName == 'point':      shape = self.process_point(n)
            elif tagName == 'polygon':    shape = self.process_polygon(n)
            elif tagName == 'circle':     shape = self.process_circle(n)
            elif tagName == 'text':       shape = self.process_text(n)
            elif tagName == 'group':      shape = self.blit_group(n)
            elif tagName == 'texture':    pass
            elif tagName == 'visibility':
                print('Ignoring group with "visibility" attrib.')
                return
            elif tagName == 'control':
                pass
                #print('Ignoring group with "control" attrib.')
                #return
            elif tagName == 'controlvis':
                pass
                #print('Ignoring group with "controlvis" attrib.')
                #return
            elif tagName:
                print('Cannot handle tagName: <%s>' % tagName)
            if shape:
                group_shapes.append(shape)
        self.shapes += group_shapes
        print('blit_group: Done <%s>' % grp.getAttribute('name'))
# ------------------------------------------------------------------------------
    def process_polygon(self, node):
        color, points, linewidth, filled = None, [], 0, None
        subnodes = node.childNodes
        for n in subnodes:
            tagName = getattr(n, 'tagName', '')
            if tagName == 'vertex':
                c = int(n.getAttribute('color'))
                x = float(n.getAttribute('x'))
                y = float(n.getAttribute('y'))
                points.append([x, y])
                if color == None: color = c
            elif tagName == 'linewidth':
                linewidth = n.getAttribute('index')
            elif tagName == 'fill':
                filled = n.getAttribute('filled')
            elif tagName == 'controlvis':
                print('Ignoring polygon with "controlvis" attrib.')
                return
        linewidth = 0 if filled else int(linewidth)
        shape     = ['polygon', int(color), linewidth, points]
        return shape
# ------------------------------------------------------------------------------
    def process_point(self, node):
        shape = None ## TODO
        return shape
# ------------------------------------------------------------------------------
    def process_circle(self, node):
        color = int   (node.getAttribute('color'))
        xrad  = float (node.getAttribute('xrad'))
        yrad  = float (node.getAttribute('yrad'))

        subnodes = node.childNodes
        for n in subnodes:
            tagName = getattr(n, 'tagName', '')
            if tagName == 'vertex':
                x = float(n.getAttribute('x'))
                y = float(n.getAttribute('y'))
            elif tagName == 'linewidth':
                linew = int(n.getAttribute('index'))
        shape = ['circle', color, linew, [x,y], xrad, yrad]
        return shape
# ------------------------------------------------------------------------------
    def process_text(self, node):

        name  =       (node.getAttribute('name'))
        value =       (node.getAttribute('value'))   # either a format like '%d' or same as 'name'
        color = int   (node.getAttribute('color'))
        rot   = float (node.getAttribute('rot'))
        font  =       (node.getAttribute('font'))
        scale = float (node.getAttribute('xscale'))
        xjust =       (node.getAttribute('xjust'))
        yjust =       (node.getAttribute('yjust'))
        x     = 0.0
        y     = 0.0
        linew = 0

        subnodes = node.childNodes
        for n in subnodes:
            tagName = getattr(n, 'tagName', '')
            if tagName == 'vertex':
                x = float(n.getAttribute('x'))
                y = float(n.getAttribute('y'))
            elif tagName == 'linewidth':
                linew = int(n.getAttribute('index'))
        shape = ['text', color, linew, rot, font, scale, name, value, [x,y], xjust, yjust]
        return shape
# ------------------------------------------------------------------------------
    def next_group(self):
        self.curr_group += 1
        if len(self.all_groups) <= self.curr_group:
            self.curr_group = 0
        self.blit_group(self.all_groups[self.curr_group])

# ==============================================================================
def start():
    global locker
    locker = Locker('Chads.IDL_XML')
    locker.blit_group_by_name('Status Area')
    locker.blit_group_by_name('MenuButton00')
    locker.blit_group_by_name('MenuButton01')
    locker.blit_group_by_name('MenuButton02')
    locker.blit_group_by_name('MenuButton03')
    locker.blit_group_by_name('MenuButton04')
    locker.blit_group_by_name('MenuButton05')
    locker.blit_group_by_name('MenuButton06')
    locker.blit_group_by_name('MenuButton07')
    locker.blit_group_by_name('MenuButton08')
    locker.blit_group_by_name('MenuButton09')
    locker.blit_group_by_name('SPDU')
    locker.redraw()
# ==============================================================================
start()
while True:
    event = pygame.event.wait()
    if event.type == QUIT:
        break
    elif event.type == KEYDOWN:
        try:
            key = chr(event.key)
        except:
            continue
        if key == 'z':
            locker.next_group()
            locker.redraw()
        elif key == 'y':
            for i in range(locker.curr_group, len(locker.all_groups)):
                locker.next_group()
            locker.redraw()
        else:
            print('Press "z" to draw next group or "y" for all groups.')

