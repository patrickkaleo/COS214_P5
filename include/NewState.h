#ifndef NEWSTATE_H
#define NEWSTATE_H

#include "IncidentState.h"
#include <string>

class NewState : public IncidentState
{
public:
    explicit NewState(Incident* context);
    ~NewState();

    void updateState();
    std::string describe();
};

#endif
