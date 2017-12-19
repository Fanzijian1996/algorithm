#include"rbtree.h"
#include"readfile.h"
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> vec;
    readfile(vec,"../input/input.txt",12);
    RBTree T;
    for(int i=0;i<vec.size();i++){
        T.rbinsert(vec.at(i));
    }
    //T.display();
    //T.rbdelete(1);
    cout<<T.osSelect(13)->key<<endl;
    //T.display();
    return 0;
}
