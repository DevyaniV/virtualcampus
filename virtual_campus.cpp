#include <iostream>
#include "virtual_campus.h"

using namespace std;
namespace reso{

    string Resources::getstatus() {
        return status;
    }


    char Resources::getid() {
        return id;
    }

    void Resources::setstatus(string new_status) {
        status = new_status;
    }
    void Resources::setid(char new_id[7]) {
        id = new_id;
    }

/* Default constructor*/
    Resources::Resources(){
        status = "no status";
        id = aaa0000;
    }

    /* aaa0000 is a dummy id */

/* Parametrized constructor*/

    Resources::Resources(string _status, char _id[7]){
        status = _status;
        id = _id;
    }

/* Copy constructor*/

    Resources::Resources(const Resources & R){
        status = R.status;
        id = R.id;
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

    string Seminars::getlist_students() {
        return list_students;
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

    void Seminars::setlist_students(string new_list_students[]) {
        list_students = new_list_students;
    }


/* Default constructor*/
    Seminars::Seminars(){
        coordinator = "no coordinator";
        speaker = "no speaker";
        date = "no date";
        max_seats = -1;
        list_students = "no list of students";
    }

    /* -1 is a dummy number of max_seats */

/* Parametrized constructor*/

    Seminars::Seminars(string _coordinator, string _speaker, string _date, int _max_seats, string _list_students[]){
        coordinator = _coordinator;
        speaker = _speaker;
        date = _date;
        max_seats = _max_seats;
        list_students = _list_students;
    }

/* Copy constructor*/

    Seminars::Seminars(const Seminars & S){
        coordinator = S.coordinator;
        speaker = S.speaker;
        date = S.date;
        max_seats = S.max_seats;
        list_students = S.list_students;
    }

/* Destructor */

    Seminars::~Seminars(){
    }


    ////////////////////////////////////
    //
    ////////////////////////////////////

    string Project::gettutor() {
        return tutor;
    }


    bool Project::getco_tutor_presence() {
        return co_tutor_presence;
    }

    string Project::getco_tutor() {
        return co_tutor;
    }


    void Project::settutor(string new_tutor) {
        tutor = new_tutor;
    }


    void Project::setco_tutor_presence(bool new_co_tutor_presence) {
        co_tutor_presence = new_co_tutor_presence;
    }

    void Project::setco_tutor(string new_co_tutor){
        co_tutor = new_co_tutor;
    }


/* Default constructor*/
   Project::Project(){
        tutor = "no tutor";
        co_tutor_presence = 0;
        co_tutor = "no co-tutor";
    }



/* Parametrized constructor*/

    Project::Project(string _tutor, bool _co_tutor_presence, string _co_tutor){
        tutor = _tutor;
        co_tutor_presence = _co_tutor_presence;
        co_tutor = _co_tutor;
    }

/* Copy constructor*/

    Project::Project(const Project & P){
        tutor = P.tutor;
        co_tutor_presence = P.co_tutor_presence;
        co_tutor = P.co_tutor;
    }

/* Destructor */

    Project::~Project(){
    }


    ////////////////////////////////////
    //
    ////////////////////////////////////


    int Courses::getcredits() {
            return credits;
        }

        string Courses::getlist_students() {
            return list_students;
        }

        float Courses::getlist_marks() {
            return list_marks;
        }

        void Courses::setcredits(int new_credits) {
            credits = new_credits;
        }

        void Courses::setlist_students(string new_list_students) {
            list_students = new_list_students;
        }

        void Courses::setlist_marks(float new_list_marks) {
            list_marks = new_list_marks;
        }


    /* Default constructor*/
        Courses::Courses(){
            credits = 0;
            list_students = "no students";
            list_marks= "no marks";
        }

    /* Parametrized constructor*/

        Courses::Courses(int _credits, string _list_students, float _list_marks){
            credits = _credits;
            list_students = _students;
            list_marks = _list_marks;
        }

    /* Copy constructor*/

        Courses::Courses(const Courses & C){
            credits = C.credits;
            list_students = C.list_students;
            list_marks = C.list_marks;
        }

    /* Destructor */

        Courses::~Courses(){
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
    }

    namespace use{

        string Users::getname() {
            return name;
        }


        void Users::setname(string new_name) {
            name = new_name;
        }


    /* Default constructor*/
        Users::Users(){
            status = "no name";
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

        char Admin::getpid() {
            return pid;
        }

        void Admin::setpid(string new_pid) {
            pid = new_pid;
        }


    /* Default constructor*/
        Admin::Admin(){
            pid = "aaaaaaa";
            /* Here it is assumed that the default value of pid is "aaaaaaa" and this pid is never assigned to any user*/
        }


    /* Parametrized constructor*/

        Admin::Admin(string _pid){
            pid = _pid;
        }

    /* Copy constructor*/

        Admin::Admin(const Admin & A){
            pid = A.pid;
        }

    /* Destructor */

        Admin::~Admin(){
        }

        ////////////////////////////////////
        //
        ////////////////////////////////////

        char Professor::getpid() {
            return pid;
        }

        void Professor::setpid(string new_pid) {
            pid = new_pid;
        }


    /* Default constructor*/
        Professor::Professor(){
            pid = "aaaaaaa";
            /* Here it is assumed that the default value of pid is "aaaaaaa" and this pid is never assigned to any user*/
        }


    /* Parametrized constructor*/

        Professor::Professor(string _pid){
            pid = _pid;
        }

    /* Copy constructor*/

        Professor::Professor(const Professor & P){
            pid = P.pid;
        }

    /* Destructor */

        Professor::~Professor(){
        }

        ////////////////////////////////////
        //
        ////////////////////////////////////

        int Student::getsin() {
            return sin;
        }

        string Student::getlist_courses() {
            return list_courses;
        }

        string Student::getlist_sem() {
            return list_sem;
        }

        string Student::getlist_project() {
            return list_project;
        }

        void Student::setsin(int new_sin) {
            pid = new_sin;
        }

        void Student::setlist_courses(string new_list_courses) {
            list_courses = new_list_courses;
        }

        void Student::setlist_sem(string new_list_sem) {
            list_sem = new_list_sem;
        }

        void Student::setlist_project(string new_list_project) {
            list_project = new_list_project;
        }


    /* Default constructor*/
        Student::Student(){
            sin = "0000000";
            /* Here it is assumed that the default value of pid is "0000000" and this pid is never assigned to any user*/
            list_courses = "no courses";
            list_sem = "no seminars";
            list_project = "no project";
        }

    /* Parametrized constructor*/

        Student::Student(intint _sin, string _list_courses, string _list_sem, string _list_project){
            sin = _sinsin;
                    list_courses = _courses;
                    list_sem = _list_sem;
                    list_project = _list_project
        }

        Student::Student(string new_list_courses){
            list_courses = new_list_courses;
        }

        Student::Student(string new_list_sem){
            list_sem = new_list_sem;
        }

        Student::Student(string new_list_project){
            list_project = new_list_projec;
        }

    /* Copy constructor*/

        Student::Student(const Student & S){
            sin = S.sin;
            list_courses = S.list_courses;
            list_sem = S.list_sem;
            list_project = S.list_project;
        }

    /* Destructor */

        Student::~Student(){
        }
    }

