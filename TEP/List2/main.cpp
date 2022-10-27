#include <iostream>
#include "main.h"

using std::cout;
using std::endl;
using std::string;

bool isSizeCorrect(int size) {
    return size >= 0;
}

class Table {
private:
    string name;
    int *table;
    int length;
public:
    Table() {
        name = DEFAULT_NAME;
        length = DEFAULT_TABLE_LENGTH;
        table = new int[length];
        cout << PARAMETER_LESS << name << endl;
    }

    Table(string tableName, int tableLength) {
        if (!isSizeCorrect(tableLength)) {
            cout << WRONG_DATA << endl;
            return;
        }

        name = tableName;
        length = tableLength;
        table = new int[tableLength];
        cout << PARAMETER << name << endl;
    }

    Table(Table &other) {
        name = other.name + COPY_SUFFIX;
        length = other.length;
        table = other.table;
        cout << COPY << name << endl;
    }

    ~Table() {
        cout << DELETE << name << endl;
        delete table;
    }

    void setName(string newName) {
        name = newName;
    }

    bool setNewLength(int tableLength) {
        if (!isSizeCorrect(tableLength)) {
            cout << WRONG_DATA << endl;
            return false;
        }

        length = tableLength;
        table = new int[tableLength];
        return true;
    }

    Table *clone() {
        return new Table(name, length);
    }

    void operator=(const Table &other){
        table = other.table;
        length = other.length;
    }

    void setValueAt(int index, int value){
        table[index] = value;
    }

    void print() {
        cout << NAME << name << endl;
        cout << TABLE_LENGTH << length << endl;
        cout << TABLE;
        for (int i = 0; i < length; i++)
            cout << table[i] << "\t";
        cout << endl;
    }

    Table* operator+(Table &other) {
        Table *newTable;
        newTable = new Table(name + " + " + other.name, length + other.length);
        for(int i = 0; i < length; i++)
            newTable->table[i] = table[i];

        for (int i = 0; i < other.length; i++)
            newTable->table[length + i] = other.table[i];
        return newTable;
    }
};

int main() {
    //Task1
    cout << "TASK1" << endl;
    Table table1, table2;
    table1.setNewLength(6);
    table2.setNewLength(4);
    table1 = table2;
    table1.print();
    table2.print();
    cout << endl;

    //Task3
    cout << "TASK3" << endl;
    Table table3, table4;
    table3.setNewLength(6);
    table4.setNewLength(4);

    for(int i = 0; i < 6; i++)
        table3.setValueAt(i, i + 1);

    for(int i = 0; i < 4; i++)
        table4.setValueAt(i, i + 50);

    table3 = table4;
    table4.setValueAt(2, 123);
    table3.print();
    table4.print();
    cout << endl;

    //TASK4
    cout << "TASK4" << endl;
    Table *table5;
    table5 = table3 + table4;
    table5->print();
    cout << endl;

    return 0;
}