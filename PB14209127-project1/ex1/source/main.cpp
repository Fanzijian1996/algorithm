#include"algorithm.h"
#include"createstring.h"
#include"readfile.h"
#include<string>
#include<iostream>
#include<fstream>
#include<chrono>
#include<ctime>
using namespace std;
int main()
{
  int assistant[6]={2,5,8,11,14,17};
  std::chrono::time_point<std::chrono::system_clock> start, end;
  //计时器
  cout<<"start creating the random file!"<<endl;
  for(size_t i=0;i!=6;i++)
  {
    string path=to_string(assistant[i]);
    path="../input/input_file_"+path+".txt";
    //cout<<"creating :"<<"\t"<<path<<"..."<<endl;
    createString(assistant[i]);
  }
  cout<<"the files have been created respectively"<<endl;
  ofstream fileWrite("../output/time.txt",fstream::out|fstream::trunc);
  if(!fileWrite)
  {
    cerr<<"cannot open file:../output/time.txt"<<endl;
    exit(-1);
  }
  ofstream timeWrite;
  // /**************************insertSort*********************/
  fileWrite<<"insertSort:";
  cout<<"insertSort"<<endl;
  for(size_t i=0;i!=6;i++)
  {

    string result_path=to_string(assistant[i]);
    string path=to_string(assistant[i]);
    string time_path("../output/insertSort/time.txt");
    path="../input/input_file_"+path+".txt";
    result_path="../output/insertSort/result_"+result_path+".txt";
    ofstream resultWrite(result_path,fstream::out|fstream::trunc);
    if(!resultWrite)
    {
      cerr<<"cannot open :"<<result_path<<endl;
      exit(-1);
    }
    timeWrite.open(time_path,fstream::out|fstream::app);
    vector<string> vec;
    readFile(vec,path);
    start = std::chrono::system_clock::now();
    insertSort(vec);
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    fileWrite<<elapsed_seconds.count()<<"s";
    timeWrite<<"size:"<<assistant[i]<<'\t'<<"time:"<<elapsed_seconds.count()
    <<"s"<<endl;
    if(i!=5)
      fileWrite<<",";
    for(size_t i=0;i!=vec.size();i++)
    {
      resultWrite<<vec[i]<<endl;
    }
    timeWrite.close();
    resultWrite.close();
  }

  fileWrite<<endl;
  /******************************heapSort**************************/
  fileWrite<<"heapSort:";
  cout<<"heapSort"<<endl;
  for(size_t i=0;i!=6;i++)
  {

    string result_path=to_string(assistant[i]);
    string path=to_string(assistant[i]);
    string time_path("../output/heapSort/time.txt");
    path="../input/input_file_"+path+".txt";
    result_path="../output/heapSort/result_"+result_path+".txt";
    ofstream resultWrite(result_path,fstream::out|fstream::trunc);
    if(!resultWrite)
    {
      cerr<<"cannot open :"<<result_path<<endl;
      exit(-1);
    }
    timeWrite.open(time_path,fstream::out|fstream::app);
    if(!timeWrite)
    {
      cerr<<"can not open file in heapSort"<<endl;
      exit(-1);
    }
    vector<string> vec;
    readFile(vec,path);
    start = std::chrono::system_clock::now();
    heapSort(vec);
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    fileWrite<<elapsed_seconds.count()<<"s";
    timeWrite<<"size:"<<assistant[i]<<'\t'<<"time:"<<elapsed_seconds.count();
    timeWrite<<"s"<<endl;
    if(i!=5)
      fileWrite<<",";
    for(size_t i=0;i!=vec.size();i++)
    {
      resultWrite<<vec[i]<<endl;
    }
    timeWrite.close();
    resultWrite.close();
  }

  fileWrite<<endl;
  /*******************************mergeSort*****************************/
  fileWrite<<"mergeSort:";
  cout<<"mergeSort"<<endl;
  for(size_t i=0;i!=6;i++)
  {

    string result_path=to_string(assistant[i]);
    string path=to_string(assistant[i]);
    string time_path("../output/mergeSort/time.txt");
    path="../input/input_file_"+path+".txt";
    result_path="../output/mergeSort/result_"+result_path+".txt";
    ofstream resultWrite(result_path,fstream::out|fstream::trunc);
    if(!resultWrite)
    {
      cerr<<"cannot open :"<<result_path<<endl;
      exit(-1);
    }
    timeWrite.open(time_path,fstream::out|fstream::app);
    vector<string> vec;
    readFile(vec,path);
    start = std::chrono::system_clock::now();
    mergeSort(vec,0,vec.size()-1);
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    fileWrite<<elapsed_seconds.count()<<"s";
    timeWrite<<"size:"<<assistant[i]<<'\t'<<"time:"<<elapsed_seconds.count()
    <<"s"<<endl;
    if(i!=5)
      fileWrite<<",";
    for(size_t i=0;i!=vec.size();i++)
    {
      resultWrite<<vec[i]<<endl;
    }
    timeWrite.close();
    resultWrite.close();
  }

  fileWrite<<endl;
  /*********************************quickSort**************************/
  fileWrite<<"quickSort:";
  cout<<"quickSort"<<endl;
  for(size_t i=0;i!=6;i++)
  {

    string result_path=to_string(assistant[i]);
    string path=to_string(assistant[i]);
    string time_path("../output/quickSort/time.txt");
    path="../input/input_file_"+path+".txt";
    result_path="../output/quickSort/result_"+result_path+".txt";
    ofstream resultWrite(result_path,fstream::out|fstream::trunc);
    if(!resultWrite)
    {
      cerr<<"cannot open :"<<result_path<<endl;
      exit(-1);
    }
    timeWrite.open(time_path,fstream::out|fstream::app);
    vector<string> vec;
    readFile(vec,path);
    start = std::chrono::system_clock::now();
    quickSort(vec,0,vec.size());
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    fileWrite<<elapsed_seconds.count()<<"s";
    timeWrite<<"size:"<<assistant[i]<<'\t'<<"time:"<<elapsed_seconds.count()
    <<"s"<<endl;
    if(i!=5)
      fileWrite<<",";
    for(size_t i=0;i!=vec.size();i++)
    {
      resultWrite<<vec[i]<<endl;
    }
    timeWrite.close();
    resultWrite.close();
  }

  fileWrite<<endl;
  /*********************************end******************************/
  fileWrite.close();
  return 0;
}
