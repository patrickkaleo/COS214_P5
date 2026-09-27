#include "DispatchUnit.h"
#include "TeamCoordinator.h"
#include "ResponseUnit.h"

#include <iostream>

DispatchUnit::DispatchUnit(
    TeamCoordinator* target,
    ResponseUnit* unit,
    CampusArea* area
)
    : target(target),
      unit(unit),
      area(area)
{
}

void DispatchUnit::excute()
{
    if (
        target == nullptr ||
        unit == nullptr ||
        area == nullptr
    )
    {
        std::cout
            << "[DispatchUnit] Invalid dispatch."
            << std::endl;

        return;
    }

    std::cout
        << "[Command] Dispatching "
        << unit->getId()
        << "."
        << std::endl;

    target->deploy(area, unit);
}
