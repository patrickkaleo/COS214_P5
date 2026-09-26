#ifndef RESPONSEUNIT_H
#define RESPONSEUNIT_H

#include <string>

class TeamCoordinator;
class CampusArea;

class ResponseUnit
{
private:
    TeamCoordinator* mediator;
    std::string id;

protected:
    explicit ResponseUnit(std::string id);

public:
    virtual ~ResponseUnit();

    void setMediator(TeamCoordinator* mediator);
    void respond(CampusArea* area);
    void support(CampusArea* area);

    virtual std::string describe() = 0;

    std::string getId() const;
};

#endif
