from tkinter import *
from tkinter import messagebox, font

class Application (Tk):
    def __init__(self, top):
        super().__init__(top)
        self.top = top
        self.r = []
        self.varM = IntVar()
        self.varN = IntVar()
        self.varResult = StringVar()
        self.varM.set(1)
        self.varN.set(1)
        mFont = font.Font(self, family="Lucida Console", size=9)

        self.grid()
        self.lblM = Label(self, text="Multiplier (m):").grid(row=0, column=0, sticky=NE)
        self.txtM = Entry(self, textvariable=self.varM).grid(row=0, column=1, sticky=NW)
        self.lblN = Label(self, text="Rows to Generate (n):").grid(row=1, column=0, sticky=NE)
        self.txtN = Entry(self, textvariable=self.varN).grid(row=1, column=1, sticky=NW)

        self.btnGen = Button(self, text="Generate", command=self.getResults).grid(row=2, column=0, columnspan=2, sticky=E + W)
        self.txtRes = Message(self, bg="#FFF", textvariable=self.varResult, font=mFont).grid(row=3, column=0, columnspan=2, sticky=N + S + E + W)
        self.grid_columnconfigure(0, weight=1)
        self.grid_columnconfigure(1, weight=1)
        self.grid_rowconfigure(3, weight=1)

    def calculateRows(self, m, n):
        self.r.clear()
        for i in range(1, n + 1):
            if i < 10:
                strLine = f" {i} X {m} = {m * i}"
            else:
                strLine = f"{i} X {m} = {m * i}"
            self.r.append(strLine)
        return '\n'.join(self.r)

    def getResults(self):
        try:
            m = self.varM.get()
            n = self.varN.get()
            self.varResult.set(self.calculateRows(m, n))
        except:
            messagebox.showerror("ERROR!", "Enter only Integers.")

if __name__ == '__main__':
    app = Application(None)
    app.title("Multiplication Table Generator Plus")
    app.mainloop()
