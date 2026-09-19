#ifndef NEWSTATE_H
#define NEWSTATE_H

#include "IncidentState.h"

class NewState:public IncidentState{
    public:
        NewState(Incident* context);
        ~NewState();
        string describe();
        void updateState();
};

#endif
