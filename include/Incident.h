#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>

class IncidentState;

class Incident
{
private:
    IncidentState* state;
    std::string description;

public:
    explicit Incident(std::string description = "Unknown incident");
    ~Incident();

    void updateState(IncidentState* newState);
    void progress();

    std::string describe();
};

#endif
