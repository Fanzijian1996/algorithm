#include"readfile.h"
#include"algorithm.h"
#include<iostream>
#include<chrono>
#include<fstream>
using namespace std;

int main(int argc,char **argv)
{
  string filepath;
  const string resultpath="../output/result.txt";
  const string timepath="../output/time.txt";
  ofstream resultWriter(resultpath,fstream::out|fstream::trunc);
  ofstream timeWriter(timepath,fstream::out|fstream::trunc);
  if(argc==1)
  {
    cout<<"  using default file path!"<<endl;
    filepath="../input/input.txt";
  }
  else{
    filepath=argv[1];
  }
  std::chrono::time_point<std::chrono::system_clock> start, end;
  //clock
  size_t offset=0;

  int lenth[4]={4,16,32,60};
  //fft
  for(int k=0;k<4;k++)
  {
    vector<double> vec1,vec2;
    offset=readfile(vec1,filepath,lenth[k]);
    readfile(vec2,filepath,lenth[k],offset);
    if(k==3){
      for(int i=0;i<4;i++){
        vec1.push_back(0);
        vec2.push_back(0);
      }

    }
    vector<double> result(vec1.size()+vec2.size());
    vector<complex<double>> result1(vec1.size()+vec2.size());

    //fft(vec1,vec2,result1);
    start = std::chrono::system_clock::now();
    fft(vec1,vec2,result1);
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    timeWriter<<"size:"<<lenth[k]<<endl;
    timeWriter<<"fftTime:"<<elapsed_seconds.count()<<"s"<<endl;
    start = std::chrono::system_clock::now();
    multiply(vec1,vec2,result);
    end = std::chrono::system_clock::now();
    elapsed_seconds = end-start;
    timeWriter<<"NormalTime:"<<elapsed_seconds.count()<<"s"<<endl;
    resultWriter<<"size:"<<result.size()-1<<endl;
    resultWriter<<"FFT:"<<endl;
    for(int i=0;i<result1.size()-1;i++)
    {
      resultWriter<<result1[i].real()<<",";
    }
    resultWriter<<result1.back().real()<<endl;
    resultWriter<<endl;
    resultWriter<<"Normal:"<<endl;
    for(int i=0;i<result.size()-1;i++)
    {
      resultWriter<<result[i]<<",";
    }
    resultWriter<<result.back()<<endl;
    resultWriter<<endl;
  }
  timeWriter.close();

  return 0;
}
