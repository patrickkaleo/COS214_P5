#ifndef ALERTSERVICEADAPTER_H
#define ALERTSERVICEADAPTER_H

#include "AlertService.h"
#include "LegacyAlertService.h"

class AlertServiceAdapter:public AlertService{
    private:
        LegacyAlertService* adaptee;
    public:
        AlertServiceAdapter(LegacyAlertService* legacyService);
        ~AlertServiceAdapter();
        void issueAlert();
};

#endif
