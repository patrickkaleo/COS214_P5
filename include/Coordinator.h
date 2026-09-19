#ifndef COORDINATOR_H
#define COORDINATOR_H

#include <vector>
#include "CampusArea.h"
#include "ResponseUnit.h"

class Coordinator{
    public:
        Coordinator();
        virtual void deploy(CampusArea* area, ResponseUnit* unit) =0;
};

#endif
