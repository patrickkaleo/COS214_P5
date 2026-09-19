#ifndef INCIDENT_H
#define INCIDENT_H

class IncidentState;
#include <string>

using namespace std;

class Incident{
    private:
        IncidentState* state;
        string description;
    public:
        Incident();
        void updateState(IncidentState* newState);
        string describe();
};


#endif
