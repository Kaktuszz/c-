#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

class DataClass{
    protected:
        int id = 0;
        std::string name = " ";
        std::string surname = " ";
    public:
        DataClass(int i, std::string n, std::string s): id(i), name(n), surname(s){
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }
        virtual ~DataClass(){
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }
        virtual void Print(){
            std::cout << "ID " << id << "Imie: " << name << "Nazwisko: " << surname << std::endl; 
        }
};

class CustomerData : public DataClass{
    private: 
        std::string email = " ";
        int tel = 0;
    public:
        CustomerData(int i, std::string n, std::string s, std::string e, int t): DataClass(i,n,s){
            email = e;
            tel = t;
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }
        ~CustomerData(){
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }
        void Print() override{
            std::cout << " ID " << id << " Imie: " << name << " Nazwisko: " << surname << " Email: " << email << " Telefon: " << tel << std::endl; 
        }

};

class WorkerData : public DataClass{
    private: 
        std::string data = " ";
        std::string position = " ";
        int salary = 0;
    public:
        WorkerData(int i, std::string n, std::string s, std::string d, std::string p, int sal): DataClass(i,n,s){
            data = d;
            position = p;
            salary = sal;
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }
        ~WorkerData(){
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }
        void Print() override{
            std::cout << " ID " << id << " Imie: " << name << " Nazwisko: " << surname << " data: " << data << " position: " << position << " salary: " << salary << std::endl; 
        }

};



auto main()->int{
    std::string work_s, cust_s; 
    std::ifstream work_file ("pracownicy.dat");
    std::ifstream cus_file ("klienci.dat");

    std::vector<CustomerData> cus;
    std::vector<WorkerData> wor;

    if(work_file.is_open()){
        int i=0;
        while(getline(work_file,work_s)){
            if(i==0){
                i++;
                continue;
            }
            std::istringstream lineStream(work_s);

            std::cout << work_s << std::endl;
        }
        work_file.close();
    }


    CustomerData customer(1, "Bohdan", "Fedirko", "bebra@g.com", 214142124);
    WorkerData worker(1, "Bohdan", "Fedirko", "24.06.2001", "CEO OF BEBRA", 3000000);
    // customer.Print();
    // worker.Print();
    return 0;
}