#include <iostream>
#include "list1.h"

using std::cout;
using std::endl;
using std::string;

bool isSizeCorrect(int size) {
    return size >= 0;
}

void allocateTableAndFill(int size) {
    if (!isSizeCorrect(size))
        return;

    int *table;
    table = new int[size];

    for (int i = 0; i < size; i++)
        table[i] = DEFAULT_TABLE_FILLER;

    for (int i = 0; i < size; i++)
        cout << table[i] << "\t";

    delete table;
}

bool allocate2DTable(int **&piTable, int sizeX, int sizeY) {
    if (!isSizeCorrect(sizeX) || !isSizeCorrect(sizeY))
        return false;

    piTable = new int *[sizeX];
    for (int i = 0; i < sizeX; i++)
        piTable[i] = new int[sizeY];

    return true;

}

bool deallocate2DTable(int **&piTable, int sizeX, int sizeY) {
    if (!isSizeCorrect(sizeX) || !isSizeCorrect(sizeY))
        return false;

    for (int i = 0; i < sizeX; i++)
        delete piTable[i];
    delete piTable;

    return true;
}

class Table {
private:
    string name;
    int *table;
    int length;
public:
    Table() {
        this->name = DEFAULT_NAME;
        this->length = DEFAULT_TABLE_LENGTH;
        this->table = new int[length];
        cout << PARAMETER_LESS << name << endl;
    }

    Table(string name, int tableLength) {
        if (!isSizeCorrect(tableLength))
            return;

        this->name = name;
        this->length = tableLength;
        this->table = new int[tableLength];
        cout << PARAMETER << name << endl;
    }

    Table(Table &other) {
        this->name = other.name + COPY_SUFFIX;
        this->length = other.length;
        this->table = other.table;
        cout << COPY << name << endl;
    }

    ~Table() {
        cout << DELETE << this->name << endl;
    }

    void setName(string name) {
        this->name = name;
    }

    bool setNewLength(int tableLength) {
        if (!isSizeCorrect(tableLength))
            return false;

        this->length = tableLength;
        return true;
    }

    Table *clone() {
        return new Table(*this);
    }

    void print() {
        cout << NAME << this->name << endl;
        cout << TABLE_LENGTH << this->length << endl;
        cout << TABLE;
        for (int i = 0; i < length; i++)
            cout << table[i] << "\t";
        cout << endl;
    }
};

void modifyTable(Table *table, int tableLength) {
    table->setNewLength(tableLength);
}

void modifyTable(Table table, int tableLength) {
    table.setNewLength(tableLength);
}


int main() {
    //Task1
    cout << "Task1" << endl;
    allocateTableAndFill(4);
    allocateTableAndFill(0);
    allocateTableAndFill(-4);
    cout << "\n" << endl;

    //Task2
    cout << "Task2" << endl;
    int **table;
    cout << allocate2DTable(table, 2, 2) << endl;
    cout << allocate2DTable(table, -1, 2) << endl;
    cout << allocate2DTable(table, 1, -2) << endl;
    cout << allocate2DTable(table, -1, -2) << endl;
    cout << "\n";

    //Task3
    cout << "Task3" << endl;
    cout << deallocate2DTable(table, 2, 4) << endl;
    cout << deallocate2DTable(table, -2, 4) << endl;
    cout << deallocate2DTable(table, 2, -4) << endl;
    cout << deallocate2DTable(table, -2, -4) << endl;
    cout << "\n";

    //Task4
    cout << "Task4" << endl;
    Table *table1;
    table1 = new Table();
    table1->print();
    cout << "\n";

    Table *table2;
    table2 = new Table("Test Table", 8);
    table2->print();
    cout << "\n";

    Table *table3;
    table3 = new Table(*table1);
    table3->print();
    cout << "\n";

    delete table3;
    cout << "\n";

    table1->setName("New name");
    table1->print();
    cout << "\n";

    table1->setNewLength(3);
    table1->print();
    cout << "\n";

    Table *clonedTable;
    clonedTable = table2->clone();
    clonedTable->print();
    cout << "\n";

    Table *table4;
    table4 = new Table();
    modifyTable(table4, 3);
    table4->print();
    cout << "\n";

    Table *table5;
    table5 = new Table();
    modifyTable(*table5, 3);
    table5->print();
    cout << "\n";

    return 0;
}