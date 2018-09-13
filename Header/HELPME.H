void space()
{
 textcolor(7);
 printf("\n\t");
 textcolor(12);
}

void screen1() //16 Commands
{
  textcolor(12);
  cprintf("emt                 ==>  clear screen");
  space();
  cprintf("refresh             ==>  to restart the boss freshly");
  space();
  cprintf("new                 ==>  to create new file");
  space();
  cprintf("app                 ==>  to append a file");
  space();
  cprintf("open                ==>  to open a file");
  space();
  cprintf("execute             ==>  to execute exe files");
  space();
  cprintf("advance             ==>  to edit files");
  space();
  cprintf("cut                 ==>  to move a file to boss memory");
  space();
  cprintf("copy                ==>  to copy a file to boss memory");
  space();
  cprintf("paste               ==>  to paste a file *(from boss memory)");
  space();
  cprintf("copyto              ==>  to copy a file to specified location");
  space();
  cprintf("moveto              ==>  to move a file to specified location");
  space();
  cprintf("autocopy_all        ==>  to copy all files in a directory(*to BM)");
  space();
  cprintf("autocopy_sel        ==>  to copy selected files in a directory(*to BM)");
  space();
  cprintf("autocopyto_all      ==>  to copy all files in a directory(*to SL)");
  space();
  cprintf("autocopyto_sel      ==>  to copy selected files in a directory(*to SL)");

  textcolor(7);
  printf("\n\n\t\t");

  textcolor(14);
  cprintf("Press Any Key To Continue...");
  textcolor(7);
  printf("\n\t\t");
  textcolor(13);
  cprintf("Press ESC To Cancel...");
}

void screen2() //16 Commands
{
    clrscr();
    textcolor(7);
    printf("\t");
    textcolor(14);
    cprintf("\nContinues...");
    textcolor(7);
    printf("\n\n\t");
    textcolor(12);
    cprintf("automove_all        ==>  to move all files in a directory(*to BM)");
    space();
    cprintf("automove_sel        ==>  to move selected files in a directory(*to BM)");
    space();
    cprintf("automoveto_all      ==>  to move all files in a directory(*to SL)");
    space();
    cprintf("automoveto_sel      ==>  to move selected files in a directory(*to SL)");
    space();
    cprintf("paste_all           ==>  to paste group os files");
    space();
    cprintf("rename              ==>  to rename a file");
    space();
    cprintf("remove              ==>  to remove a file");
    space();
    cprintf("newdir              ==>  create a new directory");
    space();
    cprintf("rmdir               ==>  to remove a directory");
    space();
    cprintf("cleardir            ==>  to delete all files in a directory");
    space();
    cprintf("lsf                 ==>  to list all files");
    space();
    cprintf("exp</p/s/w");
    space();
    cprintf("    /l/od/on>       ==>  to list all files and directories");
    space();
    cprintf("graph               ==>  to view the dir's in different format");
    space();
    cprintf("chdir               ==>  to change directory(* use only in needed time)");
    space();
    cprintf("find                ==>  to search specified file");
    space();
    cprintf("calander            ==>  to see sis calander");

    textcolor(7);
    printf("\n\n\t\t");

  textcolor(14);
  cprintf("Press Any Key To Continue...");
  textcolor(7);
  printf("\n\t\t");
  textcolor(13);
  cprintf("Press ESC To Cancel...");
}

void screen3() //incomplete
{
 clrscr();
 textcolor(7);
 printf("\t");
 textcolor(14);
 cprintf("\nContinues...");
 textcolor(7);
 printf("\n\n\t");
 textcolor(12);

    cprintf("calc                ==>  to use sis calculator");
    space();
    cprintf("convert             ==>  to use sis converter");
    space();
    cprintf("time                ==>  to view time & date");
    space();
    cprintf("setdate             ==>  to set system date");
    space();
    cprintf("settime             ==>  to set system time");
    space();
    cprintf("boss_lbm            ==>  to list boss memory");
    space();
    cprintf("boss_delfile        ==>  to delete a file in boss memory");
    space();
    cprintf("boss_cbm            ==>  to clear boss memory");
    space();
    cprintf("fstatus             ==>  to check file status");
    space();
    cprintf("fsize               ==>  to view file size");
    space();
    cprintf("check               ==>  to check the availability of the file");
    space();
    cprintf("gfdate              ==>  to see the file created date");
    space();
    cprintf("space               ==>  to see unused memory in current drive");
    space();
    cprintf("bmi                 ==>  body mass index");
    space();
    cprintf("helpme              ==>  help");
    space();
    cprintf("about               ==>  About *Boss*");
    space();
    cprintf("thanks              ==>  exit from my BOSS");
}

void cancel()
{
 textcolor(7);
 printf("\n\t\t");

    textcolor(4);
    cprintf("Cancelled..!!");
}

void bosshelp()
{
  char ch;
  textcolor(7);
  printf("\n\t\t\t");

  textcolor(10);
  cprintf("Your Boss Will Help You");

  textcolor(7);
  printf("\n\n\t");
  screen1();
  ch=getch();
  if(ch!=27)
   {
    screen2();
     ch=getch();
      if(ch!=27)
       {
	screen3();
	textcolor(7);
	printf("\n\n\t\t-------------- END --------------");
       }
      else
       cancel();
   }
  else
   cancel();
  textcolor(7);
}