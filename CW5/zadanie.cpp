#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

struct Book
{
    int id;
    std::string nazwa;
    std::string imie_a;
    std::string nazwisko_a;
    int rok;

    void print(){
        std::cout << id << " " << nazwa << " " << imie_a << " " << nazwisko_a << " " << rok << std::endl;
    }

};


auto main(int argc, char* argv[])->int{

    if(argc < 2){
        std::cout << "Wpisz jeden argument (Nazwa pliku)" << std::endl;
        return 0;
    }

    fs::path katalog = fs::current_path();
    switch (fs::path p{argv[1]}; fs::status(p).type())
    {
        // fs::file_type::regular 
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

    for(const auto& element : bookVector){
        //std::cout << element.print();
        std::cout << element.id << " " << element.nazwa << " " << element.imie_a << " " << element.nazwisko_a << " " << element.rok << std::endl;
    }

    return 0;
}