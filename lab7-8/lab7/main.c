#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <D:\13\Progr\lab7-8\lab7\types.c>

int isPunct_1(char name)
{
    int u=0;
    for(;u<100;u++)
        if (name==PuctuatorNames[u][0])
            return 1;
return 0;
}

int ka(char p[],int * pos,char name[])
{     char st[200];
    int state=0;
    while (1)
    {

        char s=p[*pos];
       // printf("%s",p);
        printf("s_ %c %d ",s);
        switch(state)
        {
           case 0:
            {
                if (s>64&&s<91||s>95&&s<123||s==95) state=1; //keyword or identifier
                else
                    if (s=='"') state =2; //commnent
                    else
                        if (s=='#') state =3; //#directive
                        else
                            if (s>47&&s<58) state=4; // число без знака в начале
                            else
                                if(isPunct_1((s))) state=5;
                                else
                                    if (s) (*pos)++;
               else if ((*pos)==strlen(p)) return 0; // пробел вконце строки
 //printf("state %d %d",(*pos), strlen(p));
             break;
             }
           case 1: //ключевые слова  || переменные
            {


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
                printf("st %s\n",st);
                strcpy(name,st);
                printf("%d",*pos);
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

                int z=0;
                printf("\nINTERETIN P%s\n",p);
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
                    }
                    st[*pos]='\0';
                 strcpy(name,st);
             return -5;
            }
            case 5:
            {
                int z=0;
                if(s=='+'||s=='-')
                  if(isdigit(p[(*pos)+1]))
                  {
                      st[0]=s;
                      (*pos)++;
                      state=4;
                      break;
                  }
                  printf("Here");
                while(isPunct_1(p[*pos])){
                    st[z]=p[*pos];
                    z++;

                    (*pos)++;
                }
                strcpy(name,st);

                return -6;
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
   }
}

int main()
{
    FILE *f=fopen("1.txt","r");
    int number=1;
    int pos=0;
    char p[10000];
    char name[200];
    int len;

    FILE *fout=fopen("2.xml","w");
    fprintf(fout,"<Table of tokens>\n");
    while (!feof(f))
    {

       fgets(p,10000,f);
     pos=0;
     puts(p);
        while(pos<(strlen(p)-1))
        {
          //  printf(" string ");
            len=pos;
           int key= ka( p,&pos, name);
             printf("\nKey%d\n",key);
             printf("\nname is_%s\n",name);
           if (key==-4 ||key==0 || key==-3 ) break;

         //  if () break;
            len=pos-len;

            //распечатка токена
            fprintf(fout,"	<Token>\n");
            fprintf(fout," 		<Category_of_token>%s</Category_of_token>\n",category(key));
            fprintf(fout," 		<Name_of_token>%s</Name_of_token>\n",name);
            fprintf(fout," 		<Name_of_line>%d</Name_of_line>\n",number);
            fprintf(fout," 		<Position_in_line>%d</Position_in_line>\n",pos-len+1);
            fprintf(fout," 		<Length_name_of_token>%d</Length_name_of_token>\n",strlen(name));
            fprintf(fout,"	</Token>\n");

        }
        number++;
     printf("U_i");
    }

    return 0;
}
