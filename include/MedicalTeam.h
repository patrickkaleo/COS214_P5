#ifndef MEDICALTEAM_H
#define MEDICALTEAM_H

#include "ResponseUnit.h"
#include <string>

class MedicalTeam : public ResponseUnit
{
public:
    explicit MedicalTeam(std::string id);

    std::string describe();
};

#endif
