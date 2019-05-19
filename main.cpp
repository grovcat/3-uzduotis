#include "funk.h"

int main()
{
    int n;
    vector<Student> student;
    vector<Student> good;
    vector<Student> bad;
    srand(time(NULL));

    //Time spent counting variable
    auto start = high_resolution_clock::now(); 

    //Asking if the data will be in a file or will it be entered via console
    bool ifFileUsed;
    cout << "Ar duomenys bus gaunami is failo ar vedami ranka?  Jei is failo, iveskite 1, jei ne - 0" << endl;
    cin >> ifFileUsed;
    while(ifFileUsed != 1 && ifFileUsed != 0)
    {
        cout << "Iveskite teisinga reiksme!" << endl;
        cin >> ifFileUsed;
    }
    cout << "Duomeyns gaunami is failo bus spausdinami faile rezultatai.txt" << endl;

    //Checks the users input on file usage and if a data file exists
    if(ifFileUsed == 1)
    {
        if(checkIfFileExists() == 0)
        {
            //Asks if the user wants to make a data file using RNG
            cout << "Neegzistuoja pradinis failas kursiokai.txt" << endl
                << "Ar generuoti duomenu faila?" << endl
                << "Jei taip, iveskite 1, jei ne - 0. Pasirenkant 0 programa stabdys veikla" << endl;
            bool temp;
            cin >> temp;
            while(temp != 1 && temp != 0)
            {
                cout << "Iveskite teisinga reiksme!" << endl;
                cin >> temp;
            }
            if(temp == 1)
            {
                generateFile();
            }
            else
            {
                return 0;
            }
        }
        //Adds data from the file while checking if the data file exists
        try
        {
            start = high_resolution_clock::now();
            addDataFromFile(student, good, bad, n);   
        }
        catch(const char* msg)
        {
            std::cerr << msg << endl;
            return 1;
        }
    }
    
    //Runs the program via console
    if(ifFileUsed == 0)
    {
        cout << "Iveskite kiek pazymiu tures kiekvienas mokinys" << endl;
        cin >> n;
        bool ifRandom;
        cout << "Ar ivesite pazymius patys, ar sugeneruoti juos? Jei taip, iveskite 1, jei ne - 0" << endl;
        cin >> ifRandom;
        while(ifRandom != 1 && ifRandom != 0)
        {
            cout << "Iveskite teisinga reiksme!" << endl;
            cin >> ifRandom;
        }
        int whichCycle = 0;
        bool cycle = 1;

        //Runs the cycle until the user says otherwise
        while(cycle != 0)
        {
            addData(student, n, ifRandom);
            student[whichCycle].vid = vidCalc(student[whichCycle].hw, student[whichCycle].exam, n);
            student[whichCycle].med = medCalc(student[whichCycle].hw, student[whichCycle].exam, n);
            cout << "Jeigu norite susdabdyti vedima, iveskite 0" << endl;
            cout << "Jeigu norite vesti daugiau duomenu, iveskite 1" << endl;
            cin >> cycle;
            while(cycle != 1 && cycle != 0)
            {
                cout << "Iveskite teisinga reiksme!" << endl;
                cin >> cycle;
            }
            whichCycle++;
        }
    }

    //Runs the print function
    print(student, good, bad, n, ifFileUsed); 

    //Counts how much time did the program run for 
    auto end = high_resolution_clock::now();
    cout << "Programos veikimo trukme " << duration_cast<milliseconds>(end-start).count() << " msec" << endl;

    return 0;
}