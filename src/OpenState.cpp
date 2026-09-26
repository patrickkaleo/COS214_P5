#include "OpenState.h"
#include "RestrictedState.h"
#include "CampusArea.h"

#include <iostream>

OpenState::OpenState(CampusArea* context)
    : AccessState(context)
{
}

OpenState::~OpenState()
{
}

std::string OpenState::describe()
{
    return "OPEN";
}

void OpenState::updateState()
{
    std::cout
        << "[Access State] OPEN -> RESTRICTED"
        << std::endl;

    context->updateState(
        new RestrictedState(context)
    );
}
