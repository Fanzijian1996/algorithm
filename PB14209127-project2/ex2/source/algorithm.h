#ifndef _ALGORITHM_
#define _ALGORITHM_
#include<vector>
#include<complex>
#include<iostream>
using namespace std;
//FFT and normal algorith
void ffTran(const vector<double>&vec1,vector<double>&result);
void multiply(const vector<double>&vec1,const vector<double>&vec2,vector<double>&result);
void fft(const vector<double>&vec1,const vector<double>&vec2,vector<complex<double>>&result);
void iffTran(const vector<complex<double>>& vec,vector<complex<double>>&result);
#endif
