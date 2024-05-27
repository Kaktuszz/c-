#include <iostream>
#include <string>

auto main()->int{
    std::string s1;
    for(auto i(0);i<257; i++){
        s1 += "a";
        std::cout << s1.size() << "-" << s1.capacity() << std::endl;
    }
    
    std::cout << std::string::npos << std::endl;

    
    return 0;
};