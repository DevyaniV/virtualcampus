#ifndef VIRTUAL_CAMPUS_H
#define VIRTUAL_CAMPUS_H

#include <iostream>

using namespace std;

namespace reso {
    class Resources {
        public:
            string status;
            char id[7];

        private:
            void getstatus();
            void getid();
            Resources(){

            }
            friend class Admin;
        
        protected:
            void setstatus(string new_status);
            void setid(char new_id[7]);
};
    class Seminars {
        public:
            Resources* resource1;
            string coordinator;
            string speaker;
            string date;
            int max_seats;
            char list[8];
        private:
            void getcoordinator();
            void getspeaker();
            void getdate();
            void setmax_seats();
            void getlist();
        protected:
            void setcoordinator(new_coordinator);
            void setspeaker(new_speaker);
            void setdate(new_date);
            void setmax_seats(new_max_seats);
            void setlist(new_list);

    };
    class Project {
        public:
            Resources* resource2;
            string tutor;
            bool co_tutor_presence;
            string co_tutor;
        private:
            void gettutor();
            void getco_tutor_presence();
            void getco_tutor();
        protected:
            void settutor(new_tutor);
            void setco_tutor_presence(new_co_tutor_presence);
            void setco_tutor(new_co_tutor);
    };

    class Courses {
        public:
            Resources* resource3;
            int credits;
            string list_students[];
            float list_marks[];
        private:
            void getcredits();
            void getlist_students();
            void getlist_marks();
        protected:
            void setcredits(new_credits);
            void setlist_students(new_list_students);
            void setlist_marks(new_list_marks);
    };

    class Degree {
        public:
            Courses course[];
            Project project[];
            string degree;

        private:
            void getdegree();

        protected:
            void setdegree(new_degree);
    };


}

namespace use {
    class Users {
};
    class Admin {
        public:
            Users* user1;
            char pid[7];
        private:
            void getpid();

        protected:
            void setpid(new_pid);
    };

    class Professor {
    public:
        Users* user2;
        char pid[7];
    private:
        void getpid();

    protected:
        void setpid(new_pid);
    };

    class Students {
    public:
        Users* user3;
        int sin[7];
        string list_courses[];
        string list_sem[];
        string list_project[];
    private:
        void getsin();
        void getlist_courses();
        void getlist_sem();
        void getlist_project();

    protected:
        void setsin(new_sin);
        void setlist_courses(new_list_courses);
        void setlist_sem(new_list_sem);
        void setlist_project(new_list_project);

    };
}


#endif // VIRTUAL_CAMPUS_H
