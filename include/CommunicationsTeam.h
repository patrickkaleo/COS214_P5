#ifndef COMMUNICATIONSTEAM_H
#define COMMUNICATIONSTEAM_H

#include "ResponseUnit.h"
#include <string>

class CommunicationsTeam : public ResponseUnit
{
public:
    explicit CommunicationsTeam(std::string id);
};

#endif
