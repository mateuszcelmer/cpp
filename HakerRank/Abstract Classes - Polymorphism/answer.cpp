#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node
{
    Node *next;
    Node *prev;
    int value;
    int key;
    Node(Node *p, Node *n, int k, int val) : prev(p), next(n), key(k), value(val){};
    Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val){};
};

class Cache
{

  protected:
    map<int, Node *> mp;            //map the key to the node in the linked list
    int cp;                         //capacity
    Node *tail;                     // double linked list tail pointer
    Node *head;                     // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0;       //get function
};

class LRUCache : public Cache
{
  public:
    LRUCache(int capacity)
    {
        cp = capacity;
    };
    int get(int key)
    {
        if (cp < 1 || mp.find(key) == mp.end())
            return -1;
        return mp[key]->value;
    };
    void set(int key, int val)
    {
        // jesli capacity ustawione na 0 lub mniej -> out
        if (cp <= 0)
            return;

        // jesli zaczynamy od pustego cachu
        if (mp.size() == 0)
        {
            Node *node = new Node(key, val);
            head = node;
            tail = node;
            mp.insert(make_pair(key, node));
        }
        // jesli cache juz nie jest pusty
        else
        {
            // jeśli go nie ma w cachu => dodaj nową wartość na pocz i usun osttnia, jesli jest full
            if (mp.find(key) == mp.end())
            {
                Node *node = new Node(NULL, head, key, val);
                head->prev = node;
                head = node;
                mp.insert(make_pair(key, node));
                // usun ostatnia, jesli full
                if (mp.size() > cp)
                {
                    mp.erase(mp.find(tail->key));
                    auto przed_ostatni = tail->prev;
                    delete tail;
                    tail = przed_ostatni;
                    tail->next = NULL;
                }
            }

            // jesli juz jest w cachu => przesun na pocz i aktual val
            else
            {

                if (mp[key] == head) // jesli jest juz na poczatku cachu,
                                     // uaktualnij wartosc
                {
                    head->value = val;
                    return;
                }

                Node *on = mp[key];
                if (on->prev != NULL)
                    on->prev->next = on->next;
                if (on->next != NULL)
                    on->next->prev = on->prev;
                head->prev = on;
                on->next = head;
                on->prev = NULL;
                head = on;
                head->value = val;
            }
        }
    }
};

int main()
{
    int n, capacity, i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (command == "get")
        {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if (command == "set")
        {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}