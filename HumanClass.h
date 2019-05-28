#pragma once

#include <string>
using std::string;

class Human
{
protected:
    string name_, surname_;

    //konstruktoriai
    Human() : name_(""), surname_("") {}
    Human(const string& name) : name_(name), surname_("") {}
    Human(const string& name, const string& surname) : name_(name), surname_(surname) {}
};