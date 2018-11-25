#include <iostream>
#include "virtual_campus.h"
#include <fstream>
#include <string>

using namespace std;


string Resources::getstatus() {
    return status;
}


char* Resources::getid() {
    return id;
}

void Resources::setstatus(string new_status) {
    if(new_status == "created" || "in progress" || "completed"){
        status = new_status;

    }
    else{
        cout << "wrong format for status" << endl;
    }

}

void Resources::setid(char new_id[7]) {

    if( ((new_id[0] && new_id[1] && new_id[2]) == 'a' || 'b' || 'c' || 'd' || 'e' || 'f' || 'g' || 'h' || 'i' || 'j' || 'k' ||
             'l' || 'm' || 'n' || 'o' || 'p' || 'q' || 'r' || 's' || 't' || 'u' || 'v' || 'w' || 'x' || 'y' || 'z' || 'A' || 'B' || 'C' || 'D' ||
             'E' || 'F' || 'G' || 'H' || 'I' || 'J' || 'K' || 'L' || 'M' || 'N' || 'O' || 'P' || 'Q' || 'R' || 'S' || 'T' || 'U' || 'V' || 'W' || 'X' ||
             'Y' || 'Z') && ((new_id[3] && new_id[4] && new_id[5] && new_id[6]) == '0' || '1' || '2' || '3' || '4' || '5' || '6' || '7' || '8' || '9') ){

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
    status = "no status";
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


    if( ((_id[0] && _id[1] && _id[2]) == 'a' || 'b' || 'c' || 'd' || 'e' || 'f' || 'g' || 'h' || 'i' || 'j' || 'k' ||
             'l' || 'm' || 'n' || 'o' || 'p' || 'q' || 'r' || 's' || 't' || 'u' || 'v' || 'w' || 'x' || 'y' || 'z' || 'A' || 'B' || 'C' || 'D' ||
             'E' || 'F' || 'G' || 'H' || 'I' || 'J' || 'K' || 'L' || 'M' || 'N' || 'O' || 'P' || 'Q' || 'R' || 'S' || 'T' || 'U' || 'V' || 'W' || 'X' ||
             'Y' || 'Z') && ((_id[3] && _id[4] && _id[5] && _id[6]) == '0' || '1' || '2' || '3' || '4' || '5' || '6' || '7' || '8' || '9') ){

        for(int i = 0; i < 7; i++){
            id[i] = _id[i];

        }
    }


    else{
        cout << "wrong format for id" << endl;
    }

}

/* Copy constructor*/

Resources::Resources(const Resources & R){
    status = R.status;
    for(int i = 0; i < 7; i++){
        id[i] = R.id[i];

    }
}

/* Destructor */

Resources::~Resources(){
}



////////////////////////////////////
//
////////////////////////////////////



string Seminars::getcoordinator() {
    return coordinator;
}


string Seminars::getspeaker() {
    return speaker;
}

string Seminars::getdate() {
    return date;
}

int Seminars::getmax_seats() {
    return max_seats;
}

string* Seminars::getlist_students_s() {
    return list_students_s;
}

int Seminars::getsize(){
    return size;
}

void Seminars::setcoordinator(string new_coordinator) {
    coordinator = new_coordinator;
}


void Seminars::setspeaker(string new_speaker) {
    speaker = new_speaker;
}

void Seminars::setdate(string new_date) {
    date = new_date;
}

void Seminars::setmax_seats(int new_max_seats) {
    max_seats = new_max_seats;
}

/* Here new_list_students_s is a dynamic array of length "new_size" */

void Seminars::setsize(int new_size){
    size = new_size;
}

void Seminars::setlist_students_s(string* new_list_students_s, int new_size) {

    size = new_size;
    list_students_s = new string[size];
    for (int i = 0; i < size; i++) {
        *(list_students_s + i) = new_list_students_s[i];
    }

    delete[] new_list_students_s;

}



/* Default constructor*/
Seminars::Seminars(){
    coordinator = "no coordinator";
    speaker = "no speaker";
    date = "no date";
    max_seats = -1;
    size = 1;
    list_students_s = new string[size];
    list_students_s[0] = "no student";
}

/* -1 is a dummy number of max_seats */

/* Parametrized constructor*/

/* Here _list_students_s is a dynamic array of length "_size" */


Seminars::Seminars(string _coordinator, string _speaker, string _date, int _max_seats, string* _list_students_s, int _size){
    coordinator = _coordinator;
    speaker = _speaker;
    date = _date;
    max_seats = _max_seats;
    size = _size;
    list_students_s = new string[size];

    for (int i = 0; i < size; i++) {
        *(list_students_s + i) = _list_students_s[i];
    }

    delete[] _list_students_s;
}

/* Copy constructor*/

Seminars::Seminars(const Seminars & S){
    coordinator = S.coordinator;
    speaker = S.speaker;
    date = S.date;
    max_seats = S.max_seats;
    size = S.size;
    list_students_s = new string[size];
    list_students_s = S.list_students_s;
}

/* Destructor */

Seminars::~Seminars(){
    delete[] list_students_s;
}

void Seminars::display() {
	cout << "Status:" << status << ". ID: " << id[7] << ". Coordinator: " << coordinator << ". Speaker: " << speaker << ". Date: " << date << "Maximum number of seats: " << max_seats << " And the size is: " << size << "." << endl;
	cout << "A list of students is: " << list_students_s << endl;
}


////////////////////////////////////
//
////////////////////////////////////

string Projects::gettutor() {
    return tutor;
}


bool Projects::getco_tutor_presence() {
    return co_tutor_presence;
}

string Projects::getco_tutor() {
    return co_tutor;
}


void Projects::settutor(string new_tutor) {
    tutor = new_tutor;
}


void Projects::setco_tutor_presence(bool new_co_tutor_presence) {
    co_tutor_presence = new_co_tutor_presence;
}

void Projects::setco_tutor(string new_co_tutor){
	if (co_tutor_presence == 1 || co_tutor_presence == true) {
		co_tutor = new_co_tutor;
	}
	else { cout << "This is not possible" << endl; }
}	


/* Default constructor*/
Projects::Projects(){
    tutor = "no tutor";
    co_tutor_presence = 0;
    co_tutor = "no co-tutor";
}



/* Parametrized constructor*/

Projects::Projects(string _tutor, bool _co_tutor_presence, string _co_tutor){
    tutor = _tutor;
    co_tutor_presence = _co_tutor_presence;
    co_tutor = _co_tutor;
}

/* Copy constructor*/

Projects::Projects(const Project & P){
    tutor = P.tutor;
    co_tutor_presence = P.co_tutor_presence;
    co_tutor = P.co_tutor;
}

/* Destructor */

Projects::~Projects(){
}

void Projects::display() {
	cout << "Status:" << status << ". ID: " << id[7] << ". Tutor: " << tutor;
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

string* Courses::getlist_students() {
    return list_students;
}

float* Courses::getlist_marks() {
    return list_marks;
}

int Courses::getsize_students(){
    return size_students;
}


int Courses::getsize_marks(){
    return size_marks;
}


void Courses::setcredits(int new_credits) {
    credits = new_credits;
}

void Courses::setsize_students(int new_size_students){
    size_students = new_size_students;
}

void Courses::setsize_marks(int new_size_marks){
    size_marks = new_size_marks;
}

/* Here new_list_students is a dynamic array of length "new_size_students" */

void Courses::setlist_students(string* new_list_students, int new_size_students) {
    size_students = new_size_students;
    list_students = new string[size_students];
    for (int i = 0; i < size_students; i++) {
        *(list_students + i) = new_list_students[i];
    }

    delete[] new_list_students;

}

/* Here new_list_marks is a dynamic array of length "new_size_marks" */

void Courses::setlist_marks(float* new_list_marks, int new_size_marks) {
    size_marks = new_size_marks;
    list_marks = new float[size_marks];
    for (int i = 0; i < size_marks; i++) {
        *(list_marks + i) = new_list_marks[i];
    }

    delete[] new_list_marks;
}


/* Default constructor*/
Courses::Courses(){
    credits = 0;
    size_marks = 1;
    size_students = 1;
    list_students = new string[size_students];
    list_students[0] = "no student";
    list_marks = new float[size_marks];
    list_marks[0] = -1;
    *resource = Resources();
}

/* Parametrized constructor*/

Courses::Courses(int _credits, string* _list_students, float* _list_marks, int _size_students, int _size_marks, Resources* _resource){
    credits = _credits;
    size_students = _size_students;
    size_marks = _size_marks;
    resource->status = _resource->status;
    for(int i = 0; i < 7; i++){
        resource->id[i] = _resource->id[i];

    }


    list_students = new string[size_students];

    for (int i = 0; i < size_students; i++) {
        *(list_students + i) = _list_students[i];
    }

    delete[] _list_students;

    list_marks = new float[size_marks];

    for (int i = 0; i < size_marks; i++) {
        *(list_marks + i) = _list_marks[i];
    }

    delete[] _list_marks;
}

/* Copy constructor*/

Courses::Courses(const Courses & C){
    credits = C.credits;
    size_students = C.size_students;
    list_students = new string[size_students];
    list_students = C.list_students;
    size_marks = C.size_marks;
    list_marks = new float[size_marks];
    list_marks = C.list_marks;
    for(int i = 0; i < 7; i++){
        resource->id[i] = C.resource->id[i];

    }

    resource->status = C.resource->status;

}

/* Destructor */

Courses::~Courses(){

//    Resources::~Resources();
    delete[] list_students;
    delete[] list_marks;
}

void Courses::display() {
	cout << "Status:" << status << ". ID: " << id[7] << ". And the number of credits: " << credits << "." << endl;
	cout << "A list of students is: " << list_students << endl;
	cout << "A list of marks is: " << list_marks << endl;
	cout << "The size of list of students is: " << size_students << endl;
	cout << "The size of list of marks is: " << size_marks << endl;
}


////////////////////////////////////
//
////////////////////////////////////

string Degree::getdegree() {
    return degree;
}

void Degree::setdegree(string new_degree) {
    degree = new_degree;
}


/* Default constructor*/
Degree::Degree(){
    degree = "no degree";
}

/* Parametrized constructor*/

Degree::Degree(string _degree){
    degree = _degree;
}

/* Copy constructor*/

Degree::Degree(const Degree & D){
    degree = D.degree;

}

/* Destructor */

Degree::~Degree(){
}







string Users::getname() {
    return name;
}


void Users::setname(string new_name) {
    name = new_name;
}


/* Default constructor*/
Users::Users(){
    name = "no name";
}


/* Parametrized constructor*/

Users::Users(string _name){
    name = _name;
}

/* Copy constructor*/

Users::Users(const Users & U){
    name = U.name;
}

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

Admin::Admin(char _pid[7]){
    for(int i = 0; i < 7; i++){
        pid[i] = _pid[i];

    }
}

/* Copy constructor*/

Admin::Admin(const Admin & A){
    for(int i = 0; i < 7; i++){
        pid[i] = A.pid[i];

    }
}

/* Destructor */

Admin::~Admin(){
	delete[] deluser;
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

void Admin::displayc(Courses _course){

    int credit = _course.getcredits();
    string* list_of_students = _course.getlist_students();
    float* list_of_marks = _course.getlist_marks();
    char id[7];
    string status = _course.resource->status ;

    for(int i = 0 ; i < 7 ; i++){
        id[i] = _course.resource->id[i];

    }

    cout << "The course ID is " << id << endl;
    cout << "The course is" << status << endl;
    cout << "This course has " << credit << " number of credits." << endl;

    cout << "This course has these students along with their marks: " << endl;

    for(int i = 0 ; i < _course.size_students ; i++){
        cout << i+1 << ". " << list_of_students[i] << " with " << list_of_marks[i] << " marks"<< endl;

    }


}

void Admin::createu(Users _user) {
	fstream data("data.txt");
	if (data.is_open()) {
//		data.clear();
		data.seekg(0, ios::eof);
		string newuser;
		string identity;
		cout << endl << "Please fill in a new user." << endl;
		cin >> newuser;
		cout << endl << "Please fill in his/her identity." << endl;
		cin >> identity;
		data << newuser << "	" << identity << endl;
		data.close();
		if (identity == "Administrator") {
			Admin *newuser = new Admin;
			newuser->setname(newuser);
			cout << "Give the PID of this person." << endl;
			char newpid[7];
			cin >> newpid;
			newuser->setpid(newpid);
			//plus add new object to list of objects
		}
		if (identity == "Professor") {
			Professor *newuser = new Professor;
			newuser->setname(newuser);
			cout << "Give the PID of this person." << endl;
			char new2pid[7];
			cin >> new2pid;
			newuser->setpid(new2pid);
			//plus change object in list of objects
		}
		else {
			Student *newuser = new Student;
			newuser->setname(newuser);
			cout << "Give the SIN of this person." << endl;
			char newsin[7];
			cin >> newsin;
			newuser->setsin(newsin);
			//plus delete object of list of objects
		}
	}
	else { cout << "Sorry the Virtual Campus was unable to add data. Please start the program again in order to try again." << endl; }
}


void Admin::modifyu(Users _user){
	fstream data("data.txt");
	fstream temp("temp.txt");
	if (data.is_open()) {
		if (temp.is_open()) {
			size_t pos;
			string moduser;
			string moduser2;
			string tempuser;
			cout << endl << "Please give the name of the user you want to modify."
			cin >> moduser;
			while (data >> tempuser) {
				pos = line.find(moduser);
				if (tempuser == moduser) {
					cout << "We found the name of this person. To what name do you want to change it?" << endl;
					cin >> moduser2;
					// NOT DONE YET
					// https://www.quora.com/How-can-I-replace-modify-a-particular-string-in-a-file-using-c++
			//		data << moduser << endl;
			//		data << moduser2 << endl;
					data.close();
					moduser.setname(moduser2);
				}
				else {
					cout << "Sorry this name is not in our list." << endl;
					break;
				}
			}
		}
		else { cout << "Sorry the Virtual Campus was unable to modify data. Please start the program again in order to try again." << endl; }
	}
	else { cout << "Sorry the Virtual Campus was unable to modify data. Please start the program again in order to try again." << endl; }
}


void Admin::deleteu(Users _user) {
	fstream data("data.txt");
	if (data.is_open()) {
		size_t pos;
		string deluser;
		cout << endl << "Please give the name of the user you want to delete."
		string deluser;
		cin >> deluser;
		while (getline(data, line)) {
			// NOT DONE YET
				
	//			pos = line.find(deluser);
	//			if (pos != string::npos) {
	//				data << moduser << endl;
	//				data << "" << endl;
	//				cout << "This user has been deleted." << endl;
					data.close();
					delete deluser;
				}
				else {
					cout << "Sorry this name is not in our list." << endl;
					break;
				}
			}
	}
	else { cout << "Sorry the Virtual Campus was unable to delete data. Please start the program again in order to try again." << endl; }
}

void Admin::display() {
	cout << "Name:" << name << ". And PID: " << pid[7] << "." << endl;
}


////////////////////////////////////
//
////////////////////////////////////

char* Professor::getpid() {
    return pid;
}

void Professor::setpid(char new_pid[7]) {
    for(int i = 0; i < 7; i++){
        pid[i] = new_pid[i];

    }
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

Professor::Professor(char _pid[7]){
    for(int i = 0; i < 7; i++){
        pid[i] = _pid[i];

    }
}

/* Copy constructor*/

Professor::Professor(const Professor & Pr){
    for(int i = 0; i < 7; i++){
        pid[i] = Pr.pid[i];

    }
}

/* Destructor */

Professor::~Professor(){
}

void Professor::display() {
	cout << "Name:" << name << ". And PID: " << pid[7] << "." << endl;
}

////////////////////////////////////
//
////////////////////////////////////

int* Student::getsin() {
    return sin;
}


int Student::getsize_courses(){
    return size_courses;
}

int Student::getsize_sems(){
    return size_sems;
}

int Student::getsize_projects(){
    return size_projects;
}

string* Student::getlist_courses() {
    return list_courses;
}

string* Student::getlist_sem() {
    return list_sem;
}

string* Student::getlist_project() {
    return list_project;
}

void Student::setsin(int new_sin[7]) {
    for(int i = 0; i < 7; i++){
        sin[i] = new_sin[i];

    }
}


/* Here new_list_courses is a dynamic array of length "new_size_courses" */

void Student::setsize_courses(int new_size_courses){
    size_courses = new_size_courses;
}

void Student::setlist_courses(string* new_list_courses, int new_size_courses) {

    size_courses = new_size_courses;
    list_courses = new string[size_courses];
    for (int i = 0; i < size_courses; i++) {
        *(list_courses + i) = new_list_courses[i];
    }

    delete[] new_list_courses;

}

/* Here new_list_sem is a dynamic array of length "new_size_sems" */

void Student::setsize_sems(int new_size_sems){
    size_sems = new_size_sems;
}

void Student::setlist_sem(string* new_list_sem, int new_size_sems) {

    size_sems = new_size_sems;
    list_sem = new string[size_sems];
    for (int i = 0; i < size_sems; i++) {
        *(list_sem + i) = new_list_sem[i];
    }

    delete[] new_list_sem;

}

/* Here new_list_project is a dynamic array of length "new_size_projects" */

void Student::setsize_projects(int new_size_projects){
    size_projects = new_size_projects;
}

void Student::setlist_project(string* new_list_project, int new_size_projects) {

    size_projects = new_size_projects;
    list_project = new string[size_projects];
    for (int i = 0; i < size_projects; i++) {
        *(list_project + i) = new_list_project[i];
    }

    delete[] new_list_project;

}


/* Default constructor*/
Student::Student(){

    sin[0] = '0';
    sin[1] = '0';
    sin[2] = '0';
    sin[3] = '0';
    sin[4] = '0';
    sin[5] = '0';
    sin[6] = '0';
    sin[7] = '\0';


    size_courses = 1;
    list_courses = new string[size_courses];
    list_courses[0] = "no courses";

    size_sems = 1;
    list_sem = new string[size_sems];
    list_sem[0] = "no seminar";

    size_projects = 1;
    list_project = new string[size_projects];
    list_project[0] = "no project";

    /* Here it is assumed that the default value of pid is "0000000" */

}

/* Parametrized constructor*/

Student::Student(int _sin[7], string* _list_courses, string* _list_sem, string* _list_project, int _size_courses, int _size_sems, int _size_projects){
    for(int i = 0; i < 7; i++){
        sin[i] = _sin[i];

    }

    size_courses = _size_courses;
    list_courses = new string[size_courses];

    for (int i = 0; i < size_courses; i++) {
        *(list_courses + i) = _list_courses[i];
    }

    delete[] _list_courses;


    size_sems = _size_sems;
    list_sem = new string[size_sems];

    for (int i = 0; i < size_sems; i++) {
        *(list_sem + i) = _list_sem[i];
    }

    delete[] _list_sem;


    size_projects = _size_projects;
    list_project = new string[size_projects];

    for (int i = 0; i < size_projects; i++) {
        *(list_project + i) = _list_project[i];
    }

    delete[] _list_project;


}

/* Copy constructor*/

Student::Student(const Student & S){

    for(int i = 0; i < 7; i++){
        sin[i] = S.sin[i];

    }

    size_courses = S.size_courses;
    list_courses = new string[size_courses];
    list_courses = S.list_courses;
    size_sems = S.size_sems;
    list_sem = new string[size_sems];
    list_sem = S.list_sem;
    size_projects = S.size_projects;
    list_project = new string[size_projects];
    list_project = S.list_project;

}

/* Destructor */

Student::~Student(){

    delete[] list_courses;
    delete[] list_sem;
    delete[] list_project;
}

void Student::display() {
	cout << "Name:" << name << ". SIN: " << sin[7] << ".  <<"." << endl;
	cout << "A list of courses is: " << list_courses << endl;
	cout << "A list of seminars is: " << list_sem << endl;
	cout << "A list of projects is: " << list_project << endl;
	cout << "The size of list of courses is: " << size_courses << endl;
	cout << "The size of list of seminars is: " << size_sems << endl;
	cout << "The size of list of projects is: " << size_projects << endl;

}

//Options for students to enroll or drop courses
void Student::Studentactions() {
	cout << "What do you want to do? Enroll=1, Drop=2." << endl;
	int enrollordrop;
	cin >> enrollordrop;
	if (enrollordrop == 1) {
		cout << "What course do you want to enroll to?"
			string seekcourse;
		cin >> seekcourse;
		if (//seekcourse is in the list of objects of courses){
			list_courses.append(seekcourse);
		}
	}
	if (enrollordrop == 2) {
		cout << "Which course do you want to drop?" << endl;
		string dropcourse;
		cin >> dropcourse;
		if (//dropcourse is in the list of oject of courses){
			list_courses.remove(dropcourse);
		}
	}
	else { cout << "This is not a valid input." }
}


////////////////////////////////////
//
////////////////////////////////////

string VirtualCampus::getnameofcampus() {
    return nameofcampus;
}

void VirtualCampus::setnameofcampus(string new_nameofcampus) {
    nameofcampus = new_nameofcampus;
}

//Starting the application by logging in.
int VirtualCampus::start(){
	
	int switched;
	cout << "Welcome to the Virtual Campus of UC3M. Please log in in order to start." << endl;
	fstream data("data.txt");
	if (data.is_open()) {
		bool login = false;
		while (login == false) {
//			data.clear();
			data.seekg(0, ios::beg);
			string loginname;
			string loginpassword;
			string foundname;
			string line;
			string search1 = "Administrator";
			string search2 = "Professor";
			string search3 = "Student";


			cout << endl << "Please fill in your name (Use officialadmin as default version)" << endl;
			cin >> loginname;
			cout << endl << "Please fill in your password (Use password as default version)" << endl;
			cin >> loginpassword;
			size_t pos;
			while(getline(data,line)){
				pos = line.find(loginname);
				if (pos != string::npos) {
					size_t pos2;
					pos2 = line.find(loginpassword);
					if (pos2 != string::npos) {
						size_t pos3;
						size_t pos4;
						size_t pos5;
						cout << "Welcome, you are logged in." << endl;
						pos3 = line.find(search1);
						pos4 = line.find(search2);
						pos5 = line.find(search3);
						if (pos3 != string::npos) { cout << "You are identified as an administrator." << endl; switched = 1; }
						if (pos4 != string::npos) { cout << "You are identified as a professor." << endl; switched=2; }
						if (pos5 != string::npos) { cout << "You are identified as a student." << endl; switched=3; }
	//					else { cout << "Your identity couldn't be determined, so it is assumed you are a student." << endl; activities_start3 = true; }
						login = true;
						cout << "Do you want to change your password? y/n." << endl;
						cin >> ans;
						if (ans == 'y' || ans == 'Y') {
							cout << "Fill in your new password." << endl;
							string newpassword;
							cin >> newpassword;
							//Update password here
							data.close();
							VirtualCampus::StartActivities();
						}
						else {
							cout >> "Okay sure, you can now start any activity." << endl;
							data.close();
							VirtualCampus::StartActivities();
						}
					}
					else { 
						cout << "Sorry, wrong password" << endl;
						break;
					}
				}
				else { 
					cout << "Sorry this name is not in our list" << endl;
					break;
				}
			}
		}
	}
	else { cout << "Sorry the Virtual Campus was unable to get the data. Please start the program again in order to log in." << endl; }
	
	return { loginname, switched };
	
	
	Admin a;

    string *array1 = new string[2]{"bas", "devyani"};
    float *array2 = new float[2]{0, 0};

//    Courses english(6, array1, array2, 2, 2 );

//    float *array3 = new float[2]{10, 19};


//    a.createc(english, 2, array1, array3, 2, 2);
//    a.displayc(english);

    Courses hindi;
    a.displayc(hindi);
}



/* Default constructor*/
VirtualCampus::VirtualCampus(){
    nameofcampus = "no name";
}

/* Parametrized constructor*/

VirtualCampus::VirtualCampus(string _nameofcampus){
    nameofcampus = _nameofcampus;
}

/* Copy constructor*/

VirtualCampus::VirtualCampus(const VirtualCampus & V){
    nameofcampus = V.nameofcampus;

}

/* Destructor */

VirtualCampus::~VirtualCampus(){
}


//Give the user the available options he is allowed to do
void virtualCampus::StartActivities(){
		int choice;
		int choice2;
		switch (switched) {

		// Admin's choices
		case 1: cout << endl << "What do you want to do ? " << endl << endl << "1. Create, modify or delete users." << endl << "2. Create, modify or delete resources." << endl << "3. Show information of users." << endl << "4. Show information of resources." << endl;
			cin >> choice;
			switch (choice) {
			case 1: cout << endl << "What do you want to do ? " << endl << endl << "1. Create users." << endl << "2. Modify users." << endl << "3. Delete users." << endl;
				cin >> choice2;
				switch (choice2) {
				case 1: cout << "Here you can create users" << endl;
					Admi::createu();
					break;
				case 2: cout << "Here you can modify users" << endl;
					Admin::modifyu();
					break;
				case 3: cout << "Here you can delete users" << endl;
					Admin::deleteu();
					break;
				}
				break;
			case 2: cout << endl << "What do you want to do ? " << endl << endl << "1. Create resources." << endl << "2. Modify resources." << endl << "3. Delete resources." << endl;
				cin >> choice2;
				switch (choice2) {
				case 1: cout << "Here you can create resources" << endl;
					//initialize function
					break;
				case 2: cout << "Here you can modify resources" << endl;
					//initialize function
					break;
				case 3: cout << "Here you can delete resources" << endl;
					//initialize function
					break;
				}
				break;
			case 3: cout << endl << "What do you want to do ? " << endl << endl << "1. Show information of an administrator." << endl << "2.Show information of a professor." << endl << "3. Show information of a student." << endl;
				cin >> choice2;
				switch (choice2) {
				case 1: cout << "Here you can see information of administrators" << endl;
					VirtualCampus::BeginAction(Admin);
					break;
				case 2: cout << "Here you can see information of professors" << endl;
					VirtualCampus::BeginAction(Professor);
					break;
				case 3: cout << "Here you can see information of students" << endl;
					VirtualCampus::BeginAction(Student);
					break;
				}
				break;
			case 4: cout << endl << "What do you want to do ? " << endl << endl << "1. Show information of a course." << endl << "2.Show information of a project." << endl << "3. Show information of a seminar." << endl;
				cin >> choice2;
				switch (choice2) {
				case 1: cout << "Here you can see information of a course" << endl;
					VirtualCampus::BeginAction(Courses);
					break;
				case 2: cout << "Here you can see information of a project" << endl;
					VirtualCampus::BeginAction(Projects);
					break;
				case 3: cout << "Here you can see information of a seminar" << endl;
					VirtualCampus::BeginAction(Seminars);
					break;
				}
				break;
			}
			break;


		//Professor's choices
		case 2: cout << endl << "What do you want to do ? " << endl << endl << "1. Modify your own resources." << endl << "2. Grade students." << endl << "3. Show information of users." << endl << "4. Show information of resources." << endl;
			cin >> choice;
			switch (choice) {
			case 1: cout << endl << "What do you want to do ? " << endl << endl << "1. Modify courses." << endl << "2. Modify projects." << endl << "3. Modify seminars." << endl;
				cin >> choice2;
				switch (choice2) {
				case 1: cout << "Here you can modify courses" << endl;
					//initialize function
					break;
				case 2: cout << "Here you can modify projects" << endl;
					//initialize function
					break;
				case 3: cout << "Here you can modify seminars" << endl;
					//initialize function
					break;
				}
				break;
			case 2: cout << endl << "Here you can set grades. " << endl;
				// initialize function
				break;

			case 3: cout << endl << "What do you want to do ? " << endl << endl << "1. Show information of an administrator." << endl << "2.Show information of a professor." << endl << "3. Show information of a student." << endl;
				cin >> choice2;
				switch (choice2) {
				case 1: cout << "Here you can see information of administrators" << endl;
					VirtualCampus::BeginAction(Admin);
					break;
				case 2: cout << "Here you can see information of professors" << endl;
					VirtualCampus::BeginAction(Professor);
					break;
				case 3: cout << "Here you can see information of students" << endl;
					VirtualCampus::BeginAction(Student);
					break;
				}
				break;
			case 4: cout << endl << "What do you want to do ? " << endl << endl << "1. Show information of a course." << endl << "2.Show information of a project." << endl << "3. Show information of a seminar." << endl;
				cin >> choice2;
				switch (choice2) {
				case 1: cout << "Here you can see information of a course" << endl;
					VirtualCampus::BeginAction(Courses);
					break;
				case 2: cout << "Here you can see information of a project" << endl;
					VirtualCampus::BeginAction(Projects);
					break;
				case 3: cout << "Here you can see information of a seminar" << endl;
					VirtualCampus::BeginAction(Seminars);
					break;
				}
				break;
			}
			break;


		//Student's choices
		case 3: cout << endl << "What do you want to do ? " << endl << endl << "1. Enroll and drop resources." << endl << "2. Show information of users." << endl << "3. Show information of resources." << endl;
			cin >> choice;
			switch (choice) {
			case 1: cout << endl << "What do you want to do ? " << endl << endl << "1. Enroll for a course." << endl << "2. Drop a course." << endl;
				cin >> choice2;
				switch (choice2) {
				case 1: cout << "Here you can enroll for a course" << endl;
					Student::Studentactions();
					break;
				case 2: cout << "Here you can drop a course" << endl;
					Student::Studentactions();
					break;
				}
				break;
			case 2: cout << endl << "What do you want to do ? " << endl << endl << "1. Show information of an administrator." << endl << "2.Show information of a professor." << endl << "3. Show information of a student." << endl;
				cin >> choice2;
				switch (choice2) {
				case 1: cout << "Here you can see information of administrators" << endl;
					VirtualCampus::BeginAction(Admin);
					break;
				case 2: cout << "Here you can see information of professors" << endl;
					VirtualCampus::BeginAction(Professor);
					break;
				case 3: cout << "Here you can see information of students" << endl;
					VirtualCampus::BeginAction(Student);
					break;
				}
				break;
			case 3: cout << endl << "What do you want to do ? " << endl << endl << "1. Show information of a course." << endl << "2.Show information of a project." << endl << "3. Show information of a seminar." << endl;
				cin >> choice2;
				switch (choice2) {
				case 1: cout << "Here you can see information of a course" << endl;
					VirtualCampus::BeginAction(Courses);
					break;
				case 2: cout << "Here you can see information of a project" << endl;
					VirtualCampus::BeginAction(Projects);
					break;
				case 3: cout << "Here you can see information of a seminar" << endl;
					VirtualCampus::BeginAction(Seminars);
					break;
				}
				break;
			}
			break;
		}
}


//start displaying the users or resources
void VirtualCampus::BeginAction(object){
	cout << "What is the name of the user or resource you are looking for?" << endl;
	string searchobj;
	cin >> searchobj;
	if (searchobj == "all") {
		//show all of the objects in this particular class
	}	
	else { searchobject.display(); }
	
	
	//int *len = new int[]
	//object list [len] = {}
	//object * 
}
