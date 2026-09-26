#ifndef UNLOCKAREA_H
#define UNLOCKAREA_H

#include "Command.h"
#include "CampusArea.h"

class UnlockArea:public Command{
    private:
        CampusArea* target;
    public:
        UnlockArea(CampusArea* target);
        void excute();
};

#endif
