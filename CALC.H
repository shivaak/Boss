/* CALC FUNCTIONS */
/*
void add();
void sub();
void mul();
void div();
void square();
void root();
void power();
void absval();
void logval();
void log10val();
void sinval();
void cosval();
void tanval();
*/

#include<stdlib.h>

void add()
{
 float a,b,c;
 gotoxy(15,15);printf("Enter a value : ");
 scanf("%f",&a);
 gotoxy(15,16);printf("Enter b value : ");
 scanf("%f",&b);
 c=a+b;
 gotoxy(15,17);printf("Value of %f+%f  = %f",a,b,c);
 getch();
}

void sub()
{
 float a,b,c;
 gotoxy(15,15);printf("Enter a value : ");
 scanf("%f",&a);
 gotoxy(15,16);printf("Enter b value : ");
 scanf("%f",&b);
 c=a-b;
 gotoxy(15,17);printf("Value of %f-%f  = %f",a,b,c);
 getch();
}

void mul()
{
 float a,b,c;
 gotoxy(15,15);printf("Enter a value : ");
 scanf("%f",&a);
 gotoxy(15,16);printf("Enter b value : ");
 scanf("%f",&b);
 c=a*b;
 gotoxy(15,17);printf("Value of %f*%f  = %f",a,b,c);
 getch();
}

void divide()
{
 float a,b,c;
 int rem,ra,rb,rc;
 gotoxy(15,15);printf("Enter a value : ");
 scanf("%f",&a);
 gotoxy(15,16);printf("Enter b value : ");
 scanf("%f",&b);
 gotoxy(15,18);printf("Approximate value : ");
 ra=a;
 rb=b;
 rc=a/b;
 rem=ra%rb;
 gotoxy(15,19);printf("Value of %d/%d  = %d",ra,rb,rc);
 gotoxy(15,20);printf("Remainder  = %d",rem);

 gotoxy(15,22);printf("Accurate value : ");
 c=a/b;
 gotoxy(15,23);printf("Value of %f/%f  = %f",a,b,c);
 getch();
}

void square()
{
 float a;
 gotoxy(15,15);printf("Enter a value : ");
 scanf("%f",&a);
 gotoxy(15,17);printf("Square of %f  = %f",a,a*a);
 getch();
}

void root()
{
 double a;
 gotoxy(15,15);printf("Enter a value      : ");
 scanf("%lf",&a);
 gotoxy(15,17);printf("Square Root of %lf  = %lf",a,sqrt(a));
 getch();
}

void power()
{
 double a,b,c;
 gotoxy(15,15);printf("Enter a value : ");
 scanf("%lf",&a);
 gotoxy(15,16);printf("Enter b value : ");
 scanf("%lf",&b);
 c=pow(a,b);
 gotoxy(15,17);printf("Value of %lf^%lf = %lf",a,b,c);
 getch();

}

void absval()
{
 int a;
 gotoxy(15,15);printf("Enter value : ");
 scanf("%d",&a);
 gotoxy(15,17);printf("Absolute value of %d  = %d",a,abs(a));
 getch();
}

void logval()
{
 double a;
 gotoxy(15,15);printf("Enter value : ");
 scanf("%lf",&a);
 gotoxy(15,17);printf("Natural Log of %lf = %lf",a,log(a));
 getch();
}

void log10val()
{
 double a;
 gotoxy(15,15);printf("Enter value : ");
 scanf("%lf",&a);
 gotoxy(15,17);printf("Common Log of %lf = %lf",a,log10(a));
 getch();
}

void sinval()
{
 double a;
 gotoxy(15,15);printf("Enter value : ");
 scanf("%lf",&a);
 gotoxy(15,17);printf("Sin value of %lf = %lf",a,sin(a));
 getch();
}

void cosval()
{
 double a;
 gotoxy(15,15);printf("Enter value : ");
 scanf("%lf",&a);
 gotoxy(15,17);printf("Cos value of %lf = %lf",a,cos(a));
 getch();
}

void tanval()
{
 double a;
 gotoxy(15,15);printf("Enter value : ");
 scanf("%lf",&a);
 gotoxy(15,17);printf("Tan value of %lf = %lf",a,tan(a));
 getch();
}


void calcfun()
{
 int ch;
 char test[100];
 clrscr();
 textbackground(0);
 clrscr();
 do
 {
  clrscr();
  getcwd(test,35);
  printf("\n\n");
  textcolor(14);
  cprintf("%s>",test);
  textcolor(7);
  gotoxy(18,3);printf("SIS CALCULATOR");

  gotoxy(12,5); printf("1.Addition");
  gotoxy(12,6); printf("2.Subraction");
  gotoxy(12,7); printf("3.Multipication");
  gotoxy(12,8); printf("4.Division");
  gotoxy(12,9); printf("5.Square");
  gotoxy(12,10);printf("6.Square Root");
  gotoxy(12,11);printf("7.Power");
  gotoxy(32,5); printf("8.ABS");
  gotoxy(32,6); printf("9.Natural Log");
  gotoxy(32,7);  printf("10.Common Logarithm");
  gotoxy(32,8); printf("11.Sin");
  gotoxy(32,9); printf("12.Cos");
  gotoxy(32,10);printf("13.Tan");
  gotoxy(32,11);printf("14.Cancel");

  gotoxy(15,13);printf("Enter Your Choice : ");
  scanf("%d",&ch);

  switch(ch)
   {
    case 1:
	add();
      break;
    case 2:
	sub();
      break;
    case 3:
	mul();
      break;
    case 4:
	divide();
      break;
    case 5:
	square();
      break;
    case 6:
	root();
      break;
    case 7:
	power();
      break;
    case 8:
	absval();
      break;
    case 9:
	logval();
      break;
    case 10:
	log10val();
      break;
    case 11:
	sinval();
      break;
    case 12:
	cosval();
      break;
    case 13:
	tanval();
      break;
    case 14:
      break;
    default:
      gotoxy(18,15);printf("Wrong choice");
      getch();
      break;
   }

 }while(ch!=14);
}
