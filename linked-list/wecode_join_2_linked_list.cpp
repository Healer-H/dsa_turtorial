#include <iostream>
using namespace std;

/**
 * task 1: Có hai list L1 và L2 --> concatenate thành L
 * Task 2: Cho hai giá trị x và y, replace x trong L bởi y
 */

struct NODE
{
    int   value;
    NODE *pNext;
};

struct LIST
{
    NODE *pHead;
    NODE *pTail;
};

void CreateEmptyList(LIST &lst)
{
    lst.pHead = lst.pTail = NULL;
    return;
}

void AddTail(LIST &lst, int val)
{
    NODE *newNode = new NODE;

    newNode->value = val;
    newNode->pNext = NULL;

    if (lst.pHead == NULL && lst.pTail == NULL)
    {
        lst.pHead = lst.pTail = newNode;
    }
    else
    {
        lst.pTail->pNext = newNode;
        lst.pTail        = newNode;
    }
}

void CreateList_AddTail(LIST &lst)
{
    int x;
    while (cin >> x)
    {
        if (x == -1)
            return;
        // add tail
        // NODE *newNode  = new NODE;
        // newNode->value = x;
        // newNode->pNext = NULL;

        // if (lst.pHead == NULL && lst.pTail == NULL)
        // {
        //     lst.pHead = lst.pTail = newNode;
        // }
        // else
        // {
        //     lst.pTail->pNext = newNode;
        //     lst.pTail        = newNode;
        // }
        AddTail(lst, x);
    }
}

LIST Join(LIST L1, LIST L2)
{
    LIST ans;
    CreateEmptyList(ans);
    // if (L1.pHead == NULL && L1.pTail == NULL)
    // {
    //     ans.pHead = L2.pHead;
    //     ans.pTail = L2.pTail;
    //     return ans;
    // }

    // if (L2.pHead == NULL && L2.pTail == NULL)
    // {
    //     ans.pHead = L1.pHead;
    //     ans.pTail = L1.pTail;
    //     return ans;
    // }

    // ans.pHead        = L1.pHead;
    // ans.pTail        = L1.pTail;
    // ans.pTail->pNext = L2.pHead;
    // ans.pTail        = L2.pTail;

    NODE* node1 = L1.pHead;
    NODE* node2 = L2.pHead;
    while(node1 != NULL) {
        AddTail(ans, node1->value);
        node1 = node1->pNext;
    }
    while(node2 != NULL) {
        AddTail(ans, node2->value);
        node2 = node2->pNext;
    }

    return ans;
}

void Edit(LIST &L, int X, int Y)
{
    NODE *node = L.pHead;
    while (node != NULL)
    {
        if (node->value == X)
            node->value = Y;
        node = node->pNext;
    }
}

void PrintList(NODE *head)
{
    if (head == NULL)
    {
        cout << "Empty List.\n";
        return;
    }
    while (head != NULL)
    {
        cout << head->value << " ";
        head = head->pNext;
    }
    cout << "\n";
}

int main()
{
    LIST L, L1, L2;
    int  X, Y;
    CreateEmptyList(L1);
    CreateEmptyList(L2);

    CreateList_AddTail(L1);
    CreateList_AddTail(L2);

    L = Join(L1, L2);
    cin >> X >> Y;
    Edit(L, X, Y);

    PrintList(L1.pHead);
    PrintList(L2.pHead);
    PrintList(L.pHead);

    return 0;
}