#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerColors;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerColors["Audie"] = {10, "Yellow", "Red"};
    villagerColors["Raymond"] = {48, "Gray", "White"};
    villagerColors.insert({"Marshal", {5, "White", "Black"}});


    int choice;

    do {
        displayMenu()
        cin >> choice;

        switch(chouce) {
            case 1:
                displayAllVillagers(villagerColors);
                break;
            case 2:
                increaseFriendshipLevel(villagerColors);
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

















    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagerColors) {
        cout << pair.first << ": ";
        cout << "Level " << get<0>(pair.second) 
             << ", species: " << get<1>(pair.second)
             << ", Color: " << get<2>(pair.second) << endl;

    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    cout << "\nVillagers and their data (iterators):" << endl;
for (map<string, tuple<int, string, string>>::iterator it = villagerColors.begin(); 
                                                        it != villagerColors.end(); ++it) {
    cout << it->first << ": ";
    cout << "Level " << get<0>(it->second) 
         << ", Species: " << get<1>(it->second)
         << ", Catchphrase: " << get<2>(it->second) << endl;
        cout << endl;
    }

    // // delete an element
    // villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s data: ";

        cout << "Level " << get<0>(it->second) 
             << ", Species: " << get<1>(it->second)
             << ", Catchphrase: \"" << get<2>(it->second) << "\"";

        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}

void displayMenu() {
    cout << "\n=== Villager Friendship Menu ===" << endl;
    cout << "1. Increase Friendship" << endl;
    cout << "2. Decrease Friendship" << endl;
    cout << "3. Search for Villager" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

void increaseFriendshipLevel(map<string, tuple<int, string, string>> villagerColors) {
    string villagerName;
    cout << "Enter the name of the villager to increase friendship level: ";
    cin >> villagerName;

    auto name = villagerColors.find(villagerName);
    if (name != villagerColors.end()) {

        int level = get<0>(name->second);
        level += 1; 

        cout << villagerName << "'s new friendship level is: " << level << endl;
    } else {
        cout << villagerName << " not found." << endl;
    }

}