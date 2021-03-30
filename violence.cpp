#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

int main()
{
	// variable stuff
	bool violence;
	string command;
	string sudoas;
	violence = true;
	sudoas = "doas";
	
	// check if the system has doas or sudo (in that order)
	ifstream doas("sudo");
	if (!doas)
	{
		cout << "doas not found -- falling back to sudo" << endl;
		ifstream sudo("sudo");
		if (!sudo)
		{
			cout << "sudo not found -- program terminated" << endl;
			exit(EXIT_FAILURE);
		}
		else
		{
			sudoas = "sudo";
		}
	}
	doas.close();
	sudo.close();
	
	// main loop
	cout << "Violence ENABLED." << endl;
	while (violence)
	{
		cout << "violence> ";
		getline(cin, command);
		if (command == "exit" || command == "quit")
		{
			violence = false;
		}
		else
		{
			violentcmd = sudoas + " " + command; // for example: doas apt install some-package
			cout << violentcmd << endl;
			system(violentcmd);
		}
	}
	cout << "Violence DISABLED." << endl;
}
