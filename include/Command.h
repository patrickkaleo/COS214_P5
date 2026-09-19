#ifndef COMMAND_H
#define COMMAND_H

#include "AlertService.h"
#include <string>
using namespace std;

class Command{
    protected:
        Command();
    public:
        ~Command();
        virtual void excute() = 0;

};

#endif
