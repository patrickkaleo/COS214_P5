#include "AssignedState.h"
#include "MitigationState.h"
#include "Incident.h"

#include <iostream>

AssignedState::AssignedState(Incident* context)
    : IncidentState(context)
{
}

AssignedState::~AssignedState()
{
}

std::string AssignedState::describe()
{
    return "ASSIGNED";
}

void AssignedState::updateState()
{
    std::cout
        << "[Incident State] ASSIGNED -> MITIGATION"
        << std::endl;

    context->updateState(
        new MitigationState(context)
    );
}
