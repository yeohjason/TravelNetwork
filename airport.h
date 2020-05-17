/************************************************************
 * Name: Jason Yeoh
 * Description: Travel Network
 ************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>

// Node class
class MyNode{
    private:
        int value;
        bool isVisited;
        MyNode *next;
        
    public:
        MyNode(int val);
        MyNode* getNext();
        int getValue();
        bool getIsVisited();
        void setNext(MyNode *newNext);
        void setValue(int newVal);
        void setIsVisited(bool newIsVisited);
};


// List class
class MyList{
    private:
        MyNode *head;
        MyNode *tail;
        int size;
        
    public:
        MyList();
        void insertValue(int val);
        void deleteValue(int val);
        void deleteAllValues();
        int getNumberOfCurrentValues();
        int getNthValue(int n);
        void printValues();
        bool checkIfNodeExists(int val);
        bool seeIfVisited(int n);
        void changeIsVisited(int n, bool newIsVisited);
        MyNode* accessHead();
};


// Airport class
class Airport{
    private:
        MyList* flightList;
        bool isVisited;
        
    public:
        Airport();
        void addAirport(int val, bool visited);
        void removeAirport(int val);
        void removeAllFlights();
        void printAirportList();
        bool checkIfLinkExists(int val);
        void markUnvisited();
        void setEmptyFlightList();
        MyList* getFlightList();
        MyNode* getTop();
};


// Filename Node Class
class MyNodeFilename {
    private:
        char* file;
        MyNodeFilename* next;
        
    public:
        MyNodeFilename(char* filename);
        MyNodeFilename* getNext();
        char* getString();
        void setNext(MyNodeFilename* newNext);
};


// Filename Class
class Filename {
    private:
        MyNodeFilename* filenameHead;
        MyNodeFilename* filenameTail;
        
    public:
        Filename();
        void insertAtFront(char* filename);
        void deleteAtBack(char* filename);
        bool exists(char* filename);
};
