#include"readfile.h"
#define BUFFER_SIZE 20
size_t readfile(vector<double>&vec,const string&path,int lenth,size_t offset)
{
  ifstream filereader (path,ifstream::in);
  if(!filereader){
    cerr<<"can't open the file!"<<endl;
    exit(-1);
  }
  filereader.seekg(offset,fstream::beg);
  char buffer[20];
  for(int i=0;i<20;i++)
    buffer[i]='\0';
  for(int i=0;i<lenth;i++)
  {
    filereader.getline(buffer,20);
    string tempbuf=buffer;
    int temp=std::stoi(tempbuf);
    //int temp=1;
    vec.push_back(temp);
  }
  size_t current=filereader.tellg();
  filereader.close();
  return current;
}
