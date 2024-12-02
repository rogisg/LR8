#include <iostream>
#include <cstring>

using namespace std;

char* CopyString(const char* str) {
    size_t len = 0;
    while (str[len] != 0) {
        len++;
    }
    char* newStr = new char[len];
    memcpy(newStr, str, len);
    
    return newStr;
}



char* ConcatinateStrings(const char* a, const char* b) {

    size_t lenA = 0;
    while (a[lenA] != 0) {
        lenA++;
    }

    size_t lenB = 0;
    while (b[lenB] != 0) {
        lenB++;
    }
    
    char* newStr = new char[lenA + lenB];
    memcpy(newStr, a, lenA);
    memcpy(newStr + lenA, b, lenB);

    return newStr;
}
