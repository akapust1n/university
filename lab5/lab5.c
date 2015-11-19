#include <stdio.h>
int week_day_in(char str[])
{
  if( !strcmp(str, "MON,"))  return 0;
  if( !strcmp(str, "TUE,"))  return 1;
  if( !strcmp(str, "WED,"))  return 2;
  if( !strcmp(str, "THU,"))  return 3;
  if( !strcmp(str, "FRI,"))  return 4;
  if( !strcmp(str, "SAT,"))  return 5;
  if( !strcmp(str, "SUN,"))  return 6;

}
char* week_day_out(int week)
{
    week%=7;
  switch(week){
  case(0):{ return "MON,";break;}
  case(1):{ return "TUE,";break;}
  case(2):{ return "WED,";break;}
  case(3):{ return "THU,";break;}
  case(4):{ return "FRI,";break;}
  case(5):{ return "SAT,";break;}
  case(6):{ return "SUN,";break;}

  }

}
int month_in(char str[])
{
    if( !strcmp(str, "JAN"))  return 0;
    if( !strcmp(str, "FEB"))  return 1;
    if( !strcmp(str, "MAR"))  return 2;
    if( !strcmp(str, "APR"))  return 3;
    if( !strcmp(str, "MAY"))  return 4;
    if( !strcmp(str, "JUN"))  return 5;
    if( !strcmp(str, "JUL"))  return 6;
    if( !strcmp(str, "AUG"))  return 7;
    if( !strcmp(str, "SEP"))  return 8;
    if( !strcmp(str, "OCT"))  return 9;
    if( !strcmp(str, "NOV"))  return 10;
    if( !strcmp(str, "DEC"))  return 11;

}
char * month_out(int month)
{
   switch(month){
   case(0):{return "JAN";break;}
   case(1):{return "FEB";break;}
   case(2):{return "MAR";break;}
   case(3):{return "APR";break;}
   case(4):{return "MAY";break;}
   case(5):{return "JUN";break;}
   case(6):{return "JUL";break;}
   case(7):{return "AUG";break;}
   case(8):{return "SEP";break;}
   case(9):{return "OCT";break;}
   case(10):{return "NOV";break;}
   case(11):{return "DEC";break;}
   }


}
int year_in(char b[]) //небольшой отход от условия, если год меньше 100- то он в 20 веке
{
    int y=atoi(b);
     if (y<100) y+=1900;
     return y;
}
int otkl_in(char str[]) //возвращает отклонение в минутах
{

   if( !strcmp(str, "UT"))  return 0;
   if( !strcmp(str, "GMT"))  return 0;
   if( !strcmp(str, "EDT"))  return -4*60;
   if( !strcmp(str, "CDT"))  return -5*60;
   if( !strcmp(str, "MDT"))  return -6*60;
   if( !strcmp(str, "PDT"))  return -7*60;

  return (atoi(str)/100*60+atoi(str)%100);
}
int date_out_plus(int* date,int *month,int * year) //усли дата увеличилась
{
    //printf("%d m",*month);
    switch (*month)
    {
    case 0:{ if ((*date)>30) {(*month)++;*date=1;}break;}
    case 1:{ if ((*date)>28) {if((*year%400==0||*year%100!=0&&*year%4==0)&&(*date>29)){
      *date=1;(*month)++; }else {*date=1;(*month)++;}} ;break;}
    case 2:{ if ((*date)>31) {(*month)++;*date=1;} break;}
    case 3:{ if ((*date)>30) {(*month)++;*date=1;} break;}
    case 4:{ if ((*date)>31) {(*month)++;*date=1;} break;}
    case 5:{ if ((*date)>30) {(*month)++;*date=1;} break;} //june
    case 6:{ if ((*date)>31) {(*month)++;*date=1;} break;}
    case 7:{ if ((*date)>31) {(*month)++;*date=1;}break;}
    case 8:{ if ((*date)>30) {(*month)++;*date=1;} break;}
    case 9:{ if ((*date)>31) {(*month)++;*date=1;} break;} //october
    case 10:{ if ((*date)>30) {(*month)++;*date=1;} break;}
    case 11:{ if ((*date)>31) {(*month)=0;*date=1;(*year)++;} break;}
    }


return *date;
}

int date_out_minus(int* date,int *month,int * year) //если дата уменьшилась
{
    switch (*month)
    {
    case 0:{ if ((*date)<1) {*month=11;*date=31;(*year)--;} break;}
    case 1:{ if ((*date)<1) {*month=0;*date=30;} break;}
    case 2:{ if ((*date)<1) {if(*year%400==0||*year%100!=0&&*year%4==0)
                       {(*month)--;*date=29;} else { (*month)--;*date=28;}} break;}
    case 3:{ if ((*date)<1) {(*month)--;*date=31;} break;} //апрель->март
    case 4:{ if ((*date)<1) {(*month)--;*date=30;} break;}
    case 5:{ if ((*date)<1) {(*month)--;*date=31;} ;break;} //июнь->май
    case 6:{ if ((*date)<1) {(*month)--;*date=30;} break;}
    case 7:{ if ((*date)<1) {(*month)--;*date=31;} break;}
    case 8:{ if ((*date)<1) {(*month)--;*date=31;} break;}
    case 9:{ if ((*date)<1) {(*month)--;*date=30;} break;} //october
    case 10:{ if ((*date)<1) {(*month)--;*date=31;} break;}
    case 11:{ if ((*date)<1) {(*month)--;*date=30;} break;}
    }

    return *date;
}

void update_msk(int sm,int * week, int* year,int *date,int *month,int *hour,int *minute) //приведение даты к мск
{
    int u=*hour*60+*minute+sm; //считаем итогове время в минутах
    *hour=u/60%24;
    *minute=u%60;

   // printf("%d  vs %d \n",u,24*60);
    if (u>=(24*60)) {  //переход через сутки вперед
        (*week)++;
//         printf("%d\n",*date);
        (*date)++;
        // printf("%d\n",*date);
        *date=date_out_plus(date,month,year); //после этого у нас изменен день, месяц и год уже
    }
    else
        if(u<0) //переход через сутки назад
           {     (*week)--;
                (*date)--;

                *date=date_out_minus(&date,&month,&year); //после этого у нас изменен день, месяц и год уже
            }
return;
}

int main()
{
    FILE *fp=fopen("in.txt","r");
    FILE *fp1=fopen("out.txt","w");
    char s[100];
    int week,date, month,year, hour,minute,secund,otkl;
    int sm; //смещение
    while (!feof(fp))
    {
        fgets(s,99,fp);
        char * pch = strtok (s," :");
              //cout <<pch<<endl;
              week=week_day_in(pch);
              pch = strtok (NULL, " :");
              date=atoi(pch);
              //printf("lol%d",date);
              pch = strtok (NULL, " :");
              month=month_in(pch);
              pch = strtok (NULL, " :");
              year=year_in(pch);
              pch = strtok (NULL, " :");
              hour=atoi(pch);
              pch = strtok (NULL, " :");
              minute=atoi(pch);
              pch = strtok (NULL, " :");
              secund=atoi(pch);
              pch = strtok (NULL, " :");
              otkl=otkl_in(pch);
              sm=180-otkl; //+3=60*3
              update_msk(sm,&week,&year,&date,&month,&hour,&minute);
              fprintf(fp1,"%s ",week_day_out(week));
              if(date>9) fprintf(fp1,"%d ",date);else fprintf(fp1,"0%d ",date);
              fprintf(fp1,"%s ",month_out(month));
              fprintf(fp1,"%d ",year);
              if (hour>9) fprintf(fp1,"%d:",hour); else fprintf(fp1,"0%d:",hour);
              if(minute>9) fprintf(fp1,"%d:",minute); else fprintf(fp1,"0%d:",minute);
              if (secund>9) fprintf(fp1,"%d ",secund); else fprintf(fp1,"0%d ", secund);
              fprintf(fp1,"+0300\n");


    }
    printf("You can see result of updating time in out.txt");
    return 0;
}
