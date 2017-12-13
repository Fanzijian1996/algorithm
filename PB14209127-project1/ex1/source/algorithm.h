#ifndef _ALGORITHM_
#define _ALGORITHM_
#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool compare(const string& s1,const string&s2);
// compare s1,s2,
//if s1<=s2 return true,else return false
void insertSort(vector<string>&vec);
//insert sort
void heapSort(vector<string>&heap);
void buildMaxHeap(vector<string>&heap);
void maxHeapify(vector<string>&heap,const vector<string>::size_type& i);
//heapSort
void mergeSort(vector<string>&vec,int begin,int end);
void merge(vector<string>&vec,int begin,int mid,int end);
//mergeSort [begin,end]
void quickSort(vector<string>&vec,int begin,int end);
int partition(vector<string>&vec,int begin,int end);
//quickSort [begin,end]
#endif
