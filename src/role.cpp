#ifndef ROLE_H
#define ROLE_H

#include <iostream>

class Role
{
    enum class Roles { RegFaculty, TempFaculty, Chair, Dean };
    /* Permissions enum is meant to be used as such: permissions[ViewSchedule] == true; */
    enum class Permissions : bool { ViewSchedule, RequestChanges, CreateSchedule, ModifySchedule, ViewAllSchedules, MakeReports };
    Permissions permissions[6]; /* list of permissions */
    Roles role;
public:
    Role(std::string newRole);
    void updateRole(std::string newRole);
    std::string getRoleName() const; /* "RegFaculty", "TempFaculty", "Chair", "Dean" */
    const bool* getPermissions() const;
};

Role::Role(std::string newRole)
{
    updateRole(newRole);
}

void Role::updateRole(std::string newRole)
{
    /* ViewSchedule, RequestChanges, CreateSchedule, ModifySchedule, ViewAllSchedules, MakeReports */
    if (newRole == "RegFaculty") {
        role = RegFaculty;
        permissions = [ true, true, false, false, false, false ];
    }
    else if (newRole == "TempFaculty") {
        role = TempFaculty;
        permissions = [ true, false, false, false, false, false ];
    }
    else if (newRole == "Chair") {
        role = Chair;
        permissions = [ false, false, true, true, false, false ];
    }
    else if (newRole == "Dean") {
        role = Dean;
        permissions = [ false, false, false, false, true, true ];
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