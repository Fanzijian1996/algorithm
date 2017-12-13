#include"random_array.h"
#define SCALAR_MAX 65535
#define SCALAR_MIN 1
using namespace std;
void createArray(int array[],size_t n)
{
  //create the random array,the array is alloted outside the function
  std::cout<<"creating the random array..."<<std::endl;
  srand((unsigned)time(nullptr));
  for(size_t i=0;i!=n;i++)
    array[i]=rand()%(SCALAR_MAX-SCALAR_MIN+1)+SCALAR_MIN;
  std::cout<<"now we have created the array!"<<std::endl;
  // for(size_t i=0;i!=n;i++)
  //   cout<<array[i]<<end
  ofstream file_write("./input_file_2.txt",ofstream::app|ofstream::out);
  if(!file_write.is_open())
  {
    cout<<"cannot open the file\n";
    exit(-1);
  }
  for(size_t i=0;i!=n;i++)
  {
    file_write<<array[i]<<endl;
  }
  file_write.close();
}
