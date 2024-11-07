#include <iostream>
using namespace std;

class OSOBA {
public:
    int age;

    OSOBA(int a) : age(a) {}

    virtual void operator++() {
        age++;
        cout << "OSOBA's age increased to: " << age << endl;
    }

    virtual void print() const {
        cout << "Age: " << age << endl;
    }
};

class STUDENT : public OSOBA {
public:
    int year;

    STUDENT(int a, int y) : OSOBA(a), year(y) {}

    void operator++() override {
        ++year;
        ++age; 
        cout << "STUDENT: Now in year " << year << ", age increased to " << age << endl;
    }

    void print() const override {
        cout << "Age: " << age << ", Year: " << year << endl;
    }
};

int main() {
    OSOBA* person = new OSOBA(30);
    person->print();
    ++(*person);

    STUDENT* student = new STUDENT(20, 1);
    student->print();
    ++(*student);

    OSOBA* p = student;
    p->print();
    ++(*p); 

    delete person;
    delete student;

    return 0;
}



