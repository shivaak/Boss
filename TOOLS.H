char bossloc1[]={"boss"};
char bossloc2[]={"custom"};
int bossdrive=4; // e:

void gfdate()
{
   struct ftime ft;
   FILE *stream;
   char *name;
    printf("\nEnter The Name Of Your File : ");
    scanf("%s",name);

   if((stream = fopen(name,"rb"))==NULL)
   {
      fprintf(stderr, "Cannot open the file.\n");
   }
   else
   {
     getftime(fileno(stream), &ft);
     printf("File time: %u:%u:%u\n",ft.ft_hour,ft.ft_min,ft.ft_tsec * 2);
     printf("File date: %u/%u/%u\n",ft.ft_month,ft.ft_day,ft.ft_year+1980);
   }
   fclose(stream);
}

void renf()
{
   char *renf,*nrenf,*old;
   FILE *fp;
   int check=0;

   printf("\nEnter The Name Of Your File : ");
   scanf("%s",renf);
   strcpy(old,renf);
   fp=fopen(renf,"rb");
   if(fp==NULL)
    {
      printf("\nFile Not Found..!!");
      fclose(fp);
    }
   else
    {
     printf("\nEnter The New Name Of Your File : ");
     scanf("%s",nrenf);
     fclose(fp);
     fp=fopen(nrenf,"r");
     if(fp==NULL)
       check=1;
     if(check!=1)
      printf("\nFile name already exists..!!");
     else
      {
       rename(renf,nrenf);
       printf("\nRenamed %s to %s \n",old,nrenf);
      }
      fclose(fp);
    }
}

void remf()
{
  char *name1,ch;
  FILE *fp;

  printf("\nEnter The Name Of The File You Want To Delete : ");
  scanf("%s",name1);
  fp=fopen(name1,"rb");
  if(fp==NULL)
   {
    printf("\nFile Not Found..!!");
    fclose(fp);
   }
  else
   {
    printf("\n\nAre You Sure You Want To Delete(y/n) : ");
    getval:
    ch=getch();
    if((ch=='y') || (ch=='Y'))
    {
      fclose(fp);
      remove(name1);
      printf("\nFile Deleted..!!");

    }
    else if((ch=='n') || (ch=='N'))
     printf("\nFile Not Deleted..!!");
    else
     goto getval;
   }
}

void remsel()
{
  struct find_t ffblk;
  int done,check=0;
  char ch;
  FILE *fp;
  printf("\nSearching for files...\n");
  done = _dos_findfirst("*.*",FA_DIREC,&ffblk);
  while (!done)
  {
    fp=fopen(ffblk.name,"r");
    if(fp==NULL)
    {
     printf("\nDo you want to remove the DIRECTORY '%s' (y/n/c): ", ffblk.name);
     check=1;
    }
    else
    {
     printf("\nDo you want to remove the FILE '%s' (y/n/c): ", ffblk.name);
     check=0;
    }
     fclose(fp);
     getremselval:
     ch=getch();
     ch=tolower(ch);
     if((ch!='y') && (ch!='n') && (ch!='c'))
       goto getremselval;
     printf("%c",ch);

     if(ch=='y')
     {
	if(check==1)
	{
	   rmdir(ffblk.name);
	   printf("\nDirectory Deleted..!!");
	}
	else if(check==0)
	{
	   remove(ffblk.name);
	   printf("\nFile Deleted..!!");
	}
     }
     else if(ch=='n')
       printf("\nNot Deleted..!!");
     else if(ch=='c')
     {
       printf("\nCancelled..!!");
       goto outremsel;
     }
     done = _dos_findnext(&ffblk);
  }
  outremsel:
}
void openf()
{
   int y=4,lines=0;
   char *openf;
   int ch;
   FILE *fp;

   printf("\n\nEnter The Name Of The File You Want To Open : ");
   scanf("%s",openf);
    y=wherey();
    if(y>22)
     y=0;
   fp=fopen(openf,"rb");
   if(fp==NULL)
     printf("\nFile Not Found");
   else
    {
     while((ch=getc(fp))!=EOF)
      {
       if(ch=='\n')
	{
	 y++;
	 lines++;
	}
       if(y>=22)
	{
	 printf("\n\t\tPress any key to continue..!!");
	 printf("\n\t\tPress ESC key to cancel..!!");
	 ch=getch();
	 if(ch==27)
	  {
	   printf("\nCancelled..!!");
	   break;
	  }
	 else
	  {
	   clrscr();
	   printf("Continues..!!\n\n");
	   y=3;
	  }
	}
       printf("%c",ch);
      }
     fclose(fp);
     getch();
     printf("\n\t----------------- END OF FILE -----------------");
     printf("\n\t\t\tTotal no of lines : %d",lines);
    }
}

void newf()
{
  int ch;
  char name[50];
  char *p;
  FILE *fp;

  printf("\n\nFor Saving Your Texts...Please Press...\"F6\"");
  getch();
  printf("\n\nEnter The Name Of The File : ");
  scanf("%s",name);
  printf("\n");

  p=searchpath(name);

  if(p!=0)
   {
    printf("File already exist..!!");
    getch();
   }
  else
   {
    fp=fopen(name,"wb");
     if(fp==NULL)
      {
       printf("\nError..!!");
       getch();
      }
      while((ch=getchar())!=EOF)
	putc(ch,fp);
    fclose(fp);
    printf("\n\nFile Saved...!!!");
    getch();
   }
}

void append()
{
  char ch;
  char *name;
  char *p;
  FILE *fp;

  printf("\n\nFor Saving Your Texts...Please Press...\"F6\"");

  printf("\n\nEnter The Name Of The File : ");
  scanf("%s",name);
  printf("\n");

  fp=fopen(name,"rb");
   if(fp==NULL)
     printf("File Not Found..!!");
   else
    {
     while((ch=getc(fp))!=EOF)
       printf("%c",ch);
     fclose(fp);
    }

  fp=fopen(name,"a");
     if(fp==NULL)
      {
       printf("\nError..Cannot Append..!!");
      }
     else
      {
	while((ch=getchar())!=EOF)
	   putc(ch,fp);
	printf("\n\nFile Saved...!!!");
      }
    fclose(fp);
}

void makedir()
{
   int stat;
   char *dirname;

   printf("\nEnter The Directory Name : ");
   scanf("%s",dirname);

   stat = mkdir(dirname);
   if(!stat)
      printf("\nDirectory created");
   else
      printf("\nUnable to create directory");
}

void removedir()
{
   int stat=0;
   char dirname[30];
   char ch;

   printf("\nEnter The Directory Name : ");
   scanf("%s",dirname);

   printf("\n\nAre You Sure You Want To Delete(y/n) : ");
   ch=getch();
   if((ch=='y') || (ch=='Y'))
    {
     stat=rmdir(dirname);
     if(!stat)
      printf("\nDirectory Deleted..!!");
     else
      perror("\nUnable to delete directory..!!");
    }
   else
     printf("\nDirectory Not Deleted..!!");
    getch();
}

void cleardir()
{
 struct ffblk ffblk;
 char name[100];
 int count=0,list=0;
 int disk,ch;
 char t;
   printf("\nDelete Files(Not including Subdirectories)...");
   topdel:
   printf("Are You Sure... (y/n)??");
   t=getche();
   t=tolower(t);
   if(t=='y')
   {
    printf("\nPlease Wait.. Preparing to Delete ..");
    count=0;
	list = findfirst("*.*",&ffblk,0);
	while (!list)
	{
	   count++;
	   list = findnext(&ffblk);
	}
     printf("\n\nTotal number of files found : %d",count);
     printf("\n\nBoss Is Now Ready To Delete.. Press Any Key To Start..");
     getch();
     count=0;
     list=0;
	list = findfirst("*.*",&ffblk,0);
	while (!list)
	{
	   count++;
	   printf("\n\nFile Number %d : %s ",count,ffblk.ff_name);
	   strcpy(name,ffblk.ff_name);
	   remove(name);
	   printf("\nDELETED..");
	   list = findnext(&ffblk);
	}
	printf("\nDirectory Cleaned..");
   }
   else if(t=='n')
   {
    printf("\nNo File Deleted..");
   }
   else
   {
    printf("\nWrong Choce..press y or n only..");
    goto topdel;
   }
   outside:
   getch();

}

void disptime()
{
 time_t t;
 printf("\n");
 time(&t);
 printf("%s",ctime(&t));
}

void bmi()
{
  float weight=0,height=0,res,ans,meter;

  gotoxy(30,6);printf("Body Mass Index");

  gotoxy(20,8);printf("Enter You Body Weight(in kg) : ");
  scanf("%f",&weight);

  gotoxy(20,10);printf("Enter You Body Height(in cms) : ");
  scanf("%f",&height);

  meter=height/100;
  ans=meter*meter;

  res=weight/ans;
  gotoxy(20,12);printf("Your Body BMI is : %.2f",res);

  if(res<10)
   {    gotoxy(20,14);printf("You Are Health Less"); }
  if((res>=10) && (res<20))
   {    gotoxy(20,14);printf("You Are Slim"); }
  else if((res>=20) && (res<25))
   {    gotoxy(20,14);printf("You Are Ideal Weight"); }
  else if((res>=25) && (res<30))
   {    gotoxy(20,14);printf("You Are Over Weight"); }
  else if(res>=30)
   {    gotoxy(20,14);printf("You Are Obesity"); }

  getch();
}

int chdrive(char drive[30])
{
   char ch[26];
   int t=65;
   int drive_no=0,len,i;
   len=strlen(drive);
     for(i=0;i<=len;i++)
       drive[i]=toupper(drive[i]);
   for(i=1;i<=26;i++) // Storing ABCD...Z
    {
     ch[i]=toascii(t);
     t++;
    }
   for(i=1;i<=26;i++)
    {
     if(ch[i]==drive[0])
      return(drive_no);
     else
      drive_no++;
    }
    return(drive_no);
}

void searchfile()
{
 char *p;
 char *sf;
  printf("\nEnter The Name Of Your File : ");
  scanf("%s",sf);
  p = searchpath(sf);
  if(!p)
   perror("\nError ");
  else
   printf("\n%s",p);
}

void boss_cbm()
{
 struct ffblk ffblk;
 int list=0;
 char ch;
   char directory[100];
   int disk;

   disk=getdisk();
   getcwd(directory,35);

       setdisk(bossdrive);
       chdir("/");
       chdir(bossloc1);
       chdir(bossloc2);

      printf("\n\nAre You Sure You Want To Clear Boss Memory(y/n) : ");
      getclsval:
      ch=getch();
      if((ch=='y') || (ch=='Y'))
       {
	list = findfirst("*.*",&ffblk,0);
	while (!list)
	{
	   remove(ffblk.ff_name);
	   list = findnext(&ffblk);
	}
	printf("\n\n\tBoss Memory Cleared..!!");
       }
      else if((ch=='n') || (ch=='N'))
       printf("\n\tBoss Memory Not Cleared..!!");
      else
	goto getclsval;
      setdisk(disk);
      chdir(directory);

}

void boss_delfile()
{
 char directory[100];
 int disk;
   disk=getdisk();
   getcwd(directory,35);

       setdisk(bossdrive);
       chdir("/");
       chdir(bossloc1);
       chdir(bossloc2);
	  remf();
       setdisk(disk);
       chdir(directory);
}

void boss_delgroup()
{
 struct ffblk ffblk;
 char directory[100],code[100],name[100],t;
 int disk,list=0;
   disk=getdisk();
   getcwd(directory,35);

   setdisk(bossdrive);
   chdir("/");
   chdir(bossloc1);
   chdir(bossloc2);

   printf("\nEnter Code : ");
   scanf("%s",code);
   if(chdir(code)!=0)
   {
    printf("\nCode Error.. Code Does Not Exists..");
    goto outofdelgroup;
   }
   else
   {
    topdelgroup:
    printf("\nAre You Sure... (y/n)??");
    t=getche();
    t=tolower(t);
    if(t=='y')
    {
     printf("\nPlease Wait.. Deleting Files ..");
	list = findfirst("*.*",&ffblk,0);
	while (!list)
	{
	   strcpy(name,ffblk.ff_name);
	   remove(name);
	   list = findnext(&ffblk);
	}
	chdir("..");
	rmdir(code);
	printf("\nGroup Deleted..");
   }
   else if(t=='n')
   {
    printf("\nGroup Does Not Deleted..");
   }
   else
   {
    printf("\nWrong Choce..press y or n only..");
    goto topdelgroup;
   }
   }
   outofdelgroup:
   setdisk(disk);
   chdir("/");
   chdir(directory);
}

void boss_lbm()
{
 struct ffblk ffblk;
 int list=0,count=0;
   char directory[100];
   int disk;

   disk=getdisk();
   getcwd(directory,35);

       setdisk(bossdrive);
       chdir("/");
       chdir(bossloc1);
       chdir(bossloc2);

       list = findfirst("*.*",&ffblk,0);
       count=0;
	while (!list)
	{
	   count++;
	   printf("%10s\t", ffblk.ff_name);
	   list = findnext(&ffblk);
	}
	printf("\n\n\tTotal number of files found : %d",count);
      setdisk(disk);
      chdir(directory);
}

void getfreespace()
{
   struct dfree free;
   long avail;
   int drive;

   drive = getdisk();
   getdfree(drive+1, &free);
   if (free.df_sclus == 0xFFFF)
      printf("Error in getdfree() call\n");
   else
   {
     avail =  (long) free.df_avail
	    * (long) free.df_bsec
	    * (long) free.df_sclus;
     printf("Drive %c: has %ld bytes available\n", 'A' + drive, avail);
   }
}

void getfilemode()
{
  struct stat statbuf;
  char filename[128];
  unsigned attrib;
  FILE *fp;
  printf("\nEnter the file name:");
  scanf("%s", filename);
  if (_dos_getfileattr(filename,&attrib) != 0)
    perror("\nUnable to obtain file attributes");
  else if (attrib & _A_RDONLY)
    printf("%s is read-only.\n", filename);
  else if (attrib & _A_HIDDEN)
    printf("%s is hidden.\n", filename);
  else if (attrib & _A_SYSTEM)
    printf("%s is a system file.\n", filename);
  else if (attrib & _A_VOLID)
    printf("%s is a volume label.\n", filename);
  else if (attrib & _A_SUBDIR)
    printf("%s is a directory.\n", filename);
  else if (attrib & _A_ARCH)
    printf("%s is an archive file.\n", filename);

    fp=fopen(filename,"r");
  if(fp==NULL)
   fprintf(stderr, "Cannot open output file.\n");
  else
   {
    stat(filename, &statbuf);
    /* display the information returned */
    if(statbuf.st_mode & S_IFCHR)
      printf("Handle refers to a device.\n");
    if(statbuf.st_mode & S_IFREG)
      printf("Handle refers to an ordinary file.\n");
    if(statbuf.st_mode & S_IREAD)
      printf("User has read permission on file.\n");
    if(statbuf.st_mode & S_IWRITE)
      printf("User has write permission on file.\n");

     printf("Drive letter of file  : %c\n", 'A'+statbuf.st_dev);
     printf("Size of file in bytes : %ld\n", statbuf.st_size);
     printf("Time of file creation : %s\n", ctime(&statbuf.st_ctime));
   }
   fclose(fp);
}

void setfilemode()
{
 char filename[128];
 char mode;
 unsigned attrib;
 printf("Enter a file name:");
 scanf("%s", filename);
 if(_dos_getfileattr(filename,&attrib) != 0)
   perror("Unable to obtain file attributes");
 else
 {
  printf("\n");
  printf("MODE\n");
  printf("a  --> make the archive\n");
  printf("r  --> make the readonly\n");
  printf("w --> make the read & write\n");
  printf("h  --> make the hidden\n");
  printf("Enter a mode:");
  mode=getche();
  printf("\n");
  mode=tolower(mode);
  switch(mode)
   {
    case 'w':
	 attrib &= ~_A_RDONLY;
	printf("%s file now read-write.\n", filename);
      break;
    case 'r':
	attrib |= _A_RDONLY;
	printf("%s file now read-only.\n", filename);
      break;
    case 'h':
	attrib |= _A_HIDDEN;
	printf("%s file is now hidden.\n", filename);
      break;
    case 'a':
	attrib |= _A_ARCH;
	printf("%s file is now archive.\n", filename);
      break;
    default:
	printf("Incorrect Mode..!!");
      break;
   }
 }
}

void chdate()
{
 struct dosdate_t reset;
 int day,month,year;
 printf("\nEnter Day   : ");
 scanf("%d",&day);
 printf("\nEnter Month : ");
 scanf("%d",&month);
 printf("\nEnter Year  : ");
 scanf("%d",&year);
 reset.year  = year;
 reset.day   = day;
 reset.month = month;
 _dos_setdate(&reset);
 system("date");
 printf("\nDate Changed");
}

void chtime()
{
 struct dostime_t reset;
 printf("\nEnter Hour : ");
 scanf("%d",&reset.hour);
 printf("\nEnter Minute : ");
 scanf("%d",&reset.minute);
 printf("\nEnter Second  : ");
 scanf("%d",&reset.second);
 reset.hsecond = 0;
  _dos_settime(&reset);
  system("time");
 printf("\nTime Changed");
}

void getfilesize()
{
 int handle;
 char *name;

 printf("\nEnter The Name Of Your File : ");
 scanf("%s",name);
 handle=open(name,O_RDWR);
 if(handle==-1)
  perror("\nError ");
 else
 printf("\nFile length : %ld bytes", filelength(handle));
 close(handle);
}

void checkfile()
{
 char *name;

 printf("\nEnter The Name Of Your File : ");
 scanf("%s",name);
 if(access(name,0) == 0)
   printf("\nFile Available..!!");
 else
   printf("\nFile Not Available..!!");
}

void execute()
{
   char *exe;
   int i;

   printf("\n\nEnter The  name of the EXE file: ");
   scanf("%s",exe);
   for(i=0;i<=strlen(exe);i++)
    exe[i]=tolower(exe[i]);
   if(   (strcmp(exe,"tree")!=0)  && (strcmp(exe,"edit")!=0)
      && (strcmp(exe,"copy")!=0)  && (strcmp(exe,"move")!=0)
      && (strcmp(exe,"dir")!=0)   && (strcmp(exe,"type")!=0)
      && (strcmp(exe,"date")!=0)  && (strcmp(exe,"time")!=0)
      && (strcmp(exe,"rename")!=0)&& (strcmp(exe,"ren")!=0)
      && (strcmp(exe,"remove")!=0)&& (strcmp(exe,"rd")!=0)
      && (strcmp(exe,"attrib")!=0)&& (strcmp(exe,"cls")!=0)
      && ( strcmp(exe,"exit")!=0) && (strcmp(exe,"deltree")!=0))
		system(exe);
   else
      printf("\nExecute error : No Such Files..!!");
}