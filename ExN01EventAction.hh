
#ifndef ExN01EventAction_h
#define ExN01EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"

class ExN01RunAction;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class ExN01EventAction : public G4UserEventAction
{
 public:
   ExN01EventAction();
  ~ExN01EventAction();

 public:
   void  BeginOfEventAction(const G4Event*);
   void    EndOfEventAction(const G4Event*);
    
   void AddEcal(G4double de, G4double dl) {EnergyEcal += de; TrackLEcal += dl;};
   void AddSupp(G4double de, G4double dl) {EnergySupp += de; TrackLSupp += dl;};
      
   void SetDrawFlag   (G4String val)  {drawFlag = val;};
   void SetPrintModulo(G4int    val)  {printModulo = val;};
    
 private:
   ExN01RunAction* Run;
   G4double  EnergyEcal, EnergySupp;
   G4double  TrackLEcal, TrackLSupp;
                     
   G4String  drawFlag;
   G4int     printModulo;
                             
//   ExN01EventActionMessenger*  eventMessenger;

  G4int EcalCollID;

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

    
