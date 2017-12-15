#include"random.h"
#define MAXLEN 1000
#define SIZE 120
#define MAX 150
#define MIN 1
using namespace std;
void creatfile(const string&path,int lenth=MAXLEN)
{
  ofstream filewriter(path,fstream::out|fstream::trunc);
  if(!filewriter){
    cerr<<"can't open the file ,maybe the file path doesn't exist!\n";
    exit(-1);
  }
  srand((unsigned)time(nullptr));
  int* iptr=new int[lenth];
  for(int i=0;i<lenth;i++){
      iptr[i]=i+1;
  }
  for(int i=0;i<SIZE;)
  {
    int buffer =rand()%(MAX-MIN+1)+MIN;
    if(iptr[buffer]!=0){
        filewriter<<iptr[buffer]<<endl;
        i++;
        iptr[buffer]=0;
    }
  }
  filewriter.close();
  delete iptr;
}

int main(int argc,char **argv)
{
  string path;
  if(argc==1){
    cerr<<"no input files!use default file!"<<endl;
    path="input.txt";
  }
  else{
     path=argv[1];
  }
  creatfile(path,MAXLEN);
  return 0;
}
