#ifndef ACCESSSTATE_H
#define ACCESSSTATE_H

#include <string>

class CampusArea;

class AccessState
{
protected:
    CampusArea* context;
    AccessState();

public:
    virtual ~AccessState();
    virtual void updateState() = 0;
    virtual std::string describe() = 0;
};

#endif
