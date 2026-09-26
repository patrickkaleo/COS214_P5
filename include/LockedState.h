#ifndef LOCKEDSTATE_H
#define LOCKEDSTATE_H

#include "AccessState.h"
#include <string>

class LockedState : public AccessState
{
public:
    explicit LockedState(CampusArea* context);
    ~LockedState();
    void updateState();
    std::string describe();
};

#endif
