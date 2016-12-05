#include "ExN01EventAction.hh"
//#include "ExN01RunAction.hh"

#include "G4HCofThisEvent.hh"
#include "ExN01EcalHit.hh"

#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4TrajectoryContainer.hh"
#include "G4VTrajectory.hh"
#include "G4VVisManager.hh"
#include "G4UnitsTable.hh"
#include "G4UImanager.hh"
#include "Randomize.hh"
#include "G4ios.hh"

#include "G4SDManager.hh"
#include "G4Trajectory.hh"

#include "iostream"
#include "fstream"
using namespace std;
extern ofstream myfile;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
ExN01EventAction::ExN01EventAction()
:drawFlag("None"),printModulo(1)
//:drawFlag("None"),printModulo(10)
{}

ExN01EventAction::~ExN01EventAction()
{}

void ExN01EventAction::BeginOfEventAction(const G4Event* evt)
{

//G4int evtNb = evt->GetEventID();

 //printing survey
// if (evtNb%printModulo == 0)
//    G4cout << "\n---> Begin of Event: " << evtNb << G4endl;

 //additional initializations
// TotalEnergyDeposit = 0.;

  EnergyEcal=0;
/*
  G4SDManager * SDman = G4SDManager::GetSDMpointer();
  if(EcalCollID<0)
    {
    G4SDManager * SDman = G4SDManager::GetSDMpointer();
    G4String colNam;
    EcalCollID = SDman->GetCollectionID(colNam="EcalCollect");
    }
*/
}

void ExN01EventAction::EndOfEventAction(const G4Event* evt)
{
//  G4int eventNb = evt->GetEventID();

//  if (evtNb%printModulo == 0) {
//    G4cout << "---> End of event: " << evtNb << G4endl;	
/*
    G4cout
       << G4endl
       << "    Absrober: total energy: " << std::setw(7)
                                        << G4BestUnit(EnergySupp,"Energy")
       << "        total track length: " << std::setw(7)
                                        << G4BestUnit(TrackLSupp,"Length")
       << G4endl
       << "Scintillator: Ecal total energy: " << std::setw(7)
                                        << G4BestUnit(EnergyEcal,"Energy")
       << "        total track length: " << std::setw(7)
                                        << G4BestUnit(TrackLEcal,"Length")
       << G4endl;
*/
//if (drawFlag != "all")

//  if (evtNb%printModulo == 0) {
//    G4cout << "---> End of event: " << evtNb << G4endl;

//    myfile << " Energy deposit: "
      myfile
         << EnergyEcal/keV<< G4endl;
//       << G4BestUnit(TotalEnergyDeposit,"Energy") << G4endl;
//   myfile.close();

//  }

  // draw trajectories
  if(G4VVisManager::GetConcreteInstance())
  {
   G4TrajectoryContainer* trajectoryContainer = evt->GetTrajectoryContainer();
   G4int n_trajectories = 0;
   if (trajectoryContainer) n_trajectories = trajectoryContainer->entries();
   for(G4int i=0; i<n_trajectories; i++)
      { G4Trajectory* trj = (G4Trajectory *)
                                      ((*(evt->GetTrajectoryContainer()))[i]);
        if (drawFlag == "all") trj->DrawTrajectory(1000);
        else if ((drawFlag == "charged")&&(trj->GetCharge() != 0.))
                               trj->DrawTrajectory(1000);
  }
}
  // SDHit

  /*
  G4TrajectoryContainer* trajectoryContainer = evt->GetTrajectoryContainer();
  G4int n_trajectories = 0;
  if (trajectoryContainer) n_trajectories = trajectoryContainer->entries();

  // extract the trajectories and draw them
  //
  if (G4VVisManager::GetConcreteInstance())
    {
     for (G4int i=0; i<n_trajectories; i++)
        { G4Trajectory* trj = (G4Trajectory*)
                                    ((*(evt->GetTrajectoryContainer()))[i]);
          trj->DrawTrajectory(50);
        }
    }

  */

//  G4cout <<"eventaction "<<EcalCollID<< G4endl;
/*
  if(EcalCollID<0) return;

  G4HCofThisEvent * HCE = evt->GetHCofThisEvent();
  ExN01EcalHitsCollection* EHC = 0;
  if(HCE)  {
    EHC = (ExN01EcalHitsCollection*)(HCE->GetHC(EcalCollID));
  }

  if(EHC)
  {
    int n_hit = EHC->entries();

    G4double totE = 0;
    for (int i=0; i<n_hit; i++) {
      totE +=(*EHC)[i]->GetEdep();
      G4cout <<"Energy deposited in hit "<<i<<" "<<(*EHC)[i]->GetEdep()<< " at "<<(*EHC)[i]->GetPos()<<" at "<<(*EHC)[i]->GetTime()<<" "<<(*EHC)[i]->GetHitId() <<G4endl;
    }
//    G4cout << "     " << n_hit
//           << " hits are stored in ExN01EcalHitsCollection with total Ene// rgy  "<<totE << G4endl;
  }
*/
}





