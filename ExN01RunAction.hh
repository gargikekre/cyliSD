#ifndef ExN01RunAction_h
#define ExN01RunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class G4Run;

namespace AIDA {
  class IAnalysisFactory;
  class ITree;
  class IHistogram1D;
}  

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class ExN01RunAction : public G4UserRunAction
{
  public:
    ExN01RunAction();
   ~ExN01RunAction();

  public:
    void BeginOfRunAction(const G4Run*);
    void   EndOfRunAction(const G4Run*);
  
    AIDA::IHistogram1D* GetHisto(G4int id) {return histo[id];}
    
  private:
    AIDA::IAnalysisFactory* af;         
    AIDA::ITree*            tree;             
    AIDA::IHistogram1D*     histo[1];        
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

