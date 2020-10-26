matriz = [];
quantidade_linhas = 2;
quantidade_colunas = 2;

for l in range(quantidade_linhas):
    colunas = [];
    for c in range(quantidade_colunas):
        quantidade = int(input("Informe o elemento [{}][{}]:".format(l, c)));
        colunas.append(quantidade);

    matriz.append(colunas);
