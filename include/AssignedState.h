#ifndef ASSIGNEDSTATE_H
#define ASSIGNEDSTATE_H

#include "IncidentState.h"

class AssignedState :public IncidentState{
    public:
        AssignedState(Incident* context);
        ~AssignedState();
        string describe();
        void updateState();
};

#endif
