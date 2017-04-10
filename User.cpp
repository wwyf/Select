#include "User.h"
#include <sstream>
#include <iomanip>

using std::setw;

const int LENGTH_NAME = 10;
const int LENGTH_PASS = 20;


//  
bool User::verify(const string & name, const string & password) const 
{
     
}


void User::print_lesson() const;



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

 
void Student::menu()
{


}

const string Student::to_string() const 
{
    std::stringstream data;
    string res;

    data << setw(LENGTH_NAME) << m_name 
         << setw(LENGTH_PASS) << m_password;
    for (auto i : selected_lesson){
        data << setw(LENGTH_NAME) << i;
    }

    data >> res;
    return res;
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
    std::stringstream data;
    string res;
 
    data << setw(LENGTH_NAME) << m_name 
         << setw(LENGTH_PASS) << m_password;

    data >> res;
    return res;
}
