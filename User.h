#ifndef _USER_H_
#define _USER_H_

#include <string>
#include <vector>
#include <iostream>
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
    User():User("none", "none"){};
    const string get_name() const {return m_name;};
    bool verify(const string & try_password) const;
    virtual const string to_string(){ return "";};
    
    // virtual void menu() = 0 ;
    // void print_lesson() const;
};



class Student:public User{
    vector<string> selected_lesson;
public:
    Student(){};
    Student(const string& name,const string& password):
        User(name, password){};
    explicit Student(const string& data);
    // void menu(){};
    const string to_string() const;
    bool select_lesson(const string & lesson_name);
    bool return_lesson(const string & lesson_name);
};



class Teacher:public User{

public:
    Teacher(){};
    Teacher(const string& name, const string& password):
        User(name, password){};
    explicit Teacher(const string& data);
    const string to_string() const ;
    // void menu() {};
    // bool add_lesson();
    // bool delete_lesson();

    // void print_lesson_student();
};


#endif