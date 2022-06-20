#include <stdio.h>
#include <math.h>
int fstartingday(int month,int year)
{
  int h,q,m,k,j,day;
  
  
  day=1;
  if(month == 1)
  {
    month = 13;
    year--;
  }
  if (month == 2)
  {
    month = 14;
    year--;
  }
  q = day;
  m = month;
  k = year % 100;
  j = year / 100;
  h = q + 13*(m+1)/5 + k + k/4 + j/4 + 5*j;
  h = h % 7;
  if(h==0){
    h=7;
  }
  return h;
}