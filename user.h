#include <string>
using std::string;

class User{
    string m_name; 
    string m_password;
public:
    User();
    User(string name, string passward)
        :m_name(name),m_password(passward) {} ;
    virtual void identity() = 0;
};


class Student : public User{
    // can only read lesson and can not modify 
public:
    Student();

    void print();
};

class Teacher : public User{
    // can read modify and add students

};

class Admin : public User {
    // can add teachers and students

};

class Guest : public User {
    // only can see the whole lesson list

};
