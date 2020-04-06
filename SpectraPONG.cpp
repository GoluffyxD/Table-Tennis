#include<graphics.h>
#include<iostream>
#include<stdio.h>
#include<time.h>
#include<process.h>
#include<string.h>
#include<ctype.h>
/*color list
1.black
2.bottle green
3.cyan
4.red
5.laker purple
6. ocher
7. light grey
8.dark grey
9.sky blue
10.lightgreen
11.pale blue
12.light red
13.pink
14.bright yellow
15.white
16. white
17.brown
18.
*/



using namespace std;

//GLOBALS

int newx,newy,m,oldx,oldy,Y1,Y2,Y3,Y4,score1=0,score2=0,no_safe1=3,no_safe2=3,no_fast1=2,no_fast2=2,dy=25,c=1,d=1,k=1,z=0;
int u=1,e=1,player1move=1,player2move=1;
char xcor[50],ycor[50];
char scor1[15],scor2[15],num_safe1[2],num_safe2[2],num_fast1[2],num_fast2[2];
char ch;
char nam1[40],nam2[40];
int len1,len2;
//--------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------
//FUNCTION DECLARATION
//-----------------------------------------------------------------------------------------------------------------------------

//BALL

int RANDOM1();
int RANDOM2();
void del();//delay between each iteration
void beginin();//random position of the ball
void uplefttox1();//movement of the ball to the left screen
void beginin();//random position of the ball
void uplefttox1();//movement of the ball to the left screen
void uplefttoy1();//movement of the ball
void uprighttox1();//movement of the ball
void uprighttoy2();//movement of the ball
void downlefttoy1();//movement of the ball
void downlefttox2();//movement of the ball
void downrighttox2();//movement of the ball
void downrighttoy2();//movement of the ball
void clearball(int ,int );//clears ball trail
void ball_mov(void*);//MASTER FUNCTION TO MOVE BALL
//-------------------------------------------------------------------------------------------------------------------------
//BATS
void movebat1(int &,int &,char,int);//moves right bat
void movebat2(int &,int &,char,int);//moves left bat
void clearbat1(int,int,char,int);//clears right bat
void clearbat2(int,int,char,int);//clears left bat
void drawbat1(int,int,int);//draws right bat
void drawbat2(int,int,int);//draws left bat
//-------------------------------------------------------------------------------------------------------------------------
void game();//MASTER FUNCTION TO USE TABLE AND BATS
//------------------------------------------------------------------------------------------------------------------------
//GENERAL
void countdown();// initiates countdown
//void net(void*);//draws net
void table();//draws table
void sc1();//keeps track of player1 score
void sc2();//keeps track of player2 score
void win1();//success screen for player 1
void win2();//success screen for player 2
void logo();//PONG logo
void getnames();//accepts player names
void displaysc1();//SCORE INDICATOR
void displaysc2();//SCORE INDICATOR
void display();//indicates remaining powerups
void display();//indicates remaining powerups

//-------------------------------------------------------------------------------------------------------------------------
//POWERUPS
void safe1(void*);//keeps player1 safe
void safe2(void*);//keeps player2 safe
void fastbat1();//gives player 1 a faster bat
void fastbat2();//gives player 2 a faster bat
//-------------------------------------------------------------------------------------------------------------------------
//SCREENS
void startscr();
void mainmenu();
void rules();
void credits();
void loadingscr();
void option();
void debuggin(int,int);

//------------------------------------------------------------------------------------------------------------------------------------------

//FUNCTION DEFINITION
//---------------------------------------------------------------------------------------------------------------------------------------




void getnames()
{
    cout<<"Enter Player 1's Name: "<<endl;
    gets(nam1);
    cout<<"Enter Player 2's Name: "<<endl;
    gets(nam2);
    len1=strlen(nam1);
    len2=strlen(nam2);



    if (strcmpi(nam1,"deeps")==0||strcmpi(nam2,"deeps")==0||strcmpi(nam1,"dpk")==0||strcmpi(nam2,"dpk")==0)

      {
          initwindow(1359,1000,"DPK!");
        setcolor(14);
        settextstyle(TRIPLEX_FONT,0,8);
        outtextxy(430,100,"WOAH!");
        settextstyle(TRIPLEX_FONT,0,6);
        setcolor(LIGHTGREEN);
        if (strcmpi(nam1,"deeps")==0||strcmpi(nam1,"dpk")==0)
            outtextxy(640-len1*20,200,nam2);
        if (strcmpi(nam2,"deeps")==0||strcmpi(nam2,"dpk")==0)
            outtextxy(640-len1*20,200,nam1);
        settextstyle(TRIPLEX_FONT,0,7);
        outtextxy(200,300,"You are up against the");
        settextstyle(TRIPLEX_FONT,0,7);
        setcolor(14);
        outtextxy(640-len1*20-60,400,"CHAMP!");
        setcolor(14);
        settextstyle(TRIPLEX_FONT,0,8);
        getch();
      }


    if (strcmpi(nam1,"kashu")==0||strcmpi(nam2,"kashu")==0)
    {
        initwindow(1359,1000,"Kashu!");
        setcolor(LIGHTCYAN);
        settextstyle(TRIPLEX_FONT,0,8);
        outtextxy(430,100,"WOAH!");
        settextstyle(TRIPLEX_FONT,0,6);
        setcolor(YELLOW);
        if(strcmpi(nam1,"kashu")==0)
                outtextxy(640-len1*20,200,nam2);
        if(strcmpi(nam2,"kashu")==0)
                outtextxy(640-len1*20,200,nam1);
        settextstyle(TRIPLEX_FONT,0,7);
        outtextxy(200,300,"You are up against the");
        settextstyle(TRIPLEX_FONT,0,7);
        setcolor(LIGHTCYAN);
        outtextxy(350,400,"SASS QUEEN!");
        getch();
    }

}





void logo()//places logo top of screen
{
    int x=getmaxx()/2,y=getmaxy()/2;
    settextstyle(EUROPEAN_FONT,0,20);
    setcolor(LIGHTBLUE);
    outtextxy(x-220,y-420,"P      NG");

    setcolor(MAGENTA);
    setlinestyle(DOTTED_LINE,YELLOW,20);
    circle(640,140,10);

    setcolor(BLUE);
    setlinestyle(DOTTED_LINE,GREEN,20);
    circle(640,140,20);

    setcolor(LIGHTBLUE);
    setlinestyle(DOTTED_LINE,BLUE,20);
    circle(640,140,30);

    setcolor(GREEN);
    setlinestyle(DOTTED_LINE,RED,20);
    circle(640,140,40);

    setcolor(YELLOW);
    setlinestyle(DOTTED_LINE,YELLOW,20);
    circle(640,140,50);

    setcolor(LIGHTRED);
    setlinestyle(DOTTED_LINE,YELLOW,20);
    circle(640,140,60);

    setcolor(RED);
    setlinestyle(DOTTED_LINE,YELLOW,20);
    circle(640,140,70);
}




void startscr()
{
    initwindow(1359,1000,"PONG");
    int x=getmaxx()/2,y=getmaxy()/2;
    settextstyle(EUROPEAN_FONT,0,20);
    setcolor(LIGHTBLUE);
    outtextxy(x-220,y-220,"P      NG");
    setlinestyle(SOLID_LINE,0,4);
    rectangle(430,220,970,460);

    setcolor(MAGENTA);
    setlinestyle(DOTTED_LINE,YELLOW,20);
    circle(640,340,10);

    setcolor(BLUE);
    setlinestyle(DOTTED_LINE,GREEN,20);
    circle(640,340,20);

    setcolor(LIGHTBLUE);
    setlinestyle(DOTTED_LINE,BLUE,20);
    circle(640,340,30);

    setcolor(GREEN);
    setlinestyle(DOTTED_LINE,RED,20);
    circle(640,340,40);

    setcolor(YELLOW);
    setlinestyle(DOTTED_LINE,YELLOW,20);
    circle(640,340,50);

    setcolor(LIGHTRED);
    setlinestyle(DOTTED_LINE,YELLOW,20);
    circle(640,340,60);

    setcolor(RED);
    setlinestyle(DOTTED_LINE,YELLOW,20);
    circle(640,340,70);



    settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
    setcolor(WHITE);
    outtextxy(430,570,"CLICK ON THE SCREEN AND");
    outtextxy(x-275,y+100,"PRESS ANY KEY TO CONTINUE");
    if(kbhit())
        exit(1);

    getch();
    mainmenu();

}




void mainmenu()

{

    initwindow(1359,1000,"Main Menu");
    int press;
    logo();
    settextstyle(EUROPEAN_FONT,0,4);
    setcolor(LIGHTRED);
    outtextxy(550,300,"1. NEW GAME");
    setcolor(YELLOW);
    outtextxy(600,350,"2. RULES");
    setcolor(LIGHTGREEN);
    outtextxy(580,400,"3. CREDITS");
    setcolor(LIGHTCYAN);
    outtextxy(610,450,"4. EXIT");

    press=getch();

    if (press=='1')
        loadingscr();
    if (press=='2')
        rules();
    if (press=='3')
        credits();
    else if(press=='4')
         exit(1);

}






void credits()
{
    initwindow(1359,1000,"Credits");
    for(int i=600;i>=50;i--)
    {
    settextstyle(EUROPEAN_FONT,0,20);
    setcolor(LIGHTGREEN);
    outtextxy(400,i,"CREDITS");
    settextstyle(EUROPEAN_FONT,0,4);
    setcolor(LIGHTRED);
    outtextxy(100,i+150,"This game is developed by:");
    outtextxy(100,i+190,"1. Deepika P Karanji");
    outtextxy(100,i+220,"2. Kashmira Bhakri");
    outtextxy(100,i+250,"3. Kiran MHM");
    outtextxy(100,i+280,"4. Sanjay Chari");
    outtextxy(100,i+320,"We would also like to thank all our computer teachers for all");
    outtextxy(100,i+350,"their help and support.");
    outtextxy(100,i+390,"Thank you for playing our game!");
    setcolor(BLACK);
    }
    delay(1);
    setcolor(WHITE);
    int x=getmaxx()/2;
    int y=getmaxy()/2;
    settextstyle(EUROPEAN_FONT,0,3);
    setcolor(LIGHTGREEN);
    rectangle(315,565,1037,595);
    outtextxy(320,570,"PRESS ANY KEY TO RETURN TO MAIN MENU");

    getch();
     mainmenu();

}





void loadingscr()
{
initwindow(1359,1000,"Loading...");
int x=getmaxx()/2,y=getmaxy()/2,ea,i;
for(ea=91;ea<=451;ea++)
{
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
    setcolor(WHITE);
    outtextxy(x-100,y-150,"LOADING...");
    setcolor(RED);
    for(i=150;i<=200;i++)
        arc(x,y-150,91,ea,i);
    if(ea!=451)
        cleardevice();
    if(ea==451)
    {
        settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
        setcolor(WHITE);
        outtextxy(x-275,y+100,"PRESS ANY KEY TO CONTINUE");
    }
}

delay(0.01);
getch();
cleardevice();
countdown();
}






void rules()
{
    int x=675;
    initwindow(1359,1000,"Rules");
    settextstyle(EUROPEAN_FONT,0,8);
    setcolor(LIGHTGREEN);
    outtextxy(490,20,"RULES");
    setcolor(LIGHTGREEN);
    settextstyle(EUROPEAN_FONT,0,3);
    outtextxy(30,125,"CONTROLS FOR PLAYER 1:");
    outtextxy(30+x,125,"CONTROLS FOR PLAYER 2:");
    setcolor(LIGHTCYAN);
    outtextxy(30,150,nam1);
    outtextxy(30+x,150,nam2);
    setcolor(LIGHTGREEN);
    setlinestyle(SOLID_FILL,0,5);
    settextstyle(EUROPEAN_FONT,0,5);
    rectangle(200,220,300,320);
    outtextxy(220,240,"W");
    rectangle(90,220,190,320);
    outtextxy(110,240,"Q");
    rectangle(310,220,410,320);
    outtextxy(330,240,"E");
    rectangle(230,330,330,430);
    outtextxy(250,350,"S");
    rectangle(200+x,220,300+x,320);
    outtextxy(220+685,240,"I");
    rectangle(90+x,220,190+x,320);
    outtextxy(110+x,240,"U");
    rectangle(310+x,220,410+x,320);
    outtextxy(330+x,240,"O");
    rectangle(230+x,330,330+x,430);
    outtextxy(250+x,350,"K");
    settextstyle(EUROPEAN_FONT,0,3);
    outtextxy(500,290,"UP");
    outtextxy(500+x,290,"UP");
    outtextxy(500,400,"DOWN");
    outtextxy(500+x,400,"DOWN");
    outtextxy(100,500,"'E' - Activates SAFE MODE");
    outtextxy(100+x,500,"'U' - Activates SAFE MODE");
    outtextxy(100,525,"'Q' - Activates FAST BAT");
    outtextxy(100+x,525,"'O' - Activates FAST BAT");
    setcolor(LIGHTCYAN);
    line(0,183,1359,183);
    line(0,115,1359,115);
    line(0,600,1359,600);

    line(250,300,475,300);
    line(455,280,475,300);
    line(455,320,475,300);
    line(280,410,475,410);
    line(250+x,300,475+x,300);
    line(455+x,280,475+x,300);
    line(455+x,320,475+x,300);
    line(280+x,410,475+x,410);
    line(455,390,475,410);
    line(455,430,475,410);
    line(455+x,390,475+x,410);
    line(455+x,430,475+x,410);
    line(x,120,x,600);
    settextstyle(EUROPEAN_FONT,0,1);
    setlinestyle(SOLID_LINE,0,2);
    setcolor(LIGHTGREEN);
    rectangle(395,625,940,655);
    outtextxy(400,630,"PRESS ANY KEY TO RETURN TO MAIN MENU");
    getch();
    mainmenu();
}


void option()
{

    char press;

    initwindow(1359,1000,"Do you want to continue?");
    do
    {
    settextstyle(EUROPEAN_FONT,0,6);
    setcolor(YELLOW);
    outtextxy(100,100,"DO YOU WANT TO PLAY AGAIN?");
    settextstyle(EUROPEAN_FONT,0,5);
    outtextxy(500,170,"ENTER (Y/N)");
    press=getch();
    if(press=='Y'||press=='y')
        loadingscr();
    if(press=='N'||press=='n')
        credits();

    }while(press!='N'||press!='n');
}



 void win1()//player 2 loses
{

    initwindow(1359,1000,"Player 1 wins!");
    int A[5]={3,4,5,9,14};
    for(int i=0;i<=4;i++)
    {
        for(int j=0;j<=4;j++)
        {
            setcolor(14);
            settextstyle(TRIPLEX_FONT,0,8);
            outtextxy(290,200,"CONGRATS!");
            settextstyle(TRIPLEX_FONT,0,7);
            setcolor(3);
            outtextxy(640-len1*20,300,nam1);
            setcolor(14);
            settextstyle(TRIPLEX_FONT,0,8);
            outtextxy(480,400,"WINS!");
            setlinestyle(SOLID_FILL,0,30);
            setcolor(A[j]);
            rectangle(250-j*30,160-j*30,1085+j*30,510+j*30);
            delay(200);
            if(i!=4&&j!=4)
            cleardevice();
        }
    delay(100);
    }

     //Reseting scores and powerups
     score1=0;
     score2=0;
     scor1[0]=' ';
     scor2[0]=' ';
     no_safe1=3;
     no_safe2=3;

     getch();
     option();


 }


void win2()//player 1 loses
{

    initwindow(1359,1000,"Player 2 wins!");
    int A[5]={3,4,5,9,14};
    for(int i=0;i<=4;i++)
    {
        for(int j=0;j<=4;j++)
        {
            setcolor(14);
            settextstyle(TRIPLEX_FONT,0,8);
            outtextxy(290,200,"CONGRATS!");
            settextstyle(TRIPLEX_FONT,0,7);
            setcolor(3);
            outtextxy(640-len2*20,300,nam2);
            setcolor(14);
            settextstyle(TRIPLEX_FONT,0,8);
            outtextxy(480,400,"WINS!");
            setlinestyle(SOLID_FILL,0,30);
            setcolor(A[j]);
            rectangle(250-j*30,160-j*30,1085+j*30,510+j*30);
            delay(200);
            if(i!=4&&j!=4)
            cleardevice();
        }
    delay(100);
    }

    //Reseting scores and powerups

     score1=0;
     score2=0;
     scor1[0]=' ';
     scor1[0]=' ';
     no_safe1=3;
     no_safe2=3;

     getch();
     option();


 }


void countdown()//Initial countdown
{
    initwindow(1359,1000,"DeeKiSaKa");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
    outtextxy(450,300,"YOUR GAME BEGINS IN");
    delay(1000);
    cleardevice();
    settextstyle(DEFAULT_FONT,HORIZ_DIR,9);
    outtextxy(655,300,"3");
    delay(1000);
    cleardevice();
    outtextxy(655,300,"2");
    delay(1000);
    cleardevice();
    outtextxy(655,300,"1");
    delay(1000);
    cleardevice();
    game();
}



void powercountdown(int j=5)//indicates seconds left for powerup
{
    int i;
    char ia[2];
    for(i=j;i>=0;i--)
    {
        itoa(i,ia,10);
        settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
        setcolor(LIGHTGREEN);
        outtextxy(630,665,ia);
        delay(1000);
    }
    if(j==200)
    {
        for(i=j;i>=0;i--)
        {
            itoa(i,ia,10);
            settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
            setcolor(LIGHTGREEN);
            outtextxy(630,665,ia);
        }
    }
    settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
    setcolor(BLACK);
    outtextxy(630,660,ia);
}




void sc1()//player 2 misses
{


   score1+=1;
   itoa(score1,scor1,10);

   displaysc1();
   //allows usage of only 1 powerup per window.
   e=1;
   u=1;

   //ball beginning varies with score
   k=1;
   z=0;


    if(score1==5)
        win1();


}


void sc2()//player 1 misses
{

    score2+=1;
    itoa(score2,scor2,10);

    displaysc2();

    //allows usage of only 1 powerup per window.
    e=1;
    u=1;

    //ball beginning varies with score
    k=-1;
    z=0;



    if(score2==5)
        win2();



}


void display1()
{
    //SAFE POWERUP INDICATOR
    setbkcolor(BLACK);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    outtextxy(30,665,"SAFE POWERUPS LEFT:");
    itoa(no_safe1,num_safe1,10);
    outtextxy(296,665,num_safe1);


     //FASTBAT POWERUP INDICATOR
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    outtextxy(30,690,"FASTBAT POWERUPS LEFT:");
    itoa(no_fast1,num_fast1,10);
    outtextxy(330,690,num_fast1);


}



void display2()
{
    //POWERUP INDICATOR
    setbkcolor(BLACK);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    outtextxy(880,665,"SAFE POWERUPS LEFT:");
    itoa(no_safe2,num_safe2,10);
    outtextxy(1150,665,num_safe2);


    //FASTBAT POWERUP INDICATOR
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    outtextxy(880,690,"FASTBAT POWERUPS LEFT:");
    itoa(no_fast2,num_fast2,10);
    outtextxy(1190,690,num_fast2);
}


void displaysc1()//SCORE INDICATOR
{


    setcolor(YELLOW);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
    outtextxy(570,665,scor1);
}


void displaysc2()     //SCORE INDICATOR
{

    setcolor(YELLOW);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
    outtextxy(730,665,scor2);

}



void table()
{
    initwindow(1359,1000,"DeeKiSaKa");
   setfillstyle(SOLID_FILL,5);
   rectangle(30,30,1320,660);
   floodfill(200,200,WHITE);
   //_beginthread(net,0,NULL);
   display1();
   display2();
  displaysc1();
  displaysc2();



}



/*//NET
void net(void*a)
  {

setfillstyle(SOLID_FILL,14);
   bar(669,30,677,650);
}
*/






void drawbat1(int y1, int y2,int colour=14)
{
    setfillstyle(SOLID_FILL,colour);
    bar(1,y1,28,y2);
}



void drawbat2(int y3, int y4,int colour=14)
{
    setfillstyle(SOLID_FILL,colour);
    bar(1322,y3,1349,y4);
}

void safe1(void* a)                                   //SAFE POWERUP FOR PLAYER1
{
    player1move=0;
    display1();
    int inity1,inity2;
    inity1=Y1;inity2=Y2;
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    setcolor(WHITE);
    outtextxy(450,10,"PLAYER 1 IS SAFE FOR 5 SECONDS");
    setcolor(WHITE);setcolor(WHITE);
    Y1=30;Y2=660;
    drawbat1(Y1,Y2);
    powercountdown(5);

    //reset to normal configuration

    setbkcolor(BLACK);
    drawbat1(30,665,BLACK);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    setcolor(BLACK);
    outtextxy(450,10,"PLAYER 1 IS SAFE FOR 5 SECONDS");
    Y1=inity1;Y2=inity2;
    drawbat1(inity1,inity2);
    player1move=1;
}





void safe2(void*a)                                               //SAFE POWERUP FOR PLAYER 2
{
    player2move=0;
    display2();
    int inity3,inity4;
    inity3=Y3;inity4=Y4;
    setcolor(WHITE);
    outtextxy(450,10,"PLAYER 2 IS SAFE FOR 5 SECONDS");
    setcolor(WHITE);setcolor(WHITE);
    Y3=30;Y4=660;
    drawbat2(30,660);
    powercountdown(5);


    //reset to normal configuration


    setbkcolor(BLACK);
    drawbat2(30,660,BLACK);
    setbkcolor(BLACK);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    setcolor(BLACK);
    outtextxy(450,10,"PLAYER 2 IS SAFE FOR 5 SECONDS");
    Y3=inity3;Y4=inity4;
    drawbat2(inity3,inity4);
    player2move=1;
}



void movebat1(int &y1,int &y2,char ch1,int dy=21)
{

    if(ch1=='w'&&y1>39)
    {
       clearbat1(y1,y2,ch1,dy);
       y1-=dy;y2-=dy;
       drawbat1(y1,y2);
    }
    if(ch1=='s'&&y2<650)
    {
        clearbat1(y1,y2,ch1,dy);
        y1+=dy;y2+=dy;
        drawbat1(y1,y2);
    }
    Y1=y1;Y2=y2;
}





void movebat2(int &y3,int &y4,char ch2,int dy=21)
{
    if(ch2=='k'&&y4<650)
   {
     clearbat2(y3,y4,ch2,dy);
     y3+=dy;y4+=dy;
     drawbat2(y3,y4);
   }
    if(ch2=='i'&&y3>39)
    {
       clearbat2(y3,y4,ch2,dy);
       y3-=dy;y4-=dy;
       drawbat2(y3,y4);
    }
   Y3=y3;Y4=y4;
}





void fastbat1()
{
    int initiy1,initiy2,initiy3,initiy4,i;
    initiy1=Y1;initiy2=Y2,initiy3=Y3,initiy4=Y4;
    char ch3;
    display1();
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);


    //core of function

    for(i=0;i<100;i++)
    {
       setcolor(WHITE);
       outtextxy(450,10,"PLAYER 1 HAS CHOSEN A FAST POWERUP");
       ch3=getch();

       if(ch3=='w'&&initiy1>45)
          movebat1(initiy1,initiy2,ch3,35);
       if(ch3=='s'&&initiy2<645)
          movebat1(initiy1,initiy2,ch3,35);
       movebat2(initiy3,initiy4,ch3,20);
    }


    //reset to normal configuration

    drawbat2(initiy3,initiy4,BLACK);
    drawbat1(initiy1,initiy2,BLACK);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    setcolor(BLACK);
    outtextxy(450,10,"PLAYER 1 HAS CHOSEN A FAST POWERUP");

}



void fastbat2()
{
    int initiy3,initiy4,initiy1,initiy2,i;
    initiy3=Y3;initiy4=Y4,initiy1=Y1,initiy2=Y2;
    char ch3;
    display2();
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);


    //core of function

    for(i=0;i<100;i++)
    {
       setcolor(WHITE);
       outtextxy(450,10,"PLAYER 2 HAS CHOSEN A FAST POWERUP");
       ch3=getch();

       if(ch3=='i'&&initiy3>45)
            movebat2(initiy3,initiy4,ch3,35);
       if(ch3=='k'&&initiy4<645)
            movebat2(initiy3,initiy4,ch3,35);
       movebat1(initiy1,initiy2,ch3,20);
    }


    //reset to normal configuration
    drawbat1(initiy1,initiy2,BLACK);
    drawbat2(initiy3,initiy4,BLACK);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    setcolor(BLACK);
    outtextxy(450,10,"PLAYER 2 HAS CHOSEN A FAST POWERUP");
}



void clearbat1(int y1,int y2,char ch,int dy=20)
{
 setfillstyle(SOLID_FILL,BLACK);
 if(ch=='w')
    bar(1,y1+dy,28,y2+dy);
 else if(ch=='s')
    bar(1,y1-dy,28,y2-dy);
}

void clearbat2(int y3,int y4,char ch,int dy=20)
{
 setfillstyle(SOLID_FILL,BLACK);
 if (ch=='i')
    bar(1322,y3+dy,1349,y4+dy);
 else if(ch=='k')
    bar(1322,y3-dy,1349,y4-dy);
}









void game()
{

  int y1=200, y2=300,y3=200,y4=300;
  int i,j;
  char k;
  table();

  drawbat1(y1,y2);
  drawbat2(y3,y4);

Y1=y1;Y2=y2;Y3=y3;Y4=y4;
_beginthread(ball_mov,0,NULL);
while(1)
 {
  ch=getch();
  ch=tolower(ch);

  switch(ch)
   {
       case'w': case's':
       {
         if(player1move)
            movebat1(y1,y2,ch);
         break;
       }

       case'i': case'k':
       {
          if(player2move)
            movebat2(y3,y4,ch);
          break;
       }
       case 'e':
        {
           if(no_safe1>0)
           {
               if(e)
               {
                    _beginthread(safe1,0,NULL);
                    if(ch=='w')
                        movebat1(y1,y2,'s');
                    else if(ch=='s')
                        movebat1(y1,y2,'w');
                    e=0;
                    no_safe1--;
               }

           }

           break;
        }
       case 'u':
        {
           if(no_safe2>0)
           {
               if(u)
               {
                   _beginthread(safe2,0,NULL);

                   if(ch=='i')
                        movebat2(y3,y4,'s');
                   else if(ch=='k')
                        movebat2(y3,y4,'w');

                   u=0;
                   no_safe2--;
               }
           }

           break;
        }
         case 'q':
        {

            if(no_fast1!=0)
            {
                no_fast1--;
                fastbat1();
            }


            break;
        }
       case 'o':
        {

            if(no_fast2!=0)
            {
                no_fast2--;
                fastbat2();
            }

            break;
        }
   }
   if (ch==27)
      break;//PRESS ESCAPE TO EXIT GAME


 }
}


//**********************************************************************************************************************


void debugin(int a,int b)  //To track ball movements. For programmer convenience only. not a part of the actual game
{
 itoa(a,xcor,10);
 settextstyle(DEFAULT_FONT,0,2);
 setcolor(WHITE);
 outtextxy(100,30,xcor);
 itoa(b,ycor,10);
 outtextxy(200,30,ycor);
 getch();
}



int RANDOM1()
{
  int y;
  a:
  y=rand()%5;
  y+=2;
  if(y<=0 && y%2==1)
     goto a;
  else
   return y ;
}



int RANDOM2()
{
  int y;
  a:
  y=rand()%2;
  if(y<=0)
     goto a;
  else
   return y ;
}



void del()//programmer defined delay function
{
  int k;
  for(k=0;k<1000000+z;k++);

}



void clearball(int a,int b)
{
 // _beginthread(net,0,NULL);
  setfillstyle(SOLID_FILL,5);
  setcolor(5);
  fillellipse(a,b,10,10);

}






void beginin()
{
 int i;
 oldy=m;

 for(i=0;m-i>40;i++)
 {
     if(m+k*i==41 && m-i==41)
       break;
     setfillstyle(SOLID_FILL,LIGHTBLUE);
     setcolor(LIGHTBLUE);
     fillellipse(m+k*i,m-i,10,10);
     del();
     clearball(m+k*i,m-i);
 }
     newx=m+k*i;
     newy=m-i;
}






void uprighttoy2()
{
 oldx=newx;
 oldy=newy;
 int j;
 for(j=1;newx+j/c<1310;j++)
 {
     if(newy-j/d==40)
       break;
     if(newx+j/c==1309 && newy-j/d==41)
       break;
     setfillstyle(SOLID_FILL,LIGHTBLUE);
     setcolor(LIGHTBLUE);
     fillellipse(newx+j/c,newy-j/d,10,10);
     del();
     clearball(newx+j/c,newy-j/d);

}
     newx=newx+j/c;
     newy=newy-j/d;


}






void uprighttox1()
{
 oldx=newx;
 oldy=newy;
 int j;
 for(j=1;newy-j/d>40;j++)
 {   if(newx+j/c==1310)
       break;
     if(newx+j/c==1309 && newy-j/d==41)
       break;
     setfillstyle(SOLID_FILL,LIGHTBLUE);
     setcolor(LIGHTBLUE);
     fillellipse(newx+j/c,newy-j/d,10,10);
    del();
     clearball(newx+j/c,newy-j/d);
 }
     newx=newx+j/c;
     newy=newy-j/d;

}









void uplefttox1()
{
 oldx=newx;
 oldy=newy;
 int j;
 for(j=1;newy-j/d>40;j++)
 {
     if(newx-j/c==40)
         break;
      if(newx-j/c==41 && newy-j/d==41)
         break;

     setfillstyle(SOLID_FILL,LIGHTBLUE);
     setcolor(LIGHTBLUE);
     fillellipse(newx-j/c,newy-j/d,10,10);
     del();
     clearball(newx-j/c,newy-j/d);
 }
 newy=newy-j/d;
 newx=newx-j/c;
}





void uplefttoy1()
{
 oldx=newx;
 oldy=newy;
 int j;
 for(j=1;newx-j/c>40;j++)
 {
     if(newy-j/d==40)
         break;
     if(newx-j/c==41 && newy-j/d==41)
         break;

     setfillstyle(SOLID_FILL,LIGHTBLUE);
     setcolor(LIGHTBLUE);
     fillellipse(newx-j/c,newy-j/d,10,10);
     del();
     clearball(newx-j/c,newy-j/d);
 }
 newy=newy-j/d;
 newx=newx-j/c;
}





void downlefttoy1()
{
 oldx=newx;
 oldy=newy;
 int j;
 for(j=1;newx-j/c>40;j++)
 {
     if(newy+j/d==650)
      break;
     if(newx-j/c==41 && newy+j/d==649)
       break;
     setfillstyle(SOLID_FILL,LIGHTBLUE);
     setcolor(LIGHTBLUE);
     fillellipse(newx-j/c,newy+j/d,10,10);
     del();
     clearball(newx-j/c,newy+j/d);
 }
 newy=newy+j/d;
 newx=newx-j/c;
}






void downlefttox2()
{
 oldx=newx;
 oldy=newy;
 int j;
 for(j=1;newy+j/d<650;j++)
 {
     if(newx-j/c==40)
       break;
     if(newx-j/c==41 && newy+j/d==649)
       break;
     setfillstyle(SOLID_FILL,LIGHTBLUE);
     setcolor(LIGHTBLUE);
     fillellipse(newx-j/c,newy+j/d,10,10);
     del();
     clearball(newx-j/c,newy+j/d);
 }
 newy=newy+j/d;
 newx=newx-j/c;
}






void downrighttox2()
{
 oldx=newx;
 oldy=newy;
 int j;
 for(j=1;newy+j/d<650;j++)
 {
     if(newx+j/c==1310)
         break;
     if(newx+j/c==1309 && newy+j/d==649)
         break;

     setfillstyle(SOLID_FILL,LIGHTBLUE);
     setcolor(LIGHTBLUE);
     fillellipse(newx+j/c,newy+j/d,10,10);
     del();
     clearball(newx+j/c,newy+j/d);
 }
 newy=newy+j/d;
 newx=newx+j/c;
}







void downrighttoy2()
{
 oldx=newx;
 oldy=newy;
 int j;
 for(j=1;newx+j/c<1310;j++)
 {
     if((newy+j/d)==650)
      break;
     if(newx+j/c==1309 && newy+j/d==649)
      break;
     setfillstyle(SOLID_FILL,LIGHTBLUE);
     setcolor(LIGHTBLUE);
     fillellipse(newx+j/c,newy+j/d,10,10);
     del();
     clearball(newx+j/c,newy+j/d);
 }
 newy=newy+j/d;
 newx=newx+j/c;
}








void ball_mov(void* a) //ball is threaded in game
{
    m=650;
    beginin();
    c=RANDOM2();
    while(1)
    {
        int q=rand()%2;
        q++;
    if(newx==1310 && oldy==650 || oldx==40 && newx==1310 && newy-oldy<0)
    {
       if(newy<=Y4 && newy>=Y3)
       {

         if(newy<=Y3+Y4/2)

          {
               if(q==1)
                  {
                      c=RANDOM2();
                      d=1;
                      z-=50000;
                      uplefttox1();
                      continue;
                  }
                  else if(q==2)
                  {
                      d=RANDOM1();
                      c=1;
                      z-=50000;
                      uplefttox1();
                      continue;
                  }
          }
             else
              {
                  if(q==1)
                  {
                      c=RANDOM2();
                      d=1;
                      z-=50000;
                      downlefttox2();
                      continue;
                  }
                  else if(q==2)
                  {
                      d=RANDOM1();
                      c=1;
                      z-=50000;
                      downlefttox2();
                      continue;
                  }
             }
    }
       else
          {
              sc1();
              delay(2000);
              game();
          }
    }
    if(newy==40 && oldx==1310 || oldy==650 && newy==40 && (newx-oldx<0))
      {
          downlefttoy1();
          continue;
      }
    if(newx==40 && oldy==40 || newx==40 && oldx==1310 && newy-oldy>0)
      {
          if(newy<=Y2 && newy>=Y1)//CHECKING IF BAT1 HITS BALL
            {
                if(newy<=(Y1+Y2)/2)
                  {

                        if(q==1)
                        {
                        c=RANDOM2();
                        d=1;
                        z-=50000;
                        uprighttox1();
                        continue;
                        }
                        else if(q==2)
                         {
                        d=RANDOM1();
                        c=1;
                        z-=50000;
                        uprighttox1();
                        continue;
                        }
                  }
                else
                     {

                        if(q==1)
                        {
                        c=RANDOM2();
                        d=1;
                        z-=50000;
                        downrighttox2();
                        continue;
                        }
                        else if(q==2)
                         {
                        d=RANDOM1();
                        c=1;
                        z-=50000;
                        downrighttox2();
                        continue;
                        }
                     }
            }
          else     //if player misses
            {
              sc2();
              delay(2000);
              game();
          }
      }
    if(newy==650 && oldx==40 || newy==650 && oldy==40 && (newx-oldx>0) )
      {
          uprighttoy2();
          continue;
      }
    if(newy==650 && oldy==40 && (newx-oldx<0) || newy==650 && oldx==1310)
      {
          uplefttoy1();
          continue;
      }
    if(newx==40 && oldy==650 || newx==40 && oldx==1310 && newy-oldy<0)
      {
          if(newy<=Y2 && newy>=Y1) //CHECKING IF BAT1 HITS BALL

               {
                   if(newy<=(Y1+Y2)/2)
                    {
                        if(q==1)
                        {
                        c=RANDOM2();
                        d=1;
                        z-=50000;
                        uprighttox1();
                        continue;
                        }
                        else if(q==2)
                         {
                        d=RANDOM1();
                        c=1;
                        z-=50000;
                        uprighttox1();
                        continue;
                        }
                    }
                    else
                    {
                        if(q==1)
                        {
                        c=RANDOM2();
                        d=1;
                        z-=50000;
                        downrighttox2();
                        continue;
                        }
                        else if(q==2)
                         {
                        d=RANDOM1();
                        c=1;
                        z-=50000;
                        downrighttox2();
                        continue;
                        }
                    }


               }

          else   //if player misses
            {
                sc2();
              delay(2000);
              game();
            }
      }
    if(newy==40 && oldx==40 || oldy==650 && newy==40 && (newx-oldx>0)|| newy==40 && oldy==m)
      {
          downrighttoy2();
          continue;
      }
    if(newx==1310 && oldy==40 || newx==1310 && oldx==40 && newy-oldy>0)
    {
        if(newy<=Y4 && newy>=Y3)//CHECKING IF BAT2 HITS BALL
             {
                  if(newy>=(Y3+Y4)/2)
                  {
                      if(q==1)
                         {
                          c=RANDOM2();
                          d=1;
                          z-=50000;
                          downlefttox2();
                          continue;
                         }
                      else if(q==2)
                         {
                          d=RANDOM1();
                          c=1;
                          z-=50000;
                          downlefttox2();
                          continue;
                         }
                  }
                  else
                  {
                      if(q==1)
                         {
                          c=RANDOM2();
                          d=1;
                          z-=50000;
                          uplefttox1();
                          continue;
                         }
                      else if(q==2)
                         {
                          d=RANDOM1();
                          c=1;
                          z-=50000;
                          uplefttox1();
                          continue;
                         }
                  }

             }
        else     //if player misses
          {
              sc1();
              delay(2000);
              game();
          }
    }
    if(newx==41 && newy==41 )
        {
            if(newy>=Y1 && newy<=Y2)//CHECKING IF BAT1 HITS BALL

            {
                c=1;
                d=RANDOM1();
                z-=50000;
                downrighttox2();
                oldx=40;
                oldy=40;
            }
            else
               {
                   sc2();
              delay(2000);
              game();
               }
        }
     if(newx==1309 && newy==649 && newy>=Y3 && newy<=Y4)
       {
           if(newy>=Y3 && newy<=Y4)
           {
            c=1;
            d=RANDOM1();
            z-=50000;
            uplefttox1();
            oldx=1310;
            oldy=650;
           }
           else    //if player misses
            {
              sc1();
              delay(2000);
              game();
            }
       }
     if(newx==1309 && newy==39)
       {
           if(newy>=Y3 && newy<=Y4)//CHECKING IF BAT2 HITS BALL
            {
                c=1;
                d=RANDOM1();
                z-=50000;
                downlefttox2();
                oldx=1310;
                oldy=40;
            }
           else
             {
                sc1();
              delay(2000);
              game();
             }
       }
     if(newx==41 && newy==649 )
     {
         if(newy>=Y1 && newy<=Y2)
            {
                c=1;
                d=RANDOM1();
                z-=50000;
                uprighttox1();
                oldx=40;
                oldy=650;
            }
         else    //if player misses
            {
                sc1();
              delay(2000);
              game();
            }
     }

}
}

int main()
{
    getnames();
    startscr();
}
//*****************************************************************************************************************************
/*NOTES



                     x1
    _______________________________________
   |                                       |
   |                                       |
   |                                       |
y1 |                                       |   y2
   |                                       |
   |_______________________________________|

                     x2
*/

