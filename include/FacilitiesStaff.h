#ifndef FACILITIESSTAFF_H
#define FACILITIESSTAFF_H

#include "ResponseUnit.h"
#include <string>

class FacilitiesStaff : public ResponseUnit
{
public:
    explicit FacilitiesStaff(std::string id);

    std::string describe();
};

#endif
