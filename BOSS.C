
	    /*  * * * * * * * * * * * * * * * * * * * * * * * * * *
		*						  *
		*	          $ I $  B O S S                  *
		*	                            		  *
		*  DEVELOPED BY   :  SIS CORPORATION PRIVATE LTD  *
		*                                		  *
		*  PROGRAMMER     :  SHIVA                        *
		*                                		  *
		*  DATE           :   09-06-2006		  *
		*                                		  *
		* * * * * * * * * * * * * * * * * * * * * * * * * *  */


#include <stdio.h>
#include <conio.h>
#include <direct.h>
#include <dir.h>
#include <dos.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <process.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include <sys\stat.h>

#include "sis.h"
#include "tools.h"
#include "ccp.h"
#include "calc.h"
#include "convert.h"
#include "helpme.h"
#include "calander.h"

void main()
{
  struct ffblk ffblk;
  clock_t start,end;
  char command[100],test[100],loca[100],tempcom[100],cmd;
  int temp=0,dn=0,list=0,len=0,i=0,count=0;
  char tempdrive,tdir[50];
  long ts=0,tm=0,th=0;
  char tfname[50],tcmd[50];
  int check=0;

  clrscr();
  textbackground(0);
  clrscr();

  _setcursortype(_NOCURSOR);


  start = clock();
  startboss:


  sleep(2);
  SIS_TITLE(47,11,"SIS SOFTWARES");
  delay(20);
  SIS_TITLE(42,13,"BOSS");
  getch();

  textcolor(7);
  temp=0;dn=0;list=0;len=0;i=0;count=0;
  ts=0;tm=0;th=0;

   clrscr();
   textbackground(1);
   clrscr();
   textcolor(10);
   gotoxy(27,2);cprintf("Welcome to SIS BOSS...!!!");
   textcolor(7);
   _setcursortype(_NORMALCURSOR);
   check=0;
 do
 {
   getcwd(test,35);
   if(check==1)
   {
    clrscr();
    textbackground(1);
    clrscr();
    textcolor(10);
    gotoxy(27,2);cprintf("******** SIS BOSS ********");
    textcolor(7);
    check=0;
   }
   textcolor(7);
   printf("\n\n");
   textcolor(14);
   cprintf("%s>",test);
   textcolor(7);
   scanf("%s",&tempcom);
   textcolor(7);

   len=strlen(tempcom);
   for(i=0;i<=len;i++)
    command[i]=tolower(tempcom[i]);

   if(strcmp(command,"new")==0)
      newf();
   else if(strcmp(command,"app")==0)
      append();
   else if(strcmp(command,"refresh")==0)
      goto startboss;
   else if(strcmp(command,"execute")==0)
      execute();
   else if(strcmp(command,"open")==0)
      openf();
   else if(strcmp(command,"remove")==0)
     remf();
   else if(strcmp(command,"remsel")==0)
     remsel();
   else if(strcmp(command,"boss_cbm")==0)
      boss_cbm();
   else if(strcmp(command,"boss_lbm")==0)
      boss_lbm();
   else if(strcmp(command,"boss_delfile")==0)
      boss_delfile();
   else if(strcmp(command,"boss_delgroup")==0)
      boss_delgroup();
   else if(strcmp(command,"lsf")==0)
    {
       count=0;
       list = findfirst("*.*",&ffblk,0);
	while (!list)
	{
	   printf("%10s\t", ffblk.ff_name);
	   count++;
	   list = findnext(&ffblk);
	}
	printf("\n\t\tTotal number of files found : %d",count);
    }
   else if(strcmp(command,"exp")==0)
    {
     strcpy(command,"dir");
     system(command);
    }
   else if(strcmp(command,"chdir")==0)
   {
    printf("\nEnter directory name : ");
    scanf("%s",tdir);
    if(chdir(tdir)!=0)
     perror("Error ");
   }
   else if(strcmp(command,"graph")==0)
     system("tree");
   else if(strcmp(command,"advance")==0)
     system("edit");
   else if(strcmp(command,"find")==0)
     searchfile();
   else if((len==1) && (strcmp(command,".")!=0) && (strcmp(command,"/")!=0))
    {
      dn=chdrive(command);
      if (_chdrive(dn+1) == 0)
       printf("\nDrive Successfully changed");
      else
       printf("\nDrive Not Available");
    }
   else if(strcmp(command,"rename")==0)
      renf();
   else if(strcmp(command,"calc")==0) /* ** C A L C U L A T O R ** */
    {
      calcfun();
      check=1;
    }
   else if(strcmp(command,"convert")==0) // CONVERTER
    {
      convert();
      check=1;
    }
   else if(strcmp(command,"time")==0)
      disptime();
   else if(strcmp(command,"setdate")==0)
      chdate();
   else if(strcmp(command,"settime")==0)
      chtime();
   else if(strcmp(command,"copy")==0)
      copyf();
   else if(strcmp(command,"cut")==0)
      cutf();
   else if(strcmp(command,"copyto")==0)
      copyto();
   else if(strcmp(command,"moveto")==0)
      moveto();
   else if(strcmp(command,"autocopy_all")==0)
      autocopy_all();
   else if(strcmp(command,"autocopy_sel")==0)
      autocopy_sel();
   else if(strcmp(command,"autocopyto_all")==0)
      autocopy_to_all();
   else if(strcmp(command,"autocopyto_sel")==0)
      autocopy_to_sel();
   else if(strcmp(command,"paste_all")==0)
      paste_all();
   else if(strcmp(command,"paste")==0)
      pastef();
   else if(strcmp(command,"newdir")==0)
      makedir();
   else if(strcmp(command,"rmdir")==0)
      removedir();
   else if(strcmp(command,"cleardir")==0)
      cleardir();
   else if(strcmp(command,"compile")==0)
    {
     printf("\nEnter C Source file name : ");
     scanf("%s",tfname);
     strcpy(tcmd,strcat("tcc ",tfname));
     system(tcmd);
    }
   else if(strcmp(command,"gfdate")==0)
      gfdate();
   else if(strcmp(command,"space")==0)
      getfreespace();
   else if(strcmp(command,"fstatus")==0)
      getfilemode();
   else if(strcmp(command,"setmode")==0)
      setfilemode();
   else if(strcmp(command,"fsize")==0)
      getfilesize();
   else if(strcmp(command,"check")==0)
      checkfile();
   else if(strcmp(command,"helpme")==0)
    {
      clrscr();
      textbackground(1);
      clrscr();
      textcolor(7);
      printf("\n");
      textcolor(14);
      cprintf("%s>",test);
      textcolor(7);
      bosshelp();
      textcolor(7);
    }
   else if(strcmp(command,"bmi")==0)
    {
      clrscr();
      getcwd(test,35);
      printf("\n\n%s>",test);
      bmi();
    }
   else if(strcmp(command,"calander")==0)
    {
      calander();
      check=1;
      textcolor(7);
    }
   else if(strcmp(command,"emt")==0)
     check=1;
   else if(strcmp(command,"thanks")==0)
    {
     end = clock();
     ts=((end-start)/CLK_TCK);
     tm=ts/60;
     if(tm>=60)
      {
	  th=tm/60;
	  tm=tm%60;
      }
     if(ts>60)
       ts=ts%60;

     printf("\nThe time you used Boss : %ld Hours %ld Minutes %ld Seconds",th,tm,ts);
     printf("\n\n\tYou Are Welcome..!!");
     getch();
     temp=1;
    }
   else if(strcmp(command,".")==0)
     chdir("..");
   else
    {
     if(chdir(command)!=0)
       perror("Command Failed ");
     else
       chdir(command);
    }
 }while(temp!=1);
 exit(0);
}