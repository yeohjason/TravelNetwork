/************************************************************
 * Name: Jason Yeoh
 * Description: Travel Network
 ************************************************************/

#include "airport.h"

// Filename Node Class Methods
MyNodeFilename::MyNodeFilename(char* filename) {
    file = filename;
    /*
    new char[30];
    
    int i;
    for(i=0; filename[i] != '\0'; ++i) {
        file[i] = filename[i];
    }
    file[i] = '\0';*/
    
    next = NULL;
}

MyNodeFilename* MyNodeFilename::getNext() {
    return next;
}

void MyNodeFilename::setNext(MyNodeFilename* newNext) {
    next = newNext;
}

char* MyNodeFilename::getString() {
    return file;
}

// Filename Class Methods
Filename::Filename() {
    filenameHead = NULL;
    filenameTail = NULL;
}

void Filename::insertAtFront(char* filename) {
    MyNodeFilename* temp = new MyNodeFilename(filename);
    MyNodeFilename* temp2 = filenameHead;
    
    if(filenameHead == NULL) {
        filenameHead = temp;
    }
    else {
        while(temp2->getNext() != NULL)
            temp2 = temp2->getNext();
        
        temp2->setNext(temp);
    }
    
    filenameTail = temp;
}

void Filename::deleteAtBack(char* filename) {
    if(filenameHead == NULL) {
        printf("ERROR: Empty list.\n");
        return;
    }
    
    MyNodeFilename* temp = filenameHead;
    
    if(strcmp(filenameHead->getString(), filename) == 0) {
        filenameHead = temp->getNext();
        delete temp;
        return;
    }
    
    if(strcmp(filenameTail->getString(), filename) == 0) {
        while(temp->getNext() != NULL) {
            filenameTail = temp;
            temp = temp->getNext();
        }
        
        delete temp;
        return;
    }
    
    while(temp->getNext() != NULL) {
        if(strcmp(temp->getNext()->getString(), filename) == 0) {
            MyNodeFilename* pRemove = temp->getNext();
            
            if(temp->getNext()->getNext() != NULL)
                temp->setNext(temp->getNext()->getNext());
            else
                temp->setNext(NULL);
            
            delete pRemove;
            return;
        }
        
        temp = temp->getNext();
    }
}

bool Filename::exists(char* filename) {
    if(filenameHead == NULL)
        return false;
    
    MyNodeFilename* temp = filenameHead;
    
    while(temp != NULL) {
        if(strcmp(temp->getString(), filename) == 0)
            return true;
        
        temp = temp->getNext();
    }
    
    return false;
}
