from array import *
import pygame
import random

pygame.init()
lev = 3
wincondition = 3

xaxis = 1280
yaxis = 720
borderthick = int(xaxis/10)
borderlength = int(yaxis/10)
boxeswidth = int((xaxis-3*borderthick)/lev)
boxesheight = int((yaxis-3*borderlength)/lev)
player = ['X', 'O']

win = pygame.display.set_mode((xaxis, yaxis),pygame.FULLSCREEN)  # ,    pygame.FULLSCREEN)
pygame.display.set_caption("Tic Tac Toe")


class box():
    def __init__(self, x, y, width, height, val):
        self.x = x
        self.y = y
        self.width = width
        self.height = height
        self.val = val

    def reset(self, x, y, width, height, val):
        self.x = x
        self.y = y
        self.width = width
        self.height = height
        self.val = val

    def draw(self, win):
        font = pygame.font.SysFont('Ink Free', int(600/lev))
        text = font.render(self.val, 1, (255, 200, 0))
        win.blit(text, (self.x + (self.width/2 - text.get_width()/2),
                        self.y + (self.height/2 - text.get_height()/2)))

    def isOver(self, pos, val):
        if pos[0] > self.x and pos[0] < self.x + self.width:
            if pos[1] > self.y and pos[1] < self.y + self.height:
                if self.val == '':
                    self.val = val
                    return True
                else:
                    return False

    def __str__(self):
        return self.val


class key1():
    def __init__(self, color, x, y, width, height, text=''):
        self.color = color
        self.x = x
        self.y = y
        self.width = width
        self.height = height
        self.text = text

    def draw(self, win, outline=None, fontsize=25):
        # Call this method to draw the key1 on the screen
        outline = (
            abs(self.color[0] - 0), abs(self.color[1] - 0), abs(self.color[2] - 0))
        if outline:
            pygame.draw.rect(win, outline, (self.x-2, self.y -
                                            2, self.width+4, self.height+4), 0)

        pygame.draw.rect(win, self.color, (self.x, self.y,
                                           self.width, self.height), 0)

        if self.text != '':
            font = pygame.font.SysFont('Segoe Print', fontsize)
            text = font.render(self.text, 1, (abs(
                self.color[0] - 255), abs(self.color[1] - 255), abs(self.color[2] - 255)))
            win.blit(text, (self.x + (self.width/2 - text.get_width()/2),
                            self.y + (self.height/2 - text.get_height()/2)))

    def isOver(self, pos):
        # Pos is the mouse position or a tuple of (x,y) coordinates
        if pos[0] > self.x and pos[0] < self.x + self.width:
            if pos[1] > self.y and pos[1] < self.y + self.height:
                self.color = (0, 0, 0)
                return True

        self.color = (255, 0, 0)
        return False


class tb():
    def __init__(self, posx, posy, width, height, placeholder='Input Box', text='', isactive=False):
        self.posx = posx
        self.posy = posy
        self.width = width
        self.height = height
        self.placeholder = placeholder
        self.text = text
        self.isactive = isactive

    def isOver(self, pos):
        # Pos is the mouse position or a tuple of (x,y) coordinates
        if pos[0] > self.posx and pos[0] < self.posx + self.width:
            if pos[1] > self.posy and pos[1] < self.posy + self.height:
                self.isactive = True
                return True

        self.isactive = False
        return False

    def draw(self, win, outline=(255, 0, 0), fontsize=25):
        # Call this method to draw the key1 on the screen
        pygame.draw.rect(win, outline, (self.posx-5, self.posy -
                                        5, self.width+10, self.height+10), 0)
        pygame.draw.rect(win, (255, 0, 0), (self.posx-2, self.posy -
                                          2, self.width+4, self.height+4), 0)

        font = pygame.font.SysFont('Segoe Print', fontsize)
        if self.isactive == False and self.text == '':
            text = font.render(self.placeholder, 1, (255, 255, 255))
        else:
            if self.isactive:
                text = font.render(self.text+'_', 1, (255, 255, 255))
            else:
                text = font.render(self.text, 1, (255, 255, 255))
        win.blit(text, (self.posx + (self.width/2 - text.get_width()/2),
                        self.posy + (self.height/2 - text.get_height()/2)))

    def Addtext(self, input):
        self.text = input


boxes = [[box(borderthick+(i*boxeswidth), borderlength + (j*boxesheight), boxeswidth, boxesheight, '')
           for i in range(lev)] for j in range(lev)]

menubutton = key1((255, 255, 255), 4*xaxis/5+25, yaxis/5 
                    , xaxis/10, yaxis/20, 'Menu')
resetbutton = key1((255, 255, 255), 4*xaxis/5+25, yaxis/5 -
                     2*yaxis/20, xaxis/10, yaxis/20, 'Reset')
startbutton = key1((255, 255, 255), xaxis/5 - xaxis/11, yaxis/5-yaxis/10 ,
                     xaxis/5, yaxis/5, 'START GAME')
quitbutton = key1((255,255,255), 3*xaxis/5 + xaxis/10, yaxis/5-yaxis/10,
                    xaxis/5, yaxis/5, 'END GAME')
minimaxbutton = key1((0, 0, 255), xaxis/20, yaxis/5 + 2*yaxis/10,
                       xaxis/3, yaxis/7, ' Minimax')
abpruningbutton = key1((0,255, 0), 3*xaxis/5, yaxis/5 + 3*yaxis/10,
                         xaxis/3, yaxis/7, 'Alpha-Beta Pruning')
depthlimbutton = key1((255, 0, 0), xaxis/20, yaxis/5 + 4*yaxis/10,
                        xaxis/3, yaxis/7, ' Depth Limit Minmax')
dl_abpruningbutton = key1((255, 100, 180), 3*xaxis/5, yaxis/5 + 5*yaxis/10,
                            xaxis/3, yaxis/7, ' DL & Alpha-BetaPruning')
experimentalbutton = key1((255, 255, 0), xaxis/20, yaxis/5 + 6*yaxis/10,
                            xaxis/3, yaxis/7, 'Experimental Minimax')
levelinput = tb(4*xaxis/11, yaxis/5 - yaxis/10, 3*xaxis/5-xaxis/3, yaxis /
                       20, " Enter Size of Grid ")
winconditioninp = tb(4*xaxis/11, 2*yaxis/5-2*yaxis/10, 3*xaxis/5 - xaxis/3, yaxis /
                            20, " Winning Condition ")
menubutton1 = key1((255, 255, 255), xaxis/2-xaxis/10, yaxis/2-yaxis/20
                    , xaxis/10, yaxis/20, 'Menu')
resetbutton1 = key1((255, 255, 255), xaxis/2-xaxis/10, yaxis/2 + yaxis/20
                     , xaxis/10, yaxis/20, 'Reset')


def resetgame():
    global boxesheight
    global boxeswidth
    global boxes

    menubutton.color = (255,255,255)
    resetbutton.color = (180,255,100)
    startbutton.color = (155, 0, 0)
    quitbutton.color = (0,0,100)
    minimaxbutton.color = (0, 0, 255)
    abpruningbutton.color = (255, 255, 255)
    depthlimbutton.color = (255, 0, 0)
    dl_abpruningbutton.color = (255, 100, 180)
    experimentalbutton.color = (255, 255, 0)

    boxeswidth = int((xaxis-3*borderthick)/lev)
    boxesheight = int((yaxis-3*borderlength)/lev)

    del boxes

    boxes = [[box(borderthick+(i*boxeswidth), borderlength + (j*boxesheight), boxeswidth, boxesheight, '')
               for i in range(lev)] for j in range(lev)]


def function1(screen, winner='', errmsg=''):

    pygame.display.flip()
    win.fill((50,50,50))

    # for MENU screen
    if screen == 0:
        levelinput.draw(win)
        winconditioninp.draw(win)
        startbutton.draw(win, 60)
        quitbutton.draw(win, 60)

        font = pygame.font.SysFont('Segoe Print', 24)
        text = font.render(
            " SELECT THE ALGORITHM ", 1, (255, 255, 255))
        win.blit(text, (3*xaxis/10, yaxis/5 + 1*yaxis/10))

        minimaxbutton.draw(win)
        abpruningbutton.draw(win)
        depthlimbutton.draw(win)
        dl_abpruningbutton.draw(win)
        experimentalbutton.draw(win)

    # for GAME SCREEN
    elif screen == 1:
        flagw = boxeswidth
        flagh = boxesheight

        for i in range(lev-1):
            pygame.draw.line(win, (255, 255, 255), (flagw+borderthick, borderlength),
                             (flagw+borderthick, yaxis-2*borderlength), 1)
            flagw += boxeswidth
            pygame.draw.line(win, (255, 255, 255), (borderthick, flagh+borderlength),
                             (xaxis - borderthick, flagh+borderlength), 1)
            flagh += boxesheight

        for i in range(lev):
            for j in range(lev):
                boxes[i][j].draw(win)

        menubutton.draw(win)
        resetbutton.draw(win)
    # for CONGRATS SCREEN
    elif screen == 2:
        font = pygame.font.SysFont('comicsansms', 55)
        if winner == 'tie':
            text = font.render("THE MATCH IS A TIE", 1, (255, 255, 0))
            win.blit(text, (xaxis/2-text.get_width() /
                            2, yaxis/2-text.get_width()/2))
        if winner == 'X':
            text = font.render("X WINS THE MATCH!", 1, (255, 255, 0))
            win.blit(text, (xaxis/2-text.get_width() /
                            2, yaxis/2-text.get_width()/2))
        if winner == 'O':
            text = font.render("O WINS THE MATCH", 1, (255, 255, 0))
            win.blit(text, (xaxis/2-text.get_width() /
                            2, yaxis/2-text.get_width()/2))
        menubutton1.draw(win)
        resetbutton1.draw(win)


def checkwinner():
    result = ''
    count = 1
    for i in range(lev):
        for j in range(lev-1):
            if boxes[i][j].val == boxes[i][j+1].val:
                result = boxes[i][j].val
                count += 1
            else:
                result = ''
                count = 1
            if result != '' and count == wincondition:
                return result
        count = 1

    for i in range(lev):
        for j in range(lev-1):
            if boxes[j][i].val == boxes[j+1][i].val:
                result = boxes[j][i].val
                count += 1
            else:
                result = ''
                count = 1
            if result != '' and count == wincondition:
                return result
        count = 1

    count = 1
    for i in range(lev-1):
        if boxes[i][i].val == boxes[i+1][i+1].val:
            result = boxes[i][i].val
            count += 1
        else:
            result = ''
            count = 1
        if result != '' and count == wincondition:
            return result

    count = 1
    for i in range(lev-1):
        if boxes[i][lev-i-1].val == boxes[i+1][lev-i-2].val:
            result = boxes[i][lev-i-1].val
            count += 1
        else:
            result = ''
            count = 1
        if result != '' and count == wincondition:
            return result

    for i in range(lev):
        for j in range(lev):
            if boxes[i][j].val == '':
                return ''

    return 'tie'


def randmove():

    count = 0
    for b in boxes:
        for c in b:
            if c.val == '':
                count += 1

    if count < 2:
        return

    if checkwinner == 'tie':
        return
    while True:
        i = random.randint(0, lev-1)
        j = random.randint(0, lev-1)

        if boxes[i][j].val == '':
            break

    boxes[i][j].val = 'O'


def experimentalminmax(depth, isMaximizingPlayer, alpha, beta):

    winner = checkwinner()

    if winner == 'X':
        return -1
    elif winner == 'O':
        return 1
    elif winner == 'tie':
        return 0

    if depth > 5:
        if(isMaximizingPlayer):
            return 1
        else:
            return -1

    if isMaximizingPlayer:
        bestVal = -100
        for b in boxes:
            for c in b:
                if c.val == '':
                    c.val = 'O'
                    value = experimentalminmax(depth+1, False, alpha, beta)
                    c.val = ''
                    if(value == 1):
                        return 1
                    bestVal = max(bestVal, value)
                    alpha = max(alpha, bestVal)
                    if beta <= alpha:
                        break
        return bestVal
    else:
        bestVal = 100
        for b in boxes:
            for c in b:
                if c.val == '':
                    c.val = 'X'
                    value = depthlimitabprun(depth+1, True, alpha, beta)
                    c.val = ''
                    bestVal = min(bestVal, value)
                    beta = min(beta, bestVal)
                    if beta <= alpha:
                        break
        return bestVal


def DL(depth, is_turn):

    flag = checkwinner()
    if flag == 'X':
        return -1
    elif flag == 'O':
        return 1
    elif flag == 'tie':
        return 0

    if depth > 5:
        if(is_turn):
            return 1
        else:
            return -1

    if(is_turn):
        bestscore = -2
        for i in range(lev):
            for j in range(lev):
                if(boxes[i][j].val == ''):
                    boxes[i][j].val = 'O'
                    score =DL(depth+1, False)
                    boxes[i][j].val = ''
                    if(score > bestscore):
                        bestscore = score
        return bestscore
    else:
        bestscore = 2
        for i in range(lev):
            for j in range(lev):
                if(boxes[i][j].val == ''):
                    boxes[i][j].val = 'X'
                    score = DL(depth+1, True)
                    boxes[i][j].val = ''
                    if(score < bestscore):
                        bestscore = score
        return bestscore


def depthlimitabprun(depth, isMaximizingPlayer, alpha, beta):

    winner = checkwinner()

    if winner == 'X':
        return -1
    elif winner == 'O':
        return 1
    elif winner == 'tie':
        return 0

    if depth > 5:
        if(isMaximizingPlayer):
            return 1
        else:
            return -1

    if isMaximizingPlayer:
        bestVal = -100
        for b in boxes:
            for c in b:
                if c.val == '':
                    c.val = 'O'
                    value = depthlimitabprun(depth+1, False, alpha, beta)
                    c.val = ''
                    bestVal = max(bestVal, value)
                    alpha = max(alpha, bestVal)
                    if beta <= alpha:
                        break
        return bestVal
    else:
        bestVal = 100
        for b in boxes:
            for c in b:
                if c.val == '':
                    c.val = 'X'
                    value = depthlimitabprun(depth+1, True, alpha, beta)
                    c.val = ''
                    bestVal = min(bestVal, value)
                    beta = min(beta, bestVal)
                    if beta <= alpha:
                        break
        return bestVal


def Alphabeta(depth, isMaximizingPlayer, alpha, beta):
    winner = checkwinner()

    if winner == 'X':
        return -1
    elif winner == 'O':
        return 1
    elif winner == 'tie':
        return 0

    if isMaximizingPlayer:
        bestVal = -100
        for b in boxes:
            for c in b:
                if c.val == '':
                    c.val = 'O'
                    value = Alphabeta(depth+1, False, alpha, beta)
                    c.val = ''
                    bestVal = max(bestVal, value)
                    alpha = max(alpha, bestVal)
                    if beta <= alpha:
                        break
        return bestVal
    else:
        bestVal = 100
        for b in boxes:
            for c in b:
                if c.val == '':
                    c.val = 'X'
                    value = Alphabeta(depth+1, True, alpha, beta)
                    c.val = ''
                    bestVal = min(bestVal, value)
                    beta = min(beta, bestVal)
                    if beta <= alpha:
                        break
        return bestVal


def minimax(depth, is_turn):  # simple Minimax2
    flag = checkwinner()
    if flag == 'X':
        return -1
    elif flag == 'O':
        return 1
    elif flag == 'tie':
        return 0

    if(is_turn):
        bestscore = -100000
        for i in range(lev):
            for j in range(lev):
                if(boxes[i][j].val == ''):
                    boxes[i][j].val = 'O'
                    score = minimax(depth+1, False)
                    boxes[i][j].val = ''
                    # if(score == 1):
                    #     return 1
                    if(score > bestscore):
                        bestscore = score
        return bestscore
    else:
        bestscore = 100000
        for i in range(lev):
            for j in range(lev):
                if(boxes[i][j].val == ''):
                    boxes[i][j].val = 'X'
                    score = minimax(depth+1, True)
                    boxes[i][j].val = ''
                    # if(score == -1):
                    #     return -1
                    if(score < bestscore):
                        bestscore = score
        return bestscore


def ai(choice):
    global boxes
    bestscore = -100000
    bestmove = (None, None)
    flag = 0

    flag1 = checkwinner()
    if flag1 == 'X':
        return -1
    elif flag1 == 'O':
        return 1
    elif flag1 == 'tie':
        return 0

    if choice == 0:
        print("using random Move")
        randmove()
    elif choice == 1:
        print("using basic Pruning")
        for i in range(lev):
            for j in range(lev):
                if boxes[i][j].val == '':
                    boxes[i][j].val = 'O'
                    score = minimax(0, False)
                    boxes[i][j].val = ''
                    if score > bestscore:
                        bestscore = score
                        bestmove = (i, j)
        i = bestmove[0]
        j = bestmove[1]

        if i != None and j != None:
            boxes[i][j].val = 'O'
        else:
            function1(2, 'tie')
    elif choice == 2:
        print("using abpruning minimax")
        alpha = -100
        beta = +100
        for i in range(lev):
            for j in range(lev):
                if boxes[i][j].val == '':
                    boxes[i][j].val = 'O'
                    value = Alphabeta(1, False, alpha, beta)
                    boxes[i][j].val = ''
                    if value > bestscore:
                        bestscore = value
                        bestmove = (i, j)
                    alpha = max(alpha, bestscore)
                    if beta <= alpha:
                        break
        i = bestmove[0]
        j = bestmove[1]

        if i != None and j != None:
            boxes[i][j].val = 'O'
        else:
            function1(2, 'tie')
    elif choice == 3:
        print("using depth Limit")
        for i in range(lev):
            for j in range(lev):
                if boxes[i][j].val == '':
                    boxes[i][j].val = 'O'
                    score = DL(1, False)
                    boxes[i][j].val = ''
                    if score > bestscore:
                        bestscore = score
                        bestmove = (i, j)
        i = bestmove[0]
        j = bestmove[1]

        if i != None and j != None:
            boxes[i][j].val = 'O'
        else:
            function1(2, 'tie')
    elif choice == 4:
        print("using abpruning and depth limit minimax")
        alpha = -100
        beta = +100
        for i in range(lev):
            for j in range(lev):
                if boxes[i][j].val == '':
                    boxes[i][j].val = 'O'
                    value = depthlimitabprun(1, False, alpha, beta)
                    boxes[i][j].val = ''
                    if value > bestscore:
                        bestscore = value
                        bestmove = (i, j)
                    alpha = max(alpha, bestscore)
                    if beta <= alpha:
                        break
        i = bestmove[0]
        j = bestmove[1]

        if i != None and j != None:
            boxes[i][j].val = 'O'
        else:
            function1(2, 'tie')
    elif choice == 5:
        print("using Experimental minimax")
        alpha = -100
        beta = +100
        for i in range(lev):
            for j in range(lev):
                if boxes[i][j].val == '':
                    boxes[i][j].val = 'O'
                    value = experimentalminmax(1, False, alpha, beta)
                    boxes[i][j].val = ''
                    if value == 1:
                        boxes[i][j].val = 'O'
                        return
                    if value > bestscore:
                        bestscore = value
                        bestmove = (i, j)
                    alpha = max(alpha, bestscore)
                    if beta <= alpha:
                        break
        i = bestmove[0]
        j = bestmove[1]

        if i != None and j != None:
            boxes[i][j].val = 'O'
        else:
            function1(2, 'tie')


def start(screen=0):
    global lev
    global wincondition
    global starttime
    global stoptime
    choice = 0
    currplayer = 'X'
    winner = ''

    while True:
        if screen != 3:
            function1(screen, winner)
        else:
            function1(3, errmsg="Not Feasible With this algorithm")
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
            else:
                pos = pygame.mouse.get_pos()
                if event.type == pygame.MOUSEBUTTONDOWN:
                    # for screen 0
                    if screen == 0:
                        if(winconditioninp.isOver(pos)):
                            pass
                        if(levelinput.isOver(pos)):
                            pass
                        if(startbutton.isOver(pos)):
                            screen = 1
                            if levelinput.text != '':
                                lev = int(levelinput.text)
                                levelinput.text = ''
                                levelinput.isactive = False
                            if winconditioninp.text != '':
                                wincondition = int(winconditioninp.text)
                                winconditioninp.text = ''
                                winconditioninp.isactive = False
                            resetgame()
                        if(quitbutton.isOver(pos)):
                            pygame.quit()
                        if(minimaxbutton.isOver(pos)):
                            choice = 1
                        if(abpruningbutton.isOver(pos)):
                            choice = 2
                        if(depthlimbutton.isOver(pos)):
                            choice = 3
                        if(dl_abpruningbutton.isOver(pos)):
                            choice = 4
                        if(experimentalbutton.isOver(pos)):
                            choice = 5
                    elif screen == 1:
                        if(menubutton.isOver(pos)):
                            resetgame()
                            screen = 0
                        if(resetbutton.isOver(pos)):
                            resetgame()
                        for i in range(lev):
                            for j in range(lev):
                                if boxes[i][j].isOver(pos, currplayer):
                                    if currplayer == 'X':
                                        currplayer = 'O'
                                    ai(choice)
                                    currplayer = 'X'
                        winner = checkwinner()
                        if winner != '':
                            screen = 2
                    elif screen == 2:
                        if(menubutton1.isOver(pos)):
                            resetgame()
                            screen = 0
                        if(resetbutton1.isOver(pos)):
                            resetgame()
                            screen = 1
                elif event.type == pygame.KEYDOWN and levelinput.isactive == True:
                    if event.key == pygame.K_0 or event.key == pygame.K_KP0:
                        levelinput.text = levelinput.text + '0'
                    if event.key == pygame.K_1 or event.key == pygame.K_KP1:
                        levelinput.text = levelinput.text + '1'
                    if event.key == pygame.K_2 or event.key == pygame.K_KP2:
                        levelinput.text = levelinput.text + '2'
                    if event.key == pygame.K_3 or event.key == pygame.K_KP3:
                        levelinput.text = levelinput.text + '3'
                    if event.key == pygame.K_4 or event.key == pygame.K_KP4:
                        levelinput.text = levelinput.text + '4'
                    if event.key == pygame.K_5 or event.key == pygame.K_KP5:
                        levelinput.text = levelinput.text + '5'
                    if event.key == pygame.K_6 or event.key == pygame.K_KP6:
                        levelinput.text = levelinput.text + '6'
                    if event.key == pygame.K_7 or event.key == pygame.K_KP7:
                        levelinput.text = levelinput.text + '7'
                    if event.key == pygame.K_8 or event.key == pygame.K_KP8:
                        levelinput.text = levelinput.text + '8'
                    if event.key == pygame.K_9 or event.key == pygame.K_KP9:
                        levelinput.text = levelinput.text + '9'
                    if event.key == pygame.K_BACKSPACE:
                        levelinput.text = levelinput.text[:-1]
                    if event.key == pygame.K_RETURN:
                        screen = 1
                        if levelinput.text != '':
                            lev = int(levelinput.text)
                            levelinput.text = ''
                        resetgame()
                elif event.type == pygame.KEYDOWN and winconditioninp.isactive == True:
                    if event.key == pygame.K_0 or event.key == pygame.K_KP0:
                        winconditioninp.text = winconditioninp.text + '0'
                    if event.key == pygame.K_1 or event.key == pygame.K_KP1:
                        winconditioninp.text = winconditioninp.text + '1'
                    if event.key == pygame.K_2 or event.key == pygame.K_KP2:
                        winconditioninp.text = winconditioninp.text + '2'
                    if event.key == pygame.K_3 or event.key == pygame.K_KP3:
                        winconditioninp.text = winconditioninp.text + '3'
                    if event.key == pygame.K_4 or event.key == pygame.K_KP4:
                        winconditioninp.text = winconditioninp.text + '4'
                    if event.key == pygame.K_5 or event.key == pygame.K_KP5:
                        winconditioninp.text = winconditioninp.text + '5'
                    if event.key == pygame.K_6 or event.key == pygame.K_KP6:
                        winconditioninp.text = winconditioninp.text + '6'
                    if event.key == pygame.K_7 or event.key == pygame.K_KP7:
                        winconditioninp.text = winconditioninp.text + '7'
                    if event.key == pygame.K_8 or event.key == pygame.K_KP8:
                        winconditioninp.text = winconditioninp.text + '8'
                    if event.key == pygame.K_9 or event.key == pygame.K_KP9:
                        winconditioninp.text = winconditioninp.text + '9'
                    if event.key == pygame.K_BACKSPACE:
                        winconditioninp.text = winconditioninp.text[:-1]
                    if event.key == pygame.K_RETURN:
                        screen = 1
                        if winconditioninp.text != '':
                            wincondition = int(winconditioninp.text)
                            winconditioninp.text = ''
                        resetgame()


start()
