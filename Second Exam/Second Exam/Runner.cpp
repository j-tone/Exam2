#include "Runner.h"
#include <iostream>
Runner::Runner(){

}

Runner::Runner(string firstname, string lastname, int pace){
	this->firstname = firstname;
	this->lastname = lastname;
	this->pace = pace;
}

string Runner::get_firstname() const{
	return firstname;
}

string Runner::get_lastname()const{
	return lastname;
}

int Runner::get_pace()const{
	return pace;
}

ostream& operator<< (ostream& out, Runner& run){
	out << run.get_firstname() << " " << run.get_lastname() << " " << run.get_pace() << endl;
	return out;
}