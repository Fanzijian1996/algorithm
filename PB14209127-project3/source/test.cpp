#include"rbtree.h"
using namespace std;
int main(){
    RBTree T;
    ofstream writer("test.txt",ofstream::out|ofstream::trunc);
    //RBNode* ptrz=nullptr;

    // T.rbinsert(1);
    for(int i=1;i<20;i++){
        T.rbinsert(i);
        //cout<<T.getroot()->size<<endl;
    }
    // for(int i=20;i>0;i--){
    //     T.rbdelete();
    //     cout<<T.getroot()->size<<endl;
    // }
    //T.rbdelete(1);
    //T.display();
    //cout<<T.getroot()->size<<endl;
    T.display();
    //RBNode* ptr=T.getroot();
    // while(ptr!=T.getnil()){
    //     std::cout<<ptr->key<<std::endl;
    //     ptr=ptr->right;
    // }
    T.rbdelete(14);
    T.display();
    //cout<<T.getroot()->size<<endl;
    //T.display();
    // T.rbinsert(3);
    // //T.rbinsert(4);
    // T.rbinsert(5);
    // T.rbinsert(6);
    //cout<<T.osSelect(10)->key<<endl;
    //T.display();
    //std::cout<<T.osSelect(3)->key<<std::endl;
    // cout<<T.osSelect(9)->size<<endl;
    // T.rbdelete(8);
    // T.display();
    // T.inorder(writer);
    // writer<<endl;

    //writer<<"("<<T.getroot()->key<<","<<T.getroot()->color<<")"<<endl;

    //cout<<T.getroot()->size<<endl;
    // cout<<T.getroot()->size<<endl;
    // T.display();
    return 0;
}
