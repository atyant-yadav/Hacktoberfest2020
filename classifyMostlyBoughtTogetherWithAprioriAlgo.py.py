import pandas as pd
from apyori import apriori
from tkinter import *
from tkinter import filedialog
from tkinter import Label,Frame
from pandastable import Table



def open():
    root.filename = filedialog.askopenfilename(initialdir = 'C:\ ' , title = "Select a file", filetypes=(("CSV files", "*.csv"),))
    # my_label = Label(root, text=root.filename).pack()
    print(root.filename)
    store_data = pd.read_csv(root.filename ,header=None)
    num_records = len(store_data)
    # print("Total number of Records : ", num_records)
    label1  = Label(root,text = "Total number of Records : "+str(num_records))
    label1.pack()
    # print("\n______________________________________________________________________________________\n")

    records = []
    for i in range(0,num_records):
        records.append([str(store_data.values[i,j]) for j in range(0,20) if str(store_data.values[i,j]) not in ('nan')])
        
    association_rules = apriori(records,min_support=0.0053,min_confidence=0.20,min_lift=3)
    association_results = list(association_rules)
    # print("Number of Condition Accepting Records : ",len(association_results))
    label2  = Label(root,text = "Number of Condition Accepting Records : "+str(len(association_results)))
    label2.pack()
    # print("\n______________________________________________________________________________________\n")

    results = []
    for item in association_results:
        pair = item[0]
        items = [x for x in pair]
        
        value0 = str(items[0])
        value1 = str(items[1])
        value2 = str(item[1])[:7]
        value3 = str(item[2][0][2])[:7]
        value4 = str(item[2][0][3])[:7]
        
        rows = (value0,value1,value2,value3,value4)
        
        results.append(rows)
        
        col = ['Product1','Product2','Support','Confidence','Lift']
        
    final_result = pd.DataFrame.from_records(results,columns=col)
        
    # print(final_result)
    frame = Frame(root)
    frame.pack(fill='both', expand=True)

    pt = Table(frame)
    pt.show()
    pt.model.df = final_result


root = Tk()
root.title('CSV file reader')
root.minsize(150, 100) 
root.geometry('450x600')

my_btn = Button(root, text="Open File", command=open).pack()

root.mainloop()