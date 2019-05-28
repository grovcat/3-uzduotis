#include "funk.h"
#include "StudentClass.h"

double Student::avgCalc()
{
    int n = 0;
    for(auto const& mark : hw_)
    {
        n += mark;
    }
    
    if(hw_.size() != 0)
    {
        double vid = 0.4*(double)((double)n / (double)hw_.size()) + 0.6*exam_;
		if (vid < 0 || vid > 10)
        {
            return 0;
        }
        return vid;
    }
    return 0;
}

double Student::medCalc()
{
    sort(hw_.begin(), hw_.end());
    if(hw_.size() % 2 == 1)
    {
        double med = 0.4*(double)hw_[hw_.size() / 2] + 0.6*exam_;
        if(med < 0 || med > 10)
        {
            return 0;
        }
        return med;
    }
    if(hw_.size() % 2 == 0)
    {
        if(hw_.size() != 0)
        {
            double med = 0.4 * (double)((hw_[hw_.size() / 2 - 1] + hw_[hw_.size() / 2]) / 2) + 0.6 * exam_;
            if(med < 0 || med > 10)
            {
                return 0;
            }
            return med;
        }
    }
}

Student::~Student()
{
    hw_.clear();
    name_.clear();
    surname_.clear();
}