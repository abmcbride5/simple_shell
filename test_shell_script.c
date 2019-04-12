#include <string.h>
#include <stdlib.h>


int main (void)
{
	char *string command;
	int cout;
	int cin; 

		while (command != "exit")

		{
			if (command == "ls")
				system("ls");

			else if (command == "cd")
				system("cd");
			else if (command == "mkdir")
				system("mkdir");
			else if (command == "date")
				system("date");
			else if (command == "help")
				cout <<"ls\tdate\theko\texit\n";
			else if (command != '\0')
				count <<"ERROR\n";

			cout <<"#shell--->>";
			cin >> command;
		}

return (0);
}
