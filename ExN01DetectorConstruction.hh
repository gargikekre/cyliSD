
#ifndef ExN01DetectorConstruction_H
#define ExN01DetectorConstruction_H 1

class G4Box;
class G4Polyhedra;
class G4Tubs;

class G4LogicalVolume;
class G4VPhysicalVolume;

#include "G4VUserDetectorConstruction.hh"

class ExN01DetectorConstruction : public G4VUserDetectorConstruction
{
  public:

    ExN01DetectorConstruction();
    ~ExN01DetectorConstruction();

    G4VPhysicalVolume* Construct();

   const G4VPhysicalVolume* GetEcal()       {return tracker_phys;};

  private:
    

    //
    G4Box*       experimentalHall_box;
    G4LogicalVolume* experimentalHall_log;
    G4VPhysicalVolume* experimentalHall_phys;

    G4Tubs* tracker_tube;
    G4LogicalVolume* tracker_log;
    G4VPhysicalVolume* tracker_phys;

    G4Tubs* solidEcal;
    G4LogicalVolume* logicEcal;
    G4VPhysicalVolume* physiEcal;

    G4Tubs* solidEcal1;
    G4LogicalVolume* logicEcal1;
    G4VPhysicalVolume* physiEcal1;

    G4Tubs* solidEcal3;
    G4LogicalVolume* logicEcal3;
    G4VPhysicalVolume* physiEcal3;

    G4Tubs* solidEcalpb;
    G4LogicalVolume* logicEcalpb;
    G4VPhysicalVolume* physiEcalpb;

    G4Tubs* solidEcalcu;
    G4LogicalVolume* logicEcalcu;
    G4VPhysicalVolume* physiEcalcu;

    G4Tubs* solidEcalau;
    G4LogicalVolume* logicEcalau;
    G4VPhysicalVolume* physiEcalau;

    G4Box*       solidAlplate;
    G4LogicalVolume* logicAlplate;
    G4VPhysicalVolume* physiAlplate;

/*
    G4Tubs* solidEcal2;
    G4LogicalVolume* logicEcal2;
    G4VPhysicalVolume* physiEcal2;
*/

};

#endif

