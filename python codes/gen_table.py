print("Multiplication Table Generator")
tab_no = int(input(" Enter which table u want to generate(like 2 for 2's table):"))
range_tab = int(input(" Enter number upto which you  want to generate the table (like 10 for 1-10):"))
for i in range(1,range_tab+1):
    print(tab_no,"*",i,'=',tab_no*i,'\n')

