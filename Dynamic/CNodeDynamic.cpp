#include "CNodeDynamic.h"

void CNodeDynamic::vAddNewChild() {
    CNodeDynamic *cNodeDynamic = new CNodeDynamic;
    cNodeDynamic->pc_parent_node = this;
    v_children.push_back(cNodeDynamic);
}

CNodeDynamic *CNodeDynamic::pcGetChild(int iChildOffset) {
    if (iChildOffset >= 0 && iChildOffset < iGetChildrenNumber()) {
        return v_children.at(iChildOffset);
    } else return NULL;
}

void CNodeDynamic::vPrintAllBelow() {
    vPrint();
    for (int i = 0; i < v_children.size(); i++) {
        pcGetChild(i)->vPrintAllBelow();
    }
}

void CNodeDynamic::vPrintUp() {
    vPrint();
    if (pc_parent_node != NULL) {
        pc_parent_node->vPrintUp();
    }
}

CNodeDynamic::~CNodeDynamic() {
    for (int i = 0; i < iGetChildrenNumber(); i++) {
//        v_children[i]->vPrint();
        delete v_children[i];
    }
    v_children.clear();
}

//ZAD6

CNodeDynamic *CNodeDynamic::pcGetParent() {
    return pc_parent_node;
}

CNodeDynamic *CNodeDynamic::pcGetRoot(CNodeDynamic *cNodeDynamic) {
    if (cNodeDynamic->pc_parent_node != NULL) {
        pcGetRoot(cNodeDynamic->pc_parent_node);
    }
    return cNodeDynamic;
}

int CNodeDynamic::iGetChildPosition(CNodeDynamic *cNodeDynamic) {
    for (int i = 0; i < v_children.size(); i++) {
        if (v_children.at(i) == cNodeDynamic)
            return i;
    }
    return -1;
}

bool CNodeDynamic::bRemoveChild(CNodeDynamic *cNodeDynamic) {
    int position = iGetChildPosition(cNodeDynamic);
    if (position != -1) {
        v_children.erase(v_children.begin() + position);
        return true;
    }
    return false;
}

void CNodeDynamic::vAddNewChild(CNodeDynamic *cNodeDynamic) {
    cNodeDynamic->pc_parent_node = this;
    v_children.push_back(cNodeDynamic);
}

CTreeDynamic::CTreeDynamic() {
    pc_root = new CNodeDynamic;
}

CTreeDynamic::~CTreeDynamic() {
    delete pc_root;
}

void CTreeDynamic::vPrintTree() {
    pc_root->vPrintAllBelow();
}

bool CTreeDynamic::bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode) {
    if (pcParentNode != NULL && pcNewChildNode != NULL) {
        if (pcParentNode->pcGetRoot(pcParentNode) == pcNewChildNode->pcGetRoot(pcNewChildNode))
            return false;
        else {
            CNodeDynamic *pc_parent_temp = pcNewChildNode->pcGetParent();
            if (pc_parent_temp == NULL) {
                return false;
            }
            pcParentNode->vAddNewChild(pcNewChildNode);
            return pc_parent_temp->bRemoveChild(pcNewChildNode);
        }
    }
    return false;
}
