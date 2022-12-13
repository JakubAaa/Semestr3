#ifndef LIST5_MAIN_H
#define LIST5_MAIN_H

#include "iostream"

//TASK 1,2
class CRefCounter {
private:
    int i_count;

public:
    CRefCounter() {
        i_count = 0;
    }

    int iAdd();

    int iDec();

    int iGet();
};

template<typename T>
class CMySmartPointer {
private:
    CRefCounter *pc_counter;
    T *pc_pointer;
public:
    CMySmartPointer(T *pcPointer) {
        pc_pointer = pcPointer;
        pc_counter = new CRefCounter();
        pc_counter->iAdd();
    }

    CMySmartPointer(const CMySmartPointer &pcOther) {
        pc_pointer = pcOther.pc_pointer;
        pc_counter = pcOther.pc_counter;
        pc_counter->iAdd();
    }

    ~CMySmartPointer() {
        if (pc_counter->iDec() == 0) {
            delete pc_pointer;
            delete pc_counter;
        }
    }

    T &operator*();

    T *operator->();

    void operator=(const CMySmartPointer<T> &pcOther);
};

template<typename T>
T &CMySmartPointer<T>::operator*() {
    return *pc_pointer;
}

template<typename T>
T *CMySmartPointer<T>::operator->() {
    return pc_pointer;
}

template<typename T>
void CMySmartPointer<T>::operator=(const CMySmartPointer<T> &pcOther) {
    if (pc_pointer != NULL && pc_counter->iDec() == 0) {
        delete pc_counter;
        delete pc_pointer;
    }
    pc_pointer = pcOther.pc_pointer;
    pc_counter = pcOther.pc_counter;
    pc_counter->iAdd();
}


//TASK4
#define DEF_TAB_SIZE 10

class CTab {
private:
    void v_copy(const CTab &cOther);

    int *pi_tab;
    int i_size;
public:
    CTab() {
        pi_tab = new int[DEF_TAB_SIZE];
        i_size = DEF_TAB_SIZE;
    }

    CTab(const CTab &cOther);

    CTab(CTab &&cOther);

    CTab operator=(const CTab &cOther);

    CTab operator=(CTab &&cOther);

    ~CTab();

    bool bSetSize(int iNewSize);

    int iGetSize();
};

//TASK 5
#define WRONG_DATA "Wrong Data!"
#define DEFAULT_NAME "Default s_name"
#define DEFAULT_LENGTH  10
#define PARAMETER_LESS "Parameterless: "
#define PARAMETER "Parameter: "
#define COPY "Copy: "
#define TABLE_LENGTH "CTable i_length: "
#define COPY_SUFFIX "_copy"
#define NAME "CTable s_name: "
#define TABLE "CTable: "

class CTable {
private:
    std::string s_name;
    int *pi_table;
    int i_length;
public:
    CTable();

    CTable(std::string tableName, int tableLength);

    CTable(CTable &&other);

    void setName(std::string newName);

    bool setNewLength(int tableLength);

    CTable *clone();

    void setValueAt(int index, int value);

    void printTable();

    void operator=(CTable &&pcOther);

    CTable operator+(CTable &pcOther);
};

CTable::CTable() {
    s_name = DEFAULT_NAME;
    i_length = DEFAULT_LENGTH;
    pi_table = new int[i_length];
    std::cout << PARAMETER_LESS << s_name << std::endl;
}

CTable::CTable(std::string tableName, int tableLength) {
    if (tableLength < 0) {
        std::cout << WRONG_DATA << std::endl;
        return;
    }
    s_name = tableName;
    i_length = tableLength;
    pi_table = new int[tableLength];
    std::cout << PARAMETER << s_name << std::endl;
}

CTable::CTable(CTable &&other) {
    s_name = other.s_name + COPY_SUFFIX;
    i_length = other.i_length;
    pi_table = other.pi_table;
    std::cout << COPY << s_name << std::endl;
}

void CTable::setName(std::string newName) {
    s_name = newName;
}

bool CTable::setNewLength(int tableLength) {
    if (tableLength < 0) {
        std::cout << WRONG_DATA << std::endl;
        return false;
    }

    i_length = tableLength;
    pi_table = new int[tableLength];
    return true;
}

CTable *CTable::clone() {
    return new CTable(s_name, i_length);
}

void CTable::setValueAt(int index, int value) {
    pi_table[index] = value;
}

void CTable::printTable() {
    std::cout << NAME << s_name << std::endl;
    std::cout << TABLE_LENGTH << i_length << std::endl;
    std::cout << TABLE;
    for (int i = 0; i < i_length; i++)
        std::cout << pi_table[i] << "\t";
    std::cout << std::endl;
}

void CTable::operator=(CTable &&pcOther) {
    if(pi_table != NULL)
        delete pi_table;

    pi_table = pcOther.pi_table;
    i_length = pcOther.i_length;
    s_name = pcOther.s_name;
    pcOther.pi_table = NULL;
}

CTable CTable::operator+(CTable& pcOther) {
    CTable newTable("newTable", i_length + pcOther.i_length);

    for (int i = 0; i < i_length + pcOther.i_length; i++) {
        if (i < i_length)
            newTable.setValueAt(i, pi_table[i]);
        else {
            newTable.setValueAt(i, pcOther.pi_table[i - i_length]);
        }
    }
    return std::move(newTable);
}

#endif