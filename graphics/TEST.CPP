/* project : student data base */
#include<stdio.h>
#include<stdlib.h>  //for atoi() / itoa()
#include<dos.h>
#include<ctype.h>
#include<conio.h>
#include<graphics.h>
//#include<BirdSooter.h>
#include<string.h>
#define true 1
#define PASSWORD 1234
float DELAY_TIME  = 200 ;
struct student
{

    char id[10];
    char name[20];
    char mobile_number[13];
    char fathers_name[20];
    char mothers_name[20] ;
    char address[20];

    char semester[50];

}  ;
typedef struct student std ;


union REGS i , o ;
// to check if a string is number of not
int isnum(const char *s)
{
    while (*s)
    {
	if (!isalpha(*s) && !isspace(*s)) return 1;
	*s++;
    }

    return 0;
}

// 	WORD GAME
int missHit = 0 ;
/* LEVELS */
int LevelOne()    ;    // animal`s
int LevelTwo()    ;    // clothe`s
int LevelThree()  ;    // food
int LevelFour()   ;    // random stuff
int LevelFive()   ;    // computer parts
float score = 0 ;
/* MAIN FUNCTION */
int WordGame() ;
void hm();
void  bird(int,int,int);
/*call_bird_game function calls the bird function */
int call_bird_game(int,float,char,int,int) ; /*return`s dead bird takes speed_Rate & count_down_time & level__numer*/
/*bird_game function calls the call_bird_game function */
int bird_game() ;

	// BALOON GAME
	int call_baloon_game(int,float,char,int,int) ; /*return`s dead bird takes speed_Rate & count_down_time & level__numer*/
/*bird_game function calls the call_bird_game function */
int baloon_game() ;

// call mouse
void cm() ;
// mouse position
void mp(int &x , int &y ,int & c  ) ;

void main()
{
    // mouse vars
    int x , y , c ;
    int out = 0 ;
    FILE  *fp ,*fp2, *fp3;
    char file_name[20] ;
    int esc = 0 ;
    int login = 0 ;
    int pass = 0 ;
    int t = 0 ; // temporary variable
    int flag = 0 ;
    // declaring graphics driver
    //and graphics mode
    int gd = DETECT, gm ;
    int need = 0 ;
    // setting the graphics
    initgraph(&gd,&gm,"c:/tc/bgi");
    while(out==0)
    {
	// gui
	// prime buttons
	cleardevice();
	//	setbkcolor(BLACK);
	cm();
	//settextstyle(1,1,1);
	setbkcolor(BLUE);
	setcolor(RED);

	rectangle(200,50,400,100);
	outtextxy(280,70,"ADD");
	rectangle(200,150,400,200);
	outtextxy(280,170,"WordGame");
	rectangle(200,250,400,300);
	outtextxy(280,270,"BaloonGame");
	rectangle(200,350,400,400);
	outtextxy(280,370,"BirdGame");

	// exit button
	setfillstyle(SOLID_FILL,RED);
	bar(600,0,650,30);
	//setcolor(BLACK);
	outtextxy(605,0,"X");


	// background
	while(1)
	{
	    mp(x,y,c);

	    // dew to unusual error


	    // bird game
	    //update
	    if(c==1 && x>=200 && x<=400 && y>=350 && y<=400 )
	    {

			if(bird_game()==1) ;
		     cleardevice();
		     break ;


	    }
	    // baloon game
	    //delete button
	    if(c==1 && x>=200 && x<=400 && y>=250 && y<=300 ) // exeption not logged in
	    {
	       if(baloon_game()==1) ;
		   cleardevice();
	       break ;
		}


	    // word game
	    // search button
	    if(c==1 && x>=200 && x<=400 && y>=150 && y<=200 )
	    {
		  if(WordGame()==1) ;
		   cleardevice();
		   break ;
	    }

	    // add button
	    if(c==1 && x>=200 && x<=400 && y>=50 && y<=100 )
	    {
		 if(bird_game()==1) ;
		   cleardevice();
	       break ;
		}



	    //exit button
	    if(c==1 && x>=600 && x<=650 && y>=0 && y<=30 )
	    {
		out = -1 ;
		break ;
	    }

	}


    }
    //	background

}
int bird_game()
{

    int speed_rate = 5 ;
//	float count_down_time = 0;
    int level = 1 ;
    int target ;
    /*game loader */
    while(true)
    {
         if(level==9){
			 cleardevice();
			 gotoxy(10,15);
			 printf("GameOver 3:)");
			 return 1 ;
		 }
        if(call_bird_game(speed_rate,2000,level,12,6))  // 12 birds in 2 minut`s
        {


            level = level + 1 ;
            clrscr();
            cleardevice();

            gotoxy(30,15);
            printf("LEVEL %d \n ",level);
	        delay(2000);
	        speed_rate = speed_rate + 1 ;
	     if(call_bird_game(speed_rate,4000,level,30,10))
	    {
		clrscr();
		cleardevice();
		level = level + 1 ;
		gotoxy(30,15);
		printf("LEVEL %d \n ",level);
		delay(2000);
		speed_rate = speed_rate + 1 ;
		if(call_bird_game(speed_rate,8000,level,60,20))
		{
		    clrscr();
		    cleardevice();
		    level = level + 1 ;
		    gotoxy(30,15);
		    printf("LEVEL %d \n ",level);
		    delay(2000);
		    speed_rate = speed_rate + 1 ;
		}
		else
		{

		    break ;
		}
	    }
	    else
	    {

		break ;
            }
        }
        else
        {

            break ;

        }


    }
    return 1 ;
}
int call_bird_game(int speed_rate , float count_down_time,char level,int target,int miss_hit)
{
    int gd = DETECT ,gm ;
    int x , y , c ;
    int score = 0 ;
    int hit = 6 ; /*bullet and shoot counter */
    int flag = 0 ;
    /*moving circle var`s*/
    float mcx = 0 , mcy = 0 ;
    float m1cx = 0 , m1cy = 0 ;
    float m2cx = 0 , m2cy = 0 ;
    float m3cx = 0 , m3cy = 0 ;

    float speed_controll = 10 ;
    initgraph(&gd,&gm,"c:/tc/bgi");
    cm();


    /*GAME LOOP*/
    do
    {
        // clrscr();
        cleardevice();
		//hm(); // hiding mouse
        // setbkcolor(BLUE);
        mp(x,y,c);
        putpixel(random(620),random(419),15);
        if(flag==0)
        {
            flag = 1 ;
        }
        else
        {
            flag = 0 ;

        }

        /* BULLATE STATE */
        if(hit==0 )
        {

            outtextxy(230,200," RELODE ");

        }
        if(c==2)
        {
            hit = 6 ;
        }
        //end
        putpixel(random(620),random(419),15);
        /*graphicl representation of bullets*/
        for(int i = 0 , j = 0 ; i < hit ; i++,j+=30)
        {
            bar(j,425,j+10,450);

        }

        /*GAME OVER CONDION */
        if(score<-5)
        {
            cleardevice();
            outtextxy(230,200," __GAME OVER__ ");
            getch();
            return 0;
        }
        //END

        putpixel(random(620),random(419),15);
        /*sore printer */
        count_down_time -=1;
        printf("TIME_LEFT = %.4f\n",count_down_time);                                                                /*COUNT_DOWN_TIMER*/
        printf("LEVEL = %d\n",level);
        printf("LIVE`S LEFT %d\n",miss_hit);
        printf("score = %4d / %2d\n",score ,target);
        if(score>=target) return 1 ; //success

        /*tiemout game_over*/
        if(count_down_time<=0)
        {
            cleardevice();
            outtextxy(200,230,"TIME_OUT_GAME_OVER_\n");
            getch();
            return 0 ;
        }
        /*miss_hit game over */
        if(miss_hit<=0)
        {

            outtextxy(200,230,"TOO_MANY_MISS_HIT\n");
            getch();
            return 0 ;
        }

        /*bird four */

        /*bird speed*/
        m3cx  = m3cx + speed_rate ;
        if(m3cx>450)
        {
            m3cx =  - rand() % 150   ;
            m3cy = rand() %300 + 120 ;
        }
        setcolor(YELLOW);
        bird(m3cx,m3cy,flag);
        //  rectangle(m3cx+20,m3cy+20,m3cx+120,m3cy-20);
        /*bird four end*/

        /*bird three */

        /*SPEED_CONTORL */
        m2cx  = m2cx + speed_rate ;
        if(m2cx>450)
        {
            m2cx =  - rand() % 200   ;
            m2cy = rand() %400 + 70 ;
        }
        setcolor(RED);
        bird(m2cx,m2cy,flag);
        // rectangle(m2cx+20,m2cy+20,m2cx+120,m2cy-20);
        /*bird three end*/


        /*bird two */

        m1cx  = m1cx + speed_rate ;
        if(m1cx>450)
        {
            m1cx =  - rand() % 100   ;

            m1cy = rand() %400 + 30 ;
        }
        setcolor(BLUE);
        bird(m1cx,m1cy,flag);
        // rectangle(m1cx+20,m1cy+20,m1cx+120,m1cy-20);
        /*bird two end*/

        /*bird  one */

        //mouse position
        // mp(x,y,c);

        /*moving circle */



        //as moving in vertical line x cordinate will be constant
        //  mcy  = mcy + 10 ; // we can controll the sepped of circle object by controlling increment
        //  mcx  = mcx + 10 ;
        mcx  = mcx + speed_rate ;
        // speed_controll +=.0001 ;
        // if(mcx>500) mcx = rand() % 400 ;

        if(mcx>450)
        {
            mcx =  0  ;
            mcy = rand() %400 ;
        }
        //mcy = sin(x) *400 ; // sinosidal path way (too unstable )
        //circle(mcx,mcy,20);
        //rectangle(mcx-20,mcy+20,mcx+20,mcy-20);
        setcolor(GREEN);
        bird(mcx,mcy,flag);

        /*bird covering rectangle*/
        // rectangle(mcx+20,mcy+20,mcx+120,mcy-20);
        /*end of moving circle */

        /*IF BIRD THO IS SHOUGHT */

        if(c==1 && x>=m2cx+20 && x<=m2cx+120 && y>=m2cy-20 && y<=m2cy+20  && hit!=0) /*last condition giver to implement relode */
        {

            score = score + 1 ;
            hit = hit - 1 ;
            //circle(m1cx,mcy,60) ;
            delay(20);
            while(m2cy<550)
            {
                sound(m2cy);
                cleardevice();
                circle(m2cx,m2cy,10);
                m2cy+=10;
                delay(10);
            }
            circle(m2cx,m2cy,2);
            delay(50);
            nosound();
            putpixel(random(620),random(419),15);

        }

        /*IF BIRD FOUR IS SHOUGHT */

        if(c==1 && x>=m3cx+20 && x<=m3cx+120 && y>=m3cy-20 && y<=m3cy+20  && hit!=0) /*last condition giver to implement relode */
        {

            score = score + 1 ;
            hit = hit - 1 ;
            //circle(m1cx,mcy,60) ;
            delay(20);
            while(m3cy<550)
            {
                sound(m3cy);
                cleardevice();
                circle(m3cx,m3cy,10);
                m3cy+=10;
                delay(10);
            }
            circle(m3cx,m3cy,2);
            delay(50);
            nosound();
            putpixel(random(620),random(419),15);

        }

        /*IF BIRD THREE IS SHOUGHT */

        if(c==1 && x>=m1cx+20 && x<=m1cx+120 && y>=m1cy-20 && y<=m1cy+20  && hit!=0) /*last condition giver to implement relode */
        {

            score = score + 1 ;
            hit = hit - 1 ;
            //circle(m1cx,mcy,60) ;
            delay(20);
            while(m1cy<550)
            {
                sound(m1cy);
                cleardevice();
                circle(m1cx,m1cy,10);
                m1cy+=10;
                delay(10);
            }
            circle(m1cx,m1cy,2);
            delay(50);
            nosound();
            putpixel(random(620),random(419),15);

        }

        /*IF BIRD ONE IS SHOUGHT */

        if(c==1 && x>=mcx+20 && x<=mcx+120 && y>=mcy-20 && y<=mcy+20  && hit!=0) /*last condition giver to implement relode */
        {

            score = score + 1 ;
            hit = hit - 1 ;
            circle(mcx,mcy,60) ;
            delay(20);
            while(mcy<550)
            {
                sound(mcy);
                cleardevice();
                circle(mcx,mcy,10);
                mcy+=10;
                delay(10);
            }

            circle(mcx,mcy,2);
            delay(50);
            nosound();
            putpixel(random(620),random(419),15);

        }
        putpixel(random(620),random(419),15);
        /*
            //BIRD SHOUGHT LISTENER END



        	//IF CIRCLE IS SHOUGHT
        	       //OR
        	//CIRCLE SHOUGHT WAITER

            if(c==1 && x>=mcx-40 && x<=mcx+40 && y>=mcy-40 && y<=mcy+40  && hit!=0) //last condition giver to implement relode
        	{

        		  score = score + 1 ;
        		  hit = hit - 1 ;
        		  circle(mcx,mcy,60) ;
        		  delay(20);
        		  while(mcy<550){
        		     sound(mcy);
        		     cleardevice();
        		     circle(mcx,mcy,10);
        		     mcy+=10;
        		     delay(10);
        		  }
        		  circle(mcx,mcy,2);
        		  delay(50);
        		  nosound();


        	}

        */
        mp(x,y,c);
        /*end of circle shot waiter*/
        //IF_SHOUGHT

        if(c==1 && hit!=0) /*last condition giver to implement relode */
        {
            //  score = score - 1 ;
            miss_hit = miss_hit - 1 ;
            hit = hit - 1 ;
            setcolor(RED);
            // SOUND
            sound(1000);
            delay(10);
            sound(634);
            delay(10);
            sound(434);
            delay(30);
            nosound();
            circle(x,y,40);
            delay(300);
            putpixel(random(620),random(419),15);
        }
        putpixel(random(620),random(419),15);
        // EXIT_BUTTON
        setfillstyle(SOLID_FILL,RED);
        bar(600,0,630,50);
        //setcolor(BLACK);
       // settextstyle(BOLD_FONT,HORIZ_DIR,1);

        outtextxy(605,-1,"X");
        // EXIT_BUTTON_LISTENER
        if(c==1 && x>=600 && x<=630 && y>=0 && y<=50 )
        {
            return 0 ;
        }
        // END_OF_EXIT_BOTTON
        setcolor(GREEN);
        /*MOVING THE CIRCLE WITH THE MOUSE */
        circle(x,y,7);
        delay(50);
        /*unknown part */
        if(kbhit())
        {
            char ch = getch();
			if(ch=='w'){
			    miss_hit +=3 ;
			}
			if(ch=='n'){

				return 1 ;
			}
        }


    }
    while(true);

    getch();
    return 1 ;
}



void bird(int t,int n,int flag)
{
    int c,j,p,q,x,y,k ;

    y=getmaxy()/2;
    c=0 ;
    p=0;
    q=0;
    j=0;
    flag=0;
    //setcolor(YELLOW);

// for(k=0;k<500;k++)
    //putpixel(random(620),random(419),15);
    c = t ;
    y = n ;
    /*tail*/
    line(35+c,y+5,35+c,y-5);
    line(35+c,y+5,45+c,y);
    line(35+c,y-5,45+c,y);
    /*tail end */
    /*body*/
    //  ellipse(80+c,y,10-p,350+p,50,10);
//   ellipse(80+c,y,10-p,350+p,40,10);
    ellipse(80+c,y,10-p,350+p,30,10);
    ellipse(80+c,y,10-p,350+p,20,10);
    ellipse(80+c,y,10-p,350+p,10,10);
    /*body end */
    /*neck*/
    line(110+c,y-12,110+c,y+1);
    line(105+c,y-20,105+c,y-5);
    /*neck end*/
    /*beak or thot */
    line(115+c,y-18,120+c,y-5);
    /*end */
    /*legs*/
    line(15+c,y+15,35+c,y+10);
    line(20+c,y+20,35+c,y+10);
    /*legs end*/
    if(flag==0)
        p=p+2;
    if(flag==1)
        p=p-2;
    /*head*/
    circle(110+c,y-18,6);
    circle(110+c,y-18,1);
    /*head end */
    /*wings */
    line(50+c,y-15,20+c,y-35+j);
    line(20+c,y-35+j,90+c,y-15);
    line(50+c,y+15,20+c,y+35+q);
    line(20+c,y+35+q,90+c,y+15);
    /*wings end */
}
int baloon_game()
{

    int speed_rate = 5 ;
    //float count_down_time = 0;
    int level = 1 ;
    int target ;
    /*game loader */
    while(true)
    {
		if(level==9){
			 cleardevice();
			 gotoxy(10,15);
			 printf("GameOver 3:)");
			 return 1 ;
		 }
	if(call_baloon_game(speed_rate,2000,level,12,6))  // 12 birds in 2 minut`s
	{


	    level = level + 1 ;
	    clrscr();
	    cleardevice();

	    gotoxy(30,15);
	    printf("LEVEL %d \n ",level);
	    delay(2000);
	    speed_rate = speed_rate + 2 ;
	    if(call_baloon_game(speed_rate,4000,level,30,10))
	    {
		clrscr();
		cleardevice();
		gotoxy(30,15);
		level = level + 1 ;
		printf("LEVEL %d \n ",level);
		delay(2000);
		speed_rate = speed_rate + 2 ;
		if(call_baloon_game(speed_rate,8000,level,60,20))
		{
		    clrscr();
		    cleardevice();
		    gotoxy(30,15);
		    printf("LEVEL %d \n ",level);
		    delay(500);
		    level = level + 1 ;
		    speed_rate = speed_rate + 2 ;
		}
		else
		{

		    break ;
		}
	    }
	    else
	    {

		break ;
	    }
        }
        else
        {

            break ;

        }


    }
    return 1 ;
}
int call_baloon_game(int speed_rate , float count_down_time,char level,int target,int miss_hit)
{
    int gd = DETECT ,gm ;
    int x , y , c ;
    int score = 0 ;
    int hit = 6 ; /*bullet and shoot counter */
    int flag = 0 ;
    /*moving circle var`s*/
    float mcx = 0 , mcy = 0 ;
    float m1cx = 0 , m1cy = 0 ;
    float m2cx = 0 , m2cy = 0 ;
    float m3cx = 0 , m3cy = 0 ;

    float speed_controll = 10 ;
    initgraph(&gd,&gm,"c:/tc/bgi");
    cm();


    /*GAME LOOP*/
    do
    {
        // clrscr();
        cleardevice();
        // setbkcolor(BLUE);
        mp(x,y,c);
		//hm();
        putpixel(random(620),random(419),15);
        if(flag==0)
        {
            flag = 1 ;
        }
        else
        {
            flag = 0 ;

        }

        /* BULLATE STATE */
        if(hit==0 )
        {

            outtextxy(230,200," RELODE ");

        }
        if(c==2)
        {
            hit = 6 ;
        }
        //end
        putpixel(random(620),random(419),15);
        /*graphicl representation of bullets*/
        for(int i = 0 , j = 0 ; i < hit ; i++,j+=30)
        {
            bar(j,425,j+10,450);

        }

        /*GAME OVER CONDION */
        if(score<-5)
        {
            cleardevice();
            outtextxy(230,200," __GAME OVER__ ");
            getch();
            return 0;
        }
        //END

        putpixel(random(620),random(419),15);
        /*sore printer */
        count_down_time -=1;
        printf("TIME_LEFT = %.4f\n",count_down_time);                                                                /*COUNT_DOWN_TIMER*/
        printf("LEVEL = %d\n",level);
        printf("LIVE`S LEFT %d\n",miss_hit);
        printf("score = %4d / %2d\n",score ,target);
        if(score>=target) return 1 ; //success

        /*tiemout game_over*/
        if(count_down_time<=0)
        {
            cleardevice();
            outtextxy(200,230,"TIME_OUT_GAME_OVER_\n");
            getch();
            return 0 ;
        }
        /*miss_hit game over */
        if(miss_hit<=0)
        {
            cleardevice();
            outtextxy(200,230,"TOO_MANY_MISS_HIT\n");
            getch();
            return 0 ;
        }

        /*bird four */

        /*bird speed*/

        m3cy  = m3cy - speed_rate  ;
        if(m3cy<0)
        {
            m3cy= 400 +  rand() % 150   ;
            m3cx = rand() %300 + 120 ;
        }
        setcolor(YELLOW);
		setfillstyle(SOLID_FILL,YELLOW);
		circle(m3cx,m3cy,20);
	floodfill(m3cx,m3cy,YELLOW) ;
		//rectangle(m3cx-40,m3cy+40,m3cx+40,m3cy-40);

        //  rectangle(m3cx+20,m3cy+20,m3cx+120,m3cy-20);
        /*bird four end*/

        /*bird three */

        /*SPEED_CONTORL */
        m2cy  = m2cy - speed_rate ;
        if(m2cy<0)
        {
            m2cy = 400 + rand() % 100   ;
            m2cx = rand() %400 + 70 ;
        }
        setcolor(RED);
        setfillstyle(SOLID_FILL,RED);
		circle(m2cx,m2cy,20);
	floodfill(m2cx,m2cy,RED);
		//rectangle(m2cx-40,m2cy+40,m2cx+40,m2cy-40);
        // rectangle(m2cx+20,m2cy+20,m2cx+120,m2cy-20);
        /*bird three end*/


        /*bird two */

        m1cy  = m1cy - speed_rate  ;
        if(m1cy<0)
        {
            m1cy = 400 +  rand() % 100   ;

            m1cx = rand() %400 + 30 ;
        }
        setcolor(BLUE);
        setfillstyle(SOLID_FILL,BLUE);
		circle(m1cx,m1cy,20);
        floodfill(m1cx,m1cy,BLUE);
		//rectangle(m1cx-40,m1cy+40,m1cx+40,m1cy-40);
        // rectangle(m1cx+20,m1cy+20,m1cx+120,m1cy-20);
        /*bird two end*/

        /*bird  one */



        /*moving circle */



        //as moving in vertical line x cordinate will be constant
          mcy  = mcy - speed_rate  ; // we can controll the sepped of circle object by controlling increment

        if(mcy<0)
        {
	    mcx =  250 +rand() %400   ;
            mcy =  450 ;
        }
	    setcolor(WHITE);
        setfillstyle(SOLID_FILL,WHITE);
		circle(mcx,mcy,20);
	floodfill(mcx,mcy,WHITE);
		//rectangle(mcx-40,mcy+40,mcx+40,mcy-40);


        /*IF BIRD TWO IS SHOUGHT */

        if(c==1 && x>=m2cx-40 && x<=m2cx+40 && y>=m2cy-40 && y<=m2cy+40  && hit!=0) /*last condition giver to implement relode */
        {

            score = score + 1 ;
            hit = hit - 1 ;
            //circle(m1cx,mcy,60) ;
            delay(20);
            while(m2cy<550)
            {
                sound(m2cy);
                cleardevice();
                circle(m2cx,m2cy,10);
                m2cy+=10;
                delay(10);
            }
            circle(m2cx,m2cy,2);
            delay(50);
            nosound();
            putpixel(random(620),random(419),15);

        }

        /*IF BIRD FOUR IS SHOUGHT */

        if(c==1 && x>=m3cx-40 && x<=m3cx+40 && y>=m3cy-40 && y<=m3cy+40  && hit!=0) /*last condition giver to implement relode */
        {

            score = score + 1 ;
            hit = hit - 1 ;
            //circle(m1cx,mcy,60) ;
            delay(20);
            while(m3cy<550)
            {
                sound(m3cy);
                cleardevice();
                circle(m3cx,m3cy,10);
                m3cy+=10;
                delay(10);
            }
            circle(m3cx,m3cy,2);
            delay(50);
            nosound();
            putpixel(random(620),random(419),15);

        }

        /*IF BIRD THREE IS SHOUGHT */

        if(c==1 && x>=m1cx-40 && x<=m1cx+40 && y>=m1cy-40 && y<=m1cy+40  && hit!=0) /*last condition giver to implement relode */
        {

            score = score + 1 ;
            hit = hit - 1 ;
            //circle(m1cx,mcy,60) ;
            delay(20);
            while(m1cy<550)
            {
                sound(m1cy);
                cleardevice();
                circle(m1cx,m1cy,10);
                m1cy+=10;
                delay(10);
            }
            circle(m1cx,m1cy,2);
            delay(50);
            nosound();
            putpixel(random(620),random(419),15);

        }

        /*IF BIRD ONE IS SHOUGHT */

        if(c==1 && x>=mcx-40 && x<=mcx+40 && y>=mcy-40 && y<=mcy+40  && hit!=0) /*last condition giver to implement relode */
        {

            score = score + 1 ;
            hit = hit - 1 ;
            circle(mcx,mcy,60) ;
            delay(20);
            while(mcy<550)
            {
                sound(mcy);
                cleardevice();
                circle(mcx,mcy,10);
                mcy+=10;
                delay(10);
            }

            circle(mcx,mcy,2);
            delay(50);
            nosound();
            putpixel(random(620),random(419),15);

        }
        putpixel(random(620),random(419),15);

         mp(x,y,c);
        /*end of circle shot waiter*/
        //IF_SHOUGHT

        if(c==1 && hit!=0) /*last condition giver to implement relode */
        {
            //  score = score - 1 ;
            miss_hit = miss_hit - 1 ;
            hit = hit - 1 ;
            setcolor(RED);
            // SOUND
            sound(1000);
            delay(10);
            sound(634);
            delay(10);
            sound(434);
            delay(30);
            nosound();
            circle(x,y,40);
            delay(300);
            putpixel(random(620),random(419),15);
        }
        putpixel(random(620),random(419),15);
        // EXIT_BUTTON
        setfillstyle(SOLID_FILL,RED);
        bar(600,0,630,50);
        //setcolor(BLACK);
       // settextstyle(BOLD_FONT,HORIZ_DIR,1);
        outtextxy(605,-1,"X");
        // EXIT_BUTTON_LISTENER
        if(c==1 && x>=600 && x<=630 && y>=0 && y<=50 )
        {
            return 0 ;
        }
        // END_OF_EXIT_BOTTON
        setcolor(GREEN);
        /*MOVING THE CIRCLE WITH THE MOUSE */
        circle(x,y,10);
        delay(50);
		// cheat code
         if(kbhit())
        {
            char ch = getch();
			if(ch=='w'){
			    miss_hit +=3 ;
			}
			if(ch=='n'){

				return 1 ;
			}
        }



    }
    while(true);

    getch();
    return 1 ;
}

/*level one */
int LevelOne()
{

    int gd = DETECT , gm ;
    int x , y , c ;
    int out = 0 ;
    //float score = 0 ;
    int exit_level = 0 ;
    int match_finder = 0 ;
    int hint_x_cordinate = 0 ;
	missHit = 0 ;
    initgraph(&gd,&gm,"c:/tc/bgi");
    /*boolian section*/
    //int cow = 1 , bat = 1 , rat = 1 , cat = 1 , hen = 1 , ant = 1 , dog = 1 ;
    int bat = 1 , dog = 1 , cow = 1 , ant = 1 , pig = 1 ;
    /*boolean array */
    // 0 is false
    // 1 is true
    int show[5] = {1,0,0,0,0} ;
    /*file initialization */
    FILE *fp ;
    /*THE ROWS ARE COLUMN AND THE COLUMNS ARE ROWS IN THE BELOW MATRIX */

    /*  char* ara[100] =
      {

      "D" , "B" , "A" , "T" ,

      "C" , "O" , "W"  , "N" ,

      "D" , "O" , "G" , "A" ,

      "H" , "P" , "X" , "U"

      } ;
     */
    char* ara[100] =
    {

        "D" , "C" , "P" , "H" ,

        "B" , "O" , "I"  ,"P" ,

        "A" , "W" , "G" , "I" ,

        "T" , "N" , "A" , "E"

    } ;

    char out_string[100] ;
    out_string[0] = '\0';
    int oti = -1 ; /*out put string dincrement */

    /*LEVEL LOOP*/
    while(out==0)
    {

        /*output string in the buttom */
        setcolor(GREEN);
        // outtextxy(55,340,out_string);
        setbkcolor(8);
        clrscr();
        cleardevice();
        cm();
        /*level number*/
        outtextxy(20,20,"Animal`s");
        /*score */


        /* USER INTERFACE */
        /*  GRAPHICAL PART */

        //BUTTON LAYOUT
        for(int i = 350 , k = 0 ; i<550 ; i+=50)
        {

            for(int j =50 ; j<250 ; j+=50,/*(j<200)? k++ : k*/k++)
            {
                // if(i<300 & j<300)k++;
                if(i<=550 && j<=300)  outtextxy(i+20,j+20,ara[k])  ;
                //  rectangle(i,j,j,i);
                if(i<=550 && j<=300 ) circle(i+22,j+22,20);
            }

        }

        /*EXIT BUTTON*/
        setfillstyle(SOLID_FILL,RED);
        bar(600,0,650,30);
        outtextxy(600,10," EXIT");


        /*SUBMIT BUTTON*/
        setfillstyle(SOLID_FILL,BLUE);
        bar(355,300,403,330);
        outtextxy(356,280,out_string);
        outtextxy(356,290,"______________________");
        outtextxy(356,310,"SUBMIT");

        /*SCORE WEIGIT*/


        /*   setfillstyle(SOLID_FILL,BLUE);
         bar(320,50,390,80);
         outtextxy(322,60,"Score : ");   */
        gotoxy(25,0);
        printf("-%30s = %-.2f ","score",score);


        /*BACK_BUTTON*/
        setfillstyle(SOLID_FILL,RED);
        bar(410,300,450,330);
        outtextxy(413,310 ,"<--");

        /*
        	//HINT SECTION


        	if(cow!=0)   outtextxy(10,50,"* Gives us milk ");
        	if(bat!=0)   outtextxy(10,60,"* mammal that can fly ")  ;
        	if(cat!=0)   outtextxy(10,80,"* Tigers Aunt  ");
        	if(rat!=0)   outtextxy(10,70,"* Cats Enemy ");
        	if(hen!=0)   outtextxy(10,90,"* Lays egg ");

        	if(ant!=0)
        	{
        	    outtextxy(10,100,"* Works in group  ");
        	    outtextxy(10,110 ," and can lift ten times it weight ") ;
        	}
        	if(dog!=0)  outtextxy(10,120,"* Mans best friend  ");

        	if(cow == 0 && bat == 0 && rat == 0 && cat == 0 && hen ==0 && ant == 0 && dog == 0 ) exit_level = 1 ;

        */

        /*	NEW HINT SECTION */
        char temp[] = "hello \n arif ";
        //	gotoxy(4,4); printf("arif \n abid");
        if(show[0])
        {
            gotoxy(4,4);
            printf("*Mammals that can fly \n   can not see or blind");
        }    // bat
        if(show[1])
        {
            gotoxy(4,4);
            printf("*Man`s best friend \n   *keeps away thief ");
        } // outtextxy(10,50,"* dog "); ;
        if(show[2])
        {
            gotoxy(4,4);
            printf("*Gives us milk \n   *Lives on Grass\n");
        }// outtextxy(10,50,"* cow "); ;
        if(show[3])
        {
            gotoxy(4,4);
            printf("*Colonial insects , hard working \n   can not fly \n");
        }//outtextxy(10,50,"* ant "); ;
        if(show[4])
        {
            gotoxy(4,4);
            printf("*Wild animals , also known as boar\n");
        }//outtextxy(10,50,"* pig "); ;
        /* NEW HINT SECTION END */


        if(exit_level==1)
        {
            cleardevice();
            clrscr();
            return 1 ;
        }
        /*BACKGROUNG_ACTIVITY_AND_ACTION_LISTENER*/


        while(1)
        {
            cm();
            mp(x,y,c);
            // admin next level pass
			if(kbhit()){
				char ch = getch();
				if(ch=='N'){
					return 1 ;
				}
			}

            //back button interface
            if(c==1 && x>=410 && x<=450 && y>=300 && y<=330 && oti>=0 )
            {
                sound(200);
                delay(20);
                nosound();
                out_string[oti] = '\0';
                oti =  oti - 1 ;
                delay(DELAY_TIME);
                break ;
            }

            /* SUBMIT BUTTON */
            // submit button inter face
            // this is also the database every meaningfull word has a identical
            // boolina identifier wich`s value is altered if the right word is entered and then
            // the submit button is clicked
            if(c==1 && x>=355 && x<=403 && y>=300 && y<=330 )
            {
                sound(300);
                delay(20);
                nosound();
                /*data_base*/

                //BAT.
                if(strcmp(out_string,"BAT")==0 && bat!=0 && show[0])
                {
                    score = score + 1.25 ;
                    bat = 0 ;
                    show[1] = 1 ;
                    show[0] = 0 ;
                }
                //DOG
                else if(strcmp(out_string,"DOG")==0 && dog!=0 && show[1])
                {
                    score = score + 1.25 ;
                    dog = 0 ;
                    show[2] = 1 ;
                    show[1] = 0 ;
                }
                //COW
                if(strcmp(out_string,"COW")==0 && cow!=0 && show[2])
                {
                    score = score + 1 ;
                    cow = 0 ;
                    show[3] = 1 ;
                    show[2] = 0 ;
                }
                //ANT
                else if(strcmp(out_string,"ANT")==0 && ant!=0 && show[3])
                {
                    score = score + 1 ;
                    ant = 0 ;
                    show[4] = 1 ;
                    show[3] = 0 ;
                }

                //PIG
                else if(strcmp(out_string,"PIG")==0 && pig!=0 && show[4])
                {
                    score = score + 1 ;
                    pig = 0 ;
                    show[4] = 0 ;
                    return 1 ;

                }



                else if(out_string[0]!='\0')   // if wrong answer if given
                {
                    // wont be counted as a submisson if the string is empty
                    score = score - 0.25 ;
                    missHit = 0 ;
                    missHit++ ;
                    if(missHit >= 3)
                    {
                        missHit  = 0 ;
                        return     0 ;
                    }



                }



                //formatting the input section for new input
                delay(DELAY_TIME);
                match_finder = -1 ;
                out_string[0] = '\0';
                oti = - 1 ;
                break ;
            }


            // this is the exit sign on the top-right side

            if(c==1 && x>=600 && x<=650 && y>=0 && y<=50)
            {
                sound(500);
                delay(30);
                nosound();
                out = -1 ;
                break ;
            }


            /* POSITIO 0 0*/
            if(c==1 && x >=350 && x<=400 && y>=50 && y<=100 )
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'D';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 0 1*/
            if(c==1 && x>=400 && x<=450 && y >=50 && y<=100)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'B';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 0 2*/
            if(c==1 && x>=450 && x<=500 && y >=50 && y<=100)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'A';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            //POSITION 0 3
            if(c==1 && x>=500 && x<=550 && y >=50 && y<=100)
            {

                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'T';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /* //POSITION 0 4
              if(c==1 && x>=250 && x<=300 && y >=50 && y<=100){
             oti = oti + 1 ;
             out_string[oti] = 'T';
             out_string[oti+1] = '\0';
             delay(DELAY_TIME);
             break ;
              }
             //POSITION 0 5
              if(c==1 && x>=250 && x<=300 && y >=50 && y<=100){
             oti = oti + 1 ;
             out_string[oti] = 'I';
             out_string[oti+1] = '\0';
             delay(DELAY_TIME);
             break ;
              } */

            //POSITION 1 0
            if(c==1 && x>=350 && x<=400 && y >=100 && y<=150)
            {
                oti = oti + 1 ;
                out_string[oti] = 'C';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            //POSITION 1 1
            if(c==1 && x>=400 && x<=450 && y >=100 && y<=150)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'O';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            //POSITION 1 2
            if(c==1 && x>=450 && x<=500 && y >=100 && y<=150)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'W';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }
            //POSITION 1 3
            if(c==1 && x>=500 && x<=550 && y >=100 && y<=150)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'N';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            //POSITION 2 0
            if(c==1 && x>=350 && x<=400 && y >=150 && y<=200)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'P';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            //POSITION 2 1
            if(c==1 && x>=400 && x<=450 && y >=150 && y<=200)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'I';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }
            //POSITION 2 2
            if(c==1 && x>=450 && x<=500 && y >=150 && y<=200)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'G';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }
            //POSITION 2 3
            if(c==1 && x>=500 && x<=550 && y >=150 && y<=200)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'A';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }
            //POSITION 3 0
            if(c==1 && x>=350 && x<=400 && y>=200 && y<=250 )
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'H' ;
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }
            //POSITION 3 1
            if(c==1 && x>=400 && x<=450 && y>=200 && y<=250 )
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'P' ;
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }
            //POSITION 3 2
            if(c==1 && x>=450 && x<=500 && y>=200 && y<=250 )
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'I';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }
            //POSITION 3 3
            if(c==1 && x>=500 && x<=550 && y>=200 && y<=250 )
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'E';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }



        }






 }
    clrscr();
    cleardevice();
    printf("Exiting....");
    delay(300);
    return 0 ;
}
int LevelThree()
{

    int gd = DETECT , gm ;
    int x , y , c ;
    int out = 0 ;
    //float score = 0 ;
    int exit_level = 0 ;
    int match_finder = 0 ;
    int hint_x_cordinate = 0 ;
	missHit = 0 ;
    initgraph(&gd,&gm,"c:/tc/bgi");
    /*boolian section*/

    int rice = 1 , bean = 1 , corn = 1 , cack = 1 , plam = 1 , meat = 1 ;
    /*boolean array */
    // 0 is false
    // 1 is true
    int show[6] = {1,0,0,0,0,0} ;
    /*file initialization */
    FILE *fp ;
    /*THE ROWS ARE COLUMN AND THE COLUMNS ARE ROWS IN THE BELOW MATRIX */

    /*  char* ara[100] =
      {

          "D" , "B" , "A" , "T" ,

          "C" , "O" , "W"  , "N" ,

          "D" , "O" , "G" , "A" ,

          "H" , "P" , "X" , "U"

      } ;
     */
    char* ara[100] =
    {

        "A" , "R" , "I" , "C" , "E" , "F"  ,

        "B" , "F" , "N"  ,"A" , "E" , "B" ,

        "N" , "R" , "O" , "C" , "M" , "P" ,

        "C" , "G" , "J" , "K" , "N" , "L" ,

        "D" , "H" , "K" , "L" , "O" , "A" ,

        "E" , "I" , "T" , "A" , "E" , "M"

    } ;

    char out_string[100] ;
    out_string[0] = '\0';
    int oti = -1 ; /*out put string dincrement */

    /*LEVEL LOOP*/
    while(out==0)
    {

        /*output string in the buttom */
        setcolor(GREEN);
        // outtextxy(55,340,out_string);
        setbkcolor(8);
        clrscr();
        cleardevice();
        cm();
        /*level number*/
        outtextxy(20,20,"level 3");
        /*score */


        /* USER INTERFACE */
        /*  GRAPHICAL PART */

        //BUTTON LAYOUT
        for(int i = 300 , k = 0 ; i<650 ; i+=50)
        {

            for(int j =50 ; j<=350 ; j+=50/*(j<200)? k++ : k*/)
            {
                // if(i<300 & j<300)k++;
                if(i<=550 && j<=300)  outtextxy(i+20,j+20,ara[k++])  ;
                //  rectangle(i,j,j,i);
                if(i<=550 && j<=300 ) circle(i+22,j+22,20);
            }

        }

        /*EXIT BUTTON*/
        setfillstyle(SOLID_FILL,RED);
        bar(600,0,650,30);
        outtextxy(600,10," EXIT");


        /*SUBMIT BUTTON*/
        setfillstyle(SOLID_FILL,BLUE);
        bar(355,400,403,430);
        outtextxy(356,380,out_string);
        outtextxy(356,390,"______________________");
        outtextxy(356,410,"SUBMIT");

        /*SCORE WEIGIT*/


        /*   setfillstyle(SOLID_FILL,BLUE);
         bar(320,50,390,80);
         outtextxy(322,60,"Score : ");   */
        gotoxy(25,0);
        printf("-%30s = %-.2f ","score",score);


        /*BACK_BUTTON*/
        setfillstyle(SOLID_FILL,RED);
        bar(410,400,450,430);
        outtextxy(413,410 ,"<--");


        /*	NEW HINT SECTION */

        if(show[0])
        {
            gotoxy(4,4);
            printf("*main crop in Bangladesh\n ");
        } //outtextxy(10,50,"* rice "); ;
        if(show[1])
        {
            gotoxy(4,4);
            printf("*a leguminous plant that bears beans in pods.");
        }  //outtextxy(10,50,"* bean "); ;
        if(show[2])
        {
            gotoxy(4,4) ;
            printf("*The chief cerial crop of England\n   *The grain of serial crop ");
        }// outtextxy(10,50,"* corn  "); ;
        if(show[3])
        {
            gotoxy(4,4) ;
            printf("*Celebrate our birthday with ");
        }//outtextxy(10,50,"* cack "); ;
        if(show[4])
        {
            gotoxy(4,4);
            printf("*The fruit of a very tall tree\n   *Juicy Fruit\n");
        }//outtextxy(10,50,"* plam  "); ;
        if(show[5])
        {
            gotoxy(4,4);
            printf("*The flesh of animal as food\n");
        }//outtextxy(10,50,"* meat  "); ;
        /* NEW HINT SECTION END */


        if(exit_level==1)
        {
            cleardevice();
            clrscr();
            return 1 ;
        }
        /*BACKGROUNG_ACTIVITY_AND_ACTION_LISTENER*/


        while(1)
        {
            cm();
            mp(x,y,c);
              // admin next level pass
			if(kbhit()){
				char ch = getch();
				if(ch=='N'){
					return 1 ;
				}
			}

            //back button interface
            if(c==1 && x>=410 && x<=450 && y>=400 && y<=430 && oti>=0 )
            {
                sound(200);
                delay(20);
                nosound();
                out_string[oti] = '\0';
                oti =  oti - 1 ;
                delay(DELAY_TIME);
                break ;
            }

            /* SUBMIT BUTTON */
            // submit button inter face
            // this is also the database every meaningfull word has a identical
            // boolina identifier wich`s value is altered if the right word is entered and then
            // the submit button is clicked
            if(c==1 && x>=355 && x<=403 && y>=400 && y<=430 )
            {
                sound(300);
                delay(20);
                nosound();
                /*data_base*/

                //RICE
                if(strcmp(out_string,"RICE")==0 && rice!=0 && show[0])
                {
                    score = score + 1.25 ;
                    rice = 0 ;
                    show[1] = 1 ;
                    show[0] = 0 ;
                }
                //BEAN
                else if(strcmp(out_string,"BEAN")==0 && bean!=0 && show[1])
                {
                    score = score + 1.25 ;
                    bean = 0 ;
                    show[2] = 1 ;
                    show[1] = 0 ;
                }
                //CORN
                if(strcmp(out_string,"CORN")==0 && corn!=0 && show[2])
                {
                    score = score + 1 ;
                    corn = 0 ;
                    show[3] = 1 ;
                    show[2] = 0 ;
                }
                //CACK
                else if(strcmp(out_string,"CACK")==0 && cack!=0 && show[3])
                {
                    score = score + 1 ;
                    cack = 0 ;
                    show[4] = 1 ;
                    show[3] = 0 ;
                }

                //PLAM
                else if(strcmp(out_string,"PLAM")==0 && plam!=0 && show[4])
                {
                    score = score + 1 ;
                    plam = 0 ;
                    show[5] = 1 ;
                    show[4] = 0 ;

                }  //MEAT
                else if(strcmp(out_string,"MEAT")==0 && meat!=0 && show[5])
                {
                    score = score + 1 ;
                    meat = 0 ;
                    show[5] = 0 ;
                    return 1 ;

                }



                // if wrong answer if given

                else if(out_string[0]!='\0') // wont be counted as a submisson if the string is empty
                {
                    score = score - 0.25 ;
                    missHit++;
                    if(missHit>=3)
                    {
                        missHit = 0 ;
                        return 0 ;
                    }

                }
                else
                {

                    missHit++;
                    if(missHit>=3)
                    {
                        missHit = 0 ;
                        return 0 ;
                    }
                }


                //formatting the input section for new input
                delay(DELAY_TIME);
                match_finder = -1 ;
                out_string[0] = '\0';
                oti = - 1 ;
                break ;
            }


            // this is the exit sign on the top-right side

            if(c==1 && x>=600 && x<=650 && y>=0 && y<=50)
            {
                sound(500);
                delay(30);
                nosound();
                out = -1 ;
                break ;
            }

            /*0*/
            /* POSITIO 0 0*/
            if(c==1 && x >=300 && x<=350 && y>=50 && y<=100 )
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'A';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 0 1*/
            if(c==1 && x>=350 && x<=400 && y >=50 && y<=100)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'B';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 0 2*/
            if(c==1 && x>=400 && x<=450 && y >=50 && y<=100)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'N';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            //POSITION 0 3
            if(c==1 && x>=450 && x<=500 && y >=50 && y<=100)
            {

                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'C';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            //POSITION 0 4
            if(c==1 && x>=500 && x<=550 && y >=50 && y<=100)
            {
                oti = oti + 1 ;
                out_string[oti] = 'D';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }
            //POSITION 0 5
            if(c==1 && x>=550 && x<=600 && y >=50 && y<=100)
            {
                oti = oti + 1 ;
                out_string[oti] = 'E';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            /*1*/
            /* POSITIO 1 0*/
            if(c==1 && x >=300 && x<=350 && y>=100 && y<=150 )
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'R';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 1 1*/
            if(c==1 && x>=350 && x<=400 && y >=100 && y<=150)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'F';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 1 2*/
            if(c==1 && x>=400 && x<=450 && y >=100 && y<=150)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'R';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            //POSITION 1 3
            if(c==1 && x>=450 && x<=500 && y >=100 && y<=150)
            {

                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'G';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            //POSITION 1 4
            if(c==1 && x>=500 && x<=550 && y >=100 && y<=150)
            {
                oti = oti + 1 ;
                out_string[oti] = 'H';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }
            //POSITION 1 5
            if(c==1 && x>=550 && x<=600 && y >=100 && y<=150)
            {
                oti = oti + 1 ;
                out_string[oti] = 'I';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            /*2*/


            /*POSITION 2 0*/
            if(c==1 && x>=300 && x<=350 && y >=150 && y<=200)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'I';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 2 1*/
            if(c==1 && x>=350 && x<=400 && y >=150 && y<=200)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'N';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 2 2*/
            if(c==1 && x>=400 && x<=450 && y >=150 && y<=200)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'O';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            //POSITION 2 3
            if(c==1 && x>=450 && x<=500 && y >=150 && y<=200)
            {

                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'J';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            //POSITION 2 4
            if(c==1 && x>=500 && x<=550 && y >=150 && y<=200)
            {
                oti = oti + 1 ;
                out_string[oti] = 'K';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }
            //POSITION 2 5
            if(c==1 && x>=550 && x<=600 && y >=150 && y<=200)
            {
                oti = oti + 1 ;
                out_string[oti] = 'T';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }




            /*3*/
            /*POSITION 3 0*/
            if(c==1 && x>=300 && x<=350 && y >=200 && y<=250)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'C';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 3 1*/
            if(c==1 && x>=350 && x<=400 && y >=200 && y<=250)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'A';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 3 2*/
            if(c==1 && x>=400 && x<=450 && y >=200 && y<=250)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'C';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            //POSITION 3 3
            if(c==1 && x>=450 && x<=500 && y >=200 && y<=250)
            {

                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'K';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            //POSITION 3 4
            if(c==1 && x>=500 && x<=550 && y >=200 && y<=250)
            {
                oti = oti + 1 ;
                out_string[oti] = 'L';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }
            //POSITION 3 5
            if(c==1 && x>=550 && x<=600 && y >=200 && y<=250)
            {
                oti = oti + 1 ;
                out_string[oti] = 'A';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            /*4*/

            // POSITION 4 0
            if(c==1 && x>=300 && x<=350 && y >=250 && y<=300)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'E';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 4 1*/
            if(c==1 && x>=350 && x<=400 && y >=250 && y<=300)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'E';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 4 2*/
            if(c==1 && x>=400 && x<=450 && y >=250 && y<=300)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'M';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            //POSITION 4 3
            if(c==1 && x>=450 && x<=500 && y >=250 && y<=300)
            {

                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'N';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            //POSITION 4 4
            if(c==1 && x>=500 && x<=550 && y >=250 && y<=300)
            {
                oti = oti + 1 ;
                out_string[oti] = 'O';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }
            //POSITION 4 5
            if(c==1 && x>=550 && x<=600 && y >=250 && y<=300)
            {
                oti = oti + 1 ;
                out_string[oti] = 'E';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }





            /*5*/

            // POSITIO 5 0
            if(c==1 && x>=300 && x<=350 && y >=300 && y<=350)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'F';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 5 1*/
            if(c==1 && x>=350 && x<=400 && y >=300 && y<=350)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'B';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 5 2*/
            if(c==1 && x>=400 && x<=450 &&  y >=300 && y<=350)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'P';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            //POSITION 5 3
            if(c==1 && x>=450 && x<=500 &&  y >=300 && y<=350)
            {

                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'L';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            //POSITION 5 4
            if(c==1 && x>=500 && x<=550 &&  y >=300 && y<=350)
            {
                oti = oti + 1 ;
                out_string[oti] = 'A';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }
            //POSITION 5 5
            if(c==1 && x>=550 && x<=600 &&  y >=300 && y<=350)
            {
                oti = oti + 1 ;
                out_string[oti] = 'M';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


        }






}
    clrscr();
    cleardevice();
    printf("Exiting....");
    delay(300);
    return 1 ;
}
// LevelThreeEnd

//level 2
//level two
int LevelTwo()
{

    int gd = DETECT , gm ;
    int x , y , c ;
    int out = 0 ;
    //float score = 0 ;
    int exit_level = 0 ;
    int match_finder = 0 ;
    int hint_x_cordinate = 0 ;
	missHit = 0 ;
    initgraph(&gd,&gm,"c:/tc/bgi");
    /*boolian section*/

    //int rice = 1 , bean = 1 , corn = 1 , cack = 1 , plam = 1 , meat = 1 ;
    int cap = 1 , tie = 1 , coat = 1 , wig = 1 , belt = 1 ;
    /*boolean array */
    // 0 is false
    // 1 is true
    int show[6] = {1,0,0,0,0,0} ;
    /*file initialization */
    FILE *fp ;
    /*THE ROWS ARE COLUMN AND THE COLUMNS ARE ROWS IN THE BELOW MATRIX */

    /*  char* ara[100] =
      {

          "D" , "B" , "A" , "T" ,

          "C" , "O" , "W"  , "N" ,

          "D" , "O" , "G" , "A" ,

          "H" , "P" , "X" , "U"

      } ;
     */
    char* ara[100] =
    {

        "P" , "W" , "C" , "C" , "B" , "D"  ,

        "A" , "C" , "O"  ,"L" , "C" , "W" ,

        "B" , "A" , "B" , "C" , "B" , "X" ,

        "T" , "E" , "C" , "E" , "A" , "W" ,

        "W" , "I" , "L" , "P" , "I" , "P" ,

        "C" , "T" , "A" , "G" , "M" , "L"

    } ;

    char out_string[100] ;
    out_string[0] = '\0';
    int oti = -1 ; /*out put string dincrement */

    /*LEVEL LOOP*/
    while(out==0)
    {

        /*output string in the buttom */
        setcolor(GREEN);
        // outtextxy(55,340,out_string);
        setbkcolor(8);
        clrscr();
        cleardevice();
        cm();
        /*level number*/
        outtextxy(20,20,"level 2");
        /*score */


        /* USER INTERFACE */
        /*  GRAPHICAL PART */

        //BUTTON LAYOUT
        for(int i = 300 , k = 0 ; i<650 ; i+=50)
        {

            for(int j =50 ; j<=350 ; j+=50/*(j<200)? k++ : k*/)
            {
                // if(i<300 & j<300)k++;
                if(i<=550 && j<=300)  outtextxy(i+20,j+20,ara[k++])  ;
                //  rectangle(i,j,j,i);
                if(i<=550 && j<=300 ) circle(i+22,j+22,20);
            }

        }

        /*EXIT BUTTON*/
        setfillstyle(SOLID_FILL,RED);
        bar(600,0,650,30);
        outtextxy(600,10," EXIT");


        /*SUBMIT BUTTON*/
        setfillstyle(SOLID_FILL,BLUE);
        bar(355,400,403,430);
        outtextxy(356,380,out_string);
        outtextxy(356,390,"______________________");
        outtextxy(356,410,"SUBMIT");

        /*SCORE WEIGIT*/


        /*   setfillstyle(SOLID_FILL,BLUE);
         bar(320,50,390,80);
         outtextxy(322,60,"Score : ");   */
        gotoxy(25,0);
        printf("-%30s = %-.2f ","score",score);


        /*BACK_BUTTON*/
        setfillstyle(SOLID_FILL,RED);
        bar(410,400,450,430);
        outtextxy(413,410 ,"<--");

        /*
                //HINT SECTION


                if(cow!=0)   outtextxy(10,50,"* Gives us milk ");
                if(bat!=0)   outtextxy(10,60,"* mammal that can fly ")  ;
                if(cat!=0)   outtextxy(10,80,"* Tigers Aunt  ");
                if(rat!=0)   outtextxy(10,70,"* Cats Enemy ");
                if(hen!=0)   outtextxy(10,90,"* Lays egg ");

                if(ant!=0)
                {
                    outtextxy(10,100,"* Works in group  ");
                    outtextxy(10,110 ," and can lift ten times it weight ") ;
                }
                if(dog!=0)  outtextxy(10,120,"* Mans best friend  ");

                if(cow == 0 && bat == 0 && rat == 0 && cat == 0 && hen ==0 && ant == 0 && dog == 0 ) exit_level = 1 ;

        */

        /*	NEW HINT SECTION */

        if(show[0])
        {
            gotoxy(4,4);
            printf("*Covers our head ");
        }//outtextxy(10,50,"* cap "); ;
        if(show[1])
        {
            gotoxy(4,4);
            printf("*A long piece of cloth\n   *Worn on neck\n");
        }// outtextxy(10,50,"* tie "); ;
        if(show[2])
        {
            gotoxy(4,4);
            printf("*Worn out doors and typically \n   extended below hips ");
        }//outtextxy(10,50,"* coat  "); ;
        if(show[3])
        {
            gotoxy(4,4);
            printf("*Flase hair , artificial hair \n");
        }//outtextxy(10,50,"* wig "); ;
        if(show[4])
        {
            gotoxy(4,4);
            printf("*A string of leather worn round \n   the wrist");
        }//outtextxy(10,50,"* belt  "); ;

        /* NEW HINT SECTION END */


        if(exit_level==1)
        {
            cleardevice();
            clrscr();
            return 1 ;
        }
        /*BACKGROUNG_ACTIVITY_AND_ACTION_LISTENER*/


        while(1)
        {
            cm();
            mp(x,y,c);

			  // admin next level pass
			if(kbhit()){
				char ch = getch();
				if(ch=='N'){
					return 1 ;
				}
			}


            //back button interface
            if(c==1 && x>=410 && x<=450 && y>=400 && y<=430 && oti>=0 )
            {
                sound(200);
                delay(20);
                nosound();
                out_string[oti] = '\0';
                oti =  oti - 1 ;
                delay(DELAY_TIME);
                break ;
            }

            /* SUBMIT BUTTON */
            // submit button inter face
            // this is also the database every meaningfull word has a identical
            // boolina identifier wich`s value is altered if the right word is entered and then
            // the submit button is clicked
            if(c==1 && x>=355 && x<=403 && y>=400 && y<=430 )
            {
                sound(300);
                delay(20);
                nosound();
                /*data_base*/

                //cap
                if(strcmp(out_string,"CAP")==0 && cap!=0 && show[0])
                {
                    score = score + 1.25 ;
                    cap = 0 ;
                    show[1] = 1 ;
                    show[0] = 0 ;
                }
                //tie
                else if(strcmp(out_string,"TIE")==0 && tie && show[1])
                {
                    score = score + 1.25 ;
                    tie = 0 ;
                    show[2] = 1 ;
                    show[1] = 0 ;
                }
                //coat
                if(strcmp(out_string,"COAT")==0 && coat && show[2])
                {
                    score = score + 1 ;
                    coat = 0 ;
                    show[3] = 1 ;
                    show[2] = 0 ;
                }
                //wig
                else if(strcmp(out_string,"WIG")==0 && wig && show[3])
                {
                    score = score + 1 ;
                    wig = 0 ;
                    show[4] = 1 ;
                    show[3] = 0 ;
                }

                //belt
                else if(strcmp(out_string,"BELT")==0 && belt && show[4])
                {
                    score = score + 1 ;
                    belt = 0 ;
                    show[5] = 1 ;
                    show[4] = 0 ;
                    return 1 ;

                }


                // if wrong answer if given


                else if(out_string[0]!='\0')   // if wrong answer if given
                {
                    // wont be counted as a submisson if the string is empty
                    score = score - 0.25 ;
                    missHit = 0 ;
                    missHit++ ;
                    if(missHit >= 3)
                    {
                        missHit  = 0 ;
                        return     0 ;
                    }



                }


                //formatting the input section for new input
                delay(DELAY_TIME);
                match_finder = -1 ;
                out_string[0] = '\0';
                oti = - 1 ;
                break ;
            }


            // this is the exit sign on the top-right side

            if(c==1 && x>=600 && x<=650 && y>=0 && y<=50)
            {
                sound(500);
                delay(30);
                nosound();
                out = -1 ;
                break ;
            }

            /*0*/
            /* POSITIO 0 0*/
            if(c==1 && x >=300 && x<=350 && y>=50 && y<=100 )
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'P';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 0 1*/
            if(c==1 && x>=350 && x<=400 && y >=50 && y<=100)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'A';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 0 2*/
            if(c==1 && x>=400 && x<=450 && y >=50 && y<=100)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'B';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            //POSITION 0 3
            if(c==1 && x>=450 && x<=500 && y >=50 && y<=100)
            {

                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'T';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            //POSITION 0 4
            if(c==1 && x>=500 && x<=550 && y >=50 && y<=100)
            {
                oti = oti + 1 ;
                out_string[oti] = 'W';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }
            //POSITION 0 5
            if(c==1 && x>=550 && x<=600 && y >=50 && y<=100)
            {
                oti = oti + 1 ;
                out_string[oti] = 'C';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            /*1*/
            /* POSITIO 1 0*/
            if(c==1 && x >=300 && x<=350 && y>=100 && y<=150 )
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'W';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 1 1*/
            if(c==1 && x>=350 && x<=400 && y >=100 && y<=150)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'C';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 1 2*/
            if(c==1 && x>=400 && x<=450 && y >=100 && y<=150)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'A';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            //POSITION 1 3
            if(c==1 && x>=450 && x<=500 && y >=100 && y<=150)
            {

                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'E';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            //POSITION 1 4
            if(c==1 && x>=500 && x<=550 && y >=100 && y<=150)
            {
                oti = oti + 1 ;
                out_string[oti] = 'I';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }
            //POSITION 1 5
            if(c==1 && x>=550 && x<=600 && y >=100 && y<=150)
            {
                oti = oti + 1 ;
                out_string[oti] = 'T';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            /*2*/


            /*POSITION 2 0*/
            if(c==1 && x>=300 && x<=350 && y >=150 && y<=200)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'C';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 2 1*/
            if(c==1 && x>=350 && x<=400 && y >=150 && y<=200)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'O';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 2 2*/
            if(c==1 && x>=400 && x<=450 && y >=150 && y<=200)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'B';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            //POSITION 2 3
            if(c==1 && x>=450 && x<=500 && y >=150 && y<=200)
            {

                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'C';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            //POSITION 2 4
            if(c==1 && x>=500 && x<=550 && y >=150 && y<=200)
            {
                oti = oti + 1 ;
                out_string[oti] = 'L';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }
            //POSITION 2 5
            if(c==1 && x>=550 && x<=600 && y >=150 && y<=200)
            {
                oti = oti + 1 ;
                out_string[oti] = 'A';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }




            /*3*/
            /*POSITION 3 0*/
            if(c==1 && x>=300 && x<=350 && y >=200 && y<=250)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'C';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 3 1*/
            if(c==1 && x>=350 && x<=400 && y >=200 && y<=250)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'T';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 3 2*/
            if(c==1 && x>=400 && x<=450 && y >=200 && y<=250)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'C';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            //POSITION 3 3
            if(c==1 && x>=450 && x<=500 && y >=200 && y<=250)
            {

                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'E';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            //POSITION 3 4
            if(c==1 && x>=500 && x<=550 && y >=200 && y<=250)
            {
                oti = oti + 1 ;
                out_string[oti] = 'P';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }
            //POSITION 3 5
            if(c==1 && x>=550 && x<=600 && y >=200 && y<=250)
            {
                oti = oti + 1 ;
                out_string[oti] = 'G';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            /*4*/

            // POSITION 4 0
            if(c==1 && x>=300 && x<=350 && y >=250 && y<=300)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'B';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 4 1*/
            if(c==1 && x>=350 && x<=400 && y >=250 && y<=300)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'C';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 4 2*/
            if(c==1 && x>=400 && x<=450 && y >=250 && y<=300)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'B';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            //POSITION 4 3
            if(c==1 && x>=450 && x<=500 && y >=250 && y<=300)
            {

                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'A';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            //POSITION 4 4
            if(c==1 && x>=500 && x<=550 && y >=250 && y<=300)
            {
                oti = oti + 1 ;
                out_string[oti] = 'I';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }
            //POSITION 4 5
            if(c==1 && x>=550 && x<=600 && y >=250 && y<=300)
            {
                oti = oti + 1 ;
                out_string[oti] = 'M';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }





            /*5*/

            // POSITIO 5 0
            if(c==1 && x>=300 && x<=350 && y >=300 && y<=350)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'D';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 5 1*/
            if(c==1 && x>=350 && x<=400 && y >=300 && y<=350)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'W';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 5 2*/
            if(c==1 && x>=400 && x<=450 &&  y >=300 && y<=350)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'X';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            //POSITION 5 3
            if(c==1 && x>=450 && x<=500 &&  y >=300 && y<=350)
            {

                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'W';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            //POSITION 5 4
            if(c==1 && x>=500 && x<=550 &&  y >=300 && y<=350)
            {
                oti = oti + 1 ;
                out_string[oti] = 'P';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }
            //POSITION 5 5
            if(c==1 && x>=550 && x<=600 &&  y >=300 && y<=350)
            {
                oti = oti + 1 ;
                out_string[oti] = 'L';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }
            // admin next level pass
			if(kbhit()){
				char ch = getch();
				if(ch=='N'){
					return 1 ;
				}
			}

        }






}
    clrscr();
    cleardevice();
    printf("Exiting....");
    delay(300);
    return 0 ;
}

/* LEVEL 5 */

// levelFour
int LevelFour()
{

    int gd = DETECT , gm ;
    int x , y , c ;
    int out = 0 ;
    //float score = 0 ;
    int exit_level = 0 ;
    int match_finder = 0 ;
    int hint_x_cordinate = 0 ;
	missHit = 0 ;
    initgraph(&gd,&gm,"c:/tc/bgi");
    /*boolian section*/

    //int rice = 1 , bean = 1 , corn = 1 , cack = 1 , plam = 1 , meat = 1 ;
    //int cap = 1 , tie = 1 , coat = 1 , wig = 1 , belt = 1 ;
    int no = 1 , cat = 1 , pot = 1 ,man = 1 , pen = 1 , all = 1 , ton = 1 , aim = 1 , null = 1 , byte = 1 , gap = 1 , top = 1 ;
    /*boolean array */
    // 0 is false
    // 1 is true
    int show[12] = {1,0,0,0,0,0,0,0,0,0,0,0} ;
    /*file initialization */
    FILE *fp ;
    /*THE ROWS ARE COLUMN AND THE COLUMNS ARE ROWS IN THE BELOW MATRIX */

    /*  char* ara[100] =
      {

          "D" , "B" , "A" , "T" ,

          "C" , "O" , "W"  , "N" ,

          "D" , "O" , "G" , "A" ,

          "H" , "P" , "X" , "U"

      } ;
     */
    char* ara[100] =
    {

        "N" , "S" , "Z" , "A" , "T" , "B"  ,

        "U" , "T" , "I"  ,"O" , "L" , "Y" ,

        "L" , "M" , "C" , "L" , "P" , "T" ,

        "L" , "N" , "A" , "A" , "O" , "E" ,

        "P" , "E" , "N" , "N" , "T" , "N" ,

        "G" , "P" , "G" , "A" , "P" , "K"

    } ;

    char out_string[100] ;
    out_string[0] = '\0';
    int oti = -1 ; /*out put string dincrement */

    /*LEVEL LOOP*/
    while(out==0)
    {

        /*output string in the buttom */
        setcolor(GREEN);
        // outtextxy(55,340,out_string);
        setbkcolor(8);
        clrscr();
        cleardevice();
        cm();
        /*level number*/
        outtextxy(20,20,"Random Stuff ");
        /*score */


        /* USER INTERFACE */
        /*  GRAPHICAL PART */

        //BUTTON LAYOUT
        for(int i = 300 , k = 0 ; i<650 ; i+=50)
        {

            for(int j =50 ; j<=350 ; j+=50/*(j<200)? k++ : k*/)
            {
                // if(i<300 & j<300)k++;
                if(i<=550 && j<=300)  outtextxy(i+20,j+20,ara[k++])  ;
                //  rectangle(i,j,j,i);
                if(i<=550 && j<=300 ) circle(i+22,j+22,20);
            }

        }

        /*EXIT BUTTON*/
        setfillstyle(SOLID_FILL,RED);
        bar(600,0,650,30);
        outtextxy(600,10," EXIT");


        /*SUBMIT BUTTON*/
        setfillstyle(SOLID_FILL,BLUE);
        bar(355,400,403,430);
        outtextxy(356,380,out_string);
        outtextxy(356,390,"______________________");
        outtextxy(356,410,"SUBMIT");

        /*SCORE WEIGIT*/


        /*   setfillstyle(SOLID_FILL,BLUE);
         bar(320,50,390,80);
         outtextxy(322,60,"Score : ");   */
        gotoxy(25,0);
        printf("-%30s = %-.2f ","score",score);


        /*BACK_BUTTON*/
        setfillstyle(SOLID_FILL,RED);
        bar(410,400,450,430);
        outtextxy(413,410 ,"<--");

        /*
                //HINT SECTION


                if(cow!=0)   outtextxy(10,50,"* Gives us milk ");
                if(bat!=0)   outtextxy(10,60,"* mammal that can fly ")  ;
                if(cat!=0)   outtextxy(10,80,"* Tigers Aunt  ");
                if(rat!=0)   outtextxy(10,70,"* Cats Enemy ");
                if(hen!=0)   outtextxy(10,90,"* Lays egg ");

                if(ant!=0)
                {
                    outtextxy(10,100,"* Works in group  ");
                    outtextxy(10,110 ," and can lift ten times it weight ") ;
                }
                if(dog!=0)  outtextxy(10,120,"* Mans best friend  ");

                if(cow == 0 && bat == 0 && rat == 0 && cat == 0 && hen ==0 && ant == 0 && dog == 0 ) exit_level = 1 ;

        */

        /*	NEW HINT SECTION */

        if(show[0])
        {
            gotoxy(4,4);
            printf("*Used to give negative responce\n   *not at all \n   *to no extent \n");

        }//outtextxy(10,50,"* NO "); ;
        if(show[1])
        {
            gotoxy(4,4);
            printf("*A small domestic carniovorous\n   *mamal with soft fur\n   *kept as pet for catching mice\n   *loves milk");
        }  //outtextxy(10,50,"* CAT "); ;
        if(show[2])
        {
            gotoxy(4,4);
            printf("*Round or cylindeic container\n   *Used for cooking \n");
        }  //outtextxy(10,50,"* POT  "); ;
        if(show[3])
        {
            gotoxy(4,4);
            printf("*An adult human man\n   *A human being \n");
        }  //outtextxy(10,50,"* MAN "); ;
        if(show[4])
        {
            gotoxy(4,4);
            printf("*An instrument for writing \n   or drawing with ink typically \n   consisting of metal or nib \n");
        }  //outtextxy(10,50,"* PEN  "); ;
        if(show[5])
        {
            gotoxy(4,4);
            printf("*Used to refer whole quantity \n   *Compleatly");
        }  //outtextxy(10,50,"* ALL  ");
        if(show[6])
        {
            gotoxy(4,4);
            printf("*A large number of quantity \n   *1000 kg\n");
        }  //outtextxy(10,50,"* TON ");
        if(show[7])
        {
            gotoxy(4,4);
            printf("*Point or direct at a target\n");
        }  //outtextxy(10,50,"* AIM  ");
        if(show[8])
        {
            gotoxy(4,4);
            printf("*A zero nothing\n");
        } //outtextxy(10,50,"* NULL  ");
        if(show[9])
        {
            gotoxy(4,4);
            printf("*Unit of memory size\n");
        } // outtextxy(10,50,"* BYTE  ");
        if(show[10])
        {
            gotoxy(4,4);
            printf("*A space or interval\n");
        } // outtextxy(10,50,"* GAP ");
        if(show[11])
        {
            gotoxy(4,4);
            printf("*Heigh in position at the most \n");
        }//  outtextxy(10,50,"* TOP  ");




        if(exit_level==1)
        {
            cleardevice();
            clrscr();
            return 1 ;
        }
        /*BACKGROUNG_ACTIVITY_AND_ACTION_LISTENER*/


        while(1)
        {
            cm();
            mp(x,y,c);

               // admin next level pass
			if(kbhit()){
				char ch = getch();
				if(ch=='N'){
					return 1 ;
				}
			}
            //back button interface
            if(c==1 && x>=410 && x<=450 && y>=400 && y<=430 && oti>=0 )
            {
                sound(200);
                delay(20);
                nosound();
                out_string[oti] = '\0';
                oti =  oti - 1 ;
                delay(DELAY_TIME);
                break ;
            }

            /* SUBMIT BUTTON */
            // submit button inter face
            // this is also the database every meaningfull word has a identical
            // boolina identifier wich`s value is altered if the right word is entered and then
            // the submit button is clicked
            if(c==1 && x>=355 && x<=403 && y>=400 && y<=430 )
            {
                sound(300);
                delay(20);
                nosound();
                /*data_base*/

                 //no
                if(strcmp(out_string,"NO")==0 && no && show[0])
                {
                    score = score + 1.25 ;
                    no = 0 ;
                    show[1] = 1 ;
                    show[0] = 0 ;
                }
                //cat
                else if(strcmp(out_string,"CAT")==0 && cat && show[1])
                {
                    score = score + 1.25 ;
                    cat = 0 ;
                    show[2] = 1 ;
                    show[1] = 0 ;
                }
                //pot
                if(strcmp(out_string,"POT")==0 && pot && show[2])
                {
                    score = score + 1 ;
                    pot = 0 ;
                    show[3] = 1 ;
                    show[2] = 0 ;
                }
                //man
                else if(strcmp(out_string,"MAN")==0 && man && show[3])
                {
                    score = score + 1 ;
                    man = 0 ;
                    show[4] = 1 ;
                    show[3] = 0 ;
                }

                //pen
                else if(strcmp(out_string,"PEN")==0 && pen && show[4])
                {
                    score = score + 1 ;
                    pen = 0 ;
                    show[5] = 1 ;
                    show[4] = 0 ;

                }
                //all
                else if(strcmp(out_string,"ALL")==0 && all && show[5])
                {
                    score = score + 1 ;
                    all = 0 ;
                    show[6] = 1 ;
                    show[5] = 0 ;

                }
                //ton
                else if(strcmp(out_string,"TON")==0 && ton && show[6])
                {
                    score = score + 1 ;
                    ton = 0 ;
                    show[7] = 1 ;
                    show[6] = 0 ;

                }
                //aim
                else if(strcmp(out_string,"AIM")==0 && aim && show[7])
                {
                    score = score + 1 ;
                    aim  = 0 ;
                    show[8] = 1 ;
                    show[7] = 0 ;

                }
                //null
                else if(strcmp(out_string,"NULL")==0 && null && show[8])
                {
                    score = score + 1 ;
                    null = 0 ;
                    show[9] = 1 ;
                    show[8] = 0 ;

                }
                //byte
                else if(strcmp(out_string,"BYTE")==0 && byte && show[9])
                {
                    score = score + 1 ;
                    byte = 0 ;
                    show[10] = 1 ;
                    show[9] = 0 ;

                }
                   //gap
                else if(strcmp(out_string,"GAP")==0 && gap && show[10])
                {
                    score = score + 1 ;
                    gap = 0 ;
                    show[11] = 1 ;
                    show[10] = 0 ;

                }
                   //top
                else if(strcmp(out_string,"TOP")==0 && top && show[11])
                {
                    score = score + 1 ;
                    top = 0 ;

                    show[11] = 0 ;
                    return 1 ;

                }


                // if wrong answer if given

                else if(out_string[0]!='\0'){ // wont be counted as a submisson if the string is empty
                    score = score - 0.25 ;
                    missHit++ ;
                    if(missHit>=3)
                    {
                      missHit = 0 ;
                      return 0 ;
                    }
				}
				//formatting the input section for new input
                delay(DELAY_TIME);
                match_finder = -1 ;
                out_string[0] = '\0';
                oti = - 1 ;
                break ;

            }






        // this is the exit sign on the top-right side

        if(c==1 && x>=600 && x<=650 && y>=0 && y<=50)
        {
            sound(500);
            delay(30);
            nosound();
            out = -1 ;
            break ;
        }

        /*0*/
        /* POSITIO 0 0*/
        if(c==1 && x >=300 && x<=350 && y>=50 && y<=100 )
        {
            sound(600);
            delay(20);
            nosound();
            oti = oti + 1 ;
            out_string[oti] = 'N';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }

        /*POSITION 0 1*/
        if(c==1 && x>=350 && x<=400 && y >=50 && y<=100)
        {
            sound(600);
            delay(20);
            nosound();
            oti = oti + 1 ;
            out_string[oti] = 'U';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }

        /*POSITION 0 2*/
        if(c==1 && x>=400 && x<=450 && y >=50 && y<=100)
        {
            sound(600);
            delay(20);
            nosound();
            oti = oti + 1 ;
            out_string[oti] = 'L';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }

        //POSITION 0 3
        if(c==1 && x>=450 && x<=500 && y >=50 && y<=100)
        {

            sound(600);
            delay(20);
            nosound();
            oti = oti + 1 ;
            out_string[oti] = 'L';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }


        //POSITION 0 4
        if(c==1 && x>=500 && x<=550 && y >=50 && y<=100)
        {
            oti = oti + 1 ;
            out_string[oti] = 'P';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }
        //POSITION 0 5
        if(c==1 && x>=550 && x<=600 && y >=50 && y<=100)
        {
            oti = oti + 1 ;
            out_string[oti] = 'G';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }


        /*1*/
        /* POSITIO 1 0*/
        if(c==1 && x >=300 && x<=350 && y>=100 && y<=150 )
        {
            sound(600);
            delay(20);
            nosound();
            oti = oti + 1 ;
            out_string[oti] = 'S';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }

        /*POSITION 1 1*/
        if(c==1 && x>=350 && x<=400 && y >=100 && y<=150)
        {
            sound(600);
            delay(20);
            nosound();
            oti = oti + 1 ;
            out_string[oti] = 'T';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }

        /*POSITION 1 2*/
        if(c==1 && x>=400 && x<=450 && y >=100 && y<=150)
        {
            sound(600);
            delay(20);
            nosound();
            oti = oti + 1 ;
            out_string[oti] = 'M';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }

        //POSITION 1 3
        if(c==1 && x>=450 && x<=500 && y >=100 && y<=150)
        {

            sound(600);
            delay(20);
            nosound();
            oti = oti + 1 ;
            out_string[oti] = 'N';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }


        //POSITION 1 4
        if(c==1 && x>=500 && x<=550 && y >=100 && y<=150)
        {
            oti = oti + 1 ;
            out_string[oti] = 'E';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }
        //POSITION 1 5
        if(c==1 && x>=550 && x<=600 && y >=100 && y<=150)
        {
            oti = oti + 1 ;
            out_string[oti] = 'P';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }


        /*2*/


        /*POSITION 2 0*/
        if(c==1 && x>=300 && x<=350 && y >=150 && y<=200)
        {
            sound(600);
            delay(20);
            nosound();
            oti = oti + 1 ;
            out_string[oti] = 'Z';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }

        /*POSITION 2 1*/
        if(c==1 && x>=350 && x<=400 && y >=150 && y<=200)
        {
            sound(600);
            delay(20);
            nosound();
            oti = oti + 1 ;
            out_string[oti] = 'I';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }

        /*POSITION 2 2*/
        if(c==1 && x>=400 && x<=450 && y >=150 && y<=200)
        {
            sound(600);
            delay(20);
            nosound();
            oti = oti + 1 ;
            out_string[oti] = 'C';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }

        //POSITION 2 3
        if(c==1 && x>=450 && x<=500 && y >=150 && y<=200)
        {

            sound(600);
            delay(20);
            nosound();
            oti = oti + 1 ;
            out_string[oti] = 'A';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }


        //POSITION 2 4
        if(c==1 && x>=500 && x<=550 && y >=150 && y<=200)
        {
            oti = oti + 1 ;
            out_string[oti] = 'N';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }
        //POSITION 2 5
        if(c==1 && x>=550 && x<=600 && y >=150 && y<=200)
        {
            oti = oti + 1 ;
            out_string[oti] = 'G';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }




        /*3*/
        /*POSITION 3 0*/
        if(c==1 && x>=300 && x<=350 && y >=200 && y<=250)
        {
            sound(600);
            delay(20);
            nosound();
            oti = oti + 1 ;
            out_string[oti] = 'A';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }

        /*POSITION 3 1*/
        if(c==1 && x>=350 && x<=400 && y >=200 && y<=250)
        {
            sound(600);
            delay(20);
            nosound();
            oti = oti + 1 ;
            out_string[oti] = 'O';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }

        /*POSITION 3 2*/
        if(c==1 && x>=400 && x<=450 && y >=200 && y<=250)
        {
            sound(600);
            delay(20);
            nosound();
            oti = oti + 1 ;
            out_string[oti] = 'L';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }

        //POSITION 3 3
        if(c==1 && x>=450 && x<=500 && y >=200 && y<=250)
        {

            sound(600);
            delay(20);
            nosound();
            oti = oti + 1 ;
            out_string[oti] = 'A';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }


        //POSITION 3 4
        if(c==1 && x>=500 && x<=550 && y >=200 && y<=250)
        {
            oti = oti + 1 ;
            out_string[oti] = 'N';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }
        //POSITION 3 5
        if(c==1 && x>=550 && x<=600 && y >=200 && y<=250)
        {
            oti = oti + 1 ;
            out_string[oti] = 'A';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }


        /*4*/

        // POSITION 4 0
        if(c==1 && x>=300 && x<=350 && y >=250 && y<=300)
        {
            sound(600);
            delay(20);
            nosound();
            oti = oti + 1 ;
            out_string[oti] = 'T';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }

        /*POSITION 4 1*/
        if(c==1 && x>=350 && x<=400 && y >=250 && y<=300)
        {
            sound(600);
            delay(20);
            nosound();
            oti = oti + 1 ;
            out_string[oti] = 'L';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }

        /*POSITION 4 2*/
        if(c==1 && x>=400 && x<=450 && y >=250 && y<=300)
        {
            sound(600);
            delay(20);
            nosound();
            oti = oti + 1 ;
            out_string[oti] = 'P';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }

        //POSITION 4 3
        if(c==1 && x>=450 && x<=500 && y >=250 && y<=300)
        {

            sound(600);
            delay(20);
            nosound();
            oti = oti + 1 ;
            out_string[oti] = 'O';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }


        //POSITION 4 4
        if(c==1 && x>=500 && x<=550 && y >=250 && y<=300)
        {
            oti = oti + 1 ;
            out_string[oti] = 'T';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }
        //POSITION 4 5
        if(c==1 && x>=550 && x<=600 && y >=250 && y<=300)
        {
            oti = oti + 1 ;
            out_string[oti] = 'P';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }





        /*5*/

        // POSITIO 5 0
        if(c==1 && x>=300 && x<=350 && y >=300 && y<=350)
        {
            sound(600);
            delay(20);
            nosound();
            oti = oti + 1 ;
            out_string[oti] = 'B';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }

        /*POSITION 5 1*/
        if(c==1 && x>=350 && x<=400 && y >=300 && y<=350)
        {
            sound(600);
            delay(20);
            nosound();
            oti = oti + 1 ;
            out_string[oti] = 'Y';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }

        /*POSITION 5 2*/
        if(c==1 && x>=400 && x<=450 &&  y >=300 && y<=350)
        {
            sound(600);
            delay(20);
            nosound();
            oti = oti + 1 ;
            out_string[oti] = 'T';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }

        //POSITION 5 3
        if(c==1 && x>=450 && x<=500 &&  y >=300 && y<=350)
        {

            sound(600);
            delay(20);
            nosound();
            oti = oti + 1 ;
            out_string[oti] = 'E';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }


        //POSITION 5 4
        if(c==1 && x>=500 && x<=550 &&  y >=300 && y<=350)
        {
            oti = oti + 1 ;
            out_string[oti] = 'N';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }
        //POSITION 5 5
        if(c==1 && x>=550 && x<=600 &&  y >=300 && y<=350)
        {
            oti = oti + 1 ;
            out_string[oti] = 'K';
            out_string[oti+1] = '\0';
            delay(DELAY_TIME);
            break ;
        }

	}



    }





    clrscr();
    cleardevice();
    printf("Exiting....");
    delay(300);
     return 0 ;
 }



/* LEVEL 6 */

// levelFive
int LevelFive()
{

    int gd = DETECT , gm ;
    int x , y , c ;
    int out = 0 ;
    //float score = 0 ;
    int exit_level = 0 ;
    int match_finder = 0 ;
    int hint_x_cordinate = 0 ;
	missHit = 0 ;
    initgraph(&gd,&gm,"c:/tc/bgi");
    /*boolian section*/

    //int rice = 1 , bean = 1 , corn = 1 , cack = 1 , plam = 1 , meat = 1 ;
    //int cap = 1 , tie = 1 , coat = 1 , wig = 1 , belt = 1 ;
    int ram = 1 , bus = 1 , web = 1 , bit = 1 , bug = 1 , data = 1 ;
    /*boolean array */
    // 0 is false
    // 1 is true
    int show[6] = {1,0,0,0,0,0} ;
    /*file initialization */
    FILE *fp ;
    /*THE ROWS ARE COLUMN AND THE COLUMNS ARE ROWS IN THE BELOW MATRIX */

    /*  char* ara[100] =
      {

          "D" , "B" , "A" , "T" ,

          "C" , "O" , "W"  , "N" ,

          "D" , "O" , "G" , "A" ,

          "H" , "P" , "X" , "U"

      } ;
     */
    char* ara[100] =
    {

        "P" , "A" , "N" , "R" , "M" , "T"  ,

        "O" , "T" , "I"  ,"B" , "A" , "Y" ,

        "W" , "H" , "S" , "U" , "B" , "M" ,

        "E" , "O" , "A" , "G" , "K" , "T" ,

        "B" , "P" , "C" , "N" , "H" , "Z" ,

        "L" , "D" , "A" , "T" , "A" , "U"

    } ;

    char out_string[100] ;
    out_string[0] = '\0';
    int oti = -1 ; /*out put string dincrement */

    /*LEVEL LOOP*/
    while(out==0)
    {

        /*output string in the buttom */
        setcolor(GREEN);
        // outtextxy(55,340,out_string);
        setbkcolor(8);
        clrscr();
        cleardevice();
        cm();
        /*level number*/
        outtextxy(20,20,"Random Stuff ");
        /*score */


        /* USER INTERFACE */
        /*  GRAPHICAL PART */

        //BUTTON LAYOUT
        for(int i = 300 , k = 0 ; i<650 ; i+=50)
        {

            for(int j =50 ; j<=350 ; j+=50/*(j<200)? k++ : k*/)
            {
                // if(i<300 & j<300)k++;
                if(i<=550 && j<=300)  outtextxy(i+20,j+20,ara[k++])  ;
                //  rectangle(i,j,j,i);
                if(i<=550 && j<=300 ) circle(i+22,j+22,20);
            }

        }

        /*EXIT BUTTON*/
        setfillstyle(SOLID_FILL,RED);
        bar(600,0,650,30);
        outtextxy(600,10," EXIT");


        /*SUBMIT BUTTON*/
        setfillstyle(SOLID_FILL,BLUE);
        bar(355,400,403,430);
        outtextxy(356,380,out_string);
        outtextxy(356,390,"______________________");
        outtextxy(356,410,"SUBMIT");

        /*SCORE WEIGIT*/


        /*   setfillstyle(SOLID_FILL,BLUE);
         bar(320,50,390,80);
         outtextxy(322,60,"Score : ");   */
        gotoxy(25,0);
        printf("-%30s = %-.2f ","score",score);


        /*BACK_BUTTON*/
        setfillstyle(SOLID_FILL,RED);
        bar(410,400,450,430);
        outtextxy(413,410 ,"<--");

        /*
                //HINT SECTION


                if(cow!=0)   outtextxy(10,50,"* Gives us milk ");
                if(bat!=0)   outtextxy(10,60,"* mammal that can fly ")  ;
                if(cat!=0)   outtextxy(10,80,"* Tigers Aunt  ");
                if(rat!=0)   outtextxy(10,70,"* Cats Enemy ");
                if(hen!=0)   outtextxy(10,90,"* Lays egg ");

                if(ant!=0)
                {
                    outtextxy(10,100,"* Works in group  ");
                    outtextxy(10,110 ," and can lift ten times it weight ") ;
                }
                if(dog!=0)  outtextxy(10,120,"* Mans best friend  ");

                if(cow == 0 && bat == 0 && rat == 0 && cat == 0 && hen ==0 && ant == 0 && dog == 0 ) exit_level = 1 ;

        */

        /*	NEW HINT SECTION */

        if(show[0])
        {
            gotoxy(4,4);
            printf("*Random acess memory \n");
        } //outtextxy(10,50,"* used to give negative responce \n not at all to no extent "); ;
        if(show[1])
        {
            gotoxy(4,4);
            printf("*Conncts the componenets of computer \n");

        }// outtextxy(10,50,"* bus "); ;
        if(show[2])
        {
            gotoxy(4,4);
            printf("*World Wide Web \n   *Internet\n");
        } //outtextxy(10,50,"* web  "); ;
        if(show[3])
        {
            gotoxy(4,4);
            printf("*Short of binary digit\n   has a singla binary value\n");
        } //outtextxy(10,50,"* bit "); ;
        if(show[4])
        {
            gotoxy(4,4);
            printf("*A fault or failuer in computer\n   programm");
        }//outtextxy(10,50,"* bug  "); ;
        if(show[5])
        {
            gotoxy(4,4);
            printf("*Digital Information ");
        }//outtextxy(10,50,"* data  "); ;


        /* NEW HINT SECTION END */


        if(exit_level==1)
        {
            cleardevice();
            clrscr();
            return 1 ;
        }
        /*BACKGROUNG_ACTIVITY_AND_ACTION_LISTENER*/


        while(1)
        {
            cm();
            mp(x,y,c);
              // admin next level pass
			if(kbhit()){
				char ch = getch();
				if(ch=='N'){
					return 1 ;
				}
			}

            //back button interface
            if(c==1 && x>=410 && x<=450 && y>=400 && y<=430 && oti>=0 )
            {
                sound(200);
                delay(20);
                nosound();
                out_string[oti] = '\0';
                oti =  oti - 1 ;
                delay(DELAY_TIME);
                break ;
            }

            /* SUBMIT BUTTON */
            // submit button inter face
            // this is also the database every meaningfull word has a identical
            // boolina identifier wich`s value is altered if the right word is entered and then
            // the submit button is clicked
            if(c==1 && x>=355 && x<=403 && y>=400 && y<=430 )
            {
                sound(300);
                delay(20);
                nosound();
                /*data_base*/

                //ram
                if(strcmp(out_string,"RAM")==0 && ram && show[0])
                {
                    score = score + 1.25 ;
                    ram = 0 ;
                    show[1] = 1 ;
                    show[0] = 0 ;
                }
                //bus
                else if(strcmp(out_string,"BUS")==0 && bus && show[1])
                {
                    score = score + 1.25 ;
                    bus = 0 ;
                    show[2] = 1 ;
                    show[1] = 0 ;
                }
                //web
                if(strcmp(out_string,"WEB")==0 && web && show[2])
                {
                    score = score + 1 ;
                    web = 0 ;
                    show[3] = 1 ;
                    show[2] = 0 ;
                }
                //bit
                else if(strcmp(out_string,"BIT")==0 && bit && show[3])
                {
                    score = score + 1 ;
                    bit = 0 ;
                    show[4] = 1 ;
                    show[3] = 0 ;
                }

                //bug
                else if(strcmp(out_string,"BUG")==0 && bug && show[4])
                {
                    score = score + 1 ;
                    bug = 0 ;
                    show[5] = 1 ;
                    show[4] = 0 ;

                }
                //data
                else if(strcmp(out_string,"DATA")==0 && data && show[5])
                {
                    score = score + 1 ;
                    data = 0 ;
                    show[5] = 0 ;
                    return 1 ;

                }



                // if wrong answer if given

                else if(out_string[0]!='\0')  // wont be counted as a submisson if the string is empty
                {
                    score = score - 0.25 ;
                    missHit++;
                    if(missHit>=3)
                    {
                        missHit = 0;
                        return 0 ;
                    }

                }



                //formatting the input section for new input
                delay(DELAY_TIME);

                out_string[0] = '\0';
                oti = - 1 ;
                break ;
            }


            // this is the exit sign on the top-right side

            if(c==1 && x>=600 && x<=650 && y>=0 && y<=50)
            {
                sound(500);
                delay(30);
                nosound();
                out = -1 ;
                break ;
            }

            /*0*/
            /* POSITIO 0 0*/
            if(c==1 && x >=300 && x<=350 && y>=50 && y<=100 )
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'P';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 0 1*/
            if(c==1 && x>=350 && x<=400 && y >=50 && y<=100)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'O';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 0 2*/
            if(c==1 && x>=400 && x<=450 && y >=50 && y<=100)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'W';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            //POSITION 0 3
            if(c==1 && x>=450 && x<=500 && y >=50 && y<=100)
            {

                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'E';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            //POSITION 0 4
            if(c==1 && x>=500 && x<=550 && y >=50 && y<=100)
            {
                oti = oti + 1 ;
                out_string[oti] = 'B';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }
            //POSITION 0 5
            if(c==1 && x>=550 && x<=600 && y >=50 && y<=100)
            {
                oti = oti + 1 ;
                out_string[oti] = 'L';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            /*1*/
            /* POSITIO 1 0*/
            if(c==1 && x >=300 && x<=350 && y>=100 && y<=150 )
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'A';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 1 1*/
            if(c==1 && x>=350 && x<=400 && y >=100 && y<=150)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'T';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 1 2*/
            if(c==1 && x>=400 && x<=450 && y >=100 && y<=150)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'H';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            //POSITION 1 3
            if(c==1 && x>=450 && x<=500 && y >=100 && y<=150)
            {

                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'O';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            //POSITION 1 4
            if(c==1 && x>=500 && x<=550 && y >=100 && y<=150)
            {
                oti = oti + 1 ;
                out_string[oti] = 'P';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }
            //POSITION 1 5
            if(c==1 && x>=550 && x<=600 && y >=100 && y<=150)
            {
                oti = oti + 1 ;
                out_string[oti] = 'D';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            /*2*/


            /*POSITION 2 0*/
            if(c==1 && x>=300 && x<=350 && y >=150 && y<=200)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'N';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 2 1*/
            if(c==1 && x>=350 && x<=400 && y >=150 && y<=200)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'I';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 2 2*/
            if(c==1 && x>=400 && x<=450 && y >=150 && y<=200)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'S';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            //POSITION 2 3
            if(c==1 && x>=450 && x<=500 && y >=150 && y<=200)
            {

                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'A';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            //POSITION 2 4
            if(c==1 && x>=500 && x<=550 && y >=150 && y<=200)
            {
                oti = oti + 1 ;
                out_string[oti] = 'C';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }
            //POSITION 2 5
            if(c==1 && x>=550 && x<=600 && y >=150 && y<=200)
            {
                oti = oti + 1 ;
                out_string[oti] = 'A';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }




            /*3*/
            /*POSITION 3 0*/
            if(c==1 && x>=300 && x<=350 && y >=200 && y<=250)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'R';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 3 1*/
            if(c==1 && x>=350 && x<=400 && y >=200 && y<=250)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'B';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 3 2*/
            if(c==1 && x>=400 && x<=450 && y >=200 && y<=250)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'U';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            //POSITION 3 3
            if(c==1 && x>=450 && x<=500 && y >=200 && y<=250)
            {

                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'G';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            //POSITION 3 4
            if(c==1 && x>=500 && x<=550 && y >=200 && y<=250)
            {
                oti = oti + 1 ;
                out_string[oti] = 'N';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }
            //POSITION 3 5
            if(c==1 && x>=550 && x<=600 && y >=200 && y<=250)
            {
                oti = oti + 1 ;
                out_string[oti] = 'T';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            /*4*/

            // POSITION 4 0
            if(c==1 && x>=300 && x<=350 && y >=250 && y<=300)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'M';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 4 1*/
            if(c==1 && x>=350 && x<=400 && y >=250 && y<=300)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'A';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 4 2*/
            if(c==1 && x>=400 && x<=450 && y >=250 && y<=300)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'B';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            //POSITION 4 3
            if(c==1 && x>=450 && x<=500 && y >=250 && y<=300)
            {

                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'K';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            //POSITION 4 4
            if(c==1 && x>=500 && x<=550 && y >=250 && y<=300)
            {
                oti = oti + 1 ;
                out_string[oti] = 'H';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }
            //POSITION 4 5
            if(c==1 && x>=550 && x<=600 && y >=250 && y<=300)
            {
                oti = oti + 1 ;
                out_string[oti] = 'A';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }





            /*5*/

            // POSITIO 5 0
            if(c==1 && x>=300 && x<=350 && y >=300 && y<=350)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'T';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 5 1*/
            if(c==1 && x>=350 && x<=400 && y >=300 && y<=350)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'Y';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            /*POSITION 5 2*/
            if(c==1 && x>=400 && x<=450 &&  y >=300 && y<=350)
            {
                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'M';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }

            //POSITION 5 3
            if(c==1 && x>=450 && x<=500 &&  y >=300 && y<=350)
            {

                sound(600);
                delay(20);
                nosound();
                oti = oti + 1 ;
                out_string[oti] = 'T';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }


            //POSITION 5 4
            if(c==1 && x>=500 && x<=550 &&  y >=300 && y<=350)
            {
                oti = oti + 1 ;
                out_string[oti] = 'Z';
		out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }
            //POSITION 5 5
            if(c==1 && x>=550 && x<=600 &&  y >=300 && y<=350)
            {
                oti = oti + 1 ;
                out_string[oti] = 'U';
                out_string[oti+1] = '\0';
                delay(DELAY_TIME);
                break ;
            }



        }




    }
    clrscr();
    cleardevice();
    printf("Exiting....");
    delay(300);
    return 0 ;
}
int WordGame()
{


    //@have to give a welcome sign or choice prompt before starting

    if(LevelOne()==1)                           // one
    {
	cleardevice();
	gotoxy(20,25);
	printf("Level2");
	getch();
	delay(500);
	if(LevelTwo()==1)                       // two
	{
	    cleardevice();
	    printf("Level3");
	    getch();
	    delay(500);
	    if(LevelThree()==1)                // three
	    {
		cleardevice();
		printf("Level4");
		getch();
		delay(500);
		if(LevelFour()==1)             // four
		{
		    cleardevice();
		    printf("Level5");
		    getch();
		    delay(500);
		    if(LevelFive()==1)        // five
		    {
			cleardevice();
			printf("YOU HAVE WON THE GAME :D Congtats");
			getch();
			delay(500);
		    }
		    else
		    {
			cleardevice();
			printf("Game Over \n");
			getch();
		    }
		}
		else
		{
		    cleardevice();
		    printf("Game Over \n");
		    getch();

		}
	    }
	    else
	    {
		cleardevice();
		printf("Game Over \n");
		getch();

	    }

	}
	else
	{

	    cleardevice();
	    printf("Game Over \n");
	    getch();
	}

    }
    else
    {

	cleardevice();
	printf("Game Over \n");
	getch();
    }

    return 1;

}

void hm(){

	i.x.ax = 2 ;
	int86(0x33,&i,&o);
}
void cm()
{
    i.x.ax = 1 ;
    int86(0x33,&i,&o);
}
void mp(int &x ,int &y ,int &c )
{
    i.x.ax = 3 ;
    int86(0x33,&i,&o);

    c = o.x.bx ;
    x = o.x.cx ;
    y = o.x.dx ;
}
