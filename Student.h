#include <iostream>
#include <vector>
#include <ostream>
#include <string>
#include <algorithm>
#include <fstream>

class Student{
private:
    std::string name;
    std::string surname;
    std::string address;
    std::string idx_nr;
    std::string id;
    std::string sex;
public:
    Student(const std::string& name, const std::string& surname, const std::string& address, const std::string& idx_nr,
            const std::string& id, const std::string& sex)
    : name(name), surname(surname), address(address), idx_nr(idx_nr), id(id), sex(sex) {}

    Student() = default;
    ~Student() = default;
    void info() const;
    friend std::ostream& operator<<(std::ostream& out, const Student& student);
    friend std::istream& operator>>(std::istream& in, Student& student);
    static void show_data_base(const std::vector<Student>& vec);
    static Student search_by_surname(const std::vector<Student>& vec);
    static Student search_by_id(const std::vector<Student>& vec);
    static void sort_by_id(std::vector<Student>& vec);
    static void sort_by_surname(std::vector<Student>& vec);
    static void deleted_by_idx_nr(std::vector<Student>& vec);
    void correct_id() const;
    static void check_id_from_all_vector(const std::vector<Student>& vec);
    std::vector<Student> operator()(const std::string& filename);
    //void menu();
};