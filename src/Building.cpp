#include "Building.h"

#include "AccessState.h"
#include "OpenState.h"
#include "RestrictedState.h"
#include "LockedState.h"

#include <iostream>

Building::Building(std::string description)
    : CampusArea(description)
{
}

Building::~Building()
{
    for (CampusArea* child : children)
    {
        delete child;
    }
}

void Building::add(CampusArea* area)
{
    if (area == nullptr)
    {
        return;
    }

    children.push_back(area);

    std::cout
        << "[Composite] Added "
        << area->getId()
        << " to "
        << id
        << "."
        << std::endl;
}

void Building::display(std::string indent)
{
    std::cout
        << indent
        << "+ "
        << id
        << " ["
        << getStateDescription()
        << "]"
        << std::endl;

    for (CampusArea* child : children)
    {
        child->display(indent + "   ");
    }
}

void Building::updateState(AccessState* newState)
{
    if (newState == nullptr)
    {
        return;
    }

    std::string desiredState =
        newState->describe();

    CampusArea::updateState(newState);

    // Apply the same state to all children.
    for (CampusArea* child : children)
    {
        if (desiredState == "OPEN")
        {
            child->updateState(
                new OpenState(child)
            );
        }
        else if (desiredState == "RESTRICTED")
        {
            child->updateState(
                new RestrictedState(child)
            );
        }
        else if (desiredState == "LOCKED")
        {
            child->updateState(
                new LockedState(child)
            );
        }
    }
}
