#include "Student.h"

int main() {
    try
    {
        Student s4, s3;
        //std::cin >> s3;
        std::vector<Student> s1 = s4("student.txt");
/*      Student::show_data_base(s1);
        Student::deleted_by_idx_nr(s1);
        Student::show_data_base(s1);*/
        //s3.menu();

            std::cout << "====================================" << '\n';
            std::cout << "******** STUDENTS DATA BASE ********" << '\n';
            std::cout << "====================================" << '\n';
            std::cout << "1. Show all students" << '\n' << "2. Sort by PESEL" << '\n' << "3. Sort by SURNAME" << '\n'
                      << "4. Search student by SURNAME" << '\n' << "5. Search student by PESEL" << '\n'
                      << "6. Delete by INDEX NUMBER" << '\n' << "7. Check the correct id" << '\n' << "8. Exit" << '\n';
            do{
            int choice;
            std::cout << "Option nr: ";
            std::cin >> choice;
            switch (choice)
            {
                case 1:
                    Student::show_data_base(s1);
                    break;
                case 2:
                {
                    Student::sort_by_id(s1);
                    Student::show_data_base(s1);
                    break;
                }
                case 3:
                {
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
                    Student::deleted_by_idx_nr(s1);
                    Student::show_data_base(s1);
                    break;
                }
                case 7:{
                    Student::check_id_from_all_vector(s1);
                    break;
                }
                case 8:
                    exit(0);
                default:
                {
                    std::cout << "Wrong choice!";
                    break;
                }
            }
        } while(true);
    }
    catch (std::runtime_error& e) {
        std::cout << e.what();
    }
    return 0;
}
