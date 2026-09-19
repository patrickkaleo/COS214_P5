#ifndef ACCESSSTATE_H
#define ACCESSSTATE_H


#include <string>

#include "CampusArea.h"
#include "Incident.h"

class AccessState{
    protected:
        CampusArea* context;
        AccessState();
    public:
        virtual ~AccessState();
        virtual void updateState() = 0;
        virtual string describe() = 0;
};

#endif
