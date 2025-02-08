#include <iostream>
#include <string>
#include "role.cpp"
#include "User.cpp"

bool checkPermission(int, User); //prototype

bool checkPermission(int index, User user)
{
	return(user.role->perms[choice]);

}


int main() 
{
	string name, pwd, role; //inputting user, pass, and role
	cout << "Username: ";
	cin >> name;
	cout << "\nPassword: ";
	cin >> pwd;
	cout << "\nRole: ";
	cin >> role;

	User user(name, pwd, role); //creating user class with inputs

	if (user.login())  //checking if input is valid
	{
		int choice = 0;

		while (choice != 7) //continues loop until logged out
		{
			cout << "1) View Schedule\n2) Request Changes\n3) Create Schedule\n4)Modify Schedule\n5)View All Schedules\n6)Make Reports\n7)Log out" << endl;
			cin >> choice;
			if (choice == 7) //if logging out
				break;
			else if (0 < choice < 7 && checkPermission(choice, user)) //if choosing input and input is valid
			{
				switch (choice) 
				{
				case 1:
					cout << "Viewing Schedule..." << endl;
					break;
				case 2:
					cout << "Requesting Changes..." << endl;
				case 3:
					cout << "Creating Schedule" << endl;
				case 4:
					cout << "Modifying Schedule" << endl;
				case 5:
					cout << "Viewing all Schedules..." << endl;
				case 6:
					cout << "Making Reports" << endl;
				}
				cout << "You do not have permission to do that!" << endl;
			}


		}
	}

}
/*I understand that switch-case probably is not the most elegant implementation of this

I could have just done:
if(checkPermission(choice,user)
	cout<<"valid<<endl;

or something like that
But as I understand it, we're going to be continously adding features to this throughout the semester
so I think for now this is the best way to do it so that we do not have to change much later

*/