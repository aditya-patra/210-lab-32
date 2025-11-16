#include "Car.h"
#include <deque>
#include <array>

using namespace std;

const int START_SIZE = 2;
// probabilities of each function when lane has at least 1 car
const int F_CAR_JOIN = 39, F_CAR_LEAVE = 46, F_CAR_CHANGE = 15;
// probability of new car joining when lane has no cars
const int E_CAR_JOIN = 50;

int main() {
    array<deque<Car>, 4> carList;
    Car* temp;
    // add 2 Car objects to car line to start
    for(int i = 0; i < carList.size(); i++) {
        for (int e = 0; e < START_SIZE; e++) {
            temp = new Car();
            carList[i].push_back(*temp);
        }
    }
    // simulation
    cout << "Initial Queue: " << endl;
    for(int e = 0; e < carList.size(); e++) {
        cout << "Lane " << e+1 << ":" << endl;
        for (int i = 0; i < carList[e].size(); i++) {
            carList[e][i].print();
        }
    }
    // iterate through each time value (1 to 20)
    for (int t = 1; t <= 20; t++) {
        // print time/iteration
        cout << endl << "Time: " << t << endl;
        // iterate through each lane
        for(int g = 0; g < carList.size(); g++) {
            cout << "Lane: " << g+1;
            // check if current lane has at least 1 car
            if (carList[g].size() != 0) {
                int rnd = (int)(rand() % 100);
                // 46% chance of car paying
                if (rnd < F_CAR_LEAVE) {
                    if (carList[g].size() > 0) {
                        cout << " Car Paid: ";
                        carList[g][0].print();
                        carList[g].pop_front();
                    }
                }
                // 39% chance of car joining
                else if (rnd < (F_CAR_JOIN+F_CAR_LEAVE)) {
                    temp = new Car();
                    cout << " Joined Lane: ";
                    temp->print();
                    carList[g].push_back(*temp);
                }
                // 15% chance of car switching lanes
                else {
                    *temp = carList[g].back();
                    // switch to lane with fewest cars
                    int small_index = 0;
                    int small_val = carList[0].size();
                    for(int f = 0; f < carList.size(); f++) {
                        if (carList[f].size() < small_val) {
                            small_index = f;
                        }
                    }
                    // if current lane has fewest cars, switch to next lane
                    if (small_index == g) {
                        if (small_index == 3) {
                            small_index = 0;
                        }
                        small_index += 1;
                    }
                    // switch lanes
                    carList[g].pop_back();
                    carList[small_index].push_back(*temp);
                    cout << " Switched: ";
                    temp->print();
                }
            }
            // 50% change of car joining lane if lane is empty
            else {
                int rnd = (int)(rand() % 100);
                if (rnd < E_CAR_JOIN) {
                    temp = new Car();
                    cout << " Joined Lane: ";
                    temp->print();
                    carList[g].push_back(*temp);
                }
            }
        }
        // print current queue
        for(int e = 0; e < carList.size(); e++) {
            cout << "Lane " << e+1 << " Queue: ";
            if (carList[e].size() == 0) {
                cout << "Empty" << endl;
            }
            else {
                cout << endl;
            }
            for (int i = 0; i < carList[e].size(); i++) {
                carList[e][i].print();
            }
        }
        cout << endl;
        t++;
    }
}