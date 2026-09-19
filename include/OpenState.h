#ifndef OPENSTATE_H
#define OPENSTATE_H

#include "AccessState.h"

class OpenState:public AccessState{
    public:
        OpenState(CampusArea* context);
        ~OpenState();
        void updateState();
        string describe();
};

#endif
