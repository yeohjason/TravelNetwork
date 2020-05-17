/************************************************************
 * CS 211 PROJECT 6 (Fall 2017)
 *
 * Name: Jason Yeoh
 * NetID: jyeoh2
 * Course: CS211 (Programming Practicum)
 * Description: Travel Network
 ************************************************************/

#include "airport.h"

// NODE CLASS METHODS
// Node Method 1: Constructor
MyNode::MyNode(int val) {
    value = val;
    isVisited = false;
    next = NULL;
}

// Node Method 2: getNext()
MyNode* MyNode::getNext() {
    return next;
}

// Node Method 3: getValue()
int MyNode::getValue() {
    return value;
}

// Node Method 4: getIsVisited()
bool MyNode::getIsVisited() {
    return isVisited;
}

// Node Method 5: setNext()
void MyNode::setNext(MyNode *newNext) {
    next = newNext;
}

// Node Method 6: setValue()
void MyNode::setValue(int newVal) {
    value = newVal;
}

// Node Method 7: setIsVisited()
void MyNode::setIsVisited(bool newIsVisited) {
    isVisited = newIsVisited;
}

// SINGLY-LINKED LIST CLASS METHODS
// SLL Method 1: Constructor
MyList::MyList() {
    head = NULL;
    tail = NULL;
    size = 0;
}

// SLL Method 1: insertValue()
//  - Inserts a node at the back of the list
void MyList::insertValue(int val) {
    if(val < 0 || val > 10) {
        printf("ERROR: Out of range\n");
        return;
    }
    
    MyNode* temp = new MyNode(val);
    MyNode* temp2 = head;
    
    if(head == NULL)
        head = temp;
    
    else {
        while(temp2->getNext() != NULL)
            temp2 = temp2->getNext();
        
        temp2->setNext(temp);
    }
    
    tail = temp;
    size++;
}

// SLL Method 3: deleteValue()
//  - Deletes a node with the user-specified value
void MyList::deleteValue(int val) {
    if(head == NULL) {
        printf("ERROR: Empty list.\n");
        return;
    }
    
    MyNode* temp = head;
    
    // Value is at the front of the list
    if(head->getValue() == val) {
        head = temp->getNext();
        delete temp;
        size--;
        return;
    }
    
    // Value is at the back of the list
    if(tail->getValue() == val) {
        while(temp->getNext() != NULL) {
            tail = temp;
            temp = temp->getNext();
        }
        
        delete temp;
        size--;
        return;
    }

    // Value is at the middle of the list
    while(temp->getNext() != NULL) {
        if(temp->getNext()->getValue() == val) {
            MyNode* pRemove = temp->getNext();
            
            if(temp->getNext()->getNext() != NULL)
                temp->setNext(temp->getNext()->getNext());
            else
                temp->setNext(NULL);
            
            delete pRemove;
            size--;
            return;             // return if found
        }
        
        temp = temp->getNext();
    }
}


// SLL Method 4: deleteAllValues()
//  - Removes all nodes in the list
void MyList::deleteAllValues() {
    MyNode* temp = head;
    MyNode* temp2;
    
    while(temp != NULL) {
        temp2 = temp->getNext();
        delete temp2;
        temp = temp2;
    }
    
    head = NULL;
}

// SLL Method 5: getNumberOfCurrentValues()
//  - Returns the current count of values in the list
int MyList::getNumberOfCurrentValues() {
    MyNode* temp = head;
    int numberOfCurrentValues = 0;
    
    while(temp != NULL) {
        numberOfCurrentValues++;
        temp = temp->getNext();
    }
    
    return numberOfCurrentValues;
}

// SLL Method 6: getNthValue
//  - Returns the nth value in the list
int MyList::getNthValue(int n) {
    if(n > size) {
        printf("ERROR: n is out of range.\n");
        return -1;
    }
    
    MyNode* temp = head;
    
    while(n > 0 && temp != NULL) {
        temp = temp->getNext();
        n--;
    }
    
    if(temp == NULL) return -1;
    
    return temp->getValue();
}

// SLL Method 7: printValues()
//  - Prints the current values in the list
void MyList::printValues() {
    MyNode* temp = head;
    
    while(temp != NULL) {
        printf("%d -> ", temp->getValue());
        temp = temp->getNext();
    }
    
    printf("NULL");
}

// SLL Method 8: checkIfNodeExists()
//  - Returns true if the node exists, otherwise it returns false
bool MyList::checkIfNodeExists(int val) {
    MyNode* temp = head;
    
    if(head == NULL)
        return false;
    
    while(temp != NULL) {
        if(temp->getValue() == val)
            return true;
        
        temp = temp->getNext();
    }
    
    return false;
}

// SLL Method 9: seeIfVisited()
//  - Checks if the node has already been visited
bool MyList::seeIfVisited(int n) {
    MyNode* temp = head;
    
    while(n > 0) {
        if(temp == NULL)
            return false;
        
        temp = temp->getNext();
        n--;
    }
    
    if(temp == NULL) return false;
    
    return temp->getIsVisited();
}

// SLL Method 10: changeIsVisited()
//  - Change n's isVisited status
void MyList::changeIsVisited(int n, bool newIsVisited) {
    MyNode* temp = head;
    
    while(n > 0) {
        if(temp == NULL)
            return;
        
        temp = temp->getNext();
        n--;
    }
    
    if(temp == NULL) return;

    temp->setIsVisited(newIsVisited);
}

// SLL Method 11: accessHead()
//  - Returns the head of the list
MyNode* MyList::accessHead() {
    return head;
}
