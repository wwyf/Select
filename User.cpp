#include "User.h"
#include <sstream>
#include <iomanip>

using std::setw;

const int LENGTH_NAME = 10;
const int LENGTH_PASS = 20;


// //  
// bool User::verify(const string & name, const string & password) const 
// {
     
// }

 
// void User::print_lesson() const;



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
