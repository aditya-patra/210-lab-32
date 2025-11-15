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
    while(carList.size() != 0) {
        for(int i = 0; i < 2; i++) {
            carList[i].print();
        }
    }
}