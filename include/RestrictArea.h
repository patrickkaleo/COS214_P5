#ifndef RESTRICTAREA_H
#define RESTRICTAREA_H

#include "Command.h"
#include "CampusArea.h"

class RestrictArea: public Command{
    private:
        CampusArea* target;
    public:
        RestrictArea(CampusArea* target);
        void excute();
};

#endif
