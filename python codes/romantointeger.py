#Roman to Integer
import math
d = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000, 
"IV": 4, "IX":9, "IL":49, "IC": 99, "ID":499, "IM": 999,
"VL":45, "VC":95, "VD":495, "VM":995,
"XL":40, "XC":90, "XD":490, "XM":990,
"LD":450, "LM":950,
"CD":400 , "CM":900}
i = 0
value = 0
s = input("Input a roman number: ")
s = s.upper()
while i < len(s):
    key = s[i:i+2] 
    if key in d:
        value += d[key] 
        i += 2
    else:
        key = s[i]
        value += d[key]
        i+=1
print(value)