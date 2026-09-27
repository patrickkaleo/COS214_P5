#ifndef RESOLVEDSTATE_H
#define RESOLVEDSTATE_H

#include "IncidentState.h"
#include <string>

class ResolvedState : public IncidentState
{
public:
    explicit ResolvedState(Incident* context);
    ~ResolvedState();

    void updateState();
    std::string describe();
};

#endif
