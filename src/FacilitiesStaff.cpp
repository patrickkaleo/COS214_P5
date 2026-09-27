#include "FacilitiesStaff.h"

FacilitiesStaff::FacilitiesStaff(std::string id)
    : ResponseUnit(id)
{
}

std::string FacilitiesStaff::describe()
{
    return "STAFF";
}
