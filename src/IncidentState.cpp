#include "IncidentState.h"

IncidentState::IncidentState(Incident* context)
    : context(context),
      mitigated(false)
{
}

IncidentState::~IncidentState()
{
}
