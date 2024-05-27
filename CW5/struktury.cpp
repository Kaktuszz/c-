#include <iostream>
#include <string>
/// Struktura zwykła
struct Student
{
    std::string imie;
    std::string nazwisko;
    int id;
    float ocena;

    void print(){
        std::cout << "Student | Imie: " << imie << " | Nazwisko: " << nazwisko << " | ID: " << id << " | Ocena: " << ocena << std::endl;
    }

    void setStudent(std::string im, std::string nazw, int i, float ocen){
        imie = im;
        nazwisko = nazw;
        id = i;
        ocena = ocen;
        return;
    }
};

/// Struktura anonimowa
struct
{
    int A = 1;
    int B = 10;
    int C = 3;

    void print(){
        std::cout << A+B+C << std::endl;
    }
    
} myStruct1, myStruct2, myStruct3;



int main(){
    Student s1;
    s1.setStudent("Imie", "Nazwisko", 10, 7);
    s1.print();
    myStruct1.print();
    return 0;
}