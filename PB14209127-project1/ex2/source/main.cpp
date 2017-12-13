#include"algorithm.h"
#include"readfile.h"
#include<iostream>
#include<string>
#include<chrono>
#include<ctime>
#include<fstream>
#include<sstream>
// #define TEMP_LEN 10
//the size of array char temp[]
using namespace std;
int main()
{
  int assistant[6]={2,5,8,11,14,17};
  std::chrono::time_point<std::chrono::system_clock> start, end;
  //计时器
  int *array=nullptr;int *answer=nullptr;
  ofstream fileWrite("../output/result.txt",ofstream::out|ofstream::app);
  if(!fileWrite)
  {
    cerr<<"can not open result file"<<endl;
    exit(-1);
  }
  //
  ofstream timeWrite;
  fileWrite<<"bubbleSort:";
  cout<<"bubbleSort"<<endl;
  for(size_t j=0;j!=6;j++)
  {
    int index=pow(2,assistant[j]);
    //the size of input_file;
    // char temp[TEMP_LEN];
    stringstream stream;
    stream<<assistant[j];
    string buffer;
    buffer=stream.str();
    buffer="../input/input_file_"+buffer+".txt";
    string resultpath=to_string(assistant[j]);
    resultpath="../output/bubbleSort/result_"+resultpath+".txt";
    ofstream resultWrite(resultpath,fstream::out|fstream::trunc);
    string time_path("../output/bubbleSort/time.txt");
    // itoa(index,temp,10);
    // buffer=buffer+temp;
    array=readFile(buffer,index);
    if(array==nullptr)
    {
      cerr<<"read file failed!"<<endl;
      exit(-1);
    }
    timeWrite.open(time_path,fstream::out|fstream::app);
    if(!timeWrite)
    {
      cerr<<"can not open the file:time.txt"<<endl;
      exit(-1);
    }
    start = std::chrono::system_clock::now();
    bubbleSort(array,index);
    end = std::chrono::system_clock::now();
    for(size_t k=0;k!=index;k++)
    {
      resultWrite<<array[k]<<endl;
    }
    delete[] array;
    std::chrono::duration<double> elapsed_seconds = end-start;
    timeWrite<<"size:"<<assistant[j]<<"\t"<<"time:"<<elapsed_seconds.count()<<"s"<<endl;
    fileWrite<<elapsed_seconds.count()<<"s";
    if(j!=5)
      fileWrite<<",";
    timeWrite.close();
    resultWrite.close();
  }

  fileWrite<<endl;
  fileWrite<<"countSort:";
  cout<<"countSort"<<endl;
  for(size_t j=0;j!=6;j++)
  {
    int index=pow(2,assistant[j]);
    //the size of input_file;
    // char temp[TEMP_LEN];
    stringstream stream;
    stream<<assistant[j];
    string buffer;
    buffer=stream.str();
    buffer="../input/input_file_"+buffer+".txt";
    // itoa(index,temp,10);
    // buffer=buffer+temp;
    string resultpath=to_string(assistant[j]);
    resultpath="../output/countSort/result_"+resultpath+".txt";
    ofstream resultWrite(resultpath,fstream::out|fstream::trunc);
    string time_path("../output/countSort/time.txt");
    array=readFile(buffer,index);
    if(array==nullptr)
    {
      cerr<<"read file failed!"<<endl;
      exit(-1);
    }
    timeWrite.open(time_path,fstream::out|fstream::app);
    if(!timeWrite)
    {
      cerr<<"can not open the file:time.txt"<<endl;
      exit(-1);
    }
    answer=new int[index];
    start = std::chrono::system_clock::now();
    countSort(array,answer,index);
    end = std::chrono::system_clock::now();
    for(size_t k=0;k!=index;k++)
    {
      resultWrite<<answer[k]<<endl;
    }
    delete[] array;
    delete[] answer;
    std::chrono::duration<double> elapsed_seconds = end-start;
    fileWrite<<elapsed_seconds.count()<<"s";
    timeWrite<<"size:"<<assistant[j]<<"\t"<<"time:"<<elapsed_seconds.count()<<"s"<<endl;
    if(j!=5)
      fileWrite<<",";
    timeWrite.close();
    resultWrite.close();
  }
  fileWrite<<endl;
  fileWrite<<"quickSort:";
  cout<<"quickSort"<<endl;
  for(size_t j=0;j!=6;j++)
  {
    int index=pow(2,assistant[j]);
    //the size of input_file;
    // char temp[TEMP_LEN];
    stringstream stream;
    stream<<assistant[j];
    string buffer;
    buffer=stream.str();
    buffer="../input/input_file_"+buffer+".txt";
    // itoa(index,temp,10);
    // buffer=buffer+temp;
    string resultpath=to_string(assistant[j]);
    resultpath="../output/quickSort/result_"+resultpath+".txt";
    ofstream resultWrite(resultpath,fstream::out|fstream::trunc);
    string time_path("../output/quickSort/time.txt");
    array=readFile(buffer,index);
    if(array==nullptr)
    {
      cerr<<"read file failed!"<<endl;
      exit(-1);
    }
    timeWrite.open(time_path,fstream::out|fstream::app);
    if(!timeWrite)
    {
      cerr<<"can not open the file:time.txt"<<endl;
      exit(-1);
    }
    answer=new int[index];
    start = std::chrono::system_clock::now();
    quickSort(array,0,index);
    end = std::chrono::system_clock::now();
    for(size_t k=0;k!=index;k++)
    {
      resultWrite<<array[k]<<endl;
    }
    delete[] array;
    delete[] answer;
    std::chrono::duration<double> elapsed_seconds = end-start;
    fileWrite<<elapsed_seconds.count()<<"s";
    timeWrite<<"size:"<<assistant[j]<<"\t"<<"time:"<<elapsed_seconds.count()<<"s"<<endl;
    if(j!=5)
      fileWrite<<",";
    timeWrite.close();
    resultWrite.close();
  }
  fileWrite<<endl;
  fileWrite<<"radixSort:";
  cout<<"radixSort"<<endl;
  for(size_t j=0;j!=6;j++)
  {
    int index=pow(2,assistant[j]);
    //the size of input_file;
    // char temp[TEMP_LEN];
    stringstream stream;
    stream<<assistant[j];
    string buffer;
    buffer=stream.str();
    buffer="../input/input_file_"+buffer+".txt";
    // itoa(index,temp,10);
    // buffer=buffer+temp;
    string resultpath=to_string(assistant[j]);
    resultpath="../output/radixSort/result_"+resultpath+".txt";
    ofstream resultWrite(resultpath,fstream::out|fstream::trunc);
    string time_path("../output/radixSort/time.txt");
    array=readFile(buffer,index);
    if(array==nullptr)
    {
      cerr<<"read file failed!"<<endl;
      exit(-1);
    }
    timeWrite.open(time_path,fstream::out|fstream::app);
    if(!timeWrite)
    {
      cerr<<"can not open the file:time.txt"<<endl;
      exit(-1);
    }
    answer=new int[index];
    start = std::chrono::system_clock::now();
    radixSort(array,answer,index);
    end = std::chrono::system_clock::now();
    for(size_t k=0;k!=index;k++)
    {
      resultWrite<<answer[k]<<endl;
    }
    delete[] array;
    delete[] answer;
    std::chrono::duration<double> elapsed_seconds = end-start;
    fileWrite<<elapsed_seconds.count()<<"s";
    timeWrite<<"size:"<<assistant[j]<<"\t"<<"time:"<<elapsed_seconds.count()<<"s"<<endl;
    if(j!=5)
      fileWrite<<",";
    timeWrite.close();
    resultWrite.close();
  }
  fileWrite<<endl;
  fileWrite.close();
  return 0;
}
