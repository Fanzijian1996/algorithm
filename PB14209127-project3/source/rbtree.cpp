#include"rbtree.h"
RBTree:: RBTree(){
    //nil=new RBNode*;
    nil=new RBNode;
    if(!nil){
        std::cerr<<"malloc nil node failed!"<<std::endl;
        exit(-1);
    }
    nil->left=nullptr;
    nil->right=nullptr;
    nil->parent=nullptr;
    nil->color=BLACK;
    nil->size=0;
    nil->key=-1;
    root=nil;
    //size =0;
}
//default constructor
RBTree:: RBTree(const RBTree &Tree){
    root = Tree.root;
    nil=Tree.nil;
}
//copy constructor
void RBTree::tinydelete(RBNode* ptrz){
    if(ptrz!=this->nil){
        tinydelete(ptrz->left);
        tinydelete(ptrz->right);
        delete ptrz;
        ptrz=nullptr;
    }
}

void RBTree::clear(){
    tinydelete(this->root);
    this->root=nil;
}
RBTree:: ~RBTree(){
    //to be completed
    tinydelete(this->root);
    this->root=nil;
}
RBNode* RBTree::getroot()const{
    return (this->root);
}
void RBTree::preorder(std::ofstream&writer)const{
    //
    preorder(this->root,writer);
}
void RBTree::preorder(RBNode*ptrz,std::ofstream&writer)const{
    // if(ptrz==this->nil)
    //     return;
    // else{
    //     writer<<"("<<ptrz->key<<","<<ptrz->color<<")";
    //     if((ptrz->left!=this->nil)|(ptrz->right!=this->nil))
    //         writer<<",";
    //     preorder(ptrz->left,writer);
    //     if(ptrz->right!=this->nil)
    //         writer<<",";
    //     preorder(ptrz->right,writer);
    //     return ;
    // }
    if(ptrz!=this->nil){
        writer<<"("<<ptrz->key<<","<<ptrz->color<<")";
        if(ptrz->left!=nil)
            writer<<",";
        preorder(ptrz->left,writer);
        if(ptrz->right!=nil)
            writer<<",";
        preorder(ptrz->right,writer);
    }
}
void RBTree::inorder(std::ofstream&writer)const{
    inorder(this->root,writer);
}

void RBTree::inorder(RBNode* ptrz,std::ofstream&writer)const{
    if(ptrz!=this->nil){
        inorder(ptrz->left,writer);
        if(ptrz->left!=this->nil)
            writer<<",";
        writer<<"("<<ptrz->key<<","<<ptrz->color<<")";
        if(ptrz->right!=this->nil){
            writer<<",";
        }
        inorder(ptrz->right,writer);
    }
}

void RBTree::postorder(RBNode* ptrz,std::ofstream&writer)const{
    //
    if(ptrz!=this->nil){
        postorder(ptrz->left,writer);
        if(ptrz->left!=this->nil)
            writer<<",";
        postorder(ptrz->right,writer);
        if(ptrz->right!=this->nil)
            writer<<",";
        writer<<"("<<ptrz->key<<","<<ptrz->color<<")";
    }
}

void RBTree::postorder(std::ofstream&writer)const{
    postorder(this->root,writer);
}
void RBTree::rbinsert(int key){
    RBNode* ptrz=new RBNode(key);
    if(!ptrz){
        std::cerr<<"malloc failed"<<std::endl;
        exit(-1);
    }
    rbinsert(ptrz);
}
void RBTree::rbinsert(RBNode*ptrz){
    //
    RBNode* ptry= this->nil;
    RBNode* ptrx=this->root;
    while(ptrx!=this->nil){
        ptrx->size=ptrx->size+1;
        ptry=ptrx;
        if(ptrz->key<ptrx->key)
            ptrx=ptrx->left;
        else ptrx=ptrx->right;
    }
    ptrz->parent=ptry;
    if(ptry==this->nil){
        this->root=ptrz;
        ptrz->parent=this->nil;
    }
    else{
        if(ptrz->key<ptry->key)
            ptry->left=ptrz;
        else ptry->right=ptrz;
    }
    ptrz->left=this->nil;
    ptrz->right=this->nil;
    ptrz->color=RED;
    insertfixup(ptrz);
}

void RBTree::rbdelete(RBNode*ptrz){
    //delete a node;
    RBNode* ptrtemp=this->root;
    while(ptrtemp->key!=ptrz->key){
        ptrtemp->size=ptrtemp->size-1;
        if(ptrz->key<ptrtemp->key)
            ptrtemp=ptrtemp->left;
        else ptrtemp=ptrtemp->right;
    }//find the path to ptrz from the root
    RBNode* ptry=ptrz;
    RBNode* ptrx=nullptr;
    RBcolor yOriColor=ptry->color;
    if(ptrz->left==this->nil){
        ptrx=ptrz->right;
        rbtransplant(ptrz,ptrz->right);
    }
    else if(ptrz->right==this->nil){
        ptrx=ptrz->left;
        rbtransplant(ptrz,ptrz->left);
    }
    else{
        ptry=treeMinimum(ptrz->right);
        yOriColor=ptry->color;
        ptrx=ptry->right;
        if(ptry->parent==ptrz){
            ptrx->parent=ptry;
        }
        else{
            rbtransplant(ptry,ptry->right);
            ptry->right=ptrz->right;
            ptry->right->parent=ptry;
        }
        rbtransplant(ptrz,ptry);
        ptry->left=ptrz->left;
        ptry->left->parent=ptry;
        ptry->color=ptrz->color;
    }
    if(yOriColor==BLACK)
        deletefixup(ptrx);
    delete ptrz;
    ptrz=nullptr;
}

void RBTree::rbdelete(int i){
    RBNode* ptr=osSelect(i);
    rbdelete(ptr);
}
inline void RBTree::rbtransplant(RBNode*ptru,RBNode*ptrv){
    if(ptru->parent==this->nil){
        this->root=ptrv;
        //ptrv->parent=this->nil;
    }
    else if(ptru=ptru->parent->left)
            ptru->parent->left=ptrv;
        else ptru->parent->right=ptrv;
    ptrv->parent=ptru->parent;
}
inline void RBTree::leftRotate(RBNode*ptrx){
    //
    RBNode *ptry=ptrx->right;
    ptrx->right=ptry->left;
    if(ptry->left!=this->nil)
        ptry->left->parent=ptrx;
    ptry->parent=ptrx->parent;
    if(ptrx->parent==this->nil)
        this->root=ptry;
    else{
        if(ptrx==ptrx->parent->left)
            ptrx->parent->left=ptry;
        else ptrx->parent->right=ptry;
    }
    ptry->left=ptrx;
    ptrx->parent=ptry;
    ptry->size=ptrx->size;
    ptrx->size=ptrx->left->size+ptrx->right->size+1;
}
inline RBNode* RBTree::treeMinimum(RBNode* ptrz){
    while(ptrz->left!=this->nil){
        ptrz=ptrz->left;
    }
    return ptrz;
}

inline RBNode* RBTree::treeMinimum(){
    RBNode* ptrz=this->root;
    while(ptrz->left!=this->nil)
        ptrz=ptrz->left;
    return ptrz;
}
inline void RBTree::rightRotate(RBNode*ptrx){
    //
    RBNode* ptry=ptrx->left;
    ptrx->left=ptry->right;
    if(ptry->right!=this->nil)
        ptry->right->parent=ptrx;
    ptry->parent=ptrx->parent;
    if(ptrx->parent==this->nil)
        this->root=ptry;
    else{
        if(ptrx->parent->left==ptrx)
            ptrx->parent->left=ptry;
        else ptrx->parent->right=ptry;
    }
    ptry->right=ptrx;
    ptrx->parent=ptry;
    ptry->size=ptrx->size;
    ptrx->size=ptrx->left->size+ptrx->right->size+1;
}

void RBTree::insertfixup(RBNode*ptrz){
    //
    // if(ptrz->parent!=this->nil)
        while(ptrz->parent->color==RED){
            if(ptrz->parent==ptrz->parent->parent->left){
                RBNode *ptry=ptrz->parent->parent->right;
                if(ptry->color==RED){
                    ptrz->parent->color=BLACK;//case 1
                    ptry->color=BLACK;//case 1
                    ptrz->parent->parent->color=RED;//case 1
                    ptrz=ptrz->parent->parent;//case 1
                }
            else if(ptrz==ptrz->parent->right){
                    ptrz=ptrz->parent;//case 2
                    leftRotate(ptrz);//case 2
                    }
                    else{
                        ptrz->parent->color=BLACK;
                        ptrz->parent->parent->color=RED;//case 3
                        rightRotate(ptrz->parent->parent);//case 3
                    }
                }
            else{
                RBNode* ptry=ptrz->parent->parent->left;
                if(ptry->color==RED){
                    ptrz->parent->color=BLACK;//case 1
                    ptry->color=BLACK;//case 1
                    ptrz->parent->parent->color=RED;//case 1
                    ptrz=ptrz->parent->parent;//case 1
                }
            else if(ptrz==ptrz->parent->left){
                ptrz=ptrz->parent;//case 2
                rightRotate(ptrz);//case 2
                }
                else{
                    ptrz->parent->color=BLACK;
                    ptrz->parent->parent->color=RED;//case 3
                    leftRotate(ptrz->parent->parent);//case 3
                }
            }
        }
        this->root->color=BLACK;
}

void RBTree::deletefixup(RBNode*ptrx){
    //
    while(ptrx!=this->root&&ptrx->color==BLACK){
        if(ptrx==ptrx->parent->left){
            RBNode* ptrw=ptrx->parent->right;
            if(ptrw->color==RED){//case 1
                ptrw->color=BLACK;
                ptrx->parent->color=RED;
                leftRotate(ptrx->parent);
                ptrw=ptrx->parent->right;
            }
            if(ptrw->left->color==BLACK&&ptrw->right->color==BLACK){//case 2
                ptrw->color=RED;
                ptrx=ptrx->parent;
            }
            else if(ptrw->right->color==BLACK){//case 3
                ptrw->left->color=BLACK;
                ptrw->color=RED;
                rightRotate(ptrw);
                ptrw=ptrx->parent->right;
            }else{//case 4
                ptrw->color=ptrx->parent->color;
                ptrx->parent->color=BLACK;
                ptrw->right->color=BLACK;
                leftRotate(ptrx->parent);
                ptrx=this->root;
            }
        }
        else{
            RBNode* ptrw=ptrx->parent->left;
            if(ptrw->color==RED){//case 1
                ptrw->color=BLACK;
                ptrx->parent->color=RED;
                rightRotate(ptrx->parent);
                ptrw=ptrx->parent->left;
            }
            if(ptrw->right->color==BLACK&&ptrw->left->color==BLACK){//case 2
                ptrw->color=RED;
                ptrx=ptrx->parent;
            }
            else if(ptrw->left->color==BLACK){//case 3
                ptrw->right->color=BLACK;
                ptrw->color=RED;
                leftRotate(ptrw);
                ptrw=ptrx->parent->left;
            }else{//case 4
                ptrw->color=ptrx->parent->color;
                ptrx->parent->color=BLACK;
                ptrw->left->color=BLACK;
                rightRotate(ptrx->parent);
                ptrx=this->root;
            }
        }
    }
}

inline void RBTree::visit(const RBNode*ptrx){
    //
}
RBNode* RBTree::osSelect(RBNode* ptrx,int i)const{
    if(ptrx==this->nil)
        return this->nil;
    else{
        int r=ptrx->left->size+1;
        if(r==i){
        return ptrx;
        }
        else{
            if(i<r)
                return osSelect(ptrx->left,i);
                return osSelect(ptrx->right,i-r);
            }
        }
    }

RBNode* RBTree::osSelect(int i)const{
    osSelect(this->root,i);
}
void RBTree::display()const{
    std::cout<<"display the Red Black Tree"<<std::endl;
    std::cout<<"("<<"key"<<","<<"color"<<","<<"parent"<<")"<<std::endl;
    std::list<RBNode*> mylist;
    mylist.push_back(this->root);
    int cur_count=1;
    int next_count=0;
    while(!mylist.empty()){
        next_count=0;
        for(int i=0;i<cur_count;i++)
        {
            RBNode *temptr=mylist.front();
            mylist.pop_front();
            if(temptr->left!=this->nil){
                mylist.push_back(temptr->left);
                next_count++;
                //std::cout<<"hello"<<std::endl;
            }
            if(temptr->right!=this->nil){
                mylist.push_back(temptr->right);
                next_count++;
            }
            std::cout<<"("<<temptr->key<<",";
            if(temptr->color)
                std::cout<<"R";
            else std::cout<<"B";
            std::cout<<","<<temptr->parent->key<<")"<<" ";
        }
        std::cout<<std::endl;
        cur_count=next_count;
    }
}
