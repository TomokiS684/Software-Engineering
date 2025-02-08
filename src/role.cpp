#ifndef ROLE_H
#define ROLE_H

#include <iostream>
#include <string>

enum Permissions { ViewSchedule, RequestChanges, CreateSchedule, ModifySchedule, ViewAllSchedules, MakeReports };
/* Permissions enum is meant to be used as such: permissions[ViewSchedule] == true; */

class Role
{
    enum Roles { RegFaculty, TempFaculty, Chair, Dean };
    bool permissions[6]; /* list of permissions */
    Roles role;
public:
    Role(std::string newRole);
    void updateRole(std::string newRole);
    std::string getRoleName() const; /* "RegFaculty", "TempFaculty", "Chair", "Dean" */
    const bool* getPermissions() const;
};

Role::Role(std::string newRole)
{
    for (int i = 0; i < 6; i++)
        permissions[i] = false; /* initialize permissions to false, set them to true in updateRole() */
    
    updateRole(newRole);
}

void Role::updateRole(std::string newRole)
{
    if (newRole == "RegFaculty") {
        role = RegFaculty;
        permissions[ViewSchedule] = true;
        permissions[RequestChanges] = true;
    }
    else if (newRole == "TempFaculty") {
        role = TempFaculty;
        permissions[ViewSchedule] = true;
    }
    else if (newRole == "Chair") {
        role = Chair;
        permissions[CreateSchedule] = true;
        permissions[ModifySchedule] = true;
    }
    else if (newRole == "Dean") {
        role = Dean;
        permissions[ViewAllSchedules] = true;
        permissions[MakeReports] = true;
    }
}

std::string Role::getRoleName() const
{
    if (role == RegFaculty)
        return "RegFaculty";
    else if (role == TempFaculty)
        return "TempFaculty";
    else if (role == Chair)
        return "Chair";
    else if (role == Dean)
        return "Dean";
}

const bool* Role::getPermissions() const
{
    return permissions;
}

#endif