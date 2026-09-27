#ifndef ALERTSERVICE_H
#define ALERTSERVICE_H

class AlertService
{
public:
    AlertService();
    virtual ~AlertService();

    virtual void issueAlert();
};

#endif
