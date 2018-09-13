void game()
 {
  char ch,ch1;
  char name1[20],name2[20],name[20];
  int option;
  int n1=0,n2=0,n3=0,sum=0;
  int n4=0,n5=0,n6=0,sum1=0,sum2=0;
  long int score,score1,score2;

//  textcolor(WHITE);

 do
  {
  clrscr();
//  textcolor(WHITE);
  gotoxy(30,8); printf("Main Menu");
  gotoxy(15,10);printf("1.Single Player");
  gotoxy(15,12);printf("2.Multi Player");
  gotoxy(15,14);printf("3.Exit");

  gotoxy(15,20);printf("Enter Your Option : ");
  scanf("%d",&option);

  switch(option)
   {
     case 1:
	clrscr();
	gotoxy(20,12);printf("Enter Your Name : ");
	scanf("%s",name);
	clrscr();

	textcolor(10);gotoxy(22,9);cprintf("Press \"S\" To Start Game..!!");

	  gotoxy(25,4);printf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»" );
	  gotoxy(25,5);printf("º *****  MY BOSS GAME  ***** º" );
	  gotoxy(25,6);printf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼" );

	  gotoxy(8,12);printf("Chance 1 : ");

	  gotoxy(22,11);  printf("ÚÄÄÄÄÄÂÄÄÄÄÄÂÄÄÄÄÄ¿");
	  gotoxy(22,12);  printf("³     ³     ³     ³");
	  gotoxy(22,13);  printf("ÀÄÄÄÄÄÁÄÄÄÄÄÁÄÄÄÄÄÙ");

	  gotoxy(25,12);printf("$");
	  gotoxy(31,12);printf("$");
	  gotoxy(37,12);printf("$");

	randomize();
     do
      {
	do
	 {
	   //ch=getch();
	   while(!kbhit())
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n1=random(10);
		 gotoxy(37,12);printf("%d",n1);
		 delay(10);
	       }
	    }
	      getch();
	      break;
	  }while(ch!=13);

	do
	 {
	  // ch=getch();
	   while(!kbhit())
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n2=random(10);
		 gotoxy(31,12);printf("%d",n2);
		 delay(10);
	       }
	    }
	      getch();
	      break;
	  }while(ch!=13);


	 do
	 {
	   //ch=getch();
	   while(!kbhit())
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n3=random(10);
		 gotoxy(25,12);printf("%d",n3);
		 delay(10);
	       }
	    }
	     sum=sum+n1;
	     sum=sum+(n2*10);
	     sum=sum+(n3*100);

	      getch();
	      break;
       }while(ch!=13);

	/* _____________________________*/

      gotoxy(8,16);printf("Chance 2 : ");

      gotoxy(22,15);  printf("ÚÄÄÄÄÄÂÄÄÄÄÄÂÄÄÄÄÄ¿");
      gotoxy(22,16);  printf("³     ³     ³     ³");
      gotoxy(22,17);  printf("ÀÄÄÄÄÄÁÄÄÄÄÄÁÄÄÄÄÄÙ");

      gotoxy(25,16);printf("$");
      gotoxy(31,16);printf("$");
      gotoxy(37,16);printf("$");

      do
	 {
	   ch=getch();
	   if((ch=='s') ||(ch=='S'))
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n4=random(10);
		 gotoxy(37,16);printf("%d",n4);
		 delay(10);
	       }
	    }
	      getch();
	      break;
	  }while(ch!=13);

	do
	 {
	   ch=getch();
	   if((ch=='s') ||(ch=='S'))
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n5=random(10);
		 gotoxy(31,16);printf("%d",n5);
		 delay(10);
	       }
	    }
	      getch();
	      break;
	  }while(ch!=13);


	 do
	 {
	   ch=getch();
	   if((ch=='s') ||(ch=='S'))
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n6=random(10);
		 gotoxy(25,16);printf("%d",n6);
		 delay(10);
	       }
	    }
	     sum1=sum1+n4;
	     sum1=sum1+(n5*10);
	     sum1=sum1+(n6*100);

	      getch();
	      break;
	  }while(ch!=13);

	/* _____________________________*/

      gotoxy(8,20);printf("Chance 3 : ");

      gotoxy(22,19);  printf("ÚÄÄÄÄÄÂÄÄÄÄÄÂÄÄÄÄÄ¿");
      gotoxy(22,20);  printf("³     ³     ³     ³");
      gotoxy(22,21);  printf("ÀÄÄÄÄÄÁÄÄÄÄÄÁÄÄÄÄÄÙ");

      gotoxy(25,20);printf("$");
      gotoxy(31,20);printf("$");
      gotoxy(37,20);printf("$");

      do
	 {
	   ch=getch();
	   if((ch=='s') ||(ch=='S'))
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n4=random(10);
		 gotoxy(37,20);printf("%d",n4);
		 delay(10);
	       }
	    }
	      getch();
	      break;
	  }while(ch!=13);

	do
	 {
	   ch=getch();
	   if((ch=='s') ||(ch=='S'))
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n5=random(10);
		 gotoxy(31,20);printf("%d",n5);
		 delay(10);
	       }
	    }
	      getch();
	      break;
	  }while(ch!=13);


	 do
	 {
//	   ch=getch();
	   while(!kbhit())
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n6=random(10);
		 gotoxy(25,20);printf("%d",n6);
		 delay(10);
	       }
	    }
	     sum2=sum2+n4;
	     sum2=sum2+(n5*10);
	     sum2=sum2+(n6*100);

	      getch();
	      break;
	  }while(ch!=13);
	  break;

	/* _____________________________*/
     //  ch1=getch();

   }while(ch1!='q');

    score=sum+sum1+sum2;
    printf("\n\n\n\t\t\t%s Total Score : %ld",name,score);

    n1=0;n2=0;n3=0;sum=0;
    n4=0;n5=0;n6=0;sum1=0;sum2=0;
    getch();
    break;

  case 2:
	clrscr();
	clrscr();
	    n1=0;n2=0;n3=0;sum=0;
	    n4=0;n5=0;n6=0;sum1=0;sum2=0;

	gotoxy(20,12);printf("Enter Your Name(Player 1) : ");
	scanf("%s",name1);

	gotoxy(20,14);printf("Enter Your Name(Player 2) : ");
	scanf("%s",name2);
	clrscr();
	clrscr();

	textcolor(10);gotoxy(22,9);cprintf("Press \"S\" To Start Game..!!");

	  gotoxy(25,4);printf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»" );
	  gotoxy(25,5);printf("º *****  MY BOSS GAME  ***** º" );
	  gotoxy(25,6);printf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼" );

	  gotoxy(8,12);printf("Chance 1 : ");

	  gotoxy(22,11);  printf("ÚÄÄÄÄÄÂÄÄÄÄÄÂÄÄÄÄÄ¿");
	  gotoxy(22,12);  printf("³     ³     ³     ³");
	  gotoxy(22,13);  printf("ÀÄÄÄÄÄÁÄÄÄÄÄÁÄÄÄÄÄÙ");

	  gotoxy(25,12);printf("$");
	  gotoxy(31,12);printf("$");
	  gotoxy(37,12);printf("$");

	randomize();
     do
      {
	do
	 {
	   //ch=getch();
	   while(!kbhit())
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n1=random(10);
		 gotoxy(37,12);printf("%d",n1);
		 delay(10);
	       }
	    }
	      getch();
	      break;
	  }while(ch!=13);

	do
	 {
	  // ch=getch();
	   while(!kbhit())
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n2=random(10);
		 gotoxy(31,12);printf("%d",n2);
		 delay(10);
	       }
	    }
	      getch();
	      break;
	  }while(ch!=13);


	 do
	 {
//	   ch=getch();
	   while(!kbhit())
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n3=random(10);
		 gotoxy(25,12);printf("%d",n3);
		 delay(10);
	       }
	    }
	     sum=sum+n1;
	     sum=sum+(n2*10);
	     sum=sum+(n3*100);

	      getch();
	      break;
       }while(ch!=13);

	/* _____________________________*/

      gotoxy(8,16);printf("Chance 2 : ");

      gotoxy(22,15);  printf("ÚÄÄÄÄÄÂÄÄÄÄÄÂÄÄÄÄÄ¿");
      gotoxy(22,16);  printf("³     ³     ³     ³");
      gotoxy(22,17);  printf("ÀÄÄÄÄÄÁÄÄÄÄÄÁÄÄÄÄÄÙ");

      gotoxy(25,16);printf("$");
      gotoxy(31,16);printf("$");
      gotoxy(37,16);printf("$");

      do
	 {
//	   ch=getch();
	   while(!kbhit())
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n4=random(10);
		 gotoxy(37,16);printf("%d",n4);
		 delay(10);
	       }
	    }
	      getch();
	      break;
	  }while(ch!=13);

	do
	 {
//	   ch=getch();
	    while(!kbhit())
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n5=random(10);
		 gotoxy(31,16);printf("%d",n5);
		 delay(10);
	       }
	    }
	      getch();
	      break;
	  }while(ch!=13);


	 do
	 {
	   //ch=getch();
	   while(!kbhit())
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n6=random(10);
		 gotoxy(25,16);printf("%d",n6);
		 delay(10);
	       }
	    }
	     sum1=sum1+n4;
	     sum1=sum1+(n5*10);
	     sum1=sum1+(n6*100);

	      getch();
	      break;
	  }while(ch!=13);

	/* _____________________________*/

      gotoxy(8,20);printf("Chance 3 : ");

      gotoxy(22,19);  printf("ÚÄÄÄÄÄÂÄÄÄÄÄÂÄÄÄÄÄ¿");
      gotoxy(22,20);  printf("³     ³     ³     ³");
      gotoxy(22,21);  printf("ÀÄÄÄÄÄÁÄÄÄÄÄÁÄÄÄÄÄÙ");

      gotoxy(25,20);printf("$");
      gotoxy(31,20);printf("$");
      gotoxy(37,20);printf("$");

      do
	 {
//	   ch=getch();
	   while(!kbhit())
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n4=random(10);
		 gotoxy(37,20);printf("%d",n4);
		 delay(10);
	       }
	    }
	      getch();
	      break;
	  }while(ch!=13);

	do
	 {
	   //ch=getch();
	   while(!kbhit())
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n5=random(10);
		 gotoxy(31,20);printf("%d",n5);
		 delay(10);
	       }
	    }
	      getch();
	      break;
	  }while(ch!=13);


	 do
	 {
//	   ch=getch();
	   while(!kbhit())
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n6=random(10);
		 gotoxy(25,20);printf("%d",n6);
		 delay(10);
	       }
	    }
	     sum2=sum2+n4;
	     sum2=sum2+(n5*10);
	     sum2=sum2+(n6*100);

	      getch();
	      break;
	  }while(ch!=13);
	  break;

	/* _____________________________*/
       //	ch1=getch();

   }while(ch1!='q');

    score1=sum+sum1+sum2;
    n1=0;n2=0;n3=0;sum=0;
    n4=0;n5=0;n6=0;sum1=0;sum2=0;

    printf("\n\n\n\t\t\t%s Total Score : %ld",name1,score1);
    getch();
    clrscr();

	textcolor(10);gotoxy(22,9);cprintf("Press \"S\" To Start Game..!!");

	  gotoxy(25,4);printf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»" );
	  gotoxy(25,5);printf("º *****  MY BOSS GAME  ***** º" );
	  gotoxy(25,6);printf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼" );

	  gotoxy(8,12);printf("Chance 1 : ");

	  gotoxy(22,11);  printf("ÚÄÄÄÄÄÂÄÄÄÄÄÂÄÄÄÄÄ¿");
	  gotoxy(22,12);  printf("³     ³     ³     ³");
	  gotoxy(22,13);  printf("ÀÄÄÄÄÄÁÄÄÄÄÄÁÄÄÄÄÄÙ");

	  gotoxy(25,12);printf("$");
	  gotoxy(31,12);printf("$");
	  gotoxy(37,12);printf("$");

	randomize();
     do
      {
	do
	 {
//	   ch=getch();
	   while(!kbhit())
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n1=random(10);
		 gotoxy(37,12);printf("%d",n1);
		 delay(10);
	       }
	    }
	      getch();
	      break;
	  }while(ch!=13);

	do
	 {
//	   ch=getch();
	   while(!kbhit())
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n2=random(10);
		 gotoxy(31,12);printf("%d",n2);
		 delay(10);
	       }
	    }
	      getch();
	      break;
	  }while(ch!=13);


	 do
	 {
//	   ch=getch();
	  while(!kbhit())
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n3=random(10);
		 gotoxy(25,12);printf("%d",n3);
		 delay(10);
	       }
	    }
	     sum=sum+n1;
	     sum=sum+(n2*10);
	     sum=sum+(n3*100);

	      getch();
	      break;
       }while(ch!=13);

	/* _____________________________*/

      gotoxy(8,16);printf("Chance 2 : ");

      gotoxy(22,15);  printf("ÚÄÄÄÄÄÂÄÄÄÄÄÂÄÄÄÄÄ¿");
      gotoxy(22,16);  printf("³     ³     ³     ³");
      gotoxy(22,17);  printf("ÀÄÄÄÄÄÁÄÄÄÄÄÁÄÄÄÄÄÙ");

      gotoxy(25,16);printf("$");
      gotoxy(31,16);printf("$");
      gotoxy(37,16);printf("$");

      do
	 {
	  // ch=getch();
	   while(!kbhit())
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n4=random(10);
		 gotoxy(37,16);printf("%d",n4);
		 delay(10);
	       }
	    }
	      getch();
	      break;
	  }while(ch!=13);

	do
	 {
//	   ch=getch();
	   while(!kbhit())
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n5=random(10);
		 gotoxy(31,16);printf("%d",n5);
		 delay(10);
	       }
	    }
	      getch();
	      break;
	  }while(ch!=13);


	 do
	 {
//	   ch=getch();
	   while(!kbhit())
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n6=random(10);
		 gotoxy(25,16);printf("%d",n6);
		 delay(10);
	       }
	    }
	     sum1=sum1+n4;
	     sum1=sum1+(n5*10);
	     sum1=sum1+(n6*100);

	      getch();
	      break;
	  }while(ch!=13);

	/* _____________________________*/

      gotoxy(8,20);printf("Chance 3 : ");

      gotoxy(22,19);  printf("ÚÄÄÄÄÄÂÄÄÄÄÄÂÄÄÄÄÄ¿");
      gotoxy(22,20);  printf("³     ³     ³     ³");
      gotoxy(22,21);  printf("ÀÄÄÄÄÄÁÄÄÄÄÄÁÄÄÄÄÄÙ");

      gotoxy(25,20);printf("$");
      gotoxy(31,20);printf("$");
      gotoxy(37,20);printf("$");

      do
	 {
//	   ch=getch();
	   while(!kbhit())
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n4=random(10);
		 gotoxy(37,20);printf("%d",n4);
		 delay(10);
	       }
	    }
	      getch();
	      break;
	  }while(ch!=13);

	do
	 {
	   //ch=getch();
	   while(!kbhit())
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n5=random(10);
		 gotoxy(31,20);printf("%d",n5);
		 delay(10);
	       }
	    }
	      getch();
	      break;
	  }while(ch!=13);


	 do
	 {
	//   ch=getch();
	  while(!kbhit())
	    {
	      randomize();
	      while(!kbhit())
	       {
		 n6=random(10);
		 gotoxy(25,20);printf("%d",n6);
		 delay(10);
	       }
	    }
	     sum2=sum2+n4;
	     sum2=sum2+(n5*10);
	     sum2=sum2+(n6*100);

	      getch();
	      break;
	  }while(ch!=13);
	  break;

	/* _____________________________*/
       //	ch1=getch();

   }while(ch1!='q');

    score2=sum+sum1+sum2;
    printf("\n\n\n\t\t\t%s Total Score : %ld",name2,score2);
    getch();
    break;

  case 3:
	exit(0);
	break;
  }
   if(score1>score2)
    {
     clrscr();
     gotoxy(20,12);printf("%s is Winner",name1);
    }
   else if(score2>score1)
    {
     clrscr();
     gotoxy(20,12);printf("%s is Winner",name2);
    }
   else if(score1==score2)
    {
     clrscr();
     gotoxy(20,12);printf("Match Draw");
    }
   getch();
  }while(option!=3);

 }