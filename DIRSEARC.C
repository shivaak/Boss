#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<dir.h>
#include<stdlib.h>
#include <string.h>


void main()
{
  struct find_t ffblk;
  FILE *fp;
  int done;
	  char s[_MAX_PATH];
	  char drive[_MAX_DRIVE];
	  char dir[_MAX_DIR];
	  char file[_MAX_FNAME];
	  char ext[_MAX_EXT];
  clrscr();
  printf("Directory listing of *.\n");
  done = _dos_findfirst("*.",FA_DIREC,&ffblk);
  while (!done)
  {
    printf("\n%s\t", ffblk.name);
    getcwd(s,_MAX_PATH);
      if (s[strlen(s)-1] != '\\')
      strcat(s,"\\");

    strcat(s,ffblk.name);
    _splitpath(s,drive,dir,file,ext);

//  strcpy(ext,".TXT");

    _splitpath(s,drive,dir,file,ext);
    //	if(flags & EXTENSION)
	   printf("\textension: %s",ext);
    done = _dos_findnext(&ffblk);
  }
  getch();
}