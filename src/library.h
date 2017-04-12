
#include <iostream>
#include <string>
#include "Database.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;

static Database data; 

void create_acount()
{
    cout << "Do you wang to create an acount to select lessons?[y/n] [default:y]" << endl;
    char flag;
    cin.get(flag);
    if (flag != '\n')
        while (cin.get() != '\n')
            continue;

    string user_name;
    string user_password;
    if (flag == '\n' || flag == 'Y' || flag == 'y')
    {
        cout << "please enter your username(maybe your id number)" << endl;
        cin >> user_name;
        while (data.find_username(user_name) != 0)
        {
            cout << "Your name has been signed up, please try again." << endl;
            cin >> user_name;
        }
        cout << "please enter your password." << endl;
        cin >> user_password;
        data.add_student(user_name, user_password);
        cout << "create an account successfully" << endl;
    }
}

void start()
{
    cout << "-------------------------------------------" << endl
         << "    Welcome to the course select system    " << endl
         << "                        Copyright by Walker" << endl
         << "-------------------------------------------" << endl;

    cout << endl;
    cout << "loading the database........" << endl;
    if (data.load())
        cout << "load the data successfully!" << endl;

    cout << "Do you have an account?[y/n] [default:y]";

    char flag;
    cin.get(flag);
    if (flag != '\n')
        while (cin.get() != '\n')
            continue;

    if (flag == 'Y' || flag == 'y' || flag == '\n')
        return ;
    else if (flag == 'N' || flag == 'n')
        create_acount();
}

void student_menu(const string &user_name)
{
    cout << "---------------------------------------" << endl
         << "      Welcome to the student client    " << endl
         << "      Your are  " << user_name << "    " << endl
         << "       s : select a course             " << endl
         << "       r : return a course             " << endl
         << "       w : watch your classes          " << endl
         << "       p : print a course              " << endl
         << "       a : print all course            " << endl
         << "       q : quit the client             " << endl
         << "---------------------------------------" << endl;
    cout << " Please enter your choice. " << endl;
    string choice;
    cin >> choice;
    while (choice[0] != 'q')
    {
        switch (choice[0])
        {
            case 's':
            {
                string lesson_name;
                cout << "Please write down the name of the course you want." << endl;
                cin >> lesson_name;
                if (data.lesson_add_stud(lesson_name, user_name))
                    cout << "Select this course successfully" << endl;
                else
                    cout << "Failed to select the course." << endl;
                break;
            }
            case 'r':
            {
                string lesson_name;
                cout << "Please write down the name of the course you want to return." << endl;
                cin >> lesson_name;
                if (data.lesson_delete_stud(lesson_name, user_name))
                    cout << "Return this course successfully" << endl;
                break;
            }
            case 'w':
            {
                data.print_student_public(user_name);
                break;
            }
            case 'p':
            {
                string lesson_name;
                cout << "Please write down the name of the course you want to see." << endl;
                cin >> lesson_name;
                if (data.find_lesson(lesson_name)){
                    data.print_lesson_public(lesson_name);
                    cout << "That's all" << endl;
                }
                else {
                    cout << "Can't find this course." <<  endl;
                    cout << "Please try again" << endl;
                }
                break;
            }
            case 'a':
            {
                data.print_lesson_public();
                cout << "That's all" << endl;
                break;
            }
            case 'x':
            {
                data.print_lesson();
                cout << "That's all" << endl;
                break;
            }
            default:
            {
                cout << "Your command is invalid. Pleash enter it again" << endl;
            }

        }
        cout << "Pleash continue to enter your choice" << endl;
        cin >> choice;
    }
}

void teacher_menu(const string & user_name)
{
    cout << "---------------------------------------" << endl
         << "      Welcome to the teacher client    " << endl
         << "      Your are  " << user_name << "        " << endl
         << "       w : watch  a course             " << endl
         << "       a : add    a course             " << endl
         << "       p : print all course            " << endl
         << "       q : quit the client             " << endl
         << "---------------------------------------" << endl;
    cout << " Please enter your choice. " << endl;
    string choice;
    cin >> choice;
    while (choice[0] != 'q')
    {
        switch (choice[0])
        {
             case 'w':
             {
                 string lesson_name;
                 cout << "Please write down the name of the course you want to watch." << endl;
                 cin >> lesson_name;
                 if (data.find_lesson(lesson_name)){
                     data.print_lesson(lesson_name);
                 }
                 cout << endl;
                 break;
             }
             case 'a':
             {
                 string lesson_name;
                 int max_num = 0;
                 cout << "Please write down the name of the course you want to add." << endl;
                 cin >> lesson_name;
                 cout << "And ths max number of students." << endl;
                 cin >> max_num;
                 if (data.find_lesson(lesson_name)){
                     cout << "This lesson has existed!" << endl;
                 }
                 else{
                     data.add_lesson(lesson_name, max_num);
                     cout << "You have add this lesson successfully" << endl;
                 }
                 break;
             }
             case 'p':
             {
                 data.print_lesson();
                 cout << "That's all" << endl;
                 break;
             }
             default:
             {
                 cout << "Your command is invalid. Please enter again" << endl;
             }
        }
            cout << "Pleash continue to enter your choice" << endl;
            cin >> choice;
    }

}


bool signup()
{
    cout << "Now you can enter your username and password to sign up this system" << endl;
    string user_name;
    string user_password;
    cout << "Please enter your username." << endl;
    cin >> user_name;
    cout << "Please enter your password." << endl;
    cin >> user_password;
    int flag = data.verify(user_name, user_password);
    for (int i = 0; i < 5 && flag == 0; i++)
    {
        cout << "Your username or password maybe wrong." << endl;
        cout << "Please enter your username." << endl;
        cin >> user_name;
        cout << "Please enter your password." << endl;
        cin >> user_password;
        flag = data.verify(user_name, user_password);
    }
    if (flag == 0)
    {
        cout << "Automatically quit!" << endl;
        return false;
    }
    else if (flag == 1)
    {
        student_menu(user_name);
        return true;
    }
    else if (flag == 2)
    {
        teacher_menu(user_name);
        return true;
    }
    return false;
}


void finished()
{
    cout << "saving........." << endl;
    data.save();
    cout << "save the data successfully" << endl;
}