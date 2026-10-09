// COMSC-210 | Lab 20 | Sarthak Pani
// adapted from the instructor's Chair class starter

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;
const int SIZE = 3;

class Chair {
private:
    int legs;
    double *prices;

public:
    Chair();
    Chair(int l, const double p[]);
    ~Chair();
    void setLegs(int l);
    int getLegs();
    void setPrices(double p1, double p2, double p3);
    double getAveragePrices();
    void print();
};

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    cout << fixed << setprecision(2);

    cout << "DEFAULT CHAIR (random legs and prices)" << endl;
    Chair *chairPtr = new Chair;
    chairPtr->print();

    // use the setters after showing the default chair
    cout << "FIRST CHAIR AFTER SETTERS" << endl;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();
    delete chairPtr;
    chairPtr = nullptr;

    cout << "CUSTOM CHAIR (supplied legs and prices)" << endl;
    double priceHistory[SIZE] = {525.25, 434.34, 252.52};
    Chair *livingChair = new Chair(3, priceHistory);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    // fill the array using the default constructors
    cout << "DEFAULT CHAIR COLLECTION" << endl;
    Chair *collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++) {
        cout << "Chair " << i + 1 << ":" << endl;
        collection[i].print();
    }
    delete[] collection;
    collection = nullptr;

    return 0;
}

Chair::Chair() {
    prices = new double[SIZE];
    legs = rand() % 2 + 3;
    const int MIN = 10000, MAX = 99999;
    for (int i = 0; i < SIZE; i++) {
        // generate whole cents, then convert to dollars
        prices[i] = (rand() % (MAX - MIN + 1) + MIN) / 100.0;
    }
}

Chair::Chair(int l, const double p[]) {
    prices = new double[SIZE];
    legs = l;
    for (int i = 0; i < SIZE; i++) {
        prices[i] = p[i];
    }
}

// release the price array owned by this chair
Chair::~Chair() {
    delete[] prices;
}

void Chair::setLegs(int l) {
    legs = l;
}

int Chair::getLegs() {
    return legs;
}

void Chair::setPrices(double p1, double p2, double p3) {
    prices[0] = p1;
    prices[1] = p2;
    prices[2] = p3;
}

double Chair::getAveragePrices() {
    double sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += prices[i];
    }
    return sum / SIZE;
}

void Chair::print() {
    cout << "CHAIR DATA - legs: " << legs << endl;
    cout << "Price history: ";
    for (int i = 0; i < SIZE; i++) {
        cout << "$" << prices[i] << " ";
    }
    cout << endl << "Historical avg price: $" << getAveragePrices();
    cout << endl << endl;
}
