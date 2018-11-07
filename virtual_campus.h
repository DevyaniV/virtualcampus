#ifndef VIRTUAL_CAMPUS_H
#define VIRTUAL_CAMPUS_H

#include <iostream>

using namespace std;

namespace reso {
    class Resources {
        public:
        /* Default constructor
        */
            Resources();
            /* Parameterized constructor
            */
            Resources(string _status, char _id[7]);
            /* Copy constructor
            */
            Resources(const Resources & R);
            ~Resources();
            string status;
            char id[7];

        private:
            string getstatus();
            char getid();

            friend class Admin;
        
        protected:
            void setstatus(string new_status);
            void setid(char new_id[7]);
};
    class Seminars {
        public:
        /* Default constructor
        */
            Seminars();
            /* Parameterized constructor
            */
            Seminars(string _coordinator, string _speaker, string _date, int _max_seats, string _list_students[]);
            /* Copy constructor
            */
            Seminars(const Seminars & S);
            ~Seminars();
            Resources* resource1;
            string coordinator;
            string speaker;
            string date;
            int max_seats;
            string list_students[];
        private:
            string getcoordinator();
            string getspeaker();
            string getdate();
            int getmax_seats();
            string getlist_students();
        protected:
            void setcoordinator(string new_coordinator);
            void setspeaker(string new_speaker);
            void setdate(string new_date);
            void setmax_seats(int new_max_seats);
            void setlist_students(string new_list_students[]);

    };
    class Project {
        public:
        /* Default constructor
        */
            Project();
            /* Parameterized constructor
            */
            Project(string _tutor, bool _co_tutor_presence, string _co_tutor);
            /* Copy constructor
            */
            Project(const Project & P);
            ~Project();
            Resources* resource2;
            string tutor;
            bool co_tutor_presence;
            string co_tutor;
        private:
            string gettutor();
            bool getco_tutor_presence();
            string getco_tutor();
        protected:
            void settutor(string new_tutor);
            void setco_tutor_presence(bool new_co_tutor_presence);
            void setco_tutor(string new_co_tutor);
    };

    class Courses {
        public:
        /* Default constructor
        */
            Courses();
            /* Parameterized constructor
            */
            Courses(int _credits, string _list_students[], float _list_marks[]);
            /* Copy constructor
            */
            Courses(const Courses & C);
            ~Courses();
            Resources* resource3;
            int credits;
            string list_students[];
            float list_marks[];
        private:
            int getcredits();
            string getlist_students();
            float getlist_marks();
        protected:
            void setcredits(int new_credits);
            void setlist_students(string new_list_students[]);
            void setlist_marks(float new_list_marks[]);
    };

    class Degree {
        public:
        /* Default constructor
        */
            Degree();
            /* Parameterized constructor
            */
            Degree(string _degree);
            /* Copy constructor
            */
            Degree(const Degree & D);
            ~Degree();
            Courses course[];
            Project project[];
            string degree;

        private:
            string getdegree();

        protected:
            void setdegree(string new_degree);
    };


}

namespace use {
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
        string name;
    private :
        string getname();
    protected:
        void setname(string new_name);

};
    class Admin {
        public:
        /* Default constructor
        */
            Admin();
            /* Parameterized constructor
            */
            Admin(char _pid[7]);
            /* Copy constructor
            */
            Admin(const Admin & A);
            ~Admin();
            Users* user1;
            char pid[7];
        private:
            char getpid();

        protected:
            void setpid(char new_pid[7]);
    };

    class Professor {
    public:
        /* Default constructor
        */
        Professor();
        /* Parameterized constructor
        */
        Professor(char _pid[7]);
        /* Copy constructor
        */
        Professor(const Professor & Pr);
        ~Professor();
        Users* user2;
        char pid[7];
    private:
        char getpid();

    protected:
        void setpid(char new_pid[7]);
    };

    class Student {
    public:
        /* Default constructor
        */
        Student();
        /* Parameterized constructor
        */
        Student(int _sin[7], string _list_courses[], string _list_sem[], string _list_project[]);
        /* Copy constructor
        */
        Student(const Student & St);
        ~Student();
        Users* user3;
        int sin[7];
        string list_courses[];
        string list_sem[];
        string list_project[];
    private:
        int getsin();
        string getlist_courses();
        string getlist_sem();
        string getlist_project();

    protected:
        void setsin(int new_sin[7]);
        void setlist_courses(string new_list_courses[]);
        void setlist_sem(string new_list_sem[]);
        void setlist_project(string new_list_project[]);

    };
}


#endif // VIRTUAL_CAMPUS_H
