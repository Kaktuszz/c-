#include <iostream>
#include <string>
#include <cstring>
#include <bits/stdc++.h>


auto main()->int{

std::string s1;

std::getline(std::cin,s1);

if(s1.empty()){
    std::cout << "String nie moze byc pusty!";
    return 0;
}

std::string s2 = s1;

reverse(s2.begin(),s2.end());
std::cout << s2 << std::endl;

for(int i=1; i<s1.size();i++){
    if(s1[i-1] == ' '){
        s1[i] == std::toupper(s1[i]);
    }
}

std::cout << s1 << std::endl;

}