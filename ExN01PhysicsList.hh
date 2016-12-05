#ifndef ExN01PhysicsList_h
#define ExN01PhysicsList_h 1

//#include "G4VPhysicsConstructor.hh"

#include "G4VUserPhysicsList.hh"
#include "globals.hh"

class G4LowEnergyIonisation;
class G4LowEnergyPhotoElectric;
class G4LowEnergyBremsstrahlung;
class G4eIonisation;

class ExN01PhysicsList: public G4VUserPhysicsList
{
  public:
//    ExN01PhysicsList(const G4String& name = "general");
    ExN01PhysicsList();
    ~ExN01PhysicsList();

  protected:
    // Construct particle and physics process
    void ConstructParticle();
    void ConstructProcess();
    void SetCuts();

  protected:
    // these methods Construct particles
    void ConstructBosons();
    void ConstructLeptons();
    void ConstructBaryons();
 

  protected:
  // these methods Construct physics processes and register them
    void ConstructGeneral();
    void ConstructEM();

  private:

  G4LowEnergyIonisation*  LeIoprocess;
  G4LowEnergyPhotoElectric* LePeprocess;
  G4LowEnergyBremsstrahlung* LeBrprocess;

};

#endif







