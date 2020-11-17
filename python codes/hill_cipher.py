# Python3 code to implement Hill Cipher 

keyMatrix = [[0] * 3 for i in range(3)] 

# Generate vector for the message 
messageVector = [[0] for i in range(3)] 

# Generate vector for the cipher 
cipherMatrix = [[0] for i in range(3)] 

# Following function generates the 
# key matrix for the key string 
def getKeyMatrix(key): 
	k = 0
	for i in range(3): 
		for j in range(3): 
			keyMatrix[i][j] = ord(key[k]) % 65
			k += 1

# Following function encrypts the message 
def encrypt(messageVector): 
	for i in range(3): 
		for j in range(1): 
			cipherMatrix[i][j] = 0
			for x in range(3): 
				cipherMatrix[i][j] += (keyMatrix[i][x] *
									messageVector[x][j]) 
			cipherMatrix[i][j] = cipherMatrix[i][j] % 26

def HillCipher(message, key): 

	# Get key matrix from the key string 
	getKeyMatrix(key) 

	# Generate vector for the message 
	for i in range(3): 
		messageVector[i][0] = ord(message[i]) % 65

	# Following function generates 
	# the encrypted vector 
	encrypt(messageVector) 

	# Generate the encrypted text 
	# from the encrypted vector 
	CipherText = [] 
	for i in range(3): 
		CipherText.append(chr(cipherMatrix[i][0] + 65)) 

	# Finally print the ciphertext 
	print("Ciphertext: ", "".join(CipherText)) 

# Driver Code 
def main(): 

	# Get the message to 
	# be encrypted 
	message = "EXAM"

	# Get the key 
	key = "GYBNQKURP"

	HillCipher(message, key) 

if __name__ == "__main__": 
	main() 

# This code is contributed 
# by Pratik Somwanshi 
