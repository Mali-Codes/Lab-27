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

void increaseFriendshipLevel(map<string, tuple<int, string, string>>& villagerColors) {
    string villagerName;
    cout << "Enter the name of the villager to increase friendship level: ";
    cin >> villagerName;

    auto name = villagerColors.find(villagerName);
    if (name != villagerColors.end()) {
        
        // tutor helped with this part - I didnt know to "reupdate" the tuple in the map
        int level;
        string species;
        string catchphrase;
        tie(level, species, catchphrase) = name->second; 

        level++;

         villagerColors[villagerName] = make_tuple(level, species, catchphrase);

        cout << villagerName << "'s new friendship level is: " << level << endl;
    } else {
        cout << villagerName << " not found." << endl;
    }

}


void decreaseFriendshipLevel(map<string, tuple<int, string, string>>& villagerColors) { // still using the increase
    string villagerName;
    cout << "Enter the name of the villager to increase friendship level: ";
    cin >> villagerName;

    auto name = villagerColors.find(villagerName);
    if (name != villagerColors.end()) {
        
        // tutor helped with this part - I didnt know to "reupdate" the tuple in the map
        int level;
        string species;
        string catchphrase;
        tie(level, species, catchphrase) = name->second; 

        level--;

         villagerColors[villagerName] = make_tuple(level, species, catchphrase);

        cout << villagerName << "'s new friendship level is: " << level << endl;
    } else {
        cout << villagerName << " not found." << endl;
    }

}


void searchVilager(map<string, tuple<int, string, string>>& villagerColors) {
    string villagerName;
    cout << "Enter the name of the villager to find: ";
    cin >> villagerName;

    auto name = villagerColors.find(villagerName);
    if (name != villagerColors.end()) {
        cout << villagerName << " found!" << endl;
    }
}


void displayVillagers(const map<string, tuple<int, string, string>>& villagerColors) { //from first part of lab
    cout << "===Viallagers===" << endl;
    for (const auto& pair : villagerColors) {
        const string& name = pair.first;
        int friendshipLevel = get<0>(pair.second);
        cout << "Villager: " << name << ", Friendship Level: " << friendshipLevel << endl;
    }
}





int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerColors;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerColors["Audie"] = {10, "Yellow", "Wowzers"};
    villagerColors["Raymond"] = {48, "Gray", "Dodgers in 7"};
    villagerColors.insert({"Marshal", {5, "White", "Brrr"}});


    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch(choice) {
            
            case 1:
                increaseFriendshipLevel(villagerColors);
                break;
            case 2:
                decreaseFriendshipLevel(villagerColors);
                break;

            case 3:
                searchVilager(villagerColors);
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 4);

    displayVillagers(villagerColors);
return 0;


}


void addVillager(map<string, tuple<int, string, string>>& villagerColors, const string& name, int friendshipLevel, const string& primaryColor, const string& secondaryColor) {
    string name;
    string species;
    int friendshipLevel;

    cout << "Villager name: ";
    cin >> name;
    
    cout << "Friendship level: ";
    cin >> friendshipLevel;
    
    cout << "Species: ";
    cin >> species;


}