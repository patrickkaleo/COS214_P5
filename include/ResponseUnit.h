#ifndef RESPONSEUNIT_H
#define RESPONSEUNIT_H

#include "TeamCoordinator.h"

class ResponseUnit{
    private:
        TeamCoordinator* mediator;
        string id;
    protected:
        ResponseUnit();
    public:
        ~ResponseUnit();
        void respond(CampusArea* area);
        
};

#endif
