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
#include "AlertService.h"
#include "AlertServiceAdapter.h"

#include "Incident.h"

#include "NewState.h"
#include "OpenState.h"
#include "RestrictedState.h"
#include "LockedState.h"

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


    std::cout
        << "\nTrying to mitigate before security is on site:\n";

    fire.progress();

    std::cout
        << fire.describe()
        << std::endl;


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


    std::cout
        << "\nTrying to record the fire on Engineering again:\n";

    engineering->addIncident(&fire);


    std::cout
        << "\nTrying to record that same fire on Science:\n";

    science->addIncident(&fire);


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


    std::cout
        << "\nTrying to mitigate before the medical team arrives:\n";

    chemicalLeak.progress();

    std::cout
        << chemicalLeak.describe()
        << std::endl;


    // COMMAND + MEDIATOR + STATE

    std::cout
        << "\n2. Mobilise medical response\n";

    facade.mobilise(
        &chemicalLeak,
        science,
        &medical
    );

    std::cout
        << chemicalLeak.describe()
        << std::endl;


    std::cout
        << "\nTrying to lock Science again:\n";

    LockArea lockScience(science);

    campusOperator.run(&lockScience);

    science->display();


    std::cout
        << "\n3. Close the chemical leak\n";

    facade.closeIncident(
        &chemicalLeak,
        science
    );

    std::cout
        << chemicalLeak.describe()
        << std::endl;

    science->display();


    // ====================================================
    // SCENARIO 3
    // POWER CUT
    //
    // nobody on site, then facilities get sent
    // ====================================================

    std::cout
        << "\n====================================\n"
        << " SCENARIO 3: LIBRARY POWER CUT\n"
        << "====================================\n";


    Building* library =
        new Building("Library");

    library->add(
        new Room("Reading Room")
    );


    Incident powerCut(
        "Power cut in the Library"
    );

    library->addIncident(&powerCut);

    std::cout
        << "\n"
        << powerCut.describe()
        << std::endl;


    std::cout
        << "\nAssign it\n";

    powerCut.progress();


    std::cout
        << "\nMitigate with an empty library:\n";

    powerCut.progress();

    std::cout
        << powerCut.describe()
        << std::endl;


    std::cout
        << "\nMobilise facilities, then close the power cut\n";

    facade.mobilise(
        &powerCut,
        library,
        &facilities
    );

    std::cout
        << powerCut.describe()
        << std::endl;

    facade.closeIncident(
        &powerCut,
        library
    );

    std::cout
        << powerCut.describe()
        << std::endl;


    library->display();


    std::cout
        << "\nRecord the power cut a second time:\n";

    library->addIncident(&powerCut);


    std::cout
        << "\nBad facade calls:\n";

    facade.reportIncident(
        nullptr,
        library
    );

    facade.mobilise(
        nullptr,
        library,
        &security
    );

    facade.closeIncident(
        nullptr,
        library
    );

    facade.reportIncident(
        &fire,
        nullptr
    );


    CampusGuardFacade noAlert(
        &campusOperator,
        &coordinator,
        nullptr
    );

    noAlert.reportIncident(
        &fire,
        engineering
    );


    CampusGuardFacade noOperator(
        nullptr,
        nullptr,
        &alertAdapter
    );

    noOperator.mobilise(
        &fire,
        engineering,
        &security
    );

    noOperator.closeIncident(
        &fire,
        engineering
    );


    // ====================================================
    // paths the three scenarios never take
    // ====================================================

    std::cout
        << "\n====================================\n"
        << " EXTRA CHECKS\n"
        << "====================================\n";


    std::cout
        << "\nIncident that was never recorded on an area:\n";

    Incident loose(
        "Alarm with no area"
    );

    loose.progress();
    loose.progress();

    std::cout
        << loose.describe()
        << std::endl;

    loose.updateState(nullptr);


    std::cout
        << "\nIncident that goes away while the library is still up:\n";

    {
        Incident alarm(
            "Alarm test"
        );

        library->addIncident(&alarm);
    }


    std::cout
        << "\nNull adds and a room that cannot take a child:\n";

    engineering->add(nullptr);
    engineering->updateState(nullptr);
    engineering->addIncident(nullptr);
    engineering->addResponseUnit(nullptr);

    Room* closet =
        new Room("Storeroom");

    closet->add(nullptr);
    closet->updateState(nullptr);

    delete closet;


    std::cout
        << "\nCoordinator and operator with bad arguments:\n";

    coordinator.addColeague(nullptr);

    coordinator.deploy(
        nullptr,
        &security
    );

    coordinator.deploy(
        engineering,
        nullptr
    );

    campusOperator.run(nullptr);


    std::cout
        << "\nCommands with nothing to work on:\n";

    LockArea lockNothing(nullptr);
    campusOperator.run(&lockNothing);

    UnlockArea unlockNothing(nullptr);
    campusOperator.run(&unlockNothing);

    RestrictArea restrictNothing(nullptr);
    campusOperator.run(&restrictNothing);

    IssueAlert alertNothing(nullptr);
    campusOperator.run(&alertNothing);

    DispatchUnit dispatchNoTarget(
        nullptr,
        &security,
        engineering
    );

    campusOperator.run(&dispatchNoTarget);

    DispatchUnit dispatchNoUnit(
        &coordinator,
        nullptr,
        engineering
    );

    campusOperator.run(&dispatchNoUnit);

    DispatchUnit dispatchNoArea(
        &coordinator,
        &security,
        nullptr
    );

    campusOperator.run(&dispatchNoArea);


    std::cout
        << "\nSend security to Engineering again:\n";

    DispatchUnit dispatchSecurityAgain(
        &coordinator,
        &security,
        engineering
    );

    campusOperator.run(
        &dispatchSecurityAgain
    );


    std::cout
        << "\nUnit with no mediator, and null areas:\n";

    SecurityTeam visitor(
        "Night Guard"
    );

    visitor.respond(library);
    visitor.respond(nullptr);
    visitor.support(nullptr);
    visitor.support(library);


    std::cout
        << "\nPlain alert service, then an adapter with no legacy service:\n";

    AlertService plainAlert;

    IssueAlert campusNote(
        &plainAlert
    );

    std::cout
        << campusNote.describe()
        << std::endl;

    campusOperator.run(&campusNote);


    AlertServiceAdapter noLegacy(nullptr);

    IssueAlert brokenAlert(
        &noLegacy
    );

    campusOperator.run(&brokenAlert);


    std::cout
        << "\nDrill recorded on the library but tied to Engineering:\n";

    {
        Incident drill(
            "After hours drill"
        );

        library->addIncident(&drill);
        drill.setArea(engineering);

        DispatchUnit sendComms(
            &coordinator,
            &communications,
            library
        );

        campusOperator.run(&sendComms);

        drill.setArea(library);
    }


    std::cout
        << "\nLibrary access state moves itself:\n";

    library->getState()->updateState();
    library->display();

    library->getState()->updateState();
    library->display();

    library->getState()->updateState();
    library->display();


    std::cout
        << "\nRestrict the library twice:\n";

    RestrictArea restrictLibrary(library);
    campusOperator.run(&restrictLibrary);
    campusOperator.run(&restrictLibrary);


    std::cout
        << "\nTeam labels:\n";

    std::cout
        << security.describe()
        << std::endl;

    std::cout
        << medical.describe()
        << std::endl;

    std::cout
        << communications.describe()
        << std::endl;

    std::cout
        << facilities.describe()
        << std::endl;


    std::cout
        << "\nStates that were built with no context:\n";

    OpenState openNone(nullptr);
    openNone.updateState();

    RestrictedState restrictedNone(nullptr);
    restrictedNone.updateState();

    LockedState lockedNone(nullptr);
    lockedNone.updateState();

    NewState newNone(nullptr);
    newNone.updateState();


    std::cout
        << "\nClose a NEW incident in an empty shed:\n";

    Building* shed =
        new Building("Shed");

    Incident drip(
        "Drip in the shed"
    );

    shed->addIncident(&drip);

    facade.closeIncident(
        &drip,
        shed
    );

    std::cout
        << drip.describe()
        << std::endl;

    delete shed;


    std::cout
        << "\nClose a NEW incident where staff are already on site:\n";

    Incident late(
        "Late alarm in the library"
    );

    library->addIncident(&late);

    facade.closeIncident(
        &late,
        library
    );

    std::cout
        << late.describe()
        << std::endl;


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
        << "Incident 3: "
        << powerCut.describe()
        << std::endl;


    std::cout
        << "\nEngineering:\n";

    engineering->display();


    std::cout
        << "\nScience:\n";

    science->display();


    std::cout
        << "\nLibrary:\n";

    library->display();


    delete engineering;
    delete science;
    delete library;


    std::cout
        << "\n====================================\n"
        << " CampusGuard terminated successfully\n"
        << "====================================\n";


    return 0;
}
