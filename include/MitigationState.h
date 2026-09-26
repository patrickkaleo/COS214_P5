#ifndef MITIGATIONSTATE_H
#define MITIGATIONSTATE_H

#include "IncidentState.h"

class MitigationState:public IncidentState{
    public:
        MitigationState(Incident* context);
        ~MitigationState();
        string describe();
        void updateState();
};

#endif
