#ifndef INCIDENTSTATE_H
#define INCIDENTSTATE_H

#include <string>

class Incident;

class IncidentState
{
protected:
    Incident* context;
    bool mitigated;

    explicit IncidentState(Incident* context);

public:
    virtual ~IncidentState();

    virtual void updateState() = 0;
    virtual std::string describe() = 0;
};

#endif
