#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <map>

namespace fs = std::filesystem;

// funkcja do zamiany na lowercase 
auto toLower(std::string word)->std::string {
    std::string result;
    for(auto i : word){
        result += std::tolower(i);
    }
    return result;
}

auto main(int argc, char* argv[])->int{

    if(argc < 2){
        std::cout << "Wpisz jeden argument (Nazwa pliku do analizy)" << std::endl;
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

    std::ifstream tekst(argv[1]);
// https://www.w3resource.com/cpp-exercises/file-handling/cpp-file-handling-exercise-3.php
// if/else do sprawdzania linijek 
    if(tekst.is_open()){
        std::string line;
        int line_count = 0;
        int char_count = 0;
        int word_count = 0;
        std::map<std::string,int> word_map;
        
        while(std::getline(tekst, line)){
            std::string curr_word;
            line_count++;
            for(int i=1;i<line.length(); i++){
                char_count++;

                if(line[i-1] != ' ' && line[i-1] != '-' && line[i-1] != '.' && line[i-1] != ','){
                    curr_word += line[i-1];
                }

                if(isalpha(line[i]) && !isalpha(line[i-1])){
                   word_count++;
                    // check this if.else
                    // zrobić za pomocą gotowych funkcyj
                    if(word_map.find(toLower(curr_word)) != word_map.end()){
                        word_map[toLower(curr_word)]++;
                        std::cout << curr_word << std::endl;
                        std::cout << word_map.size() << std::endl;

                    }else{
                        word_map[toLower(curr_word)] = 1;
                       std::cout << word_map.size() << std::endl;
                    }
                   curr_word = "";
                }
            }

            if(line.length() != 0){
                if(line.back() != ' ' || line.back() != '-'){
                    word_count++;
                }
            }
        }
        std::cout << "Liczba linijek w pliku: " << line_count << std::endl;
        std::cout << "Liczba znakow w pliku: " << char_count+1 << std::endl;
        std::cout << "Liczba slow w pliku: " << word_count << std::endl;
        for(auto it = word_map.cbegin(); it != word_map.cend(); ++it){

            std::cout << it->first << ": " << it->second << std::endl;

        }
    } else {
        std::cout << "Blad otwarcia pliku";
    }

  
    
    return 0;
}