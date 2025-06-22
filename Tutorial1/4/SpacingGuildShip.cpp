#include <iostream>
#include "SpacingGuildShip.hpp"
using namespace std;

float SpacingGuildShip::totalGuildTravel = 0;
int SpacingGuildShip::producedShips = 0;

// default ctor
SpacingGuildShip::SpacingGuildShip() : maxPassengerCap(50), guildNavigatorCount(3), serialNum(++producedShips){
    this->passengerCount = 0;
    this->operatingGuildNavigator = guildNavigatorCount;
    this->spiceStock = 50;
}
// user-defined ctor
SpacingGuildShip::SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock) : maxPassengerCap(maxPassengerCap), guildNavigatorCount(guildNavigatorCount), serialNum(++producedShips) {
    this->passengerCount = 0;
    this->operatingGuildNavigator = guildNavigatorCount;
    this->spiceStock = spiceStock;
}
// cctor
SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip& s) : maxPassengerCap(s.maxPassengerCap), guildNavigatorCount(s.guildNavigatorCount), serialNum(++producedShips) {
    this->passengerCount = s.passengerCount;
    this->operatingGuildNavigator = s.operatingGuildNavigator;
    this->spiceStock = s.spiceStock;
}
// dtor
SpacingGuildShip::~SpacingGuildShip(){}

// getter
int SpacingGuildShip::getShipSerialNum() const{
    // cout << this->serialNum << endl;
    return this->serialNum;
}
int SpacingGuildShip::getPassengerCount() const{
    // cout << this->passengerCount << endl;
    return this->passengerCount;
}

// method lainnya
void SpacingGuildShip::travel(float distance) {
    if (this->operatingGuildNavigator > 0) {
        totalGuildTravel += (distance / (E * E * operatingGuildNavigator));
        this->operatingGuildNavigator -= 1;
    }
    // cout << this->operatingGuildNavigator << endl;
    // cout << totalGuildTravel << endl;
}
void SpacingGuildShip::boarding(int addedPassengers) {
    if (addedPassengers <= (this->maxPassengerCap - this->passengerCount)) {
        this->passengerCount += addedPassengers;
    } else {
        this->passengerCount = this->maxPassengerCap;
    }
    // cout << this->passengerCount << endl;
}
void SpacingGuildShip::dropOff(int droppedPassengers) {
    if (droppedPassengers <= this->passengerCount) {
        this->passengerCount -= droppedPassengers;
    } else {
        this->passengerCount = 0;
    }
    // cout << this->passengerCount << endl;
}
void SpacingGuildShip::refreshNavigator(int n) {
    int refreshed = n;
    if (refreshed > (this->guildNavigatorCount - this->operatingGuildNavigator)) {
        refreshed = this->guildNavigatorCount - this->operatingGuildNavigator;
    }
    this->operatingGuildNavigator += refreshed;
    this->spiceStock -= refreshed * GUILD_NAVIGATOR_SPICE_DOSE;
    // cout << this->operatingGuildNavigator << endl;
    // cout << this->spiceStock << endl;
}
void SpacingGuildShip::transitToArrakis(int addedSpice) {
    this->spiceStock += addedSpice;
    // cout << this->spiceStock << endl;
}