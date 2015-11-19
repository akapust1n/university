#include <stdio.h>
#include <string.h>
#include <time.h>
char *p=0;
int *p1=0;//указатель на int стек
char b[10][2];//максимальное величина стека
int  b1[30]; //для подсчета элементов уже
#define   MAX_SIZE 9
#define   MAX_SIZE1 30
//показ верхнего элемента массива

struct per
{
    int value;
    char variable;
} yy[MAX_SIZE1];;

char top_array()
{
    char f=*(p-sizeof(b[0]));
    return f;
}
int top_array_int()
{
    int f=*(p1-sizeof(b1[0]));
    return f;
}
//добавление элемента в массив
void add_array(char f)
{
    char h[2];
    h[1]='\0';
    h[0]=f;
 //printf("%s",*p);
     if(p<b[0]) {p=b[0];}
    if (p<=(b[MAX_SIZE]))
    {
        strcpy(p,h);
        p=p+sizeof(b[0]);

}
            else
    {
       // cout<<"\nStack is full now"<<endl;
    }

//cout<<(&p+sizeof(b[0]))<<" x \n";
    return;
}
void add_array_int(int h)
{
  //  printf("%d %d",p1,b1[0]);
    if(p1<b1)
          {p1=b1;}
   if (p1<=(&b1[MAX_SIZE1]))
   {
       (*p1)=h;

       p1=p1+sizeof(int);

}

    return;
}

void del_array()
{
    if (p>=b[0])
    {
       // cout<<"\nLast element was deleted\n";
        p-=sizeof(b[0]);
       }
    else
      // cout<<"\nStack is empty now\n";
    return ;

}
void del_array_int()
{
    if (p1>=b1)
    {
       // cout<<"\nLast element was deleted\n";
        p1-=sizeof(b1[0]);
       }
    else
      // cout<<"\nStack is empty now\n";
    return ;

}


//добавляем число в строку
void add_stroka(char stroka[],char h)
{
    char y[2];
    y[1]='\0';
    y[0]=h;
   strcat(stroka,y);

    return;
}

//проверяем переменная ли это
int isCharacter(char h)
{
    int ord=(int)h;
    //printf("%d\n", ord);
   // printf("%c", h);
    if ((ord>64 &&ord<91)||(ord>96&&ord<123)) return 1;
    else return 0;

}
//проверяем функция это или открывающая скобка ли это
int isFunction(char h)
{
    int ord=(int)h;
if (ord==40) return 1; // ) тут можно добавить потом функции
    else return 0;

}
//проверяем оператор ли это
int isOperator(char h)
{
   int ord=(int)h;
   if (ord==42|| ord==43|| ord==45 || ord ==47 || ord==94) return 1;            //* + - / ^
   return 0;
}
int prioritet(char h)
{

    if (h=='^') return 3; //^
    if (h=='*'||h=='/') return 2;
     if (h=='-'||h=='+') return 1;

         //printf("Error\n ");
    return 0 ;
}

int  isMinusPlus(char h)
{
    if (h=='-'||h=='+') return 1;
    else
        return 0;
}

int fromChartoNum(char t,struct  per yy[])
{
    for(int i=0;yy[i].variable;i++)
        if(yy[i].variable==t) {;return yy[i].value;}
    return 0;
}
int notbeEarly(char t,struct  per yy[])
{
    for(int i=0;yy[i].variable;i++)
        if(yy[i].variable==t) return 0;
    return 1;
}
//операция между двумя числами
 int operation(int a,int b, char oper)
 {
 switch (oper)
 {
 case '*': return a*b;
 case '-': return b-a;
 case '+': return b+a;
 case '/': { return b/a;}
 case '^': {
     int z=1;
     do {
         a--;
         z = z * b;
         } while (a != 0);
     return z;

 }
 }
 return ;
 }
int main()
{
char stroka[50];
char f[50];
strcpy(stroka,"");
printf("Input expression: ");
gets(f);
int i=0;

while (f[i])
{

if(isMinusPlus(f[i]))
  if (p>0&&isOperator(f[i-1])||f[i-1]=='('||f[i-1]==')') add_stroka(stroka,'0'); //10 проверок из 10
    else if(i==0) add_stroka(stroka,'0');
if (isCharacter(f[i]))
{

    add_stroka(stroka,f[i]); //если число переменная-добалвяем её к выходной строке

}
else
   if (isFunction(f[i])) add_array(f[i]); //если число функций(а их нету) или открывающая скобка
else
   if (f[i]==')')
   { //в теории тут должна быть проверка на правильность ввода c:
     while(top_array()!='(')
        {
         if (top_array!=')') add_stroka(stroka,top_array());
         del_array();
        }
  del_array(); //удаляем открывающую скобку
}

else

       if (isOperator(f[i])) {
           //int u=prioritet(top_array());
          // printf("%d", top_array());
          // printf("%d",p>=b[0]);
           int u;
           while (p>=b[0])
           {
               u=prioritet(f[i]);
               if (prioritet(top_array())<u) break;

             add_stroka(stroka,top_array());

             del_array();
           }
           add_array(f[i]);
       }
i++;

}
//когда строка закончилась

while (p>=b[0])
   {
    add_stroka(stroka,top_array());
    del_array();
}
printf("\nRPN %s\n",stroka);
// загоняем переменные в массив
int j=0;
for(int i=0;i<MAX_SIZE;i++)
    yy[i].variable='\0';

for(int i=0;i<strlen(stroka);i++)
{
    //int u=stroka[i];
    //добавляем

    if (isCharacter(stroka[i])&&notbeEarly(stroka[i],yy)) yy[j++].variable=stroka[i];
}
printf("\nEnter variables\n");

for(int i=0;yy[i].variable;i++)
{
printf("%c= ", yy[i].variable);
scanf("%d", &yy[i].value);
}
int flag=1;
//начинаем вычисление нашей записи
for(int i=0;i<strlen(stroka);i++)
{

 if (isCharacter(stroka[i])) {add_array_int(fromChartoNum(stroka[i],yy));}

 else
    { if(stroka[i]=='0') add_array_int(0);
     else if(isOperator(stroka[i]))
     {
         int i1=top_array_int();
         del_array_int();
         int i2=top_array_int();
         del_array_int();
       if((i1==0)&&(stroka[i]=='/')) { flag=0;printf("Zero divide error");}
       else
           add_array_int( operation(i1,i2,stroka[i]));
     }}

}
if(flag)printf("Result %d\n",top_array_int());

return 0;
}
//(a+b*c)/(d+e*b-f)


