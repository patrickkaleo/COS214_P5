#include "RestrictedState.h"
#include "LockedState.h"
#include "CampusArea.h"

#include <iostream>

RestrictedState::RestrictedState(CampusArea *context)
{
    this->context = context;
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
    if (this->context)
    {
        this->context->updateState(
            new LockedState(context));
    }
}
