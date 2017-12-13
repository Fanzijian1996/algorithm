#include"algorithm.h"
#define pi 3.1415926535
#define EPSILON 1E-3l//判断是否为零
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
  // cout<<wn<<endl;
  // cout<<w<<endl;
  // cout<<w*wn<<endl;
  // exit(-1);
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
// ordinary algorithm
void multiply(const vector<double>&vec1,const vector<double>&vec2,vector<double>&result)
{
  int totalSize=vec1.size()+vec2.size()-1;
  for(int k=0;k<totalSize;k++)
  {
    double temp=0;
    for(int i=0;i<vec1.size();i++)
    {
      int j=k-i;
      if(j<vec2.size())
        temp+=vec1[i]*vec2[j];
    }
    result[k]=temp;
  }
}

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
void fft(const vector<double>&vec1,const vector<double>&vec2,vector<complex<double>>&result)
{
  vector<double>vectemp1(vec1);
  vector<double>vectemp2(vec2);
  for(int i=0;i<vec1.size();i++)
    vectemp1.push_back(0);
  for(int j=0;j<vec2.size();j++)
    vectemp2.push_back(0);
    // cout<<vectemp1.size()<<endl;
  vector<complex<double>>vecfft1(vectemp1.size());
  vector<complex<double>>vecfft2(vectemp2.size());

  ffTran(vectemp1,vecfft1);
  ffTran(vectemp2,vecfft2);
  // cout<<"FFT:"<<endl;
  // for(int i=0;i<vecfft1.size();i++)
  //    cout<<vecfft2[i]<<endl;
//  multiply
  vector<complex<double>> vecmulp;
  // cout<<"multiply:"<<endl;
  for(int i=0;i<vecfft1.size();i++)
  {
    vecmulp.push_back(vecfft1[i]*vecfft2[i]);
  }
  // for(int i=0;i<vecmulp.size();i++)
  //   cout<<vecmulp[i]<<endl;
  //interpolation
  iffTran(vecmulp,result);
  // cout<<"IFFT:"<<endl;
  // for(int i=0;i<result.size();i++)
  // {
  //   cout<<result[i].real()/result.size()<<endl;
  // }
  complex<double> temp(result.size(),0);
  for(int i=0;i<result.size();i++)
  {
    result[i]=result[i]/temp;
    if(abs(result[i])<EPSILON)
      result[i]=0;
  }
}
