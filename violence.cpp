#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <string.h>
using namespace std;

int main(int argc, char *argv[])
{
	// variable stuff
	bool violence, sudoascheck;
	string command, sudoas, violentcmd;
	violence, sudoascheck = true, true;
	sudoas = "doas";

    if (argc > 1)
    {
        cout << argv[1] << endl;
        if (strcmp(argv[1], "--skip") == 0)
        {
            // ignore the doas/sudo check
            cout << "doas/sudo check will be skipped" << endl;
            sudoascheck = false;
        }
    }
	
	// check if the system has doas or sudo (in that order)
	ifstream doas("sudo");
    if (sudoascheck)
    {
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
                sudoas = "sudo ";
            }
            sudo.close();
        }
        else
        {
            sudoas = "doas ";
        }
    }
    else
    {
        sudoas = "";
    }
	doas.close();
	
	// main loop
	cout << "Violence ENABLED." << endl;
    violence = true;
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
			violentcmd = sudoas + command; // for example: doas apt install some-package
			cout << violentcmd << endl;
			system(violentcmd.c_str());
		}
	}
	cout << "Violence DISABLED." << endl;
}
