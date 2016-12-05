
// $Id: ExN01SteppingAction.hh,v 1.8 2003/09/15 15:38:14 maire Exp $
// GEANT4 tag $Name: geant4-07-01 $
//
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef ExN01SteppingAction_h
#define ExN01SteppingAction_h 1

#include "G4UserSteppingAction.hh"

class ExN01DetectorConstruction;
class ExN01EventAction;
class G4SteppingVerbose2;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class ExN01SteppingAction : public G4UserSteppingAction
{
  public:
    ExN01SteppingAction(ExN01DetectorConstruction*, ExN01EventAction*);
   ~ExN01SteppingAction();

    void UserSteppingAction(const G4Step*);
    
  private:
    ExN01DetectorConstruction* detector;
    ExN01EventAction*          eventaction;
    G4SteppingVerbose2* myVerbose;  
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
