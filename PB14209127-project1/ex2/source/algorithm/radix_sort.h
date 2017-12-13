#ifndef _RADIX_SORT_
#define _RADIX_SORT_
#include<iostream>
#include<cmath>
// the radix is 10,we will sort the array 5 rounds
void radixSort(int array[],int answer[],size_t n);
void countSort(int array[],int answer[],size_t n,int radix);
int keyWord(int number,int i);
//return the keyword
#endif
