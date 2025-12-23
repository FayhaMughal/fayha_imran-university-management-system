#include <iostream>
using namespace std;
class users {
protected:
	string name;
	int id;
public:
	users(string n, int i) : name(n), id(i) {
		cout << "[User Constructor] is called for: " << name << " (ID: " << id << ")" << endl;
	}
	void login() {
		cout << "---- Welcome to the Smart Management System ----" << endl;
	}
	void logOut() {
		cout << "---- Thank you for using the Smart Management System ----" << endl;
	}~users() {
		cout << "[User Destructor] is called for: " << name << " (ID: " << id << ")" << endl;
	}
};
class student : public users {
public:
	string courseName;
	student(string n, int i, string c) : users(n, i), courseName(c) {
		cout << "[Student Constructor] is called for: " << name << endl;
	}
	void courseRegister() {
		login();
		cout << courseName << "The course registered against ID: " << id << endl;
		logOut();
	}~student() {
		cout << "[Student Destructor] is called for: " << name << endl;
	}
};
class Teacher : public users {
public:
	Teacher(string n, int i) : users(n, i) {
		cout << "[Teacher Constructor] is called for: " << name << endl;
	}
	void uploadMarks() {
		login();
		cout << "Teacher " << name << " uploading marks of students" << endl;
		logOut();
	}~Teacher() {
		cout << "[Teacher Destructor] is called for: " << name << endl;
	}
};
class Admin : public users {
public:
	Admin(string n, int i) : users
	(n, i) {
		cout << "[Admin Constructor] is called for: " << name << endl;
	}
	void manageSystem() {
		login();
		cout << "[Admin] Name: " << name << "\n[Admin] ID: " << id << endl;
		cout << "--- System management assigned successfully ---" << endl;
		logOut();
	}~Admin() {
		cout << "[Admin Destructor] is called for: " << name << endl;
	}
};
int main() {
	cout << "---- Creating Student Object ----" << endl;
	student s1("Fayha", 100, "English");
	s1.courseRegister();
	cout << "\n---- Creating Teacher Object ----" << endl;
	Teacher t1("Warda", 200);
	t1.uploadMarks();
	cout << "\n---- Creating Admin Object ----" << endl;
	Admin a1("Minal", 300);
	a1.manageSystem();
	cout << "\n---- End of Program ----" << endl;
	return 0;
}