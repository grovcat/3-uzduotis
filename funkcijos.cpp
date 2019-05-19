#include "funk.h"

bool compare(Student& x, Student& y)
{
    return x.vid < y.vid;
}

//Checks if the data file "kursiokai.txt" exists for a failsafe
bool checkIfFileExists()
{
    std::ifstream fd("kursiokai.txt");
    if(!fd)
    {
        return 0; //If the file does not exist, returns a false bool value
    }
    else
    {
        return 1; //If the file exists, returns a true bool value
    }
}

bool checkIfInt(string numb)
{
	for (int i = 0; i != numb.length(); i++)
	{
		if(!isdigit(numb[i]))
        {
            return 0;
        }
	}
	return 1;
}

//Basic function for generating a grade
int generateRandom()
{
    int random;
    return random = 9 * rand()/RAND_MAX + 1;
}

//Function responsible for generating the data file
void generateFile()
{
    std::ofstream fd("kursiokai.txt");

    int mokiniai;
    cout << "Kiek mokiniu reikia sugeneruoti?" << endl;
    cin >> mokiniai;
    while(mokiniai < 0) //Waits for the user to enter a valid value for the amount students
    {
        cout << "Iveskite teisinga reiksme!" << endl;
        cin >> mokiniai;
    }
    int n;
    cin >> n;
    cout << "Kiek pazymiu tures kiekvienas mokinys?" << endl;
    while(n < 0) // Waits for the user to enter a valid value for the amount of grades each student has
    {
        cout << "Iveskite teisinga reiksme!" << endl;
        cin >> n;
    }
    
    //Writes the first line of the data file
    fd << left << setw(15) << "Vardas" << left << setw(20) << "Pavarde";
    for(int i = 0; i != n; i++)
    {
        fd << "ND" << left << setw(3) << i+1;
    }
    fd << "Egzaminas" << endl;

    //Generates the student ID's and their grades
    for(int i = 0; i != mokiniai; i++)
    {
        fd  << "Vardas" << left << setw(9) << i+1 << "Pavarde" << left << setw(13) << i+1;
        for(int k = 0; k != n; k++)
        {
            fd << left << setw(5) << generateRandom();
        }
        fd << generateRandom() << endl;
    }
    fd.close();

    //Responds with the completed function
    cout << "Failas sugeneruotas" << endl;
}

//Counts the average value of a student
double vidCalc(vector<int> hw, int exam, int n)
{
    int temp = 0;
    for(int i = 0; i != n; i++)
    {
        temp += hw[i];
    }
    return 0.4 * (double)(temp / n) + 0.6 * exam;
}

//Counts the median value of a student
double medCalc(vector<int> hw, int exam, int n)
{
    sort(hw.begin(), hw.end());
    if(n % 2 == 1)
    {
        return 0.4 * (double)hw[n / 2] + 0.6 * exam;
    }
    else
    {
        return 0.4 * (double)((hw[n / 2 - 1] + hw[n / 2]) / 2) + 0.6 * exam;
    }
}

//Adds data from the user via console
void addData(vector<Student> &student, int n, bool ifRandom)
{
    student.push_back(Student());
    int k = student.size() - 1;
    cout << "Iveskite mokinio varda" << endl;
    cin >> student[k].name;
    cout << "Iveskite mokinio pavarde" << endl;
    cin >> student[k].surname;
    string temp;

    //Checks if RNG is used for creating marks
    if(ifRandom == true)
    {
        //Goes through every mark
        for(int i = 0; i != n; i++)
        {
            cout << "Generuojamas " << i+1 << " pazymys = ";
            temp = generateRandom();
            student[k].hw.push_back(std::stoi(temp));
            cout << temp << endl;
        }
        cout << "Generuojamas egzamino pazymys = ";
        student[k].exam = generateRandom();
        cout << student[k].exam << endl;
    }
    else
    {       
        //Goes through every mark
        for(int i = 0; i != n; i++)
        {
            cout << "Iveskite " << i+1 << " pazymi" << endl;
            cin >> temp;
            while(checkIfInt(temp) != 1 || std::stoi(temp) > 10 || std::stoi(temp) < 0)
            {
                if(std::stoi(temp) > 10 || std::stoi(temp) < 0)
                {
                    cout << "Iveskite reiksme didesne uz 0 arba mazesne uz 10!" << endl;
                    cin >> temp;
                }
                else
                {
                    cout << "Iveskite teisinga reiksme!" << endl;
                    cin >> temp;
                }
            }
            student[k].hw.push_back(std::stoi(temp));
        }
        cout << "Iveskite egzamino pazymi" << endl;
        cin >> temp;
        while(checkIfInt(temp) != 1 || std::stoi(temp) > 10 || std::stoi(temp) < 0)
        {
            if(std::stoi(temp) > 10 || std::stoi(temp) < 0)
            {
                cout << "Iveskite reiksme didesne uz 0 arba mazesne uz 10!" << endl;
                cin >> temp;
            }
            else
            {
                cout << "Iveskite teisinga reiksme!" << endl;
                cin >> temp;
            }
        }
        student[k].exam = std::stoi(temp);
    }
}

//Function responsible for adding data from a file into the memory (struct)
void addDataFromFile(vector<Student> &student, vector<Student> &good, vector<Student> &bad, int &n)
{
    std::ifstream fd("kursiokai.txt");
    
    //Checks if the data file exists, if not, throws an exeption
    if(!fd)
    {
        throw "Nera duomenu failo!";
    }
    
    //Takes the first line of the file to count how many marks are there based on the amount of characters the marks take up
    string temp;
    std::getline(fd, temp);
    n = (temp.size() - 44) / 5;

    int k = 0;
    int g = 0; 
    int b = 0;
    string tempMark;
    //Runs a loop until it checks if it reached the end of the file
    while(fd.peek() != EOF)
    {
        student.push_back(Student());
        good.push_back(Student());
        bad.push_back(Student());
        good.reserve(student.capacity());
        bad.reserve(student.capacity());
        fd >> student[k].name >> student[k].surname;
        for(int i = 0; i != n; i++)
        {
            fd >> tempMark;
            if(checkIfInt(tempMark) != 1)
            {
                throw "Bloga ivestis duomenu faile (ivesta neteisinga reiksme pazymiu lenteleje)";
            }
            student[k].hw.push_back(std::stoi(tempMark));
        }
        fd >> tempMark;
        if(checkIfInt(tempMark) != 1)
        {
            throw "Bloga ivestis duomenu faile (ivesta neteisinga reiksme egzaminu dalyje)";
        }
        student[k].exam = std::stoi(tempMark);
        student[k].vid = vidCalc(student[k].hw, student[k].exam, n);
        student[k].med = medCalc(student[k].hw, student[k].exam, n);
        if(student[k].vid < 5)
        {
            bad[b].name = student[k].name;
            bad[b].surname = student[k].surname;
            for(int i = 0; i != n; i++)
            {
                tempMark = student[k].hw[i];
                bad[b].hw.push_back(std::stoi(tempMark));
            }
            bad[b].vid = student[k].vid;
            bad[b].med = student[k].med;
            b++;
        }
        else
        {
            good[g].name = student[k].name;
            good[g].surname = student[k].surname;
            for(int i = 0; i != n; i++)
            {
                tempMark = student[k].hw[i];
                good[g].hw.push_back(std::stoi(tempMark));
            }
            good[g].vid = student[k].vid;
            good[g].med = student[k].med;
            g++;
        }
        //The variable k is used to put the students info on the next group inside the struct vector
        k++;
    }
    good.shrink_to_fit();
    bad.shrink_to_fit();
}

//Function responsible for printing out the result
void print(vector<Student> &student, vector<Student> &good, vector<Student> &bad, int n, bool ifFileUsed)
{
    
    //The variable k holds the info for the number of students in the memory
    int k = student.size(); 
    int g = good.size();
    int b = bad.size();
    //Checks if the used requested to use files for the program, if not console printing for the result is used
    if(ifFileUsed == false)
    {
        sort(student.begin(), student.end(), compare);
        cout << left << setw(15) << "Vardas" << left << setw(20) << "Pavarde" << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
        for(int i = 0; i != 72; i++)
        {
            cout << "-";
        }
        cout << endl;

        for(int i = 0; i != k; i++)
        {
            cout << left << setw(15) << student[i].name << left << setw(20) << student[i].surname;
            cout << left << setw(19) << fixed << setprecision(2) << student[i].vid;
            cout << left << setw(16) << fixed << setprecision(2) << student[i].med << endl;
        }
    }  
    else
    {
        sort(good.begin(), good.end(), compare);
        sort(bad.begin(), bad.end(), compare);
        
        //Creates 2 output files for 2 different groups of students
        std::ofstream resultGood("rezultatai-good.txt");
        std::ofstream resultBad("rezultatai-bad.txt");

        //Prints the first line
        resultGood << left << setw(15) << "Vardas" << left << setw(20) << "Pavarde" << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
        resultBad << left << setw(15) << "Vardas" << left << setw(20) << "Pavarde" << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
        
        //Prints the second line
        for(int i = 0; i != 72; i++)
        {
            resultGood << "-";
            resultBad << "-";
        }
        
        resultGood << endl;
        resultBad << endl;
        
        for(int i = 0; i != g; i++)
        {
            
            resultGood << left << setw(15) << good[i].name << left << setw(20) << good[i].surname;
            resultGood << left << setw(19) << fixed << setprecision(2) << good[i].vid;
            resultGood << left << setw(16) << fixed << setprecision(2) << good[i].med << endl;
        }    
        for(int i = 0; i != b; i++)
        {
            resultBad << left << setw(15) << bad[i].name << left << setw(20) << bad[i].surname;
            resultBad << left << setw(19) << fixed << setprecision(2) << bad[i].vid;
            resultBad << left << setw(16) << fixed << setprecision(2) << bad[i].med << endl;
        }
    }
    
    //Prints out the completed function text
    cout << "Rezultatas isspausdinas" << endl;
}
