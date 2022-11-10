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
        for (int i = 0; i < v_children.size(); i++)
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

    ~CNodeDynamic() {
        if (pc_parent_node != NULL)
            delete pc_parent_node;
        while (!v_children.empty()) {
            v_children.pop_back();
        }
    };

    void vSetValue(int iNewVal) {
        i_val = iNewVal;
    };

    int iGetChildrenNumber() {
        return v_children.size();
    };

    void vAddNewChild() {
        CNodeDynamic *newNode;
        newNode = new CNodeDynamic();
        newNode->pc_parent_node = this;
        v_children.push_back(newNode);
    };

    CNodeDynamic *pcGetChild(int iChildOffset) {
        if (iChildOffset < 0) {
            cout << "Offset is negative!" << endl;
            return NULL;
        }
        if (iChildOffset >= v_children.size()) {
            cout << "Offset is out of bands!" << endl;
            return NULL;
        }

        return v_children.at(iChildOffset);
    };

    void vPrint() {
        cout << " " << i_val;
    };

    void vPrintAllBelow() {
        vPrint();
        for (int i = 0; i < iGetChildrenNumber(); i++)
            pcGetChild(i)->vPrintAllBelow();
    };

    void setChild(int offset, CNodeDynamic *child){
        v_children.at(offset) = child;
    }

    void setParent(CNodeDynamic *parent){
        pc_parent_node = parent;
    }

   void deleteChild(CNodeDynamic *childToDelete){
        for(int i = 0; i < pc_parent_node->v_children.size(); i++){
            if( pc_parent_node->v_children.at(i) == childToDelete){
                pc_parent_node->v_children.erase( pc_parent_node->v_children.begin() + i);
            }
        }
    }
};

class CTreeDynamic {
private:
    CNodeDynamic *pc_root;
public:
    CTreeDynamic() {
        pc_root = new CNodeDynamic();
    };

    ~CTreeDynamic() {
        delete pc_root;
    };

    CNodeDynamic *pcGetRoot() {
        return (pc_root);
    }

    void vPrintTree(){
        pc_root->vPrintAllBelow();
    };

    bool bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode){
        pcParentNode->vAddNewChild();
        pcParentNode->setChild(pcParentNode->iGetChildrenNumber() - 1, pcNewChildNode);
        pcNewChildNode->deleteChild(pcNewChildNode);
        pcNewChildNode->setParent(pcParentNode);
    };
};


int main() {
    cout << "TASK2" << endl;
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
    cout << "\n";

    cout << "Children number: " << c_root.iGetChildrenNumber() << endl;

    cout << "\nTASK3" << endl;
    c_root.pcGetChild(0)->pcGetChild(1)->vPrintUp();
    cout << endl;
    c_root.pcGetChild(1)->pcGetChild(0)->vPrintUp();
    cout << endl;

    cout << "\nTASK4" << endl;
    CTreeStatic *staticTree;
    staticTree= new CTreeStatic();
    staticTree->pcGetRoot()->vAddNewChild();
    staticTree->pcGetRoot()->vAddNewChild();
    staticTree->pcGetRoot()->vAddNewChild();
    staticTree->pcGetRoot()->pcGetChild(0)->vSetValue(111);
    staticTree->pcGetRoot()->pcGetChild(1)->vSetValue(222);
    staticTree->pcGetRoot()->pcGetChild(2)->vSetValue(333);
    staticTree->vPrintTree();
    cout << endl;

    cout << "\nTASK5.1" << endl;
    CNodeDynamic *nodeDynamic = new CNodeDynamic();
    nodeDynamic->vAddNewChild();
    nodeDynamic->vAddNewChild();
    nodeDynamic->vAddNewChild();
    nodeDynamic->pcGetChild(0)->vSetValue(11);
    nodeDynamic->pcGetChild(1)->vSetValue(22);
    nodeDynamic->pcGetChild(2)->vSetValue(33);
    nodeDynamic->vPrintAllBelow();
    cout << endl;

    cout << "\nTASK5.2" << endl;
    CTreeDynamic *dynamicTree1 = new CTreeDynamic();
    dynamicTree1->pcGetRoot()->vAddNewChild();
    dynamicTree1->pcGetRoot()->vAddNewChild();
    dynamicTree1->pcGetRoot()->vAddNewChild();
    dynamicTree1->pcGetRoot()->pcGetChild(0)->vSetValue(1111);
    dynamicTree1->pcGetRoot()->pcGetChild(1)->vSetValue(2222);
    dynamicTree1->pcGetRoot()->pcGetChild(2)->vSetValue(333);
    dynamicTree1->vPrintTree();
    cout << endl;

    cout << "\nTASK6" << endl;
    CTreeDynamic *dynamicTree2 = new CTreeDynamic();
    dynamicTree2->pcGetRoot()->vAddNewChild();
    dynamicTree2->pcGetRoot()->pcGetChild(0)->vSetValue(11111);
    dynamicTree2->pcGetRoot()->pcGetChild(0)->vAddNewChild();
    dynamicTree2->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(22222);
    dynamicTree2->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
    dynamicTree2->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(33333);

    dynamicTree1->vPrintTree();
    cout << endl;
    dynamicTree2->vPrintTree();
    cout << endl;

    dynamicTree1->bMoveSubtree(dynamicTree1->pcGetRoot()->pcGetChild(2), dynamicTree2->pcGetRoot()->pcGetChild(0));

    dynamicTree1->vPrintTree();
    cout << endl;
    dynamicTree2->vPrintTree();
    cout << endl;
    return 0;
}
