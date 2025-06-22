#include "TicketManager.hpp"
#include <iostream>
using namespace std;

TicketManager::TicketManager(string eventName) {
    this->eventName = eventName;
    this->vipCapacity = 5;
    this->regularCapacity = 10;
    this->ticketCount = 0;
    this->currentVIPTickets = 0;
    this->currentRegularTickets = 0;
    for (int i = 0; i < VENUE_CAPACITY; i++) {
        tickets[i] = nullptr;
    }
}

TicketManager::TicketManager(string eventName, int vipCapacity, int regularCapacity) {
    this->eventName = eventName;
    this->vipCapacity = vipCapacity;
    this->regularCapacity = regularCapacity;
    this->ticketCount = 0;
    this->currentVIPTickets = 0;
    this->currentRegularTickets = 0;

    for (int i = 0; i < VENUE_CAPACITY; i++) {
        tickets[i] = nullptr;
    }
}

TicketManager::~TicketManager() {
    for (int i = 0; i < VENUE_CAPACITY; i++) {
        if (tickets[i] != nullptr) {
            delete tickets[i];
            tickets[i] = nullptr;
        }
    }

}

string TicketManager::getEventName() const {
    return eventName;
}

void TicketManager::buyTicket(const string &ownerName, bool isVIP) {
    if (ticketCount >= VENUE_CAPACITY) {
        cout << "Error: All tickets are sold out!" << endl;
        return;
    }

    if (isVIP) {
        if (currentVIPTickets >= vipCapacity) {
            cout << "Error: No VIP tickets left!" << endl;
        } else {
            string ticketID = "V" + to_string(++currentVIPTickets);
            tickets[ticketCount++] = new VIPTicket(ticketID, ownerName);
            cout << "Success: " << ownerName << " bought a VIP ticket! Ticket ID: " << ticketID << endl;
        }
    } else {
        if (currentRegularTickets >= regularCapacity) {
            cout << "Error: No Regular tickets left!" << endl;
        } else {
            string ticketID = "R" + to_string(++currentRegularTickets);
            tickets[ticketCount++] = new RegularTicket(ticketID, ownerName);
            cout << "Success: " << ownerName << " bought a Regular ticket! Ticket ID: " << ticketID << endl;
        }
    }
}

void TicketManager::checkTicket(const string &ticketID) const {
    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i] != nullptr && tickets[i]->getTicketID() == ticketID) {
            tickets[i]->printTicket();
            return;
        }
    }
    cout << "Ticket ID is invalid!" << endl;
}

void TicketManager::listAudience() const {
    if (ticketCount == 0) {
        cout << "No audience yet!" << endl;
        return;
    }

    int nomor = 1;
    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i] != nullptr) {
            cout << nomor++ << ". ";
            tickets[i]->printTicket(); 
        }
    }

}

int TicketManager::calculateRevenue() const {
    int totalRevenue = (currentVIPTickets * 500) + (currentRegularTickets * 275);
    return totalRevenue;
}