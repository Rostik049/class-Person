#pragma once
#include <iostream>
#include <string>
#include <vector>

enum class Types { soldier, teacher, base };
enum class Service { emergency_service, reserve, contract_service };
enum class Weapon { knife, pistol, machine_gun, machine };
enum class Category { no_category, first_category, highest_category };

class Person
{
protected:
    Person()/* : type(Types::base)*/ {};
    Person(std::string country, std::string city, std::string full_name, Types type = Types::base);
public:
    virtual ~Person() {}
    virtual void print() const;
    bool countWord() const;
    bool space() const;
    bool livesInUkraine() const { return country == "Ukraine"; }
    bool livesInLviv() const { return city == "Lviv"; }
    void info() const;

    Types GetType() const { return type; }

    //virtual void fight() = 0;
    //virtual void reserve() = 0;
    //virtual void bonus_salary() = 0;
    //virtual void holiday_pay() = 0;        

private:
    std::string full_name;
    std::string country;
    std::string city;

    Types type;
};

class Soldier :public Person
{
public:
    Soldier(std::string country, std::string city, std::string full_name, Weapon wp, double TOS, int& NOF, Service sv);
    Service Get_Service()const { return service; }
    Weapon Get_Weapon()const { return weapon; }
    void fight();
    void reserve();
    void rank_system() const;
    void print() const override;
private:
    double TOS;//term_of_service;
    int NOF;//number_of_fights;
    Service service;
    Weapon weapon;
};

class Teacher :public Person
{
public:
    Teacher(std::string country, std::string city, std::string full_name,
        double experience, double& salary, Category);
    Category Get_Category()const { return category; }
    void bonus_salary();
    double holiday_pay(int day) const;
    void print() const override;

private:
    double experience;
    double salary;
    Category category;
};

class Person_System
{
public:
    ~Person_System();
    void add_soldier(std::string country, std::string city, std::string full_name, Weapon wp, double TOS, int& NOF, Service sv);
    void print();
    void fight();
    void del(size_t number);
    void menu();
    void reserve(size_t number);
    void add_teacher(std::string country, std::string city, std::string full_name, double experience, double& salary, Category ct);
    void bonus_salary(size_t number);
    void holiday_pay(size_t number, int day);
private:
    std::vector<Person*>people;
};
