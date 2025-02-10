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
    public:
    User(std::string name, std::string pwd, std::string rle);
    bool login() const;
    bool* getPermissions() const;
    std::string getRole() const;
};
User::User(std::string name, std::string pwd, std::string rle)
{
    username = name;
    password = pwd;
    role = rle;
        
}
bool User::login() const
{   
    std::fstream credentials;
    std::string line;
    std::string all_credentials = username;
    all_credentials.append(" ").append(password).append(" ").append(role.getRoleName()).append("\n");
    credentials.open("credentials.txt");
    while(getline(credentials,line))
    {
        if (all_credentials == line) break;
    }
    return (all_credentials == line);
}
bool* User::getPermissions() const
{ 
    return role.getPermissions();
}
std::string User::getRole() const
{
    return role.getRoleName();
}
