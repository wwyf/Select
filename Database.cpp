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

/*
if the username has been existed, return 1 (student) or 2 (reacher)
if the username don't existed, return 0 ;
*/
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
                      const int max_num)
 {
    lesson_data.insert({lesson_name, Lesson(lesson_name, max_num)});
    return true;
 }

    // select or diselect a lesson 
    // the stud_name should be verified
bool Database::lesson_add_stud(const string& lesson_name,
                            const string & stud_name)
{
    if (find_lesson(lesson_name)){
        if(lesson_data[lesson_name].add_student(stud_name)){
            student_data[stud_name].select_lesson(lesson_name);
            return true;
        }
        else
        {
            cout << "You has selected this course or the lesson is full." << endl;
        }
    }
    else
    {
        cout << "This lesson is not existed." << endl;
    }
    return false;
}

bool Database::lesson_delete_stud(const string& lesson_name,
                                const string & stud_name)
{
    if (find_lesson(lesson_name)){
        if(lesson_data[lesson_name].delete_student(stud_name))
        {
            student_data[stud_name].return_lesson(lesson_name);
            return true; 
        }
        else
        {
            cout << "You has not selected this course." << endl;
        }
    }
    else
    {
        cout << "This lesson is not existed." << endl;
    }
    return false;
}


void Database::print_student() const
{
    for (auto i : student_data){
        cout << i.second.to_string() << endl;
    }
}

void Database::print_student_public(const string & user_name) const
{
    cout << "-----------------------------------------------" << endl;
    cout << "name    " << "courses" << endl;
    cout << student_data.find(user_name)->second.to_string_public() << endl; 
    cout << "-----------------------------------------------" << endl;   
}
 
void Database::print_teacher() const
{
    for (auto i : teacher_data){
        cout << i.second.to_string() << endl;
    }
}

void Database::print_lesson() const
{
    cout << "-----------------------------------------------" << endl;
    cout << Lesson::lesson_head_string() << endl;
    for (auto i : lesson_data){
        cout << i.second.to_string() << endl;
    } 
    cout << "-----------------------------------------------" << endl;
}
 

void Database::print_lesson(const string & lesson_name) const
{
    cout << "-----------------------------------------------" << endl;
    cout << Lesson::lesson_head_string() << endl;
    cout << lesson_data.find(lesson_name)->second.to_string() << endl;
    cout << "-----------------------------------------------" << endl;
}

void Database::print_lesson_public(const string & lesson_name) const
{
    cout << "-----------------------------------------------" << endl;
    cout << Lesson::lesson_head_string() << endl;
    cout << lesson_data.find(lesson_name)->second.to_string_public() << endl;
    cout << "-----------------------------------------------" << endl;
}

void Database::print_lesson_public() const
{
    cout << "-----------------------------------------------" << endl;
    cout << Lesson::lesson_head_string() << endl;
    for (auto i : lesson_data)
    {
        cout << i.second.to_string_public() << endl;
    }
    cout << "-----------------------------------------------" << endl;
}  

int Database::verify(const string & user_name, const string & try_password) const
{
    int flag = find_username(user_name);
    if (flag == 0)
        return 0; 
    if (flag == 1)
        if (student_data.find(user_name)->second.verify(try_password))
            return 1;
    if (flag == 2)
        if (teacher_data.find(user_name)->second.verify(try_password))
            return 2;
    return 0;
} 
