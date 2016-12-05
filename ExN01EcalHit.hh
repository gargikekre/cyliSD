//

#ifndef ExN01EcalHit_h
#define ExN01EcalHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"

class ExN01EcalHit : public G4VHit
{
  public:

      ExN01EcalHit();
      ~ExN01EcalHit();
      ExN01EcalHit(const ExN01EcalHit &right);
      const ExN01EcalHit& operator=(const ExN01EcalHit &right);
      G4int operator==(const ExN01EcalHit &right) const;

      inline void *operator new(size_t);
      inline void operator delete(void *aHit);

      void Draw();
      void Print();

  private:
      G4double edep;
      G4ThreeVector pos;
      G4double toff;
      G4int    HitId;
  public:
      inline void SetEdep(G4double de)
      { edep = de; }
      inline void AddEdep(G4double de) 
      { edep +=de; }
      inline G4double GetEdep()
      { return edep; }
      inline void SetPos(G4ThreeVector xyz)
      { pos = xyz; }
      inline G4ThreeVector GetPos()
      { return pos; }
      inline void SetTime(G4double tf)
      { toff = tf; }
      inline G4double GetTime()
      { return toff; }
      inline void SetHitId (G4int id)
      { HitId = id; }
      inline G4int GetHitId()
      { return HitId; }
};

typedef G4THitsCollection<ExN01EcalHit> ExN01EcalHitsCollection;

extern G4Allocator<ExN01EcalHit> ExN01EcalHitAllocator;

inline void* ExN01EcalHit::operator new(size_t)
{
  void *aHit;
  aHit = (void *) ExN01EcalHitAllocator.MallocSingle();
  return aHit;
}

inline void ExN01EcalHit::operator delete(void *aHit)
{
  ExN01EcalHitAllocator.FreeSingle((ExN01EcalHit*) aHit);
}

#endif
