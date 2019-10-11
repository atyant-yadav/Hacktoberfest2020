def pisanoPeriod(m): 
    previous, current = 0, 1
    for i in range(0, m * m): 
        previous, current = current, (previous + current) % m 
          
        # A Pisano Period starts with 01 
        if (previous == 0 and current == 1):
            return i + 1
def fibb(n,m):
    t = pisanoPeriod(m)
    n = n % t
    p,ne = 0,1
    for i in range(n):
        p,ne = ne,(p+ne)
    print(p%m)
#print(pisanoPeriod(239))
n, m = map(int,input().split())
fibb(n,m)
#for last digit of fibonacci number replace m by 10
