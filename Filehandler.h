#pragma once
#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include<string>
#include<fstream>
#include"c.h"
#include"s.h"
using namespace std;
class FileHandler
{
private:
	//string filename;
	//ios::openmode mode;
	fstream fin;
public:
	FileHandler()
	{
		fin;
	}
	void open(string f, ios::openmode m)
	{
		fin.open(f, m);
	}
	void close()
	{
		fin.close();
	}
	void read(Student*& obj, int& t)
	{
		fin >> t;
		obj = new Student[t];
		string name, fname, lname, roll_num;
		int age;
		long long contact;
		for (int i = 0; i < t; i++)
		{
			fin >> fname;
			fin >> lname;
			name = fname + " " + lname;
			fin >> age;
			fin >> roll_num;
			fin >> contact;
			obj[i].readfromfile(name, roll_num, age, contact);
		}
	}
	void read(Course*& obj, int& t)
	{
		fin >> t;
		obj = new Course[t];
		string code, name, instructor;
		int credits, capacity;
		for (int i = 0; i < t; i++)
		{
			fin >> code;
			fin >> name;
			fin >> instructor;
			fin >> credits;
			fin >> capacity;
			fstream tmp;
			string fname = code + ".txt";
			tmp.open(fname, ios::in);
			Student* o;
			int T;
			tmp >> T;
			o = new Student[T];
			string a, b;
			for (int j = 0; j < T; j++)
			{
				tmp >> a;
				tmp >> b;
				o[j].name = a + " " + b;
				tmp >> o[j].age;
				tmp >> o[j].roll_num;
				tmp >> o[j].contact;
			}
			tmp.close();
			obj[i].readfromfile(code, name, instructor, credits, capacity, o, T);
		}
	}
	//void operator>>(Student& obj)
	//{
	//	fin >> obj.name;
	//	fin >> obj.age;
	//	fin >> obj.roll_num;
	//	fin >> obj.contact;
	//}
	template<typename T>
	void operator<<(T a)
	{
		fin << a;
	}
	//void operator<<(string n)
	//{
	//	fin << n << "\t\t";
	//}
	//void operator<<(int a)
	//{
	//	fin << a << "\t\t";
	//}
	//void operator<<(long long c)
	//{
	//	fin << c;
	//}
	template<typename T>
	void operator>>(T& n)
	{
		fin >> n;
	}
	//void operator>>(int& a)
	//{
	//	fin >> a;
	//}
	//void operator>>(long long& c)
	//{
	//	fin >> c;
	//}
	bool operator!()
	{
		return (fin.eof() == 0);
	}
};
#endif // !FILEHANDLER_H
