#include <iostream>
#include <vector>
#include <algorithm> 

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

    int* maxElement = std::max_element(table, 4);
    std::cout << "maxElement: %d\n", maxElement;
    int* minElement = std::min_element(table, 4);
    std::cout << "minElement: %d\n", minElement;
    int* maxNum = std::max(5,10);
    std::cout << "maxNum: %d\n", maxNum;
    int* minNum = std::min(5,10);
    std::cout << "minNum: %d\n", minNum;
    return 0;
};