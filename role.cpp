class Role
{
    enum class Roles { RegFaculty, TempFaculty, Chair, Dean };
    Roles role; /* = RegFaculty; */
public:
    Role(std::string newRole);
    std::string getRoleName() const; /* "RegFaculty", "TempFaculty", "Chair", "Dean" */
};