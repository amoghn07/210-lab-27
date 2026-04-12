#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

void inc_friend(map<string, tuple<int, string, string>>&);
void dec_friend(map<string, tuple<int, string, string>>&);
void village_search(map<string, tuple<int, string, string>>);
void output(map<string, tuple<int, string, string>>);

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagers;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagers["Audie"] = {8, "frog", "bang!"};
    villagers["Raymond"] = {9, "human", "dude!"};
    villagers.insert({"Marshal", {4, "horse", "neigh!"}});

    int ans = 0;
    while (ans != 4){
        cout << "1. Increase Friendship\n";
        cout << "2. Decrease Friendship\n";
        cout << "3. Search for Villager\n";
        cout << "4. Exit\n";
        cin >> ans;
        if (ans == 1) inc_friend(villagers);
        else if (ans == 2) dec_friend(villagers);
        else if (ans == 3) village_search(villagers);
    }


    return 0;
}

void inc_friend(map<string, tuple<int, string, string>>& m){
    //using tuple member function, get, and increasing value by one
    string n;
    cout << "Enter village name: ";
    cin >> n;
    get<0>(m[n])++;
    output(m);
}
void dec_friend(map<string, tuple<int, string, string>>& m){
    //using tuple member function, get, and decreasing value by one
    string n;
    cout << "Enter village name: ";
    cin >> n;
    get<0>(m[n])--;
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
    
    cout << '[' << score << " " << race << " " << phrase << ']'<< endl;
    }
}