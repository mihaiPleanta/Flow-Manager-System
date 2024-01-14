#ifndef FLOW_MANAGER_H
#define FLOW_MANAGER_H

#include "flow.h"
#include "create_flow.h"

#include <iostream>
#include <fstream>

using namespace std;

// Define the FlowManager class
class FlowManager {
public:
    FlowManager();  // Constructor declaration
    ~FlowManager();  // Destructor declaration
    void createFlow();  // Method to create a flow
    void displayFlow();  // Method to display a flow
    void deleteFlow();  // Method to delete a flow
    void incrementFlowStartCount(const string& flowName);  // Method to increment the start count of a flow
    void printFlowCounts() const;  // Method to print the counts of a flow
    void incrementFlowRunCount(const string& flowName);  // Method to increment the run count of a flow
    
protected:
    Flow flow;  // Flow object
    map<string, int> flowStartCounts;  // Map to keep track of the start counts of each flow
    map<string, int> flowRunCounts;  // Map to keep track of the run counts of each flow
};

#endif