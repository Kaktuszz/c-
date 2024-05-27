#include <iostream>
#include <string>

auto main()->int{
    std::string s1;
    for(int i = 0; i<=25; i++){
        s1.insert(s1.end()-1,'*');
        std::cout << s1 << std::endl;
    }
    return 0;
};