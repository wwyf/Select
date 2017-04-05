#include <map>

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::map;

struct Lesson{
    string m_major;
    string m_name;
    int m_number;
    int max_number;
    Lesson():
        m_major("none"),m_name("none"),m_number(0){};
    Lesson(const string& major,
            const string& name,
                int cur_num_stud = 0,
                    int max_num_stud = 0):
        m_major(major),
            m_name(name),
                m_number(cur_num_stud),
                    max_number(max_num_stud){};
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
        cout << m_major << " " << m_name << " " << m_number << endl;
    }
};


class Database{
    // the same name of two lesson is not allowed
    map<string, map<string, Lesson> > lesson_data;
public:
    bool upload(const string& userfile_name = "user",
                const string& lessonfile_name = "lesson");

    // bool add_major(const string& new_major);
    // bool add_lesson(const string& new_lesson);
    // bool find_major(const string& major_name) const;
    // bool find_major_lesson(const string& major_name,
    //                        const string& lesson_name) const;
    // bool find_lesson(const string& lesson_name) const;
    //void add_lesson_a_people();
};
