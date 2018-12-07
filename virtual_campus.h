#ifndef VIRTUAL_CAMPUS_H
#define VIRTUAL_CAMPUS_H

#include <iostream>
#include <vector>

using namespace std;

class Admin;
class Courses;
class Seminars;
class Project;
class Resources;
class Users;
class Student;
class Professor;
class Admin;


class VirtualCampus{
public:
    /* Default constructor
        */
    VirtualCampus();
    ~VirtualCampus();

//    void start();

private:
    vector < Resources > resources;
    vector< Users > users;
    vector< Courses > courses;
    vector< Seminars > seminars;
    vector< Project > project;
    vector< Student > students;
    vector< Admin > admins;
    vector< Professor > professors;

};



class Resources {
public:
    /* Default constructor
        */
    Resources();
    /* Parameterized constructor
            */
    Resources(string _status, char _id[7]);

    /*Destructor*/

    ~Resources();


    string getstatus();
    char* getid();


    void setstatus(string new_status);
    void setid(char new_id[7]);

    friend class Admin;


private:

    string status;
    char id[7];

};



class Seminars : public Resources {
public:

    /* Default constructor
        */

    Seminars();
    /* Parameterized constructor
                */
    Seminars(string _status, char _id[7], Professor* _coordinator, Professor* _speaker, string _date, int _max_seats, vector < Student > _list_students) ;

    /* Destructor
                */
    ~Seminars();

    Professor *getcoordinator();
    Professor *getspeaker();
    string getdate();
    int getmax_seats();
    vector < Student > getlist_students();


    void setcoordinator(Professor* new_coordinator);
    void setspeaker(Professor* new_speaker);
    void setdate(string new_date);
    void setmax_seats(int new_max_seats);
    void setlist_students(vector <Student> new_list_students);

    friend class Admin;



private:

    Professor* coordinator;
    Professor* speaker;
    string date;
    int max_seats;
    vector < Student > list_students;

};



class Project : public Resources{
public:


    /* Default constructor
        */
    Project();
    /* Parameterized constructor
            */
    Project(string _status, char _id[7], Professor* _tutor, Professor* _co_tutor, Student* _student, string _degree);
    /* Copy constructor
            */
    //Project(const Project & P);
    ~Project();


    Professor* gettutor();

    Professor* getco_tutor();
    Student* getstudent();
    string getdegree();

    void settutor(Professor* new_tutor);
    void setstudent(Student* new_student);
    void setco_tutor(Professor* new_co_tutor);
    void setdegree(string new_degree);
    friend class Admin;



private:

    Professor* tutor;
    Professor* co_tutor;
    Student* student;
    string degree;



};

class Courses : public Resources {
public:


    /* Default constructor
        */
    Courses();
    /* Parameterized constructor
            */
    Courses(string _status, char _id[7], int _credits, vector < Student > _list_students, vector < float > _list_marks, string _degree, Professor* _professors);
    /* Copy constructor
            */
    //Courses(const Courses & C);
    ~Courses();

    int getcredits();
    vector < Student > getlist_students();
    vector < float > getlist_marks();
    Professor* getprofessors();
    string getdegree();
    

    void setcredits(int new_credits);
    void setlist_students(vector < Student > new_list_students);
    void setlist_marks(vector < float > new_list_marks);
    void setprofessors(Professor* new_professors);
    void setdegree(string new_degree);

    friend class Admin;



private:


    int credits;
    vector < Student > list_students;
    vector < float > list_marks;
    string degree;
    Professor* professors;



};

//class Degree {
//public:
//    /* Default constructor
//        */
//    Degree();
//    /* Parameterized constructor
//            */
//    Degree(string _degree);
//    /* Copy constructor
//            */
//    Degree(const Degree & D);
//    ~Degree();

//    string getdegree();


//    void setdegree(string new_degree);


//private:

//    Courses course[];
//    Project project[];
//    string degree;

//};





class Users {
public:
    /* Default constructor
        */
    Users();
    /* Parameterized constructor
        */
    Users(string _name);
    /* Copy constructor
        */
    Users(const Users & U);
    ~Users();

    string getname();

    void setname(string new_name);



private :
    string name;

};


class Admin : public Users {
public:

    /* Default constructor
        */
    Admin();
    /* Parameterized constructor
            */
    Admin(string _name, char _pid[7]);
    /* Copy constructor
            */
    Admin(const Admin & A);
    ~Admin();

    char* getpid();
    void setpid(char new_pid[7]);



//    /* create, modify, delete resources */
    void createc(Courses& _course, int _credits, string* _list_students, float* _list_marks, int _size_students, int _size_marks, char new_id[7], string new_status);

//    void creates(string _coordinator, string _speaker, string _date, int _max_seats, string _list_students[]);
//    void createp(Courses _course, Seminars _seminar, Project _project);

    void displayc(Courses _course);

private:

     char pid[7];


};


class Professor : public Users{
public:
    /* Default constructor
        */
    Professor();
    /* Parameterized constructor
        */
    Professor(string _name, char _pid[7]);
    /* Copy constructor
        */
    Professor(const Professor & Pr);
    ~Professor();


    char* getpid();


    void setpid(char new_pid[7]);


private:
    char pid[7];

};



class Student : public Users{
public:
    /* Default constructor
        */
    Student();
    /* Parameterized constructor
        */
    Student(int _sin[7], string* _list_courses, string* _list_sem, string* _list_project, int _size_courses, int _size_sems, int _size_projects);
    /* Copy constructor
        */
    Student(const Student & St);
    ~Student();

    int* getsin();
    int getsize_courses();
    int getsize_sems();
    int getsize_projects();
    string* getlist_courses();
    string* getlist_sem();
    string* getlist_project();


    void setsin(int new_sin[7]);
    void setsize_courses(int new_size_courses);
    void setsize_sems(int new_size_sems);
    void setsize_projects(int new_size_projects);
    void setlist_courses(string* new_list_courses, int size_courses);
    void setlist_sem(string* new_list_sem, int size_sems);
    void setlist_project(string* new_list_project, int size_projects);


private:
    int sin[7];
    int size_courses;
    int size_sems;
    int size_projects;
    string* list_courses;
    string* list_sem;
    string* list_project;

};





#endif // VIRTUAL_CAMPUS_H
