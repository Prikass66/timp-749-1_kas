#include <stdio.h>
#include <malloc.h>
FILE *f;
int PyramSort(int Mass[], int Size, int *t)
{
    int i, k, n, m, p, Elr, Ell, x, N = Size;
    k = (Size / 2) - 1;
    while (Size != 0)
    {
        i = k;
        while (i != (-1))
        {
            n = i;
            while (1)
            {
                p = 2 * n + 1;
                m = 2 * n + 2;
                if (p < Size) Ell = Mass[p];
                else Ell = -1001;
                if (m < Size) Elr = Mass[m];
                else Elr = -1001;
                if (Elr > Ell)
                {
                    if (Elr > Mass[n])
                    {
                        x = Mass[n];
                        Mass[n] = Mass[m];
                        Mass[m] = x;
                        n = m;
                        if ((*t) != 0) fprintf(f, "\n");
                        else (*t)++;
                        for (int k = 0; k < N; k++)
                        {
                            if (k != 0) fprintf(f, " ");
                            fprintf(f, "%d", Mass[k]);
                        }
                    }
                    else break;
                }
                else
                {
                    if (Ell > Mass[n])
                    {
                        x = Mass[n];
                        Mass[n] = Mass[p];
                        Mass[p] = x;
                        n = p;
                        if ((*t) != 0) fprintf(f, "\n");
                        else (*t)++;
                        for (int k = 0; k < N; k++)
                        {
                            if (k != 0) fprintf(f, " ");
                            fprintf(f, "%d", Mass[k]);
                        }
                    }
                    else break;
                }
            }
            i--;
        }
        Size--;
        if (Mass[0] > Mass[Size])
        {
            x = Mass[0];
            Mass[0] = Mass[Size];
            Mass[Size] = x;
            if ((*t) != 0) fprintf(f, "\n");
            else (*t)++;
            for (int k = 0; k < N; k++)
            {
                if (k != 0) fprintf(f, " ");
                fprintf(f, "%d", Mass[k]);
            }
        }
    }
    return 0;
}
int FastSort(int Mass[], int B, int E, int N, int *t)
{
    int i = B, j = E, v = 0, el = Mass[(E + B) / 2], elN=(E+B)/2;
    while (1)
    {
        while (Mass[i] < el) i++;
        while (Mass[j] > el) j--;
        if (i < j)
        {
            v = Mass[i];
            Mass[i] = Mass[j];
            Mass[j] = v;
            if (i != elN) j--;
            else elN = j;
            if ((j + 1) != elN) i++;
            else elN = i;
            if ((*t) != 0) fprintf(f, "\n");
            else (*t)++;
            for (int k = 0; k < N; k++)
            {
                if (k != 0) fprintf(f, " ");
                fprintf(f, "%d", Mass[k]);
            }
        }
        else break;
    }
    if ((i - B-1) > 0) FastSort(Mass, B, i-1, N, t);
    if ((E - i-1) > 0) FastSort(Mass, i+1, E, N, t);
    return 0;
}
int main()
{
    int *Mass = (int*)malloc(sizeof(int)), *Mass1 = (int*)malloc(sizeof(int)), N, i, y = 0;
    double g;
    scanf("%lf", &g);
    N = g;
    Mass = (int*)realloc(Mass, N * sizeof(int));
    Mass1 = (int*)realloc(Mass1, N * sizeof(int));
    for (i = 0; i < N; i++)
    {
        scanf("%lf", &g);
        Mass[i] = g;
        Mass1[i] = g;
    }
    f = fopen("fastsort.log", "w+");
    fclose(f);
    f = fopen("fastsort.log", "w+");
    FastSort(Mass, 0, N - 1, N, &y);
    fclose(f);
    y = 0;
    f = fopen("pyramsort.log", "w+");
    fclose(f);
    f = fopen("pyramsort.log", "r+");
    PyramSort(Mass1, N, &y);
    fclose(f);
    for (int k = 0; k < N; k++)
    {
        if (k != 0) printf(" ");
        printf("%d", Mass[k]);
    }
    return 0;
}