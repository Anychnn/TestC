//
// Created by anyang on 2017/7/20.
//
#include <cstring>
#include "CString.h"

using namespace std;
int CString::num_strings = 0;

CString::CString(const char *s) {
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    num_strings++;
}

CString::CString(const unsigned char &s) {
    num_strings++;
    str = new char[2];
    str[0] = s;
    len = 1;
}

CString::CString() {
    num_strings++;
    str = new char[1];
    str[0] = '\0';
    len = 0;
}

CString::CString(const CString &st) {
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
}

CString::~CString() {
    num_strings--;
    //    std::cout << str << " ----destory        " << num_strings << "    left  size"<<size() << std::endl;
    delete[]str;
}

CString &CString::operator=(const CString &st) {
    if (this == &st) {
        return *this;
    }
    delete[] str;
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
    return *this;
}

CString &CString::operator=(const char *st) {
    delete[] str;
    len = strlen(st);
    str = new char[len + 1];
    strcpy(str, st);
    return *this;
}

CString CString::operator+(const CString &st) {
    CString str;
    delete[] str.str;
    str.len = this->len + st.len;
    str.str = new char[str.len + 1];
    strcpy(str.str, this->str);
    strcat(str.str, st.str);
    return str;
}

CString &CString::operator+=(const CString &st) {
    char *temp = str;
    len = len + st.len;
    str = new char[len + 1];
    strcpy(str, temp);
    strcat(str, st.str);
    delete[]temp;
    return *this;
}


char &CString::operator[](int i) {
    return str[i];
}

int CString::HowMany() {
    return num_strings;
}

bool CString::endWith(const char *suffix) {
    int suffixLen = strlen(suffix);
    if (suffixLen > len) {
        return false;
    }
    for (int i = 0; i < suffixLen; i++) {
        if(str[i + len - suffixLen]!=suffix[i]){
            return false;
        }
    }
    return true;
}

int CString::findIndexOf(char ch, int begin) {
    for(int i=begin;i<len;i++){
        if(str[i]==ch){
            return i;
        }
    }
    return -1;
}
