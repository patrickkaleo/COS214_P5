#ifndef RESTRICTEDSTATE_H
#define RESTRICTEDSTATE_H

#include "AccessState.h"

class RestrictedState :public AccessState{
    public:
        RestrictedState(CampusArea* context);
        ~RestrictedState();
        void updateState();
        string describe();
};

#endif
