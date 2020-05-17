/************************************************************
 * Name: Jason Yeoh
 * Description: Travel Network
 ************************************************************/

#include "airport.h"

class TravelNetwork
{
private:
    // Create the Data Members for the Travel Network here
    Airport* airportArray;
    Filename* file;
    int size;
    int inUse;
    
public:
    // Use a constructor to initialize the Data Members for Travel Network
    TravelNetwork()
    {
        //airportArray = NULL;
        //file = NULL;
        
        size = 10;
        inUse = 1;
        
        airportArray = new Airport[size + 1];
        
        //airportArray[0].
        
        for(int i = 0; i <= size; i++)
            airportArray[i] = *new Airport();
        
        file = new Filename;
    }
    
    
    // The main loop for reading in input
    void processCommandLoop (FILE* inFile)
    {
        char  buffer[300];
        char* input;
        
        input = fgets ( buffer, 300, inFile );   // get a line of input
        
        // loop until all lines are read from the input
        while (input != NULL)
        {
            // process each line of input using the strtok functions
            char* command;
            command = strtok (input , " \n\t\r");
            
            printf ("*%s*\n", command);
            
            if ( command == NULL )
                printf ("Blank Line\n");
            
            else if ( strcmp (command, "q") == 0)
                exit(1);
            
            else if ( strcmp (command, "?") == 0)
                showCommands();
            
            else if ( strcmp (command, "t") == 0)
                doTravel();
            
            else if ( strcmp (command, "r") == 0)
                doResize();
            
            else if ( strcmp (command, "i") == 0)
                doInsert();
            
            else if ( strcmp (command, "d") == 0)
                doDelete();
            
            else if ( strcmp (command, "l") == 0)
                doList();
            
            else if ( strcmp (command, "f") == 0)
                doFile();
            
            else if ( strcmp (command, "#") == 0)
                ;
            
            else
                printf ("Command is not known: %s\n", command);
            
            input = fgets ( buffer, 300, inFile );   // get the next line of input
            
        }
    }
    
    void showCommands()
    {
        printf ("The commands for this project are:\n");
        printf ("  q \n");
        printf ("  ? \n");
        printf ("  # \n");
        printf ("  t <int1> <int2> \n");
        printf ("  r <int> \n");
        printf ("  i <int1> <int2> \n");
        printf ("  d <int1> <int2> \n");
        printf ("  l \n");
        printf ("  f <filename> \n");
    }
    
    void doTravel()
    {
        int val1 = 0;
        int val2 = 0;
        
        // get an integer value from the input
        char* next = strtok (NULL, " \n\t\r");
        if ( next == NULL )
        {
            printf ("Integer value expected\n");
            return;
        }
        val1 = atoi ( next );
        if ( val1 == 0 && strcmp (next, "0") != 0)
        {
            printf ("Integer value expected\n");
            return;
        }
        
        // get another integer value from the input
        next = strtok (NULL, " \n\t\r");
        if ( next == NULL )
        {
            printf ("Integer value expected\n");
            return;
        }
        val2 = atoi ( next );
        if ( val2 == 0 && strcmp (next, "0") != 0)
        {
            printf ("Integer value expected\n");
            return;
        }
        
        printf ("Performing the Travel Command from %d to %d\n",
                val1, val2);
        
        depthFirstSearchHelper(val1, val2);
    }
    
    void doResize()
    {
        int val1 = 0;
        
        // get an integer value from the input
        char* next = strtok (NULL, " \n\t\r");
        if ( next == NULL )
        {
            printf ("Integer value expected\n");
            return;
        }
        val1 = atoi ( next );
        if ( val1 == 0 && strcmp (next, "0") != 0)
        {
            printf ("Integer value expected\n");
            return;
        }
        
        // check if val1 is in the valid range
        if(val1 < 1) {
            printf("ERROR: Airport %d is outside of the valid range.\n", val1);
            return;
        }
        
        for(int i = 0; i <= size; i++) {
            airportArray[i].removeAllFlights();
        }
        
        delete [] airportArray;
        
        Airport* newAirportArray = new Airport[size + 1];
        for(int i = 0; i <= val1; i++)
            airportArray[i] = *new Airport();
        
        airportArray = newAirportArray;
        size = val1;
        
        printf("Performing the Resize Command with %d\n", val1);
    }
    
    void doInsert()
    {
        int val1 = 0;
        int val2 = 0;
        
        // get an integer value from the input
        char* next = strtok(NULL, " \n\t\r");
        if(next == NULL) {
            printf ("Integer value expected\n");
            return;
        }
        val1 = atoi(next);
        if(val1 == 0 && strcmp (next, "0") != 0) {
            printf ("Integer value expected\n");
            return;
        }
        
        // get another integer value from the input
        next = strtok (NULL, " \n\t\r");
        if(next == NULL) {
            printf ("Integer value expected\n");
            return;
        }
        val2 = atoi(next);
        if(val2 == 0 && strcmp (next, "0") != 0) {
            printf ("Integer value expected\n");
            return;
        }
        
        // check if val1 is in the valid range
        if(val1 < 1 || val1 > size) {
            printf("ERROR: Airport %d is outside of the valid range.\n", val1);
            return;
        }
        
        // check if val2 is in the valid range
        if(val2 < 1 || val2 > size) {
            printf("ERROR: Airport %d is outside of the valid range.\n", val2);
            return;
        }
        
        // check if val2 already exists in the travel network
        if(airportArray[val1].checkIfLinkExists(val2) == true) {
            printf("ERROR: The flight from airport %d to airport %d already exists.\n",
                   val1, val2);
            return;
        }
        
        airportArray[val1].addAirport(val2, false);
    }
    
    void doDelete()
    {
        int val1 = 0;
        int val2 = 0;
        
        // get an integer value from the input
        char* next = strtok(NULL, " \n\t\r");
        if(next == NULL) {
            printf ("Integer value expected\n");
            return;
        }
        val1 = atoi(next);
        if(val1 == 0 && strcmp (next, "0") != 0) {
            printf ("Integer value expected\n");
            return;
        }
        
        // get another integer value from the input
        next = strtok (NULL, " \n\t\r");
        if(next == NULL) {
            printf ("Integer value expected\n");
            return;
        }
        val2 = atoi(next);
        if(val2 == 0 && strcmp (next, "0") != 0) {
            printf ("Integer value expected\n");
            return;
        }
        
        // check if val1 is in the valid range
        if(val1 < 1 || val1 > size) {
            printf("ERROR: Airport %d is outside of the valid range.\n", val1);
            return;
        }
        
        // check if val2 is in the valid range
        if(val2 < 1 || val2 > size) {
            printf("ERROR: Airport %d is outside of the valid range.\n", val2);
            return;
        }
        
        // check if val2 does not exists in the travel network
        if(airportArray[val1].checkIfLinkExists(val2) != true) {
            printf("ERROR: The flight from airport %d to airport %d does not exist.\n",
                   val1 - 1, val2);
            return;
        }
        
        airportArray[val1].removeAirport(val2);
    }
    
    void doList()
    {
        printf("\n");
        printf("=====================================\n");
        printf("LIST OF FLIGHTS AT DIFFERENT AIRPORTS\n");
        printf("=====================================\n");
        printf("\n");
        
        for(int i=1; i<=size; i++) {
            printf("@Airport %2d: ", i);
            airportArray[i].printAirportList();
            printf("\n");
        }
    }
    
    void doFile()
    {
        // get a filename from the input
        char* fname = strtok (NULL, " \n\t\r");
        if (fname == NULL)
        {
            printf ("Filename expected\n");
            return;
        }
        
        printf ("Performing the File command with file: %s\n", fname);
        
        // next steps:  (if any step fails: print an error message and return ) 
        //  1. verify the file name is not currently in use
        //  2. open the file using fopen creating a new instance of FILE*
        //  3. recursively call processCommandLoop() with this new instance of FILE* as the parameter
        //  4. close the file when processCommandLoop() returns
        
        if(file->exists(fname) != false) {
            printf("Error: File name already is currently in use.\n");
            return;
        }
        
        FILE* pFile;
        pFile = fopen(fname, "r");
        file->insertAtFront(fname);     // Push the filename
        
        if(pFile != NULL) {
            processCommandLoop(pFile);      // Recursively call processCommandLoop
            if(!feof(pFile)) {
                file->deleteAtBack(fname);      // Pop the filename
                fclose(pFile);
            }
        }
        
    }
    
    void depthFirstSearchHelper(int x, int y)
    {
        for(int i=0; i<size; i++) {
            airportArray[i].markUnvisited();
        }
        
        if(dfs(x, y) == true)
            printf("You can get from airport %d to airport %d in one or more flights.\n", x, y);
        else
            printf("You can NOT get from airport %d to airport %d in one or more flights.\n", x, y);
    }
    
    bool dfs(int a, int b)
    {
        MyNode* c = airportArray[a].getTop();
        
        if(c == NULL)
            return false;
        
        while(c != NULL) {
            if(c->getValue() == b)
                return true;
            
            if(c->getIsVisited() != true) {
                c->setIsVisited(true);
                
                // DEBUG
                //printf("***************Traversed A%d and A%d\n", c->getValue(), b);
                
                if(dfs(c->getValue(), b) == true)
                    return true;
            }
            
            c = c->getNext();
        }
        
        return false;
    }
    
    void freeTravelNetwork() {
        for(int i = 0; i <= size; i++) {
            airportArray[i].removeAllFlights();
        }
        
        delete [] airportArray;
        
        delete file;
    }
};

int main (int argc, char** argv)
{
    // set up the variable inFile to read from standard input
    FILE* inFile = stdin;
    
    // set up the data needed for the airport adjcency list
    TravelNetwork airportData;
    
    // call the method that reads and parses the input
    airportData.processCommandLoop (inFile);
    
    airportData.freeTravelNetwork();
    
    printf ("Goodbye\n");
    return 1;
}
