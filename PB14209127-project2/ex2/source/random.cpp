#include"random.h"
#define MAXLEN 120
#define MAX 600
#define MIN 1
using namespace std;
void creatfile(const string&path,int lenth)
{
  ofstream filewriter(path,fstream::out|fstream::trunc);
  if(!filewriter){
    cerr<<"can't open the file ,maybe the file path doesn't exist!\n";
    exit(-1);
  }
  srand((unsigned)time(nullptr));
  for(int i=0;i<lenth;i++)
  {
    int buffer =rand()%(MAX-MIN+1)+MIN;
    filewriter<<buffer<<endl;
  }
  filewriter.close();
}

int main(int argc,char **argv)
{
  string path;
  if(argc==1){
    cerr<<"no input files!use default file!"<<endl;
    path="../input/input.txt";
  }
  else{
     path=argv[1];
  }
  creatfile(path,MAXLEN);
  return 0;
}
