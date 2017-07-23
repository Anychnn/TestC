//
// Created by Administrator on 2017/7/23.
//

#include <dirent.h>
#include "CFile.h"
#include <fstream>
#include <cstring>

CFile::CFile(char *filePath) : filePath(filePath) {
}

char *CFile::getName() {
    int firstIndex = strlen(filePath) - 1;
    if (filePath[firstIndex] == FILE_SEPERATOR_CHAR) {
        //路径以 分隔符结尾
        firstIndex--;
    }
    int secondIndex = firstIndex;
    while (firstIndex >= 0 && filePath[firstIndex] != FILE_SEPERATOR_CHAR) {
        firstIndex--;
    }
    int resLen = secondIndex - firstIndex + 1;
    char *res = new char[resLen];
    int tmpIndex = 0;
    for (int i = firstIndex + 1; i <= secondIndex; i++) {
        res[tmpIndex++] = filePath[i];
    }
    res[tmpIndex] = '\0';
    return res;
}

char *CFile::getPath() {
    return filePath;
}

bool CFile::exists() {
    if (isDirectory() || isFile()) {
        return true;
    }
    return false;
}

bool CFile::remove() {
    return false;
}

bool CFile::isDirectory() {
    DIR *dir;
    dir = opendir(filePath);
    if (dir == NULL) return false;
    auto dirent = readdir(dir);
    if (dirent->d_type == DT_DIR) {
        closedir(dir);
        return true;
    }
    return false;
}

bool CFile::isFile() {
    DIR *dir;
    dir = opendir(filePath);
    if (dir != NULL)
        return false; //是文件夹 或者文件不存在
    if (std::ifstream(filePath)) {
        closedir(dir);
        return true;
    }
    return false;
}


void CFile::listFiles(CFile **files) {
    //check
    if (!exists() || isFile()) return;

    struct dirent *ptr;
    DIR *dir;
    int index = 0;
    dir = opendir(filePath);
    while ((ptr = readdir(dir)) != NULL) {
        if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0) {
            continue;
        }
        int dirPathLen = strlen(filePath);
        int dNameLen = strlen(ptr->d_name);
        char *newPath;
        //end with FILE_SEPERATOR
        if (filePath[dirPathLen-1] != FILE_SEPERATOR_CHAR) {
            newPath = new char[dirPathLen + dNameLen + 2];
            strcpy(newPath, this->filePath);
            strcat(newPath, FILE_SEPERATOR);
            strcat(newPath, ptr->d_name);
        } else {
            newPath = new char[dirPathLen + dNameLen + 1];
            strcpy(newPath, this->filePath);
            strcat(newPath, ptr->d_name);
        }
        files[index++] = new CFile(newPath);
    }
}


int CFile::countFiles() {
    if (!exists() || isFile()) return 0;
    int index = 0;
    struct dirent *ptr;
    DIR *dir;
    dir = opendir(filePath);
    while ((ptr = readdir(dir)) != NULL) {
        if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0) {
            continue;
        }
        index++;
    }
    return index;
}
