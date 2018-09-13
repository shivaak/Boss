char test[35];

void mode1()
{
  getcwd(test,35);
  clrscr();
  textcolor(7);
  printf("\n\n");
  textcolor(14);
  cprintf("%s>",test);
  textcolor(7);
  gotoxy(30,3); printf("SIS CONVERTER");

  gotoxy(4,5);  printf("1.Fahrenheit-Celsius");
  gotoxy(28,5); printf("2.Kelvin-Fahrenheit");
  gotoxy(52,5); printf("3.Kelvin-Celsius");

  gotoxy(4,6);  printf("4.USD-EUR");
  gotoxy(28,6); printf("5.GBP-USD");
  gotoxy(52,6); printf("6.CHF-USD");

  gotoxy(4,7);  printf("7.JPY-USD");
  gotoxy(28,7); printf("8.CHF-EUR");
  gotoxy(52,7); printf("9.CHF-GBP");

  gotoxy(4,8);  printf("10.GBP-EUR");
  gotoxy(28,8); printf("11.JPY-EUR");
  gotoxy(52,8); printf("12.JPY-GBP");

  gotoxy(4,9);  printf("13.RMB-USD");
  gotoxy(28,9); printf("14.RMB-EUR");
  gotoxy(52,9); printf("15.RMB-JPY");

  gotoxy(4,10);  printf("16.POUND-KILO");
  gotoxy(28,10); printf("17.CARAT-GRAM");
  gotoxy(52,10); printf("18.OUNCE-GRAM");

  gotoxy(4,11); printf("19.TROY OZ.-GRAM");
  gotoxy(28,11);printf("20.STONE-KILO");
  gotoxy(52,11);printf("21.MILE-KM");

  gotoxy(4,12); printf("22.METER-CM");
  gotoxy(28,12);printf("23.INCH-MM");
  gotoxy(52,12);printf("24.INCH-CM");

  gotoxy(4,13); printf("25.CM-MM");
  gotoxy(28,13);printf("26.FEET-CM");
  gotoxy(52,13);printf("27.FEET-INCH");

  gotoxy(4,14); printf("28.FEET-METER");
  gotoxy(28,14);printf("29.YARD-METER");
  gotoxy(52,14);printf("30.N.MILE-KM");

  gotoxy(4,15); printf("31.ACRE-(KM^2)");
  gotoxy(28,15);printf("32.(FEET^2)-(METER^2)");
  gotoxy(52,15);printf("33.(YARD^2)-(METER^2)");

  gotoxy(4,16); printf("34.(MILE^2)-(KM^2)");
  gotoxy(28,16);printf("35.(INCH^2)-(CM^2)");
  gotoxy(52,16);printf("36.HECTARE-(MILE^2)");

  gotoxy(4,17); printf("37.ACRE-HECTARE");
  gotoxy(28,17);printf("38.(INCH^3)-(CM^3)");
  gotoxy(52,17);printf("39.(FEET^3)-(METER^3)");

  gotoxy(4,18); printf("40.(YARD^3)-(METER^3)");
  gotoxy(28,18);printf("41.CHANGE MODE");
  gotoxy(52,18);printf("42.CANCEL");

  gotoxy(27,20);printf("Enter Your Choice : ");
}

void mode2()
{
  getcwd(test,35);
  clrscr();
  textcolor(7);
  printf("\n\n");
  textcolor(14);
  cprintf("%s>",test);
  textcolor(7);
  gotoxy(30,3); printf("SIS CONVERTER");

  gotoxy(4,5);  printf("1.Celsius-Fahrenheit");
  gotoxy(28,5); printf("2.Fahrenheit-Kelvin");
  gotoxy(52,5); printf("3.Celsius-Kelvin");

  gotoxy(4,6);  printf("4.EUR-USD");
  gotoxy(28,6); printf("5.USD-GBP");
  gotoxy(52,6); printf("6.USD-CHF");

  gotoxy(4,7);  printf("7.USD-JPY");
  gotoxy(28,7); printf("8.EUR-CHF");
  gotoxy(52,7); printf("9.GBP-CHF");

  gotoxy(4,8);  printf("10.EUR-GBP");
  gotoxy(28,8); printf("11.EUR-JPY");
  gotoxy(52,8); printf("12.GBP-JPY");

  gotoxy(4,9);  printf("13.USD-RMB");
  gotoxy(28,9); printf("14.EUR-RMB");
  gotoxy(52,9); printf("15.JPY-RMB");

  gotoxy(4,10);  printf("16.KILO-POUND");
  gotoxy(28,10); printf("17.GRAM-CARAT");
  gotoxy(52,10); printf("18.GRAM-OUNCE");

  gotoxy(4,11); printf("19.GRAM-TROY OZ.");
  gotoxy(28,11);printf("20.KILO-STONE");
  gotoxy(52,11);printf("21.KM-MILE");

  gotoxy(4,12); printf("22.CM-METER");
  gotoxy(28,12);printf("23.MM-INCH");
  gotoxy(52,12);printf("24.CM-INCH");

  gotoxy(4,13); printf("25.MM-CM");
  gotoxy(28,13);printf("26.CM-FEET");
  gotoxy(52,13);printf("27.INCH-FEET");

  gotoxy(4,14); printf("28.METER-FEET");
  gotoxy(28,14);printf("29.METER-YARD");
  gotoxy(52,14);printf("30.KM-N.MILE");

  gotoxy(4,15); printf("31.(KM^2)-ACRE");
  gotoxy(28,15);printf("32.(METER^2)-(FEET^2)");
  gotoxy(52,15);printf("33.(METER^2)-(YARD^2)");

  gotoxy(4,16); printf("34.(KM^2)-(MILE^2)");
  gotoxy(28,16);printf("35.(CM^2)-(INCH^2)");
  gotoxy(52,16);printf("36.(MILE^2)-HECTARE");

  gotoxy(4,17); printf("37.HECTARE-ACRE");
  gotoxy(28,17);printf("38.(CM^3)-(INCH^3)");
  gotoxy(52,17);printf("39.(METER^3)-(FEET^3)");

  gotoxy(4,18); printf("40.(METER^3)-(YARD^3)");
  gotoxy(28,18);printf("41.CHANGE MODE");
  gotoxy(52,18);printf("42.CANCEL");

  gotoxy(27,20);printf("Enter Your Choice : ");
}

void fa_ce(int mode) //1
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Farenheit value : ");
   scanf("%f",&val);
   ans=(val-32)*(5.000000/9.000000);
   printf("\n\t\tThe Celcius value is      : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Celcius value : ");
   scanf("%f",&val);
   ans=((9.000000/5.000000)*val)+32;
   printf("\n\t\tThe Farenheit value is  : %f",ans);
  }
}

void ke_fa(int mode)   //2
{
 printf("\n\t\t\tUnder Construction %d",mode);
}

void ke_ce(int mode)    //3
{
 printf("\n\t\t\tUnder Construction %d",mode);
}

void usd_eur(int mode)   //4
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Dollar(USA) value : ");
   scanf("%f",&val);
   ans=val*0.82068;
   printf("\n\t\tThe EURO value is           : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter Euro value         : ");
   scanf("%f",&val);
   ans=val/0.82068;
   printf("\n\t\tThe Dollar(USA) value is : %f",ans);
  }
}

void gbp_usd(int mode)      //5
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Pound(GB) value : ");
   scanf("%f",&val);
   ans=val*1.83110;
   printf("\n\t\tThe Dollar(US) value is   : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Dollar(US) value : ");
   scanf("%f",&val);
   ans=val/1.83110;
   printf("\n\t\tThe Pound(GB) value is     : %f",ans);
  }
}

void chf_usd(int mode)   //6
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Franc(CH) value : ");
   scanf("%f",&val);
   ans=val*0.79707;
   printf("\n\t\tThe Dollar(US) value is   : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Dollar(US) value : ");
   scanf("%f",&val);
   ans=val/0.79707;
   printf("\n\t\tThe Franc(CH) value is     : %f",ans);
  }
}

void jpy_usd(int mode)   //7
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Yen value       : ");
   scanf("%f",&val);
   ans=val*0.009140;
   printf("\n\t\tThe Dollar(US) value is   : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Dollar(US) value : ");
   scanf("%f",&val);
   ans=val/0.009140;
   printf("\n\t\tThe Yen value is           : %f",ans);
  }
}

void chf_eur(int mode)    //8
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Franc(CH) value : ");
   scanf("%f",&val);
   ans=val*0.65419;
   printf("\n\t\tThe Euro value is         : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Euro value   : ");
   scanf("%f",&val);
   ans=val/0.65419;
   printf("\n\t\tThe Franc(CH) value is : %f",ans);
  }
}

void chf_gbp(int mode)    //9
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Franc(CH) value : ");
   scanf("%f",&val);
   ans=val*0.43526;
   printf("\n\t\tThe Pound(GB) value is    : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Pound(GB) value : ");
   scanf("%f",&val);
   ans=val/0.43526;
   printf("\n\t\tThe Franc(CH) value is    : %f",ans);
  }
}

void gbp_eur(int mode)    //10
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Pound(GB) value : ");
   scanf("%f",&val);
   ans=val*1.50353;
   printf("\n\t\tThe Euro value is         : %f",ans);
  }
  else if(mode==2)
  {
   printf("\n\t\tEnter the Euro  value  : ");
   scanf("%f",&val);
   ans=val/1.50353;
   printf("\n\t\tThe Pound(GB) value is : %f",ans);
  }
}
void jpy_eur(int mode)    //11
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Yen value : ");
   scanf("%f",&val);
   ans=val*0.007502;
   printf("\n\t\tThe Euro value is   : %f",ans);
  }
  else if(mode==2)
  {
   printf("\n\t\tEnter the Euro  value : ");
   scanf("%f",&val);
   ans=val/0.007502;
   printf("\n\t\tThe Yen value is      : %f",ans);
  }
}
void jpy_gbp(int mode)    //12
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Yen value    : ");
   scanf("%f",&val);
   ans=val*0.004993;
   printf("\n\t\tThe Pound(GB) value is : %f",ans);
  }
  else if(mode==2)
  {
   printf("\n\t\tEnter the Pound(GB) value : ");
   scanf("%f",&val);
   ans=val/0.004993;
   printf("\n\t\tThe Yen value is          : %f",ans);
  }
}

void rmb_usd(int mode)    //13
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Renminbi value : ");
   scanf("%f",&val);
   ans=val*0.12371;
   printf("\n\t\tThe Dollar(USA) value is : %f",ans);
  }
  else if(mode==2)
  {
   printf("\n\t\tEnter the Dollar(USA) value : ");
   scanf("%f",&val);
   ans=val/0.12371;
   printf("\n\t\tThe Renminbi value is       : %f",ans);
  }
}

void rmb_eur(int mode)    //14
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Renminbi value : ");
   scanf("%f",&val);
   ans=val*0.10562;
   printf("\n\t\tThe Euro value is        : %f",ans);
  }
  else if(mode==2)
  {
   printf("\n\t\tEnter the Euro value  : ");
   scanf("%f",&val);
   ans=val/0.10562;
   printf("\n\t\tThe Renminbi value is : %f",ans);
  }
}

void rmb_jpy(int mode)    //15
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Renminbi value : ");
   scanf("%f",&val);
   ans=val*14.688;
   printf("\n\t\tThe Yen value is         : %f",ans);
  }
  else if(mode==2)
  {
   printf("\n\t\tEnter the Yen value   : ");
   scanf("%f",&val);
   ans=val/14.688;
   printf("\n\t\tThe Renminbi value is : %f",ans);
  }
}

void pou_kilo(int mode)   //16
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Pound value : ");
   scanf("%f",&val);
   ans=val*0.535924;
   printf("\n\t\tThe Kilo value is     : %f",ans);
  }
  else if(mode==2)
  {
   printf("\n\t\tEnter the Kilo value : ");
   scanf("%f",&val);
   ans=val/0.535924;
   printf("\n\t\tThe Pound value is   : %f",ans);
  }
}

void carat_gram(int mode) //17
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Carat value : ");
   scanf("%f",&val);
   ans=val*0.2;
   printf("\n\t\tThe Gram value is     : %f",ans);
  }
  else if(mode==2)
  {
   printf("\n\t\tEnter the Gram value : ");
   scanf("%f",&val);
   ans=val/0.2;
   printf("\n\t\tThe Carat value is   : %f",ans);
  }
}

void ounce_gram(int mode) //18
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Ounce value : ");
   scanf("%f",&val);
   ans=val*28.34;
   printf("\n\t\tThe Gram value is     : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Gram value : ");
   scanf("%f",&val);
   ans=val/28.34;
   printf("\n\t\tThe Ounce value is   : %f",ans);
  }

}

void troy_gram(int mode)  //19
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Troy Ounce value : ");
   scanf("%f",&val);
   ans=val*31.1035;
   printf("\n\t\tThe Gram value is          : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Gram value    : ");
   scanf("%f",&val);
   ans=val/31.1035;
   printf("\n\t\tThe Troy Ounce value is : %f",ans);
  }
}

void stone_kilo(int mode) //20
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Stone value : ");
   scanf("%f",&val);
   ans=val*6.3502932;
   printf("\n\t\tThe Kilo value is     : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Kilo value : ");
   scanf("%f",&val);
   ans=val/6.3502932;
   printf("\n\t\tThe Stone value is   : %f",ans);
  }
}

void mile_km(int mode)    //21
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Mile value   : ");
   scanf("%f",&val);
   ans=val*1.609344;
   printf("\n\t\tThe Kilometer value is : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Kilometer value : ");
   scanf("%f",&val);
   ans=val/1.609344;
   printf("\n\t\tThe Mile value is         : %f",ans);
  }
}

void meter_cm(int mode)    //22
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Meter value   : ");
   scanf("%f",&val);
   ans=val*100.0;
   printf("\n\t\tThe Centimeter value is : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Centimeter value : ");
   scanf("%f",&val);
   ans=val/100.0;
   printf("\n\t\tThe Meter value is         : %f",ans);
  }
}

void inch_mm(int mode)    //23
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Inch value    : ");
   scanf("%f",&val);
   ans=val*25.4;
   printf("\n\t\tThe Millimeter value is : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Millimeter value : ");
   scanf("%f",&val);
   ans=val/25.4;
   printf("\n\t\tThe Inch value is          : %f",ans);
  }
}

void inch_cm(int mode)    //24
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Inch value    : ");
   scanf("%f",&val);
   ans=val*2.54;
   printf("\n\t\tThe Centimeter value is : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Centimeter value : ");
   scanf("%f",&val);
   ans=val/2.54;
   printf("\n\t\tThe Inch value is          : %f",ans);
  }
}

void cm_mm(int mode)    //25
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Centimeter value : ");
   scanf("%f",&val);
   ans=val*10.0;
   printf("\n\t\tThe Millimeter value is    : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Millimeter value : ");
   scanf("%f",&val);
   ans=val/10.0;
   printf("\n\t\tThe Centimeter value is    : %f",ans);
  }
}

void feet_cm(int mode)    //26
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Feet value    : ");
   scanf("%f",&val);
   ans=val*30.48;
   printf("\n\t\tThe Centimeter value is : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Centimeter value : ");
   scanf("%f",&val);
   ans=val/30.48;
   printf("\n\t\tThe Feet value is          : %f",ans);
  }
}

void feet_inch(int mode)    //27
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Feet value : ");
   scanf("%f",&val);
   ans=val*12.0;
   printf("\n\t\tThe Inch value is    : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Inch value : ");
   scanf("%f",&val);
   ans=val/12.0;
   printf("\n\t\tThe Feet value is    : %f",ans);
  }
}

void feet_meter(int mode)    //28
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Feet value : ");
   scanf("%f",&val);
   ans=val*0.3048;
   printf("\n\t\tThe Meter value is   : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Meter value : ");
   scanf("%f",&val);
   ans=val/0.3048;
   printf("\n\t\tThe Feet value is     : %f",ans);
  }
}

void yard_meter(int mode)    //29
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Yard value : ");
   scanf("%f",&val);
   ans=val*0.9144;
   printf("\n\t\tThe Meter value is   : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Meter value : ");
   scanf("%f",&val);
   ans=val/0.9144;
   printf("\n\t\tThe Yard value is     : %f",ans);
  }
}

void nmile_km(int mode)    //30
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Nautical Mile value : ");
   scanf("%f",&val);
   ans=val*1.852;
   printf("\n\t\tThe Kilometer value is        : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Kilometer value  : ");
   scanf("%f",&val);
   ans=val/1.852;
   printf("\n\t\tThe Nautical Mile value is : %f",ans);
  }
}

void acre_skm(int mode)    //31
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Acre value          : ");
   scanf("%f",&val);
   ans=val*0.0040469;
   printf("\n\t\tThe Square Kilometer value is : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Square Kilometer value : ");
   scanf("%f",&val);
   ans=val/0.0040469;
   printf("\n\t\tThe Acre value is                : %f",ans);
  }
}

void sfeet_smeter(int mode)    //32
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Square Feet value : ");
   scanf("%f",&val);
   ans=val*0.92903;
   printf("\n\t\tThe Square Meter value is   : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Square Meter value : ");
   scanf("%f",&val);
   ans=val/0.92903;
   printf("\n\t\tThe Square Feet value is     : %f",ans);
  }
}

void syard_smeter(int mode)    //33
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Square Yard value : ");
   scanf("%f",&val);
   ans=val*0.8361274;
   printf("\n\t\tThe Square Meter value is   : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Square Meter value : ");
   scanf("%f",&val);
   ans=val/0.8361274;
   printf("\n\t\tThe Square Yard value is     : %f",ans);
  }

}

void smile_skm(int mode)    //34
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Square Mile value   : ");
   scanf("%f",&val);
   ans=val*2.589981;
   printf("\n\t\tThe Square Kilometer value is : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Square Kilometer value : ");
   scanf("%f",&val);
   ans=val/2.589981;
   printf("\n\t\tThe Square Mile value is         : %f",ans);
  }
}

void sinch_scm(int mode)    //35
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Square Inch value    : ");
   scanf("%f",&val);
   ans=val*6.4516;
   printf("\n\t\tThe Square Centimeter value is : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Square Centimeter value : ");
   scanf("%f",&val);
   ans=val/6.4516;
   printf("\n\t\tThe Square Inch value is          : %f",ans);
  }
}

void hectare_smile(int mode)    //36
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Hectare value  : ");
   scanf("%f",&val);
   ans=val*0.003861;
   printf("\n\t\tThe Square Mile value is : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Square Mile value : ");
   scanf("%f",&val);
   ans=val/0.003861;
   printf("\n\t\tThe Hectare value is        : %f",ans);
  }
}

void acre_hectare(int mode)    //37
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Acre value : ");
   scanf("%f",&val);
   ans=val*0.4046856;
   printf("\n\t\tThe Hectare value is : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Hectare value : ");
   scanf("%f",&val);
   ans=val/0.4046856;
   printf("\n\t\tThe Acre value is       : %f",ans);
  }
}

void cinch_ccm(int mode)    //38
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Cubic Inch value    : ");
   scanf("%f",&val);
   ans=val*16.3880642;
   printf("\n\t\tThe Cubic Centimeter value is : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Cubic Centimeter value : ");
   scanf("%f",&val);
   ans=val/16.3880642;
   printf("\n\t\tThe Cubic Inch value is          : %f",ans);
  }
}

void cfeet_cmeter(int mode)    //39
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Cubic Feet value : ");
   scanf("%f",&val);
   ans=val*0.0283168;
   printf("\n\t\tThe Cubic Meter value is   : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Cubic Meter value : ");
   scanf("%f",&val);
   ans=val/0.0283168;
   printf("\n\t\tThe Cubic Feet value is     : %f",ans);
  }
}

void cyard_cmeter(int mode)    //40
{
 float val=0,ans=0;
 if(mode==1)
  {
   printf("\n\t\tEnter the Cubic Yard value : ");
   scanf("%f",&val);
   ans=val*0.7645549;
   printf("\n\t\tThe Cubic Meter value is   : %f",ans);
  }
 else if(mode==2)
  {
   printf("\n\t\tEnter the Cubic Meter value : ");
   scanf("%f",&val);
   ans=val/0.7645549;
   printf("\n\t\tThe Cubic Yard value is     : %f",ans);
  }
}

 /* ------------ End of calculation ------------ */

void convert()
{
 int ch,mode=0;
 clrscr();
 textbackground(0);
 clrscr();
 mode=1;
 do
 {
  clrscr();
     if(mode==1)
       mode1();
     else if(mode==2)
       mode2();
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
      fa_ce(mode);
      getch();
     break;
   case 2:
      ke_fa(mode);
      getch();
     break;
   case 3:
      ke_ce(mode);
      getch();
     break;
   case 4:
      usd_eur(mode);
      getch();
     break;
   case 5:
      gbp_usd(mode);
      getch();
     break;
   case 6:
      chf_usd(mode);
      getch();
     break;
   case 7:
      jpy_usd(mode);
      getch();
     break;
   case 8:
      chf_eur(mode);
      getch();
     break;
   case 9:
      chf_gbp(mode);
      getch();
     break;
   case 10:
      gbp_eur(mode);
      getch();
     break;
   case 11:
      jpy_eur(mode);
      getch();
     break;
   case 12:
      jpy_gbp(mode);
      getch();
     break;
   case 13:
      rmb_usd(mode);
      getch();
     break;
   case 14:
      rmb_eur(mode);
      getch();
     break;
   case 15:
     rmb_jpy(mode);
     getch();
     break;
   case 16:
     pou_kilo(mode);
     getch();
     break;
   case 17:
     carat_gram(mode);
     getch();
     break;
   case 18:
     ounce_gram(mode);
     getch();
     break;
   case 19:
     troy_gram(mode);
     getch();
     break;
   case 20:
     stone_kilo(mode);
     getch();
     break;
   case 21:
     mile_km(mode);
     getch();
     break;
   case 22:
     meter_cm(mode);
     getch();
     break;
   case 23:
     inch_mm(mode);
     getch();
     break;
   case 24:
     cm_mm(mode);
     getch();
     break;
   case 25:
     cm_mm(mode);
     getch();
     break;
   case 26:
     feet_cm(mode);
     getch();
     break;
   case 27:
     feet_inch(mode);
     getch();
     break;
   case 28:
     feet_meter(mode);
     getch();
     break;
   case 29:
     yard_meter(mode);
     getch();
     break;
   case 30:
     nmile_km(mode);
     getch();
     break;
   case 31:
     acre_skm(mode);
     getch();
     break;
   case 32:
     sfeet_smeter(mode);
     getch();
     break;
   case 33:
     syard_smeter(mode);
     getch();
     break;
   case 34:
     smile_skm(mode);
     getch();
     break;
   case 35:
     sinch_scm(mode);
     getch();
     break;
   case 36:
     hectare_smile(mode);
     getch();
     break;
   case 37:
     acre_hectare(mode);
     getch();
     break;
   case 38:
     cinch_ccm(mode);
     getch();
     break;
   case 39:
     cfeet_cmeter(mode);
     getch();
     break;
   case 40:
     cyard_cmeter(mode);
     getch();
     break;
   case 41:
     if(mode==1)
      {
       mode2();
       mode=2;
      }
     else if(mode==2)
      {
       mode1();
       mode=1;
      }
     break;
   case 42:
      gotoxy(33,22);printf("Thank You");
     break;
   default:
      gotoxy(33,22);printf("Wrong choice");
      getch();
     break;
  }
 }while(ch!=42);
}