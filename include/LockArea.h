#ifndef LOCKAREA_H
#define LOCKAREA_H

#include "Command.h"
#include "CampusArea.h"

class LockArea: public Command{
    private:
        CampusArea* target;
    public:
        LockArea(CampusArea* target);
        void excute();
};

#endif
