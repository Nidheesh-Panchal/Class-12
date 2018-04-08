#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<graphics.h>
#include<dos.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip.h>
#include<math.h>
#include<process.h>
#include<alloc.h>

union REGS in,out;

int callmouse()
{
 in.x.ax=1;
 int86(51,&in,&out);
 return 1;
}

void mouseposi(int &xpos,int &ypos,int &click)
{
 in.x.ax=3;
 int86(51,&in,&out);
 click=out.x.bx;
 xpos=out.x.cx;
 ypos=out.x.dx;
}

int mousehide()
{
 in.x.ax=2;
 int86(51,&in,&out);
 return 1;
}

void setposi(int &xpos,int &ypos)
{
 in.x.ax=4;
 in.x.cx=xpos;
 in.x.dx=ypos;
 int86(51,&in,&out);
}

void restrictmouseptr(int x1,int y1,int x2,int y2)
{
 in.x.ax=7;
 in.x.cx=x1;
 in.x.dx=x2;
 int86(51,&in,&out);
 in.x.ax=8;
 in.x.cx=y1;
 in.x.dx=y2;
 int86(51,&in,&out);
}

void start()
{
 int x,y,i,j;
 x=getmaxx()/2;
 y=getmaxy()/2;
 setfillstyle(1,0);
 bar(0,0,639,479);
 for(j=0;j<2;j++)
 {
  clrscr();
  bar(0,0,639,479);
  setcolor(3);
  settextstyle(7,0,5);
  outtextxy(220,240,"STARTING");
  for(i=30;i<200;i++)
  {
   delay(10);
   setcolor(i/10);
   arc(x,y,0,180,i-10);
  }
 }
}

void desktop()
{
 clrscr();
 setbkcolor(0);
 setfillstyle(1,0);
 bar(0,0,639,479);
 setfillstyle(1,7);
 bar(0,450,639,479);
 setfillstyle(1,2);
 bar(5,5,55,55);
 setfillstyle(1,2);
 bar(5,65,55,115);
 setfillstyle(1,2);
 bar(5,125,55,175);
 setfillstyle(1,2);
 bar(5,185,55,235);
 setfillstyle(1,WHITE);
 bar(10,10,50,40);
 setcolor(BLACK);
 settextstyle(0,0,1);
 outtextxy(15,15,"BILL");
 settextstyle(2,0,5);
 outtextxy(17,40,"BILL");
 setfillstyle(1,WHITE);
 bar(10,70,50,100);
 setcolor(BLACK);
 settextstyle(0,0,1);
 outtextxy(17,75,"PAY");
 outtextxy(15,85,"SLIP");
 settextstyle(2,0,4);
 outtextxy(7,103,"PAY SLIP");
 line(10,83,50,83);
 setfillstyle(1,RED);
 bar(20,130,40,160);
 setfillstyle(1,BLACK);
 bar(22,132,38,137);
 setfillstyle(1,YELLOW);
 bar(22,142,24,144);
 bar(22,146,24,148);
 bar(22,150,24,152);
 bar(22,154,24,156);
 bar(28,142,30,144);
 bar(28,146,30,148);
 bar(28,150,30,152);
 bar(28,154,30,156);
 bar(34,142,36,144);
 bar(34,146,36,148);
 bar(34,150,36,152);
 bar(34,154,36,156);
 settextstyle(2,0,5);
 outtextxy(17,160,"CALC");
 setfillstyle(1,WHITE);
 bar(17,190,43,216);
 setfillstyle(1,BLUE);
 bar(19,192,23,196);
 bar(19,198,23,202);
 bar(19,204,23,208);
 bar(19,210,23,214);
 bar(25,192,29,196);
 bar(25,198,29,202);
 bar(25,204,29,208);
 bar(25,210,29,214);
 bar(31,192,35,196);
 bar(31,198,35,202);
 bar(31,204,35,208);
 bar(31,210,35,214);
 bar(37,192,41,196);
 bar(37,198,41,202);
 bar(37,204,41,208);
 bar(37,210,41,214);
 settextstyle(2,0,5);
 outtextxy(15,220,"GAME");
 setfillstyle(1,3);
 bar(52,452,212,478);
 bar(232,452,392,478);
 bar(412,452,572,478);
 setcolor(RED);
 settextstyle(3,0,2);
 outtextxy(72,452,"SHUT DOWN");
 setcolor(BLUE);
 settextstyle(3,0,2);
 outtextxy(282,452,"SLEEP");
 setcolor(YELLOW);
 settextstyle(3,0,2);
 outtextxy(442,452,"RESTART");
}

void shutdown()
{
 int x=getmaxx()/2;
 int y=getmaxy()/2;
 setfillstyle(0,0);
 bar(0,0,639,479);
 for(int j=1;j<2;j++)
 {
  clrscr();
  bar(0,0,639,479);
  setcolor(RED);
  settextstyle(7,0,5);
  outtextxy(130,240,"SHUTTING DOWN");
  for(int i=200;i>30;i--)
  {
   delay(10);
   setcolor(i/10);
   arc(x,y,0,180,i-10);
  }
 }
 setfillstyle(0,0);
 bar(0,0,639,479);
 mousehide();
}

void billing();
void payslip();
void game();
void calculator();

void main()
{
 int x,y,cl,a,b;
 clrscr();
 int g=DETECT,m;
 initgraph(&g,&m,"c:\\tc\\bgi");
 a=100;
 b=400;
 start();
 int ch;
 do
 {
  desktop();
  setposi(a,b);
  callmouse();
  ch=0;
  do
  {
   mouseposi(x,y,cl);
   if((cl&1)==1)
   {
    if((x>=52&&x<=212)&&(y>=452&&y<=478))
    {
     ch=1;
    }
    else if((x>=232&&x<=392)&&(y>=452&&y<=478))
    {
     ch=2;
    }
    else if((x>=412&&x<=572)&&(y>=452&&y<=478))
    {
     ch=3;
    }
    else if((x>=5&&x<=55)&&(y>=5&&y<=55))
    {
     ch=4;
    }
    else if((x>=5&&x<=55)&&(y>=65&&y<=115))
    {
     ch=5;
    }
    else if((x>=5&&x<=55)&&(y>=125&&y<=175))
    {
     ch=6;
    }
    else if((x>=5&&x<=185)&&(y>=55&&y<=235))
    {
     ch=7;
    }
   }
  }while(ch==0);
  switch(ch)
  {
   case 1:shutdown();
	  break;

   case 2:bar(0,0,639,479);
	  getch();
	  break;

   case 3:shutdown();
	  delay(1000);
	  start();
	  desktop();
	  break;

   case 4:billing();
	  break;

   case 5:payslip();
	  break;

   case 6:calculator();
	  break;

   case 7:game();
	  break;
  }
 }while(ch!=1);
 getch();
}

//global variable declaration
int k1=7,r1=0,flag1=0;

struct mdate
{
 int mm,dd,yy;
};

ofstream ofile;
ifstream ifile;

class item
{
 int itemno;
 char name[25];
 mdate d;

 public:
 void add()
 {
  cout<<"\n\n\tItem No: ";
  cin>>itemno;
  cout<<"\n\n\tName of the item: ";
  gets(name);
  cout<<"\n\n\tManufacturing Date(dd-mm-yy): ";
  cin>>d.mm;
  cin>>d.dd;
  cin>>d.yy;
 }
 void show()
 {
  cout<<"\n\tItem No: ";
  cout<<itemno;
  cout<<"\n\n\tName of the item: ";
  cout<<name;
  cout<<"\n\n\tManufacturing Date : ";
  cout<<d.mm<<"-"<<d.dd<<"-"<<d.yy;
 }
 void report()
 {
  gotoxy(3,k1);
  cout<<itemno;
  gotoxy(13,k1);
  puts(name);
 }
 int retno()
 {
  return(itemno);
 }
};

//derived class
class amount: public item
{
 float price,qty,tax,gross,dis,netamt;

 public:
 void add();
 void show();
 void report();
 void calculate();
 void pay();
 float retnetamt()
 {
  return(netamt);
 }
}amt;

void amount::add()
{
 char cho='y';
 ofile.open("itemstore.dat",ios::app);
 while(cho=='y'||cho=='Y')
 {
  clrscr();
  item::add();
  cout<<"\n\n\tPrice: ";
  cin>>price;
  cout<<"\n\n\tQuantity: ";
  cin>>qty;
  cout<<"\n\n\tTax percent: ";
  cin>>tax;
  cout<<"\n\n\tDiscount percent: ";
  cin>>dis;
  calculate();
  ofile.write((char *)&amt,sizeof(amt));
  ofile.close();
  cout<<"\n\nAny more records to be created (y/n) ? : ";
  cin>>cho;
 }
}
void amount::calculate()
{
 gross=price+(price*(tax/100));
 netamt=qty*(gross-(gross*(dis/100)));
}
void amount::show()
{
 ifile.open("itemstore.dat",ios::binary);
 ifile.read((char*)&amt,sizeof(amt));
 item::show();
 cout<<"\n\n\tNet amount: ";
 cout<<netamt;
 ifile.close();
}

void amount::report()
{
 item::report();
 gotoxy(23,k1);
 cout<<price;
 gotoxy(33,k1);
 cout<<qty;
 gotoxy(44,k1);
 cout<<tax;
 gotoxy(52,k1);
 cout<<dis;
 gotoxy(64,k1);
 cout<<netamt;
 k1=k1+1;
 if(k1==50)
 {
  gotoxy(25,50);
  cout<<"PRESS ANY KEY TO CONTINUE...";
  getch();
  k1=7;
  clrscr();
  gotoxy(30,3);
  cout<<" ITEM DETAILS ";
  gotoxy(3,5);
  cout<<"NUMBER";
  gotoxy(13,5);
  cout<<"NAME";
  gotoxy(23,5);
  cout<<"PRICE";
  gotoxy(33,5);
  cout<<"QUANTITY";
  gotoxy(44,5);
  cout<<"TAX";
  gotoxy(52,5);
  cout<<"DEDUCTION";
  gotoxy(64,5);
  cout<<"NET AMOUNT";
 }
}

void amount::pay()
{
 show();
 cout<<"\n\n\n\n\t\t                 DETAILS                  ";
 rectangle(119,210,487,252);
 cout<<"\n\n\n\t\tPRICE                     :"<<price;
 cout<<"\n\n\t\tQUANTITY                  :"<<qty;
 cout<<"\n\t\tTAX PERCENTAGE              :"<<tax;
 cout<<"\n\t\tDISCOUNT PERCENTAGE         :"<<dis;
 cout<<"\n\n\n\t\tNET AMOUNT              :Rs."<<netamt;
 rectangle(119,210,487,415);
 rectangle(1,1,639,479);
}

void billing()
{
 int x,y,cl,a,b;
 clrscr();
 a=100;
 b=400;
 menu:
 setposi(a,b);
 callmouse();
 mouseposi(x,y,cl);
 cout.setf(ios::fixed);
 cout.setf(ios::showpoint);
 cout<<setprecision(2);
 clrscr();
 setfillstyle(0,0);
 bar(1,1,639,479);
 setfillstyle(1,WHITE);
 bar3d(190,20,440,60,5,1);
 setcolor(GREEN);
 settextstyle(3,0,3);
 outtextxy(210,25,"Super Market Billing ");
 gotoxy(25,3);
 cout<<"\n\n\n\t\t1.Bill Report\n\n";
 cout<<"\t\t2.Add/Remove/Edit Item\n\n";
 cout<<"\t\t3.Show Item Details\n\n";
 cout<<"\t\t4.Exit\n\n";
 cout<<"\t\tPlease Click On Required Option ";

 rectangle(1,1,639,479);
 int ch=0,ff;
 float gtotal;
 do
 {
  mouseposi(x,y,cl);
  if((cl&1)==1)
  {
   if((x>=128&&x<=231)&&(y>=80&&y<=96))
   {
    ch=1;
   }
   else if((x>=128&&x<=303)&&(y>=112&&y<=128))
   {
    ch=2;
   }
   else if((x>=128&&x<=279)&&(y>=144&&y<=160))
   {
    ch=3;
   }
   else if((x>=128&&x<=175)&&(y>=177&&y<=191))
   {
    ch=4;
   }
  }
 }while(ch==0);

 switch(ch)
 {
  case 1:ss:
	 clrscr();
	 setfillstyle(0,0);
	 bar(1,1,640,480);
	 int cho=0;
	 setposi(a,b);
	 callmouse();
	 setfillstyle(1,WHITE);
	 bar3d(240,20,410,60,5,1);
	 setcolor(GREEN);
	 settextstyle(3,0,3);
	 gotoxy(25,2);
	 outtextxy(270,25,"Bill Details");
	 gotoxy(25,3);
	 cout<<"\n\n\n\t\t1.All Items\n\n";
	 cout<<"\t\t2.Back to Main menu\n\n";
	 cout<<"\t\tPlease Click On Required Option ";
	 rectangle(1,1,639,479);
	 do
	 {
	  mouseposi(x,y,cl);
	  if((cl&1)==1)
	  {
	   if((x>=124&&x<=215)&&(y>=81&&y<=96))
	   {
	    cho=1;
	   }
	   if((x>=124&&x<=278)&&(y>=113&&y<=128))
	   {
	    cho=2;
	   }
	  }
	 }while(cho==0);
	 if(cho==1)
	 {
	  clrscr();
	  setfillstyle(0,0);
	  bar(1,1,640,480);
	  gotoxy(30,3);
	  setfillstyle(1,WHITE);
	  bar3d(240,20,410,60,5,1);
	  setcolor(GREEN);
	  settextstyle(3,0,3);
	  gotoxy(25,2);
	  outtextxy(290,25,"Report");
	  gotoxy(3,5);
	  cout<<"ITEM NO";
	  gotoxy(13,5);
	  cout<<"NAME";
	  gotoxy(23,5);
	  cout<<"PRICE";
	  gotoxy(33,5);
	  cout<<"QUANTITY";
	  gotoxy(44,5);
	  cout<<"TAX %";
	  gotoxy(52,5);
	  cout<<"DISCOUNT %";
	  gotoxy(64,5);
	  cout<<"NET AMOUNT";
	  rectangle(1,1,639,479);
	  ifile.open("itemstore.dat",ios::binary);
	  if(!ifile)
	  {
	   cout<<"\n\nFile Not Found...";
	   goto menu;
	  }
	  rectangle(1,1,639,479);
	  ifile.seekg(0);
	  gtotal=0;
	  while(!ifile.eof())
	  {
	   ifile.read((char*)&amt,sizeof(amt));
	   if(!ifile.eof())
	   {
	    amt.report();
	    gtotal+=amt.retnetamt();
	    ff=0;
	   }
	   if(ff!=0) gtotal=0;
	  }
	  gotoxy(17,k1);
	  cout<<"\n\n\n\t\t\tGrand Total="<<gtotal;
	  rectangle(1,1,639,479);
	  getch();
	  ifile.close();
	  goto ss;
	 }
	 if(cho==2)
	  goto menu;
	 break;

  case 2:db:
	 clrscr();
	 setposi(a,b);
	 callmouse();
	 setfillstyle(1,BLACK);
	 bar(1,1,639,479);
	 setfillstyle(1,WHITE);
	 bar3d(240,20,410,60,5,1);
	 setcolor(GREEN);
	 settextstyle(3,0,3);
	 gotoxy(25,2);
	 outtextxy(270,25,"Bill Editors");
	 setcolor(WHITE);
	 gotoxy(25,3);
	 cout<<"\n\n\n\t\t1.Add Item Details\n\n";
	 cout<<"\t\t2.Edit Item Details\n\n";
	 cout<<"\t\t3.Delete Item Details\n\n";
	 cout<<"\t\t4.Back to Main Menu ";
	 cout<<"\n\n\t\tPlease Click On Required Option ";
	 rectangle(1,1,639,479);
	 int apc=0;
	 do
	 {
	  mouseposi(x,y,cl);
	  if((cl&1)==1)
	  {
	   if((x>=125&&x<=305)&&(y>=78&&y<=95))
	   {
	    apc=1;
	   }
	   if((x>=125&&x<=315)&&(y>=110&&y<=128))
	   {
	    apc=2;
	   }
	   if((x>=125&&x<=268)&&(y>=142&&y<=160))
	   {
	    apc=3;
	   }
	   if((x>=125&&x<=285)&&(y>=175&&y<=192))
	   {
	    apc=4;
	   }
	  }
	 }while(apc==0);
	 switch(apc)
	 {
	  case 1:ofile.open("itemstore.dat",ios::binary|ios::app);
		 amt.add();
		 cout<<"\n\t\tItem Added Successfully!";
		 getch();
		 goto db;

	  case 2:int ino;
		 flag1=0;
		 cout<<"\n\n\tEnter Item Number to be Edited :";
		 cin>>ino;
		 ifile.open("itemstore.dat",ios::binary);
		 ofile.open("itemstore.dat",ios::binary|ios::app);
		 if(!ifile)
		 {
		  cout<<"\n\nFile Not Found...";
		  goto menu;
		 }
		 ifile.seekg(0);
		 r1=0;
		 while(!ifile.eof())
		 {
		  ifile.read((char*)&amt,sizeof(amt));
		  if(!ifile.eof())
		  {
		   int x=amt.item::retno();
		   if(x==ino)
		   {
		    flag1=1;
		    ofile.seekp(r1*sizeof(amt));
		    clrscr();
		    setfillstyle(0,0);
		    bar(1,1,640,480);
		    cout<<"\n\t\tCurrent Details are\n";
		    amt.show();
		    cout<<"\n\n\t\tEnter New Details\n";
		    amt.add();
		    cout<<"\n\t\tItem Details editted";
		    rectangle(1,1,639,479);
		   }
		   else
		    flag1=0;
		  }r1++;
		 }
		 if(flag1==0)
		 {
		  cout<<"\n\t\tItem No does not exist...Please Retry!";
		  getch();
		  goto db;
		 }
		 ifile.close();
		 getch();
		 goto db;

	  case 3:flag1=0;
		 cout<<"\n\n\tEnter Item Number to be deleted :";
		 cin>>ino;
		 ifile.open("itemstore.dat",ios::binary);
		 if(!ifile)
		 {
		  cout<<"\n\nFile Not Found...";
		  goto menu;
		 }
		 fstream tmp("temp.dat",ios::binary|ios::out);
		 ifile.seekg(0);
		 while(ifile.read((char*)&amt, sizeof(amt)))
		 {
		  int x=amt.item::retno();
		  if(x!=ino)
		   tmp.write((char*)&amt,sizeof(amt));
		  else
		  {
		   flag1=1;
		  }
		 }
		 ifile.close();
		 tmp.close();
		 ofile.open("itemstore.dat",ios::trunc|ios::binary);
		 ofile.seekp(0);
		 tmp.open("temp.dat",ios::binary|ios::in);
		 if(!tmp)
		 {
		  cout<<"Error in File";
		  goto db;
		 }
		 while(tmp.read((char*)&amt,sizeof(amt)))
		 ofile.write((char*)&amt,sizeof(amt));
		 tmp.close();
		 ofile.close();
		 if(flag1==1)
		  cout<<"\n\t\tItem Succesfully Deleted";
		 else if (flag1==0)
		  cout<<"\n\t\tItem does not Exist! Please Retry";
		 rectangle(1,1,639,479);
		 getch();
		 goto db;

	  case 4:goto menu;

	  default: cout<<"\n\n\t\tWrong Choice!!! Retry";
		   getch();
		   goto db;
	 }

  case 3:clrscr();
	 setfillstyle(0,0);
	 bar(1,1,640,480);
	 flag1=0;
	 int ino;
	 cout<<"\n\n\t\tEnter Item Number :";
	 cin>>ino;
	 rectangle(1,1,639,479);
	 ifile.open("itemstore.dat",ios::binary);
	 if(!ifile)
	 {
	  cout<<"\n\nFile Not Found...\nProgram Terminated!";
	  goto menu;
	 }
	 ifile.seekg(0);
	 while(ifile.read((char*)&amt,sizeof(amt)))
	 {
	  int x=amt.item::retno();
	  if(x==ino)
	  {
	   amt.pay();
	   flag1=1;
	   break;
	  }
	 }
	 if(flag1==0)
	 cout<<"\n\t\tItem does not exist....Please Retry!";
	 rectangle(1,1,639,479);
	 getch();
	 ifile.close();
	 goto menu;

  case 4:clrscr();
	 setfillstyle(0,0);
	 setcolor(WHITE);
	 bar(1,1,640,480);
	 char yn='\0';
	 setcolor(WHITE);
	 gotoxy(25,11);
	 cout<<"ARE YOU SURE, YOU WANT TO EXIT ?";
	 rectangle(180,150,455,246);
	 gotoxy(29,15);
	 cout<<" Yes                NO";
	 rectangle(221,224,260,239);
	 rectangle(372,224,407,239);
	 rectangle(1,1,639,479);
	 do
	 {
	  mouseposi(x,y,cl);
	  if((cl&1)==1)
	  {
	   if((x>=221&&x<=260)&&(y>=224&&y<=239))
	   {
	    yn='y';
	   }
	   else if((x>=372&&x<=407)&&(y>=224&&y<=239))
	   {
	    yn='n';
	   }
	  }
	 }while(yn=='\0');

	 if((yn=='Y')||(yn=='y'))
	 {
	  desktop();
	 }
	 else if((yn=='N')||(yn=='n'))
	  goto menu;
	 else
	 {
	  goto menu;
	 }
	 break;

  default:cout<<"\n\n\t\tWrong Choice....Please Retry!";
	  rectangle(1,1,639,479);
	  getch();
	  goto menu;
 }
}

//global variable declaration
int k2=7,r2=0,flag2=0;

struct dateof
{
 int mm,dd,yy;
};

class employee
{
 int empno,dept;
 char name[25];
 dateof d,j;
 public:
 void add()
 {
  cout<<"\n\n\tEmployee No: ";
  cin>>empno;
  rectangle(1,1,639,479);
  cout<<"\n\n\tName of the Employee: ";
  gets(name);
  rectangle(1,1,639,479);
  cout<<"\n\n\tDepartment (in nos.): ";
  cin>>dept;
  rectangle(1,1,639,479);
  cout<<"\n\n\tDate of Birth (dd-mm-yy) (use space): ";
  cin>>d.mm>>d.dd>>d.yy;
  rectangle(1,1,639,479);
  cout<<"\n\n\tDate of Joining (dd-mm-yy) (use space): ";
  cin>>j.mm>>j.dd>>j.yy;
  rectangle(1,1,639,479);
 }
 void show()
 {
  cout<<"\n\tEmployee No: ";
  cout<<empno;
  cout<<"\n\n\tName of the Employee: ";
  cout<<name;
  cout<<"\n\n\tDepartment: ";
  cout<<dept;
  cout<<"\n\n\tDate of Birth (dd-mm-yy): ";
  cout<<d.mm<<"-"<<d.dd<<"-"<<d.yy;
  cout<<"\n\n\tDate of Joining (dd-mm-yy): ";
  cout<<j.mm<<"-"<<j.dd<<"-"<<j.yy;
  rectangle(1,1,639,479);
 }
 void report()
 {
  gotoxy(3,k2);
  cout<<empno;
  gotoxy(10,k2);
  puts(name);
  gotoxy(20,k2);
  cout<<dept;
 }
 int retno()
 {
  return(empno);
 }
 int retd()
 {
  return(dept);
 }
};

class Salary: public employee
{
 float basic,gross,deduction,da,hra,ot,oth,pf,lic,fadv,coops,hdfc,netpay;
 int abdys;
 public:
 void add();
 void del();
 void edit();
 void show();
 void report();
 void calculate();
 void pay();
}sal;

void Salary::add()
{
 ofile.open("mine.dat",ios::app);
 char cho='y';
 while(cho=='y'||cho=='Y')
 {
  employee::add();
  cout<<"\n\n\tBasic Pay: ";
  cin>>basic;
  rectangle(1,1,639,479);
  cout<<"\n\n\tDays Absent: ";
  cin>>abdys;
  rectangle(1,1,639,479);
  cout<<"\n\n\tOvertime Hours: ";
  cin>>oth;
  rectangle(1,1,639,479);
  cout<<"\n\n\tLoans and Savings\n";
  cout<<"\n\n\tLIC: ";
  cin>>lic;
  rectangle(1,1,639,479);
  cout<<"\n\n\tHDFC: ";
  cin>>hdfc;
  rectangle(1,1,639,479);
  cout<<"\n\n\tCo Operative Society: ";
  cin>>coops;
  rectangle(1,1,639,479);
  calculate();
  ofile.write((char *)&sal,sizeof(sal));
  cout<<"\n\nAny more records to be created (y/n) ? :";
  cin>>cho;
  rectangle(1,1,639,479);
 }
 ofile.close();
}

void Salary::del()
{
 int flag2=0,eno;
 ofile.open("temp.dat");
 ifile.open("mine.dat");
 cout<<"\n\n\tEnter Employee Number to be deleted :";
 cin>>eno;
 ifile.seekg(0);
 while(ifile.read((char*)&sal, sizeof(sal)))
 {
  int x=sal.employee::retno();
  if(x!=eno)
   ofile.write((char*)&sal,sizeof(sal));
  else
  {
    flag2=1;
  }
 }
 ifile.close();
 ofile.close();
 if(flag2==1)
 {
  remove("mine.dat");
  rename("temp.dat","mine.dat");
  cout<<"\n\t\tEmployee Succesfully Deleted";
 }
 else
  cout<<"\n\t\tEmployee does not Exist! ";
 ofile.close();
 ifile.close();
}

void Salary::edit()
{
 ifile.open("mine.dat");
 ofile.open("temp.dat");
 int eno;
 flag2=0;
 cout<<"\n\n\tEnter Employee Number to be Edited :";
 cin>>eno;
 while(ifile.read((char*)&sal,sizeof(sal)))
 {
  int x=sal.employee::retno();
  if(x==eno)
  {
   flag2=1;
   clrscr();
   setfillstyle(0,0);
   setcolor(0);
   bar(1,1,639,479);
   cout<<"\n\n\t\tCurrent details \n";
   sal.show();
   cout<<"\n\n\t\tEnter New Details\n";
   employee::add();
   cout<<"\n\n\tBasic Pay: ";
   cin>>basic;
   rectangle(1,1,639,479);
   cout<<"\n\n\tDays Absent: ";
   cin>>abdys;
   rectangle(1,1,639,479);
   cout<<"\n\n\tOvertime Hours: ";
   cin>>oth;
   rectangle(1,1,639,479);
   cout<<"\n\n\tLoans and Savings\n";
   cout<<"\n\n\tLIC: ";
   cin>>lic;
   rectangle(1,1,639,479);
   cout<<"\n\n\tHDFC: ";
   cin>>hdfc;
   rectangle(1,1,639,479);
   cout<<"\n\n\tCo Operative Society: ";
   cin>>coops;
   rectangle(1,1,639,479);
   calculate();
   ofile.write((char*)&sal,sizeof(sal));
   cout<<"\n\t\tEmployee Details editted";
  }
  else
   ofile.write((char*)&sal,sizeof(sal));
 }
 ofile.close();
 ifile.close();
 if(flag2==0)
 {
  cout<<"\n\t\tEmployee No. does not exist...Please Retry!";
 }
 else if(flag2==1)
 {
  remove("mine.dat");
  rename("temp.dat","mine.dat");
 }
}

void Salary::calculate()
{
 hra=basic*0.2;
 da=basic*0.25;
 ot=oth*70;
 pf=basic*0.15;
 fadv=100;
 gross=basic+hra+da+ot;
 deduction=pf+lic+fadv+coops+hdfc;
 netpay=gross-deduction;
}

void Salary::show()
{
 employee::show();
 cout<<"\n\n\tNet pay: ";
 cout<<netpay;
}

void Salary::report()
{
 employee::report();
 gotoxy(30,k2);
 cout<<basic;
 gotoxy(42,k2);
 cout<<gross;
 gotoxy(52,k2);
 cout<<deduction;
 gotoxy(67,k2);
 cout<<netpay;
 k2=k2+1;
 if(k2==50)
 {
  gotoxy(25,50);
  cout<<"PRESS ANY KEY TO CONTINUE...";
  getch();
  k2=7;
  clrscr();
  gotoxy(30,3);
  cout<<" EMPLOYEE DETAILS ";
  gotoxy(3,5);
  cout<<"CODE";
  gotoxy(10,5);
  cout<<"NAME";
  gotoxy(20,5);
  cout<<"DEPT";
  gotoxy(30,5);
  cout<<"BASIC";
  gotoxy(40,5);
  cout<<"GROSS PAY";
  gotoxy(52,5);
  cout<<"DEDUCTION";
  gotoxy(67,5);
  cout<<"NETPAY";
 }
}

void Salary::pay()
{
 setfillstyle(0,0);
 setcolor(0);
 bar(1,1,639,479);
 show();
 getch();
 cout<<"\n\n\n";
 cout<<"\n\t\t             ENTERPRISES                  ";
 cout<<"\n\n\t\tBASIC SALARY                 :"<<basic;
 cout<<"\n\t\tDEARNESS ALLOWANCE           :"<<da;
 cout<<"\n\t\tHOUSE RENT ALLOWANCE         :"<<hra;
 cout<<"\n\t\tOVER TIME HOURS              :"<<oth;
 cout<<"\n\t\tOVER TIME WAGES              :"<<ot;
 cout<<"\n\t\tGROSS PAY                    :"<<gross;
 cout<<"\n\n\n\t\tPROVIDENT FUND               :"<<pf;
 cout<<"\n\t\tLIC                          :"<<lic;
 cout<<"\n\t\tFESTIVAL ADVANCE             :"<<fadv;
 cout<<"\n\t\tHDFC                         :"<<hdfc;
 cout<<"\n\t\tCO-OP S                      :"<<coops;
 cout<<"\n\n\n\t\tNET PAY                      :Rs."<<netpay;
 cout<<"\n";
 setcolor(WHITE);
 rectangle(110,160,475,470);
 rectangle(110,160,475,200);
 rectangle(1,1,639,479);
 getch();
}

void payslip()
{
 int x,y,cl,a,b;
 clrscr();
 int g=DETECT,m;
 initgraph(&g,&m,"c:\\tc\\bgi");
 a=100;
 b=400;
 setfillstyle(0,0);
 setcolor(0);
 bar(1,1,639,479);
 setposi(a,b);
 callmouse();
 cout.setf(ios::fixed);
 cout.setf(ios::showpoint);
 cout<<setprecision(2);
 menu:
 k2=7;
 cl=0;
 clrscr();
 setfillstyle(0,0);
 setcolor(0);
 bar(1,1,639,479);
 gotoxy(30,3);
 setfillstyle(0,0);
 bar(1,1,639,479);
 setfillstyle(1,WHITE);
 bar3d(140,20,510,60,5,1);
 setcolor(GREEN);
 settextstyle(3,0,3);
 outtextxy(150,25,"Company Employee Management");
 gotoxy(25,3);
 cout<<"\n\n\n\t\t1.Salary Report\n\n";
 cout<<"\t\t2.Edit database\n\n";
 cout<<"\t\t3.Search\n\n";
 cout<<"\t\t4.Pay Slip\n\n";
 cout<<"\t\t5.Exit\n\n";
 cout<<"\t\tPlease Click On Required Option: ";
 setcolor(WHITE);
 rectangle(1,1,639,479);
 int ch=0;
 do
 {
  mouseposi(x,y,cl);
  if((cl&1)==1)
  {
   if((x>=125&&x<=250)&&(y>=78&&y<=95))
   {
    ch=1;
   }
   else if((x>=125&&x<=250)&&(y>=110&&y<=128))
   {
    ch=2;
   }
   else if((x>=125&&x<=195)&&(y>=142&&y<=160))
   {
    ch=3;
   }
   else if((x>=125&&x<=210)&&(y>=175&&y<=192))
   {
    ch=4;
   }
   else if((x>=125&&x<=178)&&(y>=206&&y<=224))
   {
    ch=5;
   }
  }
  cl=0;
 }while(ch==0);
 cl=0;
 switch(ch)
 {
  case 1:ss:
	 clrscr();
	 setfillstyle(0,0);
	 setcolor(0);
	 bar(1,1,639,479);
	 cl=0;
	 setfillstyle(1,WHITE);
	 bar3d(220,20,430,60,5,1);
	 setcolor(GREEN);
	 settextstyle(3,0,3);
	 outtextxy(230,25,"Salary Statement");
	 gotoxy(25,3);
	 cout<<"\n\n\n\t\t1.All Employees\n\n";
	 cout<<"\t\t2.Department wise\n\n";
	 cout<<"\t\t3.Back to Main menu\n\n";
	 cout<<"\t\tPlease Click On Required Option: ";
	 int cho=0;
	 k2=7;
	 cl=0;
	 do
	 {
	  mouseposi(x,y,cl);
	  if((cl&1)==1)
	  {
	   if((x>=125&&x<=250)&&(y>=78&&y<=95))
	   {
	    cho=1;
	   }
	   else if((x>=125&&x<=265)&&(y>=110&&y<=128))
	   {
	    cho=2;
	   }
	   else if((x>=125&&x<=282)&&(y>=142&&y<=160))
	   {
	    cho=3;
	   }
	  }
	  cl=0;
	 }while(cho==0);
	 if(cho==1)
	 {
	  ifile.open("mine.dat",ios::binary);
	  if(!ifile)
	  {
	   cout<<"\n\nFile Not Found...";
	   getch();
	   goto menu;
	  }
	  else
	  {
	   clrscr();
	   k2=7;
	   setfillstyle(0,0);
	   setcolor(0);
	   bar(1,1,639,479);
	   setfillstyle(1,WHITE);
	   bar3d(220,20,430,60,5,1);
	   setcolor(GREEN);
	   settextstyle(3,0,3);
	   outtextxy(230,25,"EMPLOYEE DETAILS");
	   gotoxy(3,5);
	   cout<<"CODE";
	   gotoxy(10,5);
	   cout<<"NAME";
	   gotoxy(20,5);
	   cout<<"DEPT";
	   gotoxy(30,5);
	   cout<<"BASIC";
	   gotoxy(40,5);
	   cout<<"GROSS PAY";
	   gotoxy(52,5);
	   cout<<"DEDUCTION";
	   gotoxy(67,5);
	   cout<<"NETPAY";
	  }
	  ifile.seekg(0);
	  while(!ifile.eof())
	  {
	   ifile.read((char*)&sal,sizeof(sal));
	   if(!ifile.eof())
	    sal.report();
	  }
	  getch();
	  ifile.close();
	  goto ss;
	 }
	 if(cho==2)
	 {
	  flag2=0;
	  k2=7;
	  cout<<"\n\t\tEnter Department: ";
	  int de;
	  cin>>de;
	  clrscr();
	  setfillstyle(0,0);
	  setcolor(0);
	  bar(1,1,639,479);
	  gotoxy(30,3);
	  cout<<" EMPLOYEE DETAILS ";
	  gotoxy(3,5);
	  cout<<"CODE";
	  gotoxy(10,5);
	  cout<<"NAME";
	  gotoxy(20,5);
	  cout<<"DEPT";
	  gotoxy(30,5);
	  cout<<"BASIC";
	  gotoxy(40,5);
	  cout<<"GROSS PAY";
	  gotoxy(52,5);
	  cout<<"DEDUCTION";
	  gotoxy(67,5);
	  cout<<"NETPAY";
	  ifile.open("mine.dat",ios::binary);
	  if(!ifile)
	  {
	   cout<<"\n\nFile Not Found...";
	   getch();
	   goto menu;
	  }
	  ifile.seekg(0);
	  while(!ifile.eof())
	  {
	   ifile.read((char*)&sal,sizeof(sal));
	   if(!ifile.eof())
	   {
	    int x=sal.employee::retd();
	    if(x==de)
	    {
	     flag2=1;
	     sal.report();
	    }
	   }
	  }
	  if(flag2==0)
	  {
	   cout<<"\n\n\n\t\tDepartment does not exist...";
	   getch();
	   ifile.close();
	   goto ss;
	  }
	  getch();
	  ifile.close();
	  goto ss;
	 }
	 if(cho==3)
	 {
	  goto menu;
	 }
	 break;
  case 2:db:
	 clrscr();
	 setfillstyle(0,0);
	 setcolor(0);
	 bar(1,1,639,479);
	 setfillstyle(1,WHITE);
	 bar3d(210,20,440,60,5,1);
	 setcolor(GREEN);
	 settextstyle(3,0,3);
	 outtextxy(220,25,"Employee database");
	 gotoxy(25,3);
	 cout<<"\n\n\n\t\t1.Add Employee Details\n\n";
	 cout<<"\t\t2.Edit Employee Details\n\n";
	 cout<<"\t\t3.Delete Employee\n\n";
	 cout<<"\t\t4.Back to Main Menu \n\n";
	 cout<<"\t\tPlease Click On Required Option";
	 setcolor(0);
	 rectangle(1,1,639,789);
	 int apc=0;
	 do
	 {
	  mouseposi(x,y,cl);
	  if((cl&1)==1)
	  {
	   if((x>=125&&x<=305)&&(y>=78&&y<=95))
	   {
	    apc=1;
	   }
	   else if((x>=125&&x<=315)&&(y>=110&&y<=128))
	   {
	    apc=2;
	   }
	   else if((x>=125&&x<=268)&&(y>=142&&y<=160))
	   {
	    apc=3;
	   }
	   else if((x>=125&&x<=285)&&(y>=174&&y<=192))
	   {
	    apc=4;
	   }
	  }
	  cl=0;
	 }while(apc==0);
	 switch(apc)
	 {

	  case 1:sal.add();
		 cout<<"\n\t\tEmployee Added Successfully!";
		 getch();
		 goto db;

	  case 2:ifile.open("mine.dat",ios::binary);
		 if(!ifile)
		 {
		  cout<<"\n\nFile Not Found...";
		  getch();
		  goto db;
		 }
		 ifile.close();
		 sal.edit();
		 getch();
		 goto db;

	  case 3:ifile.open("mine.dat",ios::binary);
		 if(!ifile)
		 {
		  cout<<"\n\nFile Not Found...";
		  getch();
		  goto menu;
		 }
		 ifile.close();
		 sal.del();
		 getch();
		 goto db;

	  case 4:goto menu;

	  default:cout<<"\n\n\t\tWrong Choice!!! Retry";
		  getch();
		  goto db;
	 }

  case 3:clrscr();
	 setfillstyle(0,0);
	 setcolor(0);
	 bar(1,1,639,479);
	 cout<<"\n\n\t\tEnter Employee Number to be found: ";
	 flag2=0;
	 int eno;
	 cin>>eno;
	 ifile.open("mine.dat",ios::binary);
	 if(!ifile)
	 {
	  cout<<"\n\nFile Not Found...";
	  getch();
	  goto menu;
	 }
	 ifile.seekg(0);
	 while(ifile.read((char*)&sal, sizeof(sal)))
	 {
	  int x=sal.employee::retno();
	  if(x==eno)
	  {
	   flag2=1;
	   clrscr();
	   setfillstyle(0,0);
	   setcolor(0);
	   bar(1,1,639,479);
	   setfillstyle(1,WHITE);
	   bar3d(220,20,420,60,5,1);
	   setcolor(GREEN);
	   settextstyle(3,0,3);
	   outtextxy(230,25,"Employee Details");
	   cout<<"\n\n\n";
	   setcolor(WHITE);
	   sal.show();
	  }
	 }
	 ifile.close();
	 if(flag2==0)
	  cout<<"\n\t\tEmployee does not exist....Please Retry!";
	 getch();
	 goto menu;

  case 4:clrscr();
	 setfillstyle(0,0);
	 setcolor(0);
	 bar(1,1,639,479);
	 flag2=0;
	 cout<<"\n\n\t\tEnter Employee Number :";
	 cin>>eno;
	 setfillstyle(0,0);
	 setcolor(0);
	 bar(1,1,639,479);
	 ifile.open("mine.dat",ios::binary);
	 if(!ifile)
	 {
	  cout<<"\n\nFile Not Found...\nProgram Terminated!";
	  getch();
	  goto menu;
	 }
	 ifile.seekg(0);
	 while(ifile.read((char*)&sal,sizeof(sal)))
	 {
	  int x=sal.employee::retno();
	  if(x==eno)
	  {
	   sal.pay();
	   flag2=1;
	   break;
	  }
	 }
	 if(flag2==0)
	  cout<<"\n\t\tEmployee does not exist....Please Retry!";
	 getch();
	 ifile.close();
	 goto menu;

  case 5:clrscr();
	 setfillstyle(0,0);
	 setcolor(0);
	 bar(1,1,639,479);
	 setfillstyle(0,0);
	 setcolor(WHITE);
	 bar(1,1,640,480);
	 char yn='\0';
	 setcolor(WHITE);
	 gotoxy(25,11);
	 cout<<"ARE YOU SURE, YOU WANT TO EXIT ?";
	 rectangle(180,150,455,246);
	 gotoxy(29,15);
	 cout<<" Yes                NO";
	 rectangle(221,224,260,239);
	 rectangle(372,224,407,239);
	 rectangle(1,1,639,479);
	 do
	 {
	  mouseposi(x,y,cl);
	  if((cl&1)==1)
	  {
	   if((x>=221&&x<=260)&&(y>=224&&y<=239))
	   {
	    yn='y';
	   }
	   else if((x>=372&&x<=407)&&(y>=224&&y<=239))
	   {
	    yn='n';
	   }
	  }
	 }while(yn=='\0');

	 if((yn=='Y')||(yn=='y'))
	 {
	  desktop();
	 }
	 else if((yn=='N')||(yn=='n'))
	  goto menu;
	 else
	 {
	  goto menu;
	 }
	 break;

  default:cout<<"\n\n\t\tWrong Choice....Please Retry!";
	  getch();
	  goto menu;
 }
}

int initmouse();
void showptr();
void openwindow();
void hideptr();
void getmousepos(int *,int*,int*);
void restrictptr(int,int,int,int);
int button,x,y,x1,y1,x2,y2,s,deci=0;
long double num=0,get,num1=0,result=0,temp;
long double addnum(int);
long double delnum();
long double adddeci(int);
void overandout();
char opr;
int a,b,r,i1,count,c,sq,newnum=1,d=0;
union REGS i,o;

void calculator()
{
 int driver=DETECT,mode;
 int q,p[12];
 char input;
 char *inpu[8][4]={"x^2","sqrt","x^3","cube_r","x^n","xroot(n)","log","ln","sin","cos","tan","clr" ,"asin","acos","atan","bkspc","7","8","9","/","4","5","6","*","1","2","3","-","0",".","=","+"};
 char inp[8][4]={'@','!','#','$','%','^','&','(',')','|','~','l','`','?','>','<','7','8','9','/','4','5','6','*','1','2','3','-','0','.','=','+'};
 initgraph(&driver,&mode,"c:\\tc\\bgi");
 if(initmouse()==0)
 {
  printf("not");
  getch();
  exit(0);
 }
 openwindow();
 getch();
 cleardevice();
 setfillstyle(CLOSE_DOT_FILL,GREEN);
 bar(150,82,530,450);
 bar(510,62,530,345);
 setfillstyle(1,RED);
 bar(130,82,510,430);
 setcolor(RED);
 rectangle(130,52,510,82);
 rectangle(131,53,509,81);
 rectangle(132,54,508,80);
 c=240;
 d=100;
 s=0;
 for(a=0;a<8;a++)
 {
  c=150;
  for(b=0;b<4;b++)
  {
   setfillstyle(1,BLUE);
   bar(c,d,c+70,d+30);
   setcolor(WHITE);
   outtextxy(c+8,d+14,inpu[a][b]);
   c+=90;
  }
  d+=40;
 }
 showptr();
 num=0;
 gotoxy(45,5);
 printf("%18.0Lf",num);
 count=0;
 do
 {
  outtextxy(30,20,"Press any key to exit..");
  i1=0;
  c=150;
  d=100;
  rectangle(0,0,638,478);
  getmousepos(&button,&x,&y);
  for(a=0;a<8;a++)
  {
   c=150;
   for(b=0;b<4;b++)
   {
    if((x>=c&&x<=c+70)&&(y>=d&&y<=d+30))
    {
     if((button&1)==1)
     {
      sound(10);
      delay(50);
      while((button&1)==1)
      {
       setcolor(YELLOW);
       rectangle(c,d,c+70,d+30);
       rectangle(c-1,d-1,c+71,d+31);
       rectangle(c-2,d-2,c+72,d+32);
       delay(50);
       break;
      }
      delay(100);
      setcolor(RED);
      rectangle(c,d,c+70,d+30);
      rectangle(c-1,d-1,c+71,d+31);
      rectangle(c-2,d-2,c+72,d+32);
      input=inp[a][b];
      switch(input)
      {
       case '1':if(deci==0)
		{
		 get=addnum(1);
		 gotoxy(45,5);
		 printf("%18.0Lf",get);
		}
		else
		{
		 get=adddeci(1);
		 gotoxy(45,5);
		 printf("%18.2Lf",get);
		}
		break;

       case '2':if(deci==0)
		{
		 get=addnum(2);
		 gotoxy(45,5);
		 printf("%18.0Lf",get);
		}
		else
		{
		 get=adddeci(2);
		 gotoxy(45,5);
		 printf("%18.2Lf",get);
		}
		break;

       case '3':if(deci==0)
		{
		 get=addnum(3);
		 gotoxy(45,5);
		 printf("%18.0Lf",get);
		}
		else
		{
		 get=adddeci(3);
		 gotoxy(45,5);
		 printf("%18.2Lf",get);
		}
		break;

       case '4':if(deci==0)
		{
		 get=addnum(4);
		 gotoxy(45,5);
		 printf("%18.0Lf",get);
		}
		else
		{
		 get=adddeci(4);
		 gotoxy(45,5);
		 printf("%18.2Lf",get);
		}
		break;

       case '5':if(deci==0)
		{
		 get=addnum(5);
		 gotoxy(45,5);
		 printf("%18.0Lf",get);
		}
		else
		{
		 get=adddeci(5);
		 gotoxy(45,5);
		 printf("%18.2Lf",get);
		}
		break;

       case '6':if(deci==0)
		{
		 get=addnum(6);
		 gotoxy(45,5);
		 printf("%18.0Lf",get);
		}
		else
		{
		 get=adddeci(6);
		 gotoxy(45,5);
		 printf("%18.2Lf",get);
		}
		break;

       case '7':if(deci==0)
		{
		 get=addnum(7);
		 gotoxy(45,5);
		 printf("%18.0Lf",get);
		}
		else
		{
		 get=adddeci(7);
		 gotoxy(45,5);
		 printf("%18.2Lf",get);
		}
		break;

       case '8':if(deci==0)
		{
		 get=addnum(8);
		 gotoxy(45,5);
		 printf("%18.0Lf",get);
		}
		else
		{
		 get=adddeci(8);
		 gotoxy(45,5);
		 printf("%18.2Lf",get);
		}
		break;

       case '9':if(deci==0)
		{
		 get=addnum(9);
		 gotoxy(45,5);
		 printf("%18.0Lf",get);
		}
		else
		{
		 get=adddeci(9);
		 gotoxy(45,5);
		 printf("%18.2Lf",get);
		}
		break;

       case '0':if(deci==0)
		{
		 get=addnum(0);
		 gotoxy(45,5);
		 printf("%18.0Lf",get);
		}
		else
		{
		 get=adddeci(0);
		 gotoxy(45,5);
		 printf("%18.2Lf",get);
		}
		break;

       case '+':num1=num;
		num=0;
		opr='+';
		deci=0;
		gotoxy(45,5);
		printf("%18.0Lf",num);
		break;

       case '-':num1=num;
		num=0;
		opr='-';
		deci=0;
		gotoxy(45,5);
		printf("%18.0Lf",num);
		break;

       case '*':num1=num;
		num=0;
		opr='*';
		deci=0;
		gotoxy(45,5);
		printf("%18.0Lf",num);
		break;

       case '/':num1=num;
		num=0;
		opr='/';
		deci=0;
		gotoxy(45,5);
		printf("%18.0Lf",num);
		break;

       case 'l':num=0;
		num1=0;
		result=0;
		count=0;
		temp=0;
		deci=0;
		gotoxy(45,5);
		printf("%18.0Lf",num);
		break;

       case '@':result=pow(num,2);
		gotoxy(45,5);
		if(deci==0)
		 printf("%18.0Lf",result);
		else
		 printf("%18.4Lf",result);
		break;

       case '!':result=sqrt(num);
		gotoxy(45,5);
		deci=0;
		printf("%18.4Lf",result);
		break;

       case '#':result=pow(num,3);
		gotoxy(45,5);
		if(deci==0)
		 printf("%18.0Lf",result);
		else
		 printf("%18.6Lf",result);
		break;

       case '$':result=pow(num,1/3);
		gotoxy(45,5);
		deci=0;
		printf("%18.4Lf",result);
		break;

       case '%':num1=num;
		num=0;
		gotoxy(45,5);
		printf("%18.0Lf",num);
		deci=0;
		opr='%';
		break;

       case '^':num1=num;
		num=0;
		gotoxy(45,5);
		deci=0;
		opr='^';
		printf("%18.0Lf",num);
		break;

       case '&':result=log10(num);
		gotoxy(45,5);
		deci=0;
		printf("%18.4Lf",result);
		break;

       case '(':result=log(num);
		gotoxy(45,5);
		deci=0;
		printf("%18.4Lf",result);
		break;

       case ')':result=sin(num*3.14/180);
		gotoxy(45,5);
		deci=0;
		printf("%18.2Lf",result);
		break;

       case '|':result=cos(num*3.14/180);
		gotoxy(45,5);
		deci=0;
		printf("%18.2Lf",result);
		break;

       case '~':result=tan(num*3.14/180);
		deci=0;
		gotoxy(45,5);
		printf("%18.2Lf",result);
		break;

       case '`':result=asin(num*180/3.14);
		gotoxy(45,5);
		deci=0;
		printf("%18.2Lf",result);
		break;

       case '?':result=acos(num*180/3.14);
		gotoxy(45,5);
		deci=0;
		printf("%18.2Lf",result);
		break;

       case '>':result=atan(num*180/3.14);
		gotoxy(45,5);
		deci=0;
		printf("%18.2Lf",result);
		break;

       case '<':get=delnum();
		gotoxy(45,5);
		if(deci==1)
		 printf("%18.2Lf",num);
		else
		 printf("%18.0Lf",num);
		break;

       case '.':deci=1;
		break;

       case '=':switch(opr)
		{
		 case '^':result=pow(num1,1/num);
			  gotoxy(45,5);
			  printf("%18.2Lf",num);
			  break;

		 case '%':result=pow(num1,num);
			  if(deci==0)
			  {
			   gotoxy(45,5);
			   printf("%18.0Lf",result);
			  }
			  else
			  {
			   gotoxy(45,5);
			   printf("%18.num*2Lf",result);
			  }
			  break;

		 case '+':if(count<1)
			  {
			   result=num+num1;
			  }
			  else
			  {
			   result=result+num;
			  }
			  gotoxy(45,5);
			  if(deci==0)
			   printf("%18.0Lf",result);
			  else
			   printf("%18.6Lf",result);
			  count+=1;
			  break;

		 case '-':if(count<1)
			  {
			   result=num1-num;
			  }
			  else
			  {
			   result=result-num;
			  }
			  gotoxy(45,5);
			  if(deci==0)
			   printf("%18.0Lf",result);
			  else
			   printf("%18.6Lf",result);
			  count+=1;
			  break;

		 case '*':if(count<1)
			  {
			   result=num1*num;
			  }
			  else
			  {
			   result=result*num;
			  }
			  gotoxy(45,5);
			  if(deci==0)
			   printf("%18.0Lf",result);
			  else
			   printf("%18.6Lf",result);
			  count+=1;
			  break;

		 case '/':if(count<1)
			  {
			   result=num1/num;
			  }
			  else
			  {
			   result=result/num;
			  }
			  gotoxy(45,5);
			  if(deci==0)
			   printf("%18.0Lf",result);
			  else
			   printf("%18.6Lf",result);
			  count+=1;
			  break;
		}
      }
     }
    }
    c+=90;
   }
   d+=40;
  }
  setcolor(YELLOW);
  delay(150);
 }while(!kbhit());
 overandout();
 getch();
}

long double addnum(int getnum)
{
 temp=num;
 num=num*10+getnum;
 return(num);
}

long double delnum()
{
 num=temp;
 return(num);
}

long double adddeci(int getnum)
{
 temp=num;
 if(num-(int)num!=0)
 {
  num=num+getnum*0.01;
 }
 else
  num=num+getnum*0.1;
 return(num);
}

int initmouse()
{
 i.x.ax=0;
 int86(0x33,&i,&o);
 return(o.x.ax);
}

void showptr()
{
  i.x.ax=1;
  int86(0x33,&i,&o);
}

void hideptr()
{
 i.x.ax=2;
 int86(0x33,&i,&o);
}

void restrictptr(int x1,int y1,int x2,int y2)
{
 i.x.ax=7;
 o.x.cx=x1;
 o.x.dx=x2;
 int86(0x33,&i,&o);
 i.x.ax=8;
 o.x.cx=y1;
 o.x.dx=y2;
 int86(0x33,&i,&o);
}

void getmousepos(int *button,int *x,int *y)
{
 i.x.ax=3;
 int86(0x33,&i,&o);
 *button=o.x.bx;
 *x=o.x.cx;
 *y=o.x.dx;
}

void openwindow()
{
 int aa,bb,cc,dd,maxx,maxy,i=10;
 maxx=getmaxx();
 maxy=getmaxy();
 rectangle(0,0,maxx,maxy);
 aa=250;
 bb=400;
 cc=260;
 for(dd=250;dd<350;dd+=20)
 {
  setfillstyle(1,2);
  bar(dd,bb,cc,bb+10);
  cc+=20;
 }
 aa=250;
 bb=400;
 cc=260;
 while(!kbhit())
 {
  setcolor(i);
  outtextxy(20,56,"Don't use more than 16 digit's");
  outtextxy(20,116,"Press any key to continue.......");
  if((aa==350)&&(cc==360))
  {
   aa=250;
   cc=260;
   continue;
  }
  else
  {
   setcolor(10);
   rectangle(aa,bb,cc,bb+10);
   rectangle(aa-1,bb-1,cc+1,bb+11);
  }
  delay(300);
  setcolor(BLACK);
  rectangle(aa,bb,cc,bb+10);
  rectangle(aa-1,bb-1,cc+1,bb+11);
  aa+=20;
  cc+=20;
 }
}

void overandout()
{
 int i8=0;
 clrscr();
 setcolor(0);
 setfillstyle(0,0);
 bar(1,1,639,479);
 for(i8=0;i8<=640;i8++)
 {
  setfillstyle(CLOSE_DOT_FILL,GREEN);
  bar(150+i8,82,530+i8,450);
  bar(510+i8,62,530+i8,345);
  setcolor(0);
  line(150+i8,82,150+i8,450);
  line(510+i8,62,510+i8,345);
  setfillstyle(1,RED);
  bar(130+i8,82,510+i8,430);
  setcolor(0);
  line(130+i8,82,130+i8,430);
  setcolor(RED);
  rectangle(130+i8,52,510+i8,82);
  rectangle(131+i8,53,509+i8,81);
  rectangle(132+i8,54,508+i8,80);
  setcolor(0);
  line(130+i8,52,130+i8,82);
  line(131+i8,53,131+i8,81);
  line(132+i8,54,132+i8,80);
  line(510+i8,52,510+i8,82);
  line(510+i8,52,510+i8,82);
  line(508+i8,54,508+i8,80);
  c=240+i8;
  d=100;
  s=0;
  for(a=0;a<8;a++)
  {
   c=150+i8;
   for(b=0;b<4;b++)
   {
    setfillstyle(1,BLUE);
    bar(c,d,c+70,d+30);
    c+=90;
   }
   d+=40;
  }
 }
 getch();
}

void *buf;
int size,count2=0,px,py,rnd[4][4],correct=0,finish=0;

float octave [7]={130.81,146.83,164.81,174.61,196,220,246.94};

void done()
{
 int i,j;
 mousehide();
 j=0;
 int n;
 for(i=1;i<=15;i++)
 {
  n=random(7);
  sound(octave[n]*4);
  delay(300);
  setfillstyle(1,2);
  bar(42+j,425,68+j,455);
  setfillstyle(1,0);
  bar(68+j,425,72+j,455);
  j=j+29;
 }
 nosound();
 delay(1000);
 for(j=0;j<382;j+=2)
 {
  for(i=0;i<575;i+=2)
  {
   putpixel(26+i,25+j,4);
   putpixel(26+i,460-j,4);
   putpixel(25+j*3/4,28+i*3/4,2);
   putpixel(595-j*3/4,458-i*3/4,2);
   delay(0);
  }
 }
 delay(1000);
 settextstyle(1,0,5);
 setcolor(14);
 delay(500);
 getch();
 if(finish!=1)
  desktop();
 else
  clrscr();
}

void checknum(int mat[4][4])
{
 finish=0;
 correct=0;
 int k=0,i,j;
 for(i=0;i<=3;i++)
 {
  for(j=0;j<=3;j++)
  {
   k++;
   if(k==mat[i][j])
    correct++;
  }
 }
 gotoxy(10,11);
 printf("CORRECT POSITION  ..: %d  ",correct);
 if(correct==15)
 {
  bar(130,40,480,80);
  settextstyle(1,0,4);
  outtextxy(300,60,"CONGRAGULATIONS !");
  finish=1;
  done();
 }
 else
 {
  bar(20,415,480,463);
  j=0;
  for(i=1;i<=correct;i++)
  {
   setfillstyle(1,1);
   bar(42+j,425,68+j,455);
   setfillstyle(1,0);
   bar(68+j,425,72+j,455);
   j=j+29;
  }
 }
}


void  move(int &a,int &b,int &c,int &d,int &w,int &x,int &y,int &z,int &num)
{
 if(a>192 && b>190 && c<403 && d<404)
 {
  sound(600);
  count2++;
  gotoxy(10,9);
  printf("NUMBER OF MOVES..: %d   ",count2);
  mousehide();
  size=imagesize(a,b,c,d);
  free(buf);
  buf=malloc(size);
  getimage(a,b,c,d,buf);
  bar(a,b,c,d);
  putimage(w,x,buf,COPY_PUT);
  w=a;
  x=b;
  y=c;
  z=d;
  if(num==1)
  {
   rnd[px][py]=rnd[px+1][py];
   rnd[px+1][py]=0;
   px++;
  }
  else if(num==2)
  {
   rnd[px][py]=rnd[px-1][py];
   rnd[px-1][py]=0;
   px-=1;
  }
  else if(num==3)
  {
   rnd[px][py]=rnd[px][py+1];
   rnd[px][py+1]=0;
   py++;
  }
  else if(num==4)
  {
   rnd[px][py]=rnd[px][py-1];
   rnd[px][py-1]=0;
   py-=1;
  }
  checknum(rnd);
  callmouse();
  delay(40);
  nosound();
 }
 return ;
}

void game()
{
 int a1,b1,cl,a,b,c,d,w,x,y,z,key,p=0,q=0,overandout=0;
 int g=DETECT,m,ext=0,rst=0,rx,ry,num,i,j;
 initgraph(&g,&m,"c:\\TC\\bgi");
 randomize();
 gotoxy(50,9);
 clrscr();
 do
 {
  finish=0;
  correct=0;
  count2=0;
  if(overandout==1)
  {
   break;
  }
  setcolor(BLACK);
  setfillstyle(0,0);
  bar(1,1,639,479);
  gotoxy(10,9);
  printf("NUMBER OF MOVES..: %d   ",count2);
  gotoxy(10,11);
  printf("CORRECT POSITION ..: %d  ",correct);

  setfillstyle(SOLID_FILL,YELLOW);
  bar(192,190,403,404);
  setfillstyle(SOLID_FILL,BLUE);
  setcolor(15);
  for(j=200;j<360;j+=50)
  {
   for(i=200;i<365;i+=50)
   {
    rectangle(j-1,i-1,j+46,i+46);
    bar(j,i,j+45,i+45);
   }
  }
  settextstyle(1,0,3);
  for(i=0;i<=3;i++)
  {
   for(j=0;j<=3;j++)
   {
    rnd[i][j]=0;
   }

  }
  for(i=0;i<=15;i++)
  {
   do
   {
    rx=random(4);
    ry=random(4);
   }  while(rnd[rx][ry]);
   rnd[rx][ry]=i;
  }
  char ab[10];
  settextjustify(CENTER_TEXT,CENTER_TEXT);
  q=0;
  p=0;
  for(i=0;i<=3;i++)
  {
   for(j=0;j<=3;j++)
   {
    if(rnd[i][j]!=0)
    {
     sprintf(ab,"%d",rnd[i][j]);
     outtextxy(225+p,217+q,ab);
    }
    else
    {
     setfillstyle(1,0);
     px=i;py=j;
     bar(199+p,199+q,247+p,247+q);
     w=199+p;
     x=199+q;
     y=247+p;
     z=247+q;
    }
    p+=50 ;
   }
   p=0;
   q+=50 ;
  }
  bar(130,40,480,80);
  bar(10,425,480,455);
  setfillstyle(SOLID_FILL,RED);
  rectangle(534,374,591,411);
  bar(535,375,590,410);
  outtextxy(561,390,"EXIT");
  rectangle(484,419,591,456);
  bar(485,420,590,455);
  outtextxy(538,433,"SHUFFLE");
  setcolor(4);
  rectangle(10,10,610,470);
  rectangle(15,15,605,465);
  setcolor(14);
  rectangle(12,12,607,467);
  settextstyle(1,0,4);
  outtextxy(300,60,"SHUFFLE GAME");
  line(150,85,450,85);

  j=0;
  delay(1500);
  int n;
  for(i=1;i<=15;i++)
  {
   n=random(7);
   sound(octave[n]*4);
   delay(300);
   setfillstyle(1,2);
   bar(42+j,425,68+j,455);
   setfillstyle(1,0);
   bar(68+j,425,72+j,455);
   j=j+29;
  }
  nosound();
  setfillstyle(SOLID_FILL,0);
  bar(30,425,480,455);
  settextstyle(2,0,5);
  outtextxy(250,425,"YOU CAN USE ARROW BUTTONS OR MOUSE TO MOVE BLOCKS.");
  outtextxy(250,450,"      PRESS ANY KEY TO START.." );

  getch();
  bar(20,415,480,463);
  callmouse();
  do
  {
   gotoxy(10,20);
   mouseposi(a1,b1,cl);
   if(a1>w && a1<y && b1>x+50 && b1<z+50 && (cl&1)==1)
   {
    num=1;
    move(w,x+50,y,z+50,w,x,y,z,num);                   //up
   }
   if(a1>w && a1<y && b1>x-50 && b1<z-50 && (cl&1)==1)
   {
    num=2;
    move(w,x-50,y,z-50,w,x,y,z,num);              //down
   }
   if(a1>w+50 && a1<y+50 && b1>x && b1<z && (cl&1)==1)
   {
    num=3;
    move(w+50,x,y+50,z,w,x,y,z,num);                   //left
   }
   if(a1>w-50 && a1<y-50 && b1>x && b1<z && (cl&1)==1)
   {
    num=4;
    move(w-50,x,y-50,z,w,x,y,z,num);                   //right
   }
   if(kbhit())
   {
    key=getch();
    switch(key)
    {
     case 72:num=1;
	     move(w,x+50,y,z+50,w,x,y,z,num);           //up
	     break;
     case 80:num=2;
	     move(w,x-50,y,z-50,w,x,y,z,num);           //down
	     break;
     case 75:num=3;
	     move(w+50,x,y+50,z,w,x,y,z,num);          //left
	     break;
     case 77:num=4;
	     move(w-50,x,y-50,z,w,x,y,z,num);          //right
	     break;
    }
   }

   if((a1>535 && a1<590 && b1>375 && b1<410 && (cl&1)==1) || key==27)
   {
    done();
    finish=1;
    overandout=1;
   }
   rst=0;
   if(a1>485 && a1<590 && b1>420 && b1<455 && (cl&1)==1 )
    rst=1;
   if(finish==1)
    rst=1;
  } while(rst==0);
 } while(rst!=0);
}

