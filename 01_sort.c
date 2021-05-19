#include <stdio.h>
#include <malloc.h>
FILE *f;

void comb(int Mass[], int N)
{
    int Size = N - 1, i, V, t=0;
    while (Size >= 1)
    {
        i = 0;
        while ((i + Size) < N)
        {
            if (Mass[i] > Mass[i + Size]) changes(Mass, N, i, i+Size, &t);
            i++;
        }
        Size = Size / 1.247;
    }
    for (i = 0; i < (N - 1); i++)
        if (Mass[i] > Mass[i + 1]) changes(Mass, N, i, i + 1, &t);
}

int Shell(int Mass[], int N)
{
    int Size = N, i, j, k, v, t=0;
    while (Size != 1)
    {
        if (Size % 2 == 1) Size++;
        Size = Size / 2;
        i = 0;
        j = i + Size;
        while (j < N)
        {
            k = i;
            while (Mass[k] > Mass[j])
            {
                changes(Mass, N, i, j, &t);
                k = k - Size;
                j = j - Size;
                if ((k < 0) || (j < 0)) break;
            }
            j = i + Size + 1;
            i++;
        }
    }
    return 1;
}

void changes(int Mass[], int N, int i, int j, int *t)
{
    int V = Mass[i];
    Mass[i] = Mass[j];
    Mass[j] = V;
    if ((*t) != 0) fprintf(f, "\n");
    else (*t)++;
    for (int k = 0; k < N; k++)
    {
        if (k != 0) fprintf(f, " ");
        fprintf(f, "%d", Mass[k]);
    }
}

int main()
{
    int *Mass = (int*)malloc(sizeof(int)), *Mass1 = (int*)malloc(sizeof(int)), N, i, t = 0;
    double k;
    scanf("%lf", &k);
    N = k;
    Mass = (int*)realloc(Mass, N * sizeof(int));
    Mass1 = (int*)realloc(Mass1, N * sizeof(int));
    for (i = 0; i < N; i++)
    {
        scanf("%lf", &k);
        Mass[i] = k;
        Mass1[i] = k;
    }
    f = fopen("combsort.log", "w+");
    fclose(f);
    f = fopen("combsort.log", "w+");
    comb(Mass, N);
    fclose(f);
    t = 0;
    f = fopen("shellsort.log", "w+");
    fclose(f);
    f = fopen("shellsort.log", "r+");
    Shell(Mass1, N);
    fclose(f);
    for (int k = 0; k < N; k++)
    {
        if (k != 0) printf(" ");
        printf("%d", Mass[k]);
    }
    return 0;
}
