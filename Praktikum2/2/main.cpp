#include "Creature.hpp"
#include "Dragon.hpp"

int main() {
    Dragon d1("Draco");
    d1.speak();
    d1.wound();
    d1.wound();
    d1.print();
    d1.speak();
    
    Creature c1 = d1;
    Creature* c2 = &d1;

    c1.wound();
    c1.print();
    c2->wound();
    d1.print();

    c1.speak();
    c1.wound();
    c1.print();
    d1.print();

    return 0;
}

// A creature has been born!
// A dragon has been born!
// I am the mighty dragon Draco! Beware of my flames!
// Base Health: 100; Additional Health: 80
// I am the mighty dragon Draco! Beware of my flames!



// Base Health: 90
// Base Health: 90; Additional Health: 80



// I am a mystical creature named Draco!
// Base Health: 80
// Base Health: 90; Additional Health: 80