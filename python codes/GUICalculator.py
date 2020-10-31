import tkinter as tk

root = tk.Tk()

canvas1 = tk.Canvas(root, width=300, height=300)
canvas1.pack()

#create entry
entry0 = tk.Entry(root)
canvas1.create_window(160, 80, window=entry0)

entry1 = tk.Entry(root)
canvas1.create_window(160, 140, window=entry1)

entry2 = tk.Entry(root)
canvas1.create_window(160, 180, window=entry2)

label0 = tk.Label(root, text='Calculator')
canvas1.create_window(150, 50, window=label0)

label1 = tk.Label(root, text='Entry 1')
canvas1.create_window(50, 80, window=label1)

label2 = tk.Label(root, text='Entry 2')
canvas1.create_window(50, 140, window=label2)

label3 = tk.Label(root, text='Result')
canvas1.create_window(50, 180, window=label3)

def add():
    v1 = entry0.get()
    v2 = entry1.get()
    
    label4 = tk.Label(root, text=float(v1)+float(v2), bg='white')
    canvas1.create_window(180, 180, window=label4)
    
buttonAdd = tk.Button(text='+', command=add)
canvas1.create_window(120, 220, window=buttonAdd)

def sub():
    v1 = entry0.get()
    v2 = entry1.get()

    label5 = tk.Label(root, text=float(v1)-float(v2), bg='white')
    canvas1.create_window(180, 180, window=label5)

buttonSub = tk.Button(text='-', command=sub)
canvas1.create_window(160, 220, window=buttonSub)    

root.mainloop()
