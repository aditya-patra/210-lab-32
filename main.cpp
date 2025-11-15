#include "Car.h"
#include <deque>

using namespace std;

int main() {
    deque<Car> carList;
    Car* temp;
    carList.push_back(*temp);
    carList[0].print();
}