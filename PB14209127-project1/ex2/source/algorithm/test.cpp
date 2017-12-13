#include"radix_sort.h"
using namespace std;
int main()
{
  int array[4]={2,1,6,7};
  //bubbleSort(4,array);
  //int answer[4];
  //countSort(array,answer,4);
  //quickSort(array,0,4);
  int answer[4];
  radixSort(array,answer,4);
  for(size_t i=0;i!=4;i++)
    cout<<answer[i]<<endl;
  return 0;
}
