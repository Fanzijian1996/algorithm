#include"quick_sort.h"
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
