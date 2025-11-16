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
        for (int i = 0; i < carList[0].size(); i++) {
            carList[e][i].print();
        }
    }
    for (int t = 1; t <= 20; t++) {
        // print time/iteration
        cout << "Time: " << t << " ";
        for(int g = 0; g < carList.size(); g++) {
            // check if car pays
            if ((int)(rand() % 100) >= 50) {
                cout << "Car Paid: ";
                carList[g][0].print();
                cout << " ";
                carList[g].pop_front();
            }
            // check if car joins lane
            if ((int)(rand() % 100) >= 50) {
                temp = new Car();
                cout << "Joined Lane: ";
                temp->print();
                cout << " ";
                carList[g].push_back(*temp);
            }
        }
        // print header for current queue
        cout << endl << "Queue: " << endl;
        // print current queue
        for(int e = 0; e < carList.size(); e++) {
            for (int i = 0; i < carList[0].size(); i++) {
                carList[e][i].print();
            }
            cout << endl;
        }
        cout << endl;
        t++;
        break;
    }
    cout << "Empty";
}