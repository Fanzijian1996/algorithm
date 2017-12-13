#include"algorithm.h"
#define SCALAR 65535
//bubble sort
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

//count sort
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

//quick sort
size_t partition(int array[],int p,int r)
{
  // we use [) section
  // boundary detection to be done
  int i=p-1;//here may be logic error
  //std::cout<<i<<std::endl;
  int keyword = array[r-1];
  //std::cout<<"r:"<<r<<","<<p<<std::endl;
  for(int j=p;j!=r-1;j++)
  {
    //std::cout<<"2"<<std::endl;
    if(array[j]<=keyword)
    {//swap
      int temp=array[++i];
      array[i]=array[j];
      array[j]=temp;
    }
  }
  array[r-1]=array[++i];

  array[i]=keyword;
  return i;
}

void quickSort(int array[],int p,int r)
{
  if(p<r-1)
  {
    size_t q=partition(array,p,r);
    // std::cout<<p<<","<<q<<","<<r<<std::endl;
    quickSort(array,p,q);
    quickSort(array,q+1,r);
  }
  else
    return;
}

//radix sort
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
