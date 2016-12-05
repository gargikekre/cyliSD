
// $Id: exampleN03.cc,v 1.22 2005/05/26 12:21:05 gcosmo Exp $
// GEANT4 tag $Name: geant4-07-01 $
//

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4UIterminal.hh"
#include "G4UItcsh.hh"

//#ifdef G4UI_USE_XM
#include "G4UIXm.hh"
//#endif

//#ifdef G4UI_USE_WIN32
//#include "G4UIWin32.hh"
//#endif

//#include "Randomize.hh"

//#include "math.h"
//#include "CLHEP/Random/RandGauss.h"

#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#endif

#include "ExN01DetectorConstruction.hh"
//#include "QGSP.hh"
//#include "LHEP.hh"
#include "ExN01PhysicsList.hh"
#include "ExN01PrimaryGeneratorAction.hh"
#include "ExN01RunAction.hh"
#include "ExN01EventAction.hh"
#include "ExN01SteppingAction.hh"
#include "ExN01SteppingVerbose.hh"
#include "NeutronHPphysics.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

int main(int argc,char** argv) {

  // choose the Random engine
//  CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);
//  HepRandom::setTheEngine(RanecuEngine());

  G4VSteppingVerbose::SetInstance(new ExN01SteppingVerbose);
     
  // Construct the default run manager
  G4RunManager * runManager = new G4RunManager;

  // set mandatory initialization classes
  ExN01DetectorConstruction* detector = new ExN01DetectorConstruction;
  runManager->SetUserInitialization(detector);

  runManager->SetUserInitialization(new ExN01PhysicsList);

  //runManager->SetUserInitialization(new NeutronHPphysics);
  //runManager->SetUserInitialization(new NeutronHPMessenger);

//  G4VUserPhysicsList* physics = new ExN01PhysicsList;
//  runManager->SetUserInitialization(new LHEP);

 G4UIsession* session=0;

  if (argc==1)   // Define UI session for interactive mode.
    {
      // G4UIterminal is a (dumb) terminal.
#if defined(G4UI_USE_XM)
      session = new G4UIXm(argc,argv);
#elif defined(G4UI_USE_WIN32)
      session = new G4UIWin32();
#elif defined(G4UI_USE_TCSH)
      session = new G4UIterminal(new G4UItcsh);      
#else
      session = new G4UIterminal();
#endif
    }
  
#ifdef G4VIS_USE
  // visualization manager
  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();
#endif
    
  // set user action classes

  runManager->SetUserAction(new ExN01PrimaryGeneratorAction);

  runManager->SetUserAction(new ExN01RunAction);

  ExN01EventAction* eventaction = new ExN01EventAction;

  runManager->SetUserAction(eventaction);

  runManager->SetUserAction(new ExN01SteppingAction(detector, eventaction));


  
  //Initialize G4 kernel
  runManager->Initialize();
    
  // get the pointer to the User Interface manager 
  G4UImanager* UI = G4UImanager::GetUIpointer();  

  if(argc==1)  // Define (G)UI terminal for interactive mode
  {
    // G4UIterminal is a (dumb) terminal
    //
    G4UIsession * session = 0;
#ifdef G4UI_USE_TCSH
      session = new G4UIterminal(new G4UItcsh);
#else
      session = new G4UIterminal();
#endif
     UI->ApplyCommand("/control/execute vis2.mac");  // for visualisation
//  UI->ApplyCommand("/control/execute vis2eff.mac");
 //   UI->ApplyCommand("/control/execute vis1.mac");
//     UI->ApplyCommand("/control/execute visd.mac");
   //UI->ApplyCommand("/control/execute vis2mtech.mac"); //for data generation
    session->SessionStart();
    delete session;
  }
  else   // Batch mode
  {
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UI->ApplyCommand(command+fileName);
  }

  // job termination
#ifdef G4VIS_USE
  delete visManager;
#endif
  delete runManager;

  return 0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
