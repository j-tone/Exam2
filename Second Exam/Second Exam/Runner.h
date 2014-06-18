#ifndef RUNNER_H
#define RUNNER_H

#include <string>
using namespace std;

class Runner{
private:
	string firstname;
	string lastname;
	int pace;
public:
	Runner();
	Runner(string firstname, string lastname, int pace);
	string get_firstname() const;
	string get_lastname() const;
	int get_pace() const;

	//allows me to output a this class as firstname, lastname, pace. It's easy for writing to a file.
	friend ostream& operator<< (ostream& out, Runner& run);
};

#endif