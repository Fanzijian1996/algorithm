### 编译环境：
1. clang version 4.0.1
2. Ubuntu 16.04.3 LTS

`algorithm.cpp` 为算法，`random.cpp` 为随机数生成模块，`main.cpp` 为主函数。

***
在ex1中，数据即时生成，然后从内存中读取，文件读取模块在ex2中有实现。
***
如要测试，请在相应的终端输入：

```
 c++ main.cpp algorithm.cpp random.cpp -o main -std=c++11

./main
```
或者直接运行`Makefile`

关键代码如下：
```
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
```
其中`matrix`数组保存矩阵链乘法的代价，`result`保存相应区间的分割。
