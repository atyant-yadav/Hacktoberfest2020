import datetime
from dateutil.relativedelta import relativedelta
from datetime import timedelta
import calendar
def calculate_subscription(expiry_date,months_to_buy,monthly_cost,annual_cost):
    exp = expiry_date.split("/")
    month = ''
    nums = [int(s) for s in exp]
    start_date = datetime.date(nums[2],nums[1],nums[0])
    days_in_month = 0
    if(months_to_buy==12):
        newDate = start_date + relativedelta(months=1)
        if(nums[0]>15):
            newDate = start_date + relativedelta(months=12)
            month = newDate.month + 1
            nD = datetime.date(newDate.year,month,1)
            extraDays = nD - newDate
            annual_cost = annual_cost + (annual_cost*extraDays.days)/365
            return nD,annual_cost
        elif(nums[0]<15 and nums[0]>1):
            newDate = start_date + relativedelta(months=12)
            nD = datetime.date(newDate.year,newDate.month,15)
            extraDays = nD - newDate
            annual_cost = annual_cost + (annual_cost*extraDays.days)/365
            return nD,annual_cost
        else:
            newDate = start_date + relativedelta(months=12)
            return newDate,annual_cost
    if(months_to_buy<12):
        if(nums[0]>15):
            newDate = start_date + relativedelta(months=months_to_buy)
            nD = datetime.date(newDate.year,newDate.month,15)
            totalDays = nD - start_date
            monthly_cost = (monthly_cost/30)*totalDays.days
            return nD,monthly_cost
        elif(nums[0]<15 and nums[0]>1):
            newDate = start_date + relativedelta(months=months_to_buy)
            nD = datetime.date(newDate.year,newDate.month,1)
            totalDays = nD - start_date
            monthly_cost = (monthly_cost/30)*totalDays.days 
            return nD,monthly_cost
        else:
            newDate = start_date + relativedelta(months=months_to_buy)
            monthly_cost = monthly_cost * months_to_buy
            return newDate,monthly_cost

date = input()
monthsToBuy = int(input())
monthlyCost = int(input())
annualCost = int(input())
s = calculate_subscription(date,monthsToBuy,monthlyCost,annualCost)
print(s[0].strftime("%d/%m/%Y"),"{:.2f}".format(s[1]))    
