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
    cout<<"And if your input will be right, we will multiply numbers\n";
    for(int i=0;i<46;i++) cout<<' ';
    cout<<"|\n";
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

    {z++;
        i++;
    }
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

int multiply(int &znak1,char b[40], char c[40],int chislo[63])
{
    int a[35], d[35]; /// числа для умножения
    int i,m; ///счетчики
    int perv=0, vtor=strlen(c); /// длина первого и второго числа
    int tochka1=-1; /// положение точки
    int yu=0;
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
        if (b[0]=='-') znak1++;
        i++;
         perv--;
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
    // убираем незначащие нули в конце-заготовка
   // tochka1=tochka(b);
   // while (b[tochka--]=='0') yu++;
    //if (yu==tochka(b))
    ///перегоняем второе число в массив
    i=0;
    m=vtor-1;
    if (c[0]=='+'||c[0]=='-')
    {
        if (c[0]=='-') znak1++;
        i++;
        m--;
       vtor--;
    }
    while (i<=vtor)
    {
        d[m--]=c[i]-'0';

        i++;
    }
     length=perv+vtor;
  //cout<<"\nperv"<<perv<<"\nvtor"<<vtor<<"\n";
   for(int j=0;j<=62;j++) chislo[j]=-1;

   /// Поразрядное перемножение чисел

    for (int ix = 0; ix <perv; ix++)
        for (int jx = 0; jx <vtor; jx++)
        {
            if (chislo[ix+jx]<0)
                chislo[ix+jx]=0;// костыль
                 chislo[ix + jx] += a[ix] * d[jx];
                 //]\
                 cout<<"\n chisla a[ix] d[jx]"<<a[ix]<<" "<<d[jx]<<" proz "<<chislo[ix+jx]<<"\n";
        };
    for (int ix = 0; ix < (length); ix++)
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
int normalize(int chislo[62],int len1,int y, char uu[40], int znak)
{
    int znakmant=(znak%2==0)?1:-1;  /// знак мантиссы

    int i;  // cчетчик
    int chislolen=0; //длина произведения
    int m=1; // счетчик дробной части
    int chislolen_save; //сохраняем длину числа
   if (chislo[0]<0) chislo[0]=0; // красиво выводим 0 -отсюда вылезает десятка в 0
    int z=0;


    for(;chislo[chislolen]>=0;chislolen++);
    chislolen_save=chislolen;
    //cout<<chislolen<<" dlina\n";

    if (chislolen>30)
    {
        while(chislolen>30)
        {
              //cout<<y;
            if (len1>0) len1--;
                    else y++;

            if(chislo[z]>4)
            {
                m=1;


                // cout<<"tyt\n";
                 cout<<chislo[z]<<"tyt\n"<<chislo[z+m];
                while ((++chislo[z+m])%10==0)
                {

                    chislo[z+m]%=10;
                    m++;

                    //cout<<"ss";
                }
             }
            chislolen--;
            z++;
        }
    }
//cout<<y;
    /// Число не длиннее 30 знаков
    i=chislolen-len1; //количество цифр до точки
    m=chislolen_save;
    m--;
     if(i>0) for(;i;i--,y++); // тупо увеличиваем порядок числа из-за сдвига
     else
         {
         i=abs(i);
         for(;i;i--,y--);
     }

    if (znakmant>0)
        uu[0]='+';
    else
        uu[0]='-';
        uu[1]='0';
        uu[2]='.';

    for(i=3;m>=z;i++, m--)
      {
        uu[i]=chislo[m]+'0';
       }
          uu[i++]='E';
    if (y>0)
        uu[i++]='+';
    else
        uu[i++]='-';

    if (abs(y)>99999)
        return 1; // переполнение порядка в результате умножения
    i+=5;
    for(int j=0;j<5;j++)
    {
    uu[--i]=abs(y%10)+'0';
    y/=10;
    };
    uu[i+5]='\0';

    return 0;
}

int main()
{
    char b1[40], b2[40],d[40]="", uu[40];
    int chislo[63];
    int znak1=0;
    input(b1,b2);
    delprob(b1,d);
    strcpy(b1,d);

    if (proverka1(b1)||proverka2(b2) || strlen(b1)==0
            || strlen(b2)==0)
     {
          cout<<"Incorrect input";
          return 0;
     }
     multiply(znak1,b1,b2,chislo); ///умножаем часть до экспоненты на целую
     cout<<"\n";
     //int i;
    // for(i=62;chislo[i]<0;i--);
     //for(;i>-1;i--) cout<<chislo[i];
     cout<<"\n";
      if (normalize (chislo,tochka(b1),poryadok(b1), uu, znak1))
      {
          cout<<"Error";
          return 1;
      }
     cout<<"Multiply: "<<uu;
    return 0;
}
