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
1. 存储课程名字
    课程人数
    课程最大人数
    课程名单
实现功能：
1. 
*/

struct Lesson{
    string m_name;
    int m_number;
    int max_number;
    vector<string> stud_selected;
    

    Lesson(const string& name,
                int cur_num_stud = 0,
                    int max_num_stud = 0): 
            m_name(name),
                m_number(cur_num_stud),
                    max_number(max_num_stud){};
    Lesson():
        Lesson("none", 0, 0) {};
    
    Lesson(const string & data);

    inline bool add_student(){
        if (!is_full()){
            m_number++;
            return true;
        }
        else
            return false;
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
};

