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
	if (this->state)
	{
		delete state;
		if (this->area != nullptr)
		{
			this->area = nullptr;
		}
	}
}

void Incident::updateState(IncidentState *newState)
{
	if (newState != nullptr)
	{
		IncidentState *oldState = state;
		state = newState;
		delete oldState;
	}
}

void Incident::progress()
{
	if (state != nullptr)
	{
		state->updateState();
	}
}

void Incident::setArea(CampusArea *area)
{
	this->area = area;
}

CampusArea *Incident::getArea() const
{
	return area;
}

bool Incident::areaHasPersonnel() const
{
	if (this->area)
		return area->hasPersonnel();
		
	return false;
}

std::string Incident::describe()
{
	return (this->description + " [" + (this->state ? this->state->describe() : "UNKNOWN")) + "]";
}
