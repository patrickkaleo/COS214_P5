#include "Incident.h"
#include "IncidentState.h"
#include "NewState.h"
#include "CampusArea.h"

Incident::Incident(std::string description)
    : state(new NewState(this)),
      description(description),
      area(nullptr)
{
}

Incident::~Incident()
{
    delete state;
}

void Incident::updateState(IncidentState* newState)
{
    if (newState == nullptr)
    {
        return;
    }

    IncidentState* oldState = state;

    state = newState;

    delete oldState;
}

void Incident::progress()
{
    if (state != nullptr)
    {
        state->updateState();
    }
}

void Incident::setArea(CampusArea* area)
{
    this->area = area;
}

bool Incident::areaHasPersonnel() const
{
    if (area == nullptr)
    {
        return false;
    }

    return area->hasPersonnel();
}

std::string Incident::describe()
{
    std::string currentState = "UNKNOWN";

    if (state != nullptr)
    {
        currentState = state->describe();
    }

    return description + " [" + currentState + "]";
}
