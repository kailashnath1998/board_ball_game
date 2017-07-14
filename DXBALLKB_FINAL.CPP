#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>
#include<fstream>

int jn=38,m=1,f=1,h=1,cu=0,k=1,er=1,io=1,op=1,td=1,L,mn,ter=1; //completed f,h,m,k,er,op,io
float p,z;
COORD coord={0,0}; // this is global variable center of axis is set to the top left corner of the screen

void decide();
void gotoxy(int ,int );
void border();

class highscore
{
    public:
    int scores;
    char name[20];
    void setval()
    {
        strcpy(name,"*****");
        scores=0;
    }
    void input(int u)
    {
        gotoxy(33,18);
        std::cout<<"Enter your name: ";
        std::cin>>name;
        scores=u;
    }
    void display()
    {
        std::cout<<name<<"      "<<scores;
    }
    void display(int u)
    {
        gotoxy(33,10+u);
        std::cout<<name;
        gotoxy(53,10+u);
        std::cout<<scores;
    }
    void copyf(highscore &s)
    {
        scores=s.scores;
        strcpy(name,s.name);
    }
};

void resetscorelist()
{
    highscore h[5];
    std::ofstream newfile("score.x3db",std::ofstream::binary|std::ofstream::out);
    for(int i=0;i<5;i++)
    {
        h[i].setval();
    }
    newfile.write((char*)&h,sizeof(h));
    gotoxy(33,19);
    std::cout<<"reset done";
    Sleep(1000);
}

int lastscore()
{
         highscore s[5];
         int yui=0;
        std::fstream update("score.x3db",std::fstream::binary|std::ifstream::in);
        do
    {
        update.read((char*)&s[yui],sizeof(s));
        //if()
        s[yui].display();
        ++yui;
        update.seekg(0+24*yui);

    } while(!(update.eof())&&yui<5);
    return s[4].scores;
}

void renamefile(int h=0)
{
    int result;
  char oldname[] ="new.x3db";
  char newname[] ="score.x3db";
  result= rename( oldname , newname );
  if(h==1)
  {if ( result == 0 )
    puts ( "File successfully renamed" );
  else
    perror( "Error renaming file" );}
}

void storeandsortscore(int y,int h)
{
    highscore s[5],su,sn[5];
    int yui=0;
    char word[20];
    highscore sf,s1;
    sf.input(y);
    std::ofstream fnew("score.x3db",std::ofstream::binary|std::ofstream::app);
    fnew.write((char*)&s,sizeof(s));
    fnew.close();
    Sleep(1000);
    std::fstream update("score.x3db",std::fstream::binary|std::ifstream::in);
    std::ofstream newfile("new.x3db",std::ofstream::binary|std::ofstream::out);
    do
    {
        update.read((char*)&s[yui],sizeof(s));
        if(h==1)
        s[yui].display();
        ++yui;
        update.seekg(0+24*yui);

    } while(!(update.eof())&&yui<5);
    s[4].copyf(sf);
    for(int o=0;o<5;o++)
    {
        for(int i=0;i<5;i++)
        {
            if(s[i].scores>s[i+1].scores)
            {
                su.copyf(s[i]);
                s[i].copyf(s[i+1]);
                s[i+1].copyf(su);
            }
        }}
    for(int ty=0;ty<5;ty++)
    {
        sn[ty]=s[4-ty];
    }

    if(h==1)
    {
        for(int g=0;g<5;g++)
        {
        sn[g].display();
        }
    }
    newfile.write((char*)&sn,sizeof(s));
    newfile.close();
    if(h==1)
    {for(int y=0;y<5;y++)
        {
            s[y].display();
        }
    }
    update.close();
    std::remove("score.x3db");
    renamefile();
    if(h==1)
    Sleep(1000);
}

void dispscorelist()
{
    int n=0;
    system("cls");
    highscore s;
    border();
    std::ifstream f("score.x3db",std::fstream::binary|std::ifstream::in);
    gotoxy(23,8);
    std::cout<<"S.No: ";
    gotoxy(33,8);
    std::cout<<"Name ";
    gotoxy(53,8);
    std::cout<<"Score ";
    f.seekg(0);
    do
    {
        f.read((char*)&s,sizeof(s));
        gotoxy(23,10+n);
        std::cout<<n+1;
        s.display(n);
        n++;
    }while((f)&&n<5);
    getch();
}

void gotoxy(int x,int y) //function to take cursor to a particular point
 {
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

void *score(void *argument) //function which is runs simultaneously with main function and updates score
{
    int n=1;
    p=0;
    while(1&&ter!=24)
    {
        p+=0.015*n;
        n++;
        Sleep(90);
    }
}

void *moveb(void *argument) //function to move the board
{
        jn=38;
        int x;
        char s;
        int u,p;
        p==0;
        HANDLE hout= GetStdHandle(STD_OUTPUT_HANDLE);
        HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
        COORD coord;
    while(1&&ter!=24)
    {
        s=getch();
        {
            if((s=='a'||s=='A')&&jn>4)
            {

                jn=jn-3;
                coord.X = jn;
                coord.Y = 24;
                SetConsoleCursorPosition(hout,coord);
                std::cout<<"<===>" ;
                for(int u =0; u<3;u++)
                {x=jn+5+u;
                coord.X=x;
                coord.Y=24;
                SetConsoleCursorPosition(hout,coord);
                std::cout<<'#';}
            }

            if((s=='d'||s=='D')&&jn<73)
            {
                jn=jn+3;
                coord.X = jn;
                coord.Y = 24;
                SetConsoleCursorPosition(hout,coord);
                std::cout<<"<===>" ;
                for(u = 1;u<4;u++)
                {x=jn-u;
                coord.X=x;
                coord.Y=24;
                SetConsoleCursorPosition(hout,coord);
                std::cout<<'#';}
            }
            }



        }
        FlushConsoleInputBuffer(hin);
    }

void dispblock() //function to display block
{
    gotoxy(20,5);
    std::cout<<"||";
    gotoxy(13,7);
    std::cout<<"||";
    gotoxy(58,8);
    std::cout<<"||";
    gotoxy(40,9);
    std::cout<<"||";
    gotoxy(20,20);
    std::cout<<"||";
    gotoxy(35,10);
    std::cout<<"||";
    gotoxy(30,5);
    std::cout<<"||";
    gotoxy(65,7);
    std::cout<<"||";
}

int check(int g,int t) //function to check whether the ball hits blocks or not
{
     if(m==1&&t==5&&g>19&&g<23)
   {
       m=2;
       gotoxy(20,5);
       std::cout<<"  ";
       cu++;
       return 0;
   }
   else if(f==1&&t==7&&g>12&&g<15)
   {
       f=2;
       gotoxy(13,7);
       std::cout<<"  ";
       cu++;
       return 0;
   }

  else if(h==1&&t==8&&g>57&&g<60)  //58,7
  {
      h=2;
      gotoxy(58,8);
      std::cout<<"  ";
      cu++;
      return 0;
  }
  else if(k==1&&t==9&&g>39&&g<42)   //40,8
  {
      k=2;
      gotoxy(40,9);
      std::cout<<"  ";
      cu++;
      return 0;
  }
  else if(er==1&&t==20&&g>19&&g<22)
  {
      er=2;
      gotoxy(20,20);
      std::cout<<"  ";
      cu++;
      return 0;
  }
   else if(io==1&&t==10&&g>34&&g<37)
  {
      io=2;
      gotoxy(35,10);
      std::cout<<"  ";
      cu++;
      return 0;
  }
  else if(op==1&&t==5&&g>29&&g<32)
  {
      op=2;
      gotoxy(30,5);
      std::cout<<"  ";
      cu++;
      return 0;
  }
  else if(td==1&&t==7&&g>64&&g<67)
  {
      td=2;
      gotoxy(65,7);
      std::cout<<"  ";
      cu++;
      return 0;
  }
  else
    return 1;}

void welcome() //function to display welcome with a pattern
{
    int i=36;
    char l[]={'w','e','l','c','o','m','e'};
    for(int k=0;k<7;k++)
    {gotoxy(i,12);
    std::cout<<l[k];
    i++;
    Sleep(100);}
    Sleep(600);
    gotoxy(36,12);
    std::cout<<"       ";
}

void loading() //function to display loading
{
    int j=36;
    char l[]={'L','o','a','d','i','n','g'};
    for(int i=0;i<7;i++)
    {
        gotoxy(j,12);
        std::cout<<l[i];
        j++;
        Sleep(100);
    }
    for(int f=0;f<5;f++)
    {
        for(int y=0;y<3;y++)
        {
            gotoxy(j,12);
            std::cout<<'.';
            Sleep(100);
            j++;
        }
    j=43;
    gotoxy(j,12);
    std::cout<<"    ";
    j=43;
    }
    gotoxy(32,12);
    std::cout<<"                ";

}

void border() //function to print border
{
    for(int i=1;i<24;i++) //vertical border
 { gotoxy(1,i);
   std::cout<<'#';
   gotoxy(79,i);
   std::cout<<'#';
  }
   for(int j=1;j<80;j++) //horizontal border
 { gotoxy(j,0);
   std::cout<<'#';
   gotoxy(j,24);
   std::cout<<'#';
  }
}

void board(int m) //function to print board during start
{
    gotoxy(m,24);
 std::cout<<"<===>";
}

void ball(int q,int w) //function to print ball
{
    gotoxy(q,w);
  std::cout<<'*';
}

void gamestart() //function to start game
{
    gotoxy(29,12);
    std::cout<<"Press a/d to start game....";
    z=getch();
    gotoxy(29,12);
    std::cout<<"                            ";

}

void moveballul(int &e,int &r,int &t,int &y) //function to move ball up and left
{
    int i,o,L=1;
    while(e>2&&r>2)
    {Sleep(100);
    i=e;o=r;
    e--;r--;
    gotoxy(i,o);
    std::cout<<' ';
    ball(e,r);
    L=check(e-1,r-1);
    if(L==0)
    break;
  }

 t=0;
 y=0;
}

void moveballur(int &e,int &r,int &t,int &y) //function to move ball up and right (c,v,l,o)
{
    int i,o,L=1;
  while(e<78&&r>2)
  {Sleep(100);
   i=e;o=r;
   e++;r--;
   gotoxy(i,o);
    std::cout<<' ';
   ball(e,r);
   L=check(e+1,r-1);
  if(L==0)
  break;
  }
 t=0;
 y=1;
}

void moveballlr(int &e,int &r,int &t,int &y) //function to move ball down and right
{
    int i,o,L=1;
  while(e<78&&r<23)
  {Sleep(100);
   i=e;o=r;
   e++;r++;
   gotoxy(i,o);
   std::cout<<' ';
   ball(e,r);
   L=check(e+1,r+1);
   if(L==0)
   break;
  }
 t=1;
 y=1;
}

void moveballll(int &e,int &r,int &t,int &y) //function to move ball down and left
{
    int i,o,L=1;
  while(e>2&&r<23)
  {Sleep(100);
   i=e;i=r;
   e--;r++;
   gotoxy(e+1,r-1);
   std::cout<<' ';
    ball(e,r);
    L=check(e-1,r+1);
    gotoxy(m,24);
   if(L==0)
   break;
  }
 t=1;
 y=0;
}

void intro() // function to display intro part
{
    system("cls");
    system("cls");
    int w;
    gotoxy(25,3);
    std::cout<<"Main menu";
    gotoxy(25,6);
    std::cout<<"enter 1 to play game";
    gotoxy(25,7);
    std::cout<<"enter 2 for instructions";
    gotoxy(25,8);
    std::cout<<"enter 3 to view high score list and play game";
    gotoxy(25,9);
    std::cout<<"enter 4 to view high score list and quit";
    gotoxy(25,10);
    std::cout<<"enter 5 to exit";
    gotoxy(25,12);
    std::cout<<"Enter your choice: ";
    decide();
}

void calcscore() // function to print "calculating score"
{
    char u[]={'c','a','l','c','u','l','a','t','i','n','g',' ','s','c','o','r','e'};
    gotoxy(31,13);
    for(int i=0;i<17;i++)
    {
     std::cout<<u[i];
     Sleep(100);
    }
    gotoxy(47,13);
    for(int j=0;j<5;j++)
    {
        for(int k=0;k<3;k++)
        {
            gotoxy(48+k,13);
            std::cout<<'.';
            Sleep(50);
        }
        gotoxy(48,13);
        std::cout<<"   ";
    }
    system("cls");
}

void gameplay() // function to control game play
{
system("cls");
int x,y,c,v,Q,l,o,b,t,n,L,bonous,fs,ck,ga,qw;
char ad,us[20],ps[20],reset,adminplay;
start:
system("cls");
gotoxy(30,12);
std::cout<<"Press any key to continue";
ad=getch();;
if(ad=='-')
{
    system("cls");
    gotoxy(36,11);
    std::cout<<"Username: ";
    gotoxy(36,12);
    std::cout<<"Password: ";
    gotoxy(45,11);
    std::cin>>us;
    for(int i=0;i<5;i++)
    {
    gotoxy(45+i,12);
    ps[i]=getch();
    std::cout<<'*';
    qw=i;
    if(ps[i]==13)
        break;
    }
    ps[qw+1]='\0';
    if((!(strcmp(us,"admin")))&&(!(strcmp(ps,"admin"))))
    {
        ga==1;
        gotoxy(36,13);
        std::cout<<"Access granted";
        Sleep(1000);
        system("cls");
        dispscorelist();
        gotoxy(33,18);
        std::cout<<"Enter 1 to reset score list";
        reset=getch();
        if(reset=='1')
        {
            resetscorelist();
            dispscorelist();
        }
        gotoxy(33,18);
        std::cout<<"Enter y to play game and q to quit";
        adminplay=getch();
        if(adminplay=='q')
        {
            Sleep(100);
            return;
        }
        if(adminplay=='y')
        {
            system("cls");
            goto game;
        }
        if(adminplay!='y'&&adminplay!='q')
        {
            gotoxy(33,19);
            std::cout<<"wrong input you are going to quit";
            Sleep(1000);
            return;
        }
        system("cls");

    }
    else
    {
        gotoxy(36,13);
        std::cout<<"Wrong username and password";
        Sleep(2000);
        ad=m;
        goto start;
    }
}
else
    ga=0;
game:
border();
pthread_t thread1,thread2;
dispblock();
time_t t1,t2;
char s;
b=38;
c=40;v=23;
L=0;bonous=0;
Q=0;l=0,o=0;

ball(c,v);
board(38);
do         //game play
 {
 if(m==3&&f==3&&h==3&&k==3&&er==3&&io==3&&op==3&&td==3)
  {
      v=24;
      t2=time(NULL);
      bonous=bonous+2000000;
      if(difftime(t2,t1)==33)
      bonous=bonous+2000000;


  }
  {
  if(p==0)
  {
    gamestart();
    if(z=='a'||z=='A')
    {
        pthread_create(&thread1,NULL,moveb,(void*)v);
        pthread_create(&thread2,NULL,score,(void*)b);
        Q=1;
        t1=time(NULL);
        moveballul(c,v,l,o);
     }
    if(z=='d'||z=='D')
    {
        pthread_create(&thread1,NULL,moveb,(void*)v);
        pthread_create(&thread2,NULL,score,(void*)b);
        t1=time(NULL);
        Q=1;
        moveballur(c,v,l,o);
    }

  }
   else if(v==23&&jn==2&&c==2)
   {
       moveballur(c,v,l,o);
   }

   else if(v==23&&c==78&&jn+4==78)
   {
       moveballul(c,v,l,o);
   }

   else if(v==2&&c>2&&c<78)
   {if(o==1)
    {moveballlr(c,v,l,o);
    }
    if(o==0)
    {moveballll(c,v,l,o);
    }
   }
   else if((v==6&&c<24&&c>18&&m==2)||(v==5&&c<24&&c>18&&m==2)||(v==4&&c<24&&c>18&&m==2))
   {
    if(l==0&&o==0)
    {
        m=3;
        moveballll(c,v,l,o);
    }
    else if(l==1&&o==0)
    {
        m=3;
        moveballul(c,v,l,o);
    }
    else if(l==0&&o==1)
    {
        m=3;
        moveballlr(c,v,l,o);
    }
    else if(l==1&&o==1)
    {
        m=3;
        moveballur(c,v,l,o);
    }
   }
    else if((v==5&&c<33&&c>28&&op==2)||(v==4&&c<33&&c>28&&op==2)||(v==6&&c<33&&c>28&&op==2))
   {
    if(l==0&&o==0)
    {
        op=3;
        moveballll(c,v,l,o);
    }
    else if(l==1&&o==0)
    {
        op=3;
        moveballul(c,v,l,o);
    }
    else if(l==0&&o==1)
    {
        op=3;
        moveballlr(c,v,l,o);
    }
    else if(l==1&&o==1)
    {
        op=3;
        moveballur(c,v,l,o);
    }
   }

       else if((v==7&&c<68&&c>63&&td==2)||(v==8&&c<68&&c>63&&td==2)||(v==6&&c<68&&c>63&&td==2))
   {
    if(l==0&&o==0)
    {
        td=3;
        moveballll(c,v,l,o);
    }
    else if(l==1&&o==0)
    {
        td=3;
        moveballul(c,v,l,o);
    }
    else if(l==0&&o==1)
    {
        td=3;
        moveballlr(c,v,l,o);
    }
    else if(l==1&&o==1)
    {
        td=3;
        moveballur(c,v,l,o);
    }
   }
   else if((v==20&&c<24&&c>18&&er==2)||(v==19&&c<24&&c>18&&er==2)||(v==21&&c<24&&c>18&&er==2))
   {
    if(l==0&&o==0)
    {
        er=3;
        moveballll(c,v,l,o);
    }
    else if(l==1&&o==0)
    {
        er=3;
        moveballul(c,v,l,o);
    }
    else if(l==0&&o==1)
    {
        er=3;
        moveballlr(c,v,l,o);
    }
    else if(l==1&&o==1)
    {
        er=3;
        moveballur(c,v,l,o);
    }
   }

   else if((v==10&&c<38&&c>33&&io==2)||(v==9&&c<38&&c>33&&io==2)||(v==11&&c<38&&c>33&&io==2))
   {
    if(l==0&&o==0)
    {
        io=3;
        moveballll(c,v,l,o);
    }
    else if(l==1&&o==0)
    {
        io=3;
        moveballul(c,v,l,o);
    }
    else if(l==0&&o==1)
    {
        io=3;
        moveballlr(c,v,l,o);
    }
    else if(l==1&&o==1)
    {
        io=3;
        moveballur(c,v,l,o);
    }
   }


   else if((v==9&&c<43&&c>38&&k==2)||(v==8&&c<43&&c>38&&k==2)||(v==10&&c<43&&c>38&&k==2)) //40,8
   {
    if(l==0&&o==0)
    {
        k=3;
        moveballll(c,v,l,o);
    }
    else if(l==1&&o==0)
    {
        k=3;
        moveballul(c,v,l,o);
    }
    else if(l==0&&o==1)
    {
        k=3;
        moveballlr(c,v,l,o);
    }
    else if(l==1&&o==1)
    {
        k=3;
        moveballur(c,v,l,o);
    }
   }

   else if((v==8&&c<16&&c>11&&f==2)||(v==7&&c<16&&c>11&&f==2)||(v==6&&c<16&&c>11&&f==2))
   {
    if(l==0&&o==0)
    {
        f=3;
        moveballll(c,v,l,o);
    }
    else if(l==1&&o==0)
    {
        f=3;
        moveballul(c,v,l,o);
    }
    else if(l==0&&o==1)
    {
        f=3;
        moveballlr(c,v,l,o);
    }
    else if(l==1&&o==1)
    {
        f=3;
        moveballur(c,v,l,o);
    }
   }

   else if((v==8&&c<61&&c>56&&h==2)||(v==7&&c<61&&c>56&&h==2)||(v==9&&c<61&&c>56&&h==2))
   {
    if(l==0&&o==0)
    {
        h=3;
        moveballll(c,v,l,o);
    }
    else if(l==1&&o==0)
    {
        h=3;
        moveballul(c,v,l,o);
    }
    else if(l==0&&o==1)
    {
        h=3;
        moveballlr(c,v,l,o);
    }
    else if(l==1&&o==1)
    {
        h=3;
        moveballur(c,v,l,o);
    }
   }

   else if(c==2&v==2)
   moveballlr(c,v,l,o);

   else if(c==78&&v==2)
   moveballll(c,v,l,o);

   else if(c==2||c==78&&v>2&&v<24)
   { if(o==0&&c==2)
     {if(l==0)
      moveballur(c,v,l,o);
      if(l==1)
      moveballlr(c,v,l,o);}
     if(o==0&&c==78)
     {if(l==1)
         moveballll(c,v,l,o);
       if(l==0)
        moveballul(c,v,l,o);}
    if(o==1&&c==2)
     {if(l==0)
       moveballur(c,v,l,o);
      if(l==1)
        moveballlr(c,v,l,o);
     }
     if(o==1&&c==78)
     {if(l==0)
      moveballul(c,v,l,o);
      if(l==1)
        moveballll(c,v,l,o);
     }
   }

   else if(c==78&&jn==74&&v==23)
   {
       moveballul(c,v,l,o);
   }

   else if(c>jn&&c<jn+4&&v==23&&Q==1)
  {if(o==0)
   moveballul(c,v,l,o);
   else if(o==1)
   moveballur(c,v,l,o);
   }

   else if(c==jn&&v==23&&o==1)
   {
       moveballul(c,v,l,o);
   }

   else if(c==jn&&v==23&&o==0)
   {
       moveballul(c,v,l,o);
   }

   else if(c==jn+4&&v==23&&o==0)
   {
       moveballur(c,v,l,o);
   }

   else if(c==jn+4&&v==23&&o==1)
   {
       moveballur(c,v,l,o);
   }

   else if(!(c>=jn&&c<=jn+4)&&v==23&&Q==1)
   {
       v=v+1;
       ter=v;
       //thread1.join();
       //threads2.join();
       t2=time(NULL);
    }
  }
}
while(v!=24);
gotoxy(36,11);
std::cout<<"Game Over";
Sleep(1000);
calcscore();
L=(int)::p;
bonous=bonous+cu*50;
gotoxy(34,11);
std::cout<<"Actual Score: "<<L;
gotoxy(34,12);
std::cout<<"Bonus: "<<bonous;
fs=L+bonous;
gotoxy(34,13);
std::cout<<"Total Score: "<<L+bonous;
gotoxy(34,14);
std::cout<<"Game play time: "<<difftime(t2,t1)<<" seconds";
Sleep(5000);
system("cls");
ck=lastscore();
if(ck<fs)
{
    dispscorelist();
    storeandsortscore(fs,ga);
    dispscorelist();
}
else if(ck>fs)
{
    std::cout<<"Sorry you were not able to make into top 5";
    gotoxy(1,2);
    dispscorelist();
}
}

void instructions() // function to display instructions
{
    system("cls");
    char q='a';
    gotoxy(10,1);
    std::cout<<"Instructions: ";
    gotoxy(10,5);
    std::cout<<"1.Press a/d to move the board";
    gotoxy(10,6);
    std::cout<<"2. 'a' to move board left and 'd' to move board right";
    gotoxy(10,7);
    std::cout<<"3. Make sure that ball does not hit base";;
    gotoxy(10,8);
    std::cout<<"4. If you hit a block you get +50 points as bonus and +2000000 if";
    gotoxy(10,9);
    std::cout<<" you hit all the blocks";
    gotoxy(10,10);
    std::cout<<"5. Scoring is also dependent on time for which you play.";
    gotoxy(35,22);
    std::cout<<"Enter 1 to play game and 2 for main menu";
    gotoxy(35,23);
    std::cout<<"Enter your choice: ";
    while(q!='1'||1!='2')
    {q=getch();
    if(q=='1')
    {
        gameplay();
        system("cls");
        gotoxy(37,12);
        std::cout<<"Thank You";
    }
    if(q=='2')
     {
         intro();
     }
        }
}

void decide() // function to decide to which part of game based on user input
{
 char n=0;
 n=getch();
 gotoxy(44,10);
 std::cout<<n;
 while(n!='1'&&n!='2'&&n!='3'&&n!='4'&&n!='5')
 {
    gotoxy(25,11);
    std::cout<<"wrong input Try again.... ";
    gotoxy(25,12);
    std::cout<<"Enter your choice:  ";
    gotoxy(44,12);
    n=getch();
    gotoxy(44,12);
    std::cout<<n;
    Sleep(100);
 }
 switch(n)
 {
    case '1':
    gameplay();
    system("cls");
    gotoxy(37,12);
    std::cout<<"Thank You";
    break;
    case '2':
    instructions();
    system("cls");
    gotoxy(37,12);
    std::cout<<"Thank You";
    break;
    case '3':
    dispscorelist();
    gameplay();
    system("cls");
    gotoxy(37,12);
    std::cout<<"Thank You";
    break;
    case '4':
    dispscorelist();
    system("cls");
    gotoxy(37,12);
    std::cout<<"Thank You";
    break;
    case '5':
    system("cls");
    gotoxy(37,12);
    std::cout<<"Thank You";
    break;
}
}

int main() // main function
{
    welcome();
    loading();
    intro();
    return 0;
}

//-std=c++0x -pthread
//pkg-config --libs gtk+-2.0

