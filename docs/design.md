# DESIGN OF THE SYSTEM FROM THE SCENARIO0

## System: CampusGuard
1. Team [Security, Medical responders, facilitiesStaff]
2. access-control systems
3. communication services
4. External legacy sytem accesed through the adapter
5. Incidents
    - registering
    - updating status (__STATE PATTERN__)
    - dispatching campus security, medical responders and staff
6. Building access actions eg: locking, unlocking, restricting areas
7. operator actions
    - dispatch response
    - issue evacuation notice
    - activate imagerncy response
    - cancel action

8. Coordinate between response components 
9. High level workflow that requires multiple services

## COMMAND PATTERN
_Operator_ invoker
_Command_ 
_ConcreteCommand_: 
_Reciever_