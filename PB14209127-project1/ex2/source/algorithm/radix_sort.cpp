#include"radix_sort.h"
int keyWord(int number,int i)
{
  int upperBound=pow(10,i);
  int lowerBound=pow(10,i-1);
  int temp=number%upperBound;
  int result=temp/lowerBound;
  return result;
}

void countSort(int array[],int answer[],size_t n,int radix)
{
  int assi[10]={0};
  for(size_t i=0;i!=n;i++)
    assi[keyWord(array[i],radix)]=assi[keyWord(array[i],radix)]+1;
  for(size_t i=1;i!=10;i++)
    assi[i]=assi[i]+assi[i-1];
  for(int i=n-1;i>=0;i--)
  {
    answer[assi[keyWord(array[i],radix)]-1]=array[i];
    assi[keyWord(array[i],radix)]--;
  }
}

void radixSort(int array[],int answer[],size_t n)
{
  for(int i=1;i<=5;i++)
  {
    countSort(array,answer,n,i);
    for(size_t j=0;j!=n;j++)
    {
      array[j]=answer[j];
      //answer[i]=0;
    }
  }
}
