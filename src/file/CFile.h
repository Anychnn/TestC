//
// Created by Administrator on 2017/7/23.
//

#ifndef TESTC_CFILE_H
#define TESTC_CFILE_H

static const char FILE_SEPERATOR_CHAR='\\';
static const char * FILE_SEPERATOR="\\";
class CFile {
public:
    CFile(char * filePath);
    ~CFile(){
        delete[] filePath;
    };
    char * getName();
    char * getPath();
    bool remove();
    bool exists();
    bool isDirectory();
    bool isFile();
    void listFiles(CFile ** files);
    int countFiles();
private:
    char * filePath;

};


#endif //TESTC_CFILE_H
