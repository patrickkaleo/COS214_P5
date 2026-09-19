#ifndef RESOLVEDSTATE_H
#define RESOLVEDSTATE_H

#include "IncidentState.h"

class ResolvedState:public IncidentState{
    public:
        ResolvedState(Incident* context);
        ~ResolvedState();
        string describe();
        void updateState();
};

#endif
