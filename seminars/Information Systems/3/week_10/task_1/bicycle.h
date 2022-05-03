#include "vehicle.h"

class Bycicle : public Vehicle {
private:
    bool hasLights;
    bool hasRing;
    int speeds;

    void copy(const Bycicle&);
public:
    Bycicle();
    Bycicle(const char*, const char*, int, int, double, bool, bool, int);
    Bycicle(const Bycicle& other);
    Bycicle& operator=(const Bycicle& other);

    void print() const;
};