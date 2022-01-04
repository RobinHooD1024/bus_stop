#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    map <int, vector<string>> buses;
    map <int, int> order;
    static int i = 1;
    int k;
    cin >> k;

    while (k > 0) {
        string command, stop;
        int bus_number, number_of_stops;
        cin >> command;
        if (command == "NEW_BUS") {
            cin >> bus_number >> number_of_stops;
            for (int i = 0; i < number_of_stops; i++) {
                cin >> stop;
                buses[bus_number].push_back(stop);
            }
            order[bus_number] = i++;

        } else if (command == "BUSES_FOR_STOP") {
            cin >> stop;
            string string1;
            vector <int> buses_for_stop;
            map <int, int> result;
            for (auto b : buses) {
                for (auto stops : b.second) {
                    if (stop == stops) {
                        buses_for_stop.push_back(b.first);
                    }
                }
            }
            if (buses_for_stop.empty()) {
                cout << "No stop" << endl;
            } else {
                for (auto bus : buses_for_stop) {
                    result[order[bus]] = bus;
                }
                for (auto bus : result) {
                    string1 += bus.second + " ";
                }
                cout << string1;
            }

        } else if (command == "STOPS_FOR_BUS") {
            cin >> bus_number;
            string string1;
            if (buses[bus_number].empty()) {
                cout << "No buses" << endl;
            } else {
                for (auto stop : buses[bus_number]) {
                    string1 += stop + " ";
                }
                cout << string1;

            }




        } else if (command == "ALL_BUSES") {
//            for (auto bus : buses) {
//                string string1;
//                for (auto stops : buses[bus])
//            }

        }
        k--;
    }
    return 0;
}
