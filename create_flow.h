#ifndef CREATE_FLOW_H
#define CREATE_FLOW_H

#include "steps.h"
#include "flow.h"
#include "steps_description.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>

using namespace std;

// Define the CreateFlow class
class CreateFlow {
private:
    int step_id;  // Variable to store the ID of a step
    int step_count;  // Variable to store the count of steps
    Flow& flow;  // Reference to a Flow object
    
public:
    CreateFlow(Flow& flow);  // Constructor that takes a reference to a Flow object
};

#endif