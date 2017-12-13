#include"readfile.h"
#define BUFFER_SIZE 33
void readFile(vector<string>&vec,const string&s)
{
  //cout<<"file name:"<<s.substr(9)<<endl;
  ifstream file_read(s,fstream::in);
  if(!file_read)
  {
    cerr<<"cannot read the file:"<<s<<endl;
    exit(-1);
  }
  char buffer[BUFFER_SIZE];
  while(file_read.getline(buffer,BUFFER_SIZE))
  {
    string temp(buffer);
    vec.push_back(temp);
  }
  cout<<"file size:"<<vec.size()<<endl;
}
