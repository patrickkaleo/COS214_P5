#include "AlertServiceAdapter.h"
#include "LegacyAlertService.h"

#include <iostream>

AlertServiceAdapter::AlertServiceAdapter(
    LegacyAlertService* legacyService
)
    : adaptee(legacyService)
{
}

AlertServiceAdapter::~AlertServiceAdapter()
{
}

void AlertServiceAdapter::issueAlert()
{
    std::cout
        << "[Adapter] Translating issueAlert() to sendAlert()."
        << std::endl;

    if (adaptee != nullptr)
    {
        adaptee->sendAlert();
    }
}
