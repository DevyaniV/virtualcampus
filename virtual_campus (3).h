#ifndef VIRTUAL_CAMPUS_H
#define VIRTUAL_CAMPUS_H

#include <iostream>

using namespace std;

class Admin;
class Courses;
class Seminars;
class Project;

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
		/* Destructor
			*/
		~Resources();

		string getstatus();
		char* getid();

		void setstatus(string new_status);
		void setid(char new_id[7]);

		friend class Admin;

		//HERE WE HAVE TO ADD THAT USERS IS A COMPOSITION FROM VIRTUALCAMPUS

	private:
		string status;
		char id[7];
		Courses *course;
		Project *project;
		Seminars *seminar;
};



class Seminars : public Resources {
	public:
		/* Default constructor
			*/
		Seminars();
		/* Parameterized constructor
			*/
		Seminars(string _status, char _id[7], string _coordinator, string _speaker, string _date, int _max_seats, string* _list_students_s, int _size) : Resources(_status, _id[7]) ;
		/* Copy constructor
			*/
		Seminars(const Seminars & S);
		/* Destructor
			*/
		~Seminars();

		string getcoordinator();
		string getspeaker();
		string getdate();
		int getmax_seats();
		string* getlist_students_s();
		int getsize();

		void setcoordinator(string new_coordinator);
		void setspeaker(string new_speaker);
		void setdate(string new_date);
		void setmax_seats(int new_max_seats);
		void setsize(int new_size);
		void setlist_students_s(string* new_list_students_s, int new_size);
		void display();

		friend class Admin;

	private:
		string coordinator;
		string speaker;
		string date;
		int max_seats;
		string* list_students_s;
		int size;
};



class Projects : public Resources {
	public:
 
		/* Default constructor
			*/
		Projects();
		/* Parameterized constructor
			*/
		Projects(string _status, char _id[7], string _tutor, bool _co_tutor_presence, string _co_tutor) : Resources(_status, _id[7]) ;
		/* Copy constructor
			*/
		Projects(const Projects & P);
		/* Destructor
			*/
		~Projects();

		string gettutor();
		bool getco_tutor_presence();
		string getco_tutor();

		void settutor(string new_tutor);
		void setco_tutor_presence(bool new_co_tutor_presence);
		void setco_tutor(string new_co_tutor);
		void display();

		friend class Admin;

	private:
		string tutor;
		bool co_tutor_presence;
		string co_tutor;
};



class Courses : public Resources {
	public:
		/* Default constructor
			*/
		Courses();
		/* Parameterized constructor
			*/
		Courses(string _status, char _id[7], int _credits, string* _list_students, float* _list_marks, int _size_students, int _size_marks, Resources* _resource) : Resources(_status, _id[7]);
		/* Copy constructor
			*/
		Courses(const Courses & C);
		/* Destructor
			*/
		~Courses();

		int getcredits();
		string* getlist_students();
		float* getlist_marks();
		int getsize_students();
		int getsize_marks();

		void setcredits(int new_credits);
		void setlist_students(string* new_list_students, int new_size_students);
		void setlist_marks(float* new_list_marks, int new_size_marks);
		void setsize_students(int new_size_students);
		void setsize_marks(int new_size_marks);
		void display();

		friend class Admin;

		//HERE WE HAVE TO ADD THAT COURSES IS A COMPOSITION FROM DEGREE

	private:	
		int credits;
		string* list_students;
		float* list_marks;
		int size_students;
		int size_marks;

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
		/* Destructor
			*/
		~Degree();

		string getdegree();

		void setdegree(string new_degree);

	private:
		Courses course[];
		Project project[];
		string degree;
};





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
		/* Destructor
			*/
		~Users();

		string getname();

		void setname(string new_name);

	private:
		string name;
};


class Admin : public Users {
	public:
	//    Users* user1;

		/* Default constructor
				*/
		Admin();
		/* Parameterized constructor
				*/
		Admin(string _name, char _pid[7]) : Users(_name);
		/* Copy constructor
				*/
		Admin(const Admin & A);
		/* Destructor
				*/
		~Admin();

	//    /* create, modify, delete resources */
		void createc(Courses& _course, int _credits, string* _list_students, float* _list_marks, int _size_students, int _size_marks, char new_id[7], string new_status);

	//    void creates(string _coordinator, string _speaker, string _date, int _max_seats, string _list_students[]);
	//    void createp(Courses _course, Seminars _seminar, Project _project);

		void displayc(Courses _course);

		char* getpid();
		void setpid(char new_pid[7]);
		void display();

		//HERE WE HAVE TO ADD THAT USERS IS A COMPOSITION FROM VIRTUALCAMPUS

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
		Professor(string _name, char _pid[7]) : Users(_name);
		/* Copy constructor
			*/
		Professor(const Professor & Pr);
		/* Destructor
			*/
		~Professor();
	//    Users* user2;

		char* getpid();

		void setpid(char new_pid[7]);
		void display();

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
		Student(string _name, int _sin[7], string* _list_courses, string* _list_sem, string* _list_project, int _size_courses, int _size_sems, int _size_projects) : Users(_name);
		/* Copy constructor
			*/
		Student(const Student & St);
		/* Destructor
			*/
		~Student();

	//    Users* user3;

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
		void display();
		void Studentactions();

		//HERE WE HAVE TO ADD THAT STUDENTS IS A COMPOSITION FROM DEGREE

	private:
		int sin[7];
		int size_courses;
		int size_sems;
		int size_projects;
		string* list_courses;
		string* list_sem;
		string* list_project;

};

class VirtualCampus{
	public:
		/* Default constructor
			*/
		VirtualCampus();
		/* Parameterized constructor
			*/
		VirtualCampus(string _nameofcampus);
		/* Copy constructor
			*/
		VirtualCampus(const VirtualCampus & V);
		/*  Destructor
			*/
		~VirtualCampus();

		string getnameofcampus();
		Resources resource[];
		Users users[];

		void start();
		void StartActivities();
		void BeginAction();
		void setnameofcampus(string new_nameofcampus);

	private:
		string nameofcampus;
};




#endif // VIRTUAL_CAMPUS_H
