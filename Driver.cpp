// #include "accountclass.h"
// #include"headers.h"
#include "patient.cpp"
#include "iot.cpp"
#include <string>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <math.h>

using namespace std;
// #include<time.h>

// char username[30] = "\0"; // using global variable array
// char password[30] = "\0"; // using global  variable array

int choice()
{

    int rchoice = 0;
    cout << "1. BLOOD PRESSURE" << endl;
    cout << "2. BMI" << endl;
    cout << "3. Pulse" << endl;
    cout << "4. Heartbeat" << endl;
    cout << "5. Oxygen" << endl;
    cout << "0. Exit" << endl;
    cin >> rchoice;

    return rchoice;
}

class UserAccount : public Patient
{
    string Name;
    string age;
    string city;
    string address;
    string phone;
    string gender;
    string Username;
    string Password;

public:
    void inputbasicinfo();
    void showbasicinfo();
    void setusername(string username);
    void setpass(string password);
    string getusername();
    string getpass();
    string getname();
    string getaddress();
    string getcity();
    string getphone();
    string getgender();
    string getage();
    void setname(string name);
    void setaddress(string address);
    void setcity(string city);
    void setphone(string phone);
    void setgender(string gender);
    void setage(string age);

    void input();
    bool login();
    int mobileapp();
    int choicemain();
    void signup(string = "", string = "", int namelen = 0, int passlen = 0);
};

void loadingBar()
{
    cout << "\n\n";
    cout << setw(45) << "Creating account...\n\n";
    cout << setw(25);

    for (int i = 0; i < 26; i++)
    {
        cout << "*";
    }
    cout << "\r";
    cout << setw(25);

    for (int i = 0; i < 26; i++)
    {
        cout << "-";

        Sleep(50);
    }
    cout << endl;
    system("CLS");
    Sleep(1000);
}

void UserAccount ::input()
{
    string name;
    string username;
    string password;

    cout << "Enter your name: ";
    cin >> name;
    Name = name;

    cout << "Sir " << name << " You Have to create a User account first" << endl;

    cout << "Enter Username : ";
    cin >> username;
    cout << "Enter Password : ";
    cin >> password;

    int namelen = username.size();
    int passlen = password.size();
    //    cout<<passlen<<endl;

    int checkname = Username.size();

    int checkpass = Password.size();

    if (checkname != namelen || checkpass != passlen)
    {
        signup(username, password, namelen, passlen);
    }

    else
    {
        login();
    }
}
void UserAccount ::showbasicinfo()
{
    cout << "Basic info" << endl;
    cout << "Name: " << Name << endl;
    cout << "Age: " << age << endl;
    cout << "City: " << city << endl;
    cout << "Address: " << address << endl;
    cout << "Phone: " << phone << endl;
}

void UserAccount::inputbasicinfo()
{
    cout << "Basic info" << endl;
    cout << "Enter Your Name" << endl;
    cin >> Name;
    setname(Name);
    cout << "Enter your age : " << endl;
    cin >> age;
    setage(age);
    cout << "Enter your gender (M or F): " << endl;
    cin >> gender;
    setgender(gender);
    cout << "Enter your address (for emergency case) : " << endl;
    cin >> address;
    setaddress(address);
    cout << "Enter your city : " << endl;
    cin >> city;
    setcity(city);

    cout << "Enter your phone : " << endl;
    cin >> phone;
    setphone(phone);
}

void UserAccount::setname(string name)
{
    this->Name = name;
}

void UserAccount::setaddress(string address)
{
    this->address = address;
}

void UserAccount::setcity(string city)
{
    this->city = city;
}

void UserAccount::setphone(string phone)
{
    this->phone = phone;
}

void UserAccount::setage(string age)
{
    this->age = age;
}

void UserAccount::setgender(string gender)
{
    this->gender = gender;
}

string UserAccount::getname()
{
    return Name;
}

string UserAccount::getaddress()
{
    return address;
}

string UserAccount::getcity()
{
    return city;
}

string UserAccount::getphone()
{
    return phone;
}

string UserAccount::getage()
{
    return age;
}

string UserAccount::getgender()
{
    return gender;
}

bool UserAccount::login()
{

    int tryagain = 1;
    string username;
    string password;
    ofstream ifile;
    char array[30];
    string name = "";
    ifile.open("user1.dat", ios::binary);
    if (!ifile.is_open())
    {
        cout << "file did'nt opened" << endl;
    }
    else
    {
        do
        {
            // getline(ifile,name);

            cout << "now for login" << endl;
            cout << "Enter Username  : " << endl;

            cin >> username;

            cout << "Enter Password : " << endl;
            cin >> password;

            int nresult = Username.compare(username);
            // cout << nresult << endl;
            int presult = Password.compare(password);
            // cout << presult << endl;

            if (nresult == 0 && presult == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // green font
                cout << "User account is valid" << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font
                tryagain = 0;
                return true; // user valid

                // then the call for next class here;

                cout << endl;
            }

            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // red font
                cout << "User account is not valid" << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font
                cout << "1 for Try again (0 for exit)" << endl;
                cout << "Enter your choice : " << endl;
                cin >> tryagain;
            }
        } while (!tryagain == 0);
    }
}
int UserAccount::choicemain()
{
    int rchoice = 0;
    cout << "1. BLOOD PRESSURE" << endl;
    cout << "2. BMI" << endl;
    cout << "3. Pulse" << endl;
    cout << "4. Heartbeat" << endl;
    cout << "5. Oxygen" << endl;
    cout << "6. Hand Tremor " << endl;
    cout << "7. No of dectected Movements " << endl;
    cout << "0. Exit" << endl;
    cin >> rchoice;
    return rchoice;
}
int UserAccount::mobileapp()
{

    int choice = 0;
    int retry = 1;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // Green font
    cout << "\t\t\tPATIENT MOBILE APP" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font
    cout << "1.Check vitals of last 90 days " << endl;
    cout << "2.For Specific day search " << endl;
    cout << "3.Appointment or consultation" << endl;
    cout << "4.To see basic information " << endl;
    cout << "5.To make a call to doctor " << endl;
    cout << "6.Send data to RMC2" << endl;
    cout << "0.EXIT" << endl;
    cin >> choice;
    return choice;
}

void UserAccount::signup(string name, string pass, int namelen, int passlen)
{

    Username = name;
    Password = pass;

    int nlen = name.size();
    int plen = pass.size();

    char *n = new char(nlen);
    char *p = new char(plen);
    // convert string into char array;
    for (int i = 0; i < nlen; i++)
    {
        n[i] = name[i];
    }

    for (int i = 0; i < plen; i++)
    {
        p[i] = pass[i];
    }
    cout << endl;
    cout << "username is " << Username << endl;
    cout << "password is " << Password << endl;

    ofstream ofile;
    ofile.open("user1.dat", ios::binary);
    for (int i = 0; i < nlen; i++)
    {
        ofile.write((char *)&n[i], sizeof(n[i]));
    }
    ofile << endl;
    cout << endl;
    for (int i = 0; i < plen; i++)
    {
        ofile.write((char *)&p[i], sizeof(p[i]));
    }

    cout << endl;

    ofile.close();
    ifstream ifile;
    ifile.open("user1.dat", ios::in);
    if (!ifile.is_open())
    {
        cout << "no such file" << endl;
    }
    else
    {
        // cout << "reading from the file" << endl;
        for (int i = 0; i < nlen; i++)
            ifile.read((char *)&n[i], sizeof(n[i]));

        for (int i = 0; i < plen; i++)
            ifile.read((char *)&p[i], sizeof(p[i]));
    }
    loadingBar(); // fancy stuff

    cout << "User account is created" << endl;
}

//----------------------------------------------RMC2----------------------------------------------

class RMC2 : public Bp, public oxygen, public heartbeat, public pulse
{

    int bphiarray[90];
    int bploarray[90];
    int pulsearray[90];
    int heartarray[90];
    int oxyarray[90];

public:
    void getbphigh();
    void getbplow();
    void getpul();
    void getheart();
    void getoxy();

    void showvitals();
    void storeinfile();
    void fromfile();
};

void RMC2 ::getbphigh()
{

    for (int i = 0; i < 90; i++)
    {
        bphiarray[i] = gethibp(i);
    }
}

void RMC2 ::getbplow()
{

    for (int i = 0; i < 90; i++)
    {
        bploarray[i] = getlobp(i);
    }
}

void RMC2 ::getoxy()
{
    for (int i = 0; i < 90; i++)
    {
        oxyarray[i] = getoxygen(i);
    }
}

void RMC2 ::getpul()
{
    for (int i = 0; i < 90; i++)
    {
        pulsearray[i] = getpulse(i);
    }
}

void RMC2 ::getheart()
{
    for (int i = 0; i < 90; i++)
    {
        heartarray[i] = getheartbeat(i);
    }
}

void RMC2::showvitals()
{

    for (int i = 0; i < 90; i++)
    {

        cout << bphiarray[i] << "\t" << bploarray[i] << "\t" << pulsearray[i] << "\t" << heartarray[i] << "\t" << oxyarray[i] << endl;
    }
}

void RMC2::storeinfile()
{

    ofstream ovitals;
    ovitals.open("vitals.dat", ios::binary);

    for (int i = 0; i < 90; i++)
    {
        ovitals.write((char *)&bphiarray[i], sizeof(bphiarray[i]));
        ovitals.write((char *)&bploarray[i], sizeof(bploarray[i]));
        ovitals.write((char *)&pulsearray[i], sizeof(pulsearray[i]));
        ovitals.write((char *)&heartarray[i], sizeof(heartarray[i]));
        ovitals.write((char *)&oxyarray[i], sizeof(oxyarray[i]));
    }
}

void RMC2::fromfile()
{
    int hib[90];
    int lob[90];
    int p[90];
    int hb[90];
    int o[90];

    ifstream ivitals;
    ivitals.open("vitals.dat", ios::binary);
    for (int i = 0; i < 90; i++)
    {
        ivitals.read((char *)&hib[i], sizeof(hib[i]));
        ivitals.read((char *)&lob[i], sizeof(lob[i]));
        ivitals.read((char *)&p[i], sizeof(p[i]));
        ivitals.read((char *)&hb[i], sizeof(hb[i]));
        ivitals.read((char *)&o[i], sizeof(o[i]));
    }
		cout<<"BP HIGH\tBP Low\tPulse\tHeartbeat  OXYGEN"<<endl;
    for (int i = 0; i < 90; i++)
        cout << bphiarray[i] << "\t" << bploarray[i] << "\t" << pulsearray[i] << "\t" << heartarray[i] << "\t   " << oxyarray[i] << endl;
}

//--------------------------------------Appointments------------------------------------------------------------
class appointmentDoctors : public Patient
{
    string n1 = "Dr.Rizwanullah (Psychiatrists)";
    string n2 = "Dr.Abdullah (Dermatologist)";
    string n3 = "Dr.Moiz (Surgeon)";
    string n4 = "Dr.Idrees (Dentist)";
    string n5 = "Dr.Azan Afzal (Neurologist)";

    string Name;

public:
    int showdoc();
    void docreadwrite();
    int mobileapp();
    void hehe();
    bool doc1();
    bool doc2();
    bool doc3();
    bool doc4();
    bool doc5();
};

int appointmentDoctors::mobileapp()
{

    int choice = 0;
    int retry = 1;

    cout << "\t\t\tPATIENT MOBILE APP" << endl;
    cout << "1.Check vitals of last 90 days " << endl;
    cout << "2.For Specific day search " << endl;
    cout << "3.Appointment or consultation" << endl;
    cout << "0.EXIT" << endl;
    cin >> choice;
    return choice;
}

bool appointmentDoctors::doc5()
{
    string name = "Dr.Azan Afzal (Neurologist)";
    int r;
    srand(time(0));
    r = rand() % 2;
    if (r == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool appointmentDoctors::doc4()
{

    string name = "Dr.Idrees (Dentist)";
    int r;
    srand(time(0));
    r = rand() % 2;
    if (r == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool appointmentDoctors::doc3()
{
    string name = "Dr.Moiz (Surgeon)";
    srand(time(0));
    int r;
    r = rand() % 2;
    if (r == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool appointmentDoctors::doc2()
{
    string name = "Dr.Abdullah (Dermatologist)";
    int r;
    srand(time(0));
    r = rand() % 2;
    if (r == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool appointmentDoctors::doc1()
{
    string name = "Dr.Rizwanullah (Psychiatrists)";
    int r;
    srand(time(0));
    r = rand() % 2;
    if (r == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int appointmentDoctors::showdoc()
{
    int x;

    cout << "1. " << n1 << endl;
    cout << "2. " << n2 << endl;
    cout << "3. " << n3 << endl;
    cout << "4. " << n4 << endl;
    cout << "5. " << n5 << endl;
    cout << endl;
    cout << "Which doctors do you want to see?" << endl;
    cin >> x;
    return x;
}

void appointmentDoctors::docreadwrite()
{

    cout << "hehehe" << endl;
    // lenght of doctor names
    int len1;
    int len2;
    int len3;
    int len4;
    int len5;

    // array of doctors
    char doc1[len1];
    char doc2[len2];
    char doc3[len3];
    char doc4[len4];
    char doc5[len5];

    len1 = n1.size();
    len2 = n2.size();
    len3 = n3.size();
    len4 = n4.size();
    len5 = n5.size();

    char *p1 = new char(len1);
    char *p2 = new char(len2);
    char *p3 = new char(len3);
    char *p4 = new char(len4);
    char *p5 = new char(len5);

    ofstream ofiledocname;
    ofiledocname.open("doc.dat", ios::binary);
    if (!ofiledocname.is_open())
    {
        cout << "file didnt opened" << endl;
    }
    else
    {

        cout << "2 hehehe" << endl;
        for (int i = 0; i < len1; i++)
        {
            p1[i] = n1[i];
        }
        for (int i = 0; i < len2; i++)
        {
            p2[i] = n2[i];
        }

        for (int i = 0; i < len3; i++)
        {
            p3[i] = n3[i];
        }
        for (int i = 0; i < len4; i++)
        {
            p4[i] = n4[i];
        }
        for (int i = 0; i < len5; i++)
        {
            p5[i] = n5[i];
        }

        for (int i = 0; i < len1; i++)
        {
            ofiledocname.write((char *)&p1[i], sizeof(p1[i]));
        }

        for (int i = 0; i < len2; i++)
        {
            ofiledocname.write((char *)&p2[i], sizeof(p2[i]));
        }
        for (int i = 0; i < len3; i++)
        {
            ofiledocname.write((char *)&p3[i], sizeof(p3[i]));
        }

        for (int i = 0; i < len4; i++)
        {
            ofiledocname.write((char *)&p4[i], sizeof(p4[i]));
        }
        for (int i = 0; i < len5; i++)
        {
            ofiledocname.write((char *)&p5[i], sizeof(p5[i]));
        }

        //  cout << "================write ho gye hy";
    }

    ofiledocname.close();

    ifstream ifiledoc;
    ifiledoc.open("doctornames.dat", ios::binary);
    if (!ifiledoc.is_open())
    {
        cout << "Couldn't open doctornames.dat" << endl;
    }
    else
    {

        for (int i = 0; i < len1; i++)
        {
            ifiledoc.read((char *)&doc1[i], sizeof(doc1[i]));
            cout << doc1[i];
        }
        for (int i = 0; i < len2; i++)
            ifiledoc.read((char *)&doc2[i], sizeof(doc2[i]));

        for (int i = 0; i < len3; i++)
            ifiledoc.read((char *)&doc3[i], sizeof(doc3[i]));
        for (int i = 0; i < len4; i++)
            ifiledoc.read((char *)&doc4[i], sizeof(doc4[i]));
        for (int i = 0; i < len5; i++)
            ifiledoc.read((char *)&doc5[i], sizeof(doc5[i]));

        ifiledoc.close();

    } // else's bracket

    int docchoice = 0;
    for (int i = 0; i < len1; i++)
        cout << "1. " << doc1[i];

    cout << endl;

    for (int i = 0; i < len2; i++)
        cout << "2. " << doc2[i];

    cout << endl;

    for (int i = 0; i < len3; i++)
        cout << "3. " << doc3[i];

    cout << endl;

    for (int i = 0; i < len4; i++)
        cout << "4. " << doc4[i];

    cout << endl;

    for (int i = 0; i < len5; i++)
        cout << "5. " << doc5[i];

    cout << endl;

    cout << "which doctor do you want to appoint with: " << endl;
    cin >> docchoice;
}

class DoctorApp : public RMC2
{
    string Name;

public:
    void viewpatients();
    void storedata();
    int selection();
    void makecall();
    void approvingrequest();
};
int DoctorApp::selection()
{
    int patientselection = 0;
    string n1 = "Abdullah Nadeem";
    string n2 = "Inshal";
    string n3 = "Mueed";
    string n4 = "Khaqan";
    string n5 = "Musaab bhai";
    string n6 = "Ahmed mustafa mario";
    string n7 = "Ibtihaj";
    string n8 = "Usman";
    string n9 = "Saad";
    string n10 = "Abu baqar shareef";
    cout << "For which Patient do you want to view data for: " << endl;
    cout << "1. " << n1 << endl;
    cout << "2. " << n2 << endl;
    cout << "3. " << n3 << endl;
    cout << "4. " << n4 << endl;
    cout << "5. " << n5 << endl;
    cout << "6. " << n6 << endl;
    cout << "7. " << n7 << endl;
    cout << "8. " << n8 << endl;
    cout << "9. " << n9 << endl;
    cout << "10. " << n10 << endl;
    cin >> patientselection;
    return patientselection;
}
void DoctorApp::viewpatients()
{
    string n1 = "Abdullah Nadeem";

    string n2 = "Inshal";
    string n3 = "Mueed";
    string n4 = "Khaqan";
    string n5 = "Musaab bhai";
    string n6 = "Ahmed mustafa mario";
    string n7 = "Ibtihaj";
    string n8 = "Usman";
    string n9 = "Saad";
    string n10 = "Abu baqar shareef";

    cout << "1. " << n1 << endl;
    cout << "2. " << n2 << endl;
    cout << "3. " << n3 << endl;
    cout << "4. " << n4 << endl;
    cout << "5. " << n5 << endl;
    cout << "6. " << n6 << endl;
    cout << "7. " << n7 << endl;
    cout << "8. " << n8 << endl;
    cout << "9. " << n9 << endl;
    cout << "10. " << n10 << endl;
}
void DoctorApp::makecall()
{
    string n1 = "Abdullah Nadeem";
    string n2 = "Inshal";
    string n3 = "Mueed";
    string n4 = "Khaqan";
    string n5 = "Musaab bhai";
    string n6 = "Ahmed mustafa mario";
    string n7 = "Ibtihaj";
    string n8 = "Usman";
    string n9 = "Saad";
    string n10 = "Abu baqar shareef";

    cout << "1. " << n1 << endl;
    cout << "2. " << n2 << endl;
    cout << "3. " << n3 << endl;
    cout << "4. " << n4 << endl;
    cout << "5. " << n5 << endl;
    cout << "6. " << n6 << endl;
    cout << "7. " << n7 << endl;
    cout << "8. " << n8 << endl;
    cout << "9. " << n9 << endl;
    cout << "10. " << n10 << endl;

    int choice = 0;
    cout << "Which Patient do you want to make a call with: " << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        cout << "Calling Abdullah Nadeem" << endl;
        {

            //  cout << setw(45) << "....\n\n";
            cout << setw(4);

            for (int i = 0; i < 5; i++)
            {
                cout << "*";
            }
            cout << "\r";
            cout << setw(4);

            for (int i = 0; i < 6; i++)
            {
                cout << ".";

                Sleep(50);
            }
            cout << endl;
            cout << endl;
            cout << endl;
            // system("CLS");
            Sleep(1000);
        }
        srand(time(NULL));
        int r = rand() % 2;
        if (r == 1)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // white font
            cout << "Abdullah Nadeem accepted your call " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // red font
            cout << "Abdullah Nadeem declined your call " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font
        }
        break;
    }

    case 2:
    {
        cout << "Calling Inshal" << endl;

        {
            system("CLS");
            //  cout << setw(45) << "....\n\n";
            cout << setw(4);

            for (int i = 0; i < 5; i++)
            {
                cout << "*";
            }
            cout << "\r";
            cout << setw(4);

            for (int i = 0; i < 6; i++)
            {
                cout << ".";

                Sleep(50);
            }
            cout << endl;
            cout << endl;
            cout << endl;
            // system("CLS");
            Sleep(1000);
        }

        srand(time(NULL));
        int r = rand() % 2;
        if (r == 1)
        {

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // green font

            cout << "Inshal accepted your call " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // red font
            cout << "Inshal declined your call " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font
        }
        break;
    }

    case 3:
    {
        system("CLS");
        cout << "Calling Mueed" << endl;

        {

            //  cout << setw(45) << "....\n\n";
            cout << setw(4);

            for (int i = 0; i < 5; i++)
            {
                cout << "*";
            }
            cout << "\r";
            cout << setw(4);

            for (int i = 0; i < 6; i++)
            {
                cout << ".";

                Sleep(50);
            }
            cout << endl;
            cout << endl;
            cout << endl;
            // system("CLS");
            Sleep(1000);
        }

        srand(time(NULL));
        int r = rand() % 2;
        if (r == 1)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // green font
            cout << "Mueed accepted your call " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // red font
            cout << "Mueed declined your call " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font
        }
        break;
    }

    case 4:
    {
        system("CLS");
        cout << "Calling Khaqan" << endl;

        {

            //  cout << setw(45) << "....\n\n";
            cout << setw(4);

            for (int i = 0; i < 5; i++)
            {
                cout << "*";
            }
            cout << "\r";
            cout << setw(4);

            for (int i = 0; i < 6; i++)
            {
                cout << ".";

                Sleep(50);
            }
            cout << endl;
            cout << endl;
            cout << endl;
            // system("CLS");
            Sleep(1000);
        }

        srand(time(NULL));
        int r = rand() % 2;
        if (r == 1)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // green font
            cout << "Khaqan accepted your call " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // red font
            cout << "Khaqan declined your call " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font
        }

        break;
    }

    case 5:
    {
        system("CLS");
        cout << "Calling Musaab bhai" << endl;

        {

            //  cout << setw(45) << "....\n\n";
            cout << setw(4);

            for (int i = 0; i < 5; i++)
            {
                cout << "*";
            }
            cout << "\r";
            cout << setw(4);

            for (int i = 0; i < 6; i++)
            {
                cout << ".";

                Sleep(50);
            }
            cout << endl;
            cout << endl;
            cout << endl;
            // system("CLS");
            Sleep(1000);
        }

        srand(time(NULL));
        int r = rand() % 2;
        if (r == 1)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // green font
            cout << "Musaab bhai accepted your call " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // red font
            cout << "Musaab bhai declined your call " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font
        }
        break;
    }

    case 6:
    {
        system("CLS");
        cout << "Calling Ahmed mustafa mario" << endl;

        {

            //  cout << setw(45) << "....\n\n";
            cout << setw(4);

            for (int i = 0; i < 5; i++)
            {
                cout << "*";
            }
            cout << "\r";
            cout << setw(4);

            for (int i = 0; i < 6; i++)
            {
                cout << ".";

                Sleep(50);
            }
            cout << endl;
            cout << endl;
            cout << endl;
            // system("CLS");
            Sleep(1000);
        }

        srand(time(NULL));
        int r = rand() % 2;
        if (r == 1)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // green font
            cout << "mario accepted your call " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // red font
            cout << "mario declined your call " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font
        }
        break;
    }

    case 7:
    {
        system("CLS");
        cout << "Calling Ibtihaj" << endl;

        {

            //  cout << setw(45) << "....\n\n";
            cout << setw(4);

            for (int i = 0; i < 5; i++)
            {
                cout << "*";
            }
            cout << "\r";
            cout << setw(4);

            for (int i = 0; i < 6; i++)
            {
                cout << ".";

                Sleep(50);
            }
            cout << endl;
            cout << endl;
            cout << endl;
            // system("CLS");
            Sleep(1000);
        }

        srand(time(NULL));
        int r = rand() % 2;
        if (r == 1)
        {

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // green font
            cout << "Ibtihaj accepted your call " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // red font
            cout << "Ibtihaj declined your call " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font
        }
        break;
    }

    case 8:
    {
        system("CLS");
        cout << "Calling Usman" << endl;

        {

            //  cout << setw(45) << "....\n\n";
            cout << setw(4);

            for (int i = 0; i < 5; i++)
            {
                cout << "*";
            }
            cout << "\r";
            cout << setw(4);

            for (int i = 0; i < 6; i++)
            {
                cout << ".";

                Sleep(50);
            }
            cout << endl;
            cout << endl;
            cout << endl;
            // system("CLS");
            Sleep(1000);
        }

        srand(time(NULL));
        int r = rand() % 2;
        if (r == 1)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // green font
            cout << "Usman accepted your call " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font
        }

        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // red font
            cout << "Usman declined your call " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font
        }
        break;
    }
    case 9:
    {
        system("CLS");
        cout << "Calling Saad" << endl;

        {

            //  cout << setw(45) << "....\n\n";
            cout << setw(4);

            for (int i = 0; i < 5; i++)
            {
                cout << "*";
            }
            cout << "\r";
            cout << setw(4);

            for (int i = 0; i < 6; i++)
            {
                cout << ".";

                Sleep(50);
            }
            cout << endl;
            cout << endl;
            cout << endl;
            // system("CLS");
            Sleep(1000);
        }

        srand(time(NULL));
        int r = rand() % 2;
        if (r == 1)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // green font
            cout << "Saad accepted your call " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font
        }

        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // red font
            cout << "Saad declined your call " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font
        }
        break;
    }
    case 10:
    {
        system("CLS");
        cout << "Calling Abu baqar shareef" << endl;

        {

            //  cout << setw(45) << "....\n\n";
            cout << setw(4);

            for (int i = 0; i < 5; i++)
            {
                cout << "*";
            }
            cout << "\r";
            cout << setw(4);

            for (int i = 0; i < 5; i++)
            {
                cout << ".";

                Sleep(50);
            }
            cout << endl;
            cout << endl;
            cout << endl;
            // system("CLS");
            Sleep(1000);
        }

        srand(time(NULL));
        int r = rand() % 2;
        if (r == 1)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // green font
            cout << "Abu baqar accepted your call " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font
        }

        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // red font
            cout << "Abu baqar declined your call " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font
        }
        break;
    }
    default:
        break;
    }
}

//--------------------------------------------------------------------------------------
//                                  MAIN FUNCTION
//--------------------------------------------------------------------------------------
int main()
{
	//calling vitals to setup
	
	pulse p1;
	p1.storingpulse();
	heartbeat h1;
	h1.storing();
	oxygen x1;
	x1.storeoxygen();
	
    string choice;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // green font
    cout << setw(55) << "REMOTE HEALTH MONITORING SYSTEM" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font
    cout << "----------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Doctor or Patient" << endl;
    cin >> choice;

    //------------------------------------DOCTOR APP----------------------------------------------------------------

    if (choice == "DOCTOR" || choice == "Doctor" || choice == "doctor")
    {

        UserAccount user1;
        user1.input();
        int check;
        check = user1.login();
        if (check == 1)
        {

            int docretry = 1;
            char docoper;
            int docchoice;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // green font
            cout << "\t\t\tDoctor Mobile App " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // green font
            do
            {
                /* code */

                cout << "1. To make a call to patient" << endl;
               // cout << "2. View my own data" << endl;
                cout << "2. View all data of specific patient" << endl;
                cout << "3. Change data of specific patient" << endl;
                cout << "4. view patients list" << endl;
                
                cin >> docchoice;

                if (docchoice == 1)
                {
                    DoctorApp D1;
                    D1.makecall();
                    cout << "Do you want to perform anyother operator? (Y/N)" << endl;
                    cin >> docoper;
                    if (docoper == 'Y' || docoper == 'y')
                    {
                        docretry = 1;
                    }
                    else if (docoper == 'N' || docoper == 'n')
                    {
                        docretry = 0;
                    }
                    else
                    {
                        cout << "invalid input" << endl;
                        docretry = 0;
                    }
                }
                else if (docchoice == 3){
                    DoctorApp Ds;
                    int choice = 0;
                    choice = Ds.selection();
                   
                    
                        int vital = 0;
                        int index = 0 ;
                        cout<<"1.BP "<<endl;
                       
                        cout<<"2.Oxygen"<<endl;
                        cout<<"3.Pulse"<<endl;
                        cout<<"4.HeartBeat"<<endl;
                        cin>>vital;
                        srand(time(NULL));
                        int per =rand() % 2 ;
                        if(per == 0){
                            cout<<"you are authorized"<<endl;
                            cout<<"Day no. (1 - 90) "<<endl;
                            cin>>index;
                            switch(vital){

                                case 1 :
                                    {
                                        int hi = 0;
                                        int lo = 0;
                                        Bp b1;
                                       
                                        b1.showspecific(index);
                                        cout<<"Enter High :";
                                        cin>>hi;
                                        cout<<endl;
                                        cout<<"Enter Low :";
                                        cin>>lo;
                                        b1.changed(hi,lo,index);
                                        cout<<endl;
                                    }
                                    break;
                                case 2:
                                {
                                        int newval;
                                        oxygen o1;
                                        o1.showspecific(index);
                                        cout<<"Enter new value :";
                                        cin>>newval;
                                        cout<<endl;
                                        o1.changed(newval,index);
                                }
                                break;

                                case 3:
                                {
                                    pulse p1;
                                    int newval;
                                     p1.showspecific(index);
                                     cout<<"Enter new value :";
                                     cin>>newval;
                                     cout<<endl;
                                    p1.changed(newval,index);
                                }
                                break;

                                case 4:
                                {
                                    heartbeat h1;
                                    int newval;
                                    h1.showspecific(index);
                                    cout<<"Enter new value :";
                                    cin>>newval;
                                    cout<<endl;
                                    h1.changed(newval,index);
                                }
                            }
                        }
                        else{
                            cout<<"not authorized"<<endl;
                        }
                    
                }
                else if (docchoice == 4)
                {
                    DoctorApp D2;
                    D2.viewpatients();
                    cout<<endl;
                }

                else if (docchoice == 2)
                {
                    int stop = 1;
                    int choosen;
                    do
                    {
                        DoctorApp D3;

                        choosen = D3.selection();

                        if (choosen == 1)
                        {
                            int permission = 0;
                            char again;
                            cout << "Abdullah Nadeem's Data : " << endl;
                            cout << "authorizing.... " << endl;
                            permission = rand() % 2;
                            if (permission == 0)
                            {
                                cout << "You got authorization" << endl;
                                // Bp b1;
                                // b1.bloodpressure();
                                pulse p1;
                                p1.storingpulse();
                                heartbeat h1;
                                h1.storing();
                                oxygen o1;
                                o1.storeoxygen();

                                RMC2 r1;
                                r1.getbphigh();
                                r1.getbplow();
                                r1.getoxy();
                                r1.getpul();
                                r1.getheart();
                                r1.getbplow();

                                r1.storeinfile();
                                r1.fromfile();
                            }
                            else
                            {
                                cout << "You are not authorized to access this data" << endl;
                                cout << "Do you want to ask again? (Y/N)" << endl;
                                cin >> again;
                                if (again == 'N' || again == 'n')
                                {
                                    stop = 0;
                                }
                            }
                        }
                        else if (choosen == 2)
                        {
                            int permission = 0;
                            char again;
                            cout << "Inshal's Data" << endl;
                            cout << "authorizing.... " << endl;
                            permission = rand() % 2;
                            if (permission == 0)
                            {
                                cout << "You got authorization" << endl;
                                // Bp b1;
                                // b1.bloodpressure();
                                pulse p1;
                                p1.storingpulse();
                                heartbeat h1;
                                h1.storing();
                                oxygen o1;
                                o1.storeoxygen();

                                RMC2 r1;
                                r1.getbphigh();
                                r1.getbplow();
                                r1.getoxy();
                                r1.getpul();
                                r1.getheart();
                                r1.getbplow();

                                r1.storeinfile();
                                r1.fromfile();
                            }
                            else
                            {
                                cout << "You are not authorized to access this data" << endl;
                                cout << "Do you want to ask again? (Y/N)" << endl;
                                cin >> again;
                                if (again == 'N' || again == 'n')
                                {
                                    stop = 0;
                                }
                            }
                        }
                        else if (choosen == 3)
                        {
                            int permission = 0;
                            char again;
                            cout << "Mueed's Data" << endl;
                            cout << "authorizing.... " << endl;
                            permission = rand() % 2;
                            if (permission == 0)
                            {
                                cout << "You got authorization" << endl;
                                // Bp b1;
                                // b1.bloodpressure();
                                pulse p1;
                                p1.storingpulse();
                                heartbeat h1;
                                h1.storing();
                                oxygen o1;
                                o1.storeoxygen();

                                RMC2 r1;
                                r1.getbphigh();
                                r1.getbplow();
                                r1.getoxy();
                                r1.getpul();
                                r1.getheart();
                                r1.getbplow();

                                r1.storeinfile();
                                r1.fromfile();
                            }
                            else
                            {
                                cout << "You are not authorized to access this data" << endl;
                                cout << "Do you want to ask again? (Y/N)" << endl;
                                cin >> again;
                                if (again == 'N' || again == 'n')
                                {
                                    stop = 0;
                                }
                            }
                        }
                        else if (choosen == 4)
                        {
                            int permission = 0;
                            char again;
                            cout << "Khaqan's Data" << endl;
                            cout << "authorizing.... " << endl;
                            permission = rand() % 2;
                            if (permission == 0)
                            {
                                cout << "You got authorization" << endl;
                                // Bp b1;
                                // b1.bloodpressure();
                                pulse p1;
                                p1.storingpulse();
                                heartbeat h1;
                                h1.storing();
                                oxygen o1;
                                o1.storeoxygen();

                                RMC2 r1;
                                r1.getbphigh();
                                r1.getbplow();
                                r1.getoxy();
                                r1.getpul();
                                r1.getheart();
                                r1.getbplow();

                                r1.storeinfile();
                                r1.fromfile();
                            }
                            else
                            {
                                cout << "You are not authorized to access this data" << endl;
                                cout << "Do you want to ask again? (Y/N)" << endl;
                                cin >> again;
                                if (again == 'N' || again == 'n')
                                {
                                    stop = 0;
                                }
                            }
                        }
                        else if (choosen == 5)
                        {

                            int permission = 0;
                            char again;
                            cout << "Musaab bhai's Data" << endl;
                            cout << "authorizing.... " << endl;
                            permission = rand() % 2;
                            if (permission == 0)
                            {
                                cout << "You got authorization" << endl;
                                // Bp b1;
                                // b1.bloodpressure();
                                pulse p1;
                                p1.storingpulse();
                                heartbeat h1;
                                h1.storing();
                                oxygen o1;
                                o1.storeoxygen();

                                RMC2 r1;
                                r1.getbphigh();
                                r1.getbplow();
                                r1.getoxy();
                                r1.getpul();
                                r1.getheart();
                                r1.getbplow();

                                r1.storeinfile();
                                r1.fromfile();
                            }
                            else
                            {
                                cout << "You are not authorized to access this data" << endl;
                                cout << "Do you want to ask again? (Y/N)" << endl;
                                cin >> again;
                                if (again == 'N' || again == 'n')
                                {
                                    stop = 0;
                                }
                            }
                        }
                        else if (choosen == 6)
                        {
                            int permission = 0;
                            char again;
                            cout << "Ahmed mustafa mario's Data" << endl;
                            cout << "authorizing.... " << endl;
                            permission = rand() % 2;
                            if (permission == 0)
                            {
                                cout << "You got authorization" << endl;
                                // Bp b1;
                                // b1.bloodpressure();
                                pulse p1;
                                p1.storingpulse();
                                heartbeat h1;
                                h1.storing();
                                oxygen o1;
                                o1.storeoxygen();

                                RMC2 r1;
                                r1.getbphigh();
                                r1.getbplow();
                                r1.getoxy();
                                r1.getpul();
                                r1.getheart();
                                r1.getbplow();

                                r1.storeinfile();
                                r1.fromfile();
                            }
                            else
                            {
                                cout << "You are not authorized to access this data" << endl;
                                cout << "Do you want to ask again? (Y/N)" << endl;
                                cin >> again;
                                if (again == 'N' || again == 'n')
                                {
                                    stop = 0;
                                }
                            }
                        }
                        else if (choosen == 7)
                        {
                            int permission = 0;
                            char again;
                            cout << "Ibtihaj's Data" << endl;
                            cout << "authorizing.... " << endl;
                            permission = rand() % 2;
                            if (permission == 0)
                            {
                                cout << "You got authorization" << endl;
                                // Bp b1;
                                // b1.bloodpressure();
                                pulse p1;
                                p1.storingpulse();
                                heartbeat h1;
                                h1.storing();
                                oxygen o1;
                                o1.storeoxygen();

                                RMC2 r1;
                                r1.getbphigh();
                                r1.getbplow();
                                r1.getoxy();
                                r1.getpul();
                                r1.getheart();
                                r1.getbplow();

                                r1.storeinfile();
                                r1.fromfile();
                            }
                            else
                            {
                                cout << "You are not authorized to access this data" << endl;
                                cout << "Do you want to ask again? (Y/N)" << endl;
                                cin >> again;
                                if (again == 'N' || again == 'n')
                                {
                                    stop = 0;
                                }
                            }
                        }
                        else if (choosen == 8)
                        {
                            int permission = 0;
                            char again;
                            cout << "Usman's Data" << endl;
                            cout << "authorizing.... " << endl;
                            permission = rand() % 2;
                            if (permission == 0)
                            {
                                cout << "You got authorization" << endl;
                                // Bp b1;
                                // b1.bloodpressure();
                                pulse p1;
                                p1.storingpulse();
                                heartbeat h1;
                                h1.storing();
                                oxygen o1;
                                o1.storeoxygen();

                                RMC2 r1;
                                r1.getbphigh();
                                r1.getbplow();
                                r1.getoxy();
                                r1.getpul();
                                r1.getheart();
                                r1.getbplow();

                                r1.storeinfile();
                                r1.fromfile();
                            }
                            else
                            {
                                cout << "You are not authorized to access this data" << endl;
                                cout << "Do you want to ask again? (Y/N)" << endl;
                                cin >> again;
                                if (again == 'N' || again == 'n')
                                {
                                    stop = 0;
                                }
                            }
                        }
                        else if (choosen == 9)
                        {
                            int permission = 0;
                            char again;
                            cout << "Saad's Data" << endl;
                            cout << "authorizing.... " << endl;
                            permission = rand() % 2;
                            if (permission == 0)
                            {
                                cout << "You got authorization" << endl;
                                // Bp b1;
                                // b1.bloodpressure();
                                pulse p1;
                                p1.storingpulse();
                                heartbeat h1;
                                h1.storing();
                                oxygen o1;
                                o1.storeoxygen();

                                RMC2 r1;
                                r1.getbphigh();
                                r1.getbplow();
                                r1.getoxy();
                                r1.getpul();
                                r1.getheart();
                                r1.getbplow();

                                r1.storeinfile();
                                r1.fromfile();
                            }
                            else
                            {
                                cout << "You are not authorized to access this data" << endl;
                                cout << "Do you want to ask again? (Y/N)" << endl;
                                cin >> again;
                                if (again == 'N' || again == 'n')
                                {
                                    stop = 0;
                                }
                            }
                        }
                        else if (choosen == 10)
                        {

                            int permission = 0;
                            char again;
                            cout << "Abu baqar's Data" << endl;
                            cout << "authorizing.... " << endl;
                            permission = rand() % 2;
                            if (permission == 0)
                            {
                                cout << "You got authorization" << endl;
                                // Bp b1;
                                // b1.bloodpressure();
                                pulse p1;
                                p1.storingpulse();
                                heartbeat h1;
                                h1.storing();
                                oxygen o1;
                                o1.storeoxygen();

                                RMC2 r1;
                                r1.getbphigh();
                                r1.getbplow();
                                r1.getoxy();
                                r1.getpul();
                                r1.getheart();
                                r1.getbplow();

                                r1.storeinfile();
                                r1.fromfile();
                            }
                            else
                            {
                                cout << "You are not authorized to access this data" << endl;
                                cout << "Do you want to ask again? (Y/N)" << endl;
                                cin >> again;
                                if (again == 'N' || again == 'n')
                                {
                                    stop = 0;
                                }
                            }
                        }
                        else
                            cout << "invalid input" << endl;

                    } while (!stop == 0);
                }

            } while (!docretry == 0);
        }
        else
            cout << "Invalid input" << endl;
    }

    //------------------------------------PATIENT APP----------------------------------------------------------------
    else if (choice == "Patient" || choice == "PATIENT" || choice == "patient")
    {
        int check;

        UserAccount user1;
        user1.input();
        cout << "Now you have to login: " << endl;
        check = user1.login();
        if (check == 1)
        {
            user1.inputbasicinfo();
            int returnedchoice;
            int dowhileexit = 1;
            int retry = 1;
            do
            {
                appointmentDoctors doc;
                appointmentDoctors calldoc;
                returnedchoice = user1.mobileapp();

                switch (returnedchoice)
                {
                case 1:
                {

                    do
                    {
                        int c2;
                        cout << endl;

                        c2 = user1.choicemain();

                        switch (c2)
                        {

                        case 1:
                        {
                            Bp bpobject;
                            bpobject.bloodpressure();
                            break;
                        }
                        case 2:
                        {
                            bmi bmiobject;
                            bmiobject.input();
                            cout << endl;
                            bmiobject.showbmi();
                            break;
                        }
                        case 3:
                        {

                            pulse pulseobject;
                            pulseobject.storingpulse();
                            pulseobject.showpulse();

                            break;
                        }

                        case 4:
                        {
                            heartbeat heartbeatobject;
                            heartbeatobject.storing();
                            heartbeatobject.showbeat();

                            break;
                        }

                        case 5:
                        {
                            oxygen oxygenobject;
                            oxygenobject.storeoxygen();
                            cout << endl;
                            oxygenobject.showoxygen();
                            break;
                        }

                        case 6:
                        {
                            HandTremors H1;

                            H1.HandTremorDectector();
                            cout << endl;
                            break;
                        }

                        case 7:
                        {
                            Motiondectector M1; //
                            M1.Motiondec();
                            M1.FallDec();

                            break;
                        }
                        case 0:
                        {
                            cout << "Exiting...." << endl;

                            dowhileexit = 0;
                        }
                        break;

                        default:
                            if (c2 == 0)
                            {
                                cout << "Exiting..." << endl;
                                break;
                                dowhileexit = 0;
                            }
                            else
                            {

                                cout << "invalid input from the choice " << endl;
                                break;
                            }
                        }

                    } while (!dowhileexit == 0);

                    break;
                }

                case 2:
                {
                    int checkchoice;
                    cout << "1. BLOOD PRESSURE" << endl;
                    cout << "2. Pulse" << endl;
                    cout << "3. Heartbeat" << endl;
                    cout << "4. Oxygen" << endl;

                    cin >> checkchoice;
                    int num;
                    cout << "Enter number of the day you want to search for (1 to 90): ";
                    cin >> num;

                    switch (checkchoice)
                    {
                    case 1:
                    {
                        Bp bpobject;
                        cout << endl;
                        if (num <= 90 && num >= 1)
                        {
                            cout << "Day no.\tHigh\tLow" << endl;
                            bpobject.showspecific(num);
                        }
                        else
                            cout << "invalid day number" << endl;
                        break;
                    }
                    case 2:
                    {
                        pulse pulseobject;
                        if (num <= 90 && num >= 1)
                        {
                            cout << "Day no.\tPulse" << endl;
                            pulseobject.showspecific(num);
                        }
                        else
                            cout << "invalid day number" << endl;
                        break;
                    }
                    case 3:
                    {
                        heartbeat heartbeatobject;
                        if (num <= 90 && num >= 1)
                        {
                            cout << "Day no.\tHeartBeat" << endl;
                            heartbeatobject.showspecific(num);
                        }
                        else
                            cout << "invalid day number" << endl;
                        break;
                    }
                    case 4:
                    {
                        oxygen oxygenobject;
                        if (num <= 90 && num >= 1)
                        {
                            cout << "Day no.\tOxygen" << endl;
                            oxygenobject.showspecific(num);
                        }
                        else
                            cout << "invalid day number" << endl;
                        break;
                    }
                    default:
                        cout << "invalid input from the choice " << endl;
                        break;
                    }
                    break;
                }
                case 3:
                {
                    cout << "in case 3" << endl;

                    int doctorselection = 0;
                    appointmentDoctors doc;

                    doctorselection = doc.showdoc();
                    if (doctorselection == 1)
                    {
                        int ch;
                        do
                        {

                            ch = doc.doc1();

                            if (ch == 1)
                            {
                                cout << "Dr.Rizwanullah (Psychiatrists) have time to see you " << endl;
                            }
                            else
                            {
                                char yn;
                                cout << "Dr.Rizwanullah (Psychiatrists) is not free to see you " << endl;
                                cout << endl;
                                cout << "Do you want to said him again to manage time for you? (Y/N): ";
                                cin >> yn;

                                if (ch == 'y' || yn == 'Y')
                                {
                                    int che;
                                    che = doc.doc1();
                                }
                                else if (ch == 'n' || yn == 'N')
                                {
                                    cout << "Okay you can try again later" << endl;
                                }
                                else
                                    cout << "invalid input from the choice " << endl;
                            }
                        } while (!ch == 1);
                    }
                    else if (doctorselection == 2)
                    {
                        int ch;
                        do
                        {
                            // doc 2
                            ch = doc.doc2();

                            if (ch == 1)
                            {
                                cout << "Dr.Abdullah (Dermatologist) have time to see you " << endl;
                            }
                            else
                            {
                                char yn;
                                cout << "Dr.Abdullah (Dermatologist) is not free to see you " << endl;
                                cout << endl;
                                cout << "Do you want to said him again to manage time for you? (Y/N): ";
                                cin >> yn;

                                if (ch == 'y' || yn == 'Y')
                                {
                                    int che;
                                    che = doc.doc2();
                                }
                                else if (ch == 'n' || yn == 'N')
                                {
                                    cout << "Okay you can try again later" << endl;
                                }
                                else
                                    cout << "invalid input from the choice " << endl;
                            }
                        } while (!ch == 1);
                    }
                    else if (doctorselection == 3)
                    {
                        int ch;
                        do
                        {
                            // doc 3
                            ch = doc.doc3();

                            if (ch == 1)
                            {
                                cout << "Dr.Moiz (Surgeon) have time to see you " << endl;
                            }
                            else
                            {
                                char yn;
                                cout << "Dr.Moiz (Surgeon) is not free to see you " << endl;
                                cout << endl;
                                cout << "Do you want to said him again to manage time for you? (Y/N): ";
                                cin >> yn;

                                if (ch == 'y' || yn == 'Y')
                                {
                                    int che;
                                    che = doc.doc3();
                                }
                                else if (ch == 'n' || yn == 'N')
                                {
                                    cout << "Okay you can try again later" << endl;
                                }
                                else
                                    cout << "invalid input from the choice " << endl;
                            }
                        } while (!ch == 1);
                    }
                    else if (doctorselection == 4)
                    {
                        int ch;
                        do
                        {
                            // doctor 4
                            ch = doc.doc4();

                            if (ch == 1)
                            {
                                cout << "Dr.Idrees (Dentist) have time to see you " << endl;
                            }
                            else
                            {
                                char yn;
                                cout << "Dr.Idrees (Dentist)) is not free to see you " << endl;
                                cout << endl;
                                cout << "Do you want to said him again to manage time for you? (Y/N): ";
                                cin >> yn;

                                if (ch == 'y' || yn == 'Y')
                                {
                                    int che;
                                    che = doc.doc4();
                                }
                                else if (ch == 'n' || yn == 'N')
                                {
                                    cout << "Okay you can try again later" << endl;
                                }
                                else
                                    cout << "invalid input from the choice " << endl;
                            }
                        } while (!ch == 1);
                    }

                    else if (doctorselection == 5)
                    {
                        int ch;
                        do
                        {

                            ch = doc.doc5();

                            if (ch == 1)
                            {
                                cout << "Dr.Azan Afzal (Neurologist) have time to see you " << endl;
                            }
                            else
                            {
                                char yn;
                                cout << "Dr.Azan Afzal (Neurologist) is not free to see you " << endl;
                                cout << endl;
                                cout << "Do you want to said him again to manage time for you? (Y/N): ";
                                cin >> yn;

                                if (ch == 'y' || yn == 'Y')
                                {
                                    int che;
                                    che = doc.doc5();
                                }
                                else if (ch == 'n' || yn == 'N')
                                {
                                    cout << "Okay you can try again later" << endl;
                                }
                                else
                                    cout << "invalid input from the choice " << endl;
                            }
                        } while (!ch == 1);
                    }

                    else
                        cout << "Invalid selection" << endl;

                    // call for consultation function

                    break;
                }

                case 4:
                {

                    user1.showbasicinfo();

                    break;
                }

                case 5:
                {
                    int call;
                    appointmentDoctors calldoc;
                    cout << "Call the doctor  " << endl;
                    call = calldoc.showdoc();

                    if (call == 1)
                    {
                        int ch;
                        do
                        {

                            ch = calldoc.doc1();
                            cout << "Calling Dr.Rizwanullah (Psychiatrists) ... " << endl;
                            if (ch == 1)
                            {
                                cout << "Dr.Rizwanullah (Psychiatrists) Accepted your call " << endl;
                            }
                            else
                            {
                                char yn;
                                cout << "Dr.Rizwanullah (Psychiatrists) cannot accept your call rightnow " << endl;
                                cout << endl;
                                cout << "Do you want to said him again to manage time for you? (Y/N): ";
                                cin >> yn;

                                if (ch == 'y' || yn == 'Y')
                                {
                                    int che;
                                    che = calldoc.doc1();
                                }
                                else if (ch == 'n' || yn == 'N')
                                {
                                    cout << "Okay you can try again later" << endl;
                                }
                                else
                                    cout << "invalid input from the choice " << endl;
                            }
                        } while (!ch == 1);
                    }

                    if (call == 2)
                    {
                        int ch;
                        do
                        {
                            // doc 2
                            ch = calldoc.doc2();
                            cout << "Calling Dr.Abdullah(Dermatologist)... " << endl;
                            if (ch == 1)
                            {
                                cout << "Dr.Abdullah (Dermatologist) accepted your call " << endl;
                            }
                            else
                            {
                                char yn;
                                cout << "Dr.Abdullah (Dermatologist) cannot accept your rightnow " << endl;
                                cout << endl;
                                cout << "Do you want to said him again to manage time for you? (Y/N): ";
                                cin >> yn;

                                if (ch == 'y' || yn == 'Y')
                                {
                                    int che;
                                    che = calldoc.doc2();
                                }
                                else if (ch == 'n' || yn == 'N')
                                {
                                    cout << "Okay you can try again later" << endl;
                                }
                                else
                                    cout << "invalid input from the choice " << endl;
                            }
                        } while (!ch == 1);
                    }
                    if (call == 3)
                    {

                        int ch;
                        do
                        {
                            // doc 3
                            ch = calldoc.doc3();
                            cout << "Calling Dr.Moiz (Surgeon)..." << endl;
                            if (ch == 1)
                            {
                                cout << "Dr.Moiz (Surgeon) accepted your call " << endl;
                            }
                            else
                            {
                                char yn;
                                cout << "Dr.Moiz (Surgeon) cannot accept your rightnow  " << endl;
                                cout << endl;
                                cout << "Do you want to said him again to manage time for you? (Y/N): ";
                                cin >> yn;

                                if (ch == 'y' || yn == 'Y')
                                {
                                    int che;
                                    che = calldoc.doc3();
                                }
                                else if (ch == 'n' || yn == 'N')
                                {
                                    cout << "Okay you can try again later" << endl;
                                }
                                else
                                    cout << "invalid input from the choice " << endl;
                            }
                        } while (!ch == 1);
                    }
                    if (call == 4)
                    {
                        int ch;
                        do
                        {
                            // doctor 4

                            cout << "Calling Dr.Idrees (Dentist)..." << endl;
                            ch = calldoc.doc4();

                            if (ch == 1)
                            {
                                cout << "Dr.Idrees (Dentist) accepted your call " << endl;
                            }
                            else
                            {
                                char yn;
                                cout << "Dr.Idrees (Dentist)) cannot accept your call rightnow " << endl;
                                cout << endl;
                                cout << "Do you want to said him again to manage time for you? (Y/N): ";
                                cin >> yn;

                                if (ch == 'y' || yn == 'Y')
                                {
                                    int che;
                                    che = calldoc.doc4();
                                }
                                else if (ch == 'n' || yn == 'N')
                                {
                                    cout << "Okay you can try again later" << endl;
                                }
                                else
                                    cout << "invalid input from the choice " << endl;
                            }
                        } while (!ch == 1);
                    }
                    if (call == 5)
                    {
                        int ch;
                        do
                        {
                            // doctor 5

                            cout << "Calling Dr.Azan Afzal (Neurologist)..." << endl;
                            ch = calldoc.doc5();

                            if (ch == 1)
                            {
                                cout << "Dr.Azan Afzal (Neurologist) accepted your call " << endl;
                            }
                            else
                            {
                                char yn;
                                cout << "Dr.Azan Afzal (Neurologist) cannot accept your call rightnow " << endl;
                                cout << endl;
                                cout << "Do you want to said him again to manage time for you? (Y/N): ";
                                cin >> yn;

                                if (ch == 'y' || yn == 'Y')
                                {
                                    int che;
                                    che = calldoc.doc5();
                                }
                                else if (ch == 'n' || yn == 'N')
                                {
                                    cout << "Okay you can try again later" << endl;
                                }
                                else
                                    cout << "invalid input from the choice " << endl;
                            }
                        } while (!ch == 1);
                    }
                    break;
                }
                case 6:
                {
                    cout << "Send data to RMC" << endl;
                    RMC2 r1;
                    r1.getbphigh();
                    r1.getbplow();
                    r1.getheart();
                    r1.getpul();
                    r1.getoxy();

                    // r1.showvitals();
                    r1.storeinfile();
                    r1.fromfile();
                    // r1.showdata();

                    //
                }
                break;
                case 0:
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // green font
                    cout << "exiting ..." << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font
                    retry = 0;
                    break;
                }
                default:
                {
                    cout << "invalid input" << endl;

                    break;
                }
                }
            } while (!retry == 0);
        }
    }
    else
        cout << "Invalid input " << endl;

    // user1.login();

    // int c1;
    // c1 = user1.mobileapp();

    return 0;
}