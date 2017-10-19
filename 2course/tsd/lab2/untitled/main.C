#include <iostream>
#include <fstream>
#include <string.h>
#include <assert.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

/// Структура
struct lit
{
    char surname [20] ;  // фамилия автора
    char title[60]; // название книги
    char ph[40]; //издательство
    int nl; // количество страниц
    char kind[20]; //тип
    union
    {
        char kindhud[20];
        struct
        {
            char sphere[20];
            char origin[20];
            int year;
        } tech;
    } type;

};
struct lit1
 {
    char surname[20];
    int number;
};

///ПРОВЕРКИ ВВОДА
bool proverka_hudkind(char y[])
{
    if (!strcmp(y,"fantastic")||!strcmp(y,"detective")||!strcmp(y,"roman")|| !strcmp(y,"drama")|| !strcmp(y,"stihi")
       || !strcmp(y,"komedia") || !strcmp(y,"satira") || !strcmp(y,"piesa"))
            return 1;
            else return 0;
}
bool proverka_kind(char y[])
{
    if (!strcmp(y,"tech")||!strcmp(y,"hud"))
            return 1;
            else return 0;
}

bool proverka_tech_sphere(char y[])
{
    if (!strcmp(y,"maths")||!strcmp(y,"economic")||!strcmp(y,"physics")|| !strcmp(y,"programming"))
            return 1;
            else return 0;
}

bool proverka_tech_origin(char y[])
{
    if (!strcmp(y,"russian")||!strcmp(y,"perevod"))
            return 1;
            else return 0;
}

///-
/// добавление записи
void add(lit &a,int num)
{
    cout<<"Input author's surname: ";
    cin>>a.surname;
    cout<<"\n";
    cout<<"Input title of book: ";
    cin>>a.title;
    cout<<"\n";
    cout<<"Input publishing house: ";
    cin>>a.ph;
    cout<<"\n";
    int fail=0;
     do
    {
        fail=1;
    cout<<"Input number of pages: ";

           cin >> a.nl;
          assert(a.nl);


 ;
    if( a.nl<0) cout<<"Error\n";
   //  assert(a.nl); для 0 не работает
    } while (a.nl<0);

    do
    {
    cout<<"\nInput kind of book(tech or hud): ";
    cin>>a.kind;
    } while (!proverka_kind(a.kind));
   if (!strcmp(a.kind,"hud"))
   {
       do
       {
       cout<<"\nInput genre book(fantastic, detective,roman,drama,stihi, komedia,satira, piesa): ";
       cin>>a.type.kindhud;
       } while (!proverka_hudkind(a.type.kindhud));
   }
   else
   {
       do
       {
       cout<<"\nInput sphere of this tech book(maths,physics, programming, economic): ";
       cin>>a.type.tech.sphere;
       }while (!proverka_tech_sphere(a.type.tech.sphere));

       do
       {
       cout<<"\nOrigin(russian, perevod): ";
       cin>>a.type.tech.origin;
       }while (!proverka_tech_origin(a.type.tech.origin));

       cout<<"\nYear: ";
       cin>>a.type.tech.year;

       assert(a.type.tech.year);
   }


}

/// сортировка
 template <typename T>
void bubblesort(T array[], int col){
T temp;

  for (int i=1; i<col ; i++)
  {
    for (int j=0; j<col-i; j++)
    {
      if ( strcoll(array[j].surname,array[j+1].surname)>0)
      {
         temp=array[j];
         array [j]=array [j+1];
         array [j+1]=temp;
       }
    }
   }
}
template<typename T>
void ShellsSort(T A[], unsigned N)
{
    int i,j,k;
    T t;
    for(k = N/2; k > 0; k /=2)
        for(i = k; i < N; i++)
        {
            t = A[i];
            for(j = i; j>=k; j-=k)
            {
                if(strcoll(t.surname,A[j-k].surname)<0) //или меньше, или больше
                    A[j] = A[j-k];
                else
                    break;
            }
            A[j] = t;
        }
}

void vuvod_tech(lit a)   /// вывод техлитры
{
    cout<<"\n\nAuthor: "<<a.surname<<"\n";
    cout<<"Title: "<<a.title<<"\n";
    cout<<"Publishing house: "<<a.ph<<"\n";
    cout<<"Number of pages: "<<a.nl<<"\n";
    cout<<"Kind of literature: "<<a.kind<<"\n";
    cout<<"Sphere: "<<a.type.tech.sphere<<"\n";
    cout<<"Origin: "<<a.type.tech.origin<<"\n";
    cout<<"Year: "<<a.type.tech.year<<"\n";
    return;
}
void vuvod_hud(lit a)   /// вывод техлитры
{
    cout<<"\n\nAuthor: "<<a.surname<<"\n";
    cout<<"Title: "<<a.title<<"\n";
    cout<<"Publishing house: "<<a.ph<<"\n";
    cout<<"Number of pages: "<<a.nl<<"\n";
    cout<<"Kind of literature: "<<a.kind<<"\n";
    cout<<"Genre: "<<a.type.kindhud<<"\n";

    return;
}

int main()
{
    lit uu[50];
    int m,i=0;
    int flag=0;
    double durationb1,durationb;
    double durationsh,durationsh1;
    int year; // god
    char otrasl[20];
    int dlina=20;
    ifstream base("io.txt");
    if (!base.is_open()) // если файл не открыт
    {
            cout << "File open error!\n";
            return 0;
    }
    ///ВВОД
    for(i=0;i<20;i++)
    {
       base>>uu[i].surname;
      // cout<<uu[i].surname<<"\n";
       base>>uu[i].title; // название книги
       base>>uu[i].ph; //издательство
       base>>uu[i].nl; // количество страниц
       assert(uu[i].nl);
       base>>uu[i].kind; //тип
       if(uu[i].kind[0]=='t')
       {
           base>>uu[i].type.tech.sphere;
           base>>uu[i].type.tech.origin;
          base>>uu[i].type.tech.year;
          assert(uu[i].type.tech.year);
       }
       else
             base>>uu[i].type.kindhud;

       }
     base.close();
     ///-
     /// создаем массив ключей
     lit1 uu1[50];
     for(int i=0;i<dlina;i++)
     {
         strcpy(uu1[i].surname,uu[i].surname);
         uu1[i].number=i;
     }
     do  ///Менюшка
     {
     cout<<"Choose the function of the programm:\n";
     cout<<"0)Diplay piece of table\n";
     cout<<"1)Add new record\n";
     cout<<"2)Delete last record\n";
     cout<<"3)Display a list of translated technical books\n";
     cout<<"4)Sort table\n";
     cout<<"5)Sort table of keys\n";
     cout<<"6)Exit\n";
     cout<<"7)Compare sort table and sort table of keys\n>>";
     cin>>m;
     switch (m)
     {
     case 0:
     {
         int a,b;
         do
         {
         cout<<"Enter the interval display table(not more 21 interval)\n";
         cout<<"Enter left border(0<=a<"<<dlina<<") a=";
         cin>>a;


         cout<<"Enter right border("<<a<<"<=b<"<<((a+20)<dlina?dlina:a)<<") b=";
         cin>>b;

         } while ((((b-a)>20)||(b>dlina-1)||(a>b)||(a<0)));
         for(i=a;i<=b;i++)
         {
             if(uu[i].kind[0]=='t') vuvod_tech(uu[i]);
             else
                 vuvod_hud(uu[i]);
             cout<<"\n";
         }

         break;

       }
case 1: {
         if (dlina==49)
         {
            cout<<"Error, too long";
            continue;
         }
            dlina++;
         add(uu[dlina-1],dlina);
         flag=0;
         cout<<"The record was successfully added"<<endl;
         cout<<"Times of sorting were zeroed"<<endl;
         break;
     }
case 2:
     {
         if(dlina==1)
         {
             cout<<"error\n";
             continue;
         }
         dlina--;
         cout<<"Last record was deleted\n";
         flag=0;
         cout<<"\ntimes of sorting were zeroed"<<endl;
         break;};

  case 3:{

     cout<<"Input the maximum year of publication: "; // в теории, неплохо бы проверить, что это число
     cin>>year;
     assert(year); // сойдет
     do
     {
     cout<<"\nSphere of book(maths,economic, programming, physics): ";
     cin>>otrasl;
     if (!proverka_tech_sphere(otrasl)) cout<<"Input correct data!\n";
     }while (!proverka_tech_sphere(otrasl));
     cout<<"\n";
     int z=0; // счетчик выведенных книг
     for(i=0;i<41;i++)

         if (uu[i].kind[0]=='t'&& uu[i].type.tech.sphere[1]==otrasl[1]
                 && uu[i].type.tech.origin[0]=='p'
                 &&uu[i].type.tech.year<=year)
         {
             vuvod_tech(uu[i]);
             z++;
         }
     if(z==0) cout<<"Sorry, there arent such books\n";//если не выведено ни одной такой книги


     break;
     }
     /// СОРТИРОВКИ
     // bubblesort
    case 4:
     {
         lit u1[50];
         for(int i=0;i<dlina;i++)
           u1[i]=uu[i];
        //пузыркьком
       double start_time =  clock();
       for(int i=0;i<10000;i++)  bubblesort(uu,dlina);
         double end_time = clock();
          durationb=end_time - start_time;
         cout<<"Array was sorted by bubblesort. Time:"<<scientific<<durationb/10000<<" ms";
          //шеллом
         if (flag==1) flag=2;
         if (flag==0) flag=1;

          start_time =  clock();
         for(int i=0;i<10000;i++)  ShellsSort(uu,dlina);
           end_time = clock();
            durationsh=end_time - start_time;
           cout<<"\nArray was sorted by ShellsSort. Time:"<<scientific<<durationsh/10000<<" ms";


         break;
     }

     case 5:
     {
         lit1 ua1[50];
         for(int i=0;i<dlina;i++)
           ua1[i]=uu1[i];
       double start_time =  clock();

         for(int i=0;i<10000;i++)  bubblesort(uu1,dlina);
        double    end_time = clock();
            durationb1=end_time - start_time;
           //bubblesort(uu,dlina); //ну это такое
           cout<<"Array of keys was sorted by bubblesort. Time:"<<scientific<<durationb1/10000<<" ms";
           if (flag==1) flag=2;
           if(flag==0) flag=1;
           start_time =  clock();
          for(int i=0;i<10000;i++)  ShellsSort(ua1,dlina);
            end_time = clock();
             durationsh1=end_time - start_time;
             cout<<"\nArray of keys was sorted by ShellsSort. Time:"<<scientific<<durationsh1/10000<<" ms\n"<<endl;

             int a,b;
             do
             {
             cout<<"Enter the interval display table(not more 21 interval)\n";
             cout<<"Enter left border(0<=a<"<<dlina<<") a=";
             cin>>a;
             cout<<"Enter right border("<<a<<"<=b<"<<((a+20)<dlina?dlina:a)<<") b=";
             cin>>b;

             } while ((((b-a)>20)||(b>dlina-1)||(a>b)||(a<0)));

             for(i=a;i<=b;i++)
             {
                 if(uu[ua1[i].number].kind[0]=='t') vuvod_tech(uu[ua1[i].number]);
                 else
                     vuvod_hud(uu[ua1[i].number]);
                 cout<<"\n";
             }
           break;
     }
case 7:
     {if (flag!=2)
            { cout<<"use items 4 5 before this";break;}
         cout<<"\nBubblesort O(n^2) "<<endl;
         cout<<"Real time  sorting table            "<<scientific<<durationb/10000<<" ms"<<endl;
         cout<<"Real time sorting table of keys     "<<scientific<<durationb1/10000<<endl;

         cout<<"\nShellsSort O(n*log(n)) "<<endl;
         cout<<"Real time  sorting table            "<<scientific<<durationsh/10000<<" ms"<<endl;
         cout<<"Real time sorting table of keys     "<<scientific<<durationsh1/10000<<endl;
         lit1 uu1[50];
         cout<<"\nMemory for table "<<sizeof(uu[0])/50*dlina<<" bytes"<<endl;
         cout<<"Memory for table of keys "<<sizeof(uu1[0])/50*dlina<<" bytes"<<endl;
         break;
     }

     default: { if(m!=6) cout<<"Input error";}
};
     cout<<"\n\n";
     }

while (m!=6);

exit;
    return 0;
}
