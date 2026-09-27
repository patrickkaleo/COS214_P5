#include "CampusArea.h"
#include "AccessState.h"
#include "OpenState.h"
#include "Incident.h"
#include "ResponseUnit.h"

#include <iostream>

CampusArea::CampusArea(std::string id)
    : state(new OpenState(this)),
      id(id)
{
}

CampusArea::~CampusArea()
{
    for (Incident *incident : incidents)
    {
        if (incident != nullptr && incident->getArea() == this)
        {
            incident->setArea(nullptr);
        }
    }

    incidents.clear();
    if (this->state)
        delete this->state;
}

void CampusArea::add(CampusArea * /* area */)
{
    std::cout
        << "[Composite] Cannot add a child to leaf area "
        << id
        << "."
        << std::endl;
}

void CampusArea::display(std::string indent)
{
    std::string access = "UNKNOWN";

    if (getState() != nullptr)
    {
        access = getState()->describe();
    }

    std::cout
        << indent
        << "- "
        << id
        << " ["
        << access
        << "]"
        << std::endl;
}

void CampusArea::updateState(AccessState *newState)
{
    if (newState == nullptr)
    {
        return;
    }

    AccessState *oldState = state;

    state = newState;

    delete oldState;
}

void CampusArea::addResponseUnit(ResponseUnit *unit)
{
    if (unit == nullptr)
    {
        return;
    }

    for (ResponseUnit *existing : responders)
    {
        if (existing == unit)
        {
            return;
        }
    }

    responders.push_back(unit);

    std::cout
        << "[Area] "
        << unit->getId()
        << " recorded as personnel at "
        << id
        << "."
        << std::endl;

    for (Incident *incident : incidents)
    {
        if (incident == nullptr)
        {
            continue;
        }

        CampusArea *recorded = incident->getArea();

        if (recorded != nullptr && recorded != this)
        {
            recorded->addResponseUnit(unit);
        }
    }
}

void CampusArea::addIncident(Incident *incident)
{
    if (incident == nullptr)
    {
        return;
    }

    if (incident->getArea() != nullptr && incident->getArea() != this)
    {
        std::cout
            << "[Area] Incident is already recorded at "
            << incident->getArea()->getId()
            << "."
            << std::endl;

        return;
    }

    for (Incident *existing : incidents)
    {
        if (existing == incident)
        {
            std::cout
                << "[Area] Incident is already recorded at "
                << id
                << "."
                << std::endl;

            return;
        }
    }

    incidents.push_back(incident);
    incident->setArea(this);
}

bool CampusArea::hasPersonnel() const
{
    return !responders.empty();
}

std::string CampusArea::getId() const
{
    return id;
}

AccessState *CampusArea::getState() const
{
    return state;
}
