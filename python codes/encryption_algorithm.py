import hashlib

def cryp():
	
	encryption1 = input("\033[1;31m Enter text to encrypt :")
	cryption = hashlib.blake2b()
	cryption.update(encryption1.encode())
	print("----- blake2b -----")
	print("Byte : \n",cryption.digest(),"\n")
	print("String : \n",cryption.hexdigest(),"\n")
	print(("_" *105),"\n")

	encryption2 = encryption1
	cryption = hashlib.blake2s()
	cryption.update(encryption2.encode())
	print("----- blake2s -----")
	print("Byte : \n",cryption.digest(),"\n")
	print("String : \n",cryption.hexdigest(),"\n")
	print(("_" *105),"\n")
	encryption3 = encryption1
	cryption = hashlib.md5()
	cryption.update(encryption3.encode())
	print("----- md5 -----")
	print("Byte : \n",cryption.digest(),"\n")
	print("String : \n",cryption.hexdigest(),"\n")
	print(("_" *105),"\n")

	encryption4 = encryption1
	cryption = hashlib.sha1()
	cryption.update(encryption4.encode())
	print("----- sha1 -----")
	print("Byte : \n",cryption.digest(),"\n")
	print("String : \n",cryption.hexdigest(),"\n")
	print(("_" *105),"\n")

	encryption5 = encryption1
	cryption = hashlib.sha224()
	cryption.update(encryption5.encode())
	print("----- sha224 -----")
	print("Byte : \n",cryption.digest(),"\n")
	print("String : \n",cryption.hexdigest(),"\n")
	print(("_" *105),"\n")

	encryption6 = encryption1
	cryption = hashlib.sha256()
	cryption.update(encryption6.encode())
	print("----- sha256 -----")
	print("Byte : \n",cryption.digest(),"\n")
	print("String : \n",cryption.hexdigest(),"\n")
	print(("_" *105),"\n")
	

	encryption7 = encryption1
	cryption = hashlib.sha384()
	cryption.update(encryption7.encode())
	print("----- sha384 -----")
	print("Byte : \n",cryption.digest(),"\n")
	print("String : \n",cryption.hexdigest(),"\n")
	print(("_" *105),"\n")

	encryption8 = encryption1
	cryption = hashlib.sha512()
	cryption.update(encryption8.encode())
	print("----- sha512 -----")
	print("Byte : \n",cryption.digest(),"\n")
	print("String : \n",cryption.hexdigest(),"\n")
	print(("_" *105),"\n")
	cryp()
cryp()
	
	
