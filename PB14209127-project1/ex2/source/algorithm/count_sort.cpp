#include"count_sort.h"
#define SCALAR 65535
//SCALAR is the size of the Array assi[];
void countSort(int array[],int answer[],size_t n)
{
  //the answer store the result
  //the number varies from 1 to 65535
  int assi[SCALAR+1];
  //the assi[0] is not used
  for(size_t i=0;i!=SCALAR+1;i++)
    assi[i]=0;
  for(size_t i=0;i!=n;i++)
    assi[array[i]]=assi[array[i]]+1;
  //now the assi[] contains the number of elements equal to i
  for(size_t i=1;i!=SCALAR+1;i++)
    assi[i]=assi[i]+assi[i-1];
  //now contains the number of elements less than or equal to i
  for(int i=n-1;i>=0;i--)
  {
    answer[assi[array[i]]-1]=array[i];
    assi[array[i]]--;
  }
}
