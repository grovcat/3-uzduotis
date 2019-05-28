#pragma once

#include "funk.h"
#include "HumanClass.h"

class Student : protected Human
{

private:
    
    std::string name_;
    std::string surname_;
    double exam_;
    std::vector<double> hw_;
    double vid_;
    double med_;

public:
    //constructors
    Student() : Human{}, exam_(0), vid_(0), med_(0) {}
    Student(string name) : Human{name}, exam_(0), vid_(0), med_(0) {}
    Student(std::string name, std::string surname) : Human{name, surname}, exam_(0), vid_(0), med_(0) {}
    
    //get'ers
    inline std::string name() const { return name_; }    // get'eriai, inline
    inline std::string surname() const { return surname_; }  // get'eriai, inline
    inline double exam() const { return exam_; }
    inline std::vector<double> hw() const { return hw_; }
    inline double vid() const { return vid_; }
    inline double med() const { return med_; }

    //set'ers
    inline void setName(const std::string& name) { name_ = name; }	
	inline void setSurname(const std::string& surname) { surname_ = surname; }	
	inline void setExam(const int& exam) { exam_ = exam; }	
	inline void setHomework(const std::vector<double>& homework) { hw_ = homework; }	
	inline void setVid(const double& vid) { vid_ = vid; }	
	inline void setMed(const double& med) { med_ = med; }

    //funkcijos
    double avgCalc();
    double medCalc();

    //operatoriai
    inline friend bool operator==(const Student& a, const Student& b) { return a.name_ == b.name_ && a.surname_ == b.surname_ && a.vid_ == b.vid_ && a.med_ == b.med_ && a.hw_ == b.hw_; }
	inline friend bool operator!=(const Student& a, const Student& b) { return !(a == b); }
	inline friend bool operator>(const Student& a, const Student& b) { return a.vid_ > b.vid_; }
	inline friend bool operator<(const Student& a, const Student& b) { return a.vid_ < b.vid_;}
	inline friend bool operator>=(const Student& a, const Student& b) { return a.vid_ >= b.vid_; }
	inline friend bool operator<=(const Student& a, const Student& b) { return a.vid_ <= b.vid_; }

    //destructoriai
    ~Student();

};