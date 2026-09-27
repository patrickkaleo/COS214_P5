#include "SecurityTeam.h"

SecurityTeam::SecurityTeam(std::string id)
    : ResponseUnit(id)
{
}

std::string SecurityTeam::describe()
{
    return "SECURITY";
}
