// https://leetcode.com/problems/lru-cache/description/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    int key;
    Node *next;
    Node *prev;
    Node(int x, int y) : key(x), val(y), next(NULL), prev(NULL) {}
};

class LRUCache
{
    int capacity, len;
    unordered_map<int, Node *> cache;
    Node *head, *tail;
    bool doesExist(int key)
    {
        return cache.find(key) != cache.end();
    }
    bool isFull()
    {
        return len == capacity;
    }
    void moveToFront(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = head;
        node->prev = head->prev;
        head->prev->next = node;
        head->prev = node;
    }
    int pop()
    {
        Node *node = tail->next;
        node->next->prev = tail;
        tail->next = node->next;
        int key = node->key;
        delete (node);
        len--;
        return key;
    }
    Node *push(int key, int val)
    {
        Node *node = new Node(key, val);
        Node *prev = head->prev;
        prev->next = node;
        node->next = head;
        head->prev = node;
        node->prev = prev;
        len++;
        return node;
    }

public:
    LRUCache(int capacity)
    {
        len = 0;
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->prev = tail;
        tail->next = head;
    }

    int get(int key)
    {
        if (doesExist(key))
        {
            moveToFront(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (doesExist(key))
        {
            cache[key]->val = value;
            moveToFront(cache[key]);
        }
        else
        {
            if (isFull())
            {
                cache.erase(pop());
            }
            cache[key] = push(key, value);
        }
    }
};
