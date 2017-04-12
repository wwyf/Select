#include "User.h"
#include <sstream>
#include <iomanip>
#include <algorithm>
using std::setw;

const int LENGTH_NAME = 10;
const int LENGTH_PASS = 20;



bool User::verify(const string & try_password) const
{ 
    return (try_password == m_password); 
}



Student::Student(const string& data){
    std::stringstream stream;
    stream << data;
    stream >> this->m_name;
    stream >> this->m_password;

    string lesson;
    while (stream >> lesson){
        this->selected_lesson.push_back(lesson);
    } 
}
 
 


const string Student::to_string() const 
{
    std::stringstream stream;
    string data;

    stream << setw(LENGTH_NAME) << this->m_name 
         << setw(LENGTH_PASS) << this->m_password;
    for (auto i : selected_lesson){
        stream << setw(LENGTH_NAME) << i;
    }

    getline(stream, data);
    return data;
}
 
const string Student::to_string_public() const 
{
    std::stringstream stream;
    string data;

    stream << setw(LENGTH_NAME) << this->m_name; 
    for (auto i : selected_lesson){
        stream << setw(LENGTH_NAME) << i;
    }

    getline(stream, data);
    return data;
}

bool Student::select_lesson(const string & lesson_name){
    auto finder = std::find(selected_lesson.begin(), selected_lesson.end(), lesson_name);
    if (finder == selected_lesson.end()){
        selected_lesson.push_back(lesson_name);
        return true;
    }
    else {
        return false;        
    }
}

bool Student::return_lesson(const string& lesson_name)
{
    auto finder = std::find(selected_lesson.begin(), selected_lesson.end(), lesson_name);
    if (finder != selected_lesson.end()){
        selected_lesson.erase(finder);
        return true;
    }
    else { 
        return false;        
    }
}



Teacher::Teacher(const string & data)
{
    std::stringstream stream;
    stream << data;
    stream >> this->m_name;
    stream >> this->m_password;
}


const string Teacher::to_string() const 
{ 
    std::stringstream stream;
    string data;
 
    stream << setw(LENGTH_NAME) << m_name 
         << setw(LENGTH_PASS) << m_password;

    getline(stream, data);
    return data;
}
