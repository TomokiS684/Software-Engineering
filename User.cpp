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
    User(std::string name, std::string pwd, std::string rle)
    {
        username = name;
        password = pwd;
        role = rle;
        
    }
    bool login() const
    {   
        std::fstream credentials;
        std::string line;
        std::string all_credentials = username;
        int compare_output;
        all_credentials.append(" ").append(password).append(" ").append(role.getRoleName()).append("\n");
        credentials.open("credentials.txt");
        while(getline(credentials,line))
        {
           if (all_credentials.compare(line)==0) break;
        }
        return !(all_credentials.compare(line));
    }
    std::string getRole() const
    {
        return role.getRoleName();
    }
};