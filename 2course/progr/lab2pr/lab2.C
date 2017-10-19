#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
double func(double x)
{
    return (x*x*x*x-2*x*x*x+3*x*x-4);
}
double func1(double x)
{
    return(4*x*x*x-6*x*x+6*x);
}
double func2(double x)
{
    return (12*x*x-12*x+6);
}
long double Y(double x)
{
return  ((x*x*x)+ (3*x*x)-2);
}
// половинного деление , хорд, ньютона( касательные)
double newton(double a,double b, double eps)
{
    double c;
    if(func(a)*func2(a)>0) c=a;
    else c=b;
    do {
        c=c-func(c)/func1(c);

    }
    while (fabs(func(c))>=eps);
    return c;
}

double poldel(double a,double b, double e)
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

double hord(double a, double b, double e)
{

while(fabs(func(b)) > e)
{
a = b - ((b - a) * func(b))/(func(b) - func(a));
b = a - ((a - b) * func(a))/(func(a) - func(b));
}
return b;
};
/// для интеграла
double trivosm(double a,double b,double eps)
{
    int z;
double h,s,x;
int m;
int n;
n=floor((b-a)/sqrt(eps))+1;
h = (b - a)/ (3*n);
s = Y(a)+Y(b);
m=3*n-1;

   for ( z=1; z<= m; z++)
            {
                x = a + h*z;
                if (z%3 == 0)
                    s = s + 2 * Y(x);
                else
                    s = s + 3 * Y(x);
            }

s = s*3/8*h;
return s;
}
double simpson( double a, double b, double eps)
{
           double I;
           double h;
           double x;

           int m;
             m=floor((b-a)/sqrt(eps))+1;
           h=(b-a)/(m-1);
           x = a;

           I = Y(a) + Y(b);
           int n=0;

           while (n < m-2)
           {
                   x = x+h;
                   if (n%2==0) I=I+4*Y(x);
                           else  I = I+2*Y(x);
                   n++;
           }

           return I*h/3;
}
double area(double a, double b, double eps)
{
    int i,n;
    n=floor((b-a)/sqrt(eps))+1;
double s=0, x=a, h=(b-a)/n;
if (n > 1)

 for( i=1; i<n; x+=h, s+=Y(x), i++);
return h*(Y(a)+Y(b)+2*s)/2;
}
int main()
{
    int i,z;
     double a,b, eps;
    printf("Choose function of programm:");
    printf("\n1)Integral count x^3+3x^2-2");
    printf("\n2)Find roots of function x^2-1\n");
    scanf("%d",&i);
    printf("Input left number:");
    scanf("%lf",&a);
    printf("Input right number:");
    scanf("%lf",&b);
    printf("\nInput accuracy:");
    scanf("%lf",&eps);
    assert(a<b);
    assert(eps>0);
    switch (i)
    {
       case  2 :
    {


    assert(a<b);
    assert(eps>0);
    printf("\nRoots:\n");
     double acc=0.3;
    double a1=a;
   // printf("\n%lf\n",a);
    printf("Poldel:\n");

    double b1=a1+acc;
    while(a1<b)
    {
       if (func(a1)*func(b1)<0)
       printf("%lf\n",poldel(a1,b1,eps));
       a1+=acc;
       b1+=acc;
    };
    printf("\nNewton:\n");
    a1=a;
    b1=a+acc;
    while(a1<b)
    {
       if (func(a1)*func(b1)<0)
       printf("%lf\n",newton(a1,b1,eps));
       a1+=acc;
       b1+=acc;
    }
    printf("\nHord:\n");
    a1=a;
    b1=a+acc;
    while(a1<b)
    {
       if (func(a1)*func(b1)<0)
       printf("%lf\n",hord(a1,b1,eps));
       a1+=acc;
       b1+=acc;
    };
    break;
    }
    case 1:
    {
       // printf("ss");
        printf("3/8 method:\n");
        printf("%lf\n",trivosm(a,b,eps));
        printf("Simpson method:\n");
        printf("%lf\n",simpson(a,b,eps));
        printf("Trapezii method:\n");
        printf("%lf\n",area(a,b,eps));

        break;
       }
    default: printf("Incorrect input");
}

   // printf("lol");
    return 0;
}
