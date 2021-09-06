/*************************THE GRAPHING INTELLIGENCE**************************/
/********************************     by     ********************************/
/******************************VASUDEV VIDYARTHI*****************************/

//*****HEADER FILES USED*****//

#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<iostream.h>
#include<process.h>

//*****FUNCTIONS USED*****//

void welcome();
void menu();
void linear();
void quadratic();
void cubic();
void input_function();
void graph_scale();
void graph();
void gety(int);
void plot_scale();
void plot();
void close();
void retry();

long y;int x;
int a,b,c,d;
int xs,ys,gscale;
float pxs,pys;
int ch;

void main()
{
 clrscr();

 int gdriver=DETECT;
 int gmode;
 initgraph(&gdriver,&gmode,"c:\\tc\\bgi");    //Initialising graph mode

 welcome();
 menu();
 input_function();
 graph_scale();
 plot_scale();
 graph();
 plot();
 close();

 closegraph();
 restorecrtmode();
}

void welcome()
{
 for(int i=1,j=0,k=0;i<300;i++)
 {
  if(i%100==0)
  {
   j++;
   if(j%2!=0&&j!=1)
     k+=200;
  }

  setcolor(RED);
  settextstyle(1,0,5);
  outtextxy(25,70,"THE GRAPHING INTELLIGENCE");

  if(i>(100+k)&&i<(200+k))
   setcolor(GREEN);
  else
   setcolor(BLACK);

  settextstyle(4,0,4);
  outtextxy(300,190,"BY");
  settextstyle(1,0,5);
  outtextxy(120,280,"VASUDEV VIDYARTHI");
  line(110,340,540,340);
  line(150,350,500,350);

  if(i>(100+k)&&i<=(200+k))
   setcolor(BLACK);
  else
   setcolor(CYAN);

  settextstyle(4,0,8);
  outtextxy(100,120,"WELCOMES");

  if(i>(100+k)&&i<(200+k))
   setcolor(BLACK);
  else
   setcolor(RED);

  settextstyle(1,0,8);
  outtextxy(240,210,"YOU");
 }
 clrscr();
}

void menu()
{
 settextstyle(4,0,6);
 setcolor(CYAN);
 outtextxy(30,70,"What Would You Graph ?");

 settextstyle(7,0,3);
 setcolor(RED);
 outtextxy(80,200,"1. Linear Function");
 outtextxy(80,250,"2. Quadratic Function");
 outtextxy(80,300,"3. Cubic Function");
 outtextxy(80,350,"4. Exit");

 gotoxy(11,25);
 cin>>ch;

 clrscr();
}

void linear(int x)                         //Linear function
{
 y=a*(x)+b;
}

void quadratic(int x)                      //Quadratic function
{
 y=a*(x*x)+b*(x)+c;
}

void cubic(int x)                          //Cubic function
{
 y=a*(x*x*x)+b*(x*x)+c*(x)+d;
}

void input_function()
{
 if(ch>0&&ch<4)
 {
  setcolor(2);
  settextstyle(10,0,3);
  outtextxy(50,50,"Enter the coeffecients:");
 }

 gotoxy(8,8);

 switch(ch)
 {
  case 1: cout<<endl<<"A: ";
	  cin>>a;
	  cout<<endl<<"B: ";
	  cin>>b;
	  break;

  case 2: cout<<endl<<"A: ";
	  cin>>a;
	  cout<<endl<<"B: ";
	  cin>>b;
	  cout<<endl<<"C: ";
	  cin>>c;
	  break;

  case 3: cout<<endl<<"A: ";
	  cin>>a;
	  cout<<endl<<"B: ";
	  cin>>b;
	  cout<<endl<<"C: ";
	  cin>>c;
	  cout<<endl<<"D: ";
	  cin>>d;
	  break;

  case 4: close();
	  clrscr();
	  exit(0);
	  break;

  default: clrscr();
	   gotoxy(33,8);
	   cout<<"Invalid Input";
	   cout<<endl;
	   gotoxy(31,10);
	   cout<<"Please try again !";
	   getch();
	   clrscr();
	   retry();

 }
 clrscr();
}

void graph_scale()
{
 settextstyle(4,0,6);
 setcolor(RED);
 outtextxy(125,70,"Graphical Window");

 gotoxy(28,10);
 cout<<"Please enter the window:";
 cin>>gscale;

//scale on x-axis
 xs=gscale/8;
//scale on y-axis
 ys=gscale/8;

 clrscr();
}

void graph()
{
 setcolor(BLACK);

//Co-ordinate Axes:
 line(0,getmaxy()/2,getmaxx(),getmaxy()/2);  //x-axis
 line(getmaxx()/2,0,getmaxx()/2,getmaxy());  //y-axis

//Origin
 gotoxy(40,16);
 cout<<"0";

//Graduations
 for(int i=-7,j=5;i<=7;i++,j+=5)        //x-axis
 {
  if(j==40)
  {
   continue;
  }
  else
  {
   gotoxy(j,16);
   cout<<"!";

   int g=i*xs,c=0;

   while(g!=0)
   {
    g/=10;
    c++;
   }
   g=i*xs;

   if(g<0)
   c++;

   gotoxy(j-c/2,17);
   cout<<g;
  }
 }

 for(int k=6,l=1;k>=-4;k-=2,l+=5)       //y-axis
 {
  if(l==16)
  {
   l=15;
  }
  else
  {
   gotoxy(40,l);
   cout<<"-";

   int g=k*ys,c=0;

   while(g!=0)
   {
    g/=10;
    c++;
   }
   g=k*ys;

   if(g<0)
   c++;

   gotoxy(40-c,l);
   cout<<g;
  }
 }
}

void gety(int x)
{
 switch(ch)
 {
  case 1: linear(x);
	  break;

  case 2: quadratic(x);
	  break;

  case 3: cubic(x);
	  break;

  default: cout<<"ERROR";
	   exit(0);
 }
}

void plot_scale()
{
 pxs=40.0/xs;
 pys=36.0/ys;
}

void plot()
{
 int x;
 long t;
 setcolor(CYAN);

 //+ve x-axis

 for(x=0;x<gscale;x++)
 {
  gety(x);
  t=y;
  gety(x+1);

  if(t>6*ys||t<-4*ys)
   continue;

  if(y>=0)            //1st Quadrant
  {
   line(320+x*pxs,240-t*pys,320+x*pxs,240-t*pys);
   line(320+x*pxs,240-t*pys,320+(x+1)*pxs,240-y*pys);
  }

  else if(y<=0)       //4th Quadrant
  {
   line(320+x*pxs,240-t*pys,320+x*pxs,240-t*pys);
   line(320+x*pxs,240-t*pys,320+(x+1)*pxs,240-y*pys);
  }
 }

 //-ve x-axis

 for(x=0;x>-gscale;x--)
 {
  gety(x);
  t=y;
  gety(x-1);

  if(t>6*ys||t<-4*ys)
   continue;

  if(y>=0)            //2nd Quadrant
  {
   line(320+x*pxs,240-t*pys,320+x*pxs,240-t*pys);
   line(320+x*pxs,240-t*pys,320+(x-1)*pxs,240-y*pys);
  }

  else if(y<=0)       //3rd Quadrant
  {
   line(320+x*pxs,240-t*pys,320+x*pxs,240-t*pys);
   line(320+x*pxs,240-t*pys,320+(x-1)*pxs,240-y*pys);
  }
 }

 getch();
 clrscr();
}

void close()
{
 for(int i=169;i>=30;i--)
 {
  delay(100);
  setcolor(i/10);
  arc(getmaxx()/2,160,360-i,180+i,i-10);

  settextstyle(1,0,4);
  outtextxy(215,40,"!! GOOD BYE !!");

  setcolor(GREEN);
  settextstyle(4,0,6);
  outtextxy(160,320,"THANK YOU");
 }
 clrscr();
}

void retry()
{
 menu();
 input_function();
 graph_scale();
 plot_scale();
 graph();
 plot();
 close();

 closegraph();
 restorecrtmode();

 exit(0);
}
