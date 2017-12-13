#include"rbtree.h"
using namespace std;
int main(){
    RBTree T;
    ofstream writer("test.txt",ofstream::out|ofstream::trunc);
    //RBNode* ptrz=nullptr;

    // T.rbinsert(1);
    for(int i=1;i<20;i++)
        T.rbinsert(i);
    // T.rbinsert(3);
    // //T.rbinsert(4);
    // T.rbinsert(5);
    // T.rbinsert(6);
    T.preorder(writer);
    writer<<endl;
    writer<<"("<<T.getroot()->key<<","<<T.getroot()->color<<")"<<endl;
    writer.close();
    cout<<T.getroot()->size<<endl;
    return 0;
}
