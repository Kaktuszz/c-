#include <iostream>
#include <vector>

int main(){
    std::vector<int> table;
    int temp;
    while(true){
        std::cin >> temp;
        
        if(std::cin.good()){
            table.push_back(temp);
        }else{
            break;
        }
    }
    std::cout << std::endl;
    for(auto i: table){
        std::cout << table[i-1] << std::endl;
    }

    return 0;
};