#include "ExN01RunAction.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"

#include "iostream"
#include "fstream"
using namespace std;
ofstream myfile("0cm.dat");

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ExN01RunAction::ExN01RunAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ExN01RunAction::~ExN01RunAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ExN01RunAction::BeginOfRunAction(const G4Run* aRun)
{
//  myfile << "### Run " << aRun->GetRunID() << " start." << G4endl;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ExN01RunAction::EndOfRunAction(const G4Run*)
{ }

