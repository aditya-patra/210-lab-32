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
    int t = 1;
    while (carList[0].size() != 0) {
        // print current queue
        for(int e = 0; e < carList.size(); e++) {
            for (int i = 0; i < carList[0].size(); i++) {
                carList[e][i].print();
            }
            cout << endl;
        }
        cout << endl;
        // print time/iteration
        cout << "Time: " << t << " ";
        // check if car pays
        if ((int)(rand() % 100) >= 55) {
            cout << "Car Paid: ";
            carList[0][0].print();
            cout << " ";
            carList[0].pop_front();
        }
        // check if car joins lane
        if ((int)(rand() % 100) >= 45) {
            temp = new Car();
            cout << "Joined Lane: ";
            temp->print();
            cout << " ";
            carList[0].push_back(*temp);
        }
        // print header for current queue
        cout << endl << "Queue: " << endl;
        t++;
        break;
    }
    cout << "Empty";
}