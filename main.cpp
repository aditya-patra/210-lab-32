#include "Car.h"
#include <deque>

using namespace std;

const int START_SIZE = 2;

int main() {
    deque<Car> carList;
    Car* temp;
    // add 2 Car objects to car line to start
    for (int i = 0; i < START_SIZE;i++) {
        temp = new Car();
        carList.push_back(*temp);
    }
    // simulation
    cout << "Initial Queue: " << endl;
    int t = 1;
    while (carList.size() != 0) {
        // print current queue
        for (int i = 0; i < carList.size(); i++) {
            carList[i].print();
        }
        cout << endl;
        // print time/iteration
        cout << "Time: " << t << " ";
        // check if car pays
        if ((int)(rand() % 100) >= 55) {
            cout << "Car Paid: ";
            carList[0].print();
            cout << " ";
            carList.pop_front();
        }
        // check if car joins lane
        if ((int)(rand() % 100) >= 45) {
            temp = new Car();
            cout << "Joined Lane: ";
            temp->print();
            cout << " ";
            carList.push_back(*temp);
        }
        // print header for current queue
        cout << endl << "Queue: " << endl;
        t++;
    }
    cout << "Empty";
}