//
// Created by anyang on 2017/7/4.

#include <iostream>
#include "file/CFile.h"

using namespace std;
void listAllFiles(char * dir){
    CFile file(dir);
    int filesCount=file.countFiles();
    CFile *files[filesCount];
    file.listFiles(files);
    for(int i=0;i<filesCount;i++){
        cout<<files[i]->getPath()<<endl;
        if(files[i]->isDirectory()){
            listAllFiles(files[i]->getPath());
        }
    }
}

int main(int argc, const char *argv[]) {

    char * testDir="E:\\Youxun\\";
    std::string dir="E:\\Youxun";

    char * game="E:\\Youxun\\Game";
    CFile testFile(testDir);
    CFile gameFile(game);
    if(gameFile.isDirectory()){
        cout<<"is dir"<<endl;
    }

    if(testFile.exists()){
        cout<<"exists"<<endl;
    }

    if(testFile.isFile()){
        cout<<"is file"<<endl;
    }
    if(testFile.isDirectory()){
        cout<<"is dir"<<endl;
    }

    cout<<testFile.getName()<<endl;
    cout<<testFile.getPath()<<endl;

    listAllFiles(testDir);
//    system("pause");
    return 0;
}