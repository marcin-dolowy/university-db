#include "Student.h"

int main() {
    while(true) {
        try {
            std::vector<Student> s1 = Student::read_file("student.txt");
            /*int AGE_MIN = 15;
            int AGE_MAX = 30;
            auto find_if = std::find_if(s1.begin(),s1.end(), age(s3,AGE_MIN,AGE_MAX));
            std::cout << *find_if << std::endl;*/

            std::cout << "====================================" << '\n';
            std::cout << "******** STUDENTS DATA BASE ********" << '\n';
            std::cout << "====================================" << '\n';
            std::cout << "1. Load all students from file" << '\n' << "2. Sort by PESEL" << '\n' << "3. Sort by SURNAME" << '\n'
                      << "4. Search student by SURNAME" << '\n' << "5. Search student by PESEL" << '\n'
                      << "6. Add student" << '\n' << "7. Delete by INDEX NUMBER"
                      << '\n' << "8. Check the correct id" << '\n' << "9. Save data" << '\n' << "10. Exit" << '\n';
            do {
                int choice;
                std::cout << "Type nr: ";
                std::cin >> choice;
                switch (choice) {
                    case 1:
                        Student::show_data_base(s1);
                        break;
                    case 2: {
                        Student::sort_by_id(s1);
                        Student::show_data_base(s1);
                        break;
                    }
                    case 3: {
                        Student::sort_by_surname(s1);
                        Student::show_data_base(s1);
                        break;
                    }
                    case 4: {
                        std::cout << Student::search_by_surname(s1);
                        break;
                    }
                    case 5: {
                        std::cout << Student::search_by_id(s1);
                        break;
                    }
                    case 6: {
                        Student s3;
                        std::cin >> s3; std::cin.get();
                        s1.emplace_back(s3);
                        break;
                    }
                    case 7: {
                        Student::deleted_by_idx_nr(s1);
                        Student::show_data_base(s1);
                        break;
                    }
                    case 8: {
                        Student::check_id_from_all_vector(s1);
                        break;
                    }
                    case 9:{
                        Student s2;
                        int a;
                        std::cout << "How many student do you want to add: ";
                        std::cin >> a;
                        std::vector<Student> vec;
                        for(int i = 0; i < a; ++i)
                        {
                            std::cin >> s2; std::cin.get();
                            vec.emplace_back(s2);
                        }
                        Student::save_file(vec, "student.txt");
                        break;
                    }
                    case 10:
                        return 0;
                    default: {
                        std::cout << "Wrong choice!";
                        return 0;
                    }
                }
            } while (true);
        }
        catch (std::runtime_error &e) {
            std::cout << e.what();
        }
    }
}