#ifndef ASSIGNEDSTATE_H
#define ASSIGNEDSTATE_H

#include "IncidentState.h"
#include <string>

class AssignedState : public IncidentState
{
public:
    explicit AssignedState(Incident* context);
    ~AssignedState();

    void updateState();
    std::string describe();
};

#endif
