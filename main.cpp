#include <iostream>
#include "library.cpp"
int main(){

    start();// load the database // create an account
    if (signup())
        finished();
    else 
        cout << "You can't enter this system!\nPlease reopen this system to try again" << endl;
    return 0;
}



    // d.load();
    // d.save("./data/student2","./data/teacher2", "./data/lesson2");


    // d.print_student();
    // d.print_teacher();
    // d.print_lesson();

    // cout << endl;

    // d.add_student("name1", "password");
    // d.add_student("name2", "********");
    // d.add_student("name3", "password");

    // d.print_student();
    // d.print_teacher();
    // d.print_lesson();
    // cout << endl;

    // d.lesson_add_stud("python", "name1");
    // d.lesson_add_stud("C++", "name1");
    // d.lesson_add_stud("C++","name2");

    // d.print_student();
    // d.print_teacher();
    // d.print_lesson();
    // cout << endl;
    
    // d.add_lesson("perl", 44); 
    // d.lesson_add_stud("perl", "name2");

    // d.print_student();
    // d.print_teacher();
    // d.print_lesson();
    // cout << endl;

    // d.lesson_delete_stud("python", "name1");
    // d.lesson_add_stud("mysql","name1");

    // d.print_student();
    // d.print_teacher();
    // d.print_lesson();
    // cout << endl;


    // d.add_teacher("teachname", "password");
    // d.add_teacher("teach2", "******");

    // d.print_teacher();
    // cout << endl;

    // d.print_lesson_public();
    // cout << endl;
    // d.print_lesson_public("C++");


