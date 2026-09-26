#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>

class IncidentState;
class CampusArea;

class Incident
{
private:
    IncidentState* state;
    std::string description;
    CampusArea* area;

public:
    explicit Incident(std::string description = "Unknown incident");
    ~Incident();

    void updateState(IncidentState* newState);
    void progress();
    void setArea(CampusArea* area);

    bool areaHasPersonnel() const;
    std::string describe();
};

#endif
