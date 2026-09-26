#ifndef MITIGATIONSTATE_H
#define MITIGATIONSTATE_H

#include "IncidentState.h"
#include <string>

class MitigationState : public IncidentState
{
public:
    explicit MitigationState(Incident* context);
    ~MitigationState();

    void updateState();
    std::string describe();
};

#endif
