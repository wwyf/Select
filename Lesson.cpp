#include "Lesson.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
using std::setw;


Lesson::Lesson(const string & data){
        stringstream res ;
        res << data;
        res >> m_name >> m_number >> max_number ;
        
        string  stud_name;
        while (res >> stud_name){
            stud_selected.push_back(stud_name);
        }
        res.clear();
    }



const string  Lesson::to_string() const
{
    std::stringstream stream; 
    std::string res;
    stream << setw(10) << this->m_name
           << setw(4)  << this->m_number
           << setw(4)  << this->max_number;
    for (auto i : stud_selected){
        stream << setw(10) << i;
    }
    getline(stream, res);
    return res;
}





bool Lesson::add_student(const string & stud_name)
{
        if (!is_full()){
            m_number++;
            stud_selected.push_back(stud_name);
            return true;
        }
        else
            return false;
}



bool Lesson::delete_student(const string & stud_name)
{
    auto finder = find(stud_selected.begin(),
                        stud_selected.end(),
                        stud_name);
    if (finder == stud_selected.end())
        return false;
    else{
        stud_selected.erase(finder);
        m_number--;
        return true;
    }
}