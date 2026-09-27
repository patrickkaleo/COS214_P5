#include "Operator.h"
#include "Command.h"

#include <iostream>

Operator::Operator()
{
}

void Operator::run(Command* command)
{
    if (command == nullptr)
    {
        std::cout
            << "[Operator] No command supplied."
            << std::endl;

        return;
    }

    command->excute();
}
