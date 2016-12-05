#include "ExN01SteppingVerbose.hh"

#include "G4SteppingManager.hh"
#include "G4UnitsTable.hh"
#include "iostream"
#include "fstream"
using namespace std;
extern ofstream myfile;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ExN01SteppingVerbose::ExN01SteppingVerbose()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ExN01SteppingVerbose::~ExN01SteppingVerbose()
{} 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ExN01SteppingVerbose::StepInfo()
{
  CopyState();
  
  G4int prec = myfile.precision(3);

  if( verboseLevel >= 1 ){
    if( verboseLevel >= 4 ) VerboseTrack();
    if( verboseLevel >= 3 ){
      myfile << G4endl;    
      myfile << std::setw( 5) << "#Step#"     << " "
	     << std::setw( 6) << "X"          << "    "
	     << std::setw( 6) << "Y"          << "    "  
	     << std::setw( 6) << "Z"          << "    "
	     << std::setw( 9) << "KineE"      << " "
	     << std::setw( 9) << "dEStep"     << " "  
	     << std::setw(10) << "StepLeng"     
	     << std::setw(10) << "TrakLeng" 
	     << std::setw(10) << "Volume"    << "  "
	     << std::setw(10) << "Process"   << G4endl;	          
    }

    myfile << std::setw( 5) << fTrack->GetCurrentStepNumber() << " "
	<< std::setw(6) << G4BestUnit(fTrack->GetPosition().x(),"Length")
	<< std::setw(6) << G4BestUnit(fTrack->GetPosition().y(),"Length")
	<< std::setw(6) << G4BestUnit(fTrack->GetPosition().z(),"Length")
	<< std::setw(6) << G4BestUnit(fTrack->GetKineticEnergy(),"Energy")
	<< std::setw(6) << G4BestUnit(fStep->GetTotalEnergyDeposit(),"Energy")
	<< std::setw(6) << G4BestUnit(fStep->GetStepLength(),"Length")
	<< std::setw(6) << G4BestUnit(fTrack->GetTrackLength(),"Length")
	<< "  ";

    // if( fStepStatus != fWorldBoundary){ 
    if( fTrack->GetNextVolume() != 0 ) { 
      myfile << std::setw(10) << fTrack->GetVolume()->GetName();
    } else {
      myfile << std::setw(10) << "OutOfWorld";
    }

    if(fStep->GetPostStepPoint()->GetProcessDefinedStep() != NULL){
      myfile << "  " 
             << std::setw(10) << fStep->GetPostStepPoint()
	                            ->GetProcessDefinedStep()->GetProcessName();
    } else {
      myfile << "   UserLimit";
    }

    myfile << G4endl;

    if( verboseLevel == 2 ){
      G4int tN2ndariesTot = fN2ndariesAtRestDoIt +
	                    fN2ndariesAlongStepDoIt +
	                    fN2ndariesPostStepDoIt;
      if(tN2ndariesTot>0){
	myfile << "    :----- List of 2ndaries - "
	       << "#SpawnInStep=" << std::setw(3) << tN2ndariesTot 
	       << "(Rest="  << std::setw(2) << fN2ndariesAtRestDoIt
	       << ",Along=" << std::setw(2) << fN2ndariesAlongStepDoIt
	       << ",Post="  << std::setw(2) << fN2ndariesPostStepDoIt
	       << "), "
	       << "#SpawnTotal=" << std::setw(3) << (*fSecondary).size()
	       << " ---------------"
	       << G4endl;

	for(size_t lp1=(*fSecondary).size()-tN2ndariesTot; 
                        lp1<(*fSecondary).size(); lp1++){
	  myfile << "    : "
		 << std::setw(6)
		 << G4BestUnit((*fSecondary)[lp1]->GetPosition().x(),"Length")
		 << std::setw(6)
		 << G4BestUnit((*fSecondary)[lp1]->GetPosition().y(),"Length")
		 << std::setw(6)
		 << G4BestUnit((*fSecondary)[lp1]->GetPosition().z(),"Length")
		 << std::setw(6)
		 << G4BestUnit((*fSecondary)[lp1]->GetKineticEnergy(),"Energy")
		 << std::setw(10)
		 << (*fSecondary)[lp1]->GetDefinition()->GetParticleName();
	  myfile << G4endl;
	}
              
	myfile << "    :-----------------------------"
	       << "----------------------------------"
	       << "-- EndOf2ndaries Info ---------------"
	       << G4endl;
      }
    }
    
  }
  myfile.precision(prec);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ExN01SteppingVerbose::TrackingStarted()
{

  CopyState();
G4int prec = myfile.precision(3);
  if( verboseLevel > 0 ){

    myfile << std::setw( 5) << "Step#"      << " "
           << std::setw( 6) << "X"          << "    "
	   << std::setw( 6) << "Y"          << "    "  
	   << std::setw( 6) << "Z"          << "    "
	   << std::setw( 9) << "KineE"      << " "
	   << std::setw( 9) << "dEStep"     << " "  
	   << std::setw(10) << "StepLeng"  
	   << std::setw(10) << "TrakLeng"
	   << std::setw(10) << "Volume"     << "  "
	   << std::setw(10) << "Process"    << G4endl;	     

    myfile << std::setw(5) << fTrack->GetCurrentStepNumber() << " "
	<< std::setw(6) << G4BestUnit(fTrack->GetPosition().x(),"Length")
	<< std::setw(6) << G4BestUnit(fTrack->GetPosition().y(),"Length")
	<< std::setw(6) << G4BestUnit(fTrack->GetPosition().z(),"Length")
	<< std::setw(6) << G4BestUnit(fTrack->GetKineticEnergy(),"Energy")
	<< std::setw(6) << G4BestUnit(fStep->GetTotalEnergyDeposit(),"Energy")
	<< std::setw(6) << G4BestUnit(fStep->GetStepLength(),"Length")
	<< std::setw(6) << G4BestUnit(fTrack->GetTrackLength(),"Length")
	<< "  ";

    if(fTrack->GetNextVolume()){
      myfile << std::setw(10) << fTrack->GetVolume()->GetName();
    } else {
      myfile << std::setw(10) << "OutOfWorld";
    }
    myfile  << "    initStep" << G4endl;
  }
  myfile.precision(prec);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
