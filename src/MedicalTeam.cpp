#include "MedicalTeam.h"

MedicalTeam::MedicalTeam(std::string id)
    : ResponseUnit(id)
{
}

std::string MedicalTeam::describe()
{
    return "MEDICAL";
}
