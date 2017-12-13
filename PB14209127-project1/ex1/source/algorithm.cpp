#include"algorithm.h"
static int heapsize;
//global variable for heapSort
//compare s1 and s2
bool compare(const string& s1,const string&s2)
{
  if(s1.size()==s2.size())
  {
    string::size_type i=0;
    while(i<s1.size())
    {
      if(s1[i]<s2[i])
      return true;
      if(s1[i]>s2[i])
      return false;
      i++;
    }
    return true;
  }
  else
  {
    return s1.size()<s2.size()?true:false;
  }
}

void insertSort(std::vector<std::string>&vec)
{
  for(int i=1;i<vec.size();i++)
  {
    string buffer=vec[i];
    int j=i-1;
    while(j>=0&&(!compare(vec[j],buffer)))
    {
      vec[j+1]=vec[j];
      j--;
    }
    vec[j+1]=buffer;
  }
}
/**************************** heapSort*******************************/
void heapSort(std::vector<std::string>&heap)
{
  if(heap.empty())
  {
    cerr<<"the heap is empty!"<<endl;
    exit(-1);
  }
  heapsize=heap.size();
  maxHeapify(heap,0);
  buildMaxHeap(heap);
  for(int i=heap.size()-1;i>=1;i--)
  {
    string buffer=heap[i];
    heap[i]=heap[0];
    heap[0]=buffer;
    heapsize--;
    // cout<<heapsize<<endl;
    maxHeapify(heap,0);
  }
}
void maxHeapify(vector<string>&heap,const vector<string>::size_type& i)
{
  vector<string>::size_type leftchild,rightchild,largest;
  leftchild=2*i+1;rightchild=2*i+2;
  //cout<<leftchild<<endl;
  if(leftchild<heapsize&&(!compare(heap[leftchild],heap[i])))
  {
    largest=leftchild;
  }
  else
    largest=i;
  if(rightchild<heapsize&&!compare(heap[rightchild],heap[largest]))
  {
    largest=rightchild;
  }
  if(largest!=i)
  {
    string buffer=heap[i];
    heap[i]=heap[largest];
    heap[largest]=buffer;
    maxHeapify(heap,largest);
  }
}

void buildMaxHeap(std::vector<std::string>&heap)
{
  int i=(heapsize-2)/2;
  for(;i>=0;i--)
  {
    maxHeapify(heap,i);
  }
}


/**********************************mergeSort****************************/

void mergeSort(vector<string>&vec,int begin,int end)
{
  if(begin==end)
    return ;
  else
  {
    int mid=(begin+end)/2;
    mergeSort(vec,begin,mid);
    mergeSort(vec,mid+1,end);
    merge(vec,begin,mid,end);
  }
}

void merge(vector<string>&vec,int begin,int mid,int end)
{
  vector<string>temp;
  int i=begin;int j=mid+1;
  while(i<=mid&&j<=end)
  {
    if(compare(vec[i],vec[j]))
    {
      temp.push_back(vec[i]);
      i++;
    }
    else
    {
      temp.push_back(vec[j]);
      j++;
    }
  }
  if(i<mid)
  {
    for(int k=i;k<=mid;k++)
      temp.push_back(vec[k]);
  }
  if(j<end)
  {
    for(int k=j;k<=end;k++)
      temp.push_back(vec[k]);
  }
  for(int k=0;k!=temp.size();k++)
  {
    vec[k+begin]=temp[k];
  }
}
int partition(vector<string>&vec,int p,int r)
{
  // we use [) section
  // boundary detection to be done
  int i=p-1;//here may be logic error
  //std::cout<<i<<std::endl;
  string keyword = vec[r-1];
  //std::cout<<"r:"<<r<<","<<p<<std::endl;
  for(int j=p;j!=r-1;j++)
  {
    //std::cout<<"2"<<std::endl;
    if(compare(vec[j],keyword))
    {//swap
      string temp=vec[++i];
      vec[i]=vec[j];
      vec[j]=temp;
    }
  }
  vec[r-1]=vec[++i];

  vec[i]=keyword;
  return i;
}

void quickSort(vector<string>&vec,int p,int r)
{
  if(p<r-1)
  {
    int q=partition(vec,p,r);
    // std::cout<<p<<","<<q<<","<<r<<std::endl;
    quickSort(vec,p,q);
    quickSort(vec,q+1,r);
  }
  else
    return;
}
// int partition(vector<string>&vec,int begin,int end)
// {
//   string buffer=vec[end];
//   int i=begin-1;
//   for(int j=begin;j<end;j++)
//   {
//     if(compare(vec[j],buffer))
//     {
//       i++;
//       string temp=vec[j];
//       vec[j]=vec[i];
//       vec[i]=temp;
//     }
//   }
//   vec[end]=vec[i+1];
//   vec[i+1]=buffer;
//   return i+1;
// }
// void quickSort(vector<string>&vec,int begin,int end)
// {
//   if(begin==end)
//   {
//     return ;
//   }
//   else
//   {
//     int mid=partition(vec,begin,end);
//     quickSort(vec,begin,mid-1);
//     quickSort(vec,mid+1,end);
//   }
// }
