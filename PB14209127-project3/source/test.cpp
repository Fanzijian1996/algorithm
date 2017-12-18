#include"select.h"
#include<iostream>
using namespace std;
int main(){
    vector<int> vec;
    for(int i=0;i<20;i++){
        vec.push_back(i);
    }
    for(int i=0;i<20;i++)
        cout<<vec[i]<<endl;
    cout<<"select:"<<endl;
    cout<<*(select(vec,0,19,5))<<endl;
    //vector<int>::const_iterator itr=vec.cbegin();
    //vec.erase()
    cout<<*(vec.erase(vec.begin()+4))<<endl;
    cout<<"size:"<<vec.size()<<endl;
    cout<<"select:"<<*(select(vec,0,18,5))<<endl;
    for(auto i:vec){
        cout<<i<<endl;
    }
    return 0;
}
