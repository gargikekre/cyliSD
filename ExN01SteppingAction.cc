#include "ExN01SteppingAction.hh"

#include "ExN01DetectorConstruction.hh"
#include "ExN01EventAction.hh"
#include "G4Track.hh"

#include "iostream"
#include "fstream"
using namespace std;
extern ofstream myfile;

////#include "G4RunManager.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ExN01SteppingAction::ExN01SteppingAction(ExN01DetectorConstruction* det, ExN01EventAction* evt)

:detector(det),eventaction(evt)
                                        
//:detector(det),eventaction(evt),myVerbose(NULL)					 
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ExN01SteppingAction::~ExN01SteppingAction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ExN01SteppingAction::UserSteppingAction(const G4Step* aStep)
{
  
  const G4Track* track = aStep->GetTrack();
  G4VPhysicalVolume* volume = track->GetVolume();
  
  G4Material* material = track->GetMaterial();
  G4Material* material2 = volume->GetLogicalVolume()->GetMaterial();

  //  G4cout <<"material "<<material->GetName()<<" "<<material2->GetName()<<" "<<" "<<detector->GetActiveMaterial()->GetName()<<" "<<aStep->GetPreStepPoint()->GetPosition()<<G4endl;

  // collect energy and track length step by step
  G4double edep = aStep->GetTotalEnergyDeposit();

  G4double stepl = 0.;
  if (track->GetDefinition()->GetPDGCharge() != 0.)
    stepl = aStep->GetStepLength();

  if (volume->GetName() == detector->GetEcal()->GetName()) {
    //    G4cout <<"ecal "<< material->GetName()<< G4endl;
    //    if (material == detector->GetActiveMaterial()) {

    eventaction->AddEcal(edep,stepl);

  } else {
    //    G4cout <<"Hcal "<< material->GetName()<<G4endl;

    eventaction->AddSupp(edep,stepl);

  }

}



