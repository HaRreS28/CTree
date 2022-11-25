# Practising dynamic and static memory allocation 

:large_blue_circle: Vectors

:large_blue_circle: Dynamic allocation

:large_blue_circle: Static allocation

## STATIC TREE

```c++
void v_tree_test() {
    CTreeStatic treeStatic;
    treeStatic.pcGetRoot()->vAddNewChild();
    treeStatic.pcGetRoot()->vAddNewChild();
    treeStatic.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    treeStatic.pcGetRoot()->pcGetChild(1)->vSetValue(2);
    treeStatic.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    treeStatic.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    treeStatic.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    treeStatic.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    treeStatic.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    treeStatic.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    treeStatic.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    treeStatic.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    CTreeStatic treeStatic2;
    treeStatic2.pcGetRoot()->vAddNewChild();
    treeStatic2.pcGetRoot()->vAddNewChild();
    treeStatic2.pcGetRoot()->pcGetChild(0)->vSetValue(-1);
    treeStatic2.pcGetRoot()->pcGetChild(1)->vSetValue(-2);
    treeStatic2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    treeStatic2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    treeStatic2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(-11);
    treeStatic2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(-12);

    treeStatic.bMoveSubtree(treeStatic.pcGetRoot()->pcGetChild(0)->pcGetChild(0)
    ,treeStatic2.pcGetRoot());
}//void v_tree_test()
```


##DYNAMIC TREE

```c++
void v_tree_test_dynamic(){
    CTreeDynamic cTreeDynamic;
    cTreeDynamic.pcGetRoot()->vAddNewChild();
    cTreeDynamic.pcGetRoot()->vAddNewChild();
    cTreeDynamic.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    cTreeDynamic.pcGetRoot()->pcGetChild(1)->vSetValue(2);
    cTreeDynamic.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    cTreeDynamic.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    cTreeDynamic.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    cTreeDynamic.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    cTreeDynamic.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    cTreeDynamic.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    cTreeDynamic.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    cTreeDynamic.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);
   
    
    CTreeDynamic cTreeDynamic2;
    cTreeDynamic2.pcGetRoot()->vAddNewChild();
    cTreeDynamic2.pcGetRoot()->vAddNewChild();
    cTreeDynamic2.pcGetRoot()->pcGetChild(0)->vSetValue(-1);
    cTreeDynamic2.pcGetRoot()->pcGetChild(1)->vSetValue(-2);
    cTreeDynamic2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    cTreeDynamic2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    cTreeDynamic2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(-11);
    cTreeDynamic2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(-12);

    cTreeDynamic.bMoveSubtree(cTreeDynamic.pcGetRoot()->pcGetChild(0)->pcGetChild(0)
            ,cTreeDynamic2.pcGetRoot());
}
```
