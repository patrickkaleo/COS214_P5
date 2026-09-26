#include "RestrictArea.h"
#include "CampusArea.h"
#include "RestrictedState.h"

#include <iostream>

RestrictArea::RestrictArea(CampusArea* target)
    : target(target)
{
}

void RestrictArea::excute()
{
    if (target == nullptr)
    {
        return;
    }

    if (
        target->getStateDescription()
        == "RESTRICTED"
    )
    {
        std::cout
            << "[RestrictArea] "
            << target->getId()
            << " is already restricted."
            << std::endl;

        return;
    }

    std::cout
        << "[Command] Restricting "
        << target->getId()
        << "."
        << std::endl;

    target->updateState(
        new RestrictedState(target)
    );
}
