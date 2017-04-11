#include <fstream>
#include <iomanip>

#include "Database.h"

using std::setw;


bool Database::load(const string& studfile_name ,
                  const string& teachfile_name, 
                const string& lessonfile_name )
{
    std::ifstream stud_file(studfile_name.c_str());
    std::ifstream teach_file(teachfile_name.c_str());
    std::ifstream lesson_file(lessonfile_name.c_str());

    // student data
    if (!stud_file.is_open()){
        return false;
    }
    else {
        while (!stud_file.eof()){
            string data;
            getline(stud_file, data);
            if (data.size() == 0)
                break;
            Student temp = Student(data);
            student_data.insert({temp.get_name(), temp});
        }
        stud_file.clear();
    } 

    // teacher data
    if (!teach_file.is_open()){
        return false;
    }
    else {
        while (!teach_file.eof()){
            string data;
            getline(teach_file, data);
            if (data.size() == 0)
                break;
            Teacher temp = Teacher(data);
            teacher_data.insert({temp.get_name(), temp});
        }
        teach_file.clear();
    }

    // lesson Data
    if (!lesson_file.is_open()){
        return false;
    }
    else {
        while (!lesson_file.eof()){
            string data;
            getline(lesson_file, data);
            if (data.size() == 0)
                break;
            Lesson temp = Lesson(data);
            lesson_data.insert({temp.get_name(), temp});
        }
        lesson_file.clear();
    }
    return true;
}




bool Database::save(const string& studfile_name ,
                  const string& teachfile_name, 
                const string& lessonfile_name )
{
    std::ofstream stud_file(studfile_name.c_str());
    std::ofstream teach_file(teachfile_name.c_str());
    std::ofstream lesson_file(lessonfile_name.c_str());
    
    // student data
    for (const auto& i : student_data){
        stud_file << i.second.to_string() << endl;
    }
    stud_file.close();

    // teacher data
    for (const auto & i : teacher_data){
        teach_file << i.second.to_string() << endl;
    }
    teach_file.close();

    //lesson data
    for (const auto& i : lesson_data){
            lesson_file << i.second.to_string() << endl;
    }
    lesson_file.close();

    return true;
}


bool Database::find_lesson(const string & lesson_name) const
{
    if (lesson_data.find(lesson_name) == lesson_data.end()){
        return false;
    }
    else
        return true;
}

int Database::find_username(const string & user_name) const
{
    auto t1 = student_data.find(user_name);
    auto end1 = student_data.end();
    auto t2 = teacher_data.find(user_name);
    auto end2 = teacher_data.end();

    if (t1 == end1 && t2 == end2){
        return 0;
    }
    else if (t1 != end1){
        return 1;
    }
    else if (t2 != end2){
        return 2;
    }
    // 1 is student;
    // 2 is teacher;
    return 0;
}

    // add a user
bool Database::add_student(const string& stud_name, 
                       const string & stud_password)
{
    student_data.insert({stud_name, Student(stud_name, stud_password)});
    return true;
}
bool Database::add_teacher(const string & teach_name,
                        const string & teach_password)
{
    teacher_data.insert({teach_name, Teacher(teach_name, teach_password)});
    return true;
}

 bool Database::add_lesson(const string& lesson_name,
                 const int num, const int max_num)
 {
    lesson_data.insert({lesson_name, Lesson(lesson_name, num, max_num)});
    return true;
 }

    // select or diselect a lesson 
bool Database::lesson_add_stud(const string& lesson_name,
                            const string & stud_name)
{
    if (find_lesson(lesson_name)){
        if(lesson_data[lesson_name].add_student(stud_name))
            return true; 
    }
    return false;
}
bool Database::lesson_delete_stud(const string& lesson_name,
                                const string & stud_name)
{
    if (find_lesson(lesson_name))
        if(lesson_data[lesson_name].add_student(stud_name))
            return true; 
    return false;
}

