#ifndef CAMPUSAREA_H
#define CAMPUSAREA_H

#include <vector>
#include <string>

#include "AccessState.h"
#include "ResponseUnit.h"
#include "Incident.h"

using namespace std;

class CampusArea{
    protected:
        
        vector<ResponseUnit*> responders;
        vector<Incident*> incidents;

        AccessState* state;
        string id;

        CampusArea();
    public:
        ~CampusArea();

        void add(CampusArea* area);
        virtual void display(string indent);
        void updateState(AccessState* newState);
        void addResponseUnit(ResponseUnit* unit);
        void addResponseUnit(Incident* incident);
};

#endif
