/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class LFUCache {
private:
    int mxCap;
    unordered_map<int, pair<int, int>> cache;
    unordered_map<int, list<int>::iterator> pos;
    map<int, list<int>> freqList;

    void cntKey(int key) {
        int &freq = cache[key].second;

        if (freq) {
            freqList[freq].erase(pos[key]);
            if (freqList[freq].empty())
                freqList.erase(freq);
        }
        
        ++freq;
        freqList[freq].emplace_back(key);
        list<int>::iterator it = --freqList[freq].end();
        pos[key] = it;
    }

    void popLFU() {
        if (freqList.empty())       return;
        list<int> &lFreq = freqList.begin()->second;
        int key = lFreq.front();
        lFreq.pop_front();
        if (lFreq.empty())
            freqList.erase(freqList.begin());
        pos.erase(key);
        cache.erase(key);
        ++mxCap;
    }
public:
    LFUCache(int capacity) {
        this->mxCap = capacity;
    }
    
    int get(int key) {
        if (cache.count(key)) {
            cntKey(key);
            return cache[key].first;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            cache[key].first = value;
            cntKey(key);
            return;
        }
        
        if (!mxCap)     popLFU();
        if (mxCap) {
            --mxCap;
            cache[key].first = value;
            cntKey(key);
        }
    }
};