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
        for (int i = 0; i < carList.size(); i++) {
            carList[i].print();
        }
        cout << endl;
        cout << "Time: " << t << " " << endl;
        if ((int)(rand() % 100) >= 55) {
            cout << "Car Paid: ";
            carList[0].print();
            cout << " ";
            carList.pop_back();
        }
        if ((int)(rand() % 100) >= 45) {
            temp = new Car();
            carList.push_back(*temp);
        }
        cout << "Queue: " << endl;
        t++;
    }
}