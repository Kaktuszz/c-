#include <iostream>
#include <string>

class MenuItem{ // klasa bazowa
protected:
    std::string name = " ";
    int calories = 0;
    float price = 0;

public:
    MenuItem(std::string n, int c, float p): name(n), calories(c), price(p){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    virtual ~MenuItem(){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    virtual void Print(){
        std::cout << "MenuItem: " << name << " calories: " << calories << " price: " << price << std::endl; 
    }

};

class FoodItem : public MenuItem
{
    private:
    int mass = 0;

public: 
    FoodItem(std::string n, int c, int m, float p): MenuItem(n,c,p){
        mass = m;
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    ~FoodItem(){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    void Print() override{
        std::cout << "FoodItem: " << name << " calories: " << calories << " mass: " << mass << " price: " << price << std::endl; 
    }
    float CalPerUnitMass(){
        return (float)calories/mass;
    }
};

class DrinkItem : public MenuItem{
private:
    int volume = 0; 

public:
    DrinkItem(std::string n, int c, int v, float p): MenuItem(n,c,p){
        volume = v;
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    ~DrinkItem(){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    void Print() override{
        std::cout << "DrinkItem: " << name << " calories: " << calories << " volume: " << volume << " price: " << price << std::endl; 
    }
     float CalPerUnitVolume(){
        return (float)calories/volume;
    }
};

auto main()->int{
    FoodItem food1("frytki", 500, 150, 12);
    food1.Print();
    std::cout << food1.CalPerUnitMass() << std::endl;
    DrinkItem drink1("Cola", 300, 200, 10);
    drink1.Print();
    std::cout << drink1.CalPerUnitVolume() << std::endl;

    MenuItem *item = nullptr;

    std::string order = " ";
    std::cout << "Zamowienie: nalesniki czy kompot?" << std::endl;
    std::cin >> order;
    if(order == "nalesniki"){
        item = new FoodItem("nalesniki", 600, 300, 20);
    }else if(order == "kompot"){
        item = new DrinkItem("kompot", 150, 200, 5);
    }else{
        std::cerr << "Bebra" << std::endl;
        return 1;
    }
    item->Print();
    return 0;
}