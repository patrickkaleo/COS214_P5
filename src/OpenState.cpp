#include "OpenState.h"
#include "RestrictedState.h"
#include "CampusArea.h"

#include <iostream>

OpenState::OpenState(CampusArea *context)
{
	this->context = context;
}

OpenState::~OpenState()
{
}

std::string OpenState::describe()
{
	return "OPEN";
}

void OpenState::updateState()
{
	std::cout
		<< "[Access State] OPEN -> RESTRICTED"
		<< std::endl;

	if (this->context)
	{
		this->context->updateState(
			new RestrictedState(context));
	}
}
