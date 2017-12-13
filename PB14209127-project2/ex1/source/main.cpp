#include"algorithm.h"
#include"random.h"
#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
#include<chrono>
using namespace std;
#define LEN 10
void print(int **result,ofstream &resultW,int low,int high)
{
  if(low==high)
    resultW<<"A"<<low;
  else
  {
    resultW<<"(";
    print(result,resultW,low,result[low][high]);
    print(result,resultW,result[low][high]+1,high);
    resultW<<")";
  }
}
int main()
{
  const int size[LEN]={5,10,20,30,50,100,150,200,500,1000};
  int **matrix=nullptr;
  int **result=nullptr;
  int *p=nullptr;
  const string path="../output/result.txt";
  const string timePath="../output/time.txt";
  std::chrono::time_point<std::chrono::system_clock> start, end;
  //clock
  ofstream resultW(path,fstream::out|fstream::trunc);
  ofstream timeW(timePath,fstream::out|fstream::trunc);
  if(!resultW)
  {
    cerr<<"can't open the file "<<path<<endl;
    exit(-1);
  }
  for(int i=0;i<LEN;i++)
  {
    //cout<<size[i]<<endl;
    int sizel=size[i];
    p=new int[sizel+1];
    if(!p){
      cerr<<"malloc failed\n";
      exit(-1);
    }
    randomNum(sizel+1,p);
    //create random array
    matrix=new int*[sizel+1];
    result=new int*[sizel+1];
    for(int k=0;k<=sizel;k++)
    {
      matrix[k]=new int[sizel+1];
      result[k]=new int[sizel+1];
    }
    start = std::chrono::system_clock::now();
    matrixChain(matrix,result,p,sizel,1,sizel);
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    //write the result
    resultW<<"size:"<<sizel<<endl;
    print(result,resultW,1,sizel);
    resultW<<endl;
    //write the time resultW
    timeW<<"size:"<<sizel<<endl;
    timeW<<"time:"<<elapsed_seconds.count()<<"s"<<endl;
    //free the memory

    for(int k=0;k<sizel+1;k++)
    {
      delete[] matrix[k];
      delete[] result[k];
    }
    delete[] matrix;
    delete[] result;
    delete[] p;
  }
  resultW.close();
  timeW.close();
  return 0;
}
