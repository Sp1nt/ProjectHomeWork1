
#include <iostream>
#include <fstream>
#include "header1.h"
#include "header.h"


using namespace std;

// ������� �� ������ ���� ����������� � ����
void writeAllWorkersToFile(const worker* workers, int quantity) {
    ofstream file("data.txt");
    if (!file.is_open()) {
        cout << "������ �������� ����� ��� ������." << endl;
        return ;
    }

    file << quantity << endl;

    for (int i = 0; i < quantity; i++) {
        file << workers[i].firstName << endl;
        file << workers[i].lastName << endl;
        file << workers[i].number << endl;
        file << workers[i].salary << endl;
    }

    file.close();
}

// ������� �� ������ ���� ����������� �� �����
bool readAllWorkersFromFile(worker* workers, int& quantity) {
    ifstream file("data.txt");
    if (!file.is_open()) {
        cout << "������ �������� ����� ��� ������." << endl;
        return false;
    }

    file >> quantity;

    for (int i = 0; i < quantity; i++) {
        file >> workers[i].firstName;
        file >> workers[i].lastName;
        file >> workers[i].number;
        file >> workers[i].salary;
    }

    file.close();
    return true;
}
