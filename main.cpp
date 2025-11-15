#include "Car.h"
#include <deque>

using namespace std;

int main() {
    deque<Car> carList;
    Car* temp;
    temp = new Car();
    carList.push_back(*temp);
    carList[0].print();
}