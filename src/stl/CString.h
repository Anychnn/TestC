//
// Created by anyang on 2017/7/20.
//

#ifndef UPDATE_TOOL_CSTRING_H
#define UPDATE_TOOL_CSTRING_H

#include <iostream>

using std::ostream;
using std::istream;
using std::cerr;
using std::cout;
using std::endl;

#include <iomanip>
class CString {
private:
    char * str;
    int len;
    static int num_strings;
public:
    CString(const char * s);
    CString(const unsigned char &s);
    CString();
    CString(const CString &);
    ~CString();
    int size()const{
        return len;
    };
    bool endWith(const char *);
    const char* c_str()const{
        return str;
    }
    int findIndexOf(char ch,int begin);
    friend std::ostream &operator<<(std::ostream & os,const CString&st){
        os<<st.str;
        return os;
    }
    
    CString &operator=(const CString &);
    CString &operator=(const char *);
    CString operator+(const CString &);
    CString &operator+=(const CString&);
    char &operator[](int i);
    static int HowMany();
};
#endif
