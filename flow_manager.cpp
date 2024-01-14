#include "flow_manager.h"

int errorCount = 0;

// Define the constructor
FlowManager::FlowManager() {

    //Choose an option
    int option;
    do {
        cout << "Please select an option:\n1. Create a new flow\n2. Load an existing flow\n3. Delete an existing flow\n4. Exit\nYour choice: ";
        cin >> option;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            errorCount++;
            continue;
        }
        try {
            if (option == 1) {
                //If the option is 1, create a new flow
                createFlow();
            } else if (option == 2) {
                //If the option is 2, run the flow
                displayFlow();
            } else if (option == 3) {
                //If the option is 3, delete the flow
                deleteFlow();
            } else if (option == 4) {
                //If the option is 4, exit the program
                cout << "Exiting..." << endl;
                break;
            } else {
                throw invalid_argument("Error: Invalid option!");
            }
        } catch (const invalid_argument& e) {
            cerr << e.what() << endl;
        }
    } while (true);

    // Print the error count
    cout << "Error count: " << errorCount << endl;

    // Print the flow counts
    printFlowCounts();
}

// Define the createFlow method
void FlowManager::createFlow() {
    string name;
    cout << "Enter the name of the new flow: ";
    cin >> name;
    flow.setName(name);
    CreateFlow createFlow(flow);
    incrementFlowStartCount(flow.getName());
}

// Define the displayFlow method    
void FlowManager::displayFlow() {
    flow.displayFlow();
    incrementFlowRunCount(flow.getName());
}

// Define the deleteFlow method
void FlowManager::deleteFlow() {
    flow.deleteFlow();
    flowStartCounts.erase(flow.getName());
}


void FlowManager::incrementFlowStartCount(const string& flowName) {
    flowStartCounts[flowName]++;
}

void FlowManager::incrementFlowRunCount(const string& flowName) {
    flowRunCounts[flowName]++;
}

// Define the printFlowCounts method(here are printed the number of times a flow was started and run)
void FlowManager::printFlowCounts() const {
    for (const auto& pair : flowStartCounts) {
        cout << "Flow " << pair.first << " started " << pair.second << " times" << endl;
    }
    for (const auto& pair : flowRunCounts) {
        cout << "Flow " << pair.first << " run " << pair.second << " times" << endl;
    }
}

// Define the destructor
FlowManager::~FlowManager() {
    cout << "FlowManager destructor called" << endl;
}