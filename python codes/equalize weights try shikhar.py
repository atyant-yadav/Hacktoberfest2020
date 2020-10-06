def fillBag(l,eachBagWeight):
    bag=[]
    
    while sum(bag)!=eachBagWeight:
        print("value of l: ",l)
        bag.append(l[0])
        l.remove(l[0])
        nextWeight=eachBagWeight-sum(bag)
        if(nextWeight in l):
            
            bag.append(nextWeight)
            l.remove(nextWeight)
            
            return bag
        else:
           
            if(nextWeight<bag[-1] and nextWeight!=0):
                bag.pop()
            else:
                continue
    
    return bag
        

noOfBags=int(input())
bagsInitialSituation=[]
for i in range(noOfBags):
    l=[]
    noOfGoods=int(input())
    bagsInitialSituation.append(list(map(int,input().strip().split())))
bagsFinalSituation=[]

totalWeight=0

temp=[]
for i in bagsInitialSituation:
    for j in i:
        totalWeight=totalWeight+j
        temp.append(j)

eachBagWeight=totalWeight//noOfBags
temp=sorted(temp)


for i in range(noOfBags):
    l=temp.copy()
    bag=fillBag(l,eachBagWeight)
    for j in bag:
        temp.remove(j)
    bagsFinalSituation.append(bag)

for i in bagsFinalSituation:
    for j in i:
        print(j,end=' ')
    print()
