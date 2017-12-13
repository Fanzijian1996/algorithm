#include"algorithm.h"
#include<iostream>
#include<climits>
using namespace std;
void matrixChain(int **matrix,int **result,const int*p,int lenth,int low,int high)
{
  for(int i=low;i<=high;i++)
  {
    for(int j=i;j<=high;j++)
      matrix[i][j]=INT_MAX;
  }
  lookupChain(matrix,result,p,lenth,low,high);
}

int lookupChain(int **matrix,int **result,const int *p,int lenth,int low,int high)
{
  if(matrix[low][high]<INT_MAX)
    return matrix[low][high];
  if(low==high)
  {
    matrix[low][high]=0;
    result[low][high]=high;
  }
  else{
    for(int k=low;k<high;k++)
    {
      int temp=lookupChain(matrix,result,p,lenth,low,k)+
      lookupChain(matrix,result,p,lenth,k+1,high)+p[low-1]*p[k]*p[high];
      if(temp<matrix[low][high])
      {
        matrix[low][high]=temp;
        result[low][high]=k;
      }
    }
  }
  return matrix[low][high];
}
