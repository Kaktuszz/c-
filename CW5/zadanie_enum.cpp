#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>
#include <bits/stdc++.h> 

namespace fs = std::filesystem;

enum class Field {
        id,
        nazwa,
        imie_a,
        nazwisko_a,
        rok
};


struct Book
{
    int id;
    std::string nazwa;
    std::string imie_a;
    std::string nazwisko_a;
    int rok;

    void print(){
        std::cout << id << nazwa << imie_a << nazwisko_a << " " << rok << std::endl;
    }

};

void sort(Field f, std::vector<Book> &vec){
    switch (f)
    {
    case Field::id:
        std::sort(vec.begin(),vec.end(), [](Book &a, Book &b){return (b.id < a.id);});
    //    std::cout << "id" << std::endl;

        break;
    case Field::nazwa:
        std::sort(vec.begin(),vec.end(), [](Book &a, Book &b){return (b.nazwa > a.nazwa);});
        break;
    case Field::nazwisko_a:
        std::sort(vec.begin(),vec.end(), [](Book &a, Book &b){return (b.nazwisko_a > a.nazwisko_a);});
        break;
    case Field::rok:
        std::sort(vec.begin(),vec.end(), [](Book &a, Book &b){return (b.rok > a.rok);});
        break;
    default:
        std::cout << "error" << std::endl;
        break;
    }
}



auto main(int argc, char* argv[])->int{

    if(argc < 2){
        std::cout << "Wpisz jeden argument (Nazwa pliku)" << std::endl;
        return 0;
    }

    fs::path katalog = fs::current_path();
    switch (fs::path p{argv[1]}; fs::status(p).type())
    {
    case fs::file_type::not_found:
        std::cout << "Nie istnieje takiego pliku" << std::endl;

        // Wypisuje zawartosc foldera
        for(auto i: fs::directory_iterator(katalog)){
            std::cout << i << std::endl;
        }
        return 0;
        break;
    
    default:
        break;
    }

    std::vector<Book> bookVector;

    std::ifstream ksiazki(argv[1]);

    if(ksiazki.is_open()){
        std::string line;
        int structures_id = 0;
        while (std::getline(ksiazki, line))
        {
            std::stringstream ss(line);
            std::string word;
            int g=0;
            int book_id;
            int book_year;
            Book newBook;
            while(std::getline(ss,word,';')){
                g++;
                switch (g)
                {
                case 1:
                    book_id = stoi(word);
                    newBook.id = book_id;
                    break;
                case 2:
                    newBook.nazwa = word;
                    break;
                case 3:
                    newBook.imie_a = word;
                    break;
                case 4:
                    newBook.nazwisko_a = word;
                    break;
                case 5:
                    book_year = stoi(word);
                    newBook.rok = book_year;
                    break;
                default:
                    std::cout << "Error " << g << std::endl;
                    break;
                }   
            }
           bookVector.push_back(newBook);
        }
    }

    // for(auto element : bookVector){
    //     element.print();
    // }

    // while(true){
        // std::string pole;
        // std::getline(std::cin,pole);
        sort(Field::rok, bookVector);
    // }
     for(auto element : bookVector){
        element.print();
    }

    return 0;
}