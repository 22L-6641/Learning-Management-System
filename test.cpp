#include<iostream>
#include<fstream>
#include<string>
#include"Filehandler.h"
#include"c.h"
#include"s.h"
#include<stdio.h>
using namespace std;

class Course;
class Student;
class FileHandler;

Course::Course()
{
	code = " ";
	name = " ";
	instructor = " ";
	credits = 0;
	students = 0;
	totalStudents = 0;
}
Course::Course(string c, string n, string ins, int cre, int cap, int ts, Student* st)
{
	code = c;
	name = n;
	instructor = ins;
	credits = cre;
	capacity = cap;
	students = st;
	totalStudents = ts;
}
void Course::DisplayStudents()
{
	system("cls");
	cout << code << "\t\t"
	<< name << "\t\t"
	<< instructor << "\t\t"
	<< credits << "\t\t"
	<< capacity << "\t\t\t"
	<< totalStudents << "\t\n";
	for (int i = 0; i < totalStudents; i++)
	{
		cout << students[i];
	}
	Sleep(3000);
}
void Course::EditStudentDetail(int t)
{
	Course*temp = this;
	string roll;
	int len;
	system("cls");
	cout << "Enter the roll number of student = ";
	cin >> roll;
	for (int i = 0; i < t; i++)
	{
		len = temp[i].totalStudents;
		for (int j = 0; j < len; j++)
		{
			if (roll == temp[i].students[j].getrollnum())
			{
				temp[i].students[j].updateStudent();
			}
		}
	}
}
void Course::removeStudent()
{
	FileHandler fin;
	string roll;
	Student* temp;
	int len;
	system("cls");
	cout << "Enter the roll number of student = ";
	cin >> roll;
	bool flag = false;
	for (int i = 0; i < totalStudents; i++)
	{
		if (roll == students[i].getrollnum())
		{
			flag = true;
			len = totalStudents - 1;
			temp = new Student[len];
			int k = 0;
			for (int j = 0; j < totalStudents; j++)
			{
				if (roll == students[j].getrollnum())
				{
					continue;
				}
				else
				{
					temp[k] = students[j];
					k++;
				}
			}
			delete[] students;
			students = temp;
			totalStudents = len;
		}

	}
	if (!flag)
	{
		cout << "Roll num not found!!!\n";
	}
	const char* filename;
	filename = Help::GetStrFromBuffer(code + ".txt");
	remove(filename);
	fin.open(filename, ios::app);
	fin << totalStudents;
	fin << '\n';
	for (int i = 0; i < totalStudents; i++)
	{
		fin << students[i].getname();
		fin << "\t\t";
		fin << students[i].getage();
		fin << "\t\t";
		fin << students[i].getrollnum();
		fin << "\t\t";
		fin << students[i].getconatct();
		fin << '\n';
	}
	fin.close();
	Sleep(100);
}
void Course::enrollStudent()
{
	FileHandler fin;
	int tmp = totalStudents;
	totalStudents++;
	string Name, roll_num , fname , lname;
	int age, * y = 0;
	long long contact;
	char* a = 0;
	system("cls");
	cout << "First Name : ";
	cin >> fname;
	cout << "Last Name : ";
	cin >> lname;
	Name = fname + " " + lname;
	cout << "Age : ";
	cin >> age;
	cout << "Roll num : ";
	cin >> roll_num;
	cout << "Contact : ";
	cin >> contact;
	Student* temp = new Student[totalStudents];
	for (int i = 0; i < tmp; i++)
	{
		temp[i] = students[i];
	}
	temp[totalStudents - 1] = Student(Name, roll_num, age, contact, a, y);
	students = temp;
	const char* filename;
	filename = Help::GetStrFromBuffer(code + ".txt");
	remove(filename);
	fin.open(filename, ios::app);
	fin << totalStudents;
	fin << '\n';
	for (int i = 0; i < totalStudents; i++)
	{
		fin << students[i].getname();
		fin << "\t\t";
		fin << students[i].getage();
		fin << "\t\t";
		fin << students[i].getrollnum();
		fin << "\t\t";
		fin << students[i].getconatct();
		fin << '\n';
	}
	fin.close();
	Sleep(100);
}
void Course::readfromfile(string c, string n, string ins, int cre, int cap, Student* obj, int t)
{
	code = c;
	name = n;
	instructor = ins;
	credits = cre;
	capacity = cap;
	totalStudents = t;
	students = new Student[t];
	for (int i = 0; i < t; i++)
	{
		students[i] = obj[i];
	}
}
void Course::Availablecourse()
{
	cout <<"(" << code << ") - " << name << endl;
}
class System
{
private:
	//Student* students;
	Course* courses;
	int totalstudents;
	int totalcourses;
	int menus;
public:
	System()
	{
		//students = 0;
		courses = 0;
		totalstudents = 0;
		totalcourses = 0;
		menus = 0;
		FileHandler fin;
		//fin.open("students.txt", ios::in);
		//fin.read(students, totalstudents);
		//fin.close();
		fin.open("courses.txt", ios::in);
		fin.read(courses, totalcourses);
		fin.close();
	}
	void Mainmenu()
	{
	start:
		system("cls");
		cout << "\t1 - Enroll a student\n";
		cout << "\t2 - Course Registration\n";
		cout << "\t3 - Attendance\n";
		cout << "\t4 - Marks\n";
		cout << "\t5 - Course Withdraw\n";
		cout << "\t6 - Exit\n";
		cin >> menus;
		if (menus > 6 || menus == 0)
		{
			system("cls");
			cout << "Invalid input!!\n";
			Sleep(3000);
			goto start;
		}
		else if(menus <= 5)
		{
			this->Submenu(menus);
		}
		else
		{
			cout << "Tabinda\n";
		}
		Sleep(100);
	}
	void Submenu(int i)
	{
		int in;
	start:
		system("cls");
		if (i == 1)
		{
			cout << "\t1 - Display already enrolled students\n";
			cout << "\t2 - Add a student\n";
			cout << "\t3 - Remove a student\n";
			cout << "\t4 - Edit student detail\n";
			cout << "\t5 - Back\n";
			cin >> in;
			if (in > 5 || in == 0)
			{
				system("cls");
				cout << "Invalid input!!\n";
				Sleep(3000);
				goto start;
			}
			else if (in == 1)
			{
				for (int i = 0; i < totalcourses; i++)
				{
					courses[i].DisplayStudents();
				}
				goto start;
			}
			else if (in == 2)
			{
				int i = 0;
			a:
				system("cls");
				cout << "\t\"Available course\"\n\n";
				for (int j = 0; j < totalcourses; j++)
				{
					cout <<"\t" << j << " - ";
					courses[j].Availablecourse();
				}
				do
				{
					if (i < 0 || i > totalstudents)
					{
						system("cls");
						cout << "Invalid input!!\n";
						Sleep(3000);
						goto a;
					}
					cout << "\nIn which course you want to add student = ";
					cin >> i;
				} while (i < 0 || i > totalstudents);
				courses[i].enrollStudent();
				Sleep(3000);
				goto start;
			}
			else if (in == 3)
			{
				int i = 0;
			b:
				system("cls");
				cout << "\t\"Available course\"\n\n";
				for (int j = 0; j < totalcourses; j++)
				{
					cout << "\t" << j << " - ";
					courses[j].Availablecourse();
				}
				do
				{
					if (i < 0 || i > totalstudents)
					{
						system("cls");
						cout << "Invalid input!!\n";
						Sleep(3000);
						goto b;
					}
					cout << "\nIn which course you want to remove student = ";
					cin >> i;
				} while (i < 0 || i > totalstudents);
				courses[i].removeStudent();
				Sleep(3000);
				goto start;

			}
			else if (in == 4)
			{
			//	int i = 0;
			//c:
			//	system("cls");
			//	cout << "\t\"Available course\"\n\n";
			//	for (int j = 0; j < totalcourses; j++)
			//	{
			//		cout << "\t" << j << " - ";
			//		courses[j].Availablecourse();
			//	}
				courses->EditStudentDetail(totalcourses);
			}
			else if (in == 5)
			{
				this->Mainmenu();
			}
		}
		else if (i == 2)
		{
			cout << "\t1 - Available Courses\n";
			cout << "\t2 - Register course\n";
			cout << "\t3 - Back\n";
			cin >> in;
			if (in > 3 || in == 0)
			{
				system("cls");
				cout << "Invalid input!!\n";
				Sleep(3000);
				goto start;
			}
			else if (in == 3)
			{
				this->Mainmenu();
			}
		}
		else if (i == 3)
		{
			cout << "\t1 - Display Attendance(Subject wise)\n";
			cout << "\t2 - Mark Attendance.\n";
			cout << "\t3 - Back\n";
			cin >> in;
			if (in > 3 || in == 0)
			{
				system("cls");
				cout << "Invalid input!!\n";
				Sleep(3000);
				goto start;
			}
			else if (in == 3)
			{
				this->Mainmenu();
			}
		}
		else if (i == 4)
		{
			cout << "\t1 - Display Marks(Subject wise)\n";
			cout << "\t2 - Assign Marks.\n";
			cout << "\t3 - Back\n";
			cin >> in;
			if (in > 3 || in == 0)
			{
				system("cls");
				cout << "Invalid input!!\n";
				Sleep(3000);
				goto start;
			}
			else if (in == 3)
			{
				this->Mainmenu();
			}
		}
		else if(i == 5)
		{
			cout << "\t1 - Enrolled courses\n";
			cout << "\t2 - Drop a course\n";
			cout << "\t3 - Back\n";
			cin >> in;
			if (in > 3 || in == 0)
			{
				system("cls");
				cout << "Invalid input!!\n";
				Sleep(3000);
				goto start;
			}
			else if (in == 3)
			{
				this->Mainmenu();
			}
		}
		Sleep(100);
	}
};
//class Validator
//{
//private:
//	Student input;
//
//};
int main()
{
	System s;
	s.Mainmenu();
	return 0;
}