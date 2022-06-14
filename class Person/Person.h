#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

enum class Service { emergency_service, reserve, contract_service };
enum class Weapon { knife, pistol, machine_gun, machine };
enum class Category { no_category, first_category, highest_category };

std::ostream& operator << (std::ostream& o, const Category ct)
{
    switch (ct)
    {
    case Category::no_category:
        o << "no_category";break;
    case Category::first_category:
        o << "first_category";break;
    case Category::highest_category:
        o << "highest_category";break;
    }
    return o;
}

std::ostream& operator << (std::ostream& o, const Service sv)
{
    switch (sv)
    {
    case Service::emergency_service:
        o << "emergency_service";break;
    case Service::reserve:
        o << "reserve";break;
    case Service::contract_service:
        o << "contract_service";break;
    }
    return o;
}
std::ostream& operator << (std::ostream& o, const Weapon wp)
{
    switch (wp)
    {
    case Weapon::knife:
        o << "knife";break;
    case Weapon::pistol:
        o << "pistol";break;
    case Weapon::machine_gun:
        o << "machine_gun";break;
    case Weapon::machine:
        o << "machine";break;
    }
    return o;
}
class Person
{
public:
    virtual void print() = 0;
    virtual void fight() = 0;
    virtual void reserve() = 0;
    virtual void bonus_salary() = 0;
    virtual void holiday_pay() = 0;
    virtual ~Person() {}
    Person() {}
    Person(std::string country,std::string city,std::string full_name)
    {
        this->country = country;
        this->city = city;
        this->full_name = full_name;;
    }
    bool countWord() 
    {
        int len = 0;
        int numWords = 0;
        for (int i = 0;i < full_name.length();i++) {
            if (full_name[i] == ' ') {
                len = 0;
            }
            else if (++len == 1) {
                numWords++;
            }
        }
        return numWords == 3;
    }
    bool space() 
    {
        for (int i = 0; i < full_name.length();i++) {
            if (full_name[i] != ' ' && full_name[i + 1] == ' ' && full_name[i + 2] != ' ') {
                return true;
            }
            else if (full_name[i] != ' ' && full_name[i + 1] == ' ' && full_name[i + 2] == ' ') {
                return false;
            }
            i++;
        }
    }
    bool livesInUkraine() const
    {
        return country == "Ukraine";
    }
    bool livesInLviv() const
    {
        return city == "Lviv";
    }
    void info()
    {
        if (livesInUkraine() && livesInLviv()) {
            std::cout << "Lives in Ukraine in Lviv" << std::endl;
        }
        else if (!livesInUkraine() && !livesInLviv()) {
            std::cout << "Lives in Ukraine not in Lviv " << std::endl;
        }
        else {
            std::cout << "Lives abroad" << std::endl;
        }
        if (countWord() && space()) {
            std::cout << "The full name consists of three words and one space between them" << std::endl;
        }
        else if (countWord() && !space()) {
            std::cout << "The full name consists of three words and more than one space between words" << std::endl;
        }
        else {
            std::cout << "Doesn't have three words" << std::endl;
        }
    }
private:
    std::string full_name;
    std::string country;
    std::string city;
};
class Soldier :public Person
{
public:
    Soldier(std::string country, std::string city, std::string full_name, Weapon wp, double TOS, int& NOF, Service sv);
        //:Person(country,city,full_name) {}
    Service Get_Service()const { return service; }
    Weapon Get_Weapon()const { return weapon; }
     void fight()
    {
        if (Get_Service() != Service::reserve)
        {
            NOF++;
        }
    }
     void reserve()
    {
        if (Get_Service() != Service::reserve)
        {
            service = Service::reserve;
        }
    }
     void rank_system()
    {
        if (NOF < 5)
        {
            std::cout << "Rank - soldier" << std::endl;
        }
        if (NOF >= 5 && NOF < 10)
        {
            std::cout << "Rank - senior soldier" << std::endl;
        }
        if (NOF >= 10 && NOF < 15)
        {
            std::cout << "Rank - lance sergeant" << std::endl;
        }
        if (NOF >= 15)
        {
            std::cout << "Rank - sergeant" << std::endl;
        }
    }
    void print()
    {
        Person::info();
        std::cout << "Weapon - " << Get_Weapon() << std::endl;
        std::cout << "TOS - " << TOS << std::endl;
        std::cout << "NOF - " << NOF << std::endl;
        std::cout << "Service - " << Get_Service() << std::endl;
        rank_system();
        std::cout << std::endl;
    }
private:
    double TOS;//term_of_service;
    int NOF;//number_of_fights;
    Service service;
    Weapon weapon;
};

Soldier::Soldier(std::string country, std::string city, std::string full_name, Weapon wp, double TOS, int& NOF, Service sv)
    :Person(country, city, full_name),weapon(wp),service(sv){
    if (TOS < 0) { throw TOS; }
    this->TOS = TOS;
    if (NOF < 0) { throw NOF; }
    this->NOF = NOF;
}
class Teacher :public Person
{
public:
    Teacher(double experience, double& salary, Category);
    Category Get_Category()const { return category; }
     void bonus_salary()
    {
        double res;
        if (experience <= 5)
        {
            if (Get_Category() == Category::no_category)
            {
                res = (salary / 5) + (salary / 10);
            }
            else if (Get_Category() == Category::first_category)
            {
                res = (salary / 3) + (salary / 10);
            }
            else if (Get_Category() == Category::highest_category)
            {
                res = (salary / 2) + (salary / 10);
            }
        }
        if (experience > 5 && experience <= 15)
        {
            if (Get_Category() == Category::no_category)
            {
                res = (salary / 5) + (salary / 8);
            }
            else if (Get_Category() == Category::first_category)
            {
                res = (salary / 3) + (salary / 8);
            }
            else if (Get_Category() == Category::highest_category)
            {
                res = (salary / 2) + (salary / 8);
            }
        }
        if (experience > 15 && experience <= 25)
        {
            if (Get_Category() == Category::no_category)
            {
                res = (salary / 5) + (salary / 6);
            }
            else if (Get_Category() == Category::first_category)
            {
                res = (salary / 3) + (salary / 6);
            }
            else if (Get_Category() == Category::highest_category)
            {
                res = (salary / 2) + (salary / 6);
            }
        }
        salary += res;
    }
     void holiday_pay()
    {
        double res;
        int day;
        std::cin >> day;
        res = (salary / 30) * day;
        std::cout << "holiday_pay - " << res << std::endl;
    }
    void print()
    {
        std::cout << "experience - " << experience << std::endl;
        std::cout << "salary - " << salary << std::endl;
        std::cout << "Category - " << Get_Category() << std::endl;
    }
private:
    double experience;
    double salary;
    Category category;
};
Teacher::Teacher(double experience, double& salary, Category ct) :category(ct) {
    this->experience = experience;
    this->salary = salary;
}
class Person_System
{
public:
    ~Person_System();
    void add_soldier(std::string country, std::string city, std::string full_name,Weapon wp, double TOS, int& NOF, Service sv);
    void print();
    void fight();
    void del(int number);
    void menu();
    void reserve(int number);
    void add_teacher(double experience, double& salary, Category ct);
    void bonus_salary(int number);
    void holiday_pay(int number);
private:
    std::vector<Person*>people;
};
Person_System::~Person_System()
{
    for (int i = 0;i < people.size();i++)
        delete people[i];
}
void Person_System::menu()
{
    std::string country;
    std::string city;
    std::string full_name;
    int wp, sv,ct;
    double TOS;int NOF;
    double experience;
    double salary;
    double* sal_ptr = &salary;
    int* nof_ptr = &NOF;
    int number;
    int n;
    do
    {
        std::cout << "1. Create_soldier" << std::endl;
        std::cout << "2. Delete" << std::endl;
        std::cout << "3. Print" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cin >> n;

        try
        {
            switch (n)
            {
            case 1:
                do
                {
                    std::cout << "1. Add_soldier" << std::endl;
                    std::cout << "2. fight" << std::endl;
                    std::cout << "3. Reserve" << std::endl;
                    std::cout << "4. Menu" << std::endl;
                    std::cout << "0. Exit" << std::endl;
                    std::cin >> n;

                    try
                    {
                        switch (n)
                        {
                        case 1:
                            std::cout << "enter  country:";
                            std::cin.get();
                            std::getline(std::cin, country);
                            std::cout << "enter city:";
                            std::getline(std::cin, city);
                            std::cout << "enter  full name:";
                            std::cin.get();
                            std::getline(std::cin, full_name);
                            std::cout << "0 - knife,1 - pistol,2 - machine_gun,3 - machine;select weapon:";
                            std::cin >> wp;
                            if (wp < 0 || wp > 3) { throw wp; }
                            std::cout << "term of service:";
                            std::cin >> TOS;
                            std::cout << "number of fights:";
                            std::cin >> NOF;
                            std::cout << "0 - emergency_service,1 - reserve,2 - contract_service;select service:";
                            std::cin >> sv;
                            if (sv < 0 || sv > 2) { throw sv; }
                            add_soldier(country,city,full_name, Weapon(wp), TOS, NOF, Service(sv));
                            break;
                        case 2:
                            fight();
                            break;
                        case 3:
                            std::cin >> number;
                            reserve(number);
                            break;
                        case 4:
                            menu();
                            break;

                        }
                    }
                    catch (const std::exception&)
                    {
                        std::cout << "wrong number" << std::endl;
                    }
                } while (n != 0);
                break;
            case 2:
                std::cin >> number;
                del(number);
                break;
            case 3:
                print();
                break;
            }
        }
        catch (const std::exception&)
        {
            std::cout << "wrong number" << std::endl;
        }
    } while (n != 0);
}
void Person_System::add_soldier(std::string country, std::string city, std::string full_name,Weapon wp, double TOS, int& NOF, Service sv)
{
    people.push_back(new Soldier(country,city,full_name, wp, TOS, NOF, sv));
}
void Person_System::print()
{
    for (int i = 0;i < people.size();i++)
        people[i]->print();
}
void Person_System::fight()
{
    for (unsigned i = 0;i < people.size();i++)
        people[i]->fight();
}
void Person_System::del(int number)
{
    if (number > people.size()) throw std::exception();
    delete people[number];
    people.erase(people.begin() + number);
}
void Person_System::reserve(int number)
{
    if (number > people.size()) throw std::exception();
    people[number]->reserve();
}
void Person_System::add_teacher(double experience, double& salary, Category ct)
{
    people.push_back(new Teacher(experience, salary, ct));
}
void Person_System::bonus_salary(int number)
{
    if (number > people.size()) throw std::exception();
    people[number]->bonus_salary();
}
void Person_System::holiday_pay(int number)
{
    if (number > people.size()) throw std::exception();
    people[number]->holiday_pay();
}
