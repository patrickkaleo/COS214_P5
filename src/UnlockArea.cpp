#include "UnlockArea.h"
#include "CampusArea.h"
#include "OpenState.h"

#include <iostream>

UnlockArea::UnlockArea(CampusArea* target)
    : target(target)
{
}

void UnlockArea::excute()
{
    if (target == nullptr)
    {
        return;
    }

    if (
        target->getState() != nullptr &&
        target->getState()->describe() == "OPEN"
    )
    {
        std::cout
            << "[UnlockArea] INVALID: "
            << target->getId()
            << " is already open."
            << std::endl;

        return;
    }

    std::cout
        << "[Command] Opening "
        << target->getId()
        << "."
        << std::endl;

    target->updateState(
        new OpenState(target)
    );
}
