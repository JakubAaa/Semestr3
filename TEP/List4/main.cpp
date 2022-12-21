#include "main.h"

int main() {
    cout << "\nTEST NodeDynamic" << endl;
    CNodeDynamic<float> *nodeDynamic = new CNodeDynamic<float>();
    nodeDynamic->vSetValue(1);
    nodeDynamic->vAddNewChild();
    nodeDynamic->vAddNewChild();
    nodeDynamic->vAddNewChild();
    nodeDynamic->pcGetChild(0)->vSetValue(11);
    nodeDynamic->pcGetChild(1)->vSetValue(22);
    nodeDynamic->pcGetChild(2)->vSetValue(33);
    nodeDynamic->vPrintAllBelow();
    cout << endl;

    cout << "\nTEST DynamicTree" << endl;
    CTreeDynamic<int> *dynamicTree1 = new CTreeDynamic<int>();
    dynamicTree1->pcGetRoot()->vSetValue(0);
    dynamicTree1->pcGetRoot()->vAddNewChild();
    dynamicTree1->pcGetRoot()->vAddNewChild();
    dynamicTree1->pcGetRoot()->vAddNewChild();
    dynamicTree1->pcGetRoot()->pcGetChild(0)->vSetValue(1);
    dynamicTree1->pcGetRoot()->pcGetChild(1)->vSetValue(2);
    dynamicTree1->pcGetRoot()->pcGetChild(2)->vSetValue(3);
    dynamicTree1->pcGetRoot()->pcGetChild(2)->vAddNewChild();
    dynamicTree1->pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4);
    dynamicTree1->vPrintTree();
    cout << endl;

    cout << "\nMove Subtree:" << endl;
    CTreeDynamic<int> *dynamicTree2 = new CTreeDynamic<int>();
    dynamicTree2->pcGetRoot()->vSetValue(50);
    dynamicTree2->pcGetRoot()->vAddNewChild();
    dynamicTree2->pcGetRoot()->vAddNewChild();
    dynamicTree2->pcGetRoot()->pcGetChild(0)->vSetValue(54);
    dynamicTree2->pcGetRoot()->pcGetChild(1)->vSetValue(55);
    dynamicTree2->pcGetRoot()->pcGetChild(0)->vAddNewChild();
    dynamicTree2->pcGetRoot()->pcGetChild(0)->vAddNewChild();
    dynamicTree2->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
    dynamicTree2->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57);
    dynamicTree2->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
    dynamicTree2->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);

    cout << "Before:" << endl;
    dynamicTree1->vPrintTree();
    cout << endl;
    dynamicTree2->vPrintTree();
    cout << endl;

    dynamicTree1->bMoveSubtree(dynamicTree1->pcGetRoot()->pcGetChild(2), dynamicTree2->pcGetRoot()->pcGetChild(0));

    cout << "After:" << endl;
    dynamicTree1->vPrintTree();
    cout << endl;
    dynamicTree2->vPrintTree();
    cout << endl;

    cout << "\nString Dynamic Tree:" << endl;
    CTreeDynamic<std::string> *dynamicTreeString = new CTreeDynamic<std::string>();
    dynamicTreeString->pcGetRoot()->vSetValue("A");
    dynamicTreeString->pcGetRoot()->vAddNewChild();
    dynamicTreeString->pcGetRoot()->vAddNewChild();
    dynamicTreeString->pcGetRoot()->pcGetChild(0)->vSetValue("B");
    dynamicTreeString->pcGetRoot()->pcGetChild(1)->vSetValue("C");
    dynamicTreeString->pcGetRoot()->pcGetChild(0)->vAddNewChild();
    dynamicTreeString->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue("D");
    dynamicTreeString->vPrintTree();
    return 0;
}
