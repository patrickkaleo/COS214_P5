#include "AlertService.h"
#include <iostream>

AlertService::AlertService()
{
}

AlertService::~AlertService()
{
}

void AlertService::issueAlert()
{
    std::cout
        << "[AlertService] Campus alert issued."
        << std::endl;
}
