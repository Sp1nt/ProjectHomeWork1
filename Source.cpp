
#include <iostream>
#include <fstream>
#include "header1.h"
#include "header.h"


using namespace std;

// Функция на запись всех сотрудников в файл
void writeAllWorkersToFile(const worker* workers, int quantity) {
    ofstream file("data.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла для записи." << endl;
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

// Функция на чтение всех сотрудников из файла
bool readAllWorkersFromFile(worker* workers, int& quantity) {
    ifstream file("data.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла для чтения." << endl;
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
