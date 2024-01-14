#ifndef FLOW_H
#define FLOW_H

#include "steps.h"
#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <map>

using namespace std;

// Flow class
class Flow {  
protected:
    string name;  // Variable to store the name of the flow
    vector<vector<Step*>> flows;  // Vector of vectors to store the flows in the matrix
    vector<string> timestamps;  // Vector to store the timestamps
    map<string, int> flowStartCounts;  // Map to store the start counts of the flows

public:
    Flow();  // Constructor
    void displayFlow();  // Method to display the flow
    void addSteps(const vector<Step*>& steps);  // Method to add steps to the flow
    const vector<vector<Step*>>& getFlows() const;  // Getter for the flows variable
    void addTimestamp();  // Method to add a timestamp
    const vector<string>& getTimestamps() const;  // Getter for the timestamps variable
    void deleteFlow();  // Method to delete the flow
    void setName(const string& name) { this->name = name; }  // Setter for the name variable
    string getName() const { return name; }  // Getter for the name variable
};

#endif