#include "Lesson.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
using std::setw;

const int LENGTH_NAME = 10;
const int LENGTH_NUMBER = 5;

string Lesson::lesson_head_string() 
{
    std::stringstream stream;
    std::string head;
    stream << setw(LENGTH_NAME) <<  "lesson name" 
           << setw(LENGTH_NUMBER) << "max"
           << setw(LENGTH_NUMBER) << "now";
    getline(stream, head);
    return head;
}

Lesson::Lesson(const string & data){
        stringstream res ;
        res << data;
        res >> m_name >> max_number >> m_number ;


        string  stud_name;
        while (res >> stud_name){
            stud_selected.push_back(stud_name);
        }
        res.clear();
    }



const string  Lesson::to_string() const
{
    std::stringstream stream; 
    std::string data;
    stream << setw(LENGTH_NAME) << this->m_name
           << setw(LENGTH_NUMBER)  << this->max_number
           << setw(LENGTH_NUMBER)  << this->m_number;
    for (auto i : stud_selected){
        stream << setw(LENGTH_NAME) << i;
    }
    getline(stream, data);
    return data;
}


const string Lesson::to_string_public() const
{
    std::stringstream stream; 
    std::string data;
    stream << setw(LENGTH_NAME) << this->m_name
           << setw(LENGTH_NUMBER)  << this->max_number
           << setw(LENGTH_NUMBER)  << this->m_number;
    getline(stream, data);
    return data;
}


bool Lesson::add_student(const string & stud_name)
{
    auto finder = find(stud_selected.begin(),
                        stud_selected.end(),
                        stud_name);
    if (finder != stud_selected.end() || this->is_full())
        return false;
    else{
        stud_selected.push_back(stud_name);
        m_number++;
        return true;
    }
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