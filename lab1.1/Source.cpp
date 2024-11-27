#include <iostream>
#include <string>
using namespace std;

//��������� ��������, ��� ���� ���������� ��� ����� ��������
//��������.���� ����� �������� �� ��������� ��������� ��������.��������
//������� ���������, ���� ����� ����� �������� ��������.������ �� �������
//���������� �� ��������� ������� Delegation(�����������).

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


    Passenger passenger1("���� ���������", "12234dfhjk", baggage1);
    Passenger passenger2("������ ������", "dshfjds444", baggage2);
    Passenger passenger3("���� ���������", "7589947fhg", nullptr);

    cout << "���������� ��� �������� 1:" << endl;
    passenger1.displayPassengerInfo();
    cout << endl;

    cout << "���������� ��� �������� 2:" << endl;
    passenger2.displayPassengerInfo();
    cout << endl;

    cout << "���������� ��� �������� 3:" << endl;
    passenger3.displayPassengerInfo();
    cout << endl;

    delete baggage1;
    delete baggage2;

    return 0;
}