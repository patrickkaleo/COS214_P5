#include "CampusGuardFacade.h"

#include "Operator.h"
#include "AlertService.h"
#include "Incident.h"
#include "CampusArea.h"

#include "RestrictArea.h"
#include "IssueAlert.h"

#include <iostream>

CampusGuardFacade::CampusGuardFacade(
    Operator *op,
    TeamCoordinator *coordinator,
    AlertService *alert)
    : op(op),
      coordinator(coordinator),
      alert(alert)
{
}

CampusGuardFacade::~CampusGuardFacade()
{
}

void CampusGuardFacade::logIncident(
    Incident *incident)
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
    Incident *incident,
    CampusArea *area)
{
    if (
        incident == nullptr ||
        area == nullptr ||
        op == nullptr ||
        alert == nullptr)
    {
        std::cout
            << "[Facade] Invalid report."
            << std::endl;

        return;
    }

    std::cout
        << "[Facade] Handling incident."
        << std::endl;

    // 1. Record incident
    logIncident(incident);

    // 2. Associate incident with area
    area->addIncident(incident);

    // 3. Move NEW -> ASSIGNED
    incident->progress();

    // 4. Restrict affected area
    RestrictArea restrict(area);
    op->run(&restrict);

    // 5. Send emergency alert
    IssueAlert alertCommand(alert);
    op->run(&alertCommand);
}
