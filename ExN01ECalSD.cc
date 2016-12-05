
#include "ExN01EcalSD.hh"
#include "ExN01EcalHit.hh"
#include "G4SDManager.hh"
#include "G4Step.hh"
#include "G4HCofThisEvent.hh"
#include "G4TouchableHistory.hh"
#include "G4ios.hh"
#include "G4Event.hh"

ExN01EcalSD::ExN01EcalSD(G4String name)
  :G4VSensitiveDetector(name)
{
  G4String HCname;
  collectionName.insert(HCname="EcalCollect");
}

ExN01EcalSD::~ExN01EcalSD(){;}

void ExN01EcalSD::Initialize(G4HCofThisEvent* HCE)
{
    EcalCollection = new ExN01EcalHitsCollection
                      (SensitiveDetectorName,collectionName[0]); 
  static G4int HCID = -1;

  if(HCID<0)
  { HCID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); }
}

G4bool ExN01EcalSD::ProcessHits(G4Step* aStep, G4TouchableHistory*)
{

 G4double edep = aStep->GetTotalEnergyDeposit();

 if (edep== 0) return false;

  ExN01EcalHit* newHit = new ExN01EcalHit();
  newHit->SetEdep      (edep);

  return true;
}

void ExN01EcalSD::EndOfEvent(G4HCofThisEvent*)
{
}

void ExN01EcalSD::clear()
{
} 

void ExN01EcalSD::DrawAll()
{
} 

void ExN01EcalSD::PrintAll()
{
} 
