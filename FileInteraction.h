#pragma once

#include <string>
#include <fstream>
#include<vector>
#include "Student.h"
#include "Date.h"
#include "Sex.h"
#include "Faculty.h"


void WriteToFile(vector<Student> students, ofstream& file) {

    for (Student student: students) {
        file << student.firstName << ";" << student.lastName << ";" << student.birthDay.year << '.' << student.birthDay.month << '.' << student.birthDay.day << ';' << SexToString(student.sex) << ";" << FacultyToString(student.faculty) << ";" << student.group << ";" << student.IsStudyToString() << endl;
    }

}

void ReadFromFile(vector<Student>& students, ifstream& file) {
    Student student;
    string someShit;
 
   
   while(!file.eof()) {
        getline(file, student.firstName, ';');
        getline(file, student.lastName, ';');
        getline(file, someShit, '.');
        student.birthDay.year = stoi(someShit);
        getline(file, someShit, '.');
        student.birthDay.month = stoi(someShit);
        getline(file, someShit, ';');
        student.birthDay.day = stoi(someShit);
        getline(file, someShit, ';');
        if (someShit == "мужской") {
            student.sex = Sex::Male;
        } else if (someShit == "женский") {
            student.sex = Sex::Female;
        }
        else {
            student.sex = Sex::Other;
        }
        getline(file, someShit, ';');
        if (someShit == "Разработка ПО") {
            student.faculty = Faculty::SoftDev;
        }
        else {
            student.faculty = Faculty::Design;
        }
        getline(file, student.group, ';');
        getline(file, someShit);
        if (someShit == "учится") {
            student.isStudy = true;
        }
        else {
            student.isStudy = false;
        }

        students.push_back(student);
    }
}




