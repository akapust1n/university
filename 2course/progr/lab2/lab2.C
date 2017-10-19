#include <stdio.h>
#include <assert.h>
double func(double x)
{
    return (x*x-1);
}

// половинного деление , хорд, ньютона( касательные)





int poldel(double a,double b, double e)
{
    double  c;

    do {
        c=(a+b)/2;
        if (func(c)*func(a)<=0) b=c;
        else a=c;

    }
    while (fabs(a-b)>=e);
     return c;
}

int main()
{
    double a,b,eps;
    printf("Input left and right interval limit\n");
    scanf("%a%a\n",&a,&b);
    printf("Enter accuracy:");
    scanf("%a",&eps);
    assert(func(a)*func(b)<=0);
    return 0;
}
