import webbrowser
import pyautogui
import time
import PIL
import sys

#pyautogui.FAILSAFE=False

x1=470.0
x2=520.0
y1,y2=310,330

def hit(key):
    pyautogui.press(key)

def collision(tbd):
    for i in range(int(x1),int(x2)):
        for j in range(y2,y1,-1):                 
                if tbd[i,j]<100:
                   return True
    return False
                          
def bcollision(tbd):
    for i in range(int(x1),int(x2)):
        for j in range(240,300):                 
            if tbd[i,j]<100:
                return True
    return False

if __name__=='__main__':
    st=time.time()
    webbrowser.open_new('https://chromedino.com')
    time.sleep(10)
    hit('UP')
    gst=time.time()
    while True:
        image = PIL.ImageGrab.grab().convert('L')
        tbd=image.load()
        # for i in range(430,470):    
        #       for j in range(25     0,330):
        #               tbd[i,j]=0   
        if collision(tbd):
            hit('UP')
        if bcollision(tbd) and not collision(tbd):
            hit('DOWN')
        #x1+=0.05 if x1<=780 else 0                  
        if time.time()-gst==10:
        	x2*=1.2
            #if time.time()-st>=360:
            #   break
