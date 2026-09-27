#ifndef TEAMCOORDINATOR_H
#define TEAMCOORDINATOR_H

#include <vector>
#include "Coordinator.h"

class ResponseUnit;
class CampusArea;

class TeamCoordinator : public Coordinator
{
private:
    std::vector<ResponseUnit*> colleagues;

public:
    TeamCoordinator();
    ~TeamCoordinator();

    void deploy(CampusArea* area, ResponseUnit* unit);
    void notify(CampusArea* area, ResponseUnit* source);

    void addColeague(ResponseUnit* coleague);
};

#endif
