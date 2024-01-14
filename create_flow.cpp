#include "create_flow.h"

CreateFlow::CreateFlow(Flow& flow) : flow(flow) {  // Constructor for the CreateFlow class
    vector<Step*> stepsVector;  // Vector to store the steps of the new flow
    StepDescription step_names;  // Create an instance of the StepDescription class to get infrmation about the steps
    step_count = 0;  // Initialize the step count

    ofstream outputFile("flows.csv",ios::app);  // Open the output file in append mode

    if (!outputFile.is_open()) {  // Check if the file is open
        cerr << "Nu am putut deschide fisierul pentru scriere!" << endl;  // Error message if the file is not open
        errorCount++;  // Increment the error count
        return;  // Return if the file is not open
    }

    cout << "Select your steps for the flow:" << endl;  // Prompt the user to select the steps

    do {
        bool ok = false;  // Variable to check if the step is valid
        step_count++;  // Increment the step count
        step_names.stepsName(step_count);  // Display the steps
        cout << "Your answer: ";  // Prompt the user for their answer
        cin >> step_id;  // Read the user's answer

        if (cin.fail()) {  // Check if the input is valid
            cin.clear();  // Clear the input stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore the rest of the line
            cout << "Invalid input. Please enter a number." << endl;  // Error message if the input is invalid
            errorCount++;  // Increment the error count
            continue;  // Continue with the next iteration of the loop
        }

        cin.ignore();  // Ignore the rest of the line

        switch (step_id) {  // Switch statement based on the step ID
            // Each case creates a new step, checks if the step is valid, writes the step ID to the output file, and adds the step to the vector
            // If the step is not valid, the step count is decremented and the error count is incremented
            case 0: {
                step_names.stepsDescription();
                break;
            }

            case 1: {
                TitleStep* titleStep = new TitleStep();
                if (titleStep->step(step_count) == true) {
                    outputFile << step_id << ",";
                    ok = true;
                    stepsVector.push_back(titleStep);
                }
                break;
            }
                
            case 2: {
                TextStep* textStep = new TextStep();
                if (textStep->step(step_count) == true) {
                    outputFile << step_id << ",";
                    ok = true;
                    stepsVector.push_back(textStep);
                }
                break;
            }
            
            case 3: {
                TextInputStep* textInputStep = new TextInputStep();
                if (textInputStep->step(step_count) == true) {
                    outputFile << step_id << ",";
                    ok = true;
                    stepsVector.push_back(textInputStep);
                }
                break;
            }
               
            case 4: {
                NumberInputStep* numberInputStep = new NumberInputStep();
                if (numberInputStep->step(step_count) == true) {
                    outputFile << step_id << ",";
                    ok = true;
                    stepsVector.push_back(numberInputStep);
                }
                break;
            }
                
            case 5: {
                CalculusStep* calculusStep = new CalculusStep();
                if (calculusStep->step(step_count) == true) {
                    outputFile << step_id << ",";
                    ok = true;
                    stepsVector.push_back(calculusStep);
                }
                break;
            }
                
            case 6: {
                DisplayStep* displayStep = new DisplayStep();
                if (displayStep->step(step_count) == true) {
                    outputFile << step_id << ",";
                    ok = true;
                    stepsVector.push_back(displayStep);
                }
                break;
            }
                
            case 7: {
                TextFileInputStep* textFileInputStep = new TextFileInputStep();
                if (textFileInputStep->step(step_count) == true) {
                    outputFile << step_id << ",";
                    ok = true;
                    stepsVector.push_back(textFileInputStep);
                }
                break;
            }
                
            case 8: {
                CsvFileInputStep* csvFileInputStep = new CsvFileInputStep();
                if (csvFileInputStep->step(step_count) == true) {
                    outputFile << step_id << ",";
                    ok = true;
                    stepsVector.push_back(csvFileInputStep);
                }
                break;
            }
                
            case 9: {
                OutputStep* outputStep = new OutputStep();
                if (outputStep->step(step_count) == true) {
                    outputFile << step_id << ",";
                    ok = true;
                    stepsVector.push_back(outputStep);
                }
                break;
            }
                
            case 10: {
                EndStep* endStep = new EndStep();
                if (endStep->step(step_count) == true) {
                    outputFile << step_id << ",";
                    ok = true;
                    stepsVector.push_back(endStep);
                }
                break;
            }
        }

        if(ok == false) {  // Check if the step is valid
            step_count--;  // Decrement the step count
            errorCount++;  // Increment the error count
        }
    } while (step_id != 10);  // Continue until the step ID is 10

    flow.addTimestamp();  // Add a timestamp to the flow

    flow.addSteps(stepsVector);  // Add the flow to the matrix

    outputFile << endl;  // Write a newline to the output file
}
