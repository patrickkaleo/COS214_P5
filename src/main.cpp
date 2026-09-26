#include <iostream>

#include "Operator.h"

#include "Building.h"
#include "Room.h"

#include "SecurityTeam.h"
#include "MedicalTeam.h"
#include "FacilitiesStaff.h"
#include "CommunicationsTeam.h"
#include "TeamCoordinator.h"

#include "LegacyAlertService.h"
#include "AlertServiceAdapter.h"

#include "Incident.h"

#include "RestrictArea.h"
#include "LockArea.h"
#include "UnlockArea.h"
#include "DispatchUnit.h"
#include "IssueAlert.h"

#include "CampusGuardFacade.h"

int main()
{
    std::cout
        << "====================================\n"
        << "          CAMPUSGUARD\n"
        << "====================================\n";


    // ====================================================
    // COMPOSITE
    // ====================================================

    Building* engineering =
        new Building("Engineering Building");

    engineering->add(
        new Room("Engineering Lab")
    );

    engineering->add(
        new Room("Lecture Room 2-1")
    );

    engineering->add(
        new Room("Server Room")
    );


    Building* science =
        new Building("Science Building");

    science->add(
        new Room("Chemistry Lab")
    );

    science->add(
        new Room("Physics Lab")
    );


    // ====================================================
    // MEDIATOR
    // ====================================================

    TeamCoordinator coordinator;

    SecurityTeam security(
        "Campus Security"
    );

    MedicalTeam medical(
        "Medical Team"
    );

    FacilitiesStaff facilities(
        "Facilities Staff"
    );

    CommunicationsTeam communications(
        "Communications Team"
    );


    coordinator.addColeague(&security);
    coordinator.addColeague(&medical);
    coordinator.addColeague(&facilities);
    coordinator.addColeague(&communications);


    // ====================================================
    // ADAPTER
    // ====================================================

    LegacyAlertService legacyAlert;

    AlertServiceAdapter alertAdapter(
        &legacyAlert
    );


    // ====================================================
    // COMMAND INVOKER
    // ====================================================

    Operator campusOperator;


    // ====================================================
    // SCENARIO 1
    // FIRE IN ENGINEERING
    //
    // Patterns:
    // State
    // Command
    // Mediator
    // Composite
    // Adapter
    // ====================================================

    std::cout
        << "\n====================================\n"
        << " SCENARIO 1: ENGINEERING FIRE\n"
        << "====================================\n";


    Incident fire(
        "Fire in Engineering Lab"
    );

    engineering->addIncident(&fire);


    std::cout
        << "\nInitial incident:\n"
        << fire.describe()
        << std::endl;


    // STATE:
    // NEW -> ASSIGNED

    std::cout
        << "\n1. Assign incident\n";

    fire.progress();


    // COMMAND + MEDIATOR

    std::cout
        << "\n2. Dispatch security\n";

    DispatchUnit dispatchSecurity(
        &coordinator,
        &security,
        engineering
    );

    campusOperator.run(
        &dispatchSecurity
    );


    // COMMAND + STATE + COMPOSITE

    std::cout
        << "\n3. Restrict Engineering Building\n";

    RestrictArea restrictEngineering(
        engineering
    );

    campusOperator.run(
        &restrictEngineering
    );


    std::cout
        << "\nBuilding hierarchy:\n";

    engineering->display();


    // COMMAND + ADAPTER

    std::cout
        << "\n4. Send emergency alert\n";

    IssueAlert emergencyAlert(
        &alertAdapter
    );

    campusOperator.run(
        &emergencyAlert
    );


    // STATE:
    // ASSIGNED -> MITIGATION

    std::cout
        << "\n5. Begin mitigation\n";

    fire.progress();

    std::cout
        << fire.describe()
        << std::endl;


    // STATE:
    // MITIGATION -> RESOLVED

    std::cout
        << "\n6. Resolve incident\n";

    fire.progress();

    std::cout
        << fire.describe()
        << std::endl;


    // COMMAND + COMPOSITE

    std::cout
        << "\n7. Reopen Engineering Building\n";

    UnlockArea reopenEngineering(
        engineering
    );

    campusOperator.run(
        &reopenEngineering
    );

    engineering->display();


    // ====================================================
    // FAILURE / INVALID CASES
    // ====================================================

    std::cout
        << "\n====================================\n"
        << " INVALID OPERATION TESTS\n"
        << "====================================\n";


    std::cout
        << "\nTrying to reopen an already OPEN building:\n";

    campusOperator.run(
        &reopenEngineering
    );


    std::cout
        << "\nTrying to progress a RESOLVED incident:\n";

    fire.progress();


    // ====================================================
    // SCENARIO 2
    // CHEMICAL LEAK
    //
    // Main focus:
    // Facade
    // ====================================================

    std::cout
        << "\n====================================\n"
        << " SCENARIO 2: CHEMICAL LEAK\n"
        << "====================================\n";


    Incident chemicalLeak(
        "Chemical leak in Chemistry Lab"
    );


    CampusGuardFacade facade(
        &campusOperator,
        &coordinator,
        &alertAdapter
    );


    // Client makes one simple Facade call.

    std::cout
        << "\n1. Report emergency through Facade\n";

    facade.reportIncident(
        &chemicalLeak,
        science
    );


    std::cout
        << "\nCurrent incident:\n"
        << chemicalLeak.describe()
        << std::endl;


    std::cout
        << "\nScience Building:\n";

    science->display();


    // COMMAND + MEDIATOR

    std::cout
        << "\n2. Dispatch Medical Team\n";

    DispatchUnit dispatchMedical(
        &coordinator,
        &medical,
        science
    );

    campusOperator.run(
        &dispatchMedical
    );


    // COMMAND + COMPOSITE

    std::cout
        << "\n3. Lock entire Science Building\n";

    LockArea lockScience(
        science
    );

    campusOperator.run(
        &lockScience
    );

    science->display();


    // INCIDENT STATE

    std::cout
        << "\n4. Begin mitigation\n";

    chemicalLeak.progress();

    std::cout
        << chemicalLeak.describe()
        << std::endl;


    std::cout
        << "\n5. Resolve chemical leak\n";

    chemicalLeak.progress();

    std::cout
        << chemicalLeak.describe()
        << std::endl;


    // OPEN AREA AGAIN

    std::cout
        << "\n6. Reopen Science Building\n";

    UnlockArea reopenScience(
        science
    );

    campusOperator.run(
        &reopenScience
    );

    science->display();


    std::cout
        << "\n====================================\n"
        << " FINAL STATUS\n"
        << "====================================\n";


    std::cout
        << "\nIncident 1: "
        << fire.describe()
        << std::endl;

    std::cout
        << "Incident 2: "
        << chemicalLeak.describe()
        << std::endl;


    std::cout
        << "\nEngineering:\n";

    engineering->display();


    std::cout
        << "\nScience:\n";

    science->display();



    delete engineering;
    delete science;


    std::cout
        << "\n====================================\n"
        << " CampusGuard terminated successfully\n"
        << "====================================\n";


    return 0;
}
