#include "LockArea.h"
#include "CampusArea.h"
#include "LockedState.h"

#include <iostream>

LockArea::LockArea(CampusArea* target)
    : target(target)
{
}

void LockArea::excute()
{
    if (target == nullptr)
    {
        return;
    }

    if (target->getStateDescription() == "LOCKED")
    {
        std::cout
            << "[LockArea] "
            << target->getId()
            << " is already locked."
            << std::endl;

        return;
    }

    std::cout
        << "[Command] Locking "
        << target->getId()
        << "."
        << std::endl;

    target->updateState(
        new LockedState(target)
    );
}
