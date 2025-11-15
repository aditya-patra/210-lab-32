#include "Car.h"
#include <deque>

using namespace std;

int main() {
    deque<Car> carList;
    Car* temp;
    temp = new Car();
    carList.push_back(*temp);
    temp = new Car();
    carList.push_back(*temp);
    for(int i = 0; i < 2; i++) {
        carList[i].print();
    }
}