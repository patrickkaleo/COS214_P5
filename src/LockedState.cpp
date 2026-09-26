#include "LockedState.h"
#include "OpenState.h"
#include "CampusArea.h"

#include <iostream>

LockedState::LockedState(CampusArea* context)
    : AccessState(context)
{
}

LockedState::~LockedState()
{
}

std::string LockedState::describe()
{
    return "LOCKED";
}

void LockedState::updateState()
{
    std::cout
        << "[Access State] LOCKED -> OPEN"
        << std::endl;

    context->updateState(
        new OpenState(context)
    );
}
