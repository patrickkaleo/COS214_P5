#include "IssueAlert.h"
#include "AlertService.h"

#include <iostream>

IssueAlert::IssueAlert(AlertService* target)
    : target(target)
{
}

IssueAlert::~IssueAlert()
{
}

std::string IssueAlert::describe()
{
    return "Issue campus alert";
}

void IssueAlert::excute()
{
    if (target == nullptr)
    {
        std::cout
            << "[IssueAlert] No alert service."
            << std::endl;

        return;
    }

    std::cout
        << "[Command] Issuing campus alert."
        << std::endl;

    target->issueAlert();
}
