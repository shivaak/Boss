/*char bossloc1[]={"boss"};
char bossloc2[]={"custom"};
int bossdrive=4; // e:*/

void copyf()
{
   char *name,*name1;
   int ch;
   char directory[100];
   int disk;

   FILE *fp,*ft;

   printf("\nEnter Name Of The File : ");
   scanf("%s",name);

   disk=getdisk();
   getcwd(directory,35);

   fp=fopen(name,"rb");
   if(fp==NULL)
    printf("\nFile Not Found..!!");
   else
   {
    printf("\nEnter New File Name    : ");
    scanf("%s",name1);
       setdisk(bossdrive);
       chdir("/");
       chdir(bossloc1);
       chdir(bossloc2);
      ft=fopen(name1,"rb");
      if(ft==NULL)
      {
	fclose(ft);
	printf("\nPlease Wait..!!");
	ft=fopen(name1,"wb");
	while((ch=getc(fp))!=EOF)
	 putc(ch,ft);
	 printf("\nFile Copied to Boss Memory..!!");
	fclose(ft);
      }
     else
      {
       printf("\nUnable to copy the file.. New file name already in the boss memory..!!");
      }
      fclose(fp);
      setdisk(disk);
      chdir(directory);
   }
   getch();
}

void cutf()
{
   char *name;
   int ch;
   char directory[100];
   int disk;

   FILE *fp,*ft;
   disk=getdisk();
   getcwd(directory,35);

   printf("\nEnter Name Of The File : ");
   scanf("%s",name);

   fp=fopen(name,"rb");

   if(fp==NULL)
     printf("\nFile Not Found..!!");
   else
    {
       setdisk(bossdrive);
       chdir("/");
       chdir(bossloc1);
       chdir(bossloc2);
      ft=fopen(name,"rb");
      if(ft==NULL)
      {
       fclose(ft);
       cut:
       printf("\nPlease Wait..!!");
       ft=fopen(name,"wb");
       while((ch=getc(fp))!=EOF)
	 putc(ch,ft);
	fclose(ft);
	setdisk(disk);
	chdir(directory);
	remove(name);
	printf("\nFile Moved to Boss Memory..!!");
      }
      else
      {
       fclose(ft);
       printf("\nFile name already in Boss Memory..!!");
       printf("\nDo you want to overwrite the file(y/n) : ");
       valofcut:
       ch=getch();
       if((ch=='y') || (ch=='Y'))
	goto cut;
       else if((ch=='n') || (ch=='N'))
	{
	 printf("\nFile does not moved..!!");
	 setdisk(disk);
	 chdir(directory);
	 goto cancelcut;
	}
       else
	goto valofcut;
      }
       cancelcut:
       fclose(fp);
    }
   getch();
}

void pastef()
{
   char *name,*newname;
   int ch;
   char directory[100];
   char directory1[100];
   int disk;

   FILE *fp,*ft;

   disk=getdisk();
   getcwd(directory,35);

       setdisk(bossdrive);
       chdir("/");
       chdir(bossloc1);
       chdir(bossloc2);
       getcwd(directory1,35);

   printf("\nEnter Name Of The File : ");
   scanf("%s",name);

   fp=fopen(name,"rb");

   if(fp==NULL)
    {
     printf("\nFile Not Found..!!");
     setdisk(disk);
     chdir(directory);
    }
   else
    {
       setdisk(disk);
       chdir(directory);
      printf("\nEnter New Name Of The File : ");
      scanf("%s",newname);
      ft=fopen(newname,"rb");
      if(ft==NULL)
      {
       fclose(ft);
       paste:
       printf("\nPlease Wait..!!");
       ft=fopen(newname,"wb");
       while((ch=getc(fp))!=EOF)
	 putc(ch,ft);
       printf("\nFile Transferred From Boss Memory..!!");
       fclose(ft);
      }
      else
      {
       fclose(ft);
       printf("\nNew file name already exists..!!");
       printf("\nDo you want to overwrite the file(y/n) : ");
       valofpaste:
       ch=getch();
       if((ch=='y') || (ch=='Y'))
	goto paste;
       else if((ch=='n') || (ch=='N'))
	{
	 printf("\nFile does not pasted..!!");
	 goto cancelpaste;
	}
       else
	goto valofpaste;
      }
      cancelpaste:
      fclose(fp);
    }
   getch();
}

void copyto()
{
   char name[50],name1[50];
   int ch,check=0;
   char directory[100];
   int disk,dn;
   char *cd;  //,countdir=0;
   char subdirname[50],d;

   FILE *fp,*ft;

   printf("\nEnter Name Of The File : ");
   scanf("%s",name);

   disk=getdisk();
   getcwd(directory,35);

   fp=fopen(name,"rb");
   if(fp==NULL)
    {
     printf("\nFile Not Found..!!");
     check=2500;
    }
   else
   {
    printf("\nEnter Drive Name : ");
    scanf("%s",cd);
    dn=chdrive(cd);
      if (_chdrive(dn+1) == 0)
       {
	chdir("/");
	getdirname:
	check=0;
	getval1:
	printf("\nWant to open a directory ?? (y/n) : ");
	d=getche();
	d=tolower(d);
	if((d!='y') && (d!='n'))
	{
	 printf("\nWrong Choice.. ");
	 goto getval1;
	}
       }
      else
       check=2500;

     if((check<=0) && (d=='y'))
      {
	while(d!='n')
	{
	  printf("\n\nEnter Directory name : ");
	  scanf("%s",subdirname);
	  //chdir(subdirname);
	  if(chdir(subdirname)!=0)
	  {
	   printf("\nDirectory not found..!!");
	   getch();
	   goto getdirname;
	  }
	  else
	  {
	   getval2:
	   printf("\n\nWant to open a directory ?? (y/n) : ");
	   d=getche();
	   d=tolower(d);
	   if((d!='y') && (d!='n'))
	   {
	     printf("\nWrong Choice.. ");
	     goto getval2;
	   }

	  }
	}
      }
     if(check<=0)
      {
	printf("\n\nEnter New File Name    : ");
	scanf("%s",&name1);
	ft=fopen(name1,"rb");
	if(ft==NULL)
	{
	 fclose(ft);
	 printf("\n\nPlease Wait..!!");
	 ft=fopen(name1,"wb");
	 while((ch=getc(fp))!=EOF)
	  putc(ch,ft);
	  printf("\n\nFile Successfully Copied ..!!");
	 fclose(ft);
	 check--;
	}
	else
	{
	 fclose(ft);
	 printf("\n\nUnable to copy the file.. New file name already exists..!!");
	 check=2500;
	}
      }
    }
    outtocopyto:
     if(check>0)
      printf("\n\nError in Copying The File..!!");
      fclose(fp);
   setdisk(disk);
   chdir(directory);
   getch();
}

void moveto()
{
   char name[50],name1[50];
   int ch,check=0;
   char directory[100];
   int disk,dn;
   char *cd;  //,countdir=0;
   char subdirname[50],d;

   FILE *fp,*ft;

   printf("\nEnter Name Of The File : ");
   scanf("%s",name);

   disk=getdisk();
   getcwd(directory,35);

   fp=fopen(name,"rb");
   if(fp==NULL)
    {
     printf("\nFile Not Found..!!");
     check=2500;
    }
   else
   {
    printf("\nEnter Drive Name : ");
    scanf("%s",cd);
    dn=chdrive(cd);
      if (_chdrive(dn+1) == 0)
       {
	chdir("/");
	getdirname:
	check=0;
	getval1:
	printf("\nWant to open a directory ?? (y/n) : ");
	d=getche();
	d=tolower(d);
	if((d!='y') && (d!='n'))
	{
	 printf("\nWrong Choice.. ");
	 goto getval1;
	}
       }
      else
       check=2500;

     if((check<=0) && (d=='y'))
      {
	while(d!='n')
	{
	  printf("\n\nEnter Directory name : ");
	  scanf("%s",subdirname);

	  if(chdir(subdirname)!=0)
	  {
	   printf("\nDirectory not found..!!");
	   getch();
	   goto getdirname;
	  }
	  else
	  {
	   getval2:
	   printf("\n\nWant to open a directory ?? (y/n) : ");
	   d=getche();
	   d=tolower(d);
	   if((d!='y') && (d!='n'))
	   {
	     printf("\nWrong Choice.. ");
	     goto getval2;
	   }
	  }
	}
      }
     if(check<=0)
      {
	printf("\n\nEnter New File Name    : ");
	scanf("%s",&name1);
	ft=fopen(name1,"rb");
	if(ft==NULL)
	{
	 fclose(ft);
	 printf("\n\nPlease Wait..!!");
	 ft=fopen(name1,"wb");
	 while((ch=getc(fp))!=EOF)
	  putc(ch,ft);
	 fclose(ft);
	 setdisk(disk);
	 chdir(directory);
	 remove(name);
	 printf("\n\nFile Successfully Moved ..!!");
	 check--;
	}
	else
	{
	 fclose(ft);
	 printf("\n\nUnable to move the file.. New file name already exists..!!");
	 check=2500;
	}
      }
    }
    outtocopyto:
     if(check>0)
      printf("\n\nError in Moving The File..!!");
   fclose(fp);
   setdisk(disk);
   chdir(directory);
   getch();
}

void autocopy_all()
{
   struct ffblk ffblk;
   char code[50],name[50];
   int count=0,list=0,stat=0;
   char directory[100];
   int disk,ch;

   disk=getdisk();
   getcwd(directory,35);

   printf("\nEnter Code : ");
   scanf("%s",code);

   setdisk(bossdrive);
   chdir("/");
   chdir(bossloc1);
   chdir(bossloc2);

   stat=mkdir(code);
   if(stat!=0)
    {
     printf("\nCode Error..Code Already Exists");
     printf("\nUnable To Copy..");
     setdisk(disk);
     chdir("/");
     chdir(directory);
     goto outside;
    }
   setdisk(disk);
   chdir("/");
   chdir(directory);

   printf("\n\nAuto Copying(Not including Subdirectories)...");
   printf("\nPlease Wait.. Preparing to Copy ..");
   count=0;
       list = findfirst("*.*",&ffblk,0);
	while (!list)
	{
	   count++;
	   list = findnext(&ffblk);
	}
   printf("\n\nTotal number of files found : %d",count);
   printf("\n\nBoss Is Now Ready To Copy.. Press Any Key To Start..");
   getch();
   count=1;
   list=0;
	list = findfirst("*.*",&ffblk,0);
	while (!list)
	{
	   printf("\n\nFile Number %d : %s ",count,ffblk.ff_name);
	   strcpy(name,ffblk.ff_name);
	   count=support_to_copyall(name,count,code);
	   list = findnext(&ffblk);
	}
	printf("\n\nAll Files Successfully Copied..!!");
   outside:
}

int support_to_copyall(char name[],int count,char code[])
{
 char directory[100];
 int disk,ch;

 FILE *fp,*ft;

 disk=getdisk();
 getcwd(directory,35);
 fp=fopen(name,"rb");

 setdisk(bossdrive);
 chdir("/");
 chdir(bossloc1);
 chdir(bossloc2);
 chdir(code);
 ft=fopen(name,"rb");
 if(ft==NULL)
 {
  fclose(ft);
  printf("\nPlease Wait..!!");
  ft=fopen(name,"wb");
  while((ch=getc(fp))!=EOF)
     putc(ch,ft);
  printf("\nFile Successfully Copied to Boss Memory..!!");
  fclose(ft);
  count++;
 }
 else
 {
  fclose(ft);
  printf("\nUnable to copy the file.. New file name already in the boss memory..!!");
  getch();
 }
  fclose(fp);
  setdisk(disk);
  chdir(directory);
  return(count);
}

void autocopy_to_all()
{
   struct ffblk ffblk;
   char code[50],name[50],d;
   int count=0,list=0,check=0,countdir=0;
   int handle;
   char directory[100],cd[5],*subdir[50];
   char temp[30];
   int disk,ch,dn;

   disk=getdisk();
   getcwd(directory,35);

   printf("\nEnter Drive Name : ");
   scanf("%s",cd);
   dn=chdrive(cd);
      if (_chdrive(dn+1) == 0)
       {
	chdir("/");
	getdirname:
	check=0;
	getval1:
	printf("\nWant to open a directory ?? (y/n) : ");
	d=getche();
	d=tolower(d);
	 if((d!='y') && (d!='n'))
	 {
	  printf("\nWrong Choice.. ");
	  goto getval1;
	 }
       }
      else
      {
       printf("\nDrive Not Available..!!");
       printf("\nError In Copying File..");
       goto outofautoct;
      }

      if((check<=0) && (d=='y'))
      {
	while(d!='n')
	{
	  countdir++;
	  printf("\n\nEnter Directory name : ");
	  scanf("%s",temp);
	  strcpy(subdir[countdir],temp);
	  if(chdir(subdir[countdir])==0)
	  {
	   getval2:
	   printf("\n\nWant to open a directory ?? (y/n) : ");
	   d=getche();
	   d=tolower(d);
	     if((d!='y') && (d!='n'))
	     {
	       printf("\nWrong Choice.. ");
	       goto getval2;
	     }
	  }
	  else
	  {
	   countdir--;
	   printf("\nDirectory not found..!!");
	   getch();
	   goto getdirname;
	  }
	}
      }
   setdisk(disk);
   chdir("/");
   chdir(directory);

   printf("\n\nAuto Copying(Not Including Subdirectories)...");
   printf("\nPlease Wait.. Preparing to Copy ..");
   count=0;
       list = findfirst("*.*",&ffblk,0);
	while (!list)
	{
	   count++;
	   list = findnext(&ffblk);
	}
   printf("\n\nTotal number of files found : %d",count);
   printf("\n\nBoss Is Now Ready To Copy.. Press Any Key To Start..");
   getch();
   count=1;
   list=0;

	list = findfirst("*.*",&ffblk,0);
	while (!list)
	{
	   handle=open(ffblk.ff_name,O_RDWR);
	   printf("\n\nFile Number %d : %s ",count,ffblk.ff_name);
	   printf("\nTotal size in Kb : %ld",filelength(handle)/1024);
	   strcpy(name,ffblk.ff_name);
	   count=support_to_copyall_to(name,count,cd,&subdir[0],countdir);
	   list = findnext(&ffblk);
	}
	printf("\n\nEnd Of Copying..!!");

   outofautoct:
}

int support_to_copyall_to(char name[],int count,char cd[],char *subdir[],int countdir)
{
 char directory[100];
 int disk,ch,dn;
 int i;
 FILE *fp,*ft;

 disk=getdisk();
 getcwd(directory,35);
 fp=fopen(name,"rb");

 dn=chdrive(cd);
 _chdrive(dn+1);
 chdir("/");

 for(i=1;i<=countdir;i++)
  chdir(subdir[i]);

 ft=fopen(name,"rb");
 if(ft==NULL)
 {
  fclose(ft);
  printf("\nPlease Wait..!!");
  ft=fopen(name,"wb");
//  handle=open(name,O_RDWR);
//  y=wherey();
  //if(y>24)
   // y=24;
//  printf("%d",y);
 // getch();
  while((ch=getc(fp))!=EOF)
  {
//     gotoxy(1,y);printf("\nCopied : %ld KB",filelength(handle)/1024);
//     getch();
     putc(ch,ft);
  }
  printf("\nFile Copied ..!!");
  fclose(ft);
  count++;
 }
 else
 {
  fclose(ft);
  printf("\nUnable to copy the file.. New file name already in the Specified Location..!!");
  getch();
 }
  fclose(fp);
  setdisk(disk);
  chdir(directory);

 return(count);
}

void autocopy_sel()
{
   struct ffblk ffblk;
   char code[50],name[50];
   int count=0,list=0,stat=0,s=0;
   char directory[100],per;
   int disk,ch;

   disk=getdisk();
   getcwd(directory,35);

   printf("\nEnter Code : ");
   scanf("%s",code);

   setdisk(bossdrive);
   chdir("/");
   chdir(bossloc1);
   chdir(bossloc2);

   stat=mkdir(code);
   if(stat!=0)
    {
     printf("\nCode Error..Code Already Exists");
     printf("\nUnable To Copy..");
     setdisk(disk);
     chdir("/");
     chdir(directory);
     goto outside;
    }
   setdisk(disk);
   chdir("/");
   chdir(directory);

   printf("\n\nAuto Copying(Not including Subdirectories)...");
   printf("\nPlease Wait.. Preparing to Copy ..");
   count=0;
       list = findfirst("*.*",&ffblk,0);
	while (!list)
	{
	   count++;
	   list = findnext(&ffblk);
	}
   printf("\n\nTotal number of files found : %d",count);
   printf("\n\nBoss Is Now Ready To Copy.. Press Any Key To Start..");
   getch();
   count=1;
   list=0;
	list = findfirst("*.*",&ffblk,0);
	while (!list)
	{
	   printf("\n\nFile Number %d : %s ",count,ffblk.ff_name);
	   printf("\nDo Want To Copy..(y/n) ? : ");
	   while((per!='y') && (per!='n'))
	   {
	    per=getch();
	    per=tolower(per);
	   }
	   if(per=='y')
	   {
	    printf("%c",per);
	    per='t';
	    strcpy(name,ffblk.ff_name);
	    count=support_to_copysel(name,count,code);
	    s++;
	    list = findnext(&ffblk);
	   }
	   else if(per=='n')
	   {
	     count++;
	     printf("%c",per);
	     printf("\nFile Skipped...");
	     per='t';
	     list = findnext(&ffblk);
	   }
	}
	printf("\n\n%d Files Successfully Copied..!!",s);
   outside:
}

int support_to_copysel(char name[],int count,char code[])
{
 char directory[100];
 int disk,ch;

 FILE *fp,*ft;

 disk=getdisk();
 getcwd(directory,35);
 fp=fopen(name,"rb");

 setdisk(bossdrive);
 chdir("/");
 chdir(bossloc1);
 chdir(bossloc2);
 chdir(code);

 ft=fopen(name,"rb");
 if(ft==NULL)
 {
  fclose(ft);
  printf("\nPlease Wait..!!");
  ft=fopen(name,"wb");
  while((ch=getc(fp))!=EOF)
     putc(ch,ft);
  printf("\nFile Successfully Copied to Boss Memory..!!");
  fclose(ft);
  count++;
 }
 else
 {
  fclose(ft);
  printf("\nUnable to copy the file.. New file name already in the boss memory..!!");
  getch();
 }
  fclose(fp);
  setdisk(disk);
  chdir(directory);
  return(count);
}


void autocopy_to_sel()
{
   struct ffblk ffblk;
   char code[50],name[50],d;
   int count=0,list=0,check=0,countdir=0;
   char directory[100],cd[5],*subdir[50];
   char temp[30],per;
   int disk,ch,dn;
   int s=0;

   disk=getdisk();
   getcwd(directory,35);

   printf("\nEnter Drive Name : ");
   scanf("%s",cd);
   dn=chdrive(cd);
      if (_chdrive(dn+1) == 0)
       {
	chdir("/");
	getdirname:
	check=0;
	getval1:
	printf("\nWant to open a directory ?? (y/n) : ");
	d=getche();
	d=tolower(d);
	 if((d!='y') && (d!='n'))
	 {
	  printf("\nWrong Choice.. ");
	  goto getval1;
	 }
       }
      else
      {
       printf("\nDrive Not Available..!!");
       printf("\nError In Copying File..");
       goto outofautoct;
      }

      if((check<=0) && (d=='y'))
      {
	while(d!='n')
	{
	  countdir++;
	  printf("\n\nEnter Directory name : ");
	  scanf("%s",temp);
	  strcpy(subdir[countdir],temp);
	  if(chdir(subdir[countdir])==0)
	  {
	   getval2:
	   printf("\n\nWant to open a directory ?? (y/n) : ");
	   d=getche();
	   d=tolower(d);
	     if((d!='y') && (d!='n'))
	     {
	       printf("\nWrong Choice.. ");
	       goto getval2;
	     }
	  }
	  else
	  {
	   countdir--;
	   printf("\nDirectory not found..!!");
	   getch();
	   goto getdirname;
	  }
	}
      }
   setdisk(disk);
   chdir("/");
   chdir(directory);

   printf("\n\nAuto Copying(Not Including Subdirectories)...");
   printf("\nPlease Wait.. Preparing to Copy ..");
   count=0;
       list = findfirst("*.*",&ffblk,0);
	while (!list)
	{
	   count++;
	   list = findnext(&ffblk);
	}
   printf("\n\nTotal number of files found : %d",count);
   printf("\n\nBoss Is Now Ready To Copy.. Press Any Key To Start..");
   getch();
   count=1;
   list=0;

	list = findfirst("*.*",&ffblk,0);
	while (!list)
	{
	   printf("\n\nFile Number %d : %s ",count,ffblk.ff_name);
	   printf("\nDo Want To Copy..(y/n) ? : ");
	   while((per!='y') && (per!='n'))
	   {
	    per=getch();
	    per=tolower(per);
	   }
	   if(per=='y')
	   {
	    printf("%c",per);
	    per='t';
	    strcpy(name,ffblk.ff_name);
	    count=support_to_copysel_to(name,count,cd,&subdir[0],countdir);
	    s++;
	    list = findnext(&ffblk);
	   }
	   else if(per=='n')
	   {
	     count++;
	     printf("%c",per);
	     printf("\nFile Skipped...");
	     per='t';
	     list = findnext(&ffblk);
	   }
	}
	 printf("\n\n%d Files Successfully Copied..!!",s);
   outofautoct:
}

int support_to_copysel_to(char name[],int count,char cd[],char *subdir[],int countdir)
{
 char directory[100];
 int disk,ch,dn;
 int i;
 FILE *fp,*ft;

 disk=getdisk();
 getcwd(directory,35);
 fp=fopen(name,"rb");

 dn=chdrive(cd);
 _chdrive(dn+1);
 chdir("/");

 for(i=1;i<=countdir;i++)
  chdir(subdir[i]);

 ft=fopen(name,"rb");
 if(ft==NULL)
 {
  fclose(ft);
  printf("\nPlease Wait..!!");
  ft=fopen(name,"wb");
  while((ch=getc(fp))!=EOF)
     putc(ch,ft);
  printf("\nFile Successfully Copied ..!!");
  fclose(ft);
  count++;
 }
 else
 {
  fclose(ft);
  printf("\nUnable to copy the file.. New file name already exists..!!");
  getch();
 }
  fclose(fp);
  setdisk(disk);
  chdir(directory);

 return(count);
}


void automove_all()
{
}

void automove_to_all()
{
}

void automove_sel()
{
}

void automove_to_sel()
{
}

void paste_all()
{
   struct ffblk ffblk;
   char code[100],name[100];
   int count=0,list=0,stat=0;
   char directory[100];
   int disk,ch;

   disk=getdisk();
   getcwd(directory,35);

   printf("\nEnter Code : ");
   scanf("%s",code);

   setdisk(bossdrive);
   chdir("/");
   chdir(bossloc1);
   chdir(bossloc2);

   stat=chdir(code);

   if(stat!=0)
    {
     printf("\nCode Error..Code Does Not Exists");
     printf("\nUnable To Copy..");
     goto outside;
    }

   printf("\n\nAuto Pasting Files ... Code : %s",code);
   printf("\nPlease Wait.. Preparing to Copy ..");
   count=0;
       list = findfirst("*.*",&ffblk,0);
	while (!list)
	{
	   count++;
	   list = findnext(&ffblk);
	}
   printf("\n\nTotal number of files found : %d",count);
   printf("\n\nBoss Is Now Ready To Paste.. Press Any Key To Start..");
   getch();
   count=1;
   list=0;
	list = findfirst("*.*",&ffblk,0);
	while (!list)
	{
	   printf("\n\nFile Number %d : %s ",count,ffblk.ff_name);
	   strcpy(name,ffblk.ff_name);
	   count=support_to_pasteall(name,count,code,disk,directory);
	   list = findnext(&ffblk);
	}
   printf("\n\nFiles Successfully Pasted..!!");
   outside:
   setdisk(disk);
   chdir("/");
   chdir(directory);
   getch();
}

int support_to_pasteall(char name[],int count,char code[],int disk,char directory[])
{
 int ch;

 FILE *fp,*ft;

 fp=fopen(name,"rb");

   setdisk(disk);
   chdir("/");
   chdir(directory);


 ft=fopen(name,"rb");
 if(ft==NULL)
 {
  fclose(ft);
  printf("\nPlease Wait..!!");
  ft=fopen(name,"wb");
  while((ch=getc(fp))!=EOF)
     putc(ch,ft);
  printf("\nFile Successfully Copied to Boss Memory..!!");
  fclose(ft);
  count++;
 }
 else
 {
  fclose(ft);
  printf("\nUnable to copy the file.. New file name already in the boss memory..!!");
 }
  fclose(fp);
 setdisk(bossdrive);
 chdir("/");
 chdir(bossloc1);
 chdir(bossloc2);
 chdir(code);

 return(count);
}
