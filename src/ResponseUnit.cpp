#include "ResponseUnit.h"
#include "CampusArea.h"
#include "TeamCoordinator.h"

#include <iostream>

namespace
{
    ResponseUnit* dispatchedUnit = nullptr;
}

ResponseUnit::ResponseUnit(std::string id)
    : mediator(nullptr),
      id(id)
{
}

ResponseUnit::~ResponseUnit()
{
}

void ResponseUnit::setMediator(
    TeamCoordinator* mediator
)
{
    this->mediator = mediator;
}

void ResponseUnit::respond(CampusArea* area)
{
    if (area == nullptr)
    {
        return;
    }

    std::cout
        << "["
        << id
        << "] Responding to "
        << area->getId()
        << "."
        << std::endl;

    dispatchedUnit = this;

    if (mediator != nullptr)
    {
        mediator->notify(area, this);
    }

    dispatchedUnit = nullptr;
}

void ResponseUnit::support(CampusArea* area)
{
    if (area == nullptr)
    {
        return;
    }

    std::cout
        << "["
        << id
        << "] Supporting ";

    if (dispatchedUnit != nullptr)
    {
        std::cout
            << dispatchedUnit->getId()
            << " ";
    }

    std::cout
        << "at "
        << area->getId()
        << "."
        << std::endl;

    area->addResponseUnit(this);
}

std::string ResponseUnit::getId() const
{
    return id;
}
