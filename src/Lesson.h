#ifndef _LESSON_H_
#define _LESSON_H_

#include <map>
#include <vector>
#include <iostream>
#include <sstream>
using std::stringstream;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::map;
using std::vector;




/*
 存储课程名字
    课程人数
    课程最大人数
    课程名单
*/
class Lesson{

    static string lesson_head_string();

    string m_name;
    int max_number;
    int m_number;
    vector<string> stud_selected;
public:

    Lesson(const string& name,
                    int max_num_stud,
                        int cur_num = 0):// ambiguous conversion 
            m_name(name),
                    max_number(max_num_stud),
                        m_number(cur_num){};
    Lesson():
        Lesson("none", 0) {};
    
    Lesson(const string & data);

    bool add_student(const string & stud_name);

    bool delete_student(const string & stud_name);

    inline const string get_name() const{
        return m_name;
    }
    inline bool is_empty() const{
        return !m_number;
    }
    inline bool is_full() const{
        return (m_number == max_number);
    }
    inline void print() const{
        cout << this->to_string() << endl;
    }
    const string to_string() const;
    const string to_string_public() const;
};

#endif
