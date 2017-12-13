#include"createstring.h"
#define MIN_LENTH 1
#define MAX_LENTH 32
#define MIN_ASCII 97
#define MAX_ASCII 122
using namespace std;
void createString(int index)
{
  int rows=pow(2,index);
  stringstream stream;
  stream<<index;
  string path;
  path=stream.str();
  path="../input/input_file_"+path+".txt";
  //the path
  //create the file;
  // cout<<"creating file:"<<path<<endl;
  // cout<<"please waiting..."<<endl;
  ofstream fileWrite(path,ofstream::out|ofstream::trunc);
  if(!fileWrite)
  {
    cerr<<"cannot open the file!";
    exit(-1);
  }
  srand((unsigned)time(nullptr));
  for(size_t i=0;i!=rows;i++)
  {
    int lenth=rand()%(MAX_LENTH-MIN_LENTH+1)+MIN_LENTH;
    string buffer;
    for(size_t j=0;j!=lenth;j++)
    {
      char tempchar=rand()%(MAX_ASCII-MIN_ASCII+1)+MIN_ASCII;
      buffer.push_back(tempchar);
    }
    fileWrite<<buffer<<endl;
  }
  fileWrite.close();
}
