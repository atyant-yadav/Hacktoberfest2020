int getId(int M[MAX][MAX], int n)
{
    int cel = 0;
    for (int i = 1; i < n; i++)
        if (M[cel][i])
            cel = i; //prev cel can't be celebrity
    for (int i = 0; i < n; i++)
        if ((cel != i) && (M[cel][i] || !M[i][cel]))
            return -1;
    return cel;
}
