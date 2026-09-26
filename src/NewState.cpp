#include "NewState.h"
#include "AssignedState.h"
#include "Incident.h"

#include <iostream>

NewState::NewState(Incident* context)
    : IncidentState(context)
{
}

NewState::~NewState()
{
}

std::string NewState::describe()
{
    return "NEW";
}

void NewState::updateState()
{
    std::cout
        << "[Incident State] NEW -> ASSIGNED"
        << std::endl;

    context->updateState(
        new AssignedState(context)
    );
}
