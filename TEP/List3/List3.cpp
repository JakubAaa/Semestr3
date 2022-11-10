#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::endl;

class CNodeStatic {
private:
    vector<CNodeStatic> v_children;
    CNodeStatic *pc_parent_node;
    int i_val;

public:
    CNodeStatic() {
        i_val = 0;
        pc_parent_node = NULL;
    };

    ~CNodeStatic() {
        while (!v_children.empty())
            v_children.pop_back();
    };

    void vSetValue(int iNewVal) {
        i_val = iNewVal;
    };

    int iGetChildrenNumber() {
        return (v_children.size());
    };

    void vAddNewChild() {
        CNodeStatic newNode;
        newNode.pc_parent_node = this;
        v_children.push_back(newNode);
    };

    CNodeStatic *pcGetChild(int iChildOffset) {
        if (iChildOffset < 0) {
            cout << "Offset is negative!" << endl;
            return NULL;
        }
        if (iChildOffset >= v_children.size()) {
            cout << "Offset is out of bands!" << endl;
            return NULL;
        }
        return &v_children.at(iChildOffset);
    };

    void vPrint() {
        cout << " " << i_val;
    };

    void vPrintAllBelow() {
        vPrint();
        for (int i = 0; i < iGetChildrenNumber(); i++)
            pcGetChild(i)->vPrintAllBelow();
    };

    void vPrintUp() {
        vPrint();
        if (pc_parent_node == NULL)
            return;
        pc_parent_node->vPrintUp();
    }
};

class CTreeStatic {
private:
    CNodeStatic c_root;
public:
    CTreeStatic() {
        c_root = CNodeStatic();
    };

    ~CTreeStatic();

    CNodeStatic *pcGetRoot() {
        return &c_root;
    }

    void vPrintTree() {
        c_root.vPrintAllBelow();
    };
};

class CNodeDynamic {
private:
    vector<CNodeDynamic *> v_children;
    CNodeDynamic *pc_parent_node;
    int i_val;
public:
    CNodeDynamic() {
        i_val = 0;
        pc_parent_node = NULL;
    };

    ~CNodeDynamic();

    void vSetValue(int iNewVal) { i_val = iNewVal; };

    int iGetChildrenNumber() { return (v_children.size); };

    void vAddNewChild();

    CTreeDynamic *pcGetChild(int iChildOffset);

    void vPrint() { cout << " " << i_val; };

    void vPrintAllBelow();
};

class CTreeDynamic {
private:
    CNodeDynamic *pc_root;
public:
    CTreeDynamic();

    ~CTreeDynamic();

    CNodeDynamic *pcGetRoot() { return (pc_root); }

    void vPrintTree();
};

void v_node_static_test() {
    CNodeStatic c_root;
    c_root.vAddNewChild();
    c_root.vAddNewChild();
    c_root.pcGetChild(0)->vSetValue(1);
    c_root.pcGetChild(1)->vSetValue(2);
    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    c_root.vPrintAllBelow();
    cout << endl;

    c_root.pcGetChild(0)->pcGetChild(1)->vPrintUp();
    cout << endl;
}

void v_tree_static_test() {
//    CTreeStatic tree;
    //tree.vPrintTree();
}


int main() {
    v_node_static_test();
    v_tree_static_test();
    return 0;
}
