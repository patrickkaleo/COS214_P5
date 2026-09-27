#include "LockedState.h"
#include "OpenState.h"
#include "CampusArea.h"

#include <iostream>

LockedState::LockedState(CampusArea *context)
{
	this->context = context;
}

LockedState::~LockedState()
{
}

std::string LockedState::describe()
{
	return "LOCKED";
}

void LockedState::updateState()
{
	std::cout
		<< "[Access State] LOCKED -> OPEN"
		<< std::endl;
	if (this->context)
	{
		context->updateState(new OpenState(this->context));
	}
}
