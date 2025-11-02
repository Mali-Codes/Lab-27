#include <iostream>
#include <map>
#include <vector>
using namespace std;


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


void decreaseFriendshipLevel(map<string, tuple<int, string, string>> villagerColors) { //using the increse block
    string villagerName;
    cout << "Enter the name of the villager to decrease friendship level: ";
    cin >> villagerName;

    auto name = villagerColors.find(villagerName);
    if (name != villagerColors.end()) {

        int level = get<0>(name->second);
        level -= 1; 

        cout << villagerName << "'s new friendship level is: " << level << endl;
    } else {
        cout << villagerName << " not found." << endl;
    }

}




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
        displayMenu();
        cin >> choice;

        switch(choice) {
            // case 1:
            //     displayAllVillagers(villagerColors);
            //     break;
            case 1:
                increaseFriendshipLevel(villagerColors);
                break;
            case 2:
                decreaseFriendshipLevel(villagerColors);
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 4);


return 0;
}


void searchVilager(map<string, tuple<int, string, string>> villagerColors) {
    string villagerName;
    cout << "Enter the name of the villager to find: ";
    cin >> villagerName;

    name = auto villagerColors.find(villagerName);
    if (name != villagerColors.end()) {
        cout << villagerName << " found!" << endl;
    }
}