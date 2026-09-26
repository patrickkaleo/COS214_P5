#include "CampusArea.h"
#include "AccessState.h"
#include "OpenState.h"

#include <iostream>

CampusArea::CampusArea(std::string id)
    : state(new OpenState(this)),
      id(id)
{
}

CampusArea::~CampusArea()
{
    delete state;
}

void CampusArea::add(CampusArea* area)
{
    std::cout
        << "[Composite] Cannot add a child to leaf area "
        << id
        << "."
        << std::endl;
}

void CampusArea::display(std::string indent)
{
    std::cout
        << indent
        << "- "
        << id
        << " ["
        << getStateDescription()
        << "]"
        << std::endl;
}

void CampusArea::updateState(AccessState* newState)
{
    if (newState == nullptr)
    {
        return;
    }

    AccessState* oldState = state;

    state = newState;

    delete oldState;
}

void CampusArea::addResponseUnit(ResponseUnit* unit)
{
    if (unit != nullptr)
    {
        responders.push_back(unit);
    }
}

void CampusArea::addIncident(Incident* incident)
{
    if (incident != nullptr)
    {
        incidents.push_back(incident);
    }
}

std::string CampusArea::getId() const
{
    return id;
}

std::string CampusArea::getStateDescription() const
{
    if (state == nullptr)
    {
        return "UNKNOWN";
    }

    return state->describe();
}
