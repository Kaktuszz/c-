#include "tstring.h"
#include <iostream>

TString::TString(const char* s):ptr{nullptr}, len{0}{
    if(s!=nullptr){
            len = strlen(s);
            ptr new char[len+1];
            strcpy(ptr,s);
        }
}