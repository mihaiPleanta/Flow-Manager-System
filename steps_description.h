#ifndef STEP_DESCRIPTION_H
#define STEP_DESCRIPTION_H

#include <iostream>
#include <limits>


using namespace std;

// StepDescription class
class StepDescription {  
public:
    void stepsName(int step_count);  // Method to set the name of the step based on the step count
    void stepsDescription();  // Method to set the description of the step
};

#endif