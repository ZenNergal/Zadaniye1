/*Создайте класс "Студент", который содержит поля для имени,
фамилии, возраста и оценок. Реализуйте методы для установки и
получения значений полей, вычисления среднего балла и является ли
студент отличником (4.5), а также для вывода информации о студенте
на экран.*/
#include <iostream>
#include <string>
#include <vector>
#include <windows.h> //Чтобы в моём компиляторе не было проблем с кириллицей
using namespace std;
class Student {
private:
    string firstName;
    string lastName;
    vector<int> grades;
    int age;
    int gradescount;
public:
    void setFirstName() {
        cout << "Введи имя студента: ";
        cin >> firstName;
    }
    void setLastName() {
        cout << "Введи фамилию студента: ";
        cin >> lastName;
    }
    void setAge() {
        cout << "Введи возраст студента: ";
        cin >> age;
    }
    void setGrades() {
        int grade;
        cout << "Введи количество оценок: ";
        cin >> gradescount;
        cout << "Введи оценки: ";
        for (int i = 0; i < gradescount; i++) {
            cin >> grade;
            grades.push_back(grade);
        }
    }
    string getFirstName() {
        return firstName;
    }
    string getLastName() {
        return lastName;
    }
    int getAge() {
        return age;
    }
    vector<int> getGrades() {
        return grades;
    }
    double getAverageGrade() {
        double summa = 0;
        for (int i = 0; i < gradescount; i++) {
            summa += grades[i];
        }
        return summa / gradescount;
    }
    bool IsStudentHonor() {
        return (getAverageGrade() >= 4.5);
    }
    void printInfo() {
        cout << "Имя: " << firstName << endl;
        cout << "Фамилия: " << lastName << endl;
        cout << "Возраст: " << age << endl;
        cout << "Оценки: ";
        for (int i = 0; i < gradescount; i++) {
            cout << grades[i] << " ";
        }
        cout << endl;
        cout << "Средний балл: " << getAverageGrade() << endl;
        if (IsStudentHonor()) {
            cout << "Студент является отличником" << endl;
        }
        else {
            cout << "Студент не является отличником" << endl;
        }
    }
};
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); //Тоже для кириллицы
    Student student;
    student.setFirstName();
    student.setLastName();
    student.setAge();
    student.setGrades();
    student.printInfo();
    return 0;
}