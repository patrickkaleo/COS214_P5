#ifndef OPERATOR_H
#define OPERATOR_H

class Command;

class Operator
{
public:
    Operator();

    void run(Command* command);
};

#endif
