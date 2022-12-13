#include "main.h"

//TASK 1,2
int CRefCounter::iAdd() {
    return ++i_count;
}

int CRefCounter::iDec() {
    return --i_count;
}

int CRefCounter::iGet() {
    return i_count;
}

//TASK4
void CTab::v_copy(const CTab &cOther) {
    i_size = cOther.i_size;
    pi_tab = new int[cOther.i_size];
    for (int i = 0; i < cOther.i_size; i++)
        pi_tab[i] = cOther.pi_tab[i];
}

CTab::CTab(const CTab &cOther) {
    v_copy(cOther);
    std::cout << "Copy ";
}

CTab::CTab(CTab &&cOther) {
    pi_tab = cOther.pi_tab;
    i_size = cOther.i_size;
    cOther.pi_tab = NULL;
    std::cout << "MOVE ";
}

CTab CTab::operator=(const CTab &cOther) {
    if (pi_tab != NULL)
        delete pi_tab;
    v_copy(cOther);
    std::cout << "op= ";
    return *this;
}

CTab CTab::operator=(CTab &&cOther) {
    if (pi_tab != NULL)
        delete pi_tab;
    pi_tab = cOther.pi_tab;
    i_size = cOther.i_size;
    cOther.pi_tab = NULL;
    return *this;
}

CTab::~CTab() {
    if (pi_tab != NULL)
        delete pi_tab;
    std::cout << "Destr ";
}

bool CTab::bSetSize(int iNewSize) {
    if (iNewSize < 0) {
        std::cout << "Negative value!" << std::endl;
        return false;
    }
    int *newTab = new int[iNewSize];
    for (int i = 0; i < std::min(i_size, iNewSize); i++) {
        newTab[i] = pi_tab[i];
    }
    i_size = iNewSize;
    pi_tab = newTab;
    return true;
}

int CTab::iGetSize() {
    return i_size;
}

int main() {
    //TASK 1,2
    std::cout << "TESTS 1,2" << std::endl;
    int *pointer = new int[123];
    CMySmartPointer<int> pointer1(pointer);
    pointer1.operator->()[0] = 123;
    pointer1.operator->()[1] = 234;
    pointer1.operator->()[2] = 345;
    pointer1.operator->()[3] = 456;
    CMySmartPointer<int> pointer2(pointer1);
    CMySmartPointer<int> pointer3(new int[7]);
    pointer3 = pointer2;
    std::cout << pointer2.operator->()[0] << std::endl;
    std::cout << pointer2.operator->()[1] << std::endl;
    std::cout << pointer2.operator->()[2] << std::endl;
    std::cout << pointer2.operator->()[3] << std::endl;
    std::cout << std::endl;
    std::cout << pointer3.operator->()[0] << std::endl;
    std::cout << pointer3.operator->()[1] << std::endl;
    std::cout << pointer3.operator->()[2] << std::endl;
    std::cout << pointer3.operator->()[3] << std::endl;
    std::cout << std::endl;

    //TASK 4
    std::cout << "TESTS 4" << std::endl;
    CTab ctab1, ctab2;

    ctab1.bSetSize(5);
    ctab2.bSetSize(7);

    ctab1 = std::move(ctab2);
    std::cout << std::endl;
    std::cout << ctab1.iGetSize() << std::endl;
    std::cout << std::endl;

    //TASK5
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