#pragma once

#include <string>
#include <fstream>
#include<vector>
#include "Student.h"
#include "Date.h"
#include "Sex.h"
#include "Faculty.h"


void WriteToFile(string adress, vector<Student> students) {
    ofstream file_1;
    file_1.open(adress, ios_base::trunc);

    for (Student student: students) {
        file_1 << student.firstName << ";" << student.lastName << ";" << student.birthDay.year << '.' << student.birthDay.month << '.' << student.birthDay.day << ';' << SexToString(student.sex) << ";" << FacultyToString(student.faculty) << ";" << student.group << ";" << student.IsStudyToString() << endl;
    }

    file_1.close();
}

void ReadFromFile(string adress, vector<Student>& students) {
    Student student;
    string someShit;
 
    ifstream file_2;
    file_2.open(adress);
    if (file_2.is_open()) {
        getline(file_2, student.firstName, ';');
        getline(file_2, student.lastName, ';');
        getline(file_2, someShit, '.');
        student.birthDay.year = stoi(someShit);
        getline(file_2, someShit, '.');
        student.birthDay.month = stoi(someShit);
        getline(file_2, someShit, ';');
        student.birthDay.day = stoi(someShit);
        getline(file_2, someShit, ';');
        if (someShit == "мужской") {
            student.sex = Sex::Male;
        } else if (someShit == "женский") {
            student.sex = Sex::Female;
        }
        else {
            student.sex = Sex::Other;
        }
        getline(file_2, someShit, ';');
        if (someShit == "Разработка ПО") {
            student.faculty = Faculty::SoftDev;
        }
        else {
            student.faculty = Faculty::Design;
        }
        getline(file_2, student.group, ';');
        getline(file_2, someShit, ';');
        if (someShit == "учится") {
            student.isStudy = true;
        }
        else {
            student.isStudy = false;
        }
    }
    file_2.close();

    students.push_back(student);

}




