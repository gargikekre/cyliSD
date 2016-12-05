
#ifndef ExN01EcalSD_h
#define ExN01EcalSD_h 1

#include "G4VSensitiveDetector.hh"
#include "ExN01EcalHit.hh"
class G4Step;
class G4HCofThisEvent;
class G4TouchableHistory;

class ExN01EcalSD : public G4VSensitiveDetector
{

  public:
      ExN01EcalSD(G4String name);
      ~ExN01EcalSD();

      void Initialize(G4HCofThisEvent*HCE);
      G4bool ProcessHits(G4Step*aStep,G4TouchableHistory*ROhist);
      void EndOfEvent(G4HCofThisEvent*HCE);
      
      void clear();
      void DrawAll();
      void PrintAll();

  private:
      ExN01EcalHitsCollection *EcalCollection;
  public:
};




#endif

