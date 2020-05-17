/************************************************************
 * Name: Jason Yeoh
 * Description: Travel Network
 ************************************************************/

#include "airport.h"

// AIRPORT CLASS METHODS
// Airport Method 1: Constructor for Airport()
Airport::Airport() {
    flightList = NULL;
    isVisited = false;
}

// Airport Method 2: addAirport()
//  - Adds a flight into the airport
void Airport::addAirport(int val, bool visited) {
    // Checks if given value is out of range.
    if(val < 0 || val > 10) {
        printf("ERROR: Out of range\n");
        return;
    }
    
    if(flightList == NULL) {
        MyList* airportList = new MyList();
        airportList->insertValue(val);
        flightList = airportList;
        isVisited = visited;
    }
    
    else {
        flightList->insertValue(val);
        isVisited = visited;
    }
}

// Airport Method 3: addAirport()
//  - Removes a flight from the airport
void Airport::removeAirport(int val) {
    // Checks if given value is out of range.
    if(val < 0 || val > 10) {
        printf("ERROR: Out of range\n");
        return;
    }
    
    if(flightList->checkIfNodeExists(val) != true) {
        printf("ERROR: Airport # does not exists. \n");
        return;
    }
    else {
        flightList->deleteValue(val);
    }
}


// Airport Method 4: removeAllFlights()
//  - Removes all flights from the airport
void Airport::removeAllFlights() {
    if(flightList == NULL)
        return;
    
    MyList* airportList = flightList;
    
    airportList->deleteAllValues();
    delete airportList;
    flightList = airportList;
}


// Airport Method 5: printAirportList()
//  - Prints the airport's flight list
void Airport::printAirportList() {
    if(flightList == NULL)
        return;
    
    flightList->printValues();
    
    printf("\n\t>>There are %d flights on this airport.",
           flightList->getNumberOfCurrentValues());
}


// Airport Method 6: checkIfLinkExists()
//  - Returns true if link exists, otherwise it returns false
bool Airport::checkIfLinkExists(int val) {
    if(flightList == NULL)
        return false;
    
    return flightList->checkIfNodeExists(val);
}


// Airport Method 7: markUnvisited()
//  - Marks all nodes unvisited
void Airport::markUnvisited() {
    if(flightList == NULL)
        return;
    
    isVisited = false;
    
    MyNode* temp = flightList->accessHead();
    
    while(temp != NULL) {
        temp->setIsVisited(false);
        temp = temp->getNext();
    }
}

// Airport Method 8: getTop()
//  - Access the head element of the flight list
MyNode* Airport::getTop() {
    if(flightList == NULL)
        return NULL;
    
    return flightList->accessHead();
}

// Airport Method 9: getFlightList()
//  - Returns flight list
MyList* Airport::getFlightList() {
    return flightList;
}
