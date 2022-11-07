#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Table {
private:
    int **table;
    int sizeX;
    int sizeY;
public:
    Table(int xSize, int ySize) {
        sizeX = xSize;
        sizeY = ySize;
        table = new int *[sizeX];
        for (int i = 0; i < sizeX; i++)
            table[i] = new int[sizeY];
    }

    Table operator+(const Table &other) {
        if (sizeX != other.sizeX || sizeY != other.sizeY) {
            cout << "Table have different sizes!" << endl;
        }
        Table newTable= Table(sizeX, sizeY);
        for (int i = 0; i < sizeX; i++) {
            for (int j = 0; j < sizeY; j++)
                newTable.table[i][j] = table[i][j] + other.table[i][j];
        }
        return newTable;
    }

    void fillTable1() {
        for (int i = 0; i < sizeX; i++) {
            for (int j = 0; j < sizeY; j++) {
                table[i][j] = 1;
            }
        }
    };

    void fillTable2() {
        for (int i = 0; i < sizeX; i++) {
            for (int j = 0; j < sizeY; j++) {
                table[i][j] = 2;
            }
        }
    };

    void printTable() {
        for (int i = 0; i < sizeX; i++) {
            for (int j = 0; j < sizeY; j++)
                cout << *&table[i][j] << "    ";
            cout << endl;
        }
    };
};

int main() {
    Table table1 = Table(4, 5);
    table1.fillTable1();
    Table table2 = Table(4, 5);
    table2.fillTable2();
    Table table3 = Table(4,5);
    table3 = table2 + table1;
    table1.printTable();
    cout << endl;;
    table2.printTable();
    cout << endl;;
    table3.printTable();
    return 0;
};