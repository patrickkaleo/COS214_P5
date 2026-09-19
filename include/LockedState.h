#ifndef LOCKEDSTATE_H
#define LOCKEDSTATE_H

#include "AccessState.h"

class LockedState: public AccessState{
    public:
        LockedState(CampusArea* context);
        ~LockedState();
        void updateState();
        string describe();
};

#endif
