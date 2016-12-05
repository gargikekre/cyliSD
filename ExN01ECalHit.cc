
#include "ExN01EcalHit.hh"
#include "G4VVisManager.hh"
#include "G4Circle.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"


G4Allocator<ExN01EcalHit> ExN01EcalHitAllocator;

ExN01EcalHit::ExN01EcalHit()
{;}

ExN01EcalHit::~ExN01EcalHit()
{;}

ExN01EcalHit::ExN01EcalHit(const ExN01EcalHit &right)
  : G4VHit()
{
  edep = right.edep;
  pos = right.pos;
  toff = right.toff;
  HitId = right.HitId;
}

const ExN01EcalHit& ExN01EcalHit::operator=(const ExN01EcalHit &right)
{
  edep = right.edep;
  pos = right.pos;
  toff = right.toff;
  HitId = right.HitId;

  return *this;
}

G4int ExN01EcalHit::operator==(const ExN01EcalHit &right) const
{
  return (this==&right) ? 1 : 0;
}

void ExN01EcalHit::Draw()
{
  G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();
  if(pVVisManager)
  {
    G4Circle circle(pos);
    circle.SetScreenSize(0.04);
    circle.SetFillStyle(G4Circle::filled);
    G4Colour colour(1.,0.,0.);
    G4VisAttributes attribs(colour);
    circle.SetVisAttributes(attribs);
    pVVisManager->Draw(circle);
  }
}

void ExN01EcalHit::Print()
{;}


