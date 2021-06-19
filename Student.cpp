#include "Student.h"

void Student::info() const{
        std::cout << name << " " << surname << " " << address << " " << "IDX_NR: " << idx_nr << " "
        << "PESEL: " << id << " " << sex << '\n';
}

std::ostream &operator<<(std::ostream &out, const Student &student) {
    out << student.name << " " << student.surname << " " << student.address << " " << student.idx_nr << " "
    << student.id << " " << student.sex << '\n';
    return out;
}

std::istream& operator>>(std::istream &in, Student &student) {
    std::cout << "TYPE NAME: ";
    std::getline(in, student.name);
    std::cout << "TYPE SURNAME: ";
    std::getline(in, student.surname);
    std::cout << "TYPE ADDRESS: ";
    std::getline(in, student.address);
    std::cout << "TYPE INDEX NR: ";
    in >> student.idx_nr; in.get();
    std::cout << "TYPE PESEL: ";
    in >> student.id; in.get();
    std::cout << "TYPE SEX: ";
    std::getline(in, student.sex);
    return in;
}

void Student::show_data_base(const std::vector<Student> &vec) {
    for (const auto &i : vec){
        i.info();
    }
}

Student Student::search_by_surname(const std::vector<Student> &vec) {
    std::string surname_;
    std::vector<Student> s1;
    std::cout << "TYPE SURNAME: ";
    std::cin >> surname_;
    for(const auto & i : vec)
    {
        if(i.surname == surname_)
        {
            return i;
        }
    }
    throw std::runtime_error("SURNAME NOT FOUND");
}

Student Student::search_by_id(const std::vector<Student> &vec) {
    std::string id_;
    std::cout << "TYPE PESEL: ";
    std::cin >> id_;
    for(const auto & i : vec)
    {
        if(i.id == id_)
        {
            return i;
        }
    }
    throw std::runtime_error("PESEL NOT FOUND");
}

void Student::sort_by_id(std::vector<Student> &vec) {
    std::sort(vec.begin(), vec.end(), [](const Student& lhs, const Student& rhs) {
        return lhs.id < rhs.id;
    });
}

void Student::sort_by_surname(std::vector<Student> &vec) {
    std::sort(vec.begin(), vec.end(), [](const Student& lhs, const Student& rhs){
       return lhs.surname < rhs.surname;
    });
}

//usuwanie przez numer indeksu
void Student::deleted_by_idx_nr(std::vector<Student> &vec) {
    std::string idx_nr_;
    std::cout << "TYPE IDX_NR: ";
    std::cin >> idx_nr_;
    for(int i = 0; i < vec.size(); ++i)
    {
        if(idx_nr_ == vec[i].idx_nr)
        {
            vec.erase(vec.begin() + i);
        }
    }
}

void Student::correct_id() const{
    std::vector<int> vec {1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1};
    int a;
    int result = 0;
    for(int i = 0; i < id.length(); i++)
    {
        a = id[i] * vec[i];
        result += a;
    }
    if(result > 0 && result % 10 == 0)
    {
        std::cout << "PESEL IS CORRECT" << '\n';
    }
    else
    {
        std::cout << "PESEL IS INCORRECT!" << '\n';
    }
    result = 0;
}

void Student::check_id_from_all_vector(const std::vector<Student>& vec) {
    for(const auto & i : vec)
    {
        i.info();
        i.correct_id();
    }
}

std::vector<Student> Student::operator()(const std::string &filename) {
    std::ifstream file;
    file.open(filename);
    if(!file.good()) {
        throw std::runtime_error("");
    }
    std::string name_, surname_, address_, idx_nr_,id_, sex_;
    std::string separator;
    std::vector<Student> s;
    while(!file.eof())
    {
        std::getline(file, name_);
        std::getline(file, surname_);
        std::getline(file, address_);
        std::getline(file, idx_nr_);
        std::getline(file, id_);
        std::getline(file, sex_);
        std::getline(file, separator);
        s.emplace_back(name_, surname_, address_, idx_nr_, id_, sex_);
    }
    return s;
}

/*void Student::menu()
{
    std::cout << "====================================" << '\n';
    std::cout << "******** STUDENTS DATA BASE ********" << '\n';
    std::cout << "====================================" << '\n';
    std::cout << "1. Show all students" <<'\n' << "2. Sort by PESEL" << '\n' << "3. Sort by SURNAME" << '\n'
    << "4. Search student by SURNAME" << '\n' << "4. Search student by PESEL" << '\n' << "5. Delete by INDEX NUMBER" << '\n';
    int choice;
    switch (choice) {
        case 1:
            Student::show_data_base();
    }
}*/

