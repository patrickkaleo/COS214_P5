#include "TeamCoordinator.h"
#include "ResponseUnit.h"
#include "CampusArea.h"

#include <iostream>

TeamCoordinator::TeamCoordinator()
{
}

TeamCoordinator::~TeamCoordinator()
{
}

void TeamCoordinator::addColeague(
    ResponseUnit* coleague
)
{
    if (coleague == nullptr)
    {
        return;
    }

    colleagues.push_back(coleague);

    coleague->setMediator(this);

    std::cout
        << "[Mediator] Registered "
        << coleague->getId()
        << "."
        << std::endl;
}

void TeamCoordinator::deploy(
    CampusArea* area,
    ResponseUnit* unit
)
{
    if (area == nullptr || unit == nullptr)
    {
        std::cout
            << "[Mediator] Invalid deployment."
            << std::endl;

        return;
    }

    std::cout
        << "[Mediator] Deploying "
        << unit->getId()
        << " to "
        << area->getId()
        << "."
        << std::endl;

    unit->respond(area);

    notify(area, unit);
}

void TeamCoordinator::notify(
    CampusArea* area,
    ResponseUnit* source
)
{
    std::cout
        << "[Mediator] Coordinating supporting units."
        << std::endl;

    for (ResponseUnit* unit : colleagues)
    {
        if (unit != source)
        {
            unit->respond(area);
        }
    }
}
