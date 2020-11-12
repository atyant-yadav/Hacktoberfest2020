import cmath
import math
print("nome do arquivo")
name = input()
arquivo = open(name, "r")
v = (arquivo.readline())
v = v[:-1]
n = int(v) #tamanho da matriz
l = [0]*(n+1) #matriz auxiliar
A = [0]*n #matriz A que será modificada gerando uma matriz triangular superior
C = [0]*n #matriz A que permanecerá intacta, para pode fazer o calculo do vetor residual
for x in range(0,n): #gerando as matrizes zeradas
	A[x] = [0]*n
	C[x] = [0]*n

b = [0]*n #vetor b que será modificado
c = [0]*n #vetor b que permanecerá intacto, para pode fazer o calculo do vetor residual
r = [0]*n #vetor residual
i = 0

#lendo arquivo

for linha in arquivo: 
	l[i] = linha.split()
	i=i+1


#gerando as matrizes com os valores

for x in range(0,n):
	for i in range(0,n+1):
		if i == n:
			b[x] = float(l[x][i])
			c[x] = float(l[x][i])
		else:
			A[x][i] = float(l[x][i])
			C[x][i] = float(l[x][i])


#Eliminação Gaussiana com Pivoteamento parcial

for k in range(0,n-1):
	pivo = A[k][k]
	l_pivo = k
	for i in range(k+1,n-1):
		if (abs(A[i][k]) > abs(pivo)):
			pivo = A[i][k]
			l_pivo = i
	if pivo == 0:
		break

	if l_pivo != k:
		for j in range(0,n):
			troca = A[k][j]
			A[k][j] = A[l_pivo][j]
			A[l_pivo][j] = troca
		troca = b[k]
		b[k] = b[l_pivo]
		b[l_pivo] = troca

	for i in range(k+1,n):
			m = A[i][k]/A[k][k]
			A[i][k]=0
			for j in range(k+1,n):
				A[i][j]=A[i][j]-m*A[k][j]
			b[i] = b[i] - m*b[k]


#Resolução do sistema triangular superior

x = [0]*n
x[n-1] = b[n-1]/A[n-1][n-1]

for i in range(n-2,-1,-1):
	soma = 0
	for j in range(i,n):
		soma = soma + A[i][j]*x[j]
	x[i] = (b[i] - soma)/A[i][i] 

print("matriz solução:")
print(x) #resolução


#calculando vetor residual

for i in range(0,n):
	for j in range(0,n):
		r[i] += C[i][j]*x[j]

for i in range(0,n):
	r[i] = c[i] - r[i]

print("vetor residual:")
print(r)

#norma do vetor residuo
norma = 0
for i in range(0,n):
	norma = r[i]**2 + norma
norma = math.sqrt(norma)
print("Norma:")
print(norma)
