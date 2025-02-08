#include <iostream>
#include <string>
#include <fstream>
#include "role.cpp"

class User
{
    private:
    std::string username;
    std::string password;
    Role role;
    std::fstream credentials;
    public:
    User(std::string name, std::string pwd, std::string rle)
    {
        credentials.open("credentials.txt");
        credentials << name << " " << pwd << " " << rle << std::endl;
        credentials.close();
        username = name;
        password = pwd;
        Role newRole(rle);
        role = newRole;
    }
    bool login(std::string givenname, std::string givenpassword) const
    {   
        return !(username.compare(givenname)&&password.compare(givenpassword));
    }
    std::string getRole() const
    {
        return role.getRoleName();
    }
};