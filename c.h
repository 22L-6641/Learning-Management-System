#pragma once
#ifndef C_H
#define C_H
#include<iostream>
#include<Windows.h>
#include"Filehandler.h"
#include"s.h";
using namespace std;
class Course
{
private:
	string code;
	string name;
	string instructor;
	int credits;
	int capacity;
	Student* students;
	int totalStudents;
public:
	friend class FileHandler;
	Course();
	Course(string c, string n, string ins, int cre, int cap , int ts, Student* st);
	void DisplayStudents();
	void enrollStudent();
	void removeStudent();
	Course* EditStudentDetail(int);
	void readfromfile(string c, string n, string ins, int cre, int cap, Student* obj, int t);
	void Availablecourse();
};
#endif