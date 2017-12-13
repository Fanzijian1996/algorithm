### 1.Overview

代码由两个独立的模块组成。

模块1：`algorithm.cpp`,`readfile.cpp`, `main.cpp`。
其中，`algorithm.cpp`为算法部分，`readfile.cpp`为文件读取部分，`main.cpp`为主函数。

模块2：`random.cpp`为产生随机数的文件。

*编译的时候应该分开运行*。

如需检查结果，输入
`c++ algorithm.cpp readfile.cpp main.cpp -o main -std=c++11`
产生可执行文件`main`,输入 `c++ random.cpp -o random -std=c++11`,产生`random`用于产生生成随机数的可执行文件，或者使用`Makefile`。

### 2.Analysis

实验流程与教材类似，首先做`FFT`,得到两个相应的点值表达式，两个点值表达式做乘法，得到乘法结果的点值表达式，再做一个逆FFT,得到最终结果。

关键代码如下：
```
void ffTran(const vector<double>&vec,vector<complex<double>>&result)
{
  if(vec.size()==1){
    complex<double> element(vec[0],0);
    result[0]=element;
    return;
  }
  complex<double> temp(0,2*pi/vec.size());
  complex<double> wn=exp(temp);
  complex<double> w(1.0,0);
  vector<double> coe1,coe2;
  for(int i=0;i<vec.size();i++)
  {
    (i%2==0)?coe1.push_back(vec[i]):coe2.push_back(vec[i]);
  }
  vector<complex<double>> result1(coe1.size()),result2(coe2.size());

  ffTran(coe1,result1);
  ffTran(coe2,result2);
  for(int k=0;k<vec.size()/2;k++)
  {
    result[k]=result1[k]+w*result2[k];
    result[k+vec.size()/2]=result1[k]-w*result2[k];
    w=w*wn;
    //cout<<w<<endl;
  }
}
```
以及逆FFT
```
void iffTran(const vector<complex<double>>&vec,vector<complex<double>>&result)
{
  if(vec.size()==1){
    result[0]=vec[0];
    return ;
  }
  complex<double> temp(0,-2*pi/vec.size());
  complex<double> wn=exp(temp);
  complex<double> w(1,0);
  vector<complex<double>> coe1,coe2;
  for(int i=0;i<vec.size();i++)
  {
    if(i%2==0){
      coe1.push_back(vec[i]);
    }
    else{
      coe2.push_back(vec[i]);
    }
  }
  vector<complex<double>> result1(coe1.size()),result2(coe2.size());
  iffTran(coe1,result1);
  iffTran(coe2,result2);
  for(int k=0;k<vec.size()/2;k++)
  {
    result[k]=result1[k]+w*result2[k];
    //cout<<temp<<endl;

    result[k+vec.size()/2]=result1[k]-w*result2[k];
    w=w*wn;
    //cout<<temp<<endl;
  }
  return;
}
```
