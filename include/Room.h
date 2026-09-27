#ifndef ROOM_H
#define ROOM_H

#include "CampusArea.h"
#include <string>

class Room : public CampusArea
{
public:
    explicit Room(std::string description);
    ~Room();
};

#endif
