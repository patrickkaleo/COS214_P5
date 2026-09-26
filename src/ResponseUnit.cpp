#include "ResponseUnit.h"
#include "CampusArea.h"

#include <iostream>

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

    area->addResponseUnit(this);
}

std::string ResponseUnit::getId() const
{
    return id;
}
