#pragma once

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
#include "StudentClass.h"

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

bool compare(const Student&, const Student&);
bool comparePagalPavarde(const Student&, const Student&);
bool comparePagalEgza(const Student&, const Student&);
bool checkIfFileExists();
bool checkIfInt(string);

int generateRandom();

double vidCalc(vector<int>, int, int);
double medCalc(vector<int>, int, int);

void addData(vector<Student>&, int, bool);
void addDataFromFile(vector<Student>&, vector<Student>&, vector<Student>&, int&);
void print(vector<Student>&, vector<Student>&, vector<Student>&, int, bool);
void generateFile(vector<Student>&);

#endif 