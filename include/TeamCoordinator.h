#ifndef TEAMCOORDINATOR_H
#define TEAMCOORDINATOR_H

#include "Coordinator.h"

class TeamCoordinator : public Coordinator{
    private:
        std::vector<ResponseUnit*> colleagues;
    public:
        TeamCoordinator();

        void deploy(CampusArea* area, ResponseUnit* unit);
        void notify(CampusArea* area, ResponseUnit* unit);
        void addColeague(ResponseUnit* coleague);

};

#endif
