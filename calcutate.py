c='y'
while c=='y' or c=='Y':
    print("MENU \n1.ADD \n2.SUBTRACT \n3.DIVIDE \n4.MULTIPLY \n5.EXIT\n")
    ch=input("Enter your choice\t:")
    if ch=='1':
        a=int(input("Enter the first digit"))
        b=int(input("Enter the second digit"))
        add=a+b
        print(a,"+",b,"=",add)
    elif ch=='2':
            a=int(input("Enter the first digit"))
            b=int(input("Enter the second digit"))
            sub=a-b
            print(a,"-",b,"=",sub)
    elif ch=='3':
        a=int(input("Enter the first digit"))
        b=int(input("Enter the second digit"))
        if b!=0:
            div=a/b
            print(a,"/",b,"=",div)
        else:
            print("You cannot divide by zero")
    elif ch=='4':
        a=int(input("Enter the first digit"))
        b=int(input("Enter the second digit"))
        mul=a*b
        print(a,"x",b,"=",mul)
    
    else :
       c='n'
