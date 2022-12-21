#include <iostream>
#include "main.h"

using std::cout;
using std::endl;
using std::string;

bool isSizeCorrect(int size) {
    return size >= 0;
}

class CTable {
private:
    string name;
    int *table;
    int length;
public:
    CTable() {
        name = DEFAULT_NAME;
        length = DEFAULT_TABLE_LENGTH;
        table = new int[length];
        cout << PARAMETER_LESS << name << endl;
    }

    CTable(string tableName, int tableLength) {
        if (!isSizeCorrect(tableLength)) {
            cout << WRONG_DATA << endl;
            return;
        }

        name = tableName;
        length = tableLength;
        table = new int[tableLength];
        cout << PARAMETER << name << endl;
    }

    CTable(CTable &other) {
        name = other.name + COPY_SUFFIX;
        length = other.length;
        table = other.table;
        cout << COPY << name << endl;
    }

//    ~CTable() {
//        cout << DELETE << name << endl;
//        delete table;
//    }

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

    CTable *clone() {
        return new CTable(name, length);
    }

    void setValueAt(int index, int value) {
        table[index] = value;
    }

    void printTable() {
        cout << NAME << name << endl;
        cout << TABLE_LENGTH << length << endl;
        cout << TABLE;
        for (int i = 0; i < length; i++)
            cout << table[i] << "\t";
        cout << endl;
    }

    void operator=(const CTable &other) {
        table = other.table;
        length = other.length;
    }

    CTable operator+(const CTable &other) {
        CTable *newTable;
        newTable = new CTable(name, length + other.length);
        for (int i = 0; i < length; i++)
            newTable->table[i] = table[i];

        for (int i = 0; i < other.length; i++)
            newTable->table[length + i] = other.table[i];
        return *newTable;
    }
};

//class Table {
//private:
//    int **table;
//    int sizeX;
//    int sizeY;
//public:
//    Table(int xSize, int ySize) {
//        sizeX = xSize;
//        sizeY = ySize;
//        table = new int *[sizeX];
//        for (int i = 0; i < sizeX; i++)
//            table[i] = new int[sizeY];
//    }
//
//    Table operator+(const Table &other) {
//        if (sizeX != other.sizeX || sizeY != other.sizeY) {
//            cout << "Table have different sizes!" << endl;
//        }
//        Table newTable= Table(sizeX, sizeY);
//        for (int i = 0; i < sizeX; i++) {
//            for (int j = 0; j < sizeY; j++)
//                newTable.table[i][j] = table[i][j] + other.table[i][j];
//        }
//        return newTable;
//    }
//
//    void fillTable1() {
//        for (int i = 0; i < sizeX; i++) {
//            for (int j = 0; j < sizeY; j++) {
//                table[i][j] = 1;
//            }
//        }
//    };
//
//    void fillTable2() {
//        for (int i = 0; i < sizeX; i++) {
//            for (int j = 0; j < sizeY; j++) {
//                table[i][j] = 2;
//            }
//        }
//    };
//
//    void printTable() {
//        for (int i = 0; i < sizeX; i++) {
//            for (int j = 0; j < sizeY; j++)
//                cout << *&table[i][j] << "    ";
//            cout << endl;
//        }
//    };
//};
//
//    int main() {
//        Table table1 = Table(4, 5);
//        table1.fillTable1();
//        Table table2 = Table(4, 5);
//        table2.fillTable2();
//        Table table3 = Table(4,5);
//        table3 = table2 + table1;
//        table1.printTable();
//        cout << endl;;
//        table2.printTable();
//        cout << endl;;
//        table3.printTable();
//        return 0;
//    };
//
//    //Task1
//    cout << "TASK1" << endl;
//    CTable table1, table2;
//    table1.setNewLength(6);
//    table2.setNewLength(4);
//    table1 = table2;
//    table1.printTable();
//    table2.printTable();
//    cout << endl;
//
//    //Task3
//    cout << "TASK3" << endl;
//    CTable table3, table4;
//    table3.setNewLength(6);
//    table4.setNewLength(4);
//
//    for (int i = 0; i < 6; i++)
//        table3.setValueAt(i, i + 1);
//
//    for (int i = 0; i < 4; i++)
//        table4.setValueAt(i, i + 50);
//
//    table3 = table4;
//    table4.setValueAt(2, 123);
//    table3.printTable();
//    table4.printTable();
//    cout << endl;
//
//    //TASK4
//    cout << "TASK4" << endl;
//    CTable table5;
//    table5 = table3 + table4;
//    table5.printTable();
//    cout << endl;
//
//    return 0;
//}

int main(){
    std::cout << "TESTS 5" << std::endl;
    CTable tab1("one", 1);
    tab1.setValueAt(0, 123);
    CTable tab2("two", 2);
    tab2.setValueAt(0, 234);
    tab2.setValueAt(1, 345);

    CTable tab3;

    tab3 = tab1 + tab2;
    tab3.printTable();
    return 0;
}