#include "LegacyAlertService.h"
#include <iostream>

LegacyAlertService::LegacyAlertService()
{
}

void LegacyAlertService::sendAlert()
{
    std::cout
        << "[LegacyAlertService] Legacy emergency alert sent."
        << std::endl;
}
