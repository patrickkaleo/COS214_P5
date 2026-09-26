#ifndef ISSUEALERT_H
#define ISSUEALERT_H

#include "Command.h"


class IssueAlert :public Command{
    private:
        AlertService* target;
    public:
        IssueAlert(AlertService* target);
        ~IssueAlert();
        string describe();
        void excute();
};

#endif
