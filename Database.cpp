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
        string data;
        getline(stud_file, data); 

        Student temp = data; 
        student_data.insert({temp.get_name, temp});
    }

    // teacher data
    if (!teach_file.is_open()){
        return false;
    }
    else {
        string data;
        getline(teach_file, data); 

        Teacher temp = data; 
        teacher_data.insert({temp.get_name, temp});
    }

    // lesson Data
    if (!lesson_file.is_open()){
        return false;
    }
    else {
        string data;
        getline(lesson_file, data);

        Lesson temp = data;
        lesson_data.insert({temp.get_name, temp});
    }
    return true;

}

bool Database::save(const string& userfile_name,
                const string& lessonfile_name )
{
    std::ofstream stud_file(userfile_name.c_str());
    std::ofstream lesson_file(lessonfile_name.c_str());
    
    //lesson data
    for (const auto& i : lesson_data){
            lesson_file << i.second.to_string() << endl;
    }


    if (lesson_file)
        return true;
    else
        return false;
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
}



