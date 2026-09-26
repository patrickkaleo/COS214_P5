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
    if (!context->areaHasPersonnel())
    {
        std::cout
            << "[Incident State] INVALID: "
            << "cannot mitigate. No personnel at the incident area."
            << std::endl;

        return;
    }

    std::cout
        << "[Incident State] ASSIGNED -> MITIGATION"
        << std::endl;

    context->updateState(
        new MitigationState(context)
    );
}
