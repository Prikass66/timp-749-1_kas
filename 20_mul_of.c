#include <stdio.h>

int main(void)
{
    double d;
    double pr=1;
    int i;
    int a;
    (void)scanf("%d", &a);
    for(i=1; i<=a; i++)
    {
        (void)scanf("%lf", &d);
        pr=(d-i)*pr;
    }
    printf("%lf", pr);
    return 0;
}

