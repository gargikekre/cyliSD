#ifndef ExN01PrimaryGeneratorAction_h
#define ExN01PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"

//class G4ParticleGun;
class ExN01DetectorConstruction;
class G4GeneralParticleSource;
class G4Event;

class ExN01PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    ExN01PrimaryGeneratorAction();
    ~ExN01PrimaryGeneratorAction();

  public:
    void GeneratePrimaries(G4Event* anEvent);

  private:
    G4GeneralParticleSource* particleGun;
//    ExN01DetectorConstruction*  ExN01Detector;
//    G4ParticleGun* particleGun;
};

#endif


