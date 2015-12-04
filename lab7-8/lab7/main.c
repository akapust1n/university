#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <D:\13\Progr\lab7-8\lab7\types.c>

int isPunct_1(char name)
{
    int u=0;
    for(;u<100;u++)
        if (name==PuctuatorNames[u][0])
            return u;
return 0;
}

int ka(char p[],int * pos,char name[])
{     char st[200];
    int state=0;
    while (1)
    {

        char s=p[*pos];
       printf(" ss %s",p);
       // printf("s_ %c %d ",s);
        switch(state)
        {
           case 0:
            {
                         if ((s=='/'&& p[(*pos)+1]=='*')||((s=='*')&&(p[(*pos)+1]=='//'))) return 0;        //комментарий либо один на строчке, либо им заканчивается строка
                        if(*pos>(strlen(p))) return 0; // безопасность и пустые строки
                       printf("*pos%d %d ", *pos,(int)s);
                    if (s==' ' || (s<32)) {(*pos)++; printf("there"); break;} //убираем пробелы
                    if((*pos)==(strlen(p)-1)) return 1; //пробелы в конце
                if (s>64&&s<91||s>95&&s<123||s==95) state=1; //keyword or identifier
                else
                    if (s=='"') state =2; //one line commnent
                    else
                        if (s=='#') state =3; //#directive
                        else
                            if (s>47&&s<58) state=4; // число без знака в начале
                            else
                                if(isPunct_1((s))||s=='[')  state=5;
                                else
                                    if ((*pos)==strlen(p)) return 0; // пробел вконце строки
                                    else
                                    if(s=='\'') state=6;



             break;
             }
           case 1: //ключевые слова  || переменные
            {
                 printf("test");

                int z=0;
                while (s>64&&s<91||s>95&&s<123||s==95||s>47&&s<58)
                {
                    st[z++]=s;
                    s=p[++(*pos)];
                }
                st[z]='\0';
                int u=0;
                for(;u<37;u++) if (!strcmp(st,KeywordsName[u])) break;
                strcpy(name,st);
                //printf("%d",*pos);
                if(u==37)
                    return -1; //идентификатор
                else
                    return -2; //ключевое слово
                break;
            }
             case 2:
            {

                int z=0;
                while (1)
                {
                    (*pos)++;

                while(p[*pos]!='"')
                {
                    st[z]=p[*pos];
                    z++;
                    (*pos)++;
                }

                if (p[*pos+1]!='"') break;
                }
                (*pos)++;
                st[z]='\0';
                //printf("st %s\n",st);
                strcpy(name,st);
               // printf("%d",*pos);
                return -3; //комметарий
                break;

            }
            case 3:
            {
                (*pos)++;
                return -3;
                break;
            }
            case 4:
            {
             int z;
               if(st[0])  z=1;
               else z=0;
                //printf("\nINTERETIN P%s\n",p);
                while(p[*pos]>47&&p[*pos]<58)
                {
                    st[z]=p[*pos];
                    z++;
                    (*pos)++;
                } //считываем число до точки или знака экспоненты
                if(p[*pos]=='.')
                   {
                      st[z]=p[*pos];
                      z++;
                      (*pos)++;
                    while(p[*pos]>47&&p[*pos]<58)
                    {
                        st[z]=p[*pos];
                        z++;
                        (*pos)++;
                    };
                }

                    if (tolower(p[*pos])=='e')
                    {
                        st[z]=p[*pos];
                        z++;
                        (*pos)++;
                        if(p[*pos]=='+'||p[*pos]=='-')
                           { st[z]=p[*pos];
                            z++;
                            (*pos)++;}
                            while(p[*pos]>47&&p[*pos]<58)
                            {
                                st[z]=p[*pos];
                                z++;
                                (*pos)++;
                            }
                            (*pos)--; //потому что
                            (*pos)--;
                    }
                    st[*pos]='\0';
                 strcpy(name,st);
             return -5;
            }
            case 5:
            {
                int z=0;
              //  printf("INTerestin %c",p[(*pos)+1]);
                if(s=='+'||s=='-')
                  if(p[(*pos)+1]>47&&p[(*pos)+1]<58)
                  {
                      st[0]=s;
                      st[1]='\0';
                      strcpy(name,st);
                      (*pos)++;
                      state=4;
                      break;
                  }
                 // printf("Here");
                int u=isPunct_1(p[*pos]);
                while(isPunct_1(p[*pos])|| p[*pos]=='['){
                  if(u!=isPunct_1(p[*pos]))
                  {
                      //(*pos)--;
                      st[z]='\0';
                      strcpy(name,st);
                      return -6;
                  }
                    st[z]=p[*pos];
                    z++;



                    u=isPunct_1(p[*pos]);
                    (*pos)++;
                }
                st[z]='\0';
                strcpy(name,st);

                return -6;
            }
            case 6:
            {
                int z=0;
                (*pos)++;
                while(p[*pos]!='\'')
                {
                    st[z]=p[*pos];
                    z++;
                    (*pos)++;
                }
                (*pos)++;
                st[z]='\0';
                strcpy(name,st);

                return -7;
            }
        }
    }
}

const char *category(int i)
{
   switch(i)
   {
       case -2: return "Keyword";
       case -1: return "Identefier";
      // case -3: return "Comment";
      //case -4: return "Directive";
       case -5: return "Number";
       case -6: return "Punctuator";
       case -7: return "String literal";
   }
}

int main()
{
    FILE *f=fopen("1.txt","r");
    int number=1;
    int pos=0;
    char p[1000];
    char name[200];
    int len;
 int h=0;
    FILE *fout=fopen("2.xml","w");
    fprintf(fout,"<Table of tokens>\n");

    while (!feof(f))
    {
     // fflush(p);
       fgets(p,1000,f);
     pos=0;

   // if (h==10)

    //p[strlen(p)-1]='\0';
      //p[strlen(p)-1]='\0';

    //while(p[kk]) kk++;

     //printf("ord%d\n",h);

   // printf("KK_%c_",p[strlen(p)]);
     //puts(p);
       //  if(strlen(p)==0) continue; //особенность fgets
  // puts(p);


   if(strlen(p)==0) printf("%d",h);
   printf("op:%s\n",p);
    printf("number %d\n",h); h++;
    printf("len %d\n\n",strlen(p));
    // printf("%d",number);

        while(pos<(strlen(p)))
        {

          //  printf(" string ");
            len=pos;
           // printf("STRLEN%d",strlen(p));
           int key= ka( p,&pos, name);

           //  printf("\nKey%d\n",key);
            // printf("\nname is_%s\n",name);
             // printf("\n POS %d STRLEN %d\n", pos,strlen(p));

           if (key==-4 ||key==0 || key==-3 || key==1) break;

         //  if () break;
            len=pos-len;
            printf("hey");
            //распечатка токена
            fprintf(fout,"	<Token>\n");
            fprintf(fout," 		<Category_of_token>%s</Category_of_token>\n",category(key));
            fprintf(fout," 		<Name_of_token>%s</Name_of_token>\n",name);
            fprintf(fout," 		<Name_of_line>%d</Name_of_line>\n",number);
            fprintf(fout," 		<Position_in_line>%d</Position_in_line>\n",pos-len+1);
            fprintf(fout," 		<Length_name_of_token>%d</Length_name_of_token>\n",strlen(name));
            fprintf(fout,"	</Token>\n");

        }
        //strcpy(p,"");
        number++;
        printf("why1");
   // printf("U_i");
    }
    printf("\nEnd of programm");
    fclose(f);
    fclose(fout);

    return 0;
}
