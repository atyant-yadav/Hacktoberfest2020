#User Input
while True:
    print("Input Date Format - DD/MM/YYYY\nEnter DAY '0' for Exit !")
    day = int(input('DAY : '))
    if day == 0:
        break
    elif day>31 or day<0:
        print('Invalid Keyword')
        continue
    month = int(input('MONTH : '))
    if month>12 or month<1:
        print('Invalid Keyword')
        continue
    year = int(input('YEAR : '))
    if year<1:
        print('Invalid Keyword')
        continue
#Month
    ja=ma=my=jl=au=oc=de=31
    ap=ju=se=no=30
    if year%400 == 0:
        fe = 29
    elif year%100 == 0:
        fe = 28
    elif year%4 == 0:
        fe = 29
    else:
        fe = 28
    month_list = [ja,fe,ma,ap,my,ju,jl,au,se,oc,no,de]
    month_list2 = ["January","February","March","April","May","June","July","August","September","October","November","December"]
    mon = 0
    for i in month_list[0:month-1]:
        mon += i
# m is maximum day of month, for August Maximum Day is '31'
    m = month_list[month-1]
    if day>m:
        print('Enter Correct Day !')
        continue
#Year
    count = 0
    complete_year = year-1
    if complete_year>400:
        complete_year = complete_year%400
    if complete_year>300:
        complete_year = complete_year%300
        count += 1    
    if complete_year>200:
        complete_year = complete_year%200
        count += 3
    if complete_year>100:
        complete_year = complete_year%100
        count += 5
    if complete_year>0:
        complete_year = complete_year
    leap_year = complete_year//4
    normal_year = complete_year-leap_year
    y1 = (leap_year*2)+normal_year
#Calculation
    x = (day+mon+y1+count)%7
    dy = ['SUNDAY','MONDAY','TUESDAY','WEDNESDAY','THURSDAY','FRIDAY','SATURDAY']
    print('{}th'.format(day),month_list2[month-1],year,':',dy[x],end='\n\n')
    continue
