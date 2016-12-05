#include "ExN01DetectorConstruction.hh"

#include "G4Material.hh"
#include "G4Element.hh"
#include "G4MaterialTable.hh"
#include "G4ElementTable.hh"

#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Polyhedra.hh"
#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4PVPlacement.hh"
#include "G4RotationMatrix.hh"

#include "ExN01EcalSD.hh"
#include "G4SDManager.hh"

#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"

#include "G4VisAttributes.hh"
#include "G4Colour.hh"

//#include "globals.hh"
#include "G4ios.hh"

ExN01DetectorConstruction::ExN01DetectorConstruction()
 :  experimentalHall_log(0), 
    experimentalHall_phys(0), tracker_log(0), tracker_phys(0)
{;}

ExN01DetectorConstruction::~ExN01DetectorConstruction()
{
}

G4VPhysicalVolume* ExN01DetectorConstruction::Construct()
{

  // Clean old geometry, if any
  G4PhysicalVolumeStore::GetInstance()->Clean();
  G4LogicalVolumeStore::GetInstance()->Clean();
  G4SolidStore::GetInstance()->Clean();

//  ConstructMaterials();
  //------------------------------------------------------ materials

  G4double a;  // atomic mass
  G4double z;  // atomic number
  G4double density;
  G4int ncomponents,natoms;
  G4int nel;
  G4double fractionmass;

// examples of vacuum

  G4Material* Vacuum =
  new G4Material("Galactic", z=1., a=1.01*g/mole,density= universe_mean_density,                           kStateGas, 3.e-18*pascal, 2.73*kelvin);

  G4Element* N  = new G4Element("Nitrogen" ,"N" , z= 7., a=  14.01*g/mole);
  G4Element* O  = new G4Element("Oxygen"   ,"O" , z= 8., a=  16.00*g/mole);

  G4Material* Air = 
  new G4Material("Air", density= 1.290*mg/cm3, ncomponents=2);
  Air->AddElement(N, fractionmass=70.*perCent);
  Air->AddElement(O, fractionmass=30.*perCent);


// ------GGAG--------------GGAG------------GGAG---------
/*
  G4Element* elGd= new G4Element("Gadolinium", "Gd", z=64., a=157.25*g/mole);
  G4Element* elGa= new G4Element("Gallium",    "Ga", z=31., a=69.723*g/mole);
  G4Element* elAl = new G4Element("Aluminium", "Al", z=13., a=26.981539*g/mole);
  G4Element* elO= new G4Element("Oxygen",      "O",  z=8.,  a=15.9994*g/mole);
  
  G4Material* GGAG = new G4Material("GGAG", density=6.7*g/cm3,  nel=4);
  GGAG->AddElement(elGd, 51*perCent);
  GGAG->AddElement(elGa, 23*perCent);
  GGAG->AddElement(elAl, 6*perCent);
  GGAG->AddElement(elO, 23*perCent);
*/

//------NE213--------------NE213------------NE213--------BC501
/*  G4Element* elHydrogen= new G4Element("Hydrogen", "H", z=1., a=1.00794*g/mole); 
  G4Element* elCarbon= new G4Element("Carbon", "C", z=6., a=12.0107*g/mole);
  
  G4Material* NE213 = new G4Material("NE213", density=0.874*g/cm3,  nel=2);//ncomp or nel
  NE213->AddElement(elHydrogen,9.2*perCent);
  NE213->AddElement(elCarbon,90.8*perCent);
*/
/*
// ------NaI--------------NaI------------NaI---------

  G4Element* elI = new G4Element("Iodine", "I", z=53., a=126.90*g/mole);
  G4Element* elNa= new G4Element("Sodium", "Na", z=11., a=22.9898*g/mole);

  G4Material* NaI = new G4Material("NaI", density=3.67*g/cm3,  nel=2);
  NaI->AddElement(elI, 85*perCent);
  NaI->AddElement(elNa, 15*perCent);
*/

/*
// ------LaBr3--------------LaBr3---------LaBr3---------

 G4Element* elLa = new G4Element("Lanthanum","La",z=57.,a=138.9057*g/mole);
 G4Element* elBr= new G4Element("Bromine", "Br", z=35., a=79.904*g/mole);

 G4Material* LaBr3 = new G4Material("LaBr3",density=5.08*g/cm3,nel=2);
 LaBr3->AddElement(elLa, 37*perCent);
 LaBr3->AddElement(elBr, 63*perCent);
*/

// ------BaF2--------------BaF2---------BaF2---------
/*
 G4Element* elBa = new G4Element("Barium","Ba",z=56.,a=137.327*g/mole);
 G4Element* elF= new G4Element("Flourine", "F", z=9., a=18.998*g/mole);

 G4Material* BaF2 = new G4Material("BaF2",density=4.88*g/cm3,nel=2);
 BaF2->AddElement(elBa, 78.4*perCent);
 BaF2->AddElement(elF, 21.6*perCent);
*/
// ------LaCl3--------------LaCl3---------LaCl3---------
/*
 G4Element* elLa = new G4Element("Lanthanum","La",z=57.,a=138.9057*g/mole);
 G4Element* elCl= new G4Element("Chlorine", "Cl", z=17., a=35.453*g/mole);

 G4Material* LaCl3 = new G4Material("LaCl3",density=3.85*g/cm3,nel=2);
 LaCl3->AddElement(elLa, 57*perCent);
 LaCl3->AddElement(elCl, 43*perCent);

*/
// ------CsI--------------CsI---------CsI---------
/*
 G4Element* elCs = new G4Element("Cesium","Cs",z=55.,a=132.905*g/mole);
 G4Element* elI= new G4Element("Iodine", "I", z=53., a=126.904*g/mole);

 G4Material* CsI = new G4Material("CsI",density=4.534*g/cm3,nel=2);
 CsI->AddElement(elCs, 51*perCent);
 CsI->AddElement(elI, 49*perCent);
 CsI->GetIonisation()->SetMeanExcitationEnergy(553.1*eV);
*/
// ------BGO-------------BGO---------BGO---------
/*
 G4Element* elBi = new G4Element("Bismuth","Bi",z=83.,a=208.98*g/mole);
 G4Element* elGe= new G4Element("Germanium","Ge",z=32., a=72.64*g/mole);
 G4Element* elO = new G4Element("Oxygen","O",z=8.,a=16.*g/mole);

  G4Material* BGO = 
  new G4Material("BGO", density= 7.13*g/cm3, nel=3);
  BGO->AddElement(elO , 15.4*perCent);
  BGO->AddElement(elGe,17.5*perCent);
  BGO->AddElement(elBi, 67.1*perCent);


// ------HPGe-------------HPGe--------HPGe---------

  G4Material* HPGe = 
  new G4Material("HPGe", density= 5.323*g/cm3, nel=1);

  HPGe->AddElement(elGe, 100.*perCent);
*/

  //G4Material* Al = 
  //new G4Material("Aluminum", z= 13., a= 26.98*g/mole, density= 2.7*g/cm3);
  
  a=16.*g/mole;
  G4Element* elO=new G4Element("Oxygen","O2",z=8.,a);

  a=22.99*g/mole;
  G4Element* elNa=new G4Element("Sodium","Na",z=11.,a);

  a=26.98*g/mole;
  G4Element* elAl=new G4Element("Aluminium","Al",z=13.,a);

  a=28.085*g/mole;
  G4Element* elSi=new G4Element("Silicon","Si",z=14.,a);

  a=40.08*g/mole;
  G4Element* elCa=new G4Element("Calcium","Ca",z=20.,a);

  a=55.850*g/mole;
  G4Element* elFe=new G4Element("Iron","Fe",z=26.,a);

  density = 2.5*g/cm3;
  G4Material* ShieldingConcrete = new G4Material("ShieldingConcrete",density,nel=6);
  ShieldingConcrete->AddElement(elO, fractionmass = 0.52);
  ShieldingConcrete->AddElement(elSi, fractionmass = 0.325);
  ShieldingConcrete->AddElement(elCa, fractionmass = 0.06);
  ShieldingConcrete->AddElement(elNa, fractionmass = 0.015);
  ShieldingConcrete->AddElement(elFe, fractionmass = 0.04);
  ShieldingConcrete->AddElement(elAl, fractionmass = 0.04);

//    G4Material* Au = 
//    new G4Material("Gold", z= 79., a= 196.96*g/mole, density= 19.32*g/cm3);

  G4Material* Pb = 
  new G4Material("Lead", z= 82., a= 207.2*g/mole, density= 11.35*g/cm3);

//  G4Material* Cu = 
//  new G4Material("Copper", z= 29., a= 63.54*g/mole, density= 8.96*g/cm3);

  //------------------------------------------------------ volumes
  //------------------------------ experimental hall (world volume)

  G4double expHall_x = 10.0*m;
  G4double expHall_y = 10.0*m;
  G4double expHall_z = 10.0*m;
  G4Box* experimentalHall_box
    = new G4Box("expHall_box",expHall_x,expHall_y,expHall_z);
  experimentalHall_log = new G4LogicalVolume(experimentalHall_box,
                                             ShieldingConcrete,"expHall_log",0,0,0);
  experimentalHall_phys = new G4PVPlacement(0,G4ThreeVector(),
                                      experimentalHall_log,"expHall",0,false,0);


  //------------------------------ a tracker tube

    G4double innerRadiuscr = 0.*mm;

//  G4double outerRadiuscr = 12.7*mm; // 1 inch dia
//  G4double outerRadiuscr = 19.*mm; // 1.5 inch dia
  G4double outerRadiuscr = 25.4*mm; // 2 inch dia
//  G4double outerRadiuscr = 38.1*mm; // 3 inch dia
//  G4double outerRadiuscr = 44.45*mm; // 3.5 inch dia
//  G4double outerRadiuscr = 50.8*mm; // 4 inch dia
//  G4double outerRadiuscr = 63.5*mm; // 5 inch dia
//  G4double outerRadiuscr = 76.2*mm; // 6 inch dia
//  G4double outerRadiuscr = 88.9*mm; // 7 inch dia
//  G4double outerRadiuscr = 101.6*mm; // 8 inch dia
//  G4double outerRadiuscr = 127*mm; // 10 inch dia
 //G4double outerRadiuscr = 100000*mm; // 20 inch dia

//  G4double heightcr = 12.7*mm; //Arbitrary length
//    G4double heightcr = 12.7*mm; //1 inch length
//  G4double heightcr = 19.*mm; //1.5 inch length
  G4double heightcr = 25.4*mm; //2 inch length
//  G4double heightcr = 38.1*mm; //3 inch length
//  G4double heightcr = 50.8*mm; //4 inch length
//  G4double heightcr = 63.5*mm; //5 inch length
//  G4double heightcr = 76.2*mm; //6 inch length
//  G4double heightcr = 88.9*mm; //7 inch length
//  G4double heightcr = 101.6*mm; // 8 inci dia
//  G4double heightcr = 152.4*mm; //12 inch length
  //G4double heightcr = 100000*mm; // 20 inch dia


/*
//----Maximum

  G4double outerRadiuscr = 12.95*mm; // 1 inch dia
  G4double heightcr = 12.95*mm; //1 inch length
*/
/*
//----Minimum

  G4double outerRadiuscr = 12.45*mm; // 1 inch dia
  G4double heightcr = 12.45*mm; // inch length
*/

  G4double startAngle = 0.*deg;
  G4double spanningAngle = 360.*deg;

  G4Tubs* tracker_tube = new G4Tubs("tracker_tube",innerRadiuscr,
                                    outerRadiuscr,heightcr,
                                    startAngle,spanningAngle);
//  tracker_log = new G4LogicalVolume(tracker_tube,LaBr3,"tracker_log",0,0,0);
   tracker_log = new G4LogicalVolume(tracker_tube,Pb,"tracker_log",0,0,0);

  tracker_phys = new G4PVPlacement(0,
                                   G4ThreeVector(0,0,0),
                  tracker_log,"tracker",experimentalHall_log,false,0);

/*
 //------------------------------ lead collimator
  G4double innerRadiuspb = 6.*mm;
  G4double outerRadiuspb = 44.45*mm; // 3.5 inch dia
  G4double heightpb = 65.2*mm; //6 inch length

  G4Tubs* solidEcalpb = new G4Tubs("Ecalspb",innerRadiuspb,
                                    outerRadiuspb,heightpb,
                                    startAngle,spanningAngle);

  logicEcalpb = new G4LogicalVolume(solidEcalpb,  Pb,
                                        "Ecallogpb"); //name

  physiEcalpb = new G4PVPlacement(0,
                                   G4ThreeVector(0,0,220 *mm),
                          logicEcalpb,"ecalpb",experimentalHall_log,false,0);

*/
 //------------------------------ a tracker tube
//--------------------------------6" cylinder with Al housing
/*
  G4double innerRadiusAl = (outerRadiuscr+5.0)*mm;
  G4double outerRadiusAl = (innerRadiusAl+0.4)*mm;
  G4double heightAl = (heightcr+5.0)*mm;
*/
//------------------------------------------

  G4double innerRadiusAl = (outerRadiuscr+2.0)*mm;
  G4double outerRadiusAl = (innerRadiusAl+0.5)*mm;
  G4double heightAl = (heightcr+3.0)*mm; 


  G4Tubs* solidEcal = new G4Tubs("Ecals",innerRadiusAl,
                                    outerRadiusAl,heightAl,
                                    startAngle,spanningAngle);

  logicEcal = new G4LogicalVolume(solidEcal,  Pb, "Ecallog"); //name

  physiEcal = new G4PVPlacement(0,
                                   G4ThreeVector(0,0,0 *mm),
                          logicEcal,"ecalphy",experimentalHall_log,false,0);

  G4double innerRadiusAl1 = 0.*mm;
  G4double heightAl1 = 50.*mm; 

  G4Tubs* solidEcal1 = new G4Tubs("Ecals1",innerRadiusAl1,
                                    outerRadiusAl,heightAl1,
                                    startAngle,spanningAngle);

  logicEcal1 = new G4LogicalVolume(solidEcal1,  Pb,
                                        "Ecallog"); //name

  physiEcal1 = new G4PVPlacement(0,
                                   G4ThreeVector(0,0,(heightAl)*mm),
                          logicEcal1,"ecalphy1",experimentalHall_log,false,0);

//------------------------------ a Pb scatterer
/*
 G4double innerRadiusAu = 0.*mm;
 G4double outerRadiusAu = 12.7*mm;
 G4double heightAu = 0.0005*mm; // for 1 micro-mm thickness

  G4Tubs* solidEcal3 = new G4Tubs("Ecals3",innerRadiusAu,
                                    outerRadiusAu,heightAu,
                                    startAngle,spanningAngle);

  logicEcal3 = new G4LogicalVolume(solidEcal3,  Au,
                                        "Ecallog3"); //name

//  physiEcal3 = new G4PVPlacement(0,
//                                   G4ThreeVector(0,0,(heightAl+10.0)*mm),
//                          logicEcal3,"ecalphy3",experimentalHall_log,false,0);

   physiEcal3 = new G4PVPlacement(0,
                                   G4ThreeVector(0,0,(heightcr+1.25)*mm), // for foil placed at 2.5mm from detector
                          logicEcal3,"ecalphy3",experimentalHall_log,false,0);

*/
//-----------------------------------define of a carbon material

  G4Material* C =
       new G4Material("Carbon",z=6.,a= 12.01*g/mole, density= 2.267*g/cm3);

  G4double platex1 = 200.0*mm;
  G4double platey1 = 30.*mm;
//  G4double platey1 = 500.*mm;
  G4double platez1 = 200.0*mm;

  G4Box* solidAlplate
    = new G4Box("solidAlplate",platex1,platey1,platez1);
  logicAlplate = new G4LogicalVolume(solidAlplate,
                        C, "logicAlplate",0,0,0);

/*
  physiAlplate = new G4PVPlacement(0,G4ThreeVector(0,-95.*mm,200.*mm),
                                      logicAlplate,"chamber",experimentalHall_log,false,0);
*/

/*
  physiEcal2 = new G4PVPlacement(0,
                                   G4ThreeVector(0,0,-(heightAl+1.0)*mm),
                          logicEcal1,"ecalphy",experimentalHall_log,false,0);
*/

  G4SDManager* SDman = G4SDManager::GetSDMpointer();
  G4String  ecalName = "cyliSDEcal";
  ExN01EcalSD * ecalSD = new ExN01EcalSD(ecalName);
  SDman->AddNewDetector(ecalSD);
            
  tracker_log->SetSensitiveDetector(ecalSD); //define sensitive detector

  // Visualization attributes

  experimentalHall_log->SetVisAttributes (G4VisAttributes(true));


  G4VisAttributes* simpleHexVisAtt= new G4VisAttributes(true, G4Colour(1.0,1.5,0.5));
  simpleHexVisAtt->SetVisibility(true);
  logicEcal->SetVisAttributes(simpleHexVisAtt);
  logicEcal1->SetVisAttributes(simpleHexVisAtt);
//   logicEcal3->SetVisAttributes(simpleHexVisAtt);
//  logicEcalpb->SetVisAttributes(simpleHexVisAtt);

//  logicAlplate->SetVisAttributes(simpleHexVisAtt);
//  logicEcal2->SetVisAttributes(simpleHexVisAtt);
	
//    logicEcal->SetVisAttributes(G4VisAttributes::Invisible);

  G4VisAttributes* simpleHexVisAtt2= new G4VisAttributes(true, G4Colour(1.0,0.5,1.0));
  //  simpleHexVisAtt2->SetVisibility(true);
  tracker_log->SetVisAttributes(simpleHexVisAtt2);
//  G4VisAttributes* simpleHexVisAtt3= new G4VisAttributes(true, G4Colour(1.0,0.5,0.5));
//  simpleHexVisAtt3->SetVisibility(true);
//  logicEcal3->SetVisAttributes(simpleHexVisAtt);

  return experimentalHall_phys;
}
