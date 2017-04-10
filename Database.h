#include <string>
#include <map>
#include <iostream>

#include "Lesson.h"
#include "User.h"


using std::string;
using std::map;
using std::cout;
using std::cin;

/*
数据库
存放课程
文件1：学生信息（权限）  用户名 密码 选课列表
文件2：老师信息（权限）  用户名 密码 
文件3：课堂名字 课程当前人数 课程最大人数 选课名单
*/

class Database{
    map<string, Student> student_data;
    map<string, Teacher> teacher_data;
    map<string, Lesson> lesson_data;

public:
    bool load(const string& studfile_name = "student",
               const string& teachfile_name = "teacher",
                const string& lessonfile_name = "lesson");
    bool save(const string& studfile_name = "student",
               const string& teachfile_name = "teacher",
                const string& lessonfile_name = "lesson");
    
    // void print() const;
 
    // if found ,return true;
    // if not found , false;
    // finder
    bool find_lesson(const string & lesson_name) const;
    int find_username(const string & user_name) const;

    // modifier

    // add a user
    bool add_student(const string& stud_name, 
                       const string & stud_password);
    bool add_teacher(const string & teach_name,
                        const string & teach_password);
    
    // select or diselect a lesson 
    bool lesson_add_stud(const string& lesson_name,
                            const string & stud_name);
    bool lesson_delete_stud(const string& lesson_name,
                                const string & stud_name);
    

    
};
