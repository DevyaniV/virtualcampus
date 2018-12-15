#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include "virtual_campus.h"


using namespace std;


//    string *array1 = new string[2]{"bas", "devyani"};
//    float *array2 = new float[2]{0, 0};

////    Courses english(6, array1, array2, 2, 2 );

////    float *array3 = new float[2]{10, 19};


////    a.createc(english, 2, array1, array3, 2, 2);
////    a.displayc(english);

//    Courses hindi;

//    //show start up menu

//    char a;


//    cout << "Welcome to virtual campus" << endl;
//    cout << "Please enter your identity alphabet (S - student, P - professor, A - Admin" << endl;
//    cin >> a;


//    while(a=! 'S'| a=! 's'| a=! 'A'| a=! 'a'| a=! 'P'| a=! 'p');

//    if(a == 'S'|a == 's'){
//        char sin[7];
//        cout << "Please enter your SIN" << endl;
//        cin << sin;
//        //authentication process

//        int b;

//        cout << "Please press the number for the desired task" << endl;
//        cout << "1. Add course" << endl;
//        cout << "2. Drop course" << endl;
//        cout << "3. Add seminar" << endl;
//        cout << "4. Drop seminar" << endl;
//        cout << "5. Add final degree project" << endl;
//        cout << "6. Drop final degree project" << endl;
//        cin >> b;
//        while(b=! 1 | b=! 2| b=! 3| b=! 4| b=! 5| b=! 6);




//    }



//    if(a == 'P'|a == 'p'){
//        char pic[7];
//        cout << "Please enter your PIC" << endl;
//        cin << pic;
//        //authentication process

//        int b;

//        cout << "Please press the number for the desired task" << endl;
//        cout << "1. Modify a course" << endl;
//        cout << "2. Modify a seminar" << endl;
//        cout << "3. Modify a project" << endl;
//        cout << "4. Set marks for a course" << endl;

//        cin >> b;
//        while(b=! 1 | b=! 2| b=! 3| b=! 4);

//    }



//    if(a == 'A'|a == 'a'){
//        char pic[7];
//        cout << "Please enter your PIC" << endl;
//        cin << pic;
//        //authentication process

//        int b;

//        cout << "Please press the number for the desired task" << endl;
//        cout << "1. Add course" << endl;
//        cout << "2. Modify course" << endl;
//        cout << "3. Delete courser" << endl;
//        cout << "4. Add seminar" << endl;
//        cout << "5. Modify seminar" << endl;
//        cout << "6. Delete seminar" << endl;
//        cout << "7. Add final degree project" << endl;
//        cout << "8. Modify final degree project" << endl;
//        cout << "9. Delete final degree project" << endl;
//        cout << "10. Add student" << endl;
//        cout << "11. Modify student" << endl;
//        cout << "12. Delete student" << endl;
//        cout << "13. Add professor" << endl;
//        cout << "14. Modify professor" << endl;
//        cout << "15. Delete professor" << endl;
//        cout << "16. Add admin" << endl;
//        cout << "17. Modify admin" << endl;
//        cout << "18. Delete admin" << endl;
//        cin >> b;
//        while(b=! 1 || b=! 2 || b=! 3 || b=! 4 || b=! 5 || b=! 6 || b=! 7 || b=! 8| b=! 9| b=! 10| b=! 11| b=! 12| b=! 13 | b=! 14| b=! 15| b=! 16| b=! 17| b=! 18);

//    }





/* Default constructor*/
VirtualCampus::VirtualCampus(){

}


/* Destructor */

VirtualCampus::~VirtualCampus(){
}

//Starting the application by logging in.
int VirtualCampus::start() {

	int switched = 3;
	fstream data("login.txt");
	if (data.is_open()) {
		cout << "Welcome to the Virtual Campus of UC3M. Please log in in order to start." << endl;
		bool login = false;
		while (login == false) {
			data.seekg(0, ios::beg);
			string loginname;
			string loginpassword;
			string foundname;
			string line;
			string search1 = "Administrator";
			string search2 = "Professor";
			string search3 = "Student";
			//Giving the login credentials
			cout << endl << "Please fill in your name (Use officialadmin as default version)" << endl;
			cin >> loginname;
			cout << endl << "Please fill in your password (Use password as default version)" << endl;
			cin >> loginpassword;
			size_t pos;
			while (data >> line) {
				//Look if both the name is in the list and if the password is correct
				pos = line.find(loginname);
				if (pos != string::npos) {
					size_t pos2;
					pos2 = line.find(loginpassword);
					if (pos2 != string::npos) {
						size_t pos3;
						size_t pos4;
						size_t pos5;
						cout << "Welcome, you are logged in." << endl;
							//Giving a value to each user stating what kind of user they are
							pos3 = line.find(search1);
							pos4 = line.find(search2);
							pos5 = line.find(search3);
							if (pos3 != string::npos) { cout << "You are identified as an administrator." << endl; switched = 1; }
							if (pos4 != string::npos) { cout << "You are identified as a professor." << endl; switched = 2; }
							if (pos5 != string::npos) { cout << "You are identified as a student." << endl; switched = 3; }
							if (pos3 == string::npos && pos4 == string::npos && pos5 == string::npos) { cout << "Your identity couldn't be determined, so it is assumed you are a student." << endl; switched = 3; }
							login = true;
							//Giving the user the possibility to change their password
							cout << "Do you want to change your password? y/n." << endl;
							char ans;
							cin >> ans;
							if (ans == 'y' || ans == 'Y') {
								fstream temp("temp.txt");
								if (temp.is_open()) {
									string temppass;
									data.seekg(0, ios::beg);
									while (data >> temppass) {
										size_t pos7 = temppass.find(loginpassword);
										size_t len = loginpassword.length();
										if (pos7 != string::npos) {
											cout << endl << "Please give the new password." << endl;
											string newpassword;
											cin >> newpassword;
											temppass.replace(pos7, len, newpassword);
										}
										temppass += "/n";
										temp << temppass;
										rename("temp.txt", "data.txt");
										temp.close();
									}
									cout << "Your new password is set." << endl;
								}
								else { cout << "Currently you cannot change your password." << endl; }
								data.close();
								cout << "Now you start any activity." << endl;
								vc.StartActivities();
//								return { switched };
							}
							else {
								cout << "Okay sure, you can now start any activity." << endl;
								data.close();
								vc.StartActivities();
//								return { switched };
							}
					}
					else {
						cout << "Sorry, wrong password" << endl;
						break;
					}

				}
				if(data.eof()-1) {
					cout << "Sorry this name is not in our list" << endl;
					break;
				}
			}
		}
	}
	else { cout << "Sorry the Virtual Campus was unable to get the data. Please start the program again in order to log in." << endl; }

	cout << "Okay, you're logged out now and the program will close." << endl;
	return { switched };
}

//Give the user the available options he is allowed to do
void VirtualCampus::StartActivities(int switched) {
	cout << "Please provide your pid or sin" << endl;
	char *id = new char[7];
	cin >> id;
	bool continueing = true;
	while (continueing == true) {
			int choice;
			int choice2;
			switch (switched) {

				// Admin's choices
			case 1: cout << endl << "What do you want to do ? " << endl << endl << "1. Create, modify or delete users." << endl << "2. Create, modify or delete resources." << endl << "3. Show information of users." << endl << "4. Show information of resources." << endl << "5. Close the program." << endl;
				cin >> choice;
				switch (choice) {
				case 1: cout << endl << "What do you want to do ? " << endl << endl << "1. Create users." << endl << "2. Modify users." << endl << "3. Delete users." << endl;
					cin >> choice2;
					switch (choice2) {
					case 1: cout << "Here you can create users" << endl;
						userobj.createu();
						break;
					case 2: cout << "Here you can modify users" << endl;
						userobj.modifyu();
						break;
					case 3: cout << "Here you can delete users" << endl;
						userobj.deleteu();
						break;
					}
					break;
				case 2: cout << endl << "What do you want to do ? " << endl << endl << "1. Create resources." << endl << "2. Modify resources." << endl << "3. Delete resources." << endl;
					cin >> choice2;
					switch (choice2) {
					case 1: cout << "Here you can create resources" << endl;
						userobj.creater();
						break;
					case 2: cout << "Here you can modify resources" << endl;
						userobj.modifyr();
						break;
					case 3: cout << "Here you can delete resources" << endl;
						userobj.deleter();
						break;
					}
					break;
				case 3: cout << endl << "What do you want to do ? " << endl << endl << "1. Show information of an administrator." << endl << "2. Show information of a professor." << endl << "3. Show information of a student." << endl;
					cin >> choice2;
					switch (choice2) {
					case 1: cout << "Here you can see information of administrators" << endl;
						vc.BeginAction("admins.csv");
						break;
					case 2: cout << "Here you can see information of professors" << endl;
						vc.BeginAction("professors.csv");
						break;
					case 3: cout << "Here you can see information of students" << endl;
						vc.BeginAction("students.csv");
						break;
					}
					break;
				case 4: cout << endl << "What do you want to do ? " << endl << endl << "1. Show information of a course." << endl << "2. Show information of a project." << endl << "3. Show information of a seminar." << endl;
					cin >> choice2;
					switch (choice2) {
					case 1: cout << "Here you can see information of a course" << endl;
						vc.BeginAction("courses.csv");
						break;
					case 2: cout << "Here you can see information of a project" << endl;
						vc.BeginAction("projects.csv");
						break;
					case 3: cout << "Here you can see information of a seminar" << endl;
						vc.BeginAction("seminars.csv");
						break;
					}
					break;
				case 5: cout << endl << "Okay, we will close the program." << endl;
					continueing = false;
					break;
				}
				break;


				//Professor's choices
			case 2: 						
				cout << endl << "What do you want to do ? " << endl << endl << "1. Modify your own resources." << endl << "2. Grade students." << endl << "3. Show information of users." << endl << "4. Show information of resources." << endl << "5. Close the program." << endl;
				cin >> choice;
				switch (choice) {
				case 1: cout << endl << "What do you want to do ? " << endl << endl << "1. Modify courses." << endl << "2. Modify projects." << endl << "3. Modify seminars." << endl;
					cin >> choice2;
					switch (choice2) {
					case 1: cout << "Here you can modify courses" << endl;
						userobj.modifyc;
						break;
					case 2: cout << "Here you can modify projects" << endl;
						userobj.modifyp;
						break;
					case 3: cout << "Here you can modify seminars" << endl;
						userobj.modifys;
						break;
					}
					break;
				case 2: cout << endl << "Here you can set grades. " << endl;
					userobj.setmarks();
					break;

				case 3: cout << endl << "What do you want to do ? " << endl << endl << "1. Show information of an administrator." << endl << "2. Show information of a professor." << endl << "3. Show information of a student." << endl;
					cin >> choice2;
					switch (choice2) {
					case 1: cout << "Here you can see information of administrators" << endl;
						vc.BeginAction("admins.csv");
						break;
					case 2: cout << "Here you can see information of professors" << endl;
						vc.BeginAction("professors.csv");
						break;
					case 3: cout << "Here you can see information of students" << endl;
						vc.BeginAction("students.csv");
						break;
					}
					break;
				case 4: cout << endl << "What do you want to do ? " << endl << endl << "1. Show information of a course." << endl << "2. Show information of a project." << endl << "3. Show information of a seminar." << endl;
					cin >> choice2;
					switch (choice2) {
					case 1: cout << "Here you can see information of a course" << endl;
						vc.BeginAction("courses.csv");
						break;
					case 2: cout << "Here you can see information of a project" << endl;
						vc.BeginAction("projects.csv");
						break;
					case 3: cout << "Here you can see information of a seminar" << endl;
						vc.BeginAction("seminars.csv");
						break;
					}
					break;
				case 5: cout << endl << "Okay, we will close the program." << endl;
					continueing = false;
					break;
				}
				break;


				//Student's choices
			case 3: 				
				cout << endl << "What do you want to do ? " << endl << endl << "1. Enroll and drop resources." << endl << "2. Show information of users." << endl << "3. Show information of resources." << endl << "4. Close the program." << endl;
				cin >> choice;

				switch (choice) {
				case 1: cout << endl << "What do you want to do ? " << endl << endl << "1. Enroll or drop a course." << endl << "2. Enroll or drop a seminar." << endl << "3. Enroll or drop a final degree project" << endl;
					cin >> choice2;
					switch (choice2) {
					case 1: cout << "Here you can enroll or drop a course" << endl;
						userobj.Studentactionsc();
						break;
					case 2: cout << "Here you can enroll or drop a seminar" << endl;
						userobj.Studentactionss();
						break;
					case 3: cout << "Here you can enroll or drop a final degree project" << endl;
						userobj.Studentactionsp();
						break;
					}
					break;
				case 2: cout << endl << "What do you want to do ? " << endl << endl << "1. Show information of an administrator." << endl << "2. Show information of a professor." << endl << "3. Show information of a student." << endl;
					cin >> choice2;
					switch (choice2) {
					case 1: cout << "Here you can see information of administrators" << endl;
						vc.BeginAction("administrators.csv");
						break;
					case 2: cout << "Here you can see information of professors" << endl;
						vc.BeginAction("professors.csv");
						break;
					case 3: cout << "Here you can see information of students" << endl;
						vc.BeginAction("students.csv");
						break;
					}
					break;
				case 3: cout << endl << "What do you want to do ? " << endl << endl << "1. Show information of a course." << endl << "2. Show information of a project." << endl << "3. Show information of a seminar." << endl;
					cin >> choice2;
					switch (choice2) {
					case 1: cout << "Here you can see information of a course" << endl;
						vc.BeginAction("courses.csv");
						break;
					case 2: cout << "Here you can see information of a project" << endl;
						vc.BeginAction("projects.csv");
						break;
					case 3: cout << "Here you can see information of a seminar" << endl;
						vc.BeginAction("seminars.csv");
						break;
					}
					break;
				case 4: cout << endl << "Okay, we will close the program." << endl;
					continueing = false;
					break;
				}
				break;
			}
	}
	return;
}


//start displaying the users or resources
void VirtualCampus::BeginAction(string files) {
	ifstream data(files);
	if (data.is_open()) {
		data.seekg(0, ios::beg);
		cout << "What is the PID/SIN of the user or ID of the resource you are looking for? Say \"all\" if you want to see everything from a specific type of users or resources." << endl;
		string searchobj;
		cin >> searchobj;
		size_t pos;
		string line;
		int linecount = 0;
		if (searchobj == "all") {
			data.seekg(0, ios::beg);
			while (data >> line) {
				string output;
				output = line;
				linecount += 1;
				cout << "number " << linecount << ": " << output << endl << endl;
			}
		}
		else {
			bool found = false;
			while (data >> line) {
				pos = line.find(searchobj);
				if (pos != string::npos) {
					string output;
					output = line;
					cout << output << endl;
					found = true;
					// OR show all of the objects in this particular class by looking at the string files what type it is and then make objects of this type and use  searchedobject.display()
				}
			}
			if (found == false) { cout << "Sorry, this person or resource cannot be found." << endl; }
		}
	}
	else { cout << "Sorry the Virtual Campus was unable to get the data. Please try again." << endl; }
	return 0;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////



string Resources::getstatus() {
    return status;
}


char* Resources::getid() {
    return id;
}

void Resources::setstatus(string new_status) {
    if(new_status == "created" || new_status == "in progress" || new_status == "completed"){
        status = new_status;

    }
    else{
        cout << "wrong format for status" << endl;
    }

}
void Resources::setid(char new_id[7]) {


    if(isalpha(new_id[0]) && isalpha(new_id[1]) && isalpha(new_id[2]) && isdigit(new_id[3]) && isdigit(new_id[4]) && isdigit(new_id[5]) && isdigit(new_id[6])){
        for(int i = 0; i < 7; i++){
            id[i] = new_id[i];

        }

    }

    else{
        cout << "wrong format for id" << endl;
    }

}

/* Default constructor*/
Resources::Resources(){
    status = "created";
    id[0] = 'a';
    id[1] = 'a';
    id[2] = 'a';
    id[3] = '0';
    id[4] = '0';
    id[5] = '0';
    id[6] = '0';
    id[7] = '\0';
}

/* aaa0000 is a dummy id */

/* Parametrized constructor*/

Resources::Resources(string _status, char _id[7]){
    if(_status == "created" || "in progress" || "completed"){
        status = _status;

    }
    else{
        cout << "wrong format for status" << endl;
    }


    if(isalpha(_id[0]) && isalpha(_id[1]) && isalpha(_id[2]) && isdigit(_id[3]) && isdigit(_id[4]) && isdigit(_id[5]) && isdigit(_id[6])){

        for(int i = 0; i < 7; i++){
            id[i] = _id[i];

        }
    }


    else{
        cout << "wrong format for id" << endl;
    }

}

///* Copy constructor*/

//Resources::Resources(const Resources & R){
//    status = R.status;
//    for(int i = 0; i < 7; i++){
//        id[i] = R.id[i];

//    }
//}

/* Destructor */

Resources::~Resources(){
}



////////////////////////////////////
//
////////////////////////////////////


Professor* Seminars::getcoordinator() {
    return coordinator;
}


Professor *Seminars::getspeaker() {
    return speaker;
}

string Seminars::getdate() {
    return date;
}

int Seminars::getmax_seats() {
    return max_seats;
}

vector < Student > Seminars::getlist_students() {
    return list_students;
}


void Seminars::setcoordinator(Professor* new_coordinator) {
    coordinator = new_coordinator;
}


void Seminars::setspeaker(Professor *new_speaker) {
    speaker = new_speaker;
}

void Seminars::setdate(string new_date) {
    date = new_date;
}

void Seminars::setmax_seats(int new_max_seats) {
    max_seats = new_max_seats;
}


void Seminars::setlist_students(vector<Student> new_list_students) {
    list_students = new_list_students;


}



/* Default constructor*/
Seminars::Seminars():Resources(){
    Professor a,b;
    //Student s;
    *coordinator = a;
    *speaker = b;
    date = "no date";
    max_seats = -1;
}

/* -1 is a dummy number of max_seats */

/* Parametrized constructor*/

/* Here _list_students_s is a dynamic array of length "_size" */


Seminars::Seminars(string _status, char _id[7], Professor* _coordinator, Professor* _speaker, string _date, int _max_seats, vector < Student > _list_students) : Resources(_status, _id){
    coordinator = _coordinator;
    speaker = _speaker;
    date = _date;
    max_seats = _max_seats;
    list_students = _list_students;

}

/* Copy constructor*/

//Seminars::Seminars(const Seminars & S){
//    coordinator = S.coordinator;
//    speaker = S.speaker;
//    date = S.date;
//    max_seats = S.max_seats;
//    size = S.size;
//    list_students_s = new string[size];
//    list_students_s = S.list_students_s;
//}

/* Destructor */

Seminars::~Seminars(){

}

void Seminars::display() {
	cout << "Status:" << status << ". ID: " << id[7] << ". Coordinator: " << coordinator << ". Speaker: " << speaker << ". Date: " << date << "Maximum number of seats: " << max_seats << " And the size is: " << size << "." << endl;
	cout << "A list of students is: " << list_students << endl;
}


////////////////////////////////////
//
////////////////////////////////////

Professor *Project::gettutor() {
    return tutor;
}


Professor *Project::getco_tutor() {
    return co_tutor;
}

Student *Project::getstudent() {
    return student;
}

string Project::getdegree() {
    return degree;
}

void Project::settutor(Professor *new_tutor) {
    tutor = new_tutor;
}


void Project::setstudent(Student* new_student) {
    student = new_student;
}

void Project::setdegree(string new_degree){
    degree = new_degree;
}


/* Default constructor*/

Project::Project() : Resources() {
    Professor p,b;
    Student s;
    tutor = &p;
    student = &s ;
    co_tutor = &b ;
    degree = "not assigned";
}



/* Parametrized constructor*/

Project::Project(string _status, char _id[7], Professor* _tutor, Professor* _co_tutor, Student* _student, string _degree) : Resources(_status, _id){
    tutor = _tutor;
    student = _student;
    co_tutor = _co_tutor;
    degree = _degree;
}

/* Copy constructor*/

//Project::Project(const Project & P){
//    tutor = P.tutor;
//    co_tutor_presence = P.co_tutor_presence;
//    co_tutor = P.co_tutor;
//}

/* Destructor */

Project::~Project(){
}

void Projects::display() {
cout << "Status:" << status << ". ID: " << id[7] << ". Tutor: " << tutor << "1. Student: " << student;
if (co_tutor_presence == 1 || co_tutor_presence == true) {
	cout << ". Co_tutor: " << co_tutor << "." << endl;
}
}

////////////////////////////////////
//
////////////////////////////////////


int Courses::getcredits() {
	return credits;
}

vector<Student> Courses::getlist_students() {
	return list_students;
}

vector<float> Courses::getlist_marks() {
	for (int i = 0; i < list_marks.getsize(); ++i) {
		return list_marks[i];
	}
}

Professor* Courses::getprofessors() {
	return professors;
}


string Courses::getdegree() {
	return degree;
}


void Courses::setcredits(int new_credits) {
	credits = new_credits;
}

/* Here new_list_students is a dynamic array of length "new_size_students" */

void Courses::setlist_students(vector<Student> new_list_students) {
	list_students = new_list_students;

}


void Courses::setlist_marks(vector<float> new_list_marks) {
	list_marks = new_list_marks;
}


void Courses::setprofessors(Professor *new_professors) {
	*professors = *new_professors;
	*(professors + 1) = *(new_professors + 1);
}


/* Default constructor*/
Courses::Courses() :Resources() {
	credits = 0;
	Professor a, b;
	*professors = a;
	*(professors + 1) = b;
	degree = "not assigned";

}

/* Parametrized constructor*/

Courses::Courses(string _status, char _id[7], int _credits, vector < Student > _list_students, vector < float > _list_marks, string _degree, Professor* _professors) : Resources(_status, _id) {
	credits = _credits;

	list_students = _list_students;
	list_marks = _list_marks;
	degree = _degree;
	*professors = *_professors;
	*(professors + 1) = *(_professors + 1);

}

/* Copy constructor*/

//		Courses::Courses(const Courses & C){
//			credits = C.credits;
//			size_students = C.size_students;
//			list_students = new string[size_students];
//			list_students = C.list_students;
//			size_marks = C.size_marks;
//			list_marks = new float[size_marks];
//			list_marks = C.list_marks;
//			for(int i = 0; i < 7; i++){
//				resource->id[i] = C.resource->id[i];
//
//			}
//
//			resource->status = C.resource->status;
//
//		}

/* Destructor */

Courses::~Courses(){
//    Resources::~Resources();
}

void Courses::display() {
	cout << "Status:" << status << ". ID: " << id[7] << ". And the number of credits: " << credits << "." << endl;
	cout << "A list of students is: " << list_students << endl;
	cout << "A list of marks is: " << list_marks << endl;
	cout << "The degree it belongs to is: " << degree << endl;
	cout << "The professor(s) that give(s) this course are/is: " << professors << endl;
	if (list_students.getsize() == list_marks.getsize()) {
		for (int i = 0; i < list_students.getsize(); ++i) {
			cout << "The name of student number " << i << "is: " list_students[i] << "And the corresponding mark is: " << list_marks[i] << endl;
		}
	else cout << "The number of students did not match with the number of marks."
	}
}


////////////////////////////////////
//
////////////////////////////////////

//		string Degree::getdegree() {
//			return degree;
//		}
//
//		void Degree::setdegree(string new_degree) {
//			degree = new_degree;
//		}
//
//
//		/* Default constructor*/
//		Degree::Degree(){
//			degree = "no degree";
//		}
//
//		/* Parametrized constructor*/
//
//		Degree::Degree(string _degree){
//			degree = _degree;
//		}
//
//		/* Copy constructor*/
//
//		Degree::Degree(const Degree & D){
//			degree = D.degree;
//
//		}
//
//		/* Destructor */
//
//		Degree::~Degree(){
//		}
//		*/



string Users::getname() {
    return name;
}

string Users::gettype() {
	return type;
}


void Users::setname(string new_name) {
    name = new_name;
}

void Users::settype(string new_type) {
	if (new_type == "student" || new_type == "professor" || new_type == "admin") {
		type = new_type;
	}
	else cout << "wrong type format" << endl;
}

/* Default constructor*/
Users::Users(){
    name = "no name";
	type = "no type";
}


/* Parametrized constructor*/

Users::Users(string _name, string _type){
    name = _name;
	type = _type;
}

/* Copy constructor*/

//		Users::Users(const Users & U){
//			name = U.name;
//			type = U.type;
//		}

/* Destructor */

Users::~Users(){
}

////////////////////////////////////
//
////////////////////////////////////




char* Admin::getpid() {
    return pid;
}

void Admin::setpid(char new_pid[7]) {
    for(int i = 0; i < 7; i++){
        pid[i] = new_pid[i];

    }
}


/* Default constructor*/
Admin::Admin(){
    pid[0] = 'a';
    pid[1] = 'a';
    pid[2] = 'a';
    pid[3] = 'a';
    pid[4] = 'a';
    pid[5] = 'a';
    pid[6] = 'a';
    pid[7] = '\0';


    /* Here it is assumed that the default value of pid is "aaaaaaa" */
}


/* Parametrized constructor*/

Admin::Admin(string _name, string _type, char _pid[7]) :Users(_name, _type) {
	if (_type == "admin") {
		for (int i = 0; i < 7; i++) {
			pid[i] = _pid[i];
		}
	}
	else cout << "wrong type specified" << endl;
}

/* Copy constructor*/

//		Admin::Admin(const Admin & A){
//			for(int i = 0; i < 7; i++){
//				pid[i] = A.pid[i];
//
//			}
//		}

/* Destructor */

Admin::~Admin(){
}


void Admin::createc(Courses& _course, int _credits, string* _list_students, float* _list_marks, int _size_students, int _size_marks, char new_id[7], string new_status ){

   _course.setcredits(_credits);
   _course.setsize_students(_size_students);
   _course.setsize_marks(_size_marks);
   _course.setlist_students(_list_students, _size_students);
   _course.setlist_marks(_list_marks, _size_marks);
   _course.resource->setid(new_id);
   _course.resource->setstatus(new_status);

}



void Admin::createu() {

	/*For names and degrees, use underscore for separating or only put first names; no spaces condition*/
	string name_user;
	char identity_type = '0';
	cout << endl << "Please fill the name of the new user." << endl;
	cin >> name_user;
	cout << endl << "Please press the alphabet corresponding to their identity (a-Administrator, s-Student, p-Professor)" << endl;
	cin >> identity_type;
	while (identity_type != 'a' && identity_type != 'A' && identity_type != 's' && identity_type != 'S' && identity_type != 'p' && identity_type != 'P') {
		cin >> identity_type;
	}

	if (identity_type == 's' || identity_type == 'S') {


		fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv", ios::out | ios::app);
		if (data.is_open()) {
			Student *newuser = new Student;

			newuser->setname(name_user);
			cout << "Give the SIN of this person." << endl;
			char newpid[7];
			cin >> newpid;
			newuser->setsin(newpid);

			cout << "Give degree of this student." << endl;
			string degree;
			cin >> degree;
			newuser->setdegree(degree);
			cout << newuser->getname() << "," << newuser->getsin() << "," << newuser->getdegree() << " has been added" << endl;
			data << newuser->getname() << "," << newuser->getsin() << "," << newuser->getdegree() << "\n";
			data.close();
			delete newuser;
		}
		else { cout << "Sorry the Virtual Campus was unable to add data. Please start the program again in order to try again." << endl; }
	}

	if (identity_type == 'a' || identity_type == 'A') {
		fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/admins.csv", ios::out | ios::app);
		if (data.is_open()) {
			Admin *newuser = new Admin;
			newuser->setname(name_user);
			cout << "Give the PID of this person." << endl;
			char newpid[7];
			cin >> newpid;
			newuser->setpid(newpid);

			cout << newuser->getname() << "," << newuser->getpid() << " has been added" << endl;

			data << newuser->getname() << "," << newuser->getpid() << "\n";
			data.close();

			delete newuser;
		}
		else { cout << "Sorry the Virtual Campus was unable to add data. Please start the program again in order to try again." << endl; }
	}


	if (identity_type == 'p' || identity_type == 'P') {
		fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/professors.csv", ios::out | ios::app);
		if (data.is_open()) {

			Professor *newuser = new Professor;
			newuser->setname(name_user);
			cout << "Give the PID of this person." << endl;
			char new2pid[7];
			cin >> new2pid;

			newuser->setpid(new2pid);

			cout << newuser->getname() << "," << newuser->getpid() << " has been added" << endl;
			data << newuser->getname() << "," << newuser->getpid() << "\n";
			data.close();
			delete newuser;
		}
		else { cout << "Sorry the Virtual Campus was unable to add data. Please start the program again in order to try again." << endl; }
	}
}


void Admin::modifyu() {

	char identity_type;
	char change_type;
	int line_n;
	cout << endl << "Please press the alphabet corresponding to the identity of the user to be modified (a-Administrator, s-Student, p-Professor)" << endl;
	cin >> identity_type;
	while (identity_type != 'a' && identity_type != 'A' && identity_type != 's' && identity_type != 'S' && identity_type != 'p' && identity_type != 'P') {
		cin >> identity_type;
	}
	char pid[7];


	if (identity_type == 's' || identity_type == 'S') {

		cout << endl << "Please provide the SIN of the user to be modified." << endl;
		cin >> pid;

		string name_obj;
		string id_obj;
		string deg_obj;
		vector <string> name_ob;
		vector <string> id_ob;
		vector <string> degrees;
		int i = 0;

		ifstream Myfile;
		Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv");

		while (Myfile.good()) {
			getline(Myfile, name_obj, ',');

			bool h = Myfile.good();
			if (h) {

				i++;
				name_ob.push_back(name_obj);
				getline(Myfile, id_obj, ',');
				id_ob.push_back(id_obj);
				getline(Myfile, deg_obj, '\n');
				degrees.push_back(deg_obj);
			}
		}


		int count = 0;
		for (size_t j = 0; j < id_ob.size(); j++) {
			if (id_ob[j].find(pid) != string::npos) {
				line_n = j;
				count++;
			}
		}



		if (count == 0) {
			cout << "Sorry that id number is not registered in the database." << endl;
			return;
		}

		Student *newuser = new Student;
		cout << "Please press : n - for changing name, i - for changing sin, d - for changing degree" << endl;
		cin >> change_type;
		while (change_type != 'n' && change_type != 'N' && change_type != 'i' && change_type != 'I' && change_type != 'd' && change_type != 'D') {
			cin >> change_type;
		}

		if (change_type == 'n' || identity_type == 'N') {
			string newname;
			cout << "Give the new name for user." << endl;
			cin >> newname;
			newuser->setname(newname);
			name_ob[line_n] = newuser->getname();
		}


		if (change_type == 'i' || identity_type == 'I') {

			char newsin[7];
			cout << "Give the new SIN for user." << endl;
			cin >> newsin;
			newuser->setsin(newsin);
			id_ob[line_n] = newuser->getsin();
		}


		if (change_type == 'd' || identity_type == 'D') {
			string newdegree;
			cout << "Give the new degree for user." << endl;
			cin >> newdegree;
			newuser->setdegree(newdegree);

			degrees[line_n] = newuser->getdegree();
		}

		fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv", ios::out | ios::trunc);
		if (data.is_open()) {
			for (size_t j = 0; j < name_ob.size(); j++) {
				data << name_ob[j] << "," << id_ob[j] << "," << degrees[j] << "\n";
			}
			data.close();
			cout << "user modified." << endl;
		}
		delete newuser;
	}




	if (identity_type == 'p' || identity_type == 'P') {
		cout << endl << "Please provide the PID of the user to be modified." << endl;
		cin >> pid;

		string name_obj;
		string id_obj;
		vector <string> name_ob;
		vector <string> id_ob;

		int i = 0;
		ifstream Myfile;
		Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/professors.csv");

		while (Myfile.good()) {
			getline(Myfile, name_obj, ',');
			bool h = Myfile.good();
			if (h) {
				i++;
				name_ob.push_back(name_obj);
				getline(Myfile, id_obj, '\n');
				id_ob.push_back(id_obj);
			}
		}


		int count = 0;
		for (size_t j = 0; j < id_ob.size(); j++) {
			if (id_ob[j].find(pid) != string::npos) {
				line_n = j;
				count++;
			}
		}


		if (count == 0) {
			cout << "Sorry that id number is not registered in the database." << endl;
			return;
		}

		Professor *newuser = new Professor;

		cout << "Please press : n - for changing name, i - for changing pid" << endl;
		cin >> change_type;
		while (change_type != 'n' && change_type != 'N' && change_type != 'i' && change_type != 'I') {
			cin >> change_type;
		}

		if (change_type == 'n' || identity_type == 'N') {
			string newname;
			cout << "Give the new name for user." << endl;
			cin >> newname;
			newuser->setname(newname);
			name_ob[line_n] = newuser->getname();
		}


		if (change_type == 'i' || identity_type == 'I') {
			char newpid[7];
			cout << "Give the new PID for user." << endl;
			cin >> newpid;
			newuser->setpid(newpid);
			id_ob[line_n] = newuser->getpid();
		}


		fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/professors.csv", ios::out | ios::trunc);
		if (data.is_open()) {
			for (size_t j = 0; j < name_ob.size(); j++) {
				data << name_ob[j] << "," << id_ob[j] << "\n";
			}
			data.close();
			cout << "user modified." << endl;
		}
		delete newuser;
	}




	if (identity_type == 'a' || identity_type == 'A') {
		cout << endl << "Please provide the PID of the user to be modified." << endl;
		cin >> pid;

		string name_obj;
		string id_obj;
		vector <string> name_ob;
		vector <string> id_ob;

		int i = 0;

		ifstream Myfile;
		Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/admins.csv");

		while (Myfile.good()) {
			getline(Myfile, name_obj, ',');
			bool h = Myfile.good();
			if (h) {
				i++;
				name_ob.push_back(name_obj);
				getline(Myfile, id_obj, '\n');
				id_ob.push_back(id_obj);
			}
		}


		int count = 0;
		for (size_t j = 0; j < id_ob.size(); j++) {
			if (id_ob[j].find(pid) != string::npos) {
				line_n = j;
				count++;
			}
		}



		if (count == 0) {
			cout << "Sorry that id number is not registered in the database." << endl;
			return;
		}

		Admin *newuser = new Admin;

		cout << "Please press : n - for changing name, i - for changing pid" << endl;
		cin >> change_type;
		while (change_type != 'n' && change_type != 'N' && change_type != 'i' && change_type != 'I') {
			cin >> change_type;
		}

		if (change_type == 'n' || identity_type == 'N') {
			string newname;
			cout << "Give the new name for user." << endl;
			cin >> newname;
			newuser->setname(newname);
			name_ob[line_n] = newuser->getname();
		}

		if (change_type == 'i' || identity_type == 'I') {
			char newpid[7];
			cout << "Give the new PID for user." << endl;
			cin >> newpid;
			newuser->setpid(newpid);
			id_ob[line_n] = newuser->getpid();
		}


		fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/admins.csv", ios::out | ios::trunc);
		if (data.is_open()) {
			for (size_t j = 0; j < name_ob.size(); j++) {
				data << name_ob[j] << "," << id_ob[j] << "\n";
			}
			data.close();
			cout << "user modified." << endl;
		}
		delete newuser;
	}
}



void Admin::deleteu() {

	char identity_type;
	int line_n;

	cout << endl << "Please press the alphabet corresponding to the identity of the user to be deleted (a-Administrator, s-Student, p-Professor)" << endl;
	cin >> identity_type;
	while (identity_type != 'a' && identity_type != 'A' && identity_type != 's' && identity_type != 'S' && identity_type != 'p' && identity_type != 'P') {
		cin >> identity_type;
	}

	char pid[7];

	if (identity_type == 's' || identity_type == 'S') {
		cout << endl << "Please provide the SIN of the user to be deleted." << endl;
		cin >> pid;

		string name_obj;
		string id_obj;
		string deg_obj;
		vector <string> name_ob;
		vector <string> id_ob;
		vector <string> degrees;
		int i = 0;

		ifstream Myfile;
		Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv");

		while (Myfile.good()) {
			getline(Myfile, name_obj, ',');
			bool h = Myfile.good();
			if (h) {
				i++;
				name_ob.push_back(name_obj);

				getline(Myfile, id_obj, ',');
				id_ob.push_back(id_obj);
				getline(Myfile, deg_obj, '\n');
				degrees.push_back(deg_obj);
			}
		}


		int count = 0;
		for (size_t j = 0; j < id_ob.size(); j++) {
			if (id_ob[j].find(pid) != string::npos) {
				line_n = j;
				count++;
			}
		}

		if (count == 0) {
			cout << "Sorry that id number is not registered in the database." << endl;
			return;
		}

		name_ob.erase(name_ob.begin() + line_n);
		id_ob.erase(id_ob.begin() + line_n);
		degrees.erase(degrees.begin() + line_n);


		fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv", ios::out | ios::trunc);
		if (data.is_open()) {
			for (size_t j = 0; j < name_ob.size(); j++) {
				data << name_ob[j] << "," << id_ob[j] << "," << degrees[j] << "\n";
			}
			data.close();
			cout << "user deleted." << endl;
		}
	}


	if (identity_type == 'p' || identity_type == 'P') {
		cout << endl << "Please provide the PID of the user to be deleted." << endl;
		cin >> pid;

		string name_obj;
		string id_obj;
		vector <string> name_ob;
		vector <string> id_ob;

		int i = 0;

		ifstream Myfile;
		Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/professors.csv");

		while (Myfile.good()) {
			getline(Myfile, name_obj, ',');
			bool h = Myfile.good();
			if (h) {
				i++;
				name_ob.push_back(name_obj);
				getline(Myfile, id_obj, '\n');
				id_ob.push_back(id_obj);
			}
		}


		int count = 0;
		for (size_t j = 0; j < id_ob.size(); j++) {
			if (id_ob[j].find(pid) != string::npos) {
				line_n = j;
				count++;
			}
		}



		if (count == 0) {
			cout << "Sorry that id number is not registered in the database." << endl;
			return;
		}

		name_ob.erase(name_ob.begin() + line_n);
		id_ob.erase(id_ob.begin() + line_n);

		fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/professors.csv", ios::out | ios::trunc);
		if (data.is_open()) {
			for (size_t j = 0; j < name_ob.size(); j++) {
				data << name_ob[j] << "," << id_ob[j] << "\n";
			}
			data.close();
			cout << "user deleted." << endl;
		}
	}

	if (identity_type == 'a' || identity_type == 'A') {

		cout << endl << "Please provide the PID of the user to be deleted." << endl;
		cin >> pid;

		string name_obj;
		string id_obj;
		vector <string> name_ob;
		vector <string> id_ob;

		int i = 0;

		ifstream Myfile;
		Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/admins.csv");

		while (Myfile.good()) {
			getline(Myfile, name_obj, ',');
			bool h = Myfile.good();
			if (h) {
				i++;
				name_ob.push_back(name_obj);
				getline(Myfile, id_obj, '\n');
				id_ob.push_back(id_obj);
			}
		}


		int count = 0;
		for (size_t j = 0; j < id_ob.size(); j++) {
			if (id_ob[j].find(pid) != string::npos) {
				line_n = j;
				count++;
			}
		}

		if (count == 0) {
			cout << "Sorry that id number is not registered in the database." << endl;
			return;
		}
		name_ob.erase(name_ob.begin() + line_n);
		id_ob.erase(id_ob.begin() + line_n);

		fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/admins.csv", ios::out | ios::trunc);
		if (data.is_open()) {
			for (size_t j = 0; j < name_ob.size(); j++) {
				data << name_ob[j] << "," << id_ob[j] << "\n";
			}
			data.close();
			cout << "user deleted." << endl;
		}
	}
}


























void Admin::creater() {

	/*For names and degrees, use underscore for separating or only put first names; no spaces condition*/
	string name_user;
	char identity_type = '0';
	cout << endl << "Please fill the name of the new user." << endl;
	cin >> name_user;
	cout << endl << "Please press the alphabet corresponding to their identity (a-Administrator, s-Student, p-Professor)" << endl;
	cin >> identity_type;
	while (identity_type != 'a' && identity_type != 'A' && identity_type != 's' && identity_type != 'S' && identity_type != 'p' && identity_type != 'P') {
		cin >> identity_type;
	}

	if (identity_type == 's' || identity_type == 'S') {


		fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv", ios::out | ios::app);
		if (data.is_open()) {
			Student *newuser = new Student;

			newuser->setname(name_user);
			cout << "Give the SIN of this person." << endl;
			char newpid[7];
			cin >> newpid;
			newuser->setsin(newpid);

			cout << "Give degree of this student." << endl;
			string degree;
			cin >> degree;
			newuser->setdegree(degree);
			cout << newuser->getname() << "," << newuser->getsin() << "," << newuser->getdegree() << " has been added" << endl;
			data << newuser->getname() << "," << newuser->getsin() << "," << newuser->getdegree() << "\n";
			data.close();
			delete newuser;
		}
		else { cout << "Sorry the Virtual Campus was unable to add data. Please start the program again in order to try again." << endl; }
	}

	if (identity_type == 'a' || identity_type == 'A') {
		fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/admins.csv", ios::out | ios::app);
		if (data.is_open()) {
			Admin *newuser = new Admin;
			newuser->setname(name_user);
			cout << "Give the PID of this person." << endl;
			char newpid[7];
			cin >> newpid;
			newuser->setpid(newpid);

			cout << newuser->getname() << "," << newuser->getpid() << " has been added" << endl;

			data << newuser->getname() << "," << newuser->getpid() << "\n";
			data.close();

			delete newuser;
		}
		else { cout << "Sorry the Virtual Campus was unable to add data. Please start the program again in order to try again." << endl; }
	}


	if (identity_type == 'p' || identity_type == 'P') {
		fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/professors.csv", ios::out | ios::app);
		if (data.is_open()) {

			Professor *newuser = new Professor;
			newuser->setname(name_user);
			cout << "Give the PID of this person." << endl;
			char new2pid[7];
			cin >> new2pid;

			newuser->setpid(new2pid);

			cout << newuser->getname() << "," << newuser->getpid() << " has been added" << endl;
			data << newuser->getname() << "," << newuser->getpid() << "\n";
			data.close();
			delete newuser;
		}
		else { cout << "Sorry the Virtual Campus was unable to add data. Please start the program again in order to try again." << endl; }
	}
}


void Admin::modifyr() {

	char identity_type;
	char change_type;
	int line_n;
	cout << endl << "Please press the alphabet corresponding to the identity of the user to be modified (a-Administrator, s-Student, p-Professor)" << endl;
	cin >> identity_type;
	while (identity_type != 'a' && identity_type != 'A' && identity_type != 's' && identity_type != 'S' && identity_type != 'p' && identity_type != 'P') {
		cin >> identity_type;
	}
	char pid[7];


	if (identity_type == 's' || identity_type == 'S') {

		cout << endl << "Please provide the SIN of the user to be modified." << endl;
		cin >> pid;

		string name_obj;
		string id_obj;
		string deg_obj;
		vector <string> name_ob;
		vector <string> id_ob;
		vector <string> degrees;
		int i = 0;

		ifstream Myfile;
		Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv");

		while (Myfile.good()) {
			getline(Myfile, name_obj, ',');

			bool h = Myfile.good();
			if (h) {

				i++;
				name_ob.push_back(name_obj);
				getline(Myfile, id_obj, ',');
				id_ob.push_back(id_obj);
				getline(Myfile, deg_obj, '\n');
				degrees.push_back(deg_obj);
			}
		}


		int count = 0;
		for (size_t j = 0; j < id_ob.size(); j++) {
			if (id_ob[j].find(pid) != string::npos) {
				line_n = j;
				count++;
			}
		}



		if (count == 0) {
			cout << "Sorry that id number is not registered in the database." << endl;
			return;
		}

		Student *newuser = new Student;
		cout << "Please press : n - for changing name, i - for changing sin, d - for changing degree" << endl;
		cin >> change_type;
		while (change_type != 'n' && change_type != 'N' && change_type != 'i' && change_type != 'I' && change_type != 'd' && change_type != 'D') {
			cin >> change_type;
		}

		if (change_type == 'n' || identity_type == 'N') {
			string newname;
			cout << "Give the new name for user." << endl;
			cin >> newname;
			newuser->setname(newname);
			name_ob[line_n] = newuser->getname();
		}


		if (change_type == 'i' || identity_type == 'I') {

			char newsin[7];
			cout << "Give the new SIN for user." << endl;
			cin >> newsin;
			newuser->setsin(newsin);
			id_ob[line_n] = newuser->getsin();
		}


		if (change_type == 'd' || identity_type == 'D') {
			string newdegree;
			cout << "Give the new degree for user." << endl;
			cin >> newdegree;
			newuser->setdegree(newdegree);

			degrees[line_n] = newuser->getdegree();
		}

		fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv", ios::out | ios::trunc);
		if (data.is_open()) {
			for (size_t j = 0; j < name_ob.size(); j++) {
				data << name_ob[j] << "," << id_ob[j] << "," << degrees[j] << "\n";
			}
			data.close();
			cout << "user modified." << endl;
		}
		delete newuser;
	}




	if (identity_type == 'p' || identity_type == 'P') {
		cout << endl << "Please provide the PID of the user to be modified." << endl;
		cin >> pid;

		string name_obj;
		string id_obj;
		vector <string> name_ob;
		vector <string> id_ob;

		int i = 0;
		ifstream Myfile;
		Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/professors.csv");

		while (Myfile.good()) {
			getline(Myfile, name_obj, ',');
			bool h = Myfile.good();
			if (h) {
				i++;
				name_ob.push_back(name_obj);
				getline(Myfile, id_obj, '\n');
				id_ob.push_back(id_obj);
			}
		}


		int count = 0;
		for (size_t j = 0; j < id_ob.size(); j++) {
			if (id_ob[j].find(pid) != string::npos) {
				line_n = j;
				count++;
			}
		}


		if (count == 0) {
			cout << "Sorry that id number is not registered in the database." << endl;
			return;
		}

		Professor *newuser = new Professor;

		cout << "Please press : n - for changing name, i - for changing pid" << endl;
		cin >> change_type;
		while (change_type != 'n' && change_type != 'N' && change_type != 'i' && change_type != 'I') {
			cin >> change_type;
		}

		if (change_type == 'n' || identity_type == 'N') {
			string newname;
			cout << "Give the new name for user." << endl;
			cin >> newname;
			newuser->setname(newname);
			name_ob[line_n] = newuser->getname();
		}


		if (change_type == 'i' || identity_type == 'I') {
			char newpid[7];
			cout << "Give the new PID for user." << endl;
			cin >> newpid;
			newuser->setpid(newpid);
			id_ob[line_n] = newuser->getpid();
		}


		fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/professors.csv", ios::out | ios::trunc);
		if (data.is_open()) {
			for (size_t j = 0; j < name_ob.size(); j++) {
				data << name_ob[j] << "," << id_ob[j] << "\n";
			}
			data.close();
			cout << "user modified." << endl;
		}
		delete newuser;
	}




	if (identity_type == 'a' || identity_type == 'A') {
		cout << endl << "Please provide the PID of the user to be modified." << endl;
		cin >> pid;

		string name_obj;
		string id_obj;
		vector <string> name_ob;
		vector <string> id_ob;

		int i = 0;

		ifstream Myfile;
		Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/admins.csv");

		while (Myfile.good()) {
			getline(Myfile, name_obj, ',');
			bool h = Myfile.good();
			if (h) {
				i++;
				name_ob.push_back(name_obj);
				getline(Myfile, id_obj, '\n');
				id_ob.push_back(id_obj);
			}
		}


		int count = 0;
		for (size_t j = 0; j < id_ob.size(); j++) {
			if (id_ob[j].find(pid) != string::npos) {
				line_n = j;
				count++;
			}
		}



		if (count == 0) {
			cout << "Sorry that id number is not registered in the database." << endl;
			return;
		}

		Admin *newuser = new Admin;

		cout << "Please press : n - for changing name, i - for changing pid" << endl;
		cin >> change_type;
		while (change_type != 'n' && change_type != 'N' && change_type != 'i' && change_type != 'I') {
			cin >> change_type;
		}

		if (change_type == 'n' || identity_type == 'N') {
			string newname;
			cout << "Give the new name for user." << endl;
			cin >> newname;
			newuser->setname(newname);
			name_ob[line_n] = newuser->getname();
		}

		if (change_type == 'i' || identity_type == 'I') {
			char newpid[7];
			cout << "Give the new PID for user." << endl;
			cin >> newpid;
			newuser->setpid(newpid);
			id_ob[line_n] = newuser->getpid();
		}


		fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/admins.csv", ios::out | ios::trunc);
		if (data.is_open()) {
			for (size_t j = 0; j < name_ob.size(); j++) {
				data << name_ob[j] << "," << id_ob[j] << "\n";
			}
			data.close();
			cout << "user modified." << endl;
		}
		delete newuser;
	}
}



void Admin::deleter() {

	char identity_type;
	int line_n;

	cout << endl << "Please press the alphabet corresponding to the identity of the user to be deleted (a-Administrator, s-Student, p-Professor)" << endl;
	cin >> identity_type;
	while (identity_type != 'a' && identity_type != 'A' && identity_type != 's' && identity_type != 'S' && identity_type != 'p' && identity_type != 'P') {
		cin >> identity_type;
	}

	char pid[7];

	if (identity_type == 's' || identity_type == 'S') {
		cout << endl << "Please provide the SIN of the user to be deleted." << endl;
		cin >> pid;

		string name_obj;
		string id_obj;
		string deg_obj;
		vector <string> name_ob;
		vector <string> id_ob;
		vector <string> degrees;
		int i = 0;

		ifstream Myfile;
		Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv");

		while (Myfile.good()) {
			getline(Myfile, name_obj, ',');
			bool h = Myfile.good();
			if (h) {
				i++;
				name_ob.push_back(name_obj);

				getline(Myfile, id_obj, ',');
				id_ob.push_back(id_obj);
				getline(Myfile, deg_obj, '\n');
				degrees.push_back(deg_obj);
			}
		}


		int count = 0;
		for (size_t j = 0; j < id_ob.size(); j++) {
			if (id_ob[j].find(pid) != string::npos) {
				line_n = j;
				count++;
			}
		}

		if (count == 0) {
			cout << "Sorry that id number is not registered in the database." << endl;
			return;
		}

		name_ob.erase(name_ob.begin() + line_n);
		id_ob.erase(id_ob.begin() + line_n);
		degrees.erase(degrees.begin() + line_n);


		fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv", ios::out | ios::trunc);
		if (data.is_open()) {
			for (size_t j = 0; j < name_ob.size(); j++) {
				data << name_ob[j] << "," << id_ob[j] << "," << degrees[j] << "\n";
			}
			data.close();
			cout << "user deleted." << endl;
		}
	}


	if (identity_type == 'p' || identity_type == 'P') {
		cout << endl << "Please provide the PID of the user to be deleted." << endl;
		cin >> pid;

		string name_obj;
		string id_obj;
		vector <string> name_ob;
		vector <string> id_ob;

		int i = 0;

		ifstream Myfile;
		Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/professors.csv");

		while (Myfile.good()) {
			getline(Myfile, name_obj, ',');
			bool h = Myfile.good();
			if (h) {
				i++;
				name_ob.push_back(name_obj);
				getline(Myfile, id_obj, '\n');
				id_ob.push_back(id_obj);
			}
		}


		int count = 0;
		for (size_t j = 0; j < id_ob.size(); j++) {
			if (id_ob[j].find(pid) != string::npos) {
				line_n = j;
				count++;
			}
		}



		if (count == 0) {
			cout << "Sorry that id number is not registered in the database." << endl;
			return;
		}

		name_ob.erase(name_ob.begin() + line_n);
		id_ob.erase(id_ob.begin() + line_n);

		fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/professors.csv", ios::out | ios::trunc);
		if (data.is_open()) {
			for (size_t j = 0; j < name_ob.size(); j++) {
				data << name_ob[j] << "," << id_ob[j] << "\n";
			}
			data.close();
			cout << "user deleted." << endl;
		}
	}

	if (identity_type == 'a' || identity_type == 'A') {

		cout << endl << "Please provide the PID of the user to be deleted." << endl;
		cin >> pid;

		string name_obj;
		string id_obj;
		vector <string> name_ob;
		vector <string> id_ob;

		int i = 0;

		ifstream Myfile;
		Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/admins.csv");

		while (Myfile.good()) {
			getline(Myfile, name_obj, ',');
			bool h = Myfile.good();
			if (h) {
				i++;
				name_ob.push_back(name_obj);
				getline(Myfile, id_obj, '\n');
				id_ob.push_back(id_obj);
			}
		}


		int count = 0;
		for (size_t j = 0; j < id_ob.size(); j++) {
			if (id_ob[j].find(pid) != string::npos) {
				line_n = j;
				count++;
			}
		}

		if (count == 0) {
			cout << "Sorry that id number is not registered in the database." << endl;
			return;
		}
		name_ob.erase(name_ob.begin() + line_n);
		id_ob.erase(id_ob.begin() + line_n);

		fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/admins.csv", ios::out | ios::trunc);
		if (data.is_open()) {
			for (size_t j = 0; j < name_ob.size(); j++) {
				data << name_ob[j] << "," << id_ob[j] << "\n";
			}
			data.close();
			cout << "user deleted." << endl;
		}
	}
}
































void Admin::display() {
	cout << "Name:" << name << "Type: " << type << ". And PID: " << pid[7] << "." << endl;
}



////////////////////////////////////
//
////////////////////////////////////

char* Professor::getpid() {
    return pid;
}

vector<Courses> Professor::getlist_courses() {
	return list_courses;
}

vector <Seminars> Professor::getlist_sem() {
	return list_sem;
}

Project Professor::getproject() {
	return project;
}

void Professor::setpid(char new_pid[7]) {
    for(int i = 0; i < 7; i++){
        pid[i] = new_pid[i];
    }
}

void Professor::setlist_courses(vector <Courses> new_list_courses) {
	list_courses = new_list_courses;
}


void Professor::setlist_sem(vector <Seminars> new_list_sem) {
	list_sem = new_list_sem;
}


void Professor::setproject(Project new_project) {
	project = new_project;
}


/* Default constructor*/
Professor::Professor(){
    pid[0] = 'a';
    pid[1] = 'a';
    pid[2] = 'a';
    pid[3] = 'a';
    pid[4] = 'a';
    pid[5] = 'a';
    pid[6] = 'a';
    pid[7] = '\0';
    /* Here it is assumed that the default value of pid is "aaaaaaa" */
}


/* Parametrized constructor*/

Professor::Professor(string _name, string _type, char _pid[7], vector <Courses> _list_courses, vector <Seminars> _list_sem, Project _project) : Users(_name, _type) {
	if (_type == "professor") {
		for (int i = 0; i < 7; i++) {
			pid[i] = _pid[i];
		}

		list_courses = _list_courses;
		list_sem = _list_sem;
		project = _project;

	}
	else cout << "wrong specified type" << endl;

}

/* Copy constructor*/

//		Professor::Professor(const Professor & Pr){
//			for(int i = 0; i < 7; i++){
//				pid[i] = Pr.pid[i];
//
//			}
//		}

/* Destructor */

Professor::~Professor(){
}

void Professor::display() {
	cout << "Name:" << name << ". And PID: " << pid[7] << "." << endl;
}

void Professor::setmarks() {
	vector <string> coursevec;
	string courseid;
	cout << "For which course do you want to add grades?, please give the course id " << endl;
	cin >> courseid;
	file = "courses.txt";
	fstream data(file);
		if (data.is_open()) {
			bool continueing = false;
			while (continueing == false) {
				data.seekg(0, ios::beg);
				string searchname;
				string line;
				size_t pos;
				while (data >> line) {
					pos = line.find(courseid);
					if (pos != string::npos) {
						size_t pos2;
						cout << "The course is found." << endl;
						string wholeline = line;
						stringstream ss(wholeline);

						while (ss.good()) {
							string substr;
							getline(ss, substr, ',');
							coursevec.push_back(substr);
						}
//						for (int i = 0; i < coursevec.size(); ++i) {
//							cout << coursevec.at(i) << " " << endl;
//						}
					}
					else { cout << "We could not find this name in the database." << endl; }
				}
			}
			data.close();
		}
		else { cout << "Sorry the Virtual Campus was unable to get the data." << endl; }
	}
	Courses courseobj;
	int lencoursevec = coursevec.size();
	int len_list_students = (coursevec.size() - 5) / 2;
	courseobj.setstatus(coursevec.at(0));
	courseobj.setid(coursevec.at(1));
	courseobj.setcredits(coursevec.at(2));
	courseobj.setdegree(coursevec.at(lencoursevec - 1));
	courseobj.setprofessors(coursevec.at(lencoursevec));
	for (int i = 3; i < len_list_students+3; ++i) {
		courseobj.setlist_students(coursevec.at(i));
	}
	for (int i = len_list_students+3; i < len_list_students+len_list_students+3; ++i) {
		courseobj.setlist_marks(coursevec.at(i));
	}
	vector <string> list_students = courseobj.getlist_students;
	vector < int > list_marks = courseobj.getlist_marks;
	string courseproff = courseobj.getprofessors();
//	string coursproff2 = OBJECT OF PROFESSOR.getname();
//	if (courseproff == courseproff) {
		cout << "For which student do you want to set a grade?" << endl;
		string searchstudent;
		cin >> searchstudent;
		for (int i = 0; i < len_list_students; ++i) {
			if (searchstudent == list_students.at(i)) {
				int numberofstudent = i
			}
		}
		cout << "What is the grade you want to set?" << endl;
		string studentgrade;
		cin >> studentgrade;
		coursevec.at(3+len_list_students+numberofstudent) = studentgrade;
		fstream data("courses.txt", ios::app);
		if (data.is_open()) {
			for (int i = 0; i < ) {
				data << coursevec.at(i) << "," << endl;
			}
			data << "\n" << endl;
			cout << "The grade is set." << endl;
			data.close();

		}
		else { cout << "Sorry the Virtual Campus was unable to add data. Please start the program again in order to try again." << endl; }
//	}
}


////////////////////////////////////
//
////////////////////////////////////

char *Student::getsin() {
	return sin;
}

string Student::getdegree() {
	return degree;
}

vector<Courses> Student::getlist_courses() {
	return list_courses;
}

vector <Seminars> Student::getlist_sem() {
	return list_sem;
}

Project Student::getproject() {
	return project;
}

void Student::setsin(char new_sin[7]) {
	if (isdigit(new_sin[0]) && isdigit(new_sin[1]) && isdigit(new_sin[2]) && isdigit(new_sin[3]) && isdigit(new_sin[4]) && isdigit(new_sin[5]) && isdigit(new_sin[6])) {
		for (int i = 0; i < 7; i++) {
			sin[i] = new_sin[i];

		}

	}
	else cout << "wrong sin format" << endl;

}


void Student::setlist_courses(vector <Courses> new_list_courses) {

	list_courses = new_list_courses;
}



void Student::setlist_sem(vector <Seminars> new_list_sem) {

	list_sem = new_list_sem;

}


void Student::setproject(Project new_project) {
	project = new_project;
}

void Student::setdegree(string new_degree) {
	degree = new_degree;
}


/* Default constructor*/
Student::Student() :Users() {

	sin[0] = '0';
	sin[1] = '0';
	sin[2] = '0';
	sin[3] = '0';
	sin[4] = '0';
	sin[5] = '0';
	sin[6] = '0';
	sin[7] = '\0';
	Project p;
	project = p;
	degree = "not assigned";
	/* Here it is assumed that the default value of pid is "0000000" */
}


/* Parametrized constructor*/

Student::Student(string _name, string _type, char _sin[7], string _degree, vector <Courses> _list_courses, vector <Seminars> _list_sem, Project _project) :Users(_name, _type) {
	if (_type == "student") {
		if (isdigit(_sin[0]) && isdigit(_sin[1]) && isdigit(_sin[2]) && isdigit(_sin[3]) && isdigit(_sin[4]) && isdigit(_sin[5]) && isdigit(_sin[6])) {
			for (int i = 0; i < 7; i++) {
				sin[i] = _sin[i];

			}

		}
		else cout << "wrong sin format" << endl;

		list_courses = _list_courses;
		list_sem = _list_sem;
		degree = _degree;
		project = _project;
		
	}
	else cout << "wrong type specified." << endl;
}

/* Copy constructor*/

//		Student::Student(const Student & S){
//
//			for(int i = 0; i < 7; i++){
//				sin[i] = S.sin[i];
//
//			}
//
//			size_courses = S.size_courses;
//			list_courses = new string[size_courses];
//			list_courses = S.list_courses;
//			size_sems = S.size_sems;
//			list_sem = new string[size_sems];
//			list_sem = S.list_sem;
//			size_projects = S.size_projects;
//			list_project = new string[size_projects];
//			list_project = S.list_project;
//
//		}

/* Destructor */

Student::~Student(){}

void Student::display() {
	cout << "Name:" << name << ". SIN: " << sin[7] << "." << endl;
	cout << "A list of courses is: " << list_courses << endl;
	cout << "A list of seminars is: " << list_sem << endl;
	cout << "A list of projects is: " << project << endl;
	cout << "the Degree this student belongs to is: " << degree << endl;


}

//Options for students to enroll or drop courses
void Student::Studentactionsc() {
	cout << "What do you want to do? Enroll=1, Drop=2." << endl;
	int enrollordrop;
	cin >> enrollordrop;
	if (enrollordrop == 1) {
		cout << "What course do you want to enroll to?" << endl;
		string seekcourse;
		cin >> seekcourse;
		fstream data("courses.txt");
		if (data.is_open()) {
			data.seekg(0, ios::beg);
			string line;
			size_t pos;
			vector <string> coursevec;
			while (data >> line) {
				pos = line.find(seekcourse);
				if (pos != string::npos) {
					string wholeline = line;
					stringstream ss(wholeline);
					while (ss.good()) {
						string substr;
						getline(ss, substr, ',');
						coursevec.push_back(substr);
					}
					Courses courseobj;
					int lencoursevec = coursevec.size();
					int len_list_students = (coursevec.size() - 5) / 2;
					courseobj.setstatus(coursevec.at(0));
					char id[7];
					string temp = coursevec.at(1);
					strcpy(pid, temp.c_str());
					seminarobj.setid(id[7]);
					courseobj.setcredits(coursevec.at(2));
					courseobj.setdegree(coursevec.at(lencoursevec - 1));
					courseobj.setprofessors(coursevec.at(lencoursevec));
					for (int i = 3; i < len_list_students + 3; ++i) {
						courseobj.setlist_students(coursevec.at(i));
					}
					for (int i = len_list_students + 3; i < len_list_students + len_list_students + 3; ++i) {
						courseobj.setlist_marks(coursevec.at(i));
					}
					if (courseobj.getdegree == userobj.getdegree) {
						userobj.list_courses.append(seekcourse);
						//Plus add name to vector of names list_students from particular course
					}
					else { cout << "This course doesn't belong to the degree you are following." << endl; }
				}
				else { cout << "This course cannot be found in the course list." << endl; }
			}
		}
	}
	if (enrollordrop == 2) {
		cout << "Which course do you want to drop?" << endl;
		string dropcourse;
		cin >> dropcourse;
		vector <string> list_courses = userobj.getlist_courses();
		vector <string> templist;
		for (int i = 0; i < list_courses.size(); ++i) {
			if (list_courses.at(i) != = dropcourse) {
				templist.at(i) = list_courses.at(i);
			//Plus delete name out of vector of names list_students from particular course
			}
		}
		for (int i = 0; i < templist.size(); ++i) {
			courseobj.setlist_courses(templist.at(i));
		}
	}
	else { cout << "This is not a valid input." << endl; }
}

//Options for students to enroll or drop seminars
void Student::Studentactionss() {
	cout << "What do you want to do? Enroll=1, Drop=2." << endl;
	int enrollordrop;
	cin >> enrollordrop;
	if (enrollordrop == 1) {
		cout << "What seminar do you want to enroll to?" << endl;
		string seekseminar;
		cin >> seekseminar;
		fstream data("seminars.txt");
		if (data.is_open()) {
			data.seekg(0, ios::beg);
			string line;
			size_t pos;
			vector <string> seminarvec;
			while (data >> line) {
				pos = line.find(seekseminar);
				if (pos != string::npos) {
					string wholeline = line;
					stringstream ss(wholeline);
					while (ss.good()) {
						string substr;
						getline(ss, substr, ',');
						seminarvec.push_back(substr);
					}
					Seminars seminarobj;
					int len_seminarvec = seminarvec.size();
					seminarobj.setstatus(seminarvec.at(0));
					char id[7];
					string temp = seminarvec.at(1);
					strcpy(pid, temp.c_str());
					seminarobj.setid(id[7]);
					seminarobj.setcoordinator(seminarvec.at(2));
					seminarobj.setspeaker(seminarvec.at(3));
					seminarobj.setdate(seminarvec.at(4));
					seminarobj.setmax_seats(seminarvec.at(5));
					for (int i = 6; i < len_seminarvec; ++i) {
						seminarobj.setlist_students(seminarvec.at(i));
					}
					int max = seminarobj.getmax_seats();
					vector < semstud > = seminarobj.getlist_students();
					int num = semstud.getsize();
					if (num < max) {
						userobj.list_sem.append(seekseminar);
						//Plus add name to vector of names list_students from particular seminar
					}
					else { cout << "Sorry there are no free spots available anymore." << endl; }
				}
				else { cout << "This seminar cannot be found in the seminar list." << endl; }
			}
		}
	}
	if (enrollordrop == 2) {
		cout << "Which seminar do you want to drop?" << endl;
		string dropseminar;
		cin >> dropseminar;
		vector <string> list_sem = userobj.getlist_sem();
		vector <string> templist;
		for (int i = 0; i < list_sem.size(); ++i) {
			if (list_sem.at(i) != = dropseminar) {
				templist.at(i) = list_sem.at(i);
				//Plus delete name out of vector of names list_students from particular seminar
			}
		}
		for (int i = 0; i < templist.size(); ++i) {
			courseobj.setlist_courses(templist.at(i));
		}
	}
	else { cout << "This is not a valid input." << endl; }
}
		

//Options for students to enroll or drop projects
void Student::Studentactionsp() {
	cout << "What do you want to do? Enroll=1, Drop=2." << endl;
	int enrollordrop;
	cin >> enrollordrop;
	if (enrollordrop == 1) {
		cout << "What project do you want to enroll to?" << endl;
		string seekproject;
		cin >> seekproject;
		fstream data("projects.txt");
		if (data.is_open()) {
			data.seekg(0, ios::beg);
			string line;
			size_t pos;
			vector <string> projectvec;
			while (data >> line) {
				pos = line.find(seekproject);
				if (pos != string::npos) {
					string wholeline = line;
					stringstream ss(wholeline);
					while (ss.good()) {
						string substr;
						getline(ss, substr, ',');
						projectvec.push_back(substr);
					}
					Project projectobj;
					int len_projectvec = projectvec.size();
					projectobj.setstatus(projectvec.at(0));
					char id[7];
					string temp = projectvec.at(1);
					strcpy(pid, temp.c_str());
					projectobj.setid(id[7]);
					projectobj.settutor(projectvec.at(2));
					projectobj.setco_tutor(projectvec.at(3));
					projectobj.setstudent(projectvec.at(4));
					projectobj.setdegree(seminarvec.at(5));
					string proj = userobj.getdegree();
					string proj2 = projectobj.getdegree();

					if (proj == "not assigned" && proj2 == "not assigned" ) {
						userobj.setproject(seekseminar);
						//Plus add name to student of particular project
					}
					else { cout << "This project already has a student or you already have a project." << endl; }
				}
				else { cout << "Sorry this project cannot be found in the project list." << endl; }
			}
		}
	}
	if (enrollordrop == 2) {
		cout << "Okay, we will delete this project for you." << endl;
				userobj.setproject("not assigned")
				//Plus delete name of student of particular project
			}
		}
		for (int i = 0; i < templist.size(); ++i) {
			courseobj.setlist_courses(templist.at(i));
		}
	}
	else { cout << "This is not a valid input." << endl; }
}







////////////////////////////////////
//
////////////////////////////////////
