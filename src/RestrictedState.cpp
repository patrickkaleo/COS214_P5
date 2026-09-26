#include "RestrictedState.h"
#include "LockedState.h"
#include "CampusArea.h"

#include <iostream>

RestrictedState::RestrictedState(CampusArea* context)
    : AccessState(context)
{
}

RestrictedState::~RestrictedState()
{
}

std::string RestrictedState::describe()
{
    return "RESTRICTED";
}

void RestrictedState::updateState()
{
    std::cout
        << "[Access State] RESTRICTED -> LOCKED"
        << std::endl;

    context->updateState(
        new LockedState(context)
    );
}
