#include <iostream>
#include <fstream>
#include "Stronghold.h"  // Your header with all class declarations

using namespace std;

// Saves all the game data to a file, kinda like a save point
void saveGameState(const Population& pop, const Army& army, const Economy& eco, 
                  const ResourceManager& res, const Bank& bank) {
    ofstream saveFile("game_state.txt");
    if (saveFile.is_open()) {
        // Save population data
        saveFile << pop.getTotal() << ";" << pop.getPeasantCount() << ";" 
                << pop.getMerchantCount() << ";" << pop.getNobleCount() << ";"
                << pop.getHappiness() << ";" << pop.getFoodReserves() << ";";
        
        // Save army data
        saveFile << army.getSoldierCount() << ";" << army.getMorale() << ";"
                << army.getRations() << ";";
        
        // Save economy data
        saveFile << eco.getTreasury() << ";" << eco.getTaxRate() << ";"
                << eco.getInflation() << ";";
        
        // Save resource data
        saveFile << res.getFoodStock() << ";" << res.getTimberStock() << ";"
                << res.getStoneStock() << ";" << res.getMetalStock() << ";";
        
        // Save bank data
        saveFile << bank.getActiveLoans() << ";" << bank.getDetectedFraud() << ";";
        
        saveFile.close();
        cout << "\nGame saved successfully.\n";
    } else {
        cout << "\nError: Could not save game.\n";
    }
}

// Loads the game from a save file, basically the opposite of saveGameState
void loadGameState(Population& pop, Army& army, Economy& eco, 
                  ResourceManager& res, Bank& bank) {
    ifstream loadFile("game_state.txt");
    if (loadFile.is_open()) {
        string line;
        getline(loadFile, line);
        
        // Parse the line using semicolon as delimiter
        size_t pos = 0;
        string token;
        int values[18]; // Increased array size to accommodate all values
        int index = 0;
        
        while ((pos = line.find(';')) != string::npos) {
            token = line.substr(0, pos);
            values[index++] = stoi(token);
            line.erase(0, pos + 1);
        }
        
        // Restore population
        pop.setTotal(values[0]);
        pop.setPeasantCount(values[1]);
        pop.setMerchantCount(values[2]);
        pop.setNobleCount(values[3]);
        pop.setHappiness(values[4]);
        pop.setFoodReserves(values[5]);
        
        // Restore army
        army.setSoldierCount(values[6]);
        army.setMorale(values[7]);
        army.setRations(values[8]);
        
        // Restore economy
        eco.setTreasury(values[9]);
        eco.setTaxRate(values[10]);
        eco.setInflation(values[11]);
        
        // Restore resources
        res.setFoodStock(values[12]);
        res.setTimberStock(values[13]);
        res.setStoneStock(values[14]);
        res.setMetalStock(values[15]);
        
        // Restore bank
        bank.setActiveLoans(values[16]);
        bank.setDetectedFraud(values[17]);
        
        loadFile.close();
        cout << "\nGame loaded successfully.\n";
    } else {
        cout << "\nError: Could not load game.\n";
    }
}

int main() {
    ResourceManager realmResources;
    Economy realmEconomy;
    Population realmCitizens;
    Army realmForces;
    Leader* realmRuler = new King();
    EventManager realmEvents;
    Bank realmTreasury;
    Kingdom playerKingdom;

    cout << "\n==================================================\n";
    cout << "                    KINGDOM CREATION               \n";
    cout << "==================================================\n";
    cout << "Enter your kingdom's name: ";
    string kingdomName;
    getline(cin, kingdomName);
    playerKingdom.setName(kingdomName);
    cout << "Welcome to the Kingdom of " << playerKingdom.getName() << "!\n";
    cout << "==================================================\n\n";

    int userSelection;
    bool gameActive = true;

    while (gameActive) {
        cout << "\n==================================================\n";
        cout << "                    " << playerKingdom.getName() << "                      \n";
        cout << "==================================================\n";
        cout << "1. Show Stats                                     \n";
        cout << "2. Manage People                                  \n";
        cout << "3. Manage Army                                    \n";
        cout << "4. Manage Money                                   \n";
        cout << "5. Get Resources                                  \n";
        cout << "6. Random Events                                  \n";
        cout << "7. Save Game                                      \n";
        cout << "8. Load Game                                      \n";
        cout << "9. Exit Game                                      \n";
        cout << "==================================================\n";
        cout << "Enter your choice: ";
        cin >> userSelection;

        if (cin.fail() || userSelection < 1 || userSelection > 9) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid choice! Please select between 1 and 9.\n";
            continue;
        }

        // Handle the player's choice
        switch (userSelection) {
            case 1:
                cout << "\nCurrent Stats:\n";
                realmCitizens.showStats();
                realmForces.showStats();
                realmEconomy.showStats();
                realmResources.showStats();
                realmTreasury.showStats();
                break;

            case 2:
                cout << "\nManaging People:\n";
                realmCitizens.simulate();
                break;

            case 3:
                cout << "\nManaging Army:\n";
                realmForces.recruitAndTrain(realmCitizens);
                break;

            case 4:
                cout << "\nManaging Money:\n";
                cout << "==================================================\n";
                cout << "1. Collect Taxes                                  \n";
                cout << "2. Get a Loan                                     \n";
                cout << "3. Repay Loan                                     \n";
                cout << "4. Audit Treasury                                 \n";
                cout << "==================================================\n";
                cout << "Choose an option: ";
                int moneyChoice;
                cin >> moneyChoice;
                
                switch (moneyChoice) {
                    case 1:
                        realmEconomy.taxPopulation(realmCitizens);
                        break;
                    case 2:
                        cout << "Enter loan amount: ";
                        int loanAmount;
                        cin >> loanAmount;
                        realmTreasury.issueLoan(realmEconomy, loanAmount);
                        break;
                    case 3:
                        cout << "Enter repayment amount: ";
                        int repayAmount;
                        cin >> repayAmount;
                        realmTreasury.repayLoan(realmEconomy, repayAmount);
                        break;
                    case 4:
                        realmTreasury.auditTreasury(realmEconomy);
                        break;
                    default:
                        cout << "Invalid choice!\n";
                }
                break;

            case 5:
                cout << "\nGetting Resources:\n";
                cout << "==================================================\n";
                cout << "1. Get Food\n";
                cout << "2. Get Wood\n";
                cout << "3. Get Stone\n";
                cout << "4. Get Steel\n";
                cout << "==================================================\n";
                cout << "Choose resource to get: ";
                int resourceChoice;
                cin >> resourceChoice;
                if (resourceChoice >= 1 && resourceChoice <= 4) {
                    realmResources.manage();
                } else {
                    cout << "\nInvalid choice!\n";
                }
                break;

            case 6:
                cout << "\nRandom Events:\n";
                realmEvents.trigger(realmCitizens, realmForces, realmEconomy, realmResources);
                break;

            case 7:
                cout << "\nSaving Game:\n";
                saveGameState(realmCitizens, realmForces, realmEconomy, realmResources, realmTreasury);
                break;

            case 8:
                cout << "\nLoading Game:\n";
                loadGameState(realmCitizens, realmForces, realmEconomy, realmResources, realmTreasury);
                break;

            case 9:
                gameActive = false;
                break;
        }
    }

    delete realmRuler;
    cout << "\nGame ended. Thanks for playing!\n";
    return 0;
}
