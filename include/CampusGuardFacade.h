#ifndef CAMPUSGUARDFACADE_H
#define CAMPUSGUARDFACADE_H

class Operator;
class TeamCoordinator;
class AlertService;
class Incident;
class CampusArea;

class CampusGuardFacade
{
private:
    Operator* op;
    TeamCoordinator* coordinator;
    AlertService* alert;

public:
    CampusGuardFacade(
        Operator* op,
        TeamCoordinator* coordinator,
        AlertService* alert
    );

    ~CampusGuardFacade();

    void logIncident(Incident* incident);

    void reportIncident(
        Incident* incident,
        CampusArea* area
    );
};

#endif
