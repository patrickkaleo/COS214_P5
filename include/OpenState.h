#ifndef OPENSTATE_H
#define OPENSTATE_H

#include "AccessState.h"
#include <string>

class OpenState : public AccessState
{
public:
    explicit OpenState(CampusArea* context);
    ~OpenState();

    void updateState();
    std::string describe();
};

#endif
