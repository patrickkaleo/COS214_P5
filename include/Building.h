#ifndef BUILDING_H
#define BUILDING_H

#include "CampusArea.h"

class Building :public CampusArea{
    private:
        std::vector<CampusArea*> children;
    public:
        Building(string description);
        ~Building();
        void add(CampusArea* area);
        void display(string indent);
        void updateState(AccessState* newState);
};

#endif
