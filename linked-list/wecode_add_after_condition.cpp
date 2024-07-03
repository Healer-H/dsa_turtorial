#include <iostream>
using namespace std;

/**
 * Input: 
 *      + List
 *      + val
 * 
 * Output: 
 *      + List include val
 * 
 * duyệt qua các phần tử trong list, nếu là sso nguyên tố --> thêm vào ngay chỗ đó --> duyệt tiếp
 * 
 * 
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

void CreateEmptyList(LIST &L)
{
    L.pHead = L.pTail = NULL;
}

void AddTail(LIST &L, int val)
{
    NODE *newNode  = new NODE;
    newNode->value = val;
    newNode->pNext = NULL;
    if (L.pHead == NULL && L.pTail == NULL)
    {
        L.pHead = L.pTail = newNode;
        return;
    }
    L.pTail->pNext = newNode;
    L.pTail        = newNode;
}

void CreateList(LIST &L)
{
    int x;
    while (cin >> x)
    {
        if (x == -1)
            return;
        AddTail(L, x);
    }
}

bool isPrime(int val)
{
    if (val < 2)
        return false;
    for (int i = 2; i * i <= val; i++)
    {  // sqrt(i) <= val
        if (val % i == 0)
            return false;
    }
    return true;
}

void AddAfterNode(NODE *&node, int val)
{
    NODE *newNode  = new NODE;
    newNode->value = val;
    newNode->pNext = node->pNext;
    node->pNext    = newNode;
}

void add_after_all_prime(LIST &L, int val)
{
    NODE *node = L.pHead;
    while (node != NULL)
    {
        if (isPrime(node->value))
        {
            // add after node
            AddAfterNode(node, val);
            node = node->pNext;
        }
        node = node->pNext;
    }
}

void PrintList(LIST L)
{
    NODE *node = L.pHead;
    if (node == NULL)
    {
        cout << "Empty List.\n";
        return;
    }

    while (node != NULL)
    {
        cout << node->value << " ";
        node = node->pNext;
    }
    cout << "\n";
}

void print(NODE* node) {
    if(!node) cout << " empty ";
    else cout << node->value << " ";
} 

void reverseList(LIST &L)
{
    if (L.pHead == NULL && L.pTail == NULL)
        return;

    if (L.pHead == L.pTail)
        return;
    NODE *prev    = NULL;
    NODE *current = L.pHead;
    NODE *next    = current->pNext;

    NODE* head = L.pHead, *tail = L.pTail;
    
    while(current != NULL) {
        current->pNext = prev;
        prev = current;
        current = next;
        if(next != NULL) next = next->pNext;
    }
    L.pHead = tail;
    L.pTail = head;
}

int main()
{
    LIST L;
    int  Y;

    CreateEmptyList(L);

    CreateList(L);

    PrintList(L);

    reverseList(L);

    PrintList(L);

    return 0;
}