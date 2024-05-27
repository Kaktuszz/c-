#include <iostream>
#include <array>

int main(){
    std::array<int, 5> table;
    for(int i = 0; i<5; i++){
        int number;
        std::cin >> number;
        table[i] = number;
    }
    std::cout << std::endl;
    for(int i = 0; i<5;i++){
        std::cout << table[i] << std::endl;
    }

    return 0;
};