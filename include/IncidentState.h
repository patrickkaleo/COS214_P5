#ifndef INCIDENTSTATE_H
#define INCIDENTSTATE_H

#include "Incident.h"

class IncidentState{
    protected:
        Incident* context;
        bool mitigated;
        IncidentState();
    public:
        ~IncidentState();
        virtual void updateState() =0;
        virtual string describe() = 0;
        
};

#endif
