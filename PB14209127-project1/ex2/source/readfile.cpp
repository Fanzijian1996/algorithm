#include"readfile.h"
#define BUFFER_SIZE 10
using namespace std;
int * readFile(const string& s,const size_t &len)
{
  ifstream file_read(s,fstream::in);
  if(!file_read)
  {
    cerr<<"cannot open this file"<<endl;
    exit(-1);
  }
  cout<<"file size:"<<"\t"<<len<<endl;
  int *array =new int[len];
  if(array==nullptr)
  {
    cerr<<"malloc failed!"<<endl;
    exit(-1);
  }
  char buffer[BUFFER_SIZE];
  int i=0;//the count
  while(file_read.getline(buffer,BUFFER_SIZE-1))
  {
    string temp(buffer);
    array[i++]=stoi(temp);
  }
  return array;
}
