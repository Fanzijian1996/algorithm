#include"rbtree.h"
#include"readfile.h"
#include"select.h"
#include<iostream>
#include<string>
#include<fstream>
#include<chrono>
using namespace std;
int main(){
    int array[5]={12,24,36,48,60};
    std::chrono::time_point<std::chrono::system_clock> end,start;
    std::chrono::duration<double> elapsed_seconds;
    std::chrono::duration<double> total_time;
    ofstream preWriter,inWriter,postWriter,timeWriter,time2Writer,deleteDataWriter;
    //cout<<"exe 1 start"<<endl;
    for(int i=1;i<5;i++){
        vector<int> vec;
        RBTree T;
        string resultPath("../output/size");
        string prePath("preorder.txt");
        string inPath("inorder.txt");
        string postPath("postorder.txt");
        string timePath("time1.txt");
        //exe2
        string time2Path("time2.txt");
        string deletePath("delete_data.txt");
        //exe2
        string temp=to_string(array[i]);
        resultPath=resultPath+temp+"/";
        readfile(vec,"../input/input.txt",array[i]);

        prePath=resultPath+prePath;
        inPath=resultPath+inPath;
        postPath=resultPath+postPath;
        timePath=resultPath+timePath;
        //exe2
        time2Path=resultPath+time2Path;
        deletePath=resultPath+deletePath;
        //exe2
        preWriter.open(prePath,fstream::out|fstream::trunc);
        inWriter.open(inPath,fstream::out|fstream::trunc);
        postWriter.open(postPath,fstream::out|fstream::trunc);
        timeWriter.open(timePath,fstream::out|fstream::trunc);
        //exe2
        time2Writer.open(time2Path,fstream::out|fstream::trunc);
        deleteDataWriter.open(deletePath,fstream::out|fstream::trunc);
        //exe2
        timeWriter<<"size:"<<array[i]<<endl;
        start = std::chrono::system_clock::now();
        //startini = std::chrono::system_clock::now();
        for(int j=0;j<array[i];j++){
            T.rbinsert(vec[j]);
            if((j+1)%10==0){
                end = std::chrono::system_clock::now();
                elapsed_seconds=end-start;
                // total_time+=elapsed_seconds;
                timeWriter<<"every 10 insert :"<<elapsed_seconds.count()<<"s"<<endl;
                //break;
                start = std::chrono::system_clock::now();
            }
        }
        // end = std::chrono::system_clock::now();
        // elapsed_seconds=end-startini;
        // //total_time+=elapsed_seconds;
        // timeWriter<<"total time:"<<elapsed_seconds.count()<<"s"<<endl;
        T.clear();
        start = std::chrono::system_clock::now();
        for(int j=0;j<array[i];j++){
            T.rbinsert(vec[j]);
        }
        end = std::chrono::system_clock::now();
        elapsed_seconds=end-start;
        timeWriter<<"total time:"<<elapsed_seconds.count()<<"s"<<endl;
        T.preorder(preWriter);
        //T.inorder(inWriter);
        T.postorder(postWriter);

        T.inorder(inWriter);
        //exe2
        cout<<"size:"<<array[i]<<endl;
        cout<<"initial:"<<endl;
        T.display();
        deleteDataWriter<<"osSelect:"<<endl;
        RBNode* ptrTemp=T.osSelect(T.size()/3);
        deleteDataWriter<<"("<<ptrTemp->key<<","<<ptrTemp->color<<")"<<endl;
        start = std::chrono::system_clock::now();
        T.rbdelete(ptrTemp);
        end = std::chrono::system_clock::now();
        elapsed_seconds=end-start;
        time2Writer<<"delete time:"<<elapsed_seconds.count()<<"s"<<endl;
        cout<<"delete first node:"<<endl;
        T.display();
        //std::cout<<T.size()<<endl;
        ptrTemp=T.osSelect(T.size()/4);
        deleteDataWriter<<"("<<ptrTemp->key<<","<<ptrTemp->color<<")"<<endl;
        start = std::chrono::system_clock::now();
        T.rbdelete(T.size()/4);
        end = std::chrono::system_clock::now();
        elapsed_seconds=end-start;
        time2Writer<<"delete time:"<<elapsed_seconds.count()<<"s"<<endl;
        cout<<"delete second node:"<<endl;
        T.display();
        //exe2
        //test
        deleteDataWriter<<"using linear algorithm:"<<endl;
        vector<int>::iterator itr=select(vec,0,vec.size()-1,vec.size()/3);
        // for(int i=0;i<vec.size();i++)
        //     cout<<vec[i]<<endl;
        deleteDataWriter<<*(itr)<<endl;
        //cout<<*itr<<endl;
        vec.erase(itr);

        deleteDataWriter<<*(select(vec,0,vec.size()-1,vec.size()/4))<<endl;
        preWriter.close();
        inWriter.close();
        postWriter.close();
        timeWriter.close();
        time2Writer.close();
        deleteDataWriter.close();
        //T.display();
    }
    //cout<<"exe 1 end"<<endl;
    return 0;

}
