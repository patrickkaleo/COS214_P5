#include "MitigationState.h"
#include "ResolvedState.h"
#include "Incident.h"

#include <iostream>

MitigationState::MitigationState(Incident* context)
    : IncidentState(context)
{
    mitigated = true;
}

MitigationState::~MitigationState()
{
}

std::string MitigationState::describe()
{
    return "MITIGATION";
}

void MitigationState::updateState()
{
    if (!mitigated)
    {
        std::cout
            << "[Incident State] Mitigation incomplete."
            << std::endl;

        return;
    }

    std::cout
        << "[Incident State] MITIGATION -> RESOLVED"
        << std::endl;

    context->updateState(
        new ResolvedState(context)
    );
}
