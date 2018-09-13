
	   /* * * * * * * * * * * * * * * * * * * * * * * *
	   *    Program Developed By   : Shiva            *
	   *    Program Started Date   : 08-01-08         *
	   *    Program Ended Date     : 10-01-08         *
	   * * * * * * * * * * * * * * * * * * * * * * * */

void main_screen(int mon,int year)
{
 clrscr();
 if((year<10000) && (year>999))
  {
   gotoxy(26,3);textcolor(6);
   cprintf("* * * SIS CALANDER      * * *");
   textcolor(3);gotoxy(45,3);cprintf("%d",year);
  }
 else if(year>9999)
  {
   gotoxy(25,3);textcolor(6);
   cprintf("* * * SIS CALANDER       * * *");
   textcolor(3);gotoxy(44,3);cprintf("%d",year);
  }
 else if((year<1000) && (year>99))
  {
   gotoxy(25,3);textcolor(6);
   cprintf("* * * SIS CALANDER     * * *");
   textcolor(3);gotoxy(44,3);cprintf("%d",year);
  }
 else if((year<100) && (year>9))
  {
   gotoxy(24,3);textcolor(6);
   cprintf("* * * SIS CALANDER    * * *");
   textcolor(3);gotoxy(43,3);cprintf("%d",year);
  }
 else if((year<10) && (year>0))
  {
   gotoxy(24,3);textcolor(6);
   cprintf("* * * SIS CALANDER   * * *");
   textcolor(3);gotoxy(43,3);cprintf("%d",year);
  }
 textcolor(5);gotoxy(15,6);cprintf("MONTH : ");
 textcolor(4);
 gotoxy(15,8);cprintf("SUN     MON     TUE     WED     THU     FRI     SAT");
 textcolor(2);
 if(mon!=12)
  {
    gotoxy(54,15);
    cprintf("NEXT MONTH");
    textcolor(6);cprintf(" >>");
    gotoxy(27,19);
    textcolor(2);cprintf("Go to Last month : ");
    gotoxy(47,19);
    textcolor(6);cprintf("DOWN ARROW");
   }
 if(mon!=1)
  {
    gotoxy(16,15);
    textcolor(6);cprintf("<< ");
    textcolor(2);
    cprintf("PREVIOUS MONTH");
    gotoxy(27,17);
    textcolor(2);cprintf("Go to First month : ");
    gotoxy(47,17);
    textcolor(6);cprintf("UP ARROW");
  }
}

int welcome_screen()
{
 int choice=0;
 clrscr();
 gotoxy(22,3);textcolor(2);
 cprintf("* * * WELCOME TO SIS CALANDER * * *");
 textcolor(3);
 gotoxy(30,5);cprintf(" .GO TO CALANDER");
 gotoxy(30,6);cprintf(" .SELECT-YEAR");
 gotoxy(30,7);cprintf(" .SELECT-MONTH");
 gotoxy(30,8);cprintf(" .ABOUT");
 gotoxy(30,9);cprintf(" .EXIT");
 textcolor(12);
 gotoxy(30,5);cprintf("1");
 gotoxy(30,6);cprintf("2");
 gotoxy(30,7);cprintf("3");
 gotoxy(30,8);cprintf("4");
 gotoxy(30,9);cprintf("5");
 textcolor(4);
 gotoxy(26,11);cprintf("Enter Your Choice(1 to 5) : ");
 scanf("%d",&choice);
 return(choice);
}

int month(int mon,int year)
{
 int totday;
 textcolor(12);
 if(mon==1)
  { gotoxy(23,6); cprintf("JANUARY"); totday=31; }
 else if(mon==2)
  {
    gotoxy(23,6); cprintf("FEBRUARY");
    if(year%4==0)
     totday=29;
    else
     totday=28;
  }
 else if(mon==3)
  { gotoxy(23,6); cprintf("MARCH"); totday=31; }
 else if(mon==4)
  { gotoxy(23,6); cprintf("APRIL"); totday=30; }
 else if(mon==5)
  { gotoxy(23,6); cprintf("MAY"); totday=31; }
 else if(mon==6)
  { gotoxy(23,6); cprintf("JUNE"); totday=30; }
 else if(mon==7)
  { gotoxy(23,6); cprintf("JULY"); totday=31; }
 else if(mon==8)
  { gotoxy(23,6); cprintf("AUGUST"); totday=31; }
 else if(mon==9)
  { gotoxy(23,6); cprintf("SEPTEMBER"); totday=30; }
 else if(mon==10)
  { gotoxy(23,6); cprintf("OCTOBER"); totday=31; }
 else if(mon==11)
  { gotoxy(23,6); cprintf("NOVEMBER"); totday=30; }
 else if(mon==12)
  { gotoxy(23,6); cprintf("DECEMBER"); totday=31; }
  return(totday);
}

int print_date(int x,int daylimit)
{
 int i,t=1,y=9;
 textcolor(13);
 for(i=1;i<=daylimit;i++)
 {
  gotoxy(x,y);
  cprintf("%d",i);
  if(t>=7)
   { t=1; printf("\n"); }
  else
   t++;
     x=x+8;
   if(x>65)
    { x=17; y++; }
 }
 return(x);
}

void display_date(int month_no,int year,int daylimit)
{
    int md=0,i,temp;
    char ch;
    clrscr();
    main_screen(month_no,year);
    daylimit=month(month_no,year);
    md=findmonthday(year);
    md=print_date(md,daylimit);
    do
    {
     getval:
     ch=getch();
     if((ch==77) && (month_no!=12)) //>>
     {
      month_no++;
      main_screen(month_no,year);
      daylimit=month(month_no,year);
      md=print_date(md,daylimit);
     }
     else if((ch==75) && (month_no!=1)) //<<
     {
      month_no--;
      temp=month_no;
      month_no=1;
      md=findmonthday(year);
      for(i=1;i<=temp;i++)
       {
	clrscr();
	main_screen(month_no,year);
	daylimit=month(month_no,year);
	md=print_date(md,daylimit);
	month_no++;
       }
       month_no=temp;
     }
     else if((ch==72) && (month_no!=1))//First month
     {
     main_screen(1,year);
     daylimit=month(1,year);
     md=findmonthday(year);
     md=print_date(md,daylimit);
     month_no=1;
     }
     else if((ch==80) && (month_no!=12))//Last Month
     {
      md=findmonthday(year);
      for(i=1;i<=12;i++)
       {
	clrscr();
	main_screen(i,year);
	daylimit=month(i,year);
	findmonthday(year);
	md=print_date(md,daylimit);
       }
      month_no=12;
     }
     else if(ch==27)
      continue;
     else
      goto getval;
    }while(ch!=27);
}

int findmonthday(int year)
{
 int dayno=0;
 int xday=0;
 xday=findyearday(year);
 dayno=xday;
 return(dayno);
}

int findyearday(int year)
{
 int txday=0,i=0,startyear=0,ys=0;
  for(i=1;i<=year;i++)
   {
     startyear=startyear+1;
     ys=ys+1;
     if((startyear-1)%4==0)
      {
       ys=ys+1;
      /* if((startyear-1)==0)
	  ys=ys-1;*/
      }
     if(ys>7)
      ys=ys-7;
   }
  if(ys==1)
    txday=65;
  else if(ys==2)
    txday=17;
  else if(ys==3)
    txday=25;
  else if(ys==4)
    txday=33;
  else if(ys==5)
    txday=41;
  else if(ys==6)
    txday=49;
  else if(ys==7)
    txday=57;
 return(txday);
}

void about_screen();

void calander()
{
 int month_no=1,daylimit=31,year=1;
 int choice=0,temp=0,i=0,t1=0,x=0;
 char ch;
 clrscr();
 textbackground(0);
 clrscr();
 textcolor(12);
 gotoxy(25,12);
 cprintf("Enter Year : ");
 scanf("%d",&year);
 do
 {
  clrscr();
  choice=welcome_screen();
  switch(choice)
  {
  case 1:
     display_date(month_no,year,daylimit);
    break;

   case 2:
     textcolor(5);
     gotoxy(29,13);cprintf("Enter New Year : ");
     scanf("%d",&temp);
     if(temp<1)
      {
       textcolor(14);
       gotoxy(27,15);
       cprintf("!!!* *INVALID YEAR* *!!!");
       getch();
      }
     else
      {
       textcolor(13);
       gotoxy(29,15);
       year=temp;
       cprintf("Year Changed To %d",year);
       getch();
      }
     month_no=1;
    break;

   case 3:
     textcolor(5);
     gotoxy(29,13);cprintf("Enter The Month : ");
     scanf("%d",&month_no);
     t1=month_no;
     if((month_no<1) || (month_no>12))
      {
       textcolor(14);
       gotoxy(27,15);
       cprintf("!!!* *INVALID MONTH* *!!!");
       getch();
      }
     else
      {
	x=findmonthday(year);
       for(i=1;i<=t1;i++)
	{
	 clrscr();
	 main_screen(i,year);
	 daylimit=month(i,year);
	 findmonthday(year);
	 x=print_date(x,daylimit);
	}
	 month_no=1;
	 getch();
	 clrscr();
      }
    break;

   case 4:
     about_screen();
    break;

   case 5:
     gotoxy(25,13);
     textcolor(13);
     cprintf("Thank You For Using This Program");
     textcolor(7);
     getch();
    break;
   default:
     gotoxy(28,13);
     textcolor(13);
     cprintf("!!!* *INVALID OPTION* *!!!");
     getch();
    break;
  }
 }while(choice!=5);
}

void about_screen()
{
      clrscr();
      textbackground(0);
      clrscr();
      textcolor(4);
      gotoxy(5,5);cprintf("This Program Was Developed By :");

      textcolor(6);
      gotoxy(32,9);cprintf("SIS SOFTWARES");
      gotoxy(34,10);cprintf("NEWYORK");
      gotoxy(28,11);cprintf("UNITED STATES OF AMERICA");
      textcolor(12);
      gotoxy(5,17);cprintf("Website :");
      textcolor(5);
      gotoxy(15,17);cprintf("www.sissoftwares.com");
      textcolor(12);
      gotoxy(40,17);cprintf("E.Mail Us At :");
      textcolor(5);
      gotoxy(55,17);cprintf("sissoftwares@Yahoo.co.in");
      textcolor(7);
      gotoxy(28,24);cprintf(" Copyright@2008-2009");
      getch();
      clrscr();
}