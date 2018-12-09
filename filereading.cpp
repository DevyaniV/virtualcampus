#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;

int main() {

	string file;
	cout << endl << "What file do you want to enter? Admin = 1, Prof = 2, Student = 3, Course = 4, Sem = 5, project = 6." << endl;
	int number;
	cin >> number;
	if (number == 1) {
		file = "administrators.txt";
	}
	if (number == 2) {
		file = "professors.txt";
	}
	if (number == 3) {
		file = "students.txt";
	}
	if (number == 4) {
		file = "courses.txt";
	}
	if (number == 5) {
		file = "seminars.txt";
	}
	if (number == 6) {
		file = "projects.txt";
	}

	fstream data(file);

	if (data.is_open()) {
		bool continueing = false;
		while (continueing == false) {
			data.seekg(0, ios::beg);
			string searchname;
			string line;

			cout << endl << "Please fill in the name" << endl;
			cin >> searchname;

			size_t pos;
			vector <string> people;
			while (data >> line) {
				pos = line.find(searchname);
				if (pos != string::npos) {
					size_t pos2;
					cout << "the name is found" << endl;
					string wholeline = line;
					stringstream ss(wholeline);

					while (ss.good()) {
						string substr;
						getline(ss, substr, ',');
						people.push_back(substr);
					}
					for (int i = 0; i < people.size(); ++i) {
						cout << people.at(i) << " " << endl;
					}
				}
				else { cout << "We could not find this name in the database." << endl; }
			}
		}
	}
	else { cout << "Sorry the Virtual Campus was unable to get the data. Please start the program again in order to log in." << endl; }
}