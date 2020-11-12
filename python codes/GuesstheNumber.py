from tkinter import *
from tkinter import messagebox
from PIL import Image , ImageTk


root = Tk()
root.geometry('300x200')
root.resizable(0, 0)
image1 = Image.open('correct.jpg')
photo = ImageTk.PhotoImage(image1)

def guess_the_num():
    import random
    num = random.randint(0, 10)
    user_input = int(data.get())
    if num == user_input:
        label.configure(text='correct')
    elif num < user_input and user_input < 10:
        label.configure(text=f'guess is high,num is {num}')

    elif num > user_input and user_input < 10 :
        label.configure(text=f'guess is low, '
                             f'Num is{num}')

    else:
        messagebox.showerror('error','wrong input')



label = Label(root, text='guess the number!!(0-10)',font = ('Script MT Bold',20,'bold'))
label.pack()
data = StringVar()
e1 = Entry(root, font=('Algerian', 16), textvariable=data)
e1.pack()
button_ok = Button(root, text='OK', background='white', fg='black',width = 6, command=guess_the_num)
button_ok.pack()

root.mainloop()

