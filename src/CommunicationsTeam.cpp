#include "CommunicationsTeam.h"

CommunicationsTeam::CommunicationsTeam(std::string id)
    : ResponseUnit(id)
{
}

std::string CommunicationsTeam::describe()
{
    return "COMMUNICATIONS";
}
