#include <iostream>

double operator"" _sec(long double x){
    return x/60;
}

int main(){
    std::cout << 70.0_sec << "\n";
    return 0;
};