#include <stdio.h>

int main(void)
{
    double pr;
    double aft;
    int a;
    int i;
    int l;
    int out=1;
    (void)scanf("%d", &a);
    (void)scanf("%lf", &pr);
    for(i=1; i<a; i++)
    {
        (void)scanf("%lf", &aft);
        if(pr <= aft)
        {
            pr = aft;
            l = 1;
        }
        else
        {
            pr = aft;
            l = 0;
        }
        if((out == 1) && (l == 0))
        {
            out = 0;
        }
    }
    printf("%lf", (double)out);
    return 0;
}
