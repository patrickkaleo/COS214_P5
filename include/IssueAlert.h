#ifndef ISSUEALERT_H
#define ISSUEALERT_H

#include "Command.h"
#include <string>

class AlertService;

class IssueAlert : public Command
{
private:
    AlertService* target;

public:
    explicit IssueAlert(AlertService* target);
    ~IssueAlert();

    std::string describe();
    void excute();
};

#endif
