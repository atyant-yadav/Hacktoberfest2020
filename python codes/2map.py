from tkinter import *
import random
from tkinter import messagebox
root=Tk()
root.geometry("470x210")


string= 'E'
canvas=[]
button=[]


button.append(Button(root,text='',height=1,width=3,fg='red',font="Verdana 19 bold"))
button[0].place(relx=0.082, rely=0.121, height=54, width=57)
canvas.append(Canvas(button[0]))

button.append(Button(root,text='',height=1,width=3,fg='red',font="Verdana 19 bold"))
button[1].place(relx=0.206, rely=0.121, height=54, width=57)
canvas.append(Canvas(button[1]))

button.append(Button(root,text='',height=1,width=3,fg='red',font="Verdana 19 bold"))
button[2].place(relx=0.082, rely=0.367, height=54, width=57)
canvas.append(Canvas(button[2]))

button.append(Button(root,text='',height=1,width=3,fg='red',font="Verdana 19 bold"))
button[3].place(relx=0.206, rely=0.367, height=54, width=57)
canvas.append(Canvas(button[3]))

lol=Label(root,text='0             1             ')
lol.place(relx=0.05, rely=0.000, height=31, width=194)

w=Label(root,text='0')
w.place(relx=0.05, rely=0.140, height=31, width=7)

ww=Label(root,text='1')
ww.place(relx=0.05, rely=0.380, height=31, width=5)


exp=Label(root,text='expression(x,y):')
exp.place(relx=0.0, rely=0.756, height=31, width=144)

e = Entry(root)
e.place(relx=0.277, rely=0.756,height=30, relwidth=0.307)

rows, cols = (2, 2) 
arr = [[0 for i in range(cols)] for j in range(rows)]
def printtext():
    global e
    global string
    global arr
    string = e.get() 
    print (string)

    list=string.split('+')
    print(list)
    # Using above first method to create a  
    # 2D array 
    
   
            
       
    print(arr)
    
    
    

    
    for i in list:
        
        if i=="x'y'":
            
            canvas[0].create_text(20, 30, anchor=W, font="Purisa",
            text="1")
            arr[0][0]=1
            
        if i=="x'y":
            canvas[1].create_text(20, 30, anchor=W, font="Purisa",
            text="1")
            arr[0][1]=1
            
        if i=="xy'":
            canvas[2].create_text(20, 30, anchor=W, font="Purisa",
            text="1")
            arr[1][0]=1
            
        if i=="xy":
            canvas[3].create_text(20, 30, anchor=W, font="Purisa",
            text="1")
            arr[1][1]=1
    for i in range(4):
        canvas[i].pack()
    groups();
    
        
    
    
    
    
    
    
    
    
b = Button(root,text='Calculate',command=printtext)
b.place(relx=0.717, rely=0.311, height=44, width=77)
def groups():
    global arr
    if arr[0][0]==1 and arr[0][1]==1 and arr[1][0]==1 and arr[1][1]==1:
        canvas[0].create_line(0, 2, 80, 2)
        canvas[0].create_line(2, 2, 2, 80)
        canvas[1].create_line(0, 2, 80, 2)
        canvas[1].create_line(46, 0, 46, 80)
        canvas[2].create_line(0, 43, 92,43 )
        canvas[2].create_line(2, 2, 2, 80)
        canvas[3].create_line(46, 0, 46, 80)
        canvas[3].create_line(0, 43, 92,43 )
        #canvas[0].create_line(46, 0, 46, 80)
        #canvas[0].create_line(0, 43, 92,43 )
        
        canvas[0].pack()
        canvas[1].pack()
        canvas[2].pack()
        canvas[3].pack()
        return 1;
        print('0')
    
        
    elif arr[0][0]==1 and arr[0][1]==1 :
        canvas[0].create_line(0, 2, 80, 2)
        canvas[0].create_line(0, 43, 92,43 )
        canvas[0].create_line(2, 2, 2, 80)
        canvas[1].create_line(0, 2, 80, 2)
        canvas[1].create_line(46, 0, 46, 80)
        canvas[1].create_line(0, 43, 92,43 )
        #canvas[1].create_line(2, 2, 2, 80)
        canvas[0].pack()
        canvas[1].pack()
        if arr[1][1]==1:
            canvas[1].create_line(2, 2, 2, 80)
            canvas[3].create_line(46, 0, 46, 80)
            canvas[3].create_line(0, 43, 92,43 )
            canvas[3].create_line(2, 2, 2, 80)
            canvas[1].pack()
            canvas[3].pack()
        if arr[1][0]==1:
            canvas[0].create_line(46, 0, 46, 80)
            canvas[2].create_line(46, 0, 46, 80)
            canvas[2].create_line(0, 43, 92,43 )
            canvas[2].create_line(2, 2, 2, 80)
            canvas[2].pack()
            canvas[0].pack()
            
            
        print('1')
    elif arr[1][0]==1 and arr[1][1]==1 :
        canvas[2].create_line(0, 2, 80, 2)
        canvas[2].create_line(0, 43, 92,43 )
        canvas[2].create_line(2, 2, 2, 80)

        canvas[3].create_line(0, 2, 80, 2)
        canvas[3].create_line(46, 0, 46, 80)
        canvas[3].create_line(0, 43, 92,43 )
        canvas[2].pack()
        canvas[3].pack()

        if arr[0][0]==1:
            canvas[2].create_line(46, 0, 46, 80)
            canvas[0].create_line(0, 2, 80, 2)
            canvas[0].create_line(46, 0, 46, 80)
            canvas[0].create_line(2, 2, 2, 80)
            canvas[0].pack()
            canvas[2].pack()
        if arr[0][1]==1:
            canvas[3].create_line(2, 2, 2, 80)
            canvas[1].create_line(0, 2, 80, 2)
            canvas[1].create_line(46, 0, 46, 80)
        
            canvas[1].create_line(2, 2, 2, 80)
            canvas[1].pack()
            canvas[3].pack()
            
            
        
        
    if arr[0][0]==1 and arr[1][0]==1:
        canvas[0].create_line(0, 2, 80, 2)
        canvas[0].create_line(46, 0, 46, 80)
        canvas[0].create_line(2, 2, 2, 80)

        
        canvas[2].create_line(46, 0, 46, 80)
        canvas[2].create_line(0, 43, 92,43 )
        canvas[2].create_line(2, 2, 2, 80)
        
        canvas[0].pack()
        canvas[2].pack()
        if arr[0][1]==1:
            canvas[0].create_line(46, 0, 46, 80)
            canvas[1].create_line(0, 2, 80, 2)
            canvas[1].create_line(46, 0, 46, 80)
            canvas[1].create_line(0, 43, 92,43 )
            canvas[1].pack()
            canvas[0].pack()
        if arr[1][1]==1:
            canvas[2].create_line(46, 0, 46, 80)
            canvas[3].create_line(0, 2, 80, 2)
            canvas[3].create_line(46, 0, 46, 80)
            canvas[3].create_line(0, 43, 92,43 )
            canvas[3].pack()
            canvas[2].pack()
    if arr[0][1]==1 and arr[1][1]==1:
        canvas[1].create_line(0, 2, 80, 2)
        canvas[1].create_line(46, 0, 46, 80)
        canvas[1].create_line(2, 2, 2, 80)
        canvas[3].create_line(46, 0, 46, 80)
        canvas[3].create_line(0, 43, 92,43 )
        canvas[3].create_line(2, 2, 2, 80)
        canvas[1].pack()
        canvas[3].pack()
        
        
    
        
        
        print('2')
        
    #if arr[1][1]==1:
       #canvas[3].create_line(0, 2, 80, 2)
        #canvas[3].create_line(46, 0, 46, 80)
        #canvas[3].create_line(0, 43, 92,43 )
        #canvas[3].create_line(2, 2, 2, 80)
        #canvas[3].pack()
        #print('3')
   
    
def clear():
    global arr
    global string
    string=''
    arr = [[0 for i in range(cols)] for j in range(rows)]
    canvas[0].delete('all')
    canvas[1].delete('all')
    canvas[2].delete('all')
    canvas[3].delete('all')
    #canvas.create_line(10, 0, 10, 50)
    #canvas.pack()
    
a = Button(root,text='Clear',command=clear)
a.place(relx=0.717, rely=0.551, height=44, width=77)

