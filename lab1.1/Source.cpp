#include <iostream>
#include <string>
using namespace std;

//Розробити програму, яка надає інформацію про багаж пасажирів
//авіарейсу.Весь багаж перебуває під контролем багажного відділення.Програма
//повинна вказувати, який багаж якому пасажиру належить.Зв’язки між класами
//встановити за допомогою шаблону Delegation(Делегування).

class Baggage {
private:
    double weight;
    int baggageId;

public:

    Baggage(double wt, const int& id)
        : weight(wt), baggageId(id) {}

    void displayBaggageInfo() const {
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Id: " << baggageId << endl;
    }

    int getBaggageId() const {
        return baggageId;
    }
};


class Passenger {
private:
    string name;            
    string passportNumber;  
    Baggage* baggage;       

public:
    Passenger(const string& name, const string& pass, Baggage* bag)
        : name(name), passportNumber(pass), baggage(bag) {}

    void displayPassengerInfo() const {
        cout << "Passenger Name: " << name << endl;
        cout << "Passport number: " << passportNumber << endl;
        if (baggage) {
            cout << "---About baggage---" << endl;
            baggage->displayBaggageInfo();
        }
        else {
            cout << "Baggage wasnt found" << endl;
        }
    }

    int getBaggageId() const { 
        if (baggage) {
            return baggage->getBaggageId();
        }
        return -1; 
    }
};

int main() {
    setlocale(LC_ALL, "Ukr");

    Baggage* baggage1 = new Baggage(25.5, 1); 
    Baggage* baggage2 = new Baggage(15.3, 2); 


    Passenger passenger1("Іван Симоненко", "12234dfhjk", baggage1);
    Passenger passenger2("Василь Коваль", "dshfjds444", baggage2);
    Passenger passenger3("Олег Яворський", "7589947fhg", nullptr);

    cout << "Інформація про пасажира 1:" << endl;
    passenger1.displayPassengerInfo();
    cout << endl;

    cout << "Інформація про пасажира 2:" << endl;
    passenger2.displayPassengerInfo();
    cout << endl;

    cout << "Інформація про пасажира 3:" << endl;
    passenger3.displayPassengerInfo();
    cout << endl;

    delete baggage1;
    delete baggage2;

    return 0;
}