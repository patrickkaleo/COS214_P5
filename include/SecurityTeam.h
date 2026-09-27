#ifndef SECURITYTEAM_H
#define SECURITYTEAM_H

#include "ResponseUnit.h"
#include <string>

class SecurityTeam : public ResponseUnit
{
public:
    explicit SecurityTeam(std::string id);

    std::string describe();
};

#endif
