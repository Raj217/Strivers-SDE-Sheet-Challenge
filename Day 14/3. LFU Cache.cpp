// https://leetcode.com/problems/lfu-cache/description/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    int key;
    int freq;
    Node *next;
    Node *prev;
    Node(int x, int y, int z) : key(x), val(y), freq(z), next(NULL), prev(NULL) {}
};

class LFUCache
{
    int capacity, len;
    unordered_map<int, pair<Node *, Node *>> freq;
    unordered_map<int, Node *> cache;
    bool doesExist(int key)
    {
        return cache.find(key) != cache.end();
    }
    bool isFull()
    {
        return len == capacity;
    }
    void createKeyInFreq(int f)
    {
        Node *head = new Node(-1, -1, f);
        Node *tail = new Node(-1, -1, f);
        head->prev = tail;
        tail->next = head;
        freq[f] = {head, tail};
    }
    void addToHead(Node *node)
    {
        if (freq.find(node->freq) == freq.end())
        {
            createKeyInFreq(node->freq);
        }
        Node *head = freq[node->freq].first;
        head->prev->next = node;
        node->prev = head->prev;
        node->next = head;
        head->prev = node;
    }
    void removeKeyFromFreqWithCheck(int f)
    {
        Node *head = freq[f].first;
        if (head->prev == freq[f].second)
        {
            freq.erase(freq.find(f));
        }
    }
    void incFreq(int key)
    {
        Node *node = cache[key];
        node->freq++;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        removeKeyFromFreqWithCheck(node->freq - 1);
        addToHead(node);
    }
    int pop()
    {
        int f = 1;
        while (freq.find(f) == freq.end())
            f++;
        Node *tail = freq[f].second;
        Node *node = tail->next;
        tail->next = node->next;
        node->next->prev = tail;
        removeKeyFromFreqWithCheck(node->freq);
        len--;
        return node->key;
    }
    Node *push(int key, int val)
    {
        Node *node = new Node(key, val, 1);
        len++;
        addToHead(node);
        return node;
    }

public:
    LFUCache(int capacity)
    {
        len = 0;
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (doesExist(key))
        {
            incFreq(key);
            return cache[key]->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (doesExist(key))
        {
            cache[key]->val = value;
            incFreq(key);
        }
        else
        {
            if (isFull())
            {
                int key = pop();
                // cout << key << endl;
                cache.erase(key);
            }
            cache[key] = push(key, value);
        }
    }
};