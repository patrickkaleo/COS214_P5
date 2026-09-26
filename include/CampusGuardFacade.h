#ifndef CAMPUSGUARDFACADE_H
#define CAMPUSGUARDFACADE_H

class Operator;
class TeamCoordinator;
class AlertService;
class Incident;
class CampusArea;
class ResponseUnit;

class CampusGuardFacade
{
private:
    Operator* op;
    TeamCoordinator* coordinator;
    AlertService* alert;

    void logIncident(Incident* incident);

public:
    CampusGuardFacade(
        Operator* op,
        TeamCoordinator* coordinator,
        AlertService* alert
    );

    ~CampusGuardFacade();

    void reportIncident(
        Incident* incident,
        CampusArea* area
    );

    void mobilise(
        Incident* incident,
        CampusArea* area,
        ResponseUnit* unit
    );

    void closeIncident(
        Incident* incident,
        CampusArea* area
    );
};

#endif
