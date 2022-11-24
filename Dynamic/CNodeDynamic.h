#include <iostream>
#include <vector>

using namespace std;

class CTreeDynamic;

class CNodeDynamic {
public:
    CNodeDynamic() {
        i_val = 0;
        pc_parent_node = NULL;
    };

    ~CNodeDynamic();

    void vSetValue(int iNewVal) { i_val = iNewVal; };

    int iGetChildrenNumber() { return (v_children.size)(); };

    void vAddNewChild();

    void vAddNewChild(CNodeDynamic *cNodeDynamic);

    CNodeDynamic *
    pcGetChild(int iChildOffset);  // TODO zamienic potem typ zwracany na CTreeDynamic w CNodeStatic to samo

    void vPrint() { cout << " " << i_val; };

    void vPrintAllBelow();

    void vPrintUp();

//    ZAD6
    int iGetChildPosition(CNodeDynamic *cNodeDynamic);

    bool bRemoveChild(CNodeDynamic *cNodeDynamic);

    CNodeDynamic *pcGetParent();

    CNodeDynamic *pcGetRoot(CNodeDynamic *cNodeDynamic);

private:
    vector<CNodeDynamic *> v_children;
    CNodeDynamic *pc_parent_node;
    int i_val;
};//class CNodeDynamic

class CTreeDynamic {
public:
    CTreeDynamic();

    ~CTreeDynamic();

    CNodeDynamic *pcGetRoot() { return (pc_root); }

    void vPrintTree();

    bool bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode);

private:
    CNodeDynamic *pc_root;
};//class CTreeDynamic