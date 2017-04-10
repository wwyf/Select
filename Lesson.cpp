#include "Lesson.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

using std::setw;


Lesson::Lesson(const string & data){
        stringstream res ;
        res << data;
        res >> m_name >> m_number >> max_number ;
        
        string  stud_name;
        while (res >> stud_name){
            stud_selected.push_back(stud_name);
        }
    }



const string  Lesson::to_string() const
{
    std::stringstream stream; 
    std::string res;
    stream << setw(10) << this->m_name
           << setw(4)  << this->m_number
           << setw(4)  << this->max_number;
    getline(stream, res);
    return res;
}





