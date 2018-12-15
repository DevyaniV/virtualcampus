#include <iostream>
#include "virtual_campus.h"
#include <fstream>
#include <sstream>
#include <numeric>
#include <string>
#include <cstdlib>
#include <cstring>
#include <string.h>

using namespace std;


void VirtualCampus::start(){

    cout << "Welcome to virtual campus!" << endl;
    char a;


    cout << "Please enter your identity alphabet (S - student, P - professor, A - Admin)" << endl;
    cin >> a;
    while (a != 's' && a != 'S' && a != 'p' && a != 'P' && a != 'a' && a != 'A'){
        cin >> a;
    }

    if(a == 'S'|a == 's'){
        char sin[7];
        cout << "Please enter your SIN" << endl;
        cin >> sin;

/////////////////////////////////student authentication process///////////////////////////////////////

        string name_obj;
        string id_obj;
        string deg_obj;
        int line_n;

        string pro;
        string cour;
        string sem;

        vector <string> name_ob;
        vector <string> id_ob;
        vector <string> degrees;

        vector <string> courses;

        vector <string> seminars;
        vector <string> project;



        fstream Myfile;
        int line = -1;

        Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv");

        while(Myfile.good()){

            line++;


            if(line%4 == 0){
                getline(Myfile, name_obj, ',');

                bool h = Myfile.good();
                if(h){


                    name_ob.push_back(name_obj);


                    getline(Myfile, id_obj, ',');
                    id_ob.push_back(id_obj);


                    getline(Myfile, deg_obj, '\n');
                    degrees.push_back(deg_obj);



                }
            }
            if(line%4==1){

                getline(Myfile, cour, '\n');
                courses.push_back(cour);


            }

            if(line%4==2){
                getline(Myfile, sem, '\n');
                seminars.push_back(sem);


            }

            if(line%4==3){
                getline(Myfile, pro, '\n');
                project.push_back(pro);


            }
        }



        int count = 0;
        for(size_t j = 0; j < id_ob.size(); j++){

            if (id_ob[j].find(sin) != string::npos){


                line_n = j;
                count++;
            }
        }


        if(count == 0){
            cout << "Sorry your id number is not registered in the database." << endl;
            return;

        }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////


        Student* currentst = new Student;

        char b;

        cout << "Please press the number for the desired task" << endl;
        cout << "A - Enroll in a resource" << endl;
        cout << "B - Drop a resource" << endl;
        cout << "C - Exit the application" << endl;

        cin >> b;
        while (b != 'a' && b != 'A' && b != 'b' && b != 'B' && b != 'c' && b != 'C'){
            cin >> b;
        }

        if(b == 'a' || b == 'A'){
            currentst->enroll(sin);
            delete currentst;
            return;
        }


        if(b == 'b' || b == 'B'){
            currentst->drop(sin);
            delete currentst;
            return;
        }

        if(b == 'c' || b == 'C'){
            cout << "Exiting the application. Byeee" << endl;
            delete currentst;
            return;
        }
    }


    if(a == 'p'|a == 'P'){
        char pidp[7];
        cout << "Please enter your PID" << endl;
        cin >> pidp;

/////////////////////////////////professor authentication process///////////////////////////////////////

        string name_obj;
        string id_obj;

        vector <string> name_ob;
        vector <string> id_ob;
        int line_n;



        ifstream Myfile;
        Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/professors.csv");

        while(Myfile.good()){


                getline(Myfile, name_obj, ',');

                bool h = Myfile.good();
                if(h){


                    name_ob.push_back(name_obj);

                    getline(Myfile, id_obj, '\n');
                    id_ob.push_back(id_obj);


                }

            }




        int count = 0;
        for(size_t j = 0; j < id_ob.size(); j++){

            if (id_ob[j].find(pidp) != string::npos){

                line_n = j;
                count++;
            }




        }



        if(count == 0){
            cout << "Sorry that id number is not registered in the database." << endl;
            return;

        }


/////////////////////////////////////////////////////////////////////////////////////////////////////////////

        Professor* currentpr = new Professor;
        char c;

        cout << "Please press the number for the desired task" << endl;
        cout << "A - Set students marks" << endl;
        cout << "B - Modify the resources you are incharge of" << endl;
        cout << "C - Exit the application" << endl;

        cin >> c;
        while (c != 'a' && c != 'A' && c != 'b' && c != 'B' && c != 'c' && c != 'C'){
            cin >> c;
        }

        if(c == 'a' || c == 'A'){
            currentpr->setmarks(pidp);
            delete currentpr;
            return;
        }


        if(c == 'b' || c == 'B'){
            currentpr->modifyr(pidp);
            delete currentpr;
            return;
        }

        if(c == 'c' || c == 'C'){
            cout << "Exiting the application. Byeee" << endl;
            delete currentpr;
            return;
        }
    }


    if(a == 'a'|a == 'A'){
        char pida[7];
        cout << "Please enter your PID" << endl;
        cin >> pida;

/////////////////////////////////admin authentication process///////////////////////////////////////

        string name_obj;
        string id_obj;


        vector <string> name_ob;
        vector <string> id_ob;
        int line_n;




        ifstream Myfile;
        Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/admins.csv");

        while(Myfile.good()){


            getline(Myfile, name_obj, ',');

            bool h = Myfile.good();
            if(h){


                name_ob.push_back(name_obj);

                getline(Myfile, id_obj, '\n');
                id_ob.push_back(id_obj);


            }

        }





        int count = 0;
        for(size_t j = 0; j < id_ob.size(); j++){

            if (id_ob[j].find(pida) != string::npos){


                line_n = j;
                count++;
            }
        }

        if(count == 0){
            cout << "Sorry that id number is not registered in the database." << endl;
            return;

        }


/////////////////////////////////////////////////////////////////////////////////////////////////////////////

        Admin *currentad = new Admin;
        char d;

        cout << "Please press the number for the desired task" << endl;
        cout << "A - Create resources" << endl;
        cout << "B - Modify resources" << endl;
        cout << "C - Delete resources" << endl;
        cout << "D - Create users" << endl;
        cout << "E - Modify users" << endl;
        cout << "F - Delete users" << endl;
        cout << "G - See the virtual campus database" << endl;
        cout << "H - Exit the application" << endl;

        cin >> d;
        while (d != 'a' && d != 'A' && d != 'b' && d != 'B' && d != 'c' && d != 'C' && d != 'd' && d != 'D' && d != 'e' && d != 'E' && d != 'f' && d != 'F' && d != 'g' && d != 'G' && d != 'h' && d != 'H'){
            cin >> d;
        }

        if(d == 'a' || d == 'A'){
            currentad->creater();
            delete currentad;
            return;
        }


        if(d == 'b' || d == 'B'){
            currentad->modifyr();
            delete currentad;
            return;
        }

        if(d == 'c' || d == 'C'){
            currentad->deleter();
            delete currentad;
            return;
        }

        if(d == 'd' || d == 'D'){
            currentad->createu();
            delete currentad;
            return;
        }

        if(d == 'e' || d == 'E'){
            currentad->modifyu();
            delete currentad;
            return;
        }

        if(d == 'f' || d == 'F'){
            currentad->deleteu();
            delete currentad;
            return;
        }

        if(d == 'g' || d == 'G'){

            char e;
            cout << "Please press the number for the desired task" << endl;
            cout << "A - Show administrator database" << endl;
            cout << "B - Show student database" << endl;
            cout << "C - Show professor database" << endl;
            cout << "D - Show course database" << endl;
            cout << "E - Show seminar database" << endl;
            cout << "F - Show final degree project database" << endl;

            cin >> e;
            while (e != 'a' && e != 'A' && e != 'b' && e != 'B' && e != 'c' && e != 'C' && e != 'd' && e != 'D' && e != 'e' && e != 'E' && e != 'f' && e != 'F'){
                cin >> e;
            }

            if(e == 'a' || e == 'A'){
                currentad->BeginAction("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/admins.csv");
                delete currentad;
                return;
            }


            if(e == 'b' || e == 'B'){
                currentad->BeginAction("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv");
                delete currentad;
                return;
            }

            if(e == 'c' || e == 'C'){
                currentad->BeginAction("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/professors,csv");
                delete currentad;
                return;
            }

            if(e == 'd' || e == 'D'){
                currentad->BeginAction("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/courses.csv");
                delete currentad;
                return;
            }

            if(e == 'e' || e == 'E'){
                currentad->BeginAction("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/seminars.csv");
                delete currentad;
                return;
            }

            if(e == 'f' || e == 'F'){
                currentad->BeginAction("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/project.csv");
                delete currentad;
                return;
            }
        }

        if(d == 'h' || d == 'H'){
            cout << "Exiting the application. Byeee" << endl;
            delete currentad;
            return;
        }
    }

}



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
    if(new_status == "created" || new_status == "in_progress" || new_status == "completed"){
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

void Project::setco_tutor(Professor *new_co_tutor){
    co_tutor = new_co_tutor;
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

void Courses::setdegree(string new_degree){
    degree = new_degree;
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




void Admin::createu() {

    /*For names and degrees, use underscore for separating or only put first names; no spaces condition*/

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

            data << newuser->getname() << "," << newuser->getsin() << "," << newuser->getdegree() << "\n" ;
            data << "\n";
            data << "\n";
            data << "\n";
            data.close();

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


            cout << newuser->getname() << "," << newuser->getpid() << " has been added" << endl;

            data << newuser->getname() << "," << newuser->getpid() << "\n" ;
            data.close();

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


            cout << newuser->getname() << "," << newuser->getpid() << " has been added" << endl;
            data << newuser->getname() << "," << newuser->getpid() << "\n" ;


            data.close();
            delete newuser;
        }
        else { cout << "Sorry the Virtual Campus was unable to add data. Please start the program again in order to try again." << endl; }



    }






}


void Admin::modifyu(){

    char identity_type;
    char change_type;
    int line_n;
    cout << endl << "Please press the alphabet corresponding to the identity of the user to be modified (a-Administrator, s-Student, p-Professor)" << endl;
    cin >> identity_type;
    while (identity_type != 'a' && identity_type != 'A' && identity_type != 's' && identity_type != 'S' && identity_type != 'p' && identity_type != 'P'){
        cin >> identity_type;
    }

    char pid[7];


    if(identity_type == 's' || identity_type == 'S') {



        cout << "Please provide the SIN of the user to be modified." << endl;
        cin >> pid;

        string name_obj;
        string id_obj;
        string deg_obj;
        string cour;
        string sem;
        string pro;

        vector <string> name_ob;
        vector <string> id_ob;
        vector <string> degrees;
        vector <string> courses;
        vector <string> seminars;
        vector <string> project;



        fstream Myfile;
        int line = -1;
        Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv");

        while(Myfile.good()){

            line++;

            if(line%4 == 0){
                getline(Myfile, name_obj, ',');

                bool h = Myfile.good();
                if(h){


                    name_ob.push_back(name_obj);

                    getline(Myfile, id_obj, ',');
                    id_ob.push_back(id_obj);

                    getline(Myfile, deg_obj, '\n');
                    degrees.push_back(deg_obj);


                }
            }
            if(line%4==1){
                getline(Myfile, cour, '\n');
                courses.push_back(cour);


            }
            if(line%4==2){
                getline(Myfile, sem, '\n');
                seminars.push_back(sem);

            }
            if(line%4==3){
                getline(Myfile, pro, '\n');
                project.push_back(pro);


            }









        }


        int count = 0;
        for(size_t j = 0; j < id_ob.size(); j++){

            if (id_ob[j].find(pid) != string::npos){


                line_n = j;
                count++;
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
            name_ob[line_n] = newuser->getname();


        }


        if (change_type == 'i' || identity_type == 'I'){

            char newsin[7];

            cout << "Give the new SIN for user." << endl;
            cin >> newsin;
            newuser->setsin(newsin);

            id_ob[line_n] = newuser->getsin();



        }


        if (change_type == 'd' || identity_type == 'D'){

            string newdegree;

            cout << "Give the new degree for user." << endl;
            cin >> newdegree;
            newuser->setdegree(newdegree);

            degrees[line_n] = newuser->getdegree();


        }




        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv", ios::out | ios::trunc);
        if (data.is_open()){

            for(size_t j = 0; j < name_ob.size(); j++){

                data << name_ob[j] << "," << id_ob[j] << "," << degrees[j] << "\n" ;
                data << courses[j] << "\n";
                data << seminars[j] << "\n";
                data << project[j] << "\n";



            }


            data.close();
            cout << "user modified." << endl;
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



        ifstream Myfile;
        Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/professors.csv");

        while(Myfile.good()){


                getline(Myfile, name_obj, ',');

                bool h = Myfile.good();
                if(h){


                    name_ob.push_back(name_obj);

                    getline(Myfile, id_obj, '\n');
                    id_ob.push_back(id_obj);


                }

            }




        int count = 0;
        for(size_t j = 0; j < id_ob.size(); j++){

            if (id_ob[j].find(pid) != string::npos){

                line_n = j;
                count++;
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


        }


        if (change_type == 'i' || identity_type == 'I'){

            char newpid[7];

            cout << "Give the new PID for user." << endl;
            cin >> newpid;
            newuser->setpid(newpid);

            id_ob[line_n] = newuser->getpid();





        }


        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/professors.csv", ios::out | ios::trunc);
        if (data.is_open()){

            for(size_t j = 0; j < name_ob.size(); j++){

                data << name_ob[j] << "," << id_ob[j] << "\n" ;

            }


            data.close();
            cout << "user modified." << endl;
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




        ifstream Myfile;
        Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/admins.csv");

        while(Myfile.good()){


            getline(Myfile, name_obj, ',');

            bool h = Myfile.good();
            if(h){


                name_ob.push_back(name_obj);

                getline(Myfile, id_obj, '\n');
                id_ob.push_back(id_obj);


            }

        }





        int count = 0;
        for(size_t j = 0; j < id_ob.size(); j++){

            if (id_ob[j].find(pid) != string::npos){


                line_n = j;
                count++;
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


        }


        if (change_type == 'i' || identity_type == 'I'){

            char newpid[7];

            cout << "Give the new PID for user." << endl;
            cin >> newpid;
            newuser->setpid(newpid);

            id_ob[line_n] = newuser->getpid();


        }


        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/admins.csv", ios::out | ios::trunc);
        if (data.is_open()){
            for(size_t j = 0; j < name_ob.size(); j++){

                data << name_ob[j] << "," << id_ob[j] << "\n" ;


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
        int line = -1;

        string cour;
        string sem;
        string pro;

        vector <string> courses;
        vector <string> seminars;
        vector <string> project;



        ifstream Myfile;
        Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv");

        while(Myfile.good()){
            line++;

            if(line%4 == 0){
                getline(Myfile, name_obj, ',');

                bool h = Myfile.good();
                if(h){


                    name_ob.push_back(name_obj);

                    getline(Myfile, id_obj, ',');
                    id_ob.push_back(id_obj);

                    getline(Myfile, deg_obj, '\n');
                    degrees.push_back(deg_obj);


                }
            }
            if(line%4==1){
                getline(Myfile, cour, '\n');
                courses.push_back(cour);


            }
            if(line%4==2){
                getline(Myfile, sem, '\n');
                seminars.push_back(sem);

            }
            if(line%4==3){
                getline(Myfile, pro, '\n');
                project.push_back(pro);


            }

        }






        int count = 0;
        for(size_t j = 0; j < id_ob.size(); j++){

            if (id_ob[j].find(pid) != string::npos){

                line_n = j;
                count++;

            }




        }



        if(count == 0){
            cout << "Sorry that id number is not registered in the database." << endl;
            return;

        }


        name_ob.erase(name_ob.begin() + line_n);
        id_ob.erase(id_ob.begin() + line_n);
        degrees.erase(degrees.begin() + line_n);
        courses.erase(courses.begin() + line_n);
        seminars.erase(seminars.begin() + line_n );
        project.erase(project.begin() + line_n);




        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv", ios::out | ios::trunc);
        if (data.is_open()){

            for(size_t j = 0 ; j < name_ob.size(); j++){


                data << name_ob[j] << "," << id_ob[j] << "," << degrees[j] << "\n" ;
                data << courses[j] << "\n";
                data << seminars[j] << "\n";
                data << project[j] << "\n";

            }


            data.close();
            cout << "user deleted." << endl;
        }


    }


    if(identity_type == 'p' || identity_type == 'P') {



        cout << endl << "Please provide the PID of the user to be deleted." << endl;
        cin >> pid;

        string name_obj;
        string id_obj;

        vector <string> name_ob;
        vector <string> id_ob;




        ifstream Myfile;
        Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/professors.csv");

        while(Myfile.good()){

            getline(Myfile, name_obj, ',');

            bool h = Myfile.good();
            if(h){


                name_ob.push_back(name_obj);

                getline(Myfile, id_obj, '\n');
                id_ob.push_back(id_obj);

            }


        }


        int count = 0;
        for(size_t j = 0; j < id_ob.size(); j++){

            if (id_ob[j].find(pid) != string::npos){

                line_n = j;
                count++;
            }




        }



        if(count == 0){
            cout << "Sorry that id number is not registered in the database." << endl;
            return;

        }

        name_ob.erase(name_ob.begin() + line_n);
        id_ob.erase(id_ob.begin() + line_n);


        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/professors.csv", ios::out | ios::trunc);
        if (data.is_open()){
            for(size_t j = 0; j < name_ob.size(); j++){

                data << name_ob[j] << "," << id_ob[j] << "\n" ;

            }


            data.close();
            cout << "user deleted." << endl;
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

                getline(Myfile, id_obj, '\n');
                id_ob.push_back(id_obj);

            }


        }


        int count = 0;
        for(size_t j = 0; j < id_ob.size(); j++){

            if (id_ob[j].find(pid) != string::npos){


                line_n = j;
                count++;
            }




        }

        if(count == 0){
            cout << "Sorry that id number is not registered in the database." << endl;
            return;

        }

        name_ob.erase(name_ob.begin() + line_n);
        id_ob.erase(id_ob.begin() + line_n);

        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/admins.csv", ios::out | ios::trunc);
        if (data.is_open()){
            for(size_t j = 0; j < name_ob.size(); j++){

                data << name_ob[j] << "," << id_ob[j] << "\n" ;

            }


            data.close();
            cout << "user deleted." << endl;
        }


    }


}




/*For names and degrees, use underscore for separating or only put first names; no spaces condition*/
void Admin::creater() {
    string status;
    char id[7];
    char identity_type = '0';

    cout << endl << "Please fill the id of the new resource(only 7 characters)." << endl;
    cin >> id;
    cout << endl << "Please press the alphabet corresponding to their identity (c-Course, s-Seminar, p-Project)" << endl;
    cin >> identity_type;
    while (identity_type != 'C' && identity_type != 'c' && identity_type != 's' && identity_type != 'S' && identity_type != 'p' && identity_type != 'P') {
        cin >> identity_type;
    }


    if (identity_type == 'c' || identity_type == 'c') {
        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/courses.csv", ios::out | ios::app);
        if (data.is_open()) {

            Courses *newcourse = new Courses;


            newcourse->setid(id);

            cout << "Give the PID of the first professor of this course." << endl;
            Professor* a1 = new Professor;
            char pid1[7];
            cin >> pid1;
            a1->setpid(pid1);
            newcourse->setprofessor1(a1);

            cout << "Give the PID of the second professor of this course." << endl;
            Professor* a2 = new Professor;
            char pid2[7];
            cin >> pid2;
            a2->setpid(pid2);
            newcourse->setprofessor2(a2);

            cout << "Give the number of credits of this course." << endl;
            int credits;
            cin >> credits;
            newcourse->setcredits(credits);

            cout << "Give the degree of this course." << endl;
            string degreea;
            cin >> degreea;
            newcourse->setdegree(degreea);

            cout << newcourse->getid() << "," << "created" << "," << newcourse->getprofessor1()->getpid() << "," << newcourse->getprofessor2()->getpid() << "," << newcourse->getcredits() << "," << newcourse->getdegree() << " has been added" << endl;

            data << newcourse->getid() << "," << "created" << "," << newcourse->getprofessor1()->getpid() << "," << newcourse->getprofessor2()->getpid() << ","  << newcourse->getcredits() <<  ","  << newcourse->getdegree() << "\n";
            data << "\n";
            data << "\n";
            data.close();

            delete newcourse;
            delete a1;
            delete a2;
        }
        else { cout << "Sorry the Virtual Campus was unable to add data. Please start the program again in order to try again." << endl; }
    }

    if (identity_type == 's' || identity_type == 'S') {
        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/seminars.csv", ios::out | ios::app);
        if (data.is_open()) {
            Seminars *newseminar = new Seminars;

            newseminar->setid(id);

            cout << "Give the PID of the coordinator of this seminar." << endl;
            Professor* a1 = new Professor;
            char pid1[7];
            cin >> pid1;
            a1->setpid(pid1);
            newseminar->setcoordinator(a1);

            cout << "Give the PID of the speaker of this seminar." << endl;
            Professor* a2 = new Professor;
            char pid2[7];
            cin >> pid2;
            a2->setpid(pid2);
            newseminar->setspeaker(a2);

            cout << "Give the date of this seminar." << endl;
            string date;
            cin >> date;
            newseminar->setdate(date);

            cout << "Give the maximum number of seats of this seminar." << endl;
            int max;
            cin >> max;
            newseminar->setmax_seats(max);

            cout << newseminar->getid() << "," << "created" << "," << newseminar->getcoordinator()->getpid() << "," << newseminar->getspeaker()->getpid() << "," << newseminar->getdate() << "," << newseminar->getmax_seats() << " has been added" << endl;

            data << newseminar->getid() << "," << "created" << "," << newseminar->getcoordinator()->getpid() << "," << newseminar->getspeaker()->getpid() << "," << newseminar->getdate() << "," << newseminar->getmax_seats() << "\n";
            data << "\n";
            data.close();

            delete newseminar;
            delete a1;
            delete a2;

        }
        else { cout << "Sorry the Virtual Campus was unable to add data. Please start the program again in order to try again." << endl; }
    }


    if (identity_type == 'p' || identity_type == 'P') {

        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/project.csv", ios::out | ios::app);
        if (data.is_open()) {

            Project *newproject = new Project;

            newproject->setid(id);

            cout << "Give the tutor of this project." << endl;
            Professor* a1 = new Professor;
            char pid1[7];
            cin >> pid1;
            a1->setpid(pid1);
            newproject->settutor(a1);

            cout << "Give the co-tutor of this project." << endl;
            Professor* a2 = new Professor;
            char pid2[7];
            cin >> pid2;
            a2->setpid(pid2);
            newproject->setco_tutor(a2);

            cout << "Give the degree of this project." << endl;
            string degree;
            cin >> degree;
            newproject->setdegree(degree);

            cout << newproject->getid() << "," << "created" << "," << newproject->gettutor()->getpid() << "," << newproject->getco_tutor()->getpid() << ","  << newproject->getdegree() << " has been added" << endl;

            data << newproject->getid() << "," << "created" << "," << newproject->gettutor()->getpid() << "," << newproject->getco_tutor()->getpid() << "," << newproject->getdegree() << "\n";
            data << "\n";
            data.close();

            delete newproject;
            delete a1;
            delete a2;
        }
        else { cout << "Sorry the Virtual Campus was unable to add data. Please start the program again in order to try again." << endl; }
    }
}


void Admin::modifyr() {

    char identity_type;
    char change_type;
    int line_n;
    cout << endl << "Please press the alphabet corresponding to the identity of the resource to be modified (c-Course, s-Seminar, p-Project)" << endl;
    cin >> identity_type;
    while (identity_type != 'c' && identity_type != 'C' && identity_type != 's' && identity_type != 'S' && identity_type != 'p' && identity_type != 'P') {
        cin >> identity_type;
    }

    char id[7];


    if (identity_type == 'c' || identity_type == 'C') {



        cout << "Please provide the ID of the resource to be modified." << endl;
        cin >> id;

        string id_obj;
        string status_obj;
        string professor1_obj;
        string professor2_obj;
        string degree_obj;
        string credits_obj;
        string stud;
        string mark;

        vector <string> status_ob;
        vector <string> id_ob;
        vector <string> professors1_ob;
        vector <string> professors2_ob;
        vector <string> allcredits_ob;
        vector <string> degrees;
        vector <string> students;
        vector <string> marks;


        fstream Myfile;
        int line = -1;
        Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/courses.csv");

        while (Myfile.good()) {

            line++;

            if (line % 3 == 0) {
                getline(Myfile, id_obj, ',');

                bool h = Myfile.good();
                if (h) {


                    id_ob.push_back(id_obj);

                    getline(Myfile, status_obj, ',');
                    status_ob.push_back(status_obj);

                    getline(Myfile, professor1_obj, ',');
                    professors1_ob.push_back(professor1_obj);

                    getline(Myfile, professor2_obj, ',');
                    professors2_ob.push_back(professor2_obj);

                    getline(Myfile, credits_obj, ',');
                    allcredits_ob.push_back(credits_obj);

                    getline(Myfile, degree_obj, '\n');
                    degrees.push_back(degree_obj);


                }
            }
            if (line % 3 == 1) {
                getline(Myfile, stud, '\n');
                students.push_back(stud);


            }
            if (line % 3 == 2) {
                getline(Myfile, mark, '\n');
                marks.push_back(mark);

            }

        }


        int count = 0;
        for (size_t j = 0; j < id_ob.size(); j++) {

            if (id_ob[j].find(id) != string::npos) {

                line_n = j;
                count++;
            }
        }



        if (count == 0) {
            cout << "Sorry that id number is not registered in the database." << endl;
            return;
        }

        Courses *newcourse = new Courses;


        cout << "Please press : s - for changing status, i - for changing id, p - for changing the first professor, k - for changing the second professor, c - for changing the number of credits or d - for changing the degree." << endl;

        cin >> change_type;
        while (change_type != 's' && change_type != 'S' && change_type != 'i' && change_type != 'I' && change_type != 'p' && change_type != 'P'&& change_type != 'k' && change_type != 'K' && change_type != 'c' && change_type != 'C' && change_type != 'd' && change_type != 'D') {
            cin >> change_type;
        }

        if (change_type == 's' || identity_type == 'S') {

            string newstatus;
            cout << "Give the new status for the course." << endl;
            cin >> newstatus;
            newcourse->setstatus(newstatus);
            status_ob[line_n] = newcourse->getstatus();
        }


        if (change_type == 'i' || identity_type == 'I') {

            char newid[7];

            cout << "Give the new ID for the course." << endl;
            cin >> newid;
            newcourse->setid(newid);

            id_ob[line_n] = newcourse->getid();
        }

        if (change_type == 'p' || identity_type == 'P') {

            Professor* a1 = new Professor;
            char pid1[7];
            cout << "Give the PID of the new first professor for the course." << endl;
            cin >> pid1;
            a1->setpid(pid1);
            newcourse->setprofessor1(a1);

            professors1_ob[line_n] = newcourse->getprofessor1()->getpid();
            delete a1;
        }

        if (change_type == 'k' || identity_type == 'K') {

            Professor* a2 = new Professor;
            char pid2[7];
            cout << "Give the PID of the new second professor for the course." << endl;
            cin >> pid2;
            a2->setpid(pid2);
            newcourse->setprofessor2(a2);

            professors2_ob[line_n] = newcourse->getprofessor2()->getpid();
            delete a2;
        }

        if (change_type == 'c' || identity_type == 'C') {

            int newcredits;

            cout << "Give the new number of credits for the course." << endl;
            cin >> newcredits;
            newcourse->setcredits(newcredits);
            stringstream ss;
            ss << newcourse->getcredits();
            string numberAsString(ss.str());

            allcredits_ob[line_n] = numberAsString;
        }

        if (change_type == 'd' || identity_type == 'D') {

            string newdegree;

            cout << "Give the new degree for the course." << endl;
            cin >> newdegree;
            newcourse->setdegree(newdegree);

            degrees[line_n] = newcourse->getdegree();


        }




        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/courses.csv", ios::out | ios::trunc);
        if (data.is_open()) {

            for (size_t j = 0; j < id_ob.size(); j++) {

                data << id_ob[j] << "," << status_ob[j] << "," << professors1_ob[j] << "," << professors2_ob[j] << "," << allcredits_ob[j] << "," << degrees[j] << "\n";
                data << students[j] << "\n";
                data << marks[j] << "\n";
            }
            data.close();
            cout << "Course modified." << endl;
        }

        delete newcourse;
    }



    if (identity_type == 's' || identity_type == 'S') {

        cout << endl << "Please provide the ID of the seminar to be modified." << endl;
        cin >> id;

        string id_obj;
        string status_obj;
        string coordinator_obj;
        string speaker_obj;
        string date_obj;
        string maxseats_obj;
        string stud;

        vector <string> status_ob;
        vector <string> id_ob;
        vector <string> coordinators;
        vector <string> speakers;
        vector <string> dates;
        vector <string> max;
        vector <string> students;
        int line = -1;


        ifstream Myfile;
        Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/seminars.csv");

        while (Myfile.good()) {
            line++;
            if (line % 2 == 1) {
                getline(Myfile, stud, '\n');
                students.push_back(stud);
            }
            if (line % 2 == 0) {
                getline(Myfile, id_obj, ',');

                bool h = Myfile.good();
                if (h) {


                    id_ob.push_back(id_obj);

                    getline(Myfile, status_obj, ',');
                    status_ob.push_back(status_obj);

                    getline(Myfile, coordinator_obj, ',');
                    coordinators.push_back(coordinator_obj);

                    getline(Myfile, speaker_obj, ',');
                    speakers.push_back(speaker_obj);

                    getline(Myfile, date_obj, ',');
                    dates.push_back(date_obj);

                    getline(Myfile, maxseats_obj, '\n');
                    max.push_back(maxseats_obj);
                }
            }
        }


        int count = 0;
        for (size_t j = 0; j < id_ob.size(); j++) {

            if (id_ob[j].find(id) != string::npos) {

                line_n = j;
                count++;
            }
        }


        if (count == 0) {
            cout << "Sorry that id number is not registered in the database." << endl;
            return;
        }

        Seminars *newseminar = new Seminars;


        cout << "Please press : s - for changing status, i - for changing id, c - for changing coordinator, p - for changing speaker, d - for changing the date or m - for changing the maximum number of seats." << endl;

        cin >> change_type;
        while (change_type != 's' && change_type != 'S' && change_type != 'i' && change_type != 'I' && change_type != 'c' && change_type != 'C' && change_type != 'p' && change_type != 'P' && change_type != 'd' && change_type != 'D' && change_type != 'm' && change_type != 'M') {
            cin >> change_type;
        }

        if (change_type == 's' || identity_type == 'S') {

            string newstatus;
            cout << "Give the new status for the seminar." << endl;
            cin >> newstatus;
            newseminar->setstatus(newstatus);
            status_ob[line_n] = newseminar->getstatus();
        }


        if (change_type == 'i' || identity_type == 'I') {

            char newid[7];

            cout << "Give the new ID for the seminar." << endl;
            cin >> newid;
            newseminar->setid(newid);

            id_ob[line_n] = newseminar->getid();
        }

        if (change_type == 'c' || identity_type == 'C') {

            Professor* a1 = new Professor;
            char pid1[7];
            cout << "Give the PID of the new coordinator for the course." << endl;
            cin >> pid1;
            a1->setpid(pid1);
            newseminar->setcoordinator(a1);

            coordinators[line_n] = newseminar->getcoordinator()->getpid();
            delete a1;
        }

        if (change_type == 'p' || identity_type == 'P') {

            Professor* a2 = new Professor;
            char pid2[7];
            cout << "Give the PID of the new speaker for the course." << endl;
            cin >> pid2;
            a2->setpid(pid2);
            newseminar->setspeaker(a2);

            speakers[line_n] = newseminar->getspeaker()->getpid();
        }

        if (change_type == 'd' || identity_type == 'D') {

            string date;

            cout << "Give the new date for the seminar." << endl;
            cin >> date;
            newseminar->setdate(date);

            dates[line_n] = newseminar->getdate();
        }

        if (change_type == 'm' || identity_type == 'M') {

            int maxnumber;

            cout << "Give the new maximun number of seats for the seminar." << endl;
            cin >> maxnumber;
            newseminar->setmax_seats(maxnumber);
            stringstream ss;
            ss << newseminar->getmax_seats();
            string numberAsString(ss.str());

            max[line_n] = numberAsString;
        }





        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/seminars.csv", ios::out | ios::trunc);
        if (data.is_open()) {

            for (size_t j = 0; j < id_ob.size(); j++) {

                data << id_ob[j] << "," << status_ob[j] << "," << coordinators[j] << "," << speakers[j] << "," << dates[j] << "," << max[j] << "\n";
                data << students[j] << "\n";
            }

            data.close();
            cout << "Seminar modified." << endl;
        }


        delete newseminar;
    }




    if (identity_type == 'p' || identity_type == 'P') {



        cout << endl << "Please provide the ID of the project to be modified." << endl;
        cin >> id;

        string status_obj;
        string id_obj;
        string tutor_obj;
        string cotutor_obj;
        string degree_obj;
        string student_obj;


        vector <string> status_ob;
        vector <string> id_ob;
        vector <string> tutor_ob;
        vector <string> cotutor_ob;
        vector <string> degree_ob;
        vector <string> student_ob;
        int line = -1;


        ifstream Myfile;
        Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/project.csv");

        while (Myfile.good()) {
            line++;
            if (line % 2 == 1) {
                getline(Myfile, student_obj, '\n');
                student_ob.push_back(student_obj);
            }
            if (line % 2 == 0) {
                getline(Myfile, id_obj, ',');

                bool h = Myfile.good();
                if (h) {


                    id_ob.push_back(id_obj);

                    getline(Myfile, status_obj, ',');
                    status_ob.push_back(status_obj);

                    getline(Myfile, tutor_obj, ',');
                    tutor_ob.push_back(tutor_obj);

                    getline(Myfile, cotutor_obj, ',');
                    cotutor_ob.push_back(cotutor_obj);

                    getline(Myfile, degree_obj, '\n');
                    degree_ob.push_back(degree_obj);
                }
            }
        }


        int count = 0;
        for (size_t j = 0; j < id_ob.size(); j++) {

            if (id_ob[j].find(id) != string::npos) {
                line_n = j;
                count++;
            }
        }

        if (count == 0) {
            cout << "Sorry that id number is not registered in the database." << endl;
            return;

        }

        Project *newproject = new Project;


        cout << "Please press : s - for changing status, i - for changing id, t - for changing tutor, c - for changing co-tutor or d - for changing degree." << endl;

        cin >> change_type;
        while (change_type != 's' && change_type != 'S' && change_type != 'i' && change_type != 'I' && change_type != 't' && change_type != 'T' && change_type != 'c' && change_type != 'C' && change_type != 'd' && change_type != 'D') {
            cin >> change_type;
        }

        if (change_type == 's' || identity_type == 'S') {

            string newstatus;
            cout << "Give the new status for the project." << endl;
            cin >> newstatus;
            newproject->setstatus(newstatus);
            status_ob[line_n] = newproject->getstatus();
        }


        if (change_type == 'i' || identity_type == 'I') {

            char newid[7];

            cout << "Give the new ID for the project." << endl;
            cin >> newid;
            newproject->setid(newid);

            id_ob[line_n] = newproject->getid();
        }

        if (change_type == 't' || identity_type == 'T') {

            Professor* a1 = new Professor;
            char pid1[7];
            cout << "Give the PID of the new tutor for the course." << endl;
            cin >> pid1;
            a1->setpid(pid1);
            newproject->settutor(a1);

            tutor_ob[line_n] = newproject->gettutor()->getpid();
        }

        if (change_type == 'c' || identity_type == 'C') {

            Professor* a2 = new Professor;
            char pid2[7];
            cout << "Give the PID of the new co-tutor for the course." << endl;
            cin >> pid2;
            a2->setpid(pid2);
            newproject->setco_tutor(a2);

            cotutor_ob[line_n] = newproject->getco_tutor()->getpid();
        }

        if (change_type == 'd' || identity_type == 'D') {

            string degree;

            cout << "Give the new degree for the project." << endl;
            cin >> degree;
            newproject->setdegree(degree);

            degree_ob[line_n] = newproject->getdegree();
        }


        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/project.csv", ios::out | ios::trunc);
        if (data.is_open()) {
            for (size_t j = 0; j < id_ob.size(); j++) {
                data << id_ob[j] << "," << status_ob[j] << "," << tutor_ob[j] << "," << cotutor_ob[j] << "," << degree_ob[j] << "\n";
                data << student_ob[j] << "\n";
            }

            data.close();
            cout << "Project modified." << endl;
        }
        delete newproject;
    }
}



void Admin::deleter() {

    char identity_type;

    int line_n;
    cout << endl << "Please press the alphabet corresponding to the identity of the resource to be deleted (c-Course, s-Seminar, p-Project)" << endl;
    cin >> identity_type;
    while (identity_type != 'c' && identity_type != 'C' && identity_type != 's' && identity_type != 'S' && identity_type != 'p' && identity_type != 'P') {
        cin >> identity_type;
    }

    char id[7];


    if (identity_type == 'c' || identity_type == 'C') {



        cout << "Please provide the ID of the resource to be modified." << endl;
        cin >> id;

        string id_obj;
        string status_obj;
        string professor1_obj;
        string professor2_obj;
        string degree_obj;
        string credits_obj;
        string stud;
        string mark;

        vector <string> status_ob;
        vector <string> id_ob;
        vector <string> professors1_ob;
        vector <string> professors2_ob;
        vector <string> allcredits_ob;
        vector <string> degrees;
        vector <string> students;
        vector <string> marks;


        int line = -1;

        ifstream Myfile;

        Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/courses.csv");

        while (Myfile.good()) {

            line++;

            if (line % 3 == 0) {
                getline(Myfile, id_obj, ',');

                bool h = Myfile.good();
                if (h) {


                    id_ob.push_back(id_obj);

                    getline(Myfile, status_obj, ',');
                    status_ob.push_back(status_obj);

                    getline(Myfile, professor1_obj, ',');
                    professors1_ob.push_back(professor1_obj);

                    getline(Myfile, professor2_obj, ',');
                    professors2_ob.push_back(professor2_obj);

                    getline(Myfile, credits_obj, ',');
                    allcredits_ob.push_back(credits_obj);

                    getline(Myfile, degree_obj, '\n');
                    degrees.push_back(degree_obj);


                }
            }
            if (line % 3 == 1) {
                getline(Myfile, stud, '\n');
                students.push_back(stud);


            }
            if (line % 3 == 2) {
                getline(Myfile, mark, '\n');
                marks.push_back(mark);

            }

        }


        int count = 0;
        for (size_t j = 0; j < id_ob.size(); j++) {

            if (id_ob[j].find(id) != string::npos) {

                line_n = j;
                count++;
            }
        }



        if (count == 0) {
            cout << "Sorry that id number is not registered in the database." << endl;
            return;
        }

        status_ob.erase(status_ob.begin() + line_n);
        id_ob.erase(id_ob.begin() + line_n);
        professors1_ob.erase(professors1_ob.begin() + line_n);
        professors2_ob.erase(professors2_ob.begin() + line_n);
        allcredits_ob.erase(allcredits_ob.begin() + line_n);
        degrees.erase(degrees.begin() + line_n);
        students.erase(students.begin() + line_n);
        marks.erase(marks.begin() + line_n);

        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/courses.csv", ios::out | ios::trunc);
        if (data.is_open()) {

            for (size_t j = 0; j < id_ob.size(); j++) {

                data << id_ob[j] << "," << status_ob[j] << "," << professors1_ob[j] << "," << professors2_ob[j] << "," << allcredits_ob[j] << "," << degrees[j] << "\n";
                data << students[j] << "\n";
                data << marks[j] << "\n";

            }
            data.close();
            cout << "Course deleted." << endl;
        }

    }



    if (identity_type == 's' || identity_type == 'S') {

        cout << endl << "Please provide the ID of the seminar to be deleted." << endl;
        cin >> id;

        string id_obj;
        string status_obj;
        string coordinator_obj;
        string speaker_obj;
        string date_obj;
        string maxseats_obj;
        string stud;

        vector <string> status_ob;
        vector <string> id_ob;
        vector <string> coordinators;
        vector <string> speakers;
        vector <string> dates;
        vector <string> max;
        vector <string> students;


        int line = -1;

        ifstream Myfile;
        Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/seminars.csv");

        while (Myfile.good()) {
            line++;
            if (line % 2 == 1) {
                getline(Myfile, stud, '\n');
                students.push_back(stud);
            }
            if (line % 2 == 0) {
                getline(Myfile, id_obj, ',');

                bool h = Myfile.good();
                if (h) {


                    id_ob.push_back(id_obj);

                    getline(Myfile, status_obj, ',');
                    status_ob.push_back(status_obj);

                    getline(Myfile, coordinator_obj, ',');
                    coordinators.push_back(coordinator_obj);

                    getline(Myfile, speaker_obj, ',');
                    speakers.push_back(speaker_obj);

                    getline(Myfile, date_obj, ',');
                    dates.push_back(date_obj);

                    getline(Myfile, maxseats_obj, '\n');
                    max.push_back(maxseats_obj);
                }
            }
        }


        int count = 0;
        for (size_t j = 0; j < id_ob.size(); j++) {
            if (id_ob[j].find(id) != string::npos) {
                line_n = j;
                count++;
            }
        }


        if (count == 0) {
            cout << "Sorry that id number is not registered in the database." << endl;
            return;
        }

        status_ob.erase(status_ob.begin() + line_n);
        id_ob.erase(id_ob.begin() + line_n);
        coordinators.erase(coordinators.begin() + line_n);
        speakers.erase(speakers.begin() + line_n);
        dates.erase(dates.begin() + line_n);
        max.erase(max.begin() + line_n);
        students.erase(students.begin() + line_n);

        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/seminars.csv", ios::out | ios::trunc);
        if (data.is_open()) {

            for (size_t j = 0; j < id_ob.size(); j++) {
                data << id_ob[j] << "," << status_ob[j] << "," << coordinators[j] << "," << speakers[j] << "," << dates[j] << "," << max[j] << "\n";
                data << students[j] << "\n";
            }
            data.close();
            cout << "Seminar deleted." << endl;
        }

    }




    if (identity_type == 'p' || identity_type == 'P') {



        cout << endl << "Please provide the ID of the project to be deleted." << endl;
        cin >> id;

        string status_obj;
        string id_obj;
        string tutor_obj;
        string cotutor_obj;
        string degree_obj;
        string student_obj;


        vector <string> status_ob;
        vector <string> id_ob;
        vector <string> tutor_ob;
        vector <string> cotutor_ob;
        vector <string> degree_ob;
        vector <string> student_ob;


        int line = -1;

        ifstream Myfile;
        Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/project.csv");

        while (Myfile.good()) {
            line++;
            if (line % 2 == 1) {
                getline(Myfile, student_obj, '\n');
                student_ob.push_back(student_obj);
            }
            if (line % 2 == 0) {
                getline(Myfile, id_obj, ',');

                bool h = Myfile.good();
                if (h) {


                    id_ob.push_back(id_obj);

                    getline(Myfile, status_obj, ',');
                    status_ob.push_back(status_obj);

                    getline(Myfile, tutor_obj, ',');
                    tutor_ob.push_back(tutor_obj);

                    getline(Myfile, cotutor_obj, ',');
                    cotutor_ob.push_back(cotutor_obj);

                    getline(Myfile, degree_obj, '\n');
                    degree_ob.push_back(degree_obj);
                }
            }
        }

        int count = 0;
        for (size_t j = 0; j < id_ob.size(); j++) {

            if (id_ob[j].find(id) != string::npos) {
                line_n = j;
                count++;
            }
        }

        if (count == 0) {
            cout << "Sorry that id number is not registered in the database." << endl;
            return;

        }

        status_ob.erase(status_ob.begin() + line_n);
        id_ob.erase(id_ob.begin() + line_n);
        tutor_ob.erase(tutor_ob.begin() + line_n);
        cotutor_ob.erase(cotutor_ob.begin() + line_n);
        degree_ob.erase(degree_ob.begin() + line_n);
        student_ob.erase(student_ob.begin() + line_n);

        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/project.csv", ios::out | ios::trunc);
        if (data.is_open()) {
            for (size_t j = 0; j < id_ob.size(); j++) {
                data << id_ob[j] << "," << status_ob[j] << "," << tutor_ob[j] << "," << cotutor_ob[j] << "," << degree_ob[j] << "\n";
                data << student_ob[j] << "\n";
            }
            data.close();
            cout << "Project deleted." << endl;
        }

    }
}


//start displaying the users or resources
void Admin::BeginAction(string files) {
    fstream data(files.c_str());
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
    return ;

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

Professor::Professor(string _name, string _type, char _pid[7]) : Users(_name, _type){
    if(_type == "professor"){
        for(int i = 0; i < 7; i++){
            pid[i] = _pid[i];

        }
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


void Professor::setmarks(char pid[7]){

    string newpidp = pid;
    cout << "Please enter the course ID for which you want to set the marks." << endl;
    char id[7];
    cin >> id;



    string id_c;
    string status_c;
    string prof_c1;
    string prof_c2;
    string cred_c;
    string deg_c;
    int line_c;

    string stu;
    string marks;

    vector <string> id_co;
    vector <string> status_co;
    vector <string> deg_co;
    vector <string> prof1_co;
    vector <string> prof2_co;
    vector <string> cred_co;
    vector <string> stu_co;
    vector <string> marks_co;
    vector <string> specific_students;
    vector <int> specific_marks;



    fstream Myfile;
    int line = -1;

    Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/courses.csv");

    while(Myfile.good()){

        line++;


        if(line%3 == 0){
            getline(Myfile, id_c, ',');

            bool h = Myfile.good();
            if(h){


                id_co.push_back(id_c);


                getline(Myfile, status_c, ',');
                status_co.push_back(status_c);


                getline(Myfile, prof_c1, ',');
                prof1_co.push_back(prof_c1);


                getline(Myfile, prof_c2, ',');
                prof2_co.push_back(prof_c2);


                getline(Myfile, cred_c, ',');
                cred_co.push_back(cred_c);


                getline(Myfile, deg_c, '\n');
                deg_co.push_back(deg_c);



            }
        }
        if(line%3 == 1){

            getline(Myfile, stu, '\n');
            stu_co.push_back(stu);



        }

        if(line%3 == 2){
            getline(Myfile, marks, '\n');
            marks_co.push_back(marks);


        }

    }


    int count = 0;
    for(size_t j = 0; j < id_co.size(); j++){

        if (id_co[j].find(id) != string::npos){


            line_c = j;
            count++;

        }




    }



    if(count == 0){
        cout << "Sorry this course is not registered in the database." << endl;
        return;

    }

    if(prof1_co[line_c] != newpidp && prof2_co[line_c] != newpidp){
        cout << "Sorry you cannot set marks for this course as you are not the incharge of this course." << endl;
        return;
    }




    string line_st = stu_co[line_c];
    stringstream stud(line_st);
    while (stud.good()) {

        string substr;
        getline(stud, substr, ',');

        bool ho = stud.good();
        if(ho){

            specific_students.push_back(substr);


        }
    }

    /*Here, not assigned marks will be taken as -1 */

    for(size_t j = 0; j < specific_students.size(); j++){
        specific_marks.push_back(-1);
    }


    cout << "Please enter the student ID for which you want to set the marks." << endl;
    char sin[7];
    cin >> sin;

    int count1 = 0;
    int line_d;
    for(size_t j = 0; j < specific_students.size(); j++){

        if (specific_students[j].find(sin) != string::npos){

            line_d = j;
            count1++;

        }




    }



    if(count1 == 0){
        cout << "Sorry this student is not registered in this course." << endl;
        return;

    }

    int markss;
    cout << "Please enter the marks for this student from 0 to 10." << endl;
    cin >> markss;

    while (markss != 10 && markss != 9 && markss != 8 && markss != 7 && markss != 6 && markss != 5 && markss != 3 && markss != 3 && markss != 2 && markss != 1 && markss != 0){
        cin >> markss;
    }

    specific_marks[line_d] = markss;

    string snak;


    for(size_t t = 0; t < specific_marks.size(); t++){

        stringstream ss;
        ss << specific_marks[t];
        string numberAsString(ss.str());

        snak = snak + numberAsString + ",";

    }

    marks_co[line_c] = snak;






    fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/courses.csv", ios::out | ios::trunc);
    if (data.is_open()){

        for(unsigned int j = 0; j < id_co.size(); j++){

            data << id_co[j] << "," << status_co[j] << "," << prof1_co[j] << "," << prof2_co[j] << "," << cred_co[j] << "," << deg_co[j] << "\n" ;
            data << stu_co[j] << "\n";
            data << marks_co[j] << "\n";

        }


        data.close();
        cout << "marks set in the course file." << endl;
    }


}


void Professor::modifyr(char pid[7]) {

    char identity_type;
    char change_type;
    int line_n;
    string newpidp = pid;
    cout << endl << "Please press the alphabet corresponding to the identity of the resource to be modified (c-Course, s-Seminar, p-Project)" << endl;
    cin >> identity_type;
    while (identity_type != 'c' && identity_type != 'C' && identity_type != 's' && identity_type != 'S' && identity_type != 'p' && identity_type != 'P') {
        cin >> identity_type;
    }

    char id[7];


    if (identity_type == 'c' || identity_type == 'C') {



        cout << "Please provide the ID of the resource to be modified." << endl;
        cin >> id;

        string id_obj;
        string status_obj;
        string professor1_obj;
        string professor2_obj;
        string degree_obj;
        string credits_obj;
        string stud;
        string mark;

        vector <string> status_ob;
        vector <string> id_ob;
        vector <string> professors1_ob;
        vector <string> professors2_ob;
        vector <string> allcredits_ob;
        vector <string> degrees;
        vector <string> students;
        vector <string> marks;


        fstream Myfile;
        int line = -1;
        Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/courses.csv");

        while (Myfile.good()) {

            line++;

            if (line % 3 == 0) {
                getline(Myfile, id_obj, ',');

                bool h = Myfile.good();
                if (h) {


                    id_ob.push_back(id_obj);

                    getline(Myfile, status_obj, ',');
                    status_ob.push_back(status_obj);

                    getline(Myfile, professor1_obj, ',');
                    professors1_ob.push_back(professor1_obj);

                    getline(Myfile, professor2_obj, ',');
                    professors2_ob.push_back(professor2_obj);

                    getline(Myfile, credits_obj, ',');
                    allcredits_ob.push_back(credits_obj);

                    getline(Myfile, degree_obj, '\n');
                    degrees.push_back(degree_obj);


                }
            }
            if (line % 3 == 1) {
                getline(Myfile, stud, '\n');
                students.push_back(stud);


            }
            if (line % 3 == 2) {
                getline(Myfile, mark, '\n');
                marks.push_back(mark);

            }

        }


        int count = 0;
        for (size_t j = 0; j < id_ob.size(); j++) {

            if (id_ob[j].find(id) != string::npos) {

                line_n = j;
                count++;
            }
        }



        if (count == 0) {
            cout << "Sorry that id number is not registered in the database." << endl;
            return;
        }


        if(professors1_ob[line_n] != newpidp && professors2_ob[line_n] != newpidp){

            cout << "Sorry you are not the incharge of this course." << endl;
            return;
        }



        Courses *newcourse = new Courses;


        cout << "Please press : s - for changing status, i - for changing id, p - for changing the first professor, k - for changing the second professor, c - for changing the number of credits or d - for changing the degree." << endl;

        cin >> change_type;
        while (change_type != 's' && change_type != 'S' && change_type != 'i' && change_type != 'I' && change_type != 'p' && change_type != 'P'&& change_type != 'k' && change_type != 'K' && change_type != 'c' && change_type != 'C' && change_type != 'd' && change_type != 'D') {
            cin >> change_type;
        }

        if (change_type == 's' || identity_type == 'S') {

            string newstatus;
            cout << "Give the new status for the course." << endl;
            cin >> newstatus;
            newcourse->setstatus(newstatus);
            status_ob[line_n] = newcourse->getstatus();
        }


        if (change_type == 'i' || identity_type == 'I') {

            char newid[7];

            cout << "Give the new ID for the course." << endl;
            cin >> newid;
            newcourse->setid(newid);

            id_ob[line_n] = newcourse->getid();
        }

        if (change_type == 'p' || identity_type == 'P') {

            Professor* a1 = new Professor;
            char pid1[7];
            cout << "Give the PID of the new first professor for the course." << endl;
            cin >> pid1;
            a1->setpid(pid1);
            newcourse->setprofessor1(a1);

            professors1_ob[line_n] = newcourse->getprofessor1()->getpid();
            delete a1;
        }

        if (change_type == 'k' || identity_type == 'K') {

            Professor* a2 = new Professor;
            char pid2[7];
            cout << "Give the PID of the new second professor for the course." << endl;
            cin >> pid2;
            a2->setpid(pid2);
            newcourse->setprofessor2(a2);

            professors2_ob[line_n] = newcourse->getprofessor2()->getpid();
            delete a2;
        }

        if (change_type == 'c' || identity_type == 'C') {

            int newcredits;

            cout << "Give the new number of credits for the course." << endl;
            cin >> newcredits;
            newcourse->setcredits(newcredits);
            stringstream ss;
            ss << newcourse->getcredits();
            string numberAsString(ss.str());

            allcredits_ob[line_n] = numberAsString;
        }

        if (change_type == 'd' || identity_type == 'D') {

            string newdegree;

            cout << "Give the new degree for the course." << endl;
            cin >> newdegree;
            newcourse->setdegree(newdegree);

            degrees[line_n] = newcourse->getdegree();


        }




        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/courses.csv", ios::out | ios::trunc);
        if (data.is_open()) {

            for (size_t j = 0; j < id_ob.size(); j++) {

                data << id_ob[j] << "," << status_ob[j] << "," << professors1_ob[j] << "," << professors2_ob[j] << "," << allcredits_ob[j] << "," << degrees[j] << "\n";
                data << students[j] << "\n";
                data << marks[j] << "\n";
            }
            data.close();
            cout << "Course modified." << endl;
        }

        delete newcourse;
    }



    if (identity_type == 's' || identity_type == 'S') {

        cout << endl << "Please provide the ID of the seminar to be modified." << endl;
        cin >> id;

        string id_obj;
        string status_obj;
        string coordinator_obj;
        string speaker_obj;
        string date_obj;
        string maxseats_obj;
        string stud;

        vector <string> status_ob;
        vector <string> id_ob;
        vector <string> coordinators;
        vector <string> speakers;
        vector <string> dates;
        vector <string> max;
        vector <string> students;
        int line = -1;


        ifstream Myfile;
        Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/seminars.csv");

        while (Myfile.good()) {
            line++;
            if (line % 2 == 1) {
                getline(Myfile, stud, '\n');
                students.push_back(stud);
            }
            if (line % 2 == 0) {
                getline(Myfile, id_obj, ',');

                bool h = Myfile.good();
                if (h) {


                    id_ob.push_back(id_obj);

                    getline(Myfile, status_obj, ',');
                    status_ob.push_back(status_obj);

                    getline(Myfile, coordinator_obj, ',');
                    coordinators.push_back(coordinator_obj);

                    getline(Myfile, speaker_obj, ',');
                    speakers.push_back(speaker_obj);

                    getline(Myfile, date_obj, ',');
                    dates.push_back(date_obj);

                    getline(Myfile, maxseats_obj, '\n');
                    max.push_back(maxseats_obj);
                }
            }
        }


        int count = 0;
        for (size_t j = 0; j < id_ob.size(); j++) {

            if (id_ob[j].find(id) != string::npos) {

                line_n = j;
                count++;
            }
        }


        if (count == 0) {
            cout << "Sorry that id number is not registered in the database." << endl;
            return;
        }


        if(coordinators[line_n] != newpidp && speakers[line_n] != newpidp){
            cout << "Sorry you are not the incharge of this seminar." << endl;
            return;
        }


        Seminars *newseminar = new Seminars;


        cout << "Please press : s - for changing status, i - for changing id, c - for changing coordinator, p - for changing speaker, d - for changing the date or m - for changing the maximum number of seats." << endl;

        cin >> change_type;
        while (change_type != 's' && change_type != 'S' && change_type != 'i' && change_type != 'I' && change_type != 'c' && change_type != 'C' && change_type != 'p' && change_type != 'P' && change_type != 'd' && change_type != 'D' && change_type != 'm' && change_type != 'M') {
            cin >> change_type;
        }

        if (change_type == 's' || identity_type == 'S') {

            string newstatus;
            cout << "Give the new status for the seminar." << endl;
            cin >> newstatus;
            newseminar->setstatus(newstatus);
            status_ob[line_n] = newseminar->getstatus();
        }


        if (change_type == 'i' || identity_type == 'I') {

            char newid[7];

            cout << "Give the new ID for the seminar." << endl;
            cin >> newid;
            newseminar->setid(newid);

            id_ob[line_n] = newseminar->getid();
        }

        if (change_type == 'c' || identity_type == 'C') {

            Professor* a1 = new Professor;
            char pid1[7];
            cout << "Give the PID of the new coordinator for the course." << endl;
            cin >> pid1;
            a1->setpid(pid1);
            newseminar->setcoordinator(a1);

            coordinators[line_n] = newseminar->getcoordinator()->getpid();
            delete a1;
        }

        if (change_type == 'p' || identity_type == 'P') {

            Professor* a2 = new Professor;
            char pid2[7];
            cout << "Give the PID of the new speaker for the course." << endl;
            cin >> pid2;
            a2->setpid(pid2);
            newseminar->setspeaker(a2);

            speakers[line_n] = newseminar->getspeaker()->getpid();
        }

        if (change_type == 'd' || identity_type == 'D') {

            string date;

            cout << "Give the new date for the seminar." << endl;
            cin >> date;
            newseminar->setdate(date);

            dates[line_n] = newseminar->getdate();
        }

        if (change_type == 'm' || identity_type == 'M') {

            int maxnumber;

            cout << "Give the new maximun number of seats for the seminar." << endl;
            cin >> maxnumber;
            newseminar->setmax_seats(maxnumber);
            stringstream ss;
            ss << newseminar->getmax_seats();
            string numberAsString(ss.str());

            max[line_n] = numberAsString;
        }





        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/seminars.csv", ios::out | ios::trunc);
        if (data.is_open()) {

            for (size_t j = 0; j < id_ob.size(); j++) {

                data << id_ob[j] << "," << status_ob[j] << "," << coordinators[j] << "," << speakers[j] << "," << dates[j] << "," << max[j] << "\n";
                data << students[j] << "\n";
            }

            data.close();
            cout << "Seminar modified." << endl;
        }


        delete newseminar;
    }




    if (identity_type == 'p' || identity_type == 'P') {



        cout << endl << "Please provide the ID of the project to be modified." << endl;
        cin >> id;

        string status_obj;
        string id_obj;
        string tutor_obj;
        string cotutor_obj;
        string degree_obj;
        string student_obj;


        vector <string> status_ob;
        vector <string> id_ob;
        vector <string> tutor_ob;
        vector <string> cotutor_ob;
        vector <string> degree_ob;
        vector <string> student_ob;
        int line = -1;


        ifstream Myfile;
        Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/project.csv");

        while (Myfile.good()) {
            line++;
            if (line % 2 == 1) {
                getline(Myfile, student_obj, '\n');
                student_ob.push_back(student_obj);
            }
            if (line % 2 == 0) {
                getline(Myfile, id_obj, ',');

                bool h = Myfile.good();
                if (h) {


                    id_ob.push_back(id_obj);

                    getline(Myfile, status_obj, ',');
                    status_ob.push_back(status_obj);

                    getline(Myfile, tutor_obj, ',');
                    tutor_ob.push_back(tutor_obj);

                    getline(Myfile, cotutor_obj, ',');
                    cotutor_ob.push_back(cotutor_obj);

                    getline(Myfile, degree_obj, '\n');
                    degree_ob.push_back(degree_obj);
                }
            }
        }


        int count = 0;
        for (size_t j = 0; j < id_ob.size(); j++) {

            if (id_ob[j].find(id) != string::npos) {
                line_n = j;
                count++;
            }
        }

        if (count == 0) {
            cout << "Sorry that id number is not registered in the database." << endl;
            return;

        }


        if(tutor_ob[line_n] != newpidp && cotutor_ob[line_n] != newpidp){
            cout << "Sorry you are not the incharge of this project." << endl;
            return;
        }



        Project *newproject = new Project;


        cout << "Please press : s - for changing status, i - for changing id, t - for changing tutor, c - for changing co-tutor or d - for changing degree." << endl;

        cin >> change_type;
        while (change_type != 's' && change_type != 'S' && change_type != 'i' && change_type != 'I' && change_type != 't' && change_type != 'T' && change_type != 'c' && change_type != 'C' && change_type != 'd' && change_type != 'D') {
            cin >> change_type;
        }

        if (change_type == 's' || identity_type == 'S') {

            string newstatus;
            cout << "Give the new status for the project." << endl;
            cin >> newstatus;
            newproject->setstatus(newstatus);
            status_ob[line_n] = newproject->getstatus();
        }


        if (change_type == 'i' || identity_type == 'I') {

            char newid[7];

            cout << "Give the new ID for the project." << endl;
            cin >> newid;
            newproject->setid(newid);

            id_ob[line_n] = newproject->getid();
        }

        if (change_type == 't' || identity_type == 'T') {

            Professor* a1 = new Professor;
            char pid1[7];
            cout << "Give the PID of the new tutor for the course." << endl;
            cin >> pid1;
            a1->setpid(pid1);
            newproject->settutor(a1);

            tutor_ob[line_n] = newproject->gettutor()->getpid();
        }

        if (change_type == 'c' || identity_type == 'C') {

            Professor* a2 = new Professor;
            char pid2[7];
            cout << "Give the PID of the new co-tutor for the course." << endl;
            cin >> pid2;
            a2->setpid(pid2);
            newproject->setco_tutor(a2);

            cotutor_ob[line_n] = newproject->getco_tutor()->getpid();
        }

        if (change_type == 'd' || identity_type == 'D') {

            string degree;

            cout << "Give the new degree for the project." << endl;
            cin >> degree;
            newproject->setdegree(degree);

            degree_ob[line_n] = newproject->getdegree();
        }


        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/project.csv", ios::out | ios::trunc);
        if (data.is_open()) {
            for (size_t j = 0; j < id_ob.size(); j++) {
                data << id_ob[j] << "," << status_ob[j] << "," << tutor_ob[j] << "," << cotutor_ob[j] << "," << degree_ob[j] << "\n";
                data << student_ob[j] << "\n";
            }

            data.close();
            cout << "Project modified." << endl;
        }
        delete newproject;
    }
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



void Student::enroll(char student_sin[7]){


    ////////////////////////////Read the student data and make an object////////////////

    string name_obj;
    string id_obj;
    string deg_obj;
    int line_n;

    string pro;
    string cour;
    string sem;

    vector <string> name_ob;
    vector <string> id_ob;
    vector <string> degrees;
    vector <string> specific_courses;
    vector <string> courses;
    vector <string> specific_seminars;
    vector <string> seminars;
    vector <string> project;



    fstream Myfile;
    int line = -1;

    Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv");

    while(Myfile.good()){

        line++;


        if(line%4 == 0){
            getline(Myfile, name_obj, ',');

            bool h = Myfile.good();
            if(h){


                name_ob.push_back(name_obj);


                getline(Myfile, id_obj, ',');
                id_ob.push_back(id_obj);


                getline(Myfile, deg_obj, '\n');
                degrees.push_back(deg_obj);



            }
        }
        if(line%4==1){

            getline(Myfile, cour, '\n');
            courses.push_back(cour);


        }

        if(line%4==2){
            getline(Myfile, sem, '\n');
            seminars.push_back(sem);


        }

        if(line%4==3){
            getline(Myfile, pro, '\n');
            project.push_back(pro);


        }
    }



    int count = 0;
    for(size_t j = 0; j < id_ob.size(); j++){

        if (id_ob[j].find(student_sin) != string::npos){


            line_n = j;
            count++;
        }




    }



    if(count == 0){
        cout << "Sorry your id number is not registered in the database." << endl;
        return;

    }


    string line_t = courses[line_n];
    stringstream ss(line_t);
    while (ss.good()) {

        string substr;
        getline(ss, substr, ',');

        bool ho = ss.good();
        if(ho){

            specific_courses.push_back(substr);

        }
    }

    string line_s = seminars[line_n];
    stringstream st(line_s);
    while (st.good()) {

        string substr;
        getline(st, substr, ',');

        bool ho = st.good();
        if(ho){

            specific_seminars.push_back(substr);

        }
    }






    /////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////Read the course/project/seminar file which needs to be enrolled////////////////


    char type;
    char r_id[7];
    cout << "What category of resources you want to enroll in? (Press P - Final Degree Project, C - Courses, S - Seminars)" << endl;
    cin >> type;
    while (type != 's' && type != 'S' && type != 'C' && type != 'c' && type != 'p' && type != 'P'){
        cin >> type;
    }



    cout << "Please provide the ID for the resource." << endl;
    cin >> r_id;


    if(type == 'c' || type == 'C'){

        string id_c;
        string status_c;
        string prof_c1;
        string prof_c2;
        string cred_c;
        string deg_c;
        int line_c;

        string stu;
        string marks;

        vector <string> id_co;
        vector <string> status_co;
        vector <string> deg_co;
        vector <string> prof1_co;
        vector <string> prof2_co;
        vector <string> cred_co;
        vector <string> stu_co;
        vector <string> marks_co;
        vector <string> specific_students;



        fstream Myfile;
        int line = -1;

        Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/courses.csv");

        while(Myfile.good()){

            line++;


            if(line%3 == 0){
                getline(Myfile, id_c, ',');

                bool h = Myfile.good();
                if(h){


                    id_co.push_back(id_c);


                    getline(Myfile, status_c, ',');
                    status_co.push_back(status_c);


                    getline(Myfile, prof_c1, ',');
                    prof1_co.push_back(prof_c1);


                    getline(Myfile, prof_c2, ',');
                    prof2_co.push_back(prof_c2);


                    getline(Myfile, cred_c, ',');
                    cred_co.push_back(cred_c);


                    getline(Myfile, deg_c, '\n');
                    deg_co.push_back(deg_c);



                }
            }
            if(line%3 == 1){

                getline(Myfile, stu, '\n');
                stu_co.push_back(stu);



            }

            if(line%3 == 2){
                getline(Myfile, marks, '\n');
                marks_co.push_back(marks);


            }

        }



        int count = 0;
        for(size_t j = 0; j < id_co.size(); j++){

            if (id_co[j].find(r_id) != string::npos){


                line_c = j;
                count++;

            }




        }



        if(count == 0){
            cout << "Sorry this course is not registered in the database." << endl;
            return;

        }

        if(deg_co[line_c] != degrees[line_n]){
            cout << "Sorry you cannot take this course as it is from another degree." << endl;
            return;
        }



        string line_st = stu_co[line_c];
        stringstream stud(line_st);
        while (stud.good()) {

            string substr;
            getline(stud, substr, ',');

            bool ho = stud.good();
            if(ho){

                specific_students.push_back(substr);


            }
        }


        specific_students.push_back(student_sin);

        string snak;

        for(unsigned int t; t<specific_students.size(); t++){
            snak = snak + specific_students[t] + ",";
        }

        stu_co[line_c] = snak;





        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/courses.csv", ios::out | ios::trunc);
        if (data.is_open()){

            for(unsigned int j = 0; j < id_co.size(); j++){

                data << id_co[j] << "," << status_co[j] << "," << prof1_co[j] << "," << prof2_co[j] << "," << cred_co[j] << "," << deg_co[j] << "\n" ;
                data << stu_co[j] << "\n";
                data << marks_co[j] << "\n";

            }


            data.close();
            cout << "student added in the course file." << endl;
        }


        specific_courses.push_back(r_id);
        string sna;

        for(unsigned int t; t<specific_courses.size(); t++){
            sna = sna + specific_courses[t] + ",";
        }

        courses[line_n] = sna;


        fstream data1("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv", ios::out | ios::trunc);
        if (data1.is_open()){

            for(size_t j = 0; j < name_ob.size(); j++){

                data1 << name_ob[j] << "," << id_ob[j] << "," << degrees[j] << "\n" ;
                data1 << courses[j] << "\n";
                data1 << seminars[j] << "\n";
                data1 << project[j] << "\n";



            }


            data1.close();
            cout << "Course added to the student file." << endl;
        }

    }

    if(type == 's' || type == 'S'){

        string id_s;
        string status_s;
        string coord;
        string speak;
        string date;
        string maxs;
        int line_x;

        string stu;


        vector <string> id_se;
        vector <string> status_se;
        vector <string> coord_se;
        vector <string> speak_se;
        vector <string> date_se;
        vector <string> maxs_se;
        vector <string> stu_se;
        vector <string> specific_students;



        fstream Myfile;
        int line = -1;

        Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/seminars.csv");

        while(Myfile.good()){

            line++;


            if(line%2 == 0){
                getline(Myfile, id_s, ',');

                bool h = Myfile.good();
                if(h){


                    id_se.push_back(id_s);


                    getline(Myfile, status_s, ',');
                    status_se.push_back(status_s);


                    getline(Myfile, coord, ',');
                    coord_se.push_back(coord);


                    getline(Myfile, speak, ',');
                    speak_se.push_back(speak);


                    getline(Myfile, date, ',');
                    date_se.push_back(date);


                    getline(Myfile, maxs, '\n');
                    maxs_se.push_back(maxs);



                }
            }
            if(line%2 == 1){

                getline(Myfile, stu, '\n');
                stu_se.push_back(stu);



            }


        }



        int count = 0;
        for(size_t j = 0; j < id_se.size(); j++){

            if (id_se[j].find(r_id) != string::npos){


                line_x = j;
                count++;

            }




        }



        if(count == 0){
            cout << "Sorry this seminar is not registered in the database." << endl;
            return;

        }
        



        string line_st = stu_se[line_x];
        stringstream stud(line_st);
        while (stud.good()) {

            string substr;
            getline(stud, substr, ',');

            bool ho = stud.good();
            if(ho){

                specific_students.push_back(substr);


            }
        }



        if(specific_students.size() >= maxs[line_x] - '0'){
            cout << "Sorry this seminar has reached its capacity." << endl;
            return;

        }


        specific_students.push_back(student_sin);

        string snak;

        for(unsigned int t; t<specific_students.size(); t++){
            snak = snak + specific_students[t] + ",";
        }

        stu_se[line_x] = snak;






        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/seminars.csv", ios::out | ios::trunc);
        if (data.is_open()){

            for(unsigned int j = 0; j < id_se.size(); j++){

                data << id_se[j] << "," << status_se[j] << "," << coord_se[j] << "," << speak_se[j] << "," << date_se[j] << "," << maxs_se[j] << "\n" ;
                data << stu_se[j] << "\n";

            }


            data.close();
            cout << "student added in the seminar file." << endl;
        }


        specific_seminars.push_back(r_id);
        string sna;

        for(unsigned int t; t<specific_seminars.size(); t++){
            sna = sna + specific_seminars[t] + ",";
        }

        seminars[line_n] = sna;


        fstream data1("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv", ios::out | ios::trunc);
        if (data1.is_open()){

            for(size_t j = 0; j < name_ob.size(); j++){

                data1 << name_ob[j] << "," << id_ob[j] << "," << degrees[j] << "\n" ;
                data1 << courses[j] << "\n";
                data1 << seminars[j] << "\n";
                data1 << project[j] << "\n";



            }


            data1.close();
            cout << "Seminar added to the student file." << endl;
        }
    }



    if(type == 'p' || type == 'P'){



        if(project[line_n].size() != 0){
            cout << "You cannot enroll in this project as you have already registered for one project." << endl;
            return;

        }

        string id_p;
        string status_p;
        string tut;
        string cotut;
        string degree_p;

        int line_z;

        string stu;


        vector <string> id_pr;
        vector <string> status_pr;
        vector <string> tut_pr;
        vector <string> cotut_pr;
        vector <string> deg_pr;

        vector <string> stu_pr;



        fstream Myfile;
        int line = -1;

        Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/project.csv");

        while(Myfile.good()){

            line++;


            if(line%2 == 0){
                getline(Myfile, id_p, ',');

                bool h = Myfile.good();
                if(h){


                    id_pr.push_back(id_p);


                    getline(Myfile, status_p, ',');
                    status_pr.push_back(status_p);


                    getline(Myfile, tut, ',');
                    tut_pr.push_back(tut);


                    getline(Myfile, cotut, ',');
                    cotut_pr.push_back(cotut);


                    getline(Myfile, degree_p, '\n');
                    deg_pr.push_back(degree_p);





                }
            }
            if(line%2 == 1){

                getline(Myfile, stu, '\n');
                stu_pr.push_back(stu);



            }


        }



        int count = 0;
        for(size_t j = 0; j < id_pr.size(); j++){

            if (id_pr[j].find(r_id) != string::npos){


                line_z = j;
                count++;

            }




        }



        if(count == 0){
            cout << "Sorry this project is not registered in the database." << endl;
            return;

        }

        if(deg_pr[line_z] != degrees[line_n]){
            cout << "Sorry you cannot take this project as it is from another degree." << endl;
            return;
        }

        if(stu_pr[line_z].size() != 0){
            cout << "Sorry this project has already been assigned to another student." << endl;
            return;

        }


        string stri(student_sin);
        stu_pr[line_z] = stri;




        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/project.csv", ios::out | ios::trunc);
        if (data.is_open()){

            for(unsigned int j = 0; j < id_pr.size(); j++){

                data << id_pr[j] << "," << status_pr[j] << "," << tut_pr[j] << "," << cotut_pr[j] << "," << deg_pr[j] << "\n" ;
                data << stu_pr[j] << "\n";

            }


            data.close();
            cout << "student added in the project file." << endl;
        }



        project[line_n] = r_id;


        fstream data1("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv", ios::out | ios::trunc);
        if (data1.is_open()){

            for(size_t j = 0; j < name_ob.size(); j++){

                data1 << name_ob[j] << "," << id_ob[j] << "," << degrees[j] << "\n" ;
                data1 << courses[j] << "\n";
                data1 << seminars[j] << "\n";
                data1 << project[j] << "\n";



            }


            data1.close();
            cout << "Project added to the student file." << endl;
        }
    }




}




void Student::drop(char student_sin[7]){


    ////////////////////////////Read the student data and make an object////////////////

    string name_obj;
    string id_obj;
    string deg_obj;
    int line_n;

    string pro;
    string cour;
    string sem;

    vector <string> name_ob;
    vector <string> id_ob;
    vector <string> degrees;
    vector <string> specific_courses;
    vector <string> courses;
    vector <string> specific_seminars;
    vector <string> seminars;
    vector <string> project;



    fstream Myfile;
    int line = -1;

    Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv");

    while(Myfile.good()){

        line++;


        if(line%4 == 0){
            getline(Myfile, name_obj, ',');

            bool h = Myfile.good();
            if(h){


                name_ob.push_back(name_obj);


                getline(Myfile, id_obj, ',');
                id_ob.push_back(id_obj);


                getline(Myfile, deg_obj, '\n');
                degrees.push_back(deg_obj);



            }
        }
        if(line%4==1){

            getline(Myfile, cour, '\n');
            courses.push_back(cour);


        }

        if(line%4==2){
            getline(Myfile, sem, '\n');
            seminars.push_back(sem);


        }

        if(line%4==3){
            getline(Myfile, pro, '\n');
            project.push_back(pro);


        }
    }



    int count = 0;
    for(size_t j = 0; j < id_ob.size(); j++){

        if (id_ob[j].find(student_sin) != string::npos){


            line_n = j;
            count++;
        }




    }



    if(count == 0){
        cout << "Sorry your id number is not registered in the database." << endl;
        return;

    }


    string line_t = courses[line_n];
    stringstream ss(line_t);
    while (ss.good()) {

        string substr;
        getline(ss, substr, ',');

        bool ho = ss.good();
        if(ho){

            specific_courses.push_back(substr);

        }
    }

    string line_s = seminars[line_n];
    stringstream st(line_s);
    while (st.good()) {

        string substr;
        getline(st, substr, ',');

        bool ho = st.good();
        if(ho){

            specific_seminars.push_back(substr);

        }
    }






    /////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////Read the course/project/seminar file which needs to be dropped////////////////


    char type;
    char r_id[7];
    cout << "What category of resources you want to drop? (Press P - Final Degree Project, C - Courses, S - Seminars)" << endl;
    cin >> type;
    while (type != 's' && type != 'S' && type != 'C' && type != 'c' && type != 'p' && type != 'P'){
        cin >> type;
    }



    cout << "Please provide the ID for the resource." << endl;
    cin >> r_id;


    if(type == 'c' || type == 'C'){

        string id_c;
        string status_c;
        string prof_c1;
        string prof_c2;
        string cred_c;
        string deg_c;
        int line_c;

        string stu;
        string marks;

        vector <string> id_co;
        vector <string> status_co;
        vector <string> deg_co;
        vector <string> prof1_co;
        vector <string> prof2_co;
        vector <string> cred_co;
        vector <string> stu_co;
        vector <string> marks_co;
        vector <string> specific_students;



        fstream Myfile;
        int line = -1;

        Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/courses.csv");

        while(Myfile.good()){

            line++;


            if(line%3 == 0){
                getline(Myfile, id_c, ',');

                bool h = Myfile.good();
                if(h){


                    id_co.push_back(id_c);


                    getline(Myfile, status_c, ',');
                    status_co.push_back(status_c);


                    getline(Myfile, prof_c1, ',');
                    prof1_co.push_back(prof_c1);


                    getline(Myfile, prof_c2, ',');
                    prof2_co.push_back(prof_c2);


                    getline(Myfile, cred_c, ',');
                    cred_co.push_back(cred_c);


                    getline(Myfile, deg_c, '\n');
                    deg_co.push_back(deg_c);



                }
            }
            if(line%3 == 1){

                getline(Myfile, stu, '\n');
                stu_co.push_back(stu);



            }

            if(line%3 == 2){
                getline(Myfile, marks, '\n');
                marks_co.push_back(marks);


            }

        }



        int count = 0;
        for(size_t j = 0; j < id_co.size(); j++){

            if (id_co[j].find(r_id) != string::npos){


                line_c = j;
                count++;

            }




        }



        if(count == 0){
            cout << "Sorry this course is not registered in the database." << endl;
            return;

        }



        string line_st = stu_co[line_c];
        stringstream stud(line_st);
        while (stud.good()) {

            string substr;
            getline(stud, substr, ',');

            bool ho = stud.good();
            if(ho){

                specific_students.push_back(substr);


            }
        }



        int count1 = 0;
        int line_h;
        for(size_t j = 0; j < specific_students.size(); j++){

            if (specific_students[j].find(student_sin) != string::npos){


                line_h = j;
                count1++;

            }




        }


        if(count1 == 0){
            cout << "Sorry you cannot drop this course because you haven't enrolled in it!" << endl;
            return;

        }



        int count2 = 0;
        int line_a;
        for(size_t j = 0; j < specific_courses.size(); j++){


            if (specific_courses[j].find(r_id) != string::npos){


                line_a = j;
                count2++;

            }




        }


        if(count2 == 0){
            cout << "Sorry you cannot drop this course because you haven't enrolled in it." << endl;
            return;

        }



        specific_students.erase(specific_students.begin() + line_h);

        string snak;

        for(unsigned int t; t<specific_students.size(); t++){
            snak = snak + specific_students[t] + ",";
        }

        stu_co[line_c] = snak;






        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/courses.csv", ios::out | ios::trunc);
        if (data.is_open()){

            for(unsigned int j = 0; j < id_co.size(); j++){

                data << id_co[j] << "," << status_co[j] << "," << prof1_co[j] << "," << prof2_co[j] << "," << cred_co[j] << "," << deg_co[j] << "\n" ;
                data << stu_co[j] << "\n";
                data << marks_co[j] << "\n";

            }


            data.close();
            cout << "Student deleted from the course file." << endl;
        }


        specific_courses.erase(specific_courses.begin() + line_a);
        string sna;

        for(unsigned int t; t<specific_courses.size(); t++){
            sna = sna + specific_courses[t] + ",";
        }

        courses[line_n] = sna;


        fstream data1("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv", ios::out | ios::trunc);
        if (data1.is_open()){

            for(size_t j = 0; j < name_ob.size(); j++){

                data1 << name_ob[j] << "," << id_ob[j] << "," << degrees[j] << "\n" ;
                data1 << courses[j] << "\n";
                data1 << seminars[j] << "\n";
                data1 << project[j] << "\n";



            }


            data1.close();
            cout << "Course removed from the student file." << endl;
        }

    }

    if(type == 's' || type == 'S'){

        string id_s;
        string status_s;
        string coord;
        string speak;
        string date;
        string maxs;
        int line_x;

        string stu;


        vector <string> id_se;
        vector <string> status_se;
        vector <string> coord_se;
        vector <string> speak_se;
        vector <string> date_se;
        vector <string> maxs_se;
        vector <string> stu_se;
        vector <string> specific_students;



        fstream Myfile;
        int line = -1;

        Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/seminars.csv");

        while(Myfile.good()){

            line++;


            if(line%2 == 0){
                getline(Myfile, id_s, ',');

                bool h = Myfile.good();
                if(h){


                    id_se.push_back(id_s);


                    getline(Myfile, status_s, ',');
                    status_se.push_back(status_s);


                    getline(Myfile, coord, ',');
                    coord_se.push_back(coord);


                    getline(Myfile, speak, ',');
                    speak_se.push_back(speak);


                    getline(Myfile, date, ',');
                    date_se.push_back(date);


                    getline(Myfile, maxs, '\n');
                    maxs_se.push_back(maxs);



                }
            }
            if(line%2 == 1){

                getline(Myfile, stu, '\n');
                stu_se.push_back(stu);



            }


        }



        int count = 0;
        for(size_t j = 0; j < id_se.size(); j++){

            if (id_se[j].find(r_id) != string::npos){


                line_x = j;
                count++;

            }




        }



        if(count == 0){
            cout << "Sorry this seminar is not registered in the database." << endl;
            return;

        }




        string line_st = stu_se[line_x];
        stringstream stud(line_st);
        while (stud.good()) {

            string substr;
            getline(stud, substr, ',');

            bool ho = stud.good();
            if(ho){

                specific_students.push_back(substr);

            }
        }




        int count1 = 0;
        int line_h;
        for(size_t j = 0; j < specific_students.size(); j++){

            if (specific_students[j].find(student_sin) != string::npos){


                line_h = j;
                count1++;

            }




        }


        if(count1 == 0){
            cout << "Sorry you cannot drop this seminar because you haven't enrolled in it!" << endl;
            return;

        }



        int count2 = 0;
        int line_a;
        for(size_t j = 0; j < specific_seminars.size(); j++){

            if (specific_seminars[j].find(r_id) != string::npos){


                line_a = j;
                count2++;

            }




        }


        if(count2 == 0){
            cout << "Sorry you cannot drop this seminar because you haven't enrolled in it." << endl;
            return;

        }



        specific_students.erase(specific_students.begin() + line_h);



        string snak;

        for(unsigned int t; t<specific_students.size(); t++){
            snak = snak + specific_students[t] + ",";
        }

        stu_se[line_x] = snak;






        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/seminars.csv", ios::out | ios::trunc);
        if (data.is_open()){

            for(unsigned int j = 0; j < id_se.size(); j++){

                data << id_se[j] << "," << status_se[j] << "," << coord_se[j] << "," << speak_se[j] << "," << date_se[j] << "," << maxs_se[j] << "\n" ;
                data << stu_se[j] << "\n";

            }


            data.close();
            cout << "student removed from the seminar file." << endl;
        }


        specific_seminars.erase(specific_seminars.begin() + line_a);

        string sna;

        for(unsigned int t; t<specific_seminars.size(); t++){
            sna = sna + specific_seminars[t] + ",";
        }

        seminars[line_n] = sna;


        fstream data1("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv", ios::out | ios::trunc);
        if (data1.is_open()){

            for(size_t j = 0; j < name_ob.size(); j++){

                data1 << name_ob[j] << "," << id_ob[j] << "," << degrees[j] << "\n" ;
                data1 << courses[j] << "\n";
                data1 << seminars[j] << "\n";
                data1 << project[j] << "\n";



            }


            data1.close();
            cout << "Seminar removed from the student file." << endl;
        }
    }



    if(type == 'p' || type == 'P'){


        string rrr(r_id);
        if(project[line_n] != rrr){
            cout << "You cannot drop this project as you have not enrolled in it." << endl;
            return;

        }

        string id_p;
        string status_p;
        string tut;
        string cotut;
        string degree_p;

        int line_z;

        string stu;


        vector <string> id_pr;
        vector <string> status_pr;
        vector <string> tut_pr;
        vector <string> cotut_pr;
        vector <string> deg_pr;

        vector <string> stu_pr;



        fstream Myfile;
        int line = -1;

        Myfile.open("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/project.csv");

        while(Myfile.good()){

            line++;


            if(line%2 == 0){
                getline(Myfile, id_p, ',');

                bool h = Myfile.good();
                if(h){


                    id_pr.push_back(id_p);


                    getline(Myfile, status_p, ',');
                    status_pr.push_back(status_p);


                    getline(Myfile, tut, ',');
                    tut_pr.push_back(tut);


                    getline(Myfile, cotut, ',');
                    cotut_pr.push_back(cotut);


                    getline(Myfile, degree_p, '\n');
                    deg_pr.push_back(degree_p);





                }
            }
            if(line%2 == 1){

                getline(Myfile, stu, '\n');
                stu_pr.push_back(stu);



            }


        }



        int count = 0;
        for(size_t j = 0; j < id_pr.size(); j++){

            if (id_pr[j].find(r_id) != string::npos){


                line_z = j;
                count++;

            }




        }



        if(count == 0){
            cout << "Sorry this project is not registered in the database." << endl;
            return;

        }

        string sre(student_sin);

        if(stu_pr[line_z] != sre){
            cout << "You cannot drop this project as you have not enrolled in it." << endl;
            return;

        }

        stu_pr[line_z] = "";
        project[line_n] = "";




        fstream data("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/project.csv", ios::out | ios::trunc);
        if (data.is_open()){

            for(unsigned int j = 0; j < id_pr.size(); j++){

                data << id_pr[j] << "," << status_pr[j] << "," << tut_pr[j] << "," << cotut_pr[j] << "," << deg_pr[j] << "\n" ;
                data << stu_pr[j] << "\n";

            }


            data.close();
            cout << "student removed from the project file." << endl;
        }



        fstream data1("/home/aurora/Desktop/Computing systems I/Project/Proj_comp/students.csv", ios::out | ios::trunc);
        if (data1.is_open()){

            for(size_t j = 0; j < name_ob.size(); j++){

                data1 << name_ob[j] << "," << id_ob[j] << "," << degrees[j] << "\n" ;
                data1 << courses[j] << "\n";
                data1 << seminars[j] << "\n";
                data1 << project[j] << "\n";



            }


            data1.close();
            cout << "Project removed from the student file." << endl;
        }
    }




}














////////////////////////////////////
//
////////////////////////////////////
