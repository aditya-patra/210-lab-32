#include "Car.h"
#include <deque>

using namespace std;

const int START_SIZE = 2;

int main() {
    deque<Car> carList;
    Car* temp;
    temp = new Car();
    // add 2 Car objects to car line to start
    for (int i = 0; i < START_SIZE; i++) {
        carList.push_back(*temp);
    }
    for(int i = 0; i < 2; i++) {
        carList[i].print();
    }
}