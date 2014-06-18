//I affirm that all code given below was written soley by me, Justin Toney, and that any help I received adhered to the rules stated for this exam

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Runner.h"
using namespace std;

void swapRunner(Runner &a, Runner &b);
void outClass(ifstream &color);

int main()
{
	// Creating the abilty to read in the file
	string file_location = "C:\\Users\\Justin\\Documents\\GitHub\\Exam2\\Second Exam\\";
	fstream file(file_location + "Registrants.txt", ios::in);

	if (!file){
		cout << "Well, for whatever reason, the file won't open.\n";
		return 0;
	}

	// Setting up a vector to hold all of the registrants
	vector<Runner> registrants;
	string cur_name_first, cur_name_last;
	int cur_pace;

	// until the end of the file, get me the three variables in each line and it forms a current runner.
	// the current runner is added to the vector of registrants
	// thank God it takes in an integer the third time around.

	while (!file.eof()){
		file >> cur_name_first;
		file >> cur_name_last;
		file >> cur_pace;
		Runner cur_runner(cur_name_first, cur_name_last, cur_pace);
		registrants.push_back(cur_runner);
	}

	// cleanup!
	file.clear();
	file.close();

	//Sorts the registrants, just like all other sort functions
	//it takes a long time though
	for (int i = 0; i < registrants.size(); i++){
		for (int j = i + 1; j < registrants.size(); j++){
			if (registrants[j].get_pace() < registrants[i].get_pace())
				swapRunner(registrants[i], registrants[j]);
		}
	}

	//I don't need to read in these files, only make them and write to them
	ofstream white(file_location + "white.txt");
	ofstream yellow(file_location + "yellow.txt");
	ofstream green(file_location + "green.txt");
	ofstream orange(file_location + "orange.txt");
	ofstream blue(file_location + "blue.txt");
	ofstream lilac(file_location + "lilac.txt");
	ofstream red(file_location + "red.txt");

	//every time r increments a new runner is found and evaluated. If the pace is less than the max, then he or she is written into that file.
	for (int r = 0; r < registrants.size(); r++){
		if (registrants[r].get_pace() <= 360){
			white << registrants[r];
		}
		else if(registrants[r].get_pace() <= 420){
			yellow << registrants[r];
		}
		else if (registrants[r].get_pace() <= 480){
			green << registrants[r];
		}
		else if (registrants[r].get_pace() <= 540){
			orange << registrants[r];
		}
		else if (registrants[r].get_pace() <= 600){
			blue << registrants[r];
		}
		else if (registrants[r].get_pace() <= 720){
			lilac << registrants[r];
		}
		else
			red << registrants[r];
	}
	//closes everything and all that
	white.clear();
	white.close();

	yellow.clear();
	yellow.close();

	green.clear();
	green.close();

	orange.clear();
	orange.close();

	blue.clear();
	blue.close();

	lilac.clear();
	lilac.close();

	red.clear();
	red.close();

	//I tried dueling the ios::in and ios::out but it didn't work, so I initiated a different set of files for reading.
	//From here on, this is simply testing to see if I did in fact create the files, without exiting the program.
	ifstream iwhite(file_location + "white.txt");
	ifstream iyellow(file_location + "yellow.txt");
	ifstream igreen(file_location + "green.txt");
	ifstream iorange(file_location + "orange.txt");
	ifstream iblue(file_location + "blue.txt");
	ifstream ililac(file_location + "lilac.txt");
	ifstream ired(file_location + "red.txt");

	//the goal was to read all of them out, but only a few of them would show. I'm not sure the little window can handle all of the names.
	//after running the debugger, they all show up, but the earlier ones end up getting deleted.
	cout << "In the white class: \n\n";
	outClass(iwhite);

	cout << "\nIn the yellow class: \n\n";
	outClass(iyellow);

	cout << "\nIn the green class: \n\n";
	outClass(igreen);

	cout << "\nIn the orange class: \n\n";
	outClass(iorange);

	cout << "\nIn the blue class: \n\n";
	outClass(iblue);

	cout << "\nIn the lilac class: \n\n";
	outClass(ililac);

	cout << "\nIn the red class: \n\n";
	outClass(ired);

}
//helps to order the vector
void swapRunner(Runner &a, Runner &b){
	Runner tmp = a;
	a = b;
	b = tmp;
}
//publishes all of the names line by line, by category
void outClass(ifstream &color){
	string line;
	while (getline(color, line)){
		cout << line << endl;
	}
}