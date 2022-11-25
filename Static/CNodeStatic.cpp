#include "CNodeStatic.h"

void CNodeStatic::vAddNewChild() {
    CNodeStatic cNodeStatic;
    cNodeStatic.pc_parent_node = this;
    v_children.push_back(cNodeStatic);
    for (int i = 0; i<v_children.size(); ++i) {
        v_children[i].pc_parent_node=this;
    }
}

CNodeStatic *CNodeStatic::pcGetChild(int iChildOffset) {
    if (iChildOffset >= 0 && iChildOffset < iGetChildrenNumber()) {
        return &v_children.at(iChildOffset);
    } else return NULL;
}


void CNodeStatic::vPrintAllBelow() {
    vPrint();
    for (int i = 0; i < v_children.size(); i++) {
        pcGetChild(i)->vPrintAllBelow();
    }
}

void CNodeStatic::vPrintUp() {
    vPrint();
    if (pc_parent_node != NULL)
        pc_parent_node->vPrintUp();
}

CNodeStatic::~CNodeStatic() {}

CNodeStatic *CNodeStatic::pcGetParent() {
    return pc_parent_node;
}


CNodeStatic *CNodeStatic::pcGetRoot(CNodeStatic *cNodeStatic) {
    if (cNodeStatic->pc_parent_node != NULL) {
        pcGetRoot(cNodeStatic->pc_parent_node);
    }
    return cNodeStatic;
}

void CNodeStatic::vAddNewChild(CNodeStatic &cNodeStatic) {
    cNodeStatic.pc_parent_node = this;
    v_children.push_back(cNodeStatic);
}

int CNodeStatic::iGetChildPosition(CNodeStatic &cNodeStatic) {
    for (int i = 0; i < v_children.size(); i++) {
        if (&v_children.at(i) == &cNodeStatic)
            return i;
    }
    return -1;
}

bool CNodeStatic::bRemoveChild(CNodeStatic &cNodeStatic) {
    int position = iGetChildPosition(cNodeStatic);
    if (position != -1) {
        v_children.erase(v_children.begin() + position);
        return true;
    }
    return false;
}

//CLASS CTreeStatic

CTreeStatic::CTreeStatic() {
    CNodeStatic cNodeStatic;
    c_root = cNodeStatic;
}

CTreeStatic::CTreeStatic(const CNodeStatic &cNodeStatic) {
    c_root = cNodeStatic;
}

CTreeStatic::~CTreeStatic() {}

void CTreeStatic::vPrintTree() {
    c_root.vPrintAllBelow();
}

//TODO CHANGE PARENTS AND CHECK ADDRESSES !

bool CTreeStatic::bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode) {
    if (pcParentNode != NULL && pcNewChildNode != NULL) {
        if (pcParentNode->pcGetRoot(pcParentNode) == pcNewChildNode->pcGetRoot(pcNewChildNode))
            return false;
        else {
            CNodeStatic *pc_parent_temp = pcNewChildNode->pcGetParent();
            if (pc_parent_temp == NULL) {
                pcParentNode->vAddNewChild(*pcNewChildNode);
                return true;
            }
            pcParentNode->vAddNewChild(*pcNewChildNode);
            return pc_parent_temp->bRemoveChild(*pcNewChildNode);
        }
    }
    return false;
}
