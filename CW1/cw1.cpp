#include <iostream>

int main(){
    std::cout << "napisalem: " << 100 << "ksiazek, a ile ty? \n";
    int ilosc;
    std::cin >> ilosc;
        if(ilosc < 100){
            std::cout << "malo\n";
        }

    int x = 12;
    {int x = x;
    std::cout << x << "\n";}
    std::cout << x << "\n";


    return 0;
}