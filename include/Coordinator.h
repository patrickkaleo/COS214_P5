#ifndef COORDINATOR_H
#define COORDINATOR_H

class CampusArea;
class ResponseUnit;

class Coordinator
{
public:
    Coordinator();
    virtual ~Coordinator();

    virtual void deploy(
        CampusArea *area,
        ResponseUnit *unit) = 0;
};

#endif
