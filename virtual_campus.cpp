#include <iostream>
#include "virtual_campus.h"


using namespace std;


//void VirtualCampus::start(){


//    //first load info from all files here


//    //incase no file : initialize stuff here
//    Admin a;


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



//}



/* Default constructor*/
VirtualCampus::VirtualCampus(){

}


/* Destructor */

VirtualCampus::~VirtualCampus(){
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

Project::Project() {
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


////////////////////////////////////
//
////////////////////////////////////
