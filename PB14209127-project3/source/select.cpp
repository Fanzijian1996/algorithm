#include"select.h"
std::vector<int>::iterator select(std::vector<int>&vec,int p,int r,int i){
    if(p==r){
        return vec.begin()+p;
    }
    int q=partition(vec,p,r);
    int k=q-p+1;
    if(i==k){
        return vec.begin()+q;
    }
    else if(i<k)
        return select(vec,p,q-1,i);
    else return select(vec,q+1,r,i-k);
}

int partition(std::vector<int>&vec,int p,int r){
    int x=vec[r];
    int i=p-1;
    for(int j=p;j<r;j++){
        if(vec[j]<=x){
            i++;
            int temp=vec[i];
            vec[i]=vec[j];
            vec[j]=temp;
        }
    }
    int temp=vec[i+1];
    vec[i+1]=vec[r];
    vec[r]=temp;
    return i+1;
}
