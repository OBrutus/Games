#include<stdio.h>
#include<sys/ioctl.h>
#include<string.h>

int size(int *r,int *c)
{
    struct winsize max;
    int row;
    ioctl(0, TIOCGWINSZ , &max);
    //    printf ("lines %d\n", max.ws_row);
    //    printf ("columns %d\n", max.ws_col);
    row=*r=max.ws_row;
    *c=max.ws_col;
    return row;
}

int center(char *s)
{
  int r,c,i,l;
  size(&r,&c);
  l=strlen(s);
  for(i=0;i<(c-l)/2;i++)
    {
      printf(" ");
    }
  for(i=0;i<s[i]!='\0';i++)
    printf("%c",s[i]);
  return 0;
}
