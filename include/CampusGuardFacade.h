#ifndef CAMPUSGUARDFACADE_H
#define CAMPUSGUARDFACADE_H

#include "Operator.h"
#include "TeamCoordinator.h"
#include "AlertService.h"
#include "Incident.h"
#include "CampusArea.h"

class CampusGuardFacade{
    private:
        Operator* op; //cant use operator. reserved keyword
        TeamCoordinator* coordinator;
        AlertService* alert;
    public:
        CampusGuardFacade();
        ~CampusGuardFacade();

        void logIncident(Incident* incident);
        void reportIncident(Incident* incident , CampusArea* area);
};

#endif
