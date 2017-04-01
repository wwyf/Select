#include <string>
#include <vector>
#include "Lesson.h"
using std::string;
using std::vector;



class User{
    string m_name; 
    string m_password;
public:
    User();
    User(string name, string passward)
        :m_name(name),m_password(passward) {} ;
    virtual void my_identity() = 0;
};


class Student : public User{
    // can only read lesson and can not modify 
    string m_major;
    vector<Lesson> m_lesson;
public:
    Student(const string& major, 
            const string& name, 
            const string& password):
        m_major(major), User(name, password) {};
    void menu();

    void select();

    void deselect();

    void my_lesson() const;

    virtual void my_identity() const;

};

class Teacher : public User{
    // can read modify and add students
public:
    Teacher(const string& name, const string& password):
        User(name, password){};
    void menu();

    void add_lesson();

    

};

class Admin : public User {
    // can add teachers and students

};

class Guest : public User {
    // only can see the whole lesson list

};
