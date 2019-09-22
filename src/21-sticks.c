#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

void user();
void dis();
void err();
int cpu();
int cpu2();
int ch();

int p,n,tch,w=10,l;

int main()
{
 n=21;	//if(n<=8) actual prog starts
 ch();// choics toss
									//While
 do
 {
  if (w==1||w==2)
   break;
  dis();
  if(n>=8)
  {							//while if true
   cpu();
   user();
  }							//while if true
  else
  {							// while if false
   cpu2();
   user();
  }							// while if false
 }
 while(n);
 if(w==1)
  printf("\n***************I won*******************");
 else if (w==2)
  printf("\n***************U won*******************");
 else
  printf("******************************************");
return 0;
}// main()

void user()
{
 E:
 printf("\nYour turrn to pick up:\t\t");
 scanf("%d",&p);
 if(p>0 && p<5 && n-p>=0)
  {
   printf("\nYou picked %d sticks",p);
   n=n-p;
  }
 else if(n-p>0)
 {
  printf("\n####\nWrong Choice");
  goto E;
 }
 
 if((n-p)<=0)
   w=1;
}

void dis()
{
 int i;
 printf("\nSticks left are %d\n",n);
 for(i=0;i<n;i++)
  printf("| ");
 printf("\n");
 for(i=0;i<n;i++)
  printf("  ");
 printf("(%d)",n);
 printf("\n");
}

void err()
{
 printf("\n##Err:Your response was is !nvalid\nYou are a cheater and hence it is now my turn\n");
}

int ch()
{
 printf("\nToss starts");
 printf("\nTo decide who is 1st lets toss choose\n1:Heads and 2:Tales\n\t");
 scanf("%d",&tch);

 if (!(tch==1 || tch==2))	//mega if
 {
  err();			//mega if true
  return 0;
 }
  else
 {				//mega if false
  if(l) //make a toss
  {				//toss win
   if(tch==1)
    printf("\nOh! it is Heads");
   else
    printf("\nOh it is Tales");
   printf("\nYou won");
   user();
  }				//toss win
  else
  {				//toss loose
   if(tch==2)
    printf("\nOops! it was Heads");
   else
    printf("\nOops! it was Tales");
   printf("You loose toss");
  }				//toss loose
 }				//mega if
 return 0;
}// ch()

int cpu()
{
   A:
    p=rand();
    if(p%10<=0 ||  p%10>4)
      goto A;
   printf("\nMy turn I pick %d sticks",p%10);
   n=n-(p%10);
   dis();
   return 0;
} //cpu()

int cpu2()
{
 if(n<=5)
 {
  p=n-1;
  if(p!=1)
   w=0;
  printf("\nMy turn I pick %d sticks",p);
  n=n-p;
  dis();
  return 0;
 }
 else
 {
  if(n<=7 && n>6)
   p=1;
  printf("I choose 1");
  n--;
  dis();
 }
 //if(n-p<=0)
  w=2;
}

int toss()
{
 l=rand();
 l%=10;
 if(l<5)
  l=1;
 else
  l=0;
return l;
}
