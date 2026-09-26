#ifndef CAMPUSAREA_H
#define CAMPUSAREA_H

#include <vector>
#include <string>

class AccessState;
class ResponseUnit;
class Incident;

class CampusArea
{
protected:
    std::vector<ResponseUnit*> responders;
    std::vector<Incident*> incidents;

    AccessState* state;
    std::string id;

public:
    explicit CampusArea(std::string id);
    virtual ~CampusArea();

    virtual void add(CampusArea* area);
    virtual void display(std::string indent = "");
    virtual void updateState(AccessState* newState);

    void addResponseUnit(ResponseUnit* unit);
    void addIncident(Incident* incident);

    std::string getId() const;
    std::string getStateDescription() const;
};

#endif
