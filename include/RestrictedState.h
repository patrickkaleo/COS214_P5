#ifndef RESTRICTEDSTATE_H
#define RESTRICTEDSTATE_H

#include "AccessState.h"
#include <string>

class RestrictedState : public AccessState
{
public:
    explicit RestrictedState(CampusArea* context);
    ~RestrictedState();

    void updateState();
    std::string describe();
};

#endif
