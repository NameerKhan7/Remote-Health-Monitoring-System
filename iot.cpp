
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


// class iot
// {

// private:
//     int oxygen[90];    //
//     int heartbeat[90]; //= 40 + (rand() % 121); // between 40 and 160
//     int pulse[90];
//     int hibp[90];
//     int lobp[90];

// public:
//     void storinginfile();
//     void generatingoxygen();
//     void generatingheartbeat();
//     void generatingpulse();
//     void generatingbp();
//     void readingfromfile();
//     // void showbeat();
//     // void showspecific(int);
//     // void storeoxygen();
//     // void showoxygen();
//     // void showspecific(int);
// };

// void iot::storinginfile()
// {

//     ofstream ifile;
//     ifile.open("vitals.dat", ios::binary | ios::app);
//     ifile<<"High Bp"<<"\t"<<"Low Bp"<<"\t"<<"Pulse"<<"\t"<<"Oxygen"<<"\t"<<"Heartbeat"<<endl;

//     for (int i = 0; i < 90; i++)
//     {
//         ifile.write((char *)&hibp[i], sizeof(hibp[i]));
//         cout<<hibp[i]<<endl;
//         ifile << "\t";
//         ifile.write((char *)&lobp[i], sizeof(lobp[i]));
        
//         cout<<lobp[i]<<endl;
//         ifile << "\t";
//         ifile.write((char *)&pulse[i], sizeof(pulse[i]));
//         ifile << "\t";
//         ifile.write((char *)&oxygen[i], sizeof(oxygen[i]));
//         ifile << "\t";
//         ifile.write((char *)&heartbeat[i], sizeof(heartbeat[i]));
//         ifile << endl;
//     }

//     ifile.close();
// }

// void iot::generatingoxygen()
// {

//     for (int i = 0; i < 90; i++)
//     {
//         oxygen[i] = 90 + (rand() % 11); // keeping between 90 and 100
//     }
// }

// void iot::generatingheartbeat()
// {
//     for (int i = 0; i < 90; i++)
//     {
//         heartbeat[i] = 40 + (rand() % 121); // between 40 and 160
//     }
// }

// void iot::generatingpulse()
// {
//     for (int i = 0; i < 90; i++)
//     {
//         pulse[i] = 60 + (rand() % 41); // between 60 and 100
//     }
// }

// void iot::generatingbp()
// {

//     for (int i = 0; i < 90; i++)
//     {
//         hibp[i] = 90 + (rand() % 61); // between 90 and 150
//         lobp[i] = 60 + (rand() % 41); // between 60 and 100
//     }
// }



class Motiondectector{
    int motioncounter = 0;
    int fallcounter = 0;

    public :

    void Motiondec();
    void FallDec();
};

void Motiondectector::FallDec(){

    srand(time(NULL));
    int i = 0 ;

    i  = rand() % 2;
    if(i == 0){
        fallcounter++;
        cout<<"Falling Dectected = "<<fallcounter<<" times "<<endl;
    }
    else 
    cout<<"Falling = 0"<<endl;

}
void Motiondectector::Motiondec(){

srand(time(NULL));
        int r = rand() % 6;

        if(r == 0){
            motioncounter++;
            cout<<"\aMotion Detected = "<<motioncounter<<" times "<<endl;
        }

        else
        {
            cout<<"No Motion Detected"<<endl;
        }
}

class HandTremors
{
    double x;
    double y;
    double z;
    double r;
    int n;

public:
    void HandTremorDectector();
};

void HandTremors::HandTremorDectector()
{

    cout << "Enter the number of samples: ";
    cin >> n;

    r = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the values of x, y and z for sample " << i + 1 << ": ";
        cin >> x >> y >> z;
        r += pow(x, 2) + pow(y, 2) + pow(z, 2);
    }

    r = sqrt(r / n);

    if (r > 0.05)
    {
        cout << "\aHand tremors detected. .\n";
    }
    else
    {
        cout << "No hand tremors detected. Everything seems to be fine.\n";
    }
}

class oxygen
{

private:
    int oxygen[90]; //

public:
    int getoxygen(int index = 0 );
    void storeoxygen();
    void showoxygen();
    void changed(int = 0 ,int = 0);
    void showspecific(int);

};

int oxygen::getoxygen(int index){

 ifstream oxygen1;
    oxygen1.open("oxygen.dat", ios::binary);

    int oxy[90];
    for (int i = 0; i < 90; i++)
    {

        oxygen1.read((char *)&oxy[i], sizeof(oxy[i]));
        
    }
    //cout << i << ".\t" << oxy[i] << endl;
    oxygen1.close();
    return oxy[index];
}

void oxygen::changed(int a,int index){
    cout<<index<<".\t"<<a<<endl;
}
void oxygen::showspecific(int i ){
    ifstream oxygen1;
    oxygen1.open("oxygen.dat", ios::binary);

    int oxy[90];
    for (int i = 0; i < 90; i++)
    {

        oxygen1.read((char *)&oxy[i], sizeof(oxy[i]));
        
    }
    cout << i << ".\t" << oxy[i] << endl;
    oxygen1.close();
}
void oxygen::storeoxygen()
{

    ofstream ox;
    ox.open("oxygen.dat", ios::binary);
    for (int i = 0; i < 90; i++)
    {
        oxygen[i] = 90 + (rand() % 11); // keeping between 90 and 100
        ox.write((char *)&oxygen[i], sizeof(oxygen[i]));
    }

    ox.close();
}

void oxygen::showoxygen()
{
    ifstream oxygen1;
    oxygen1.open("oxygen.dat", ios::binary);

    int oxy[90];
    for (int i = 0; i < 90; i++)
    {

        oxygen1.read((char *)&oxy[i], sizeof(oxy[i]));
        cout << i + 1 << ".\t" << oxy[i] << endl;
    }
    oxygen1.close();
}
class heartbeat
{

    int heartbeat[90]; //= 40 + (rand() % 121); // between 40 and 160

public:
    int getheartbeat(int index = 0 );
    void storing();
    void showbeat();
    void showspecific(int);
    void changed(int = 0,int = 0);
};

void heartbeat::changed(int a,int index){
    cout<<index<<".\t"<<a<<endl;
}
int heartbeat::getheartbeat(int index){

     ifstream beat;
    int a[90];
    beat.open("heartbeat.dat", ios::binary);
    for (int i = 0; i < 90; i++)
    {
        beat.read((char *)&a[i], sizeof(a[i]));
       
    }
    beat.close();

    return a[index];
}
void heartbeat::showspecific(int i ){
    ifstream beat;
    int a[90];
    beat.open("heartbeat.dat", ios::binary);
    for (int i = 0; i < 90; i++)
    {
        beat.read((char *)&a[i], sizeof(a[i]));
       
    }

     cout << i << "\t" << a[i] << endl;
    beat.close();
}
void heartbeat::showbeat()
{
    ifstream beat;
    int a[90];
    beat.open("heartbeat.dat", ios::binary);
    for (int i = 0; i < 90; i++)
    {
        beat.read((char *)&a[i], sizeof(a[i]));
        cout << i + 1 << "\t" << a[i] << endl;
    }
    beat.close();
};
void heartbeat::storing()
{

    ofstream htfile;
    htfile.open("heartbeat.dat", std::ios::binary);

    for (int i = 0; i < 90; i++)
    {
        heartbeat[i] = 40 + ((rand() % 121));
        htfile.write((char *)&heartbeat[i], sizeof(heartbeat[i]));
    }
    htfile.close();
}

class pulse
{

    int pulse[90];

public:
    int getpulse(int index = 0 );
    void showpulse();
    void storingpulse();
    void showspecific(int);
    void changed(int = 0 ,int = 0 );
};

void pulse::changed(int a,int index){

    cout<<index<<".\t"<<a<<endl;
}

int pulse::getpulse(int index){

    ifstream pulse;
    int a[90];
    pulse.open("pulse.dat", ios::binary);
    for (int i = 0; i < 90; i++)
    {
        pulse.read((char *)&a[i], sizeof(a[i]));
    }
    
       pulse.close();
    return a[index];
    
}

void pulse::showspecific(int i){
    ifstream pulse;
    int a[90];
    pulse.open("pulse.dat", ios::binary);

 
    for (int i = 0; i < 90; i++)
    {
        pulse.read((char *)&a[i], sizeof(a[i]));
     
    }
    //showing specific
       cout << i << "\t" << a[i] << endl;
       pulse.close();
}
void pulse::storingpulse()
{

    ofstream p;
    p.open("pulse.dat", ios::binary);

    for (int i = 0; i < 90; i++)
    {
        pulse[i] = 60 + (rand() % 41); // between 60 and 100
        p.write((char *)&pulse[i], sizeof(pulse[i]));
    }
    p.close();
}

void pulse::showpulse()
{
    ifstream pulse;
    int a[90];
    pulse.open("pulse.dat", ios::binary);

  
    for (int i = 0; i < 90; i++)
    {
        pulse.read((char *)&a[i], sizeof(a[i]));
        cout << i + 1 << "\t" << a[i] << endl;
    }
    pulse.close();
}

class bmi
{

private:
    float calbmi;
    float height, weight;

public:
    void input();
    void showbmi();
};

void bmi::showbmi()
{
    ifstream bmi1;
    bmi1.open("bmi.dat", ios::binary);
    float bmifile;
    bmi1.read((char *)&bmifile, sizeof(bmifile));
    if (bmifile < 18.5)
    {
        cout << "Your bmi is : " << bmifile << " and is  underweigth" << endl;
    }

    else if (bmifile < 25)
    {
        cout << "Your bmi is : " << bmifile << " and which is normal " << endl;
    }

    else if (bmifile < 30)
    {
        cout << "Your bmi is : " << bmifile << " and which is overweight " << endl;
    }

    else
    {
        cout << "Your bmi is : " << bmifile << " and is obese " << endl;
    }

    bmi1.close();
}

void bmi::input()
{
    cout << "Enter the weight for bmi: " << endl;
    cin >> weight;
    cout << "Enter the heigth in cm for bmi (180cm = 5.9ft ): " << endl;
    cin >> height;

    height = height / 100.0;

    float bmi1;
    bmi1 = weight / (height * height);

    ofstream bmiobj;
    bmiobj.open("bmi.dat", ios::binary);
    bmiobj.write((char *)&bmi1, sizeof(bmi1));

    calbmi = bmi1;
    bmiobj.close();
}
class Bp
{

private:
    int hibp[90]; // 90 + (rand() % 61); // between 90 and 150
    int lobp[90]; // 60 + (rand() % 41); // between 60 and 100

public:
    
    int gethibp(int index = 0 );
    int getlobp(int index = 0 );
    void bloodpressure();
    void changed(int = 0, int = 0,int = 0);
    void showspecific(int );
};
int Bp::getlobp(int index){
    int lo[90];
    ifstream bpfilelo;
    bpfilelo.open("Bplo.dat", ios::binary);
    for (int i = 0; i < 90; i++)
    {
        bpfilelo.read((char *)&lo[i], sizeof(lo[i]));
    }

    bpfilelo.close();
   
    return lo[index];
}


int Bp::gethibp(int index){
   
    ifstream bpfilehi;
    bpfilehi.open("Bphi.dat", ios::binary);
    int hi[90];
   

    for (int i = 0; i < 90; i++)
    {
        bpfilehi.read((char *)&hi[i], sizeof(hi[i]));
    }

    bpfilehi.close();


    return hi[index];
}

void Bp::changed(int a, int b, int index)
{
 ifstream bpfilehi;
    bpfilehi.open("Bphi.dat", ios::binary);
    int hi[90];
    int lo[90];

    for (int i = 0; i < 90; i++)
    {
        bpfilehi.read((char *)&hi[i], sizeof(hi[i]));
    }

    bpfilehi.close();

    ifstream bpfilelo;
    bpfilelo.open("Bplo.dat", ios::binary);
    for (int i = 0; i < 90; i++)
    {
        bpfilelo.read((char *)&lo[i], sizeof(lo[i]));
    }

    bpfilelo.close();

    //showing specific blood pressure according to i
    hi[index] =a;
    lo[index] =b;
    cout << index<< "."<< "\t" << hi[index] << "\t" << lo[index] << endl;


}

void Bp::showspecific(int i)
{
     ifstream bpfilehi;
    bpfilehi.open("Bphi.dat", ios::binary);
    int hi[90];
    int lo[90];

    for (int i = 0; i < 90; i++)
    {
        bpfilehi.read((char *)&hi[i], sizeof(hi[i]));
    }

    bpfilehi.close();

    ifstream bpfilelo;
    bpfilelo.open("Bplo.dat", ios::binary);
    for (int i = 0; i < 90; i++)
    {
        bpfilelo.read((char *)&lo[i], sizeof(lo[i]));
    }

    bpfilelo.close();

    //showing specific blood pressure according to i

    cout << i<< "."<< "\t" << hi[i] << "\t" << lo[i] << endl;

}
void Bp::bloodpressure()
{
    ofstream ofilebphi;
    ofilebphi.open("Bphi.dat", ios::binary);
    //  ofilebp<<"Blood Pressure"<<endl;
    // ofilebp<<"High"<<"\t"<<"Low"<<endl;

    for (int i = 0; i < 90; i++)
    {
        hibp[i] = 90 + (rand() % 61); // between 90 and 150
        ofilebphi.write((char *)&hibp[i], sizeof(hibp[i]));
    }

    ofilebphi.close();
    ofstream ofilebplo;
    ofilebplo.open("Bplo.dat", ios::binary);

    for (int i = 0; i < 90; i++)
    {
        lobp[i] = 60 + (rand() % 41); // between 60 and 100
        ofilebplo.write((char *)&lobp[i], sizeof(lobp[i]));
    }

    ofilebplo.close();
    cout << "Index\tHIGH"
         << "\t"
         << "LOW" << endl;
    cout << endl;

    ifstream bpfilehi;
    bpfilehi.open("Bphi.dat", ios::binary);
    int hi[90];
    int lo[90];

    for (int i = 0; i < 90; i++)
    {
        bpfilehi.read((char *)&hi[i], sizeof(hi[i]));
    }

    bpfilehi.close();

    ifstream bpfilelo;
    bpfilelo.open("Bplo.dat", ios::binary);
    for (int i = 0; i < 90; i++)
    {
        bpfilelo.read((char *)&lo[i], sizeof(lo[i]));
    }

    bpfilelo.close();

    // showing output

    for (int i = 0; i < 90; i++)
    {

        cout << i + 1 << "."
             << "\t" << hi[i] << "\t" << lo[i] << endl;
    }
}

// int main()
// {
    
//     return 0;
// }