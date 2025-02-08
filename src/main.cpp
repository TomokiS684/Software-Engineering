#include <iostream>
#include "role.cpp"
#include "User.cpp"

bool checkPermission(int, role); //prototype

bool checkPermission(int choice, User user)
{
	return(user.role->perms[choice]);

}


int main() 
{

}