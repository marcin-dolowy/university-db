#include "Student.h"

int main() {
    try {
        Student s4,s3;
        //std::cin >> s3;
        std::vector<Student> s1 = s4("student.txt");
        //s1.emplace_back(s3);
        Student::show_data_base(s1);
        Student::deleted_by_idx_nr(s1);
        Student::show_data_base(s1);
    }
    catch (std::runtime_error& e) {
        std::cout << e.what();
    }
}
