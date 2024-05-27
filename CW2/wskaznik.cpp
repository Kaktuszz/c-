#include <iostream>

int swap(int* wsk1, int* wsk2){
    int* s1 = wsk1;
    int* s2 = wsk2;
    wsk1 = s2;
    wsk2 = s1;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "wsk A: " << wsk1 << " : " << *wsk1 << std::endl;
    std::cout << "wsk B: " << wsk2 << " : " << *wsk2 << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    return 0;
}

int main(){
    int a = 99;
    int b = 0;
    int *pointer_a = &a;
    int *pointer_b = &b;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "pointer_A: " << pointer_a << " : " << *pointer_a << std::endl;
    std::cout << "pointer_B: " << pointer_b << " : " << *pointer_b << std::endl;
    swap(pointer_a,pointer_b);
    return 0;
};