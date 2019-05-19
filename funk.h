#ifndef FUNK_H 
#define FUNK_H

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <chrono>

using std::cout;
using std::cin;
using std::left;
using std::setw;
using std::setfill;
using std::string;
using std::endl;
using std::sort;
using std::setprecision;
using std::fixed;
using std::vector;
using std::string;
using namespace std::chrono;

struct Student
{
    string name;
    string surname;
    vector<int> hw;
    int exam;
    double vid, med;
};

bool compare(Student&, Student&);
bool checkIfInt(string);
int generateRandom();
double vidCalc(vector<int>, int, int);
double medCalc(vector<int>, int, int);
void addData(vector<Student>&, int, bool);
void addDataFromFile(vector<Student>&, vector<Student>&, vector<Student>&, int&);
void print(vector<Student>&, vector<Student>&, vector<Student>&, int, bool);
bool checkIfFileExists();
void generateFile();

#endif 