#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerColors;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerColors["Audie"] = {8, "frog", "bang!"};
    villagerColors["Raymond"] = {9, "human", "dude!"};
    villagerColors.insert({"Marshal", {4, "horse", "neigh!"}});

    // access the map using a range-based for loop
    cout << "Villagers and their info (range-based for loop):" << endl;
   for (auto pair : villagerColors) {
    cout << pair.first << ": ";
    //unpacking tuple like this, because different data types
    auto [score, race, phrase] = pair.second; 
    
    cout << score << " " << race << " " << phrase << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagerColors.begin(); 
                                               it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        auto[score, race, phrase] = it->second;
        cout << score << " " << race << " " << phrase << endl;
    }

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey;
        cout << " info:\n";
        auto[score, race, phrase] = it->second;
        cout << score << " " << race << " " << phrase << endl;

    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}