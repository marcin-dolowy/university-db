#include "Student.h"

void menu(std::vector<Student>& s1) {
    char choice{};
    std::cout << "Type nr: ";
    std::cin >> choice;
    switch (choice) {
        case '1': {
            Student::show_data_base(s1);
            break;
        }
        case '2': {
            Student::sort_by_id(s1);
            Student::show_data_base(s1);
            break;
        }
        case '3': {
            Student::sort_by_surname(s1);
            Student::show_data_base(s1);
            break;
        }
        case '4': {
            std::cout << Student::search_by_surname(s1);
            break;
        }
        case '5': {
            std::cout << Student::search_by_id(s1);
            break;
        }
        case '6': {
            Student s3;
            std::cin >> s3;
            std::cin.get();
            s1.emplace_back(s3);
            std::cout << "You added one student! ;)" << '\n';
            break;
        }
        case '7': {
            Student::deleted_by_idx_nr(s1);
            Student::show_data_base(s1);
            break;
        }
        case '8': {
            Student::check_id_from_all_vector(s1);
            break;
        }
        case '9': {
            Student::save_file(s1, "data.txt");
            break;
        }
        case '0':
            exit(0);
        default: {
            std::cout << "Wrong choice!";
            break;
        }
    }
}

int main() {
    try {
        std::cout << "====================================" << '\n';
        std::cout << "******** STUDENTS DATA BASE ********" << '\n';
        std::cout << "====================================" << '\n';
        std::cout << "1. Load all students from file" << '\n' << "2. Sort by PESEL" << '\n' << "3. Sort by SURNAME"
                  << '\n'
                  << "4. Search student by SURNAME" << '\n' << "5. Search student by PESEL" << '\n' << "6. Add student"
                  << '\n' << "7. Delete by INDEX NUMBER" << '\n' << "8. Check the correctness PESEL in data base"
                  << '\n' << "9. Save data" << '\n' << "0. Exit" << '\n';

        while (true) {
            std::vector<Student> s1 = Student::read_file("students.txt");
            do {
                menu(s1);
            } while (true);
        }
    }
    catch (std::runtime_error &e) {
        std::cout << e.what();
    }

}