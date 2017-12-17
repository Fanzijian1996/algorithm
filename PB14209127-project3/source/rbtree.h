#ifndef _RBTREE_
#define _RBTREE_
#include<fstream>
#include<iostream>
#include<list>
enum RBcolor{BLACK,RED};
class RBNode{
public:
    RBNode():key(0),left(nullptr),right(nullptr),parent(nullptr){

    }
    RBNode(int keyvalue){
        key=keyvalue;
        left=nullptr;
        right=nullptr;
        parent=nullptr;
        size=1;
    }
    int key;
    struct RBNode* left;
    struct RBNode* right;
    struct RBNode* parent;
    RBcolor color;
    int size;
    bool operator==(const RBNode&node) const{
        if(key==node.key)
            return true;
        else
            return false;
    }
public:
    virtual ~RBNode()=default;
};
class RBTree{
private:
    RBNode *root;
    RBNode *nil;
private:
    void leftRotate(RBNode*ptrx);
    void rightRotate(RBNode*ptrx);
    void insertfixup(RBNode* ptrz);
    void deletefixup(RBNode* ptrz);
    void visit(const RBNode* ptrx);
    void rbtransplant(RBNode* ptru,RBNode* ptrv);
    //inline void visit(RBTree* node);

public:
    RBTree();
    RBTree(const RBTree&Tree);
    ~RBTree();
    int size()const;
    RBNode* getnil()const;
    RBNode* getroot()const;
    RBNode* osSelect(RBNode* ptrx,int i)const;
    RBNode* osSelect(int i)const;
    void preorder(std::ofstream&writer)const;
    void inorder(std::ofstream&writer)const;
    void postorder(std::ofstream&writer)const;
    void preorder(RBNode* ptrx,std::ofstream&writer)const;
    void inorder(RBNode* ptrx,std::ofstream&writer)const;
    void postorder(RBNode* ptrx,std::ofstream&writer)const;
    void rbinsert(int key);
    void rbinsert(RBNode* ptrz);
    void rbdelete(RBNode* ptrx);
    void rbdelete(int i);
    RBNode* treeMinimum();
    RBNode* treeMinimum(RBNode* ptrz);
    void display()const;
    void tinydelete(RBNode* ptrz);
    void clear();


    //delete and free the node
};
#endif
