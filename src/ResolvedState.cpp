#include "ResolvedState.h"

#include <iostream>

ResolvedState::ResolvedState(Incident* context)
    : IncidentState(context)
{
}

ResolvedState::~ResolvedState()
{
}

std::string ResolvedState::describe()
{
    return "RESOLVED";
}

void ResolvedState::updateState()
{
    std::cout
        << "[Incident State] INVALID: incident is already RESOLVED."
        << std::endl;
}
