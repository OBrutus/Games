#include<cstdio>
#include<iostream>
#include"center.h"
#include"getch.h"
#include<cstring>
#include<stdlib.h>
#include<string>
#include<math.h>
#include<unistd.h>

void info();
void banner();
int start()
{
  printf("\nthis is start\n");
  return 0;
}
int ToInt(char *s)
{
  int n=0,l,i;
  l=strlen(s);
  for(i=0;i<l;i++)
  {
      if(*s>='a' && *s<='z')
	  {
  	  n=n+10*(*(s+i)-'a');
	    continue;
	  }
    if(*s>='A' && *s<='Z')
	  {
  	  n=n+10*(*(s+i)-'A');
	    continue;
	  }
    if(*s>='0' && *s<='9')
  	{
	    n=n+10*(*(s+i)-'0');
	    continue;
	  }
  }
  return 0;
}

void swap(int *a,int *b)
{
	*a=*a+*b;
	*b=*b-*a;
	*a=*a-*b;
}

void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}

class play
{
public:
  int **a,n;
  play()
  {
        int j,ch;
    //    printf("\nEnter the difficulty\n");
    do
      {
	printf("\nEnter the Difficulty\t:");
	scanf("%d",&ch);
	if(ch<3 || ch >9)
	  {
	    printf("\nYou cannot enter no. less than 2");
	    printf("press Enter for default value 4");
	    fflush(stdin);
	    std::cout<<std::endl<<'\b';
	    ch=getch();
	    if(ch==10)
	      {
		        n=4;
		        break;
	      }
	  }
      }while(ch>9 || ch<2);
    n=ch;
    a=new int* [n];
    for(int i=0;i<n;i++)
      a[i]=new int[n];
    for(int i=0;i<n;i++)
      for(j=0;j<n;j++)
	       a[i][j]=0;////////////////////////////////////////
  }
  play(int in)
  {
    int i,j;
    n=in;
    a=new int*[n];
    for(i=0;i<n;i++)
      a[i]=new int[n];
    for(i;i<n;i++)
      for(j=0;j<n;j++)
	a[i][j]=0;
  }
  ~play()
  {
    int i;
    printf("Dis.");
    for(i=0;i<n;i++)
      delete a[i];
    delete []a;
  }
  /*
    If you can align always 
    display within center then,
    feel free to do so.
  */
  int display()
  {
    int i,j;
    char s[n+(n-1)*2];
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      	printf("%4d",a[i][j]);
      printf("\n\n");
    }
    return 0;
  }

  int getorder()
  {
    int i,j;
    scanf("%d",&n);

    if(n<3)
    {
        printf("You cannot enter order %d\nSetting order to : 4 !\n",n );
        n=4;
        printf("Enter any Key to start.");
        getch();
    }
    a=new int*[n];
    for(i=0;i<n;i++)
      a[i]=new int[n];
    for(i=0;i<n;i++){
      for(j=0;j<n;j++)
        a[i][j]=0;
    }
    printf("\n");
    return 0;
  }

  int IsFull()
  {
    int i,j;
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
	if(a[i][j]==0)
	  return 0;
    return 1;
  }
  int update();
  int down();
  int up();
  int right();
  int left();
};

int play::update()
{
  int ins,j,i=rand()%2;
  if(i==0)
    ins=2;
  else
    ins=4;
  do
    {
      i=rand()%n;
      j=rand()%n;
    }while(a[i][j]!=0);
  a[i][j]=ins;
  return 0;
}

int play::down()
{
  int i,j,k;
  for(j=n-1;j>=0;j--)
    {
      for(i=n-1;i>0;i--)
	if(a[i][j]==a[i-1][j])
	  {
	    a[i-1][j]=0;
	    a[i][j]=2*a[i][j];
	  }
      for(k=0;k<n-1;k++)
	for(i=n-1;i>0;i--)
	  {
	    if(a[i][j]==0 && a[i-1][j]!=0)
	      swap(a[i][j],a[i-1][j]);
	  }
    }
  return 0;
}

int main_menu()
{
  int in;
  system("clear");
  banner();
  printf("\n\n\n");
  printf((char *)"***Menu***");
  printf("\n");
  printf((char *)"1.Enter_Game");
  printf("\n");
  printf((char *)"2.Game_Info");
  printf("\n");
  printf((char *)"0.Exit");
  printf("\n");
  printf((char *)"Input_plz______:");
  scanf("%d",&in);
  return in;
}

void quit()
{
  printf("Thanks for playing.\n");
  printf("See you soon....\nBye!\n");
  exit(0);
}

int main()
{
  play a(4);
  int ch;
  system("clear");
  banner();
  getch();
  ch=99;
  while(ch!=0 && ch!=1)
  {
    banner();
    ch=main_menu();
    switch(ch)
		{
		case 0:
		  quit();
		  break;

		case 1: //mini menu
		  printf("\t1.Play (%d)\n",a.n);
		  printf("\t2.custom\n");
		  printf("\t3.back\t: ");
		  scanf("%d",&ch);
      if(ch==2)
      {
        printf("\t  Enter order : ");
        a.getorder();
        break;
      }
		  else if(ch==3)
		    ch=main_menu();
      else if(ch==1)
        break;
      else{
        printf("Wrong input ");
        ch=main_menu();
      }

		case 2:
		  info();
		  break;
		}
  }//end while
  system("clear");
  printf("Lets start game\nPress any key to continue");
  std::cout<<std::endl;
  fflush(stdin);
  getch();
  system("clear");
  ch=1;
  a.update();
  banner();
  while(!a.IsFull() && ch !=0)
    {
      a.display();
      scanf("%d",&ch);
      switch(ch)
      {
        case 0:
          printf("\nyou opt in to quit\nDo you really want to quit (0/1):\t");
          break;
        case 2:
          a.down();
          break;
        case 8:
          a.up();
          break;
        case 4:
          a.left();
          break;
        case 6:
          a.right();
          break;
        default:
          printf("You entered Wrong input\n");
      }
      if(ch==0)
        scanf("%d",ch);
      if(ch==1){
        printf("You opt in to QUIT in middle of the game\n");
        printf("Thats fine !!");
        quit();
      }
      printf("\n****************\n");
      a.update();
    }
    if(ch!=1)
      printf("\n************\nYou loose this time\nBetter luck next time");
  return 0;
}

void info()
{
  fflush(stdin);
  system("clear");
  printf("The Game 2048 is an awsome refreshment.\n");
  printf("So here is the near to approch of such.\n");
  printf("Before satrting the talk,\n");
  printf("\tThanks for downloading this, \n");
  printf("\tfor more such interesting stuffs visit :\n");
  printf("\t\thttps://github.com/OBrutus?tab=repositories");
  //printf("This game is ");

  printf("In upcoming updates you will able to see : \n");
  printf("\tMuti player functionality\n");
  printf("\tSaving Current game state to file\n");
  printf("\tAuto solve the easy parts (which do not need more brain power)\n");
  printf("\tBetter UI/UX\nAnd Lots more\n");
  printf("STAY TUNED !!!\n\n\n");
  printf("Press any key to go back. ");
  char ch;
  printf("Is this info was useful ? [y/n] : ");
  std::cin>>ch;
  switch(ch){
    case 'y':
    case 'Y':
      printf("Thanks for the compliment !!\n");
      break;
    case 'n':
    case 'N':
      printf("Feel free to dm the changes you would make\n");
  }
  for(int i=0;i<10;i++){
    std::cout<<".";
    usleep(100000);
  }
}

int play::up()
{
  //printf("\nI am up\n");
  int i,j,k;
  for(j=0;j<4;j++)
    {
      for(i=0;i<3;i++)//reassign
  if(a[i][j]==0 && a[i+1][j]!=0)
    swap(a[i][j],a[i+1][j]);
      for(i=0;i<3;i++)
  if(a[i][j]==a[i+1][j])
    {
      a[i][j]*=2;
      a[i+1][j]=0;
    }
      for(i=0;i<3;i++)
  if(a[i][j]==0 && a[i+1][j]!=0)
    swap(a[i][j],a[i+1][j]);
    }
  return 0;
}
int play::left()
{
  //printf("\nI am left\n");
  int i,j,k;
  for(i=0;i<4;i++)
  {
    for(j=0;j<3;j++)
      if(a[i][j]==0 && a[i][j+1]!=0)
        swap(&a[i][j],&a[i][j+1]);
        for(j=0;j<3;j++)
      if(a[i][j]==a[i][j+1])
      {
        a[i][j]*=2;
        a[i][j+1]=0;
      }
      for(j=0;j<3;j++)
        if(a[i][j]==0 && a[i][j+1]!=0)
          swap(&a[i][j],&a[i][j+1]);
  }
  return 0;
}
int play::right()
{
  //printf("\nI am right\n");
  int i,j,k;
  for(i=0;i<n;i++)
  {
    for(k=0;k<n-1;k++)
    for(j=n-1;j>0;j--)
      if(a[i][j]==0 && a[i][j-1]!=0)
        swap(a[i][j],a[i][j-1]);
    for(j=n-2;j>=0;j--)
      if(a[i][j]==a[i][j+1])
      {
        a[i][j+1]*=2;
        a[i][j]=0;
      }
      for(k=0;k<n-1;k++)
      for(j=n-1;j>0;j--)
        if(a[i][j]==0 && a[i][j-1]!=0)
          swap(a[i][j],a[i][j-1]);
  }
  return 0;
}

void banner(){
  center((char*)" ========================="); printf("\n");
  center((char*)"||     Welcome to 2048   ||"); printf("\n");
  center((char*)" ========================="); printf("\n");
}
