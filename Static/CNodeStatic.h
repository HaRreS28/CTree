#include <iostream>
#include <vector>

using namespace std;
//class CTreeStatic;
//
//class CNodeStatic {
//public:
//    CNodeStatic() {
//        i_val = 0;
//        pc_parent_node = NULL;
//    };
//
//    ~CNodeStatic();
//
//    void vSetValue(int iNewVal) { i_val = iNewVal; };
//
//    int iGetChildrenNumber() { return (v_children.size()); };
//
//    void vAddNewChild();
//
//    void vAddNewChild(CNodeStatic &cNodeStatic);
//
//    int iGetChildPosition(CNodeStatic &cNodeStatic);
//
//    bool bRemoveChild(CNodeStatic &cNodeStatic);
//
//    CNodeStatic *pcGetChild(int iChildOffset);
//
//    CNodeStatic *pcGetParent();
//
//    CNodeStatic *pcGetRoot(CNodeStatic* cNodeStatic);
//
//    void vPrint() { cout << " " << i_val; };
//
//    void vPrintAllBelow();
//
//    void vPrintUp();
//
//private:
//    vector<CNodeStatic> v_children;
//    CNodeStatic *pc_parent_node;
//    int i_val;
//};//class CNodeStatic


class CTreeStatic {
public:
    class CNodeStatic {
    public:
        CNodeStatic() {
            i_val = 0;
            pc_parent_node = NULL;
        };

        ~CNodeStatic();

        void vSetValue(int iNewVal) { i_val = iNewVal; };

        int iGetChildrenNumber() { return (v_children.size()); };

        void vAddNewChild();

        void vAddNewChild(CNodeStatic &cNodeStatic);

        int iGetChildPosition(CNodeStatic &cNodeStatic);

        bool bRemoveChild(CNodeStatic &cNodeStatic);

        CNodeStatic *pcGetChild(int iChildOffset);

        CNodeStatic *pcGetParent();

        CNodeStatic *pcGetRoot(CNodeStatic* cNodeStatic);

        void vPrint() { cout << " " << i_val; };

        void vPrintAllBelow();

        void vPrintUp();

    private:
        vector<CNodeStatic> v_children;
        CNodeStatic *pc_parent_node;
        int i_val;
    };//class CNodeStatic

    CTreeStatic();

    CTreeStatic(const CNodeStatic& cNodeStatic);

    ~CTreeStatic();

    CNodeStatic *pcGetRoot() { return (&c_root); }

    void vPrintTree();

    bool bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode);

private:
    CNodeStatic c_root;
};//class CTreeStatic