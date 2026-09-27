#include "CampusGuardFacade.h"

#include "Operator.h"
#include "AlertService.h"
#include "Incident.h"
#include "CampusArea.h"

#include "RestrictArea.h"
#include "IssueAlert.h"
#include "DispatchUnit.h"
#include "LockArea.h"
#include "UnlockArea.h"
#include "ResponseUnit.h"

#include <iostream>

CampusGuardFacade::CampusGuardFacade(
	Operator* op,
	TeamCoordinator* coordinator,
	AlertService* alert
)
	: op(op),
	  coordinator(coordinator),
	  alert(alert)
{
}

CampusGuardFacade::~CampusGuardFacade()
{
	if(this->op) delete this->op;
	if(this->coordinator) delete this->coordinator;
	if(this->alert) delete this->alert;
}

void CampusGuardFacade::logIncident(
	Incident* incident
)
{
	if (incident == nullptr)
	{
		return;
	}

	std::cout
		<< "[Facade] Logging: "
		<< incident->describe()
		<< "."
		<< std::endl;
}

void CampusGuardFacade::reportIncident(
	Incident* incident,
	CampusArea* area
)
{
	if (
		incident == nullptr ||
		area == nullptr ||
		op == nullptr ||
		alert == nullptr
	)
	{
		std::cout
			<< "[Facade] Invalid report."
			<< std::endl;

		return;
	}

	std::cout
		<< "[Facade] Handling incident."
		<< std::endl;

	logIncident(incident);

	area->addIncident(incident);

	incident->progress();

	RestrictArea restrict(area);
	op->run(&restrict);

	IssueAlert alertCommand(alert);
	op->run(&alertCommand);
}

void CampusGuardFacade::mobilise(
	Incident* incident,
	CampusArea* area,
	ResponseUnit* unit
)
{
	if (
		incident == nullptr ||
		area == nullptr ||
		unit == nullptr ||
		op == nullptr ||
		coordinator == nullptr
	)
	{
		std::cout
			<< "[Facade] Invalid mobilisation."
			<< std::endl;

		return;
	}

	std::cout
		<< "[Facade] Mobilising "
		<< unit->getId()
		<< " for "
		<< incident->describe()
		<< "."
		<< std::endl;

	DispatchUnit dispatch(coordinator, unit, area);
	op->run(&dispatch);

	LockArea lock(area);
	op->run(&lock);

	incident->progress();
}

void CampusGuardFacade::closeIncident(
	Incident* incident,
	CampusArea* area
)
{
	if (
		incident == nullptr ||
		area == nullptr ||
		op == nullptr ||
		alert == nullptr
	)
	{
		std::cout
			<< "[Facade] Invalid close."
			<< std::endl;

		return;
	}

	std::cout
		<< "[Facade] Closing "
		<< incident->describe()
		<< "."
		<< std::endl;
	incident->progress();

	UnlockArea reopen(area);
	op->run(&reopen);

	IssueAlert allClear(alert);
	op->run(&allClear);
}
