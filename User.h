#include <string>
#include <vector>
#include <iostream>
#include "Lesson.h"
using std::string;
using std::vector;




/*
1. 用户登录，验证
2. 用户交互菜单
3. 封装用户对数据库的操作
*/ 
class User{
protected:
    string m_name; 
    string m_password;
public:
    User(const string& name,const string& passward)
        :m_name(name),m_password(passward) {} ;
    User():User("none", "node"){};
    const string get_name() const {return m_name;};

    bool verify(const string & name, const string & password) const;
    virtual void menu() = 0 ;
    virtual const string to_string() = 0;
    void print_lesson() const;
};



class Student:public User{
    vector<string> selected_lesson;
public:
    Student(const string& name,const string& password):
        User(name, password){};
    explicit Student(const string& data);
    void menu(){};
    const string to_string() const;
    bool select_lesson();
    bool return_lesson();
};



class Teacher:public User{

public:
    Teacher(const string& name, const string& password):
        User(name, password){};
    Teacher(const string& data);
    virtual void menu() {};
    virtual const string to_string() const ;
    bool add_lesson();
    bool delete_lesson();

    void print_lesson_student();
};
