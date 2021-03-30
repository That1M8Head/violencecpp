#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main()
{
	// check if the program is running under Windows
	#ifdef _WIN32 
	cout << "Windows system detected - please run this program under a non-Windows OS" << endl;
	exit(EXIT_FAILURE);
	#endif
	
	// variable stuff
	bool violence;
	string command;
	violence = true;
	
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
			violentcmd = "sudo " + command;
			cout << violentcmd << endl;
			system(violentcmd);
		}
	}
	cout << "Violence DISABLED." << endl;
}
