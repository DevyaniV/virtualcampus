#include <iostream>
#include "virtual_campus.h"
#include <fstream>


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

vector<Student> Seminars::getlist_students() {
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
    Professor* a;
    Professor* b;
    vector <Student> s;
    coordinator = a;
    speaker = b;
    date = "no date";
    max_seats = -1;
    list_students = s;

}

/* -1 is a dummy number of max_seats */

/* Parametrized constructor*/

/* Here _list_students_s is a dynamic array of length "_size" */


Seminars::Seminars(string _status, char _id[7], Professor* _coordinator, Professor* _speaker, string _date, int _max_seats, vector < Student> _list_students) : Resources(_status, _id){
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
    return list_marks;
}

Professor* Courses::getprofessor1(){
    return professor1;
}

Professor* Courses::getprofessor2(){
    return professor2;
}


string Courses::getdegree(){
    return degree;
}


void Courses::setcredits(int new_credits) {
    credits = new_credits;
}

/* Here new_list_students is a dynamic array of length "new_size_students" */

void Courses::setlist_students(vector<Student> new_list_students) {
    list_students = new_list_students;

}

/* Here new_list_marks is a dynamic array of length "new_size_marks" */

void Courses::setlist_marks(vector<float> new_list_marks) {
    list_marks = new_list_marks;

}


void Courses::setprofessor1(Professor *new_professor1){
    professor1 = new_professor1;
}


void Courses::setprofessor2(Professor *new_professor2){
    professor2 = new_professor2;
}


/* Default constructor*/
Courses::Courses():Resources(){
    credits = 0;
    Professor* a;
    Professor* b;
    professor1 = a;
    professor2 = b;
    degree = "not assigned" ;

}

/* Parametrized constructor*/

Courses::Courses(string _status, char _id[7], int _credits, vector < Student > _list_students, vector < float > _list_marks, string _degree, Professor* _professor1, Professor* _professor2) : Resources(_status, _id) {
    credits = _credits;

    list_students = _list_students;
    list_marks = _list_marks;
    degree = _degree;
    professor1 = _professor1;
    professor2 = _professor2;

}

/* Copy constructor*/

//Courses::Courses(const Courses & C){
//    credits = C.credits;
//    size_students = C.size_students;
//    list_students = new string[size_students];
//    list_students = C.list_students;
//    size_marks = C.size_marks;
//    list_marks = new float[size_marks];
//    list_marks = C.list_marks;
//    for(int i = 0; i < 7; i++){
//        resource->id[i] = C.resource->id[i];

//    }

//    resource->status = C.resource->status;

//}

/* Destructor */

Courses::~Courses(){

}

////////////////////////////////////
//
////////////////////////////////////

//string Degree::getdegree() {
//    return degree;
//}

//void Degree::setdegree(string new_degree) {
//    degree = new_degree;
//}


///* Default constructor*/
//Degree::Degree(){
//    degree = "no degree";
//}

///* Parametrized constructor*/

//Degree::Degree(string _degree){
//    degree = _degree;
//}

///* Copy constructor*/

//Degree::Degree(const Degree & D){
//    degree = D.degree;

//}

///* Destructor */

//Degree::~Degree(){
//}






string Users::getname() {
    return name;
}

string Users::gettype(){
    return type;
}


void Users::setname(string new_name) {
    name = new_name;
}


void Users::settype(string new_type){
    if(new_type == "student" || new_type == "professor" || new_type == "admin" ){
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

//Users::Users(const Users & U){
//    name = U.name;
//}

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
Admin::Admin(): Users(){
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

Admin::Admin(string _name, string _type, char _pid[7]):Users(_name, _type){
    if(_type == "admin"){
        for(int i = 0; i < 7; i++){
            pid[i] = _pid[i];

        }

    }

    else cout << "wrong type specified" <<  endl;
}

/* Copy constructor*/

//Admin::Admin(const Admin & A){
//    for(int i = 0; i < 7; i++){
//        pid[i] = A.pid[i];

//    }
//}

/* Destructor */

Admin::~Admin(){
}


//void Admin::createc(Courses& _course, int _credits, string* _list_students, float* _list_marks, int _size_students, int _size_marks, char new_id[7], string new_status ){

//   _course.setcredits(_credits);
//   _course.setsize_students(_size_students);
//   _course.setsize_marks(_size_marks);
//   _course.setlist_students(_list_students, _size_students);
//   _course.setlist_marks(_list_marks, _size_marks);
//   _course.resource->setid(new_id);
//   _course.resource->setstatus(new_status);

//}

//void Admin::displayc(Courses _course){

//    int credit = _course.getcredits();
//    string* list_of_students = _course.getlist_students();
//    float* list_of_marks = _course.getlist_marks();
//    char id[7];
//    string status = _course.resource->status ;

//    for(int i = 0 ; i < 7 ; i++){
//        id[i] = _course.resource->id[i];

//    }

//    cout << "The course ID is " << id << endl;
//    cout << "The course is" << status << endl;
//    cout << "This course has " << credit << " number of credits." << endl;

//    cout << "This course has these students along with their marks: " << endl;

//    for(int i = 0 ; i < _course.size_students ; i++){
//        cout << i+1 << ". " << list_of_students[i] << " with " << list_of_marks[i] << " marks"<< endl;

//    }


//}



void Admin::createu() {

    /*For names and degrees, use underscore for separating or only put first names, no spaces condition*/

    string name_user;
    char identity_type = '0';
    cout << endl << "Please fill the name of the new user." << endl;
    cin >> name_user;
    cout << endl << "Please press the alphabet corresponding to their identity (a-Administrator, s-Student, p-Professor)" << endl;
    cin >> identity_type;
    while (identity_type != 'a' && identity_type != 'A' && identity_type != 's' && identity_type != 'S' && identity_type != 'p' && identity_type != 'P'){
        cin >> identity_type;
    }


    if(identity_type == 's' || identity_type == 'S') {


        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv", ios::out | ios::app);
        if (data.is_open()){
            //Student newu;
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

            //plus add new object to list of objects

            cout << newuser->getname() << "," << newuser->getsin() << "," << newuser->getdegree() << endl;

            data << newuser->getname() << "," << newuser->getsin() << "," << newuser->getdegree() << "\n" ;
            data.close();
            cout << "fin" << endl;
            delete newuser;

        }
        else { cout << "Sorry the Virtual Campus was unable to add data. Please start the program again in order to try again." << endl; }



    }

    if (identity_type == 'a' || identity_type == 'A') {
        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/admins.csv", ios::out | ios::app);
        if (data.is_open()){
            Admin *newuser = new Admin;
            newuser->setname(name_user);
            cout << "Give the PID of this person." << endl;
            char newpid[7];
            cin >> newpid;
            newuser->setpid(newpid);
            //plus add new object to list of objects

            cout << newuser->getname() << "," << newuser->getpid() << "\n" << endl;

            data << newuser->getname() << "," << newuser->getpid() << "\n" ;
            data.close();
            cout << "fin" << endl;
            delete newuser;

        }
        else { cout << "Sorry the Virtual Campus was unable to add data. Please start the program again in order to try again." << endl; }



    }


    if (identity_type == 'p' || identity_type == 'P') {

        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/professors.csv", ios::out | ios::app);
        if (data.is_open()){

            Professor *newuser = new Professor;
            newuser->setname(name_user);
            cout << "Give the PID of this person." << endl;
            char new2pid[7];
            cin >> new2pid;

            newuser->setpid(new2pid);

            //plus add new object to list of objects
            cout << newuser->getname() << "," << newuser->getpid() << "\n" << endl;
            data << newuser->getname() << "," << newuser->getpid() << "\n" ;

            data.close();
            delete newuser;
        }
        else { cout << "Sorry the Virtual Campus was unable to add data. Please start the program again in order to try again." << endl; }



    }






}


void Admin::modifyu(){

//    string name_user;
    char identity_type;
    char change_type;
    int line_n;
//    cout << endl << "Please fill the name of the user to be modified." << endl;
//    cin >> name_user;
    cout << endl << "Please press the alphabet corresponding to the identity of the user to be modified (a-Administrator, s-Student, p-Professor)" << endl;
    cin >> identity_type;
    while (identity_type != 'a' && identity_type != 'A' && identity_type != 's' && identity_type != 'S' && identity_type != 'p' && identity_type != 'P'){
        cin >> identity_type;
    }

    char pid[7];


    if(identity_type == 's' || identity_type == 'S') {



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

        while(Myfile.good()){

            getline(Myfile, name_obj, ',');

            bool h = Myfile.good();
            if(h){

                i++;
                name_ob.push_back(name_obj);
                //cout << "new line" << endl;



                //cout << "Name: " << name_ob[i-1] << " ";
                getline(Myfile, id_obj, ',');
                id_ob.push_back(id_obj);
                //cout << "ID: " << id_ob[i-1] << " " ;

                getline(Myfile, deg_obj, '\n');
                degrees.push_back(deg_obj);
                //cout << "Degree: " << degrees[i-1] << endl ;

            }


    }


int count = 0;
        for(size_t j = 0; j < id_ob.size(); j++){

                if (id_ob[j].find(pid) != string::npos){

                    cout << "Name: " << name_ob[j] << " ";
                    cout << "ID: " << id_ob[j] << " ";
                    cout << "Degree: " << degrees[j] << endl;
                    line_n = j;
                    count++;
                    //cout << "Line number: " << j+1 << endl;
                }




        }



        if(count == 0){
            cout << "Sorry that id number is not registered in the database." << endl;
            return;

        }

        Student *newuser = new Student;


        cout << "Please press : n - for changing name, i - for changing sin, d - for changing degree" << endl;

        cin >> change_type;
        while (change_type != 'n' && change_type != 'N' && change_type != 'i' && change_type != 'I' && change_type != 'd' && change_type != 'D'){
            cin >> change_type;
        }

        if (change_type == 'n' || identity_type == 'N'){

            string newname;
            cout << "Give the new name for user." << endl;
            cin >> newname;
            newuser->setname(newname);
            name_ob[line_n] = newuser->getsin();
            cout << name_ob[line_n] << endl;


            fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv", ios::out | ios::trunc);
            if (data.is_open()){
                for(size_t j; j < name_ob.size(); j++){
                    cout << name_ob[j] << "," << id_ob[j] << "," << degrees[j] << endl;
                    data << name_ob[j] << "," << id_ob[j] << "," << degrees[j] << "\n" ;

                }


                data.close();
            }


        }


        if (change_type == 'i' || identity_type == 'I'){

            char newsin[7];

            cout << "Give the new SIN for user." << endl;
            cin >> newsin;
            newuser->setsin(newsin);

            id_ob[line_n] = newuser->getsin();
            cout << id_ob[line_n] << endl;

            fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv", ios::out | ios::trunc);
            if (data.is_open()){

                for(size_t j = 0; j < name_ob.size(); j++){

                    cout << name_ob[j] << "," << id_ob[j] << "," << degrees[j] << endl;
                    data << name_ob[j] << "," << id_ob[j] << "," << degrees[j] << "\n" ;

                }


                data.close();
            }


        }


        if (change_type == 'd' || identity_type == 'D'){

            string newdegree;

            cout << "Give the new degree for user." << endl;
            cin >> newdegree;
            newuser->setdegree(newdegree);

            id_ob[line_n] = newuser->getdegree();
            cout << id_ob[line_n] << endl;


            fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv", ios::out | ios::trunc);
            if (data.is_open()){
                for(size_t j; j < name_ob.size(); j++){
                    cout << name_ob[j] << "," << id_ob[j] << "," << degrees[j] << endl;
                    data << name_ob[j] << "," << id_ob[j] << "," << degrees[j] << "\n" ;

                }


                data.close();
            }


        }
        delete newuser;
    }






    if(identity_type == 'p' || identity_type == 'P') {



        cout << endl << "Please provide the PID of the user to be modified." << endl;
        cin >> pid;

        string name_obj;
        string id_obj;


        vector <string> name_ob;
        vector <string> id_ob;

        int i = 0;


        ifstream Myfile;
        Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/professors.csv");

        while(Myfile.good()){

            getline(Myfile, name_obj, ',');

            bool h = Myfile.good();
            if(h){

                i++;
                name_ob.push_back(name_obj);
                //cout << "new line" << endl;



                //cout << "Name: " << name_ob[i-1] << " ";
                getline(Myfile, id_obj, '\n');
                id_ob.push_back(id_obj);
                //cout << "ID: " << id_ob[i-1] << " " ;


            }


    }


int count = 0;
        for(size_t j = 0; j < id_ob.size(); j++){

                if (id_ob[j].find(pid) != string::npos){

                    cout << "Name: " << name_ob[j] << " ";
                    cout << "ID: " << id_ob[j] << " ";
                    line_n = j;
                    count++;
                    //cout << "Line number: " << j+1 << endl;
                }




        }



        if(count == 0){
            cout << "Sorry that id number is not registered in the database." << endl;
            return;

        }

        Professor *newuser = new Professor;


        cout << "Please press : n - for changing name, i - for changing pid" << endl;

        cin >> change_type;
        while (change_type != 'n' && change_type != 'N' && change_type != 'i' && change_type != 'I' ){
            cin >> change_type;
        }

        if (change_type == 'n' || identity_type == 'N'){

            string newname;
            cout << "Give the new name for user." << endl;
            cin >> newname;
            newuser->setname(newname);
            name_ob[line_n] = newuser->getname();
            cout << name_ob[line_n] << endl;


            fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/professors.csv", ios::out | ios::trunc);
            if (data.is_open()){
                for(size_t j; j < name_ob.size(); j++){
                    cout << name_ob[j] << "," << id_ob[j] << endl;
                    data << name_ob[j] << "," << id_ob[j] << "\n" ;

                }


                data.close();
            }


        }


        if (change_type == 'i' || identity_type == 'I'){

            char newpid[7];

            cout << "Give the new PID for user." << endl;
            cin >> newpid;
            newuser->setpid(newpid);

            id_ob[line_n] = newuser->getpid();
            cout << id_ob[line_n] << endl;

            fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/professors.csv", ios::out | ios::trunc);
            if (data.is_open()){

                for(size_t j = 0; j < name_ob.size(); j++){

                    cout << name_ob[j] << "," << id_ob[j] << endl;
                    data << name_ob[j] << "," << id_ob[j] << "\n" ;

                }


                data.close();
            }


        }


        delete newuser;
    }




    if(identity_type == 'a' || identity_type == 'A') {



        cout << endl << "Please provide the PID of the user to be modified." << endl;
        cin >> pid;

        string name_obj;
        string id_obj;


        vector <string> name_ob;
        vector <string> id_ob;

        int i = 0;


        ifstream Myfile;
        Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/admins.csv");

        while(Myfile.good()){

            getline(Myfile, name_obj, ',');

            bool h = Myfile.good();
            if(h){

                i++;
                name_ob.push_back(name_obj);
                //cout << "new line" << endl;



                //cout << "Name: " << name_ob[i-1] << " ";
                getline(Myfile, id_obj, '\n');
                id_ob.push_back(id_obj);
                //cout << "ID: " << id_ob[i-1] << " " ;


            }


    }


int count = 0;
        for(size_t j = 0; j < id_ob.size(); j++){

                if (id_ob[j].find(pid) != string::npos){

                    cout << "Name: " << name_ob[j] << " ";
                    cout << "ID: " << id_ob[j] << " ";
                    line_n = j;
                    count++;
                    //cout << "Line number: " << j+1 << endl;
                }




        }



        if(count == 0){
            cout << "Sorry that id number is not registered in the database." << endl;
            return;

        }

        Admin *newuser = new Admin;


        cout << "Please press : n - for changing name, i - for changing pid" << endl;

        cin >> change_type;
        while (change_type != 'n' && change_type != 'N' && change_type != 'i' && change_type != 'I' ){
            cin >> change_type;
        }

        if (change_type == 'n' || identity_type == 'N'){

            string newname;
            cout << "Give the new name for user." << endl;
            cin >> newname;
            newuser->setname(newname);
            name_ob[line_n] = newuser->getname();
            cout << name_ob[line_n] << endl;


            fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/admins.csv", ios::out | ios::trunc);
            if (data.is_open()){
                for(size_t j; j < name_ob.size(); j++){
                    cout << name_ob[j] << "," << id_ob[j] << endl;
                    data << name_ob[j] << "," << id_ob[j] << "\n" ;

                }


                data.close();
            }


        }


        if (change_type == 'i' || identity_type == 'I'){

            char newpid[7];

            cout << "Give the new PID for user." << endl;
            cin >> newpid;
            newuser->setpid(newpid);

            id_ob[line_n] = newuser->getpid();
            cout << id_ob[line_n] << endl;

            fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/admins.csv", ios::out | ios::trunc);
            if (data.is_open()){

                for(size_t j = 0; j < name_ob.size(); j++){

                    cout << name_ob[j] << "," << id_ob[j] << endl;
                    data << name_ob[j] << "," << id_ob[j] << "\n" ;

                }


                data.close();
            }


        }


        delete newuser;
    }





}



void Admin::deleteu() {

        char identity_type;

        int line_n;

        cout << endl << "Please press the alphabet corresponding to the identity of the user to be modified (a-Administrator, s-Student, p-Professor)" << endl;
        cin >> identity_type;
        while (identity_type != 'a' && identity_type != 'A' && identity_type != 's' && identity_type != 'S' && identity_type != 'p' && identity_type != 'P'){
            cin >> identity_type;
        }

        char pid[7];


        if(identity_type == 's' || identity_type == 'S') {



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

            while(Myfile.good()){

                getline(Myfile, name_obj, ',');

                bool h = Myfile.good();
                if(h){

                    i++;
                    name_ob.push_back(name_obj);
                    //cout << "new line" << endl;



                    //cout << "Name: " << name_ob[i-1] << " ";
                    getline(Myfile, id_obj, ',');
                    id_ob.push_back(id_obj);
                    //cout << "ID: " << id_ob[i-1] << " " ;

                    getline(Myfile, deg_obj, '\n');
                    degrees.push_back(deg_obj);
                    //cout << "Degree: " << degrees[i-1] << endl ;

                }


        }


    int count = 0;
            for(size_t j = 0; j < id_ob.size(); j++){

                    if (id_ob[j].find(pid) != string::npos){

                        cout << "Name: " << name_ob[j] << " ";
                        cout << "ID: " << id_ob[j] << " ";
                        cout << "Degree: " << degrees[j] << endl;
                        line_n = j;
                        count++;
                        //cout << "Line number: " << j+1 << endl;
                    }




            }



            if(count == 0){
                cout << "Sorry that id number is not registered in the database." << endl;
                return;

            }

            for(size_t j = line_n; j < name_ob.size(); j++){
                name_ob[j] = name_ob[j+1];
                id_ob[j] = id_ob[j+1];
                degrees[j] = degrees[j+1];

            }

            fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv", ios::out | ios::trunc);
                if (data.is_open()){
                    for(size_t j; j < name_ob.size(); j++){
                        cout << name_ob[j] << "," << id_ob[j] << "," << degrees[j] << endl;
                        data << name_ob[j] << "," << id_ob[j] << "," << degrees[j] << "\n" ;

                    }


                    data.close();
                }


            }


        if(identity_type == 'p' || identity_type == 'P') {



            cout << endl << "Please provide the PID of the user to be deleted." << endl;
            cin >> pid;

            string name_obj;
            string id_obj;

            vector <string> name_ob;
            vector <string> id_ob;

            int i = 0;


            ifstream Myfile;
            Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/professors.csv");

            while(Myfile.good()){

                getline(Myfile, name_obj, ',');

                bool h = Myfile.good();
                if(h){

                    i++;
                    name_ob.push_back(name_obj);
                    //cout << "new line" << endl;



                    //cout << "Name: " << name_ob[i-1] << " ";
                    getline(Myfile, id_obj, '\n');
                    id_ob.push_back(id_obj);
                    //cout << "ID: " << id_ob[i-1] << " " ;

                }


        }


    int count = 0;
            for(size_t j = 0; j < id_ob.size(); j++){

                    if (id_ob[j].find(pid) != string::npos){

                        cout << "Name: " << name_ob[j] << " ";
                        cout << "ID: " << id_ob[j] << " ";

                        line_n = j;
                        count++;
                        //cout << "Line number: " << j+1 << endl;
                    }




            }



            if(count == 0){
                cout << "Sorry that id number is not registered in the database." << endl;
                return;

            }

            for(size_t j = line_n; j < name_ob.size(); j++){
                name_ob[j] = name_ob[j+1];
                id_ob[j] = id_ob[j+1];


            }

            fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/professors.csv", ios::out | ios::trunc);
                if (data.is_open()){
                    for(size_t j; j < name_ob.size(); j++){
                        cout << name_ob[j] << "," << id_ob[j] << endl;
                        data << name_ob[j] << "," << id_ob[j] << "\n" ;

                    }


                    data.close();
                }


            }

        if(identity_type == 'a' || identity_type == 'A') {



            cout << endl << "Please provide the PID of the user to be deleted." << endl;
            cin >> pid;

            string name_obj;
            string id_obj;

            vector <string> name_ob;
            vector <string> id_ob;

            int i = 0;


            ifstream Myfile;
            Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/admins.csv");

            while(Myfile.good()){

                getline(Myfile, name_obj, ',');

                bool h = Myfile.good();
                if(h){

                    i++;
                    name_ob.push_back(name_obj);
                    //cout << "new line" << endl;



                    //cout << "Name: " << name_ob[i-1] << " ";
                    getline(Myfile, id_obj, '\n');
                    id_ob.push_back(id_obj);
                    //cout << "ID: " << id_ob[i-1] << " " ;

                }


        }


    int count = 0;
            for(size_t j = 0; j < id_ob.size(); j++){

                    if (id_ob[j].find(pid) != string::npos){

                        cout << "Name: " << name_ob[j] << " ";
                        cout << "ID: " << id_ob[j] << " ";

                        line_n = j;
                        count++;
                        //cout << "Line number: " << j+1 << endl;
                    }




            }

            if(count == 0){
                cout << "Sorry that id number is not registered in the database." << endl;
                return;

            }

            for(size_t j = line_n; j < name_ob.size(); j++){
                name_ob[j] = name_ob[j+1];
                id_ob[j] = id_ob[j+1];


            }

            fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/admins.csv", ios::out | ios::trunc);
                if (data.is_open()){
                    for(size_t j; j < name_ob.size(); j++){
                        cout << name_ob[j] << "," << id_ob[j] << endl;
                        data << name_ob[j] << "," << id_ob[j] << "\n" ;

                    }


                    data.close();
                }


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


vector <Seminars> Professor::getlist_seminars(){
    return list_seminars;
}


vector <Courses> Professor::getlist_courses(){
    return list_courses;
}


vector <Project> Professor::getlist_projects(){
    return list_projects;
}


void Professor::setlist_courses(vector<Courses> new_list_courses){
    list_courses = new_list_courses;
}


void Professor::setlist_seminars(vector<Seminars> new_list_seminars){
    list_seminars = new_list_seminars;
}

void Professor::setlist_projects(vector<Project> new_list_projects){
    list_projects = new_list_projects;
}


/* Default constructor*/
Professor::Professor():Users(){
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

Professor::Professor(string _name, string _type, char _pid[7], vector <Seminars> _list_seminars, vector <Courses> _list_courses, vector <Project> _list_projects) : Users(_name, _type){
    if(_type == "professor"){
        for(int i = 0; i < 7; i++){
            pid[i] = _pid[i];

        }
        list_seminars = _list_seminars;
        list_courses = _list_courses;
        list_projects = _list_projects;

    }




    else cout << "wrong specified type" << endl;


}

/* Copy constructor*/

//Professor::Professor(const Professor & Pr){
//    for(int i = 0; i < 7; i++){
//        pid[i] = Pr.pid[i];

//    }
//}

/* Destructor */

Professor::~Professor(){
}

////////////////////////////////////
//
////////////////////////////////////

char *Student::getsin() {
    return sin;
}

string Student::getdegree(){
    return degree;
}

vector<Courses> Student::getlist_courses() {
    return list_courses;
}

vector <Seminars> Student::getlist_sem() {
    return list_sem;
}

Project *Student::getproject() {
    return project;
}

void Student::setsin(char new_sin[7]) {
    if(isdigit(new_sin[0]) && isdigit(new_sin[1]) && isdigit(new_sin[2]) && isdigit(new_sin[3]) && isdigit(new_sin[4]) && isdigit(new_sin[5]) && isdigit(new_sin[6])){
        for(int i = 0; i < 7; i++){
            sin[i] = new_sin[i];

        }

    }
    else cout << "wrong sin format" <<  endl;

}


/* Here new_list_courses is a dynamic array of length "new_size_courses" */


void Student::setlist_courses(vector <Courses> new_list_courses) {

    list_courses = new_list_courses;
}

/* Here new_list_sem is a dynamic array of length "new_size_sems" */


void Student::setlist_sem(vector <Seminars> new_list_sem) {

    list_sem = new_list_sem;

}

/* Here new_list_project is a dynamic array of length "new_size_projects" */

void Student::setproject(Project *new_project) {
    project = new_project;
}

void Student::setdegree(string new_degree){
    degree = new_degree;
}


/* Default constructor*/
Student::Student():Users(){

    vector <Courses> listcourses;
    vector <Seminars> listsem;

    sin[0] = '0';
    sin[1] = '0';
    sin[2] = '0';
    sin[3] = '0';
    sin[4] = '0';
    sin[5] = '0';
    sin[6] = '0';
    sin[7] = '\0';
    Project* p;
    project = p;
    degree = "not assigned";

    list_courses = listcourses;
    list_sem = listsem;


    /* Here it is assumed that the default value of pid is "0000000" */

}

/* Parametrized constructor*/

Student::Student(string _name, string _type, char _sin[7], string _degree, vector <Courses> _list_courses, vector <Seminars> _list_sem, Project* _project):Users(_name, _type){
    if(_type == "student"){
        if(isdigit(_sin[0]) && isdigit(_sin[1]) && isdigit(_sin[2]) && isdigit(_sin[3]) && isdigit(_sin[4]) && isdigit(_sin[5]) && isdigit(_sin[6])){
            for(int i = 0; i < 7; i++){
                sin[i] = _sin[i];

            }

        }
        else cout << "wrong sin format" <<  endl;

        list_courses = _list_courses;
        list_sem = _list_sem;
        degree = _degree;
        project = _project;

    }
    else cout << "wrong specified type" << endl;




}

/* Copy constructor*/

//Student::Student(const Student & S){

//    for(int i = 0; i < 7; i++){
//        sin[i] = S.sin[i];

//    }

//    size_courses = S.size_courses;
//    list_courses = new string[size_courses];
//    list_courses = S.list_courses;
//    size_sems = S.size_sems;
//    list_sem = new string[size_sems];
//    list_sem = S.list_sem;
//    size_projects = S.size_projects;
//    list_project = new string[size_projects];
//    list_project = S.list_project;

//}

/* Destructor */

Student::~Student(){

}


////////////////////////////////////
//
////////////////////////////////////
