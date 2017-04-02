//#include "User.h"
#include "Lesson.h"
#include <iostream>
#include <fstream>
#include <string>

bool Database::upload(const string & userfile_name,  const string& lessonfile_name){
    std::fstream user_file(userfile_name.c_str());
    std::fstream lesson_file(lessonfile_name.c_str());

    // user Data
    // if (!user.is_open()){
    //     cout << "User data is not exist or the file has been destoried " << endl;
    // }
    // else {
    //     string identity;
    //     string user_name;
    //     string user_password;
    //     while (user >> identity){
    //             user >> user_name;
    //             user >> user_password;
    //             user_data[user_name] = Admin(user_name, user_password);
    //         if (identity[0] == 'a'){


    //         }
    //         if (identity[0] == 't')

    //         if (identity[0] == 's')

    //     }
    // }

    // lesson Data
    if (!lesson_file.is_open()){
        cout << "Lesson data is not exist or the file has been destoried " << endl;
    }
    else {//
        string major_name;
        string lesson_name;
        int cur_num_stud;
        int max_num_stud;
        while (lesson_file >> major_name ){
            lesson_file >> lesson_name >> cur_num_stud >> max_num_stud ;
            lesson_data[major_name][lesson_name] = Lesson(major_name, lesson_name, cur_num_stud, max_num_stud);
        }
        lesson_file.clear();
    }
                        
}

void Database::print() const
{
    for (auto i : lesson_data){
        cout << (i.first()) << "'s' class " << endl;
        for (auto j :  i ){
            j.second().print();
        }
    }
}