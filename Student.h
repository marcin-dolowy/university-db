#include "libs.h"

class Student{
private:
    std::string name;
    std::string surname;
    std::string address;
    std::string idx_nr;
    std::string id;
    std::string sex;

public:
    Student(std::string name, std::string surname, std::string address,
            std::string idx_nr, std::string id, std::string sex)
    : name(std::move(name)), surname(std::move(surname)), address(std::move(address)),
    idx_nr(std::move(idx_nr)),id(std::move(id)), sex(std::move(sex)) {}
    Student() = default;
    ~Student() = default;
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
    static std::vector<Student> read_file(const std::string& filename);
    static void save_file(const std::vector<Student>& vec, const std::string& filename);
};