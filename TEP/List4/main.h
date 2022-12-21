#ifndef LIST4_MAIN_H

#include "vector"
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

template<typename T>
class CNodeDynamic {
private:
    vector<CNodeDynamic *> v_children;
    CNodeDynamic *pc_parent_node;
    T T_val;
public:
    CNodeDynamic() {
        pc_parent_node = NULL;
    };

    ~CNodeDynamic() {
        for (int i = 0; i < iGetChildrenNumber(); i++) {
            delete v_children[i];
        }
    };

    void vSetValue(T TNewValue);

    int iGetChildrenNumber();

    void vAddNewChild();

    CNodeDynamic *pcGetChild(int iChildOffset);

    void vPrint();

    void vPrintAllBelow();

    void setChild(int offset, CNodeDynamic *child);

    void setParent(CNodeDynamic *parent);

    void deleteChild(CNodeDynamic *childToDelete);
};

template<typename T>
void CNodeDynamic<T>::vSetValue(T TNewValue) {
    T_val = TNewValue;
}

template<typename T>
int CNodeDynamic<T>::iGetChildrenNumber() {
    return v_children.size();
}

template<typename T>
void CNodeDynamic<T>::vAddNewChild() {
    CNodeDynamic *newNode;
    newNode = new CNodeDynamic();
    newNode->pc_parent_node = this;
    v_children.push_back(newNode);
}

template<typename T>
CNodeDynamic<T> *CNodeDynamic<T>::pcGetChild(int iChildOffset) {
    if (iChildOffset < 0) {
        cout << "Offset is negative!" << endl;
        return NULL;
    }
    if (iChildOffset >= v_children.size()) {
        cout << "Offset is out of bands!" << endl;
        return NULL;
    }

    return v_children.at(iChildOffset);
}

template<typename T>
void CNodeDynamic<T>::vPrint() {
    cout << " " << T_val;
}

template<typename T>
void CNodeDynamic<T>::vPrintAllBelow() {
    vPrint();
    for (int i = 0; i < iGetChildrenNumber(); i++)
        pcGetChild(i)->vPrintAllBelow();
}

template<typename T>
void CNodeDynamic<T>::setChild(int offset, CNodeDynamic *child) {
    v_children.at(offset) = child;
}

template<typename T>
void CNodeDynamic<T>::setParent(CNodeDynamic *parent) {
    pc_parent_node = parent;
}

template<typename T>
void CNodeDynamic<T>::deleteChild(CNodeDynamic *childToDelete) {
    for (int i = 0; i < pc_parent_node->v_children.size(); i++) {
        if (pc_parent_node->v_children.at(i) == childToDelete)
            pc_parent_node->v_children.erase(pc_parent_node->v_children.begin() + i);

    }
}

template<typename T>
class CTreeDynamic {
private:
    CNodeDynamic<T> *pc_root;
public:
    CTreeDynamic() {
        pc_root = new CNodeDynamic<T>();
    }

    ~CTreeDynamic() {
        delete pc_root;
    }

    CNodeDynamic<T> *pcGetRoot();

    void vPrintTree();

    bool bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode);
};

template<typename T>
CNodeDynamic<T> *CTreeDynamic<T>::pcGetRoot() {
    return (pc_root);
}

template<typename T>
void CTreeDynamic<T>::vPrintTree() {
    pc_root->vPrintAllBelow();
}

template<typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode) {
    if (pcParentNode != NULL && pcNewChildNode != NULL) {
        pcParentNode->vAddNewChild();
        pcParentNode->setChild(pcParentNode->iGetChildrenNumber() - 1, pcNewChildNode);
        pcNewChildNode->deleteChild(pcNewChildNode);
        pcNewChildNode->setParent(pcParentNode);
        return true;
    } else
        return false;
}

#endif //LIST4_MAIN_H