#include"random.h"
#include<ctime>
#include<cstdlib>
#define MIN 0
#define MAX 255
//the random number is in [MIN,MAX]
void randomNum(int lenth,int *p)
{
  srand((unsigned)time(NULL));
  for(int i=0;i<lenth;i++)
  {
    *(p+i)=rand()%(MAX-MIN+1)+MIN;
  }
}
