#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
using namespace std;

int mas[60];
/// \brief Удаление пробелов из числа
/// \param [in] c[40] Входная строка с пробелами
/// \param [out] d[40] Выходная строка без пробелов
char *delprob(char c[40],char d[40])
{

    for(char* a=c, *b=d; *a; ++a, ++b){
            while(*a==' ') ++a;
            *b=*a;
        }
    return d ;
}

/// \brief Ввод чисел
/// \param [in] b1[40] Первое число
/// \param [in] b2[40] Второе число
void input(char b1[40], char b2[32])
{
    cout<<"Input the 1st number as +-m.n E +-K for example 99999 E 01+00008 \n";
    cout<<"abs(m) less then 10^30; abs(K) less then 10^5\n";
    cout<<"or you can enter a number in the usual form like .00025, +12300, -123.456 \n\n";
    cout<<"Input the 2nd number as integer number, which module less then 10^30\n";
    cout<<"And if your input will be right, we will multiply numbers\n\n";
    cout<<"Input 1st number:";
    gets(b1);
    cout<<"\nInput 2st number:";
    gets(b2);
    return  ;
}

/// \brief Проверка корректности ввода числа
/// \param [in] b1[40] Искомое число
int proverka1(char b[40])
{
    int i=0;
    int tochki=0;
    int z=0;

    if ((b[0]=='+')||(b[0]=='-'))
    {
        z=1;
        i++;
    }
    z+=30;
    /// Проверяем мантиссу
   while ((b[i]!='E')&&(i!=strlen(b)))
   {
        if (((b[i]<'0')||(b[i]>'9'))&&(b[i]!='.'))
            return 1;
        if (b[i]=='.')
        {
            tochki++;
            z++;
        }
        i++;
   }
   if ((i>z) ||(tochki>1))
           return 1;
        //слишком длинное число

   // /проверяем экспоненту
   if (b[i]=='E') i++;
   if ((b[i]=='-')||(b[i]=='+')) i++;
   for( ; b[i] && z<5 ; z++, i++)
   if ((b[i]<'0')||(b[i]>'9'))
       return 1;
   if (z==5) return 1;
       return 0;
}

/// \brief Проверка второго числа
/// \param [in] b[40] Искомое число
int proverka2(char b[40])
{
    int z=0,i=0,m=30;

    if ((b[0]=='-')||(b[0]=='+'))
        z++;
    while ((i<m)&&(i!=strlen(b)))
    {
        if ((b[i]<'0')||(b[i]>'9'))
           return 1;
        i++;
    }
    if ((i-z)>m)
        return 1;

    return 0;
}


int multiply(char b[40], char c[40],int chislo[62])
{
    int a[30], d[30]; /// числа для умножения
    int i,m; ///счетчики
    int perv=0, vtor=strlen(c); /// длина первого и второго числа
    int tochka=-1; /// положение точки
    int znak=0;  /// знак числа
    int length;

    /// находим мантиссы
    while((b[perv]!='E') && (perv!=strlen(b)))
    {
        perv++;

    }

    ///перегоняем первое число в массив(зеркальная запись)
    i=0;
    m=perv-1;
    if (b[0]=='+'||b[0]=='-')
    {
        znak++;
        i++;
       m--;
    }
    for(int j=0;j<strlen(b);j++) //костыль наличия точки
    {
        if (b[j]=='.')
        {
            perv--;
            m--;
            break;
        }
    }

    while ((b[i]!='E')&&(i<strlen(b)))
    {
        if (b[i]!='.')
            a[m--]=b[i]-'0';
        i++;
    }

    ///перегоняем второе число в массив
    i=0;
    m=vtor-1;
    if (c[0]=='+'||c[0]=='-')
    {
        znak++;
        i++;
        m--;
    }

    while (i<vtor)
    {
        d[m--]=c[i]-'0';
        i++;
    }


     length=perv+vtor;

   for(int j=0;j<62;j++) chislo[j]=-1;

   /// Поразрядное перемножение чисел

    for (int ix = 0; ix <perv; ix++)
        for (int jx = 0; jx <vtor; jx++)
        {
            if (chislo[ix+jx]<0) chislo[ix+jx]=0;// костыль
            chislo[ix + jx] += a[ix] * d[jx];


        }
 ;

    for (int ix = 0; ix < (length)&&(chislo[ix]); ix++)
    {
        if  (chislo[ix + 1]<0) chislo[ix+1]=0; //костыль
        chislo[ix + 1] +=  chislo[ix] / 10;

        chislo[ix] %= 10;

    }

    while (chislo[length]<1)
    {
        chislo[length]=-1;
        length--;

    }
    //if (chislo[i]);
    //for(;i>-1;i--) cout<<chislo[i];
    if (znak %2==1) chislo[0]*=-1; //если произведение отрицательное
    return 0;
}
/// \brief Получаем порядок числа
int poryadok(char b[40])
{
    int m=0, re;
    char por[7];
    for(;b[m]!='E';m++);
   m++;
    for(int i=m;i<strlen(b);i++)
    {
        por[i-m]=b[i];

    }

   return atoi(por);

}
/// \brief Нахождение позиции точки
int tochka(char b[40])
{

    for(int i=0;i<strlen(b);i++)
    { if (b[i]=='.')
        {
            int k=0;
            while (b[k+i+1]!='E'&&(k+i+1)<strlen(b)) k++;
            return k;    //возвращает количество символов после точки до знака экспонент
        }
    }

return 0;
}
/// \brief Нормализация числа
/// \param[in] chislo[62] искомое число разбитое в массив без порядка
/// \param[in] len1 количество знаков после точки(пережиток первого числа)
/// \param[in] y порядок
/// \param[out] b[40] нормализованное число на выход
///
int normalize(int chislo[62],int len1,int y, char uu[40])
{
    int znakmant=chislo[0]>0?1:-1;  /// знак мантиссы
    int znakexp=y>=0?1:-1; /// знак экспоненты
    int i;  // cчетчик
    int chislolen=0; //длина произведения
    int m=0; // счетчик дробной части
    chislo[0]=abs(chislo[0]); // меняем всё на положительное
    y=abs(y);

    for(;chislo[chislolen]>=0;chislolen++);


    /// Число не длиннее 30 знаков
    i=chislolen-len1; //количество цифр до точки
    m=i;
    m--;
    for(;i;i--,y++); // тупо увеличиваем порядок числа из-за сдвига

    if (znakmant>0)
        uu[0]='+';
    else
        uu[0]='-';
        uu[1]='0';
        uu[2]='.';

    for(i=3;m>=0;i++, m--)
       uu[i]=chislo[m]+'0';
          uu[i++]='E';
    if (znakexp>0)
        uu[i++]='+';
    else
        uu[i++]='-';
    if (y>1000000)
        return 1; // переполнение порядка в результате умножения

    for(int j=0;j<5;j++)
    {
    uu[i++]=y%10+'0';
    y/=10;
    };
    uu[i]='\0';
    cout<<"\n Chto u nas vyshlo  v itoge: "<<uu;
    cout<<"\n"<<m;
    return 0;
}

int main()
{
    char b1[40], b2[40],d[40]="", uu[40];
    int chislo[62];

    input(b1,b2);
    delprob(b1,d);
    strcpy(b1,d);

    if (proverka1(b1)||proverka2(b2))
    {
          cout<<"Incorrect input";
          return 0;
     }
     multiply(b1,b2,chislo); ///умножаем часть до экспоненты на целую
     cout<<chislo[2]<<"||"<<chislo[1]<<chislo[0];
     normalize (chislo,tochka(b1),poryadok(b1), uu);
    return 0;
}
