#ifndef DISPATCHUNIT_H
#define DISPATCHUNIT_H

#include "Command.h"
#include "TeamCoordinator.h"
#include "ResponseUnit.h"
#include "CampusArea.h"

class DispatchUnit: public Command{
    private:
        TeamCoordinator* target;
        ResponseUnit* unit;
        CampusArea* area;
    public:
        DispatchUnit(TeamCoordinator* target,ResponseUnit* unit,CampusArea* area);
        void excute();
};

#endif
