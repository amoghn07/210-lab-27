#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

void inc_friend(map<string, tuple<int, string, string>>&);
void dec_friend(map<string, tuple<int, string, string>>&);
void village_search(map<string, tuple<int, string, string>>);
void output(map<string, tuple<int, string, string>>);
void add_vil(map<string, tuple<int, string, string>>&);
void del_vil(map<string, tuple<int, string, string>>&);


int main() {
    // declarations
    map<string, tuple<int, string, string>> villagers;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagers["Audie"] = {8, "frog", "bang!"};
    villagers["Raymond"] = {9, "human", "dude!"};
    villagers.insert({"Marshal", {4, "horse", "neigh!"}});

    int ans = 0;
    while (ans != 6){
        cout << "1. Add Villager\n";
        cout << "2. Delete Villager\n";
        cout << "3. Increase Friendship\n";
        cout << "4. Decrease Friendship\n";
        cout << "5. Search for Villager\n";
        cout << "6. Exit\n";
        cin >> ans;
        if (cin.fail() || ans > 6 || ans < 1) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a valid selection.\n";
        }
        else if (ans == 1) add_vil(villagers);
        else if (ans == 2) del_vil(villagers);
        else if (ans == 3) inc_friend(villagers);
        else if (ans == 4) dec_friend(villagers);
        else if (ans == 5) village_search(villagers);
        
    }


    return 0;
}

void inc_friend(map<string, tuple<int, string, string>>& m){
    //using tuple member function, get, and increasing value by one
    string n;
    cout << "Enter village name: ";
    cin >> n;
    auto it = m.find(n);
    if (it != m.end()) {  // the iterator points to beyond the end of the map if key not found
        get<0>(m[n])++;
    } else
        cout << endl << n << " not found." << endl;
    output(m);
}
void dec_friend(map<string, tuple<int, string, string>>& m){
    //using tuple member function, get, and decreasing value by one
    string n;
    cout << "Enter village name: ";
    cin >> n;
    auto it = m.find(n);
    if (it != m.end()) {  // the iterator points to beyond the end of the map if key not found
        get<0>(m[n])++;
    } else
        cout << endl << n << " not found." << endl;
    output(m);
}
void village_search(map<string, tuple<int, string, string>> m){
    string searchKey;
    cout << "Enter village name: ";
    cin >> searchKey;
    auto it = m.find(searchKey);
    if (it != m.end()) {  // the iterator points to beyond the end of the map if key not found
        cout << "\nFound " << searchKey;
        cout << " info:\n";
        auto[score, race, phrase] = it->second;
        cout << score << " " << race << " " << phrase << endl;

    } else
        cout << endl << searchKey << " not found." << endl;
    output(m);
}
void output(map<string, tuple<int, string, string>> m){
    cout << "Villager details: \n";
    for (auto pair : m) {
    cout << pair.first << " ";
    auto [score, race, phrase] = pair.second; 
    
    cout << '[' << score << ", " << race << ", " << phrase << ']'<< endl;
    }
}
void add_vil(map<string, tuple<int, string, string>>& m){
    string n, s, c;
    int lvl;
    cout << "Villager name: ";
    cin >> n;
    cout << "Friendship level: ";
    cin >> lvl;
    cout << "Species: ";
    cin >> s;
    cout << "Catchphrase: ";
    cin >> c;

    //adding to map
    m[n] = {lvl, s, c};
    cout << n << " added.\n";
    output(m);
}
void del_vil(map<string, tuple<int, string, string>>& m){
    string n;
    cout << "Enter village name: ";
    cin >> n;
    m.erase(n);
    output(m);
}