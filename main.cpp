#include "Car.h"
#include <deque>
#include <array>

using namespace std;

const int START_SIZE = 2;

int main() {
    array<deque<Car>, 4> carList;
    Car* temp;
    // add 2 Car objects to car line to start
    for(int i = 0; i < carList.size(); i++) {
        for (int e = 0; e < START_SIZE; e++) {
            temp = new Car();
            carList[i].push_back(*temp);
        }
        carList[i][0].print();
    }
    // simulation
    cout << "Initial Queue: " << endl;
    for(int e = 0; e < carList.size(); e++) {
        cout << "Lane " << e << ":" << endl;
        for (int i = 0; i < carList[e].size(); i++) {
            carList[e][i].print();
        }
    }
    for (int t = 1; t <= 20; t++) {
        // print time/iteration
        cout << "Time: " << t << endl;
        for(int g = 0; g < carList.size(); g++) {
            // check if car pays
            cout << "Lane: " << g+1;
            int rnd = (int)(rand() % 100);
            // if no cars exist in current lane, car must be added as neither of the other 2 operation can function
            if (carList[g].size() == 0 && rnd < 46) {
                rnd = 60;
            }
            if (rnd < 46) {
                if (carList[g].size() > 0) {
                    cout << " Car Paid: ";
                    carList[g][0].print();
                    cout << " ";
                    carList[g].pop_front();
                }
            }
            // check if car joins lane
            else if (rnd < (46+39)) {
                temp = new Car();
                cout << " Joined Lane: ";
                temp->print();
                carList[g].push_back(*temp);
            }
            else {
                cout << " b";
                temp = &carList[g].back();
                int small_index = 0;
                int small_val = carList[0].size();
                for(int f = 0; f < carList.size(); f++) {
                    if (carList[f].size() < small_val) {
                        small_index = f;
                    }
                }
                cout << " b";
                carList[g].pop_back();
                carList[small_index].push_back(*temp);
                cout << " Switched Lane: ";
                temp->print();
                cout << " Lane " << g << " to " << small_index << " ";
            }
        }
        // print header for current queue
        cout << endl << "Queue: " << endl;
        // print current queue
        for(int e = 0; e < carList.size(); e++) {
            cout << "Lane " << e << ": ";
            for (int i = 0; i < carList[e].size(); i++) {
                carList[e][i].print();
            }
            if (carList[e].size() == 0) {
                cout << "Empty" << endl;
            }
        }
        cout << endl;
        t++;
    }
}