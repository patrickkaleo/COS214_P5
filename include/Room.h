#ifndef ROOM_H
#define ROOM_H

#include "CampusArea.h"

class Room :public CampusArea{
    public:
        Room(string description);
        ~Room();
};


#endif
