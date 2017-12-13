#include"bubble_sort.h"
//increasing order
void bubbleSort(int array[],size_t n)
{
  for(size_t j=n-1;j>0;j--)
  {
    for(size_t i=0;i<j;i++)
    {
      if(array[i]>array[i+1])
      {
        int temp=array[i];
        array[i]=array[i+1];
        array[i+1]=temp;
      }
    }
  }
}
