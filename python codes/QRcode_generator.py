import qrcode
a=input("Enter the url=\n")
b=qrcode.make(a)
b.save('ABC.png')
