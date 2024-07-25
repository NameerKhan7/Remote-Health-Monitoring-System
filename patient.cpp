using namespace std;
#include<string>
#include<cstring>



class Patient
{

    string name;
    string username;
    string password;
    int age;

public:
    Patient(string  = "", int  = 0);

    void set_name(string = "");

    void set_age(int = 0 );

    string get_name();

    int get_age();
};


Patient::Patient(string name, int age)
{

    name = name;
    age = age;
}
void Patient::set_name(string n)
{

    name = n;
}

void Patient::set_age(int age)
{

    this->age = age;
}
string Patient::get_name()
{

    return name;
}

int Patient::get_age()
{

    return age;
}

