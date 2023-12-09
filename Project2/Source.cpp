#include<iostream>
#include<fstream>
using namespace std;
class student
{
	string name;
	string rollno;
	int age;
	string contact;
	course** c;
	int* attendance;
	int* marks;
	int no_of_course;
	int crcapacity;
public :
	student()
	{
		name = "";
		rollno = "";
		age = 0;
		contact = "";
		no_of_course = 0;
		c = new course * [5];
		attendance = new int[5];
		marks = new int[5];
	}
	string getrollno()
	{
		return rollno;
	}
	void enroll(course* cr)
	{
		c[no_of_course] = cr;
		c[no_of_course]->addstudent(this);
		no_of_course++;
	}
	/*void registercourses()
	{

	}*/
	void markattendance(string course, int attend)
	{

		for (int i = 0; i < no_of_course; i++)
		{
			if (c[i]->getname() == course)
			{
				attendance[i] = attend;
			}
		}
	}
	void assign_marks(string course, int weight)
	{
		for (int i = 0; i < no_of_course; i++)
		{
			if (c[i]->getname() == course)
			{
				marks[i] = weight;
			}
		}
	}
	void withdrawcourse(string course)
	{
		for (int i = 0; i < no_of_course; i++)
		{
			if (c[i]->getname() == course)
			{
				c[i]->removestudent(rollno);
				c[i] = nullptr;
			}
		}

	}
	void display()
	{
		cout << name << endl;
		cout << rollno;
	}
};
class course
{
	string code;
	string name;
	string instructor;
	string credits;
	int capacity;
	int no_of_std;
	student** s;
public:
	course()
	{
		code = "";
		name = "";
		instructor = "";
		credits = "";
		int capacity = 30;
		s = new student*[30];
	}
	/*student* search(string rollno)
	{
		for (int i = 0; i < no_of_std; i++)
		{
			if (rollno == ((*s[i]).getrollno()))
			{
				return &s[i];
			}
		}
		return 0;
	}*/
	string getname()
	{
		return name;
	}
	void addstudent(student* st)
	{
		s[no_of_std] = st;
		no_of_std++;
	}
	void removestudent(string rollno)
	{
		for (int i = 0; i < no_of_std; i++)
		{
			if (rollno == ((*s[i]).getrollno()))
			{
				s[i] = 0;
			}
		}
	}
	void dsplaystudents()
	{
		for (int i = 0; i < no_of_std; i++)
		{
			s[i]->display();
		}
	}
};
class system
{
	int choice;
	student** s;
	course** c;
public :
	void displaymainmenu()
	{
		do {
			// Display Main Menu
			cout << "Main Menu" << endl;
			cout << "1- Enroll a student" << endl;
			cout << "2- Course Registration" << endl;
			cout << "3- Attendance" << endl;
			cout << "4- Marks" << endl;
			cout << "5- Course Withdraw" << endl;
			cout << "6- Exit" << endl;
			cout << "Press 1 to 6 to select an option: ";
			cin >> choice;

			// Process user choice
			switch (choice) {
			case 1:
				// Handle Enroll a student submenu
				cout << "Enroll a student submenu" << endl;
				// Add your code for handling this option
				break;

			case 2:
				// Handle Course Registration submenu
				cout << "Course Registration submenu" << endl;
				// Add your code for handling this option
				break;

			case 3:
				// Handle Attendance submenu
				cout << "Attendance submenu" << endl;
				// Add your code for handling this option
				break;

			case 4:
				// Handle Marks submenu
				cout << "Marks submenu" << endl;
				// Add your code for handling this option
				break;

			case 5:
				// Handle Course Withdraw submenu
				cout << "Course Withdraw submenu" << endl;
				// Add your code for handling this option
				break;

			case 6:
				// Exit the program
				cout << "Exiting the program." << endl;
				break;

			default:
				// Invalid choice
				cout << "Invalid choice. Please enter a number from 1 to 6." << endl;
			}

		} while (choice != 6);
	}
	void display_enroll_menu()
	{

	}
	void display_course_registration_menu()
	{

	}
	void display_attendance_menu()
	{

	}
	void display_marks_menu()
	{

	}
	void display_course_withdraw_menu()
	{

	}
};
template<typename N>
class filehandler
{
private :
	fstream filename;
	string mode;
public :
	void openfile(string fn, string mod)
	{
		filename.open(fn, ios::mod);
	}
	void closefile()
	{
		filename.close();
	}
	N readdata()
	{
		N data;
		filename >> data;
	}
	void writedata(N)
	{

	}
};
class validator
{
	string input;
	string type;
	string constraints;

};
int main()
{
	return 0;
}