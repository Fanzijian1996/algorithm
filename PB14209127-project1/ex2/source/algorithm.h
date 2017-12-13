#ifndef _ALGORITHM_
#define _ALGORITHM_
#include<iostream>
#include<cmath>
//bubble sort
void bubbleSort(int array[],size_t n);
//count_sort
void countSort(int array[],int answer[],size_t n);
//quick_sort
size_t partition(int array[],int p,int r);
void quickSort(int array[],int p,int r);
//radix_sort
void radixSort(int array[],int answer[],size_t n);
void countSort(int array[],int answer[],size_t n,int radix);
int keyWord(int number,int i);
#endif
