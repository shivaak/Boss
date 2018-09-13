#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>

void FTEXT(int x,int y,int forecolor,int time,char ch)
{
 gotoxy(x,y);
 textcolor(forecolor);
 cprintf("%c",ch);
 delay(time);
}

void STEXT(int x,int y,int fc1,int fc2,int time,char ch)
{
 gotoxy(x,y);
 textcolor(fc1);
 cprintf("%c",ch);
 delay(time);

 gotoxy(x,y);
 textcolor(fc2);
 cprintf("%c",ch);
 delay(time);
}

void SIS_TITLE(int x,int y,char word[])
{
 int bx=0,by=0;
 int tx=0,tc;
 int tdelay=50;
 int c=15;
 int c1,c2;
 int i=0,len=0,tlen;

 by=y;
 len=strlen(word);
 tlen=len;
 len--;
   _setcursortype(_NOCURSOR);

 while(len>=0)
 {
  FTEXT(x,y,c,tdelay,word[len]);
   FTEXT(x,y,0,tdelay,' ');
  x--;
  len--;
 }
 tx=x;
 bx=x;
       /* -------- End of forst step -------- */
 c1=15; c2=8;
 while(i!=tlen)
 {
  STEXT(x,y,c1,c2,tdelay,word[i]);
  x++;
  i++;
 }
       /* ----------*/
 x=tx; c=15; tc=8; i=0;
 while(i!=tlen)
 {
  FTEXT(x,y,c,tdelay,word[i]);
  FTEXT(x,y,tc,tdelay,word[i]);
  x++;
  i++;
 }
 delay(75);
// clrscr();
 textcolor(15);
 gotoxy(bx,by);
 cprintf("%s",word);
 delay(120);
 textcolor(8);
 gotoxy(bx,by);
 cprintf("%s",word);
}