#include "Person.h"

std::ostream& operator << (std::ostream& o, const Category ct)
{
    switch (ct)
    {
    case Category::no_category:
        o << "no_category"; break;
    case Category::first_category:
        o << "first_category"; break;
    case Category::highest_category:
        o << "highest_category"; break;
    }
    return o;
}
std::ostream& operator << (std::ostream& o, const Service sv)
{
    switch (sv)
    {
    case Service::emergency_service:
        o << "emergency_service"; break;
    case Service::reserve:
        o << "reserve"; break;
    case Service::contract_service:
        o << "contract_service"; break;
    }
    return o;
}
std::ostream& operator << (std::ostream& o, const Weapon wp)
{
    switch (wp)
    {
    case Weapon::knife:
        o << "knife"; break;
    case Weapon::pistol:
        o << "pistol"; break;
    case Weapon::machine_gun:
        o << "machine_gun"; break;
    case Weapon::machine:
        o << "machine"; break;
    }
    return o;
}

Person::Person(std::string country, std::string city, std::string full_name, Types type)
{
    this->country = country;
    this->city = city;
    this->full_name = full_name;
    this->type = type;
}
bool Person::countWord() const
{
    int len = 0;
    int numWords = 0;
    for (size_t i = 0; i < full_name.length(); i++) {
        if (full_name[i] == ' ') {
            len = 0;
        }
        else if (++len == 1) {
            numWords++;
        }
    }
    return numWords == 3;
}
bool Person::space() const
{
    for (size_t i = 0; i < full_name.length(); i++) {
        if (full_name[i] != ' ' && full_name[i + 1] == ' ' && full_name[i + 2] != ' ') {
            return true;
        }
        else if (full_name[i] != ' ' && full_name[i + 1] == ' ' && full_name[i + 2] == ' ') {
            return false;
        }
        i++;
    }
    return false;
}
void Person::info() const
{
    if (livesInUkraine() && livesInLviv()) {
        std::cout << "Lives in Ukraine in Lviv" << std::endl;
    }
    else if (livesInUkraine() && !livesInLviv()) {
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
void Person::print() const
{
    std::cout << "Full name - " << full_name << std::endl;
    std::cout << "Country - " << country << std::endl;
    std::cout << "City - " << city << std::endl;
    std::cout << std::endl;
}

Soldier::Soldier(std::string country, std::string city, std::string full_name, Weapon wp, double TOS, int& NOF, Service sv)
    :Person(country, city, full_name, Types::soldier), weapon(wp), service(sv) {
    if (TOS < 0) { throw std::exception(); }
    this->TOS = TOS;
    if (NOF < 0) { throw std::exception(); }
    this->NOF = NOF;
}
void Soldier::fight()
{
    if (Get_Service() != Service::reserve)
    {
        NOF++;
    }
}
void Soldier::reserve()
{
    if (Get_Service() != Service::reserve)
    {
        service = Service::reserve;
    }
}
void Soldier::rank_system() const
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
void Soldier::print() const
{
    Person::info();
    Person::print();
    std::cout << "Weapon - " << Get_Weapon() << std::endl;
    std::cout << "Term of service; - " << TOS << std::endl;
    std::cout << "Number of fights; - " << NOF << std::endl;
    std::cout << "Service - " << Get_Service() << std::endl;
    rank_system();
    std::cout << std::endl;
}

Teacher::Teacher(std::string country, std::string city, std::string full_name,
    double experience, double& salary, Category ct) : Person(country, city, full_name, Types::teacher),
    category(ct)
{
    if (experience < 0) { throw std::exception(); }
    this->experience = experience;
    if (salary < 0) { throw std::exception(); }
    this->salary = salary;
}
void Teacher::bonus_salary()
{
    double res = 0;
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
double Teacher::holiday_pay(int day) 
{
    res = (salary / 30) * day;
    return res;
}
void Teacher::print() const
{
    Person::info();
    Person::print();
    std::cout << "experience - " << experience << std::endl;
    std::cout << "salary - " << salary << std::endl;
    std::cout << "Category - " << Get_Category() << std::endl;
    std::cout << "holiday_pay - " << res << std::endl;
    std::cout << std::endl;
}

Person_System::~Person_System()
{
    for (size_t i = 0; i < people.size(); i++)
        delete people[i];
}
void Person_System::menu()
{
    std::string country;
    std::string city;
    std::string full_name;
    int wp, sv, ct;
    double TOS; int NOF;
    double experience,res;
    double* res_ptr = &res;
    double salary;
    double* sal_ptr = &salary;
    int* nof_ptr = &NOF;
    int number;
    int n,day;
    do
    {
        std::cout << "1. Create_soldier" << std::endl;
        std::cout << "2. Create_teacher" << std::endl;
        std::cout << "3. Delete" << std::endl;
        std::cout << "4. Print" << std::endl;
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
                            //std::cin.get();
                            std::getline(std::cin, full_name);
                            std::cout << "0 - knife,1 - pistol,2 - machine_gun,3 - machine;select weapon:";
                            std::cin >> wp;
                            if (wp < 0 || wp > 3) { throw std::exception(); }
                            std::cout << "term of service:";
                            std::cin >> TOS;
                            std::cout << "number of fights:";
                            std::cin >> NOF;
                            std::cout << "0 - emergency_service,1 - reserve,2 - contract_service;select service:";
                            std::cin >> sv;
                            if (sv < 0 || sv >= 3) { throw std::exception(); }
                            add_soldier(country, city, full_name, Weapon(wp), TOS, NOF, Service(sv));
                            break;
                        case 2:
                            fight();
                            break;
                        case 3:
                            std::cout << "enter index to reserve:";
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
                do
                {
                    std::cout << "1. Add_teacher" << std::endl;
                    std::cout << "2. Bonus salary" << std::endl;
                    std::cout << "3. Holiday pay" << std::endl;
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
                            //std::cin.get();
                            std::getline(std::cin, full_name);
                            std::cout << "enter  experience:";
                            std::cin >> experience;
                            std::cout << "enter  salary:";
                            std::cin >> salary;
                            std::cout << "0 - no_category,1 - first_category,2 - highest_category;select category:";
                            std::cin >> ct;
                            //if (ct < 0 || sv >= 3) { throw std::exception(); }
                            add_teacher(country, city, full_name,experience,salary, Category(ct));
                            break;
                        case 2:
                            std::cout << "enter index to bonus_salary:";
                            std::cin >> number;
                            bonus_salary(number);
                            break;
                        case 3:
                            std::cout << "enter index to holiday_pay:";
                            std::cin >> number;
                            std::cout << "enter the number of vacation days:";
                            std::cin >> day;
                            holiday_pay(number, day);
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
            case 3:
                std::cout << "enter index to delete:";
                std::cin >> number;
                del(number);
                break;
            case 4:
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
void Person_System::add_soldier(std::string country, std::string city, std::string full_name, Weapon wp, double TOS, int& NOF, Service sv)
{
    people.push_back(new Soldier(country, city, full_name, wp, TOS, NOF, sv));
}
void Person_System::print()
{
    for (size_t i = 0; i < people.size(); i++)
        people[i]->print();
}
void Person_System::fight()
{
    for (Person* i : people)
    {
        if (i->GetType() == Types::soldier)
        {
            Soldier* ptrSoldier = dynamic_cast<Soldier*>(i);
            ptrSoldier->fight();
        }
    }
}
void Person_System::del(size_t number)
{
    if (number > people.size()) throw std::exception();
    delete people[number];
    people.erase(people.begin() + number);
}
void Person_System::reserve(size_t number)
{
    if (number >= people.size() || people[number]->GetType() != Types::soldier) throw std::exception();
    Soldier* ptrSoldier = dynamic_cast<Soldier*>(people[number]);
    ptrSoldier->fight();
}
void Person_System::add_teacher(std::string country, std::string city, std::string full_name,
    double experience, double& salary, Category ct)
{
    people.push_back(new Teacher(country, city, full_name, experience, salary, ct));
}
void Person_System::bonus_salary(size_t number)
{
    if (number > people.size() || people[number]->GetType() != Types::teacher) throw std::exception();
    Teacher* ptrTeacher = dynamic_cast<Teacher*>(people[number]);
    ptrTeacher->bonus_salary();
}
void Person_System::holiday_pay(size_t number, int day)
{
    if (number > people.size() || people[number]->GetType() != Types::teacher) throw std::exception();
    Teacher* ptrTeacher = dynamic_cast<Teacher*>(people[number]);
    ptrTeacher->holiday_pay(day);
}
