#include "Student.h"

void Student::info() const{
        std::cout << name << " " << surname << " " << address << "\n " << "IDX_NR: " << idx_nr << "\n "
        << "PESEL: " << id << " " << sex << '\n';
}

std::ostream &operator<<(std::ostream &out, const Student &student) {
    return out << student.name << " " << student.surname << " " << student.address << " " << "IDX_NR: "
    << student.idx_nr << " "<< "PESEL: " << student.id << " " << student.sex << '\n';
}

std::istream& operator>>(std::istream &in, Student &student) {
    std::cout << "TYPE NAME: ";
    in >> student.name; in.get();
    std::cout << "TYPE SURNAME: ";
    in >> student.surname; in.get();
    std::cout << "TYPE ADDRESS: ";
    std::getline(in, student.address);
    std::cout << "TYPE INDEX NR: ";
    in >> student.idx_nr; in.get();
    std::cout << "TYPE PESEL: ";
    in >> student.id; in.get();
    std::cout << "TYPE SEX: ";
    in >> student.sex; in.get();
    return in;
}

void Student::show_data_base(const std::vector<Student> &vec) {
    for (int i = 0; i < vec.size(); ++i){
        std::cout << i + 1 << ". " << vec[i];
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
}

void Student::check_id_from_all_vector(const std::vector<Student>& vec) {
    for(const auto & i : vec)
    {
        std::cout << i;
        i.correct_id();
    }
}

std::vector<Student> Student::read_file(const std::string &filename) {
    std::ifstream file;
    file.open(filename);
    if(!file.is_open()) {
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

void Student::save_file(const std::vector<Student>& vec, const std::string &filename) {
    std::ofstream save;
    save.open(filename, std::ios::app);
    if(!save.is_open()) {
        throw std::runtime_error("ERROR");
    }
    for (const auto& i : vec)
    {
        save << '\n' << i.name << '\n' << i.surname << '\n' << i.address << '\n'
        << i.idx_nr << '\n' << i.id << '\n'<< i.sex << '\n' << "======" << '\n';
    }
    std::cout << "Saved successfully :)!" << '\n';
}
