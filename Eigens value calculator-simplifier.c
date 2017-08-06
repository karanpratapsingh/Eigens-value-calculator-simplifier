#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

///////////////////////////////////////////////////////////////////////////////

/*This program calculates the eigens value of the given matrix.*/

/* EIGENS VALUE CALCULATOR */
/* Date : 5th Aug 2017 */
/* By : Vertigo_101. */

///////////////////////////////////////////////////////////////////////////////

void about();
void loading();
void calculating();
void delay();
void eigens(int,int,int);
void gotoxy(int,int);
int main()
{
  system("cls");

  about();
  loading();

  system("cls");

  int a[3][3];
  int a0,a1 ,a2 ,a3;
  short int i ,j;
  char ch[] = {229,182,98,181};

  gotoxy(70,4);
  puts("|| EIGENS VALUE CALCULATOR/SIMPLIFIER ||");

  gotoxy(68,10);
  printf("[+] Enter the matrix (row by row) :");

  int s[] = {NULL,13,14};
  gotoxy(79,12);
  for(i=0;i<3;i++) {
      if(i==1 || i == 2) {
        gotoxy(79,s[i]);
      }

      for(j=0;j<3;j++) {
            scanf("\t%d",&a[i][j]);
    }
  }
//Calculates.

  a0 = 1;


  a1 = (-1)*(a[0][0] + a[1][1] + a[2][2]);


  a2 = ((a[1][1]*a[2][2]) - (a[1][2]*a[2][1]))

       + ((a[0][0]*a[2][2]) - (a[0][2]*a[2][0]))

       + ((a[0][0]*a[1][1]) - (a[0][1]*a[1][0]));


  a3 = (-1)*((a[0][0])*((a[1][1]*a[2][2]) - (a[1][2]*a[2][1]))

      - (a[0][1])*((a[1][0]*a[2][2]) - (a[1][2]*a[2][0]))

      + (a[0][2])*((a[1][0]*a[2][1]) - (a[1][1]*a[2][0])));


//Prints the matrix.


gotoxy(68,16);
puts("[^] You have entered the matrix :");

int p[]={NULL,19,20};

gotoxy(68,18);
for(i=0;i<3;i++) {

   if(i == 1 || i == 2) {
     gotoxy(68,p[i]);
    }

    for(j=0;j<3;j++) {
       printf("\t %d",a[i][j]);
      }
  }


//Calculating animation.


    calculating();


//Prints the result.
int an1,an2,an3;

  gotoxy(68,25);
  printf(" > a1 is %d",an1=(-1)*(a1));

  gotoxy(68,26);
  printf(" > a2 is %d",an2=(a2));

  gotoxy(68,27);
  printf(" > a3 is %d",an3=(-1)*(a3));

  gotoxy(68,29);
  printf("[*] Equation is : %c^3 + (%d)%c^2 + (%d)%c + (%d) = 0. ",ch[0],a1,ch[0],a2,ch[0],a3);

  eigens(a1,a2,a3);

printf("\n");
system("pause");
  return 0;
}
///////////////////////////////////////////////////////////////////////////////
void about()
{
  gotoxy(70,17);
  printf("/* EIGENS VALUE CALCULATOR/SIMPLIFIER */");

  gotoxy(70,18);
  printf("/* Date : 5th Aug 2017 */");

  gotoxy(70,19);
  printf("/* By : Vertigo_101. */");

}
///////////////////////////////////////////////////////////////////////////////
void loading()
{
  int i;
  char ch[2] = {177,178};

  gotoxy(63,23);
  printf("[#] LOADING PROGRAM :");

  gotoxy(85,23);
  for(i=0;i<=25;i++) {

    delay();
    printf("%c",ch[0]);
  }

  gotoxy(85,23);
  for(i=0;i<=25;i++) {

    delay();
    printf("%c",ch[1]);
  }


}
///////////////////////////////////////////////////////////////////////////////
void calculating()
{
  int i;
  char ch[2] = {177,178};

  gotoxy(68,23);
  printf("[#] CALCULATING  :");

  gotoxy(90,23);
  for(i=0;i<=20;i++) {

    delay();
    printf("%c",ch[0]);
  }

  gotoxy(90,23);
  for(i=0;i<=20;i++) {

    delay();
    printf("%c",ch[1]);
  }

}
///////////////////////////////////////////////////////////////////////////////
void eigens(int a1,int a2,int a3)
{

  int val,valf;
  char ch[] = {229,182,98,181,NULL,'y','n'};


  gotoxy(68,31);
  printf("[?] Do you want to simplify the equation for %c ?(y/n) : ",ch[0]);

  getchar();

  gotoxy(124,31);
  scanf("%c",&ch[4]);

  if(ch[4] == ch[5]) {
    delay();
    delay();
    delay();
    delay();
  }
  else {
    delay();
    gotoxy(68,32);
    printf("[X] Exiting....");
    delay();
    exit(0);
  }

  gotoxy(68,32);
  printf("[?] Please enter the value of %c by which eigens equation = 0 : ",ch[0]);
  gotoxy(131,32);
  scanf("%d",&val);

  //Simplification Algorithm.

  int afinal[5] = {NULL,NULL,NULL,NULL,NULL};

  valf = (-1)*(val);

  //1
  afinal[0] = 1;

  //2
  afinal[1] = (a1 + (afinal[0])*(val));

  //3
  afinal[2] = (a2 + (afinal[1])*(val));

  //4
  afinal[3] = (a3 + (afinal[2])*(val));

  if(afinal[3] == 0)
  {
    gotoxy(68,34);
    puts("[~] The Algorithm working, value you entered was correct.");
    delay();
    delay();
  }
  else {
    gotoxy(68,34);
    printf("[x] Not working Value of %c entered was wrong.",ch[0]);

    delay();

    /*char c[2] = {NULL,'y'};*/

    char c;
    gotoxy(68,35);
    printf("[?] Retry? (y/n) :");

    getchar();
    gotoxy(87,35);
    scanf("%c",&c);

    /*if(c[0] == c[1]) {}*/

      delay();
      system("cls");
      main();

    /*
    else {
      delay();
      gotoxy(68,37);
      printf("[X] Exiting....");
      delay();
      exit(1);
    }
    */
  }

  delay();
  delay();

  gotoxy(78,35);
  printf("%d    %d    %d    %d",afinal[0],afinal[1],afinal[2],afinal[3]);

  gotoxy(68,36);
  printf("[>>] The simplified equation becomes [%c + (%d)][%c^2 + (%d)(%c) + (%d)]",ch[0],valf,ch[0],afinal[1],ch[0],afinal[2]);

  system("pause");

}
///////////////////////////////////////////////////////////////////////////////
void gotoxy(int x,int y)
{
    COORD c;

    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);

}
///////////////////////////////////////////////////////////////////////////////
void delay()
{

  long unsigned int i;
//add delay
  for(i=0;i<=13699999;i++);

}
///////////////////////////////////////////////////////////////////////////////
