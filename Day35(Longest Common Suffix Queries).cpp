#include <iostream>
#include <vector>

// Longest Common Suffix Queries

// Instead of pointers, we use integer indices to point to the next node
struct trieNode
{
    int idx;
    int children[26];

    trieNode(int i)
    {
        idx = i;
        // Initialize with -1 instead of NULL
        for (int j = 0; j < 26; j++)
        {
            children[j] = -1;
        }
    }
};

// A contiguous pool of nodes. No 'new' or 'delete' needed!
vector<trieNode> trie;

int getNode(int i)
{
    trie.push_back(trieNode(i));
    return trie.size() - 1; // Return the index of the newly created node
}

void insertTrie(int root, int i, const vector<string> &wordsContainer)
{
    // FIX: Passed by const reference to avoid massive memory copies
    const string &word = wordsContainer[i];
    int n = word.length();
    int curr = root;

    for (int j = n - 1; j >= 0; j--)
    {
        int ch_idx = word[j] - 'a';

        if (trie[curr].children[ch_idx] == -1)
        {
            trie[curr].children[ch_idx] = getNode(i);
        }

        curr = trie[curr].children[ch_idx];

        if (wordsContainer[trie[curr].idx].length() > n)
        {
            trie[curr].idx = i;
        }
    }
}

int searchTrie(int root, const string &word)
{
    int curr = root;
    int result_idx = trie[curr].idx;
    int n = word.length();

    for (int i = n - 1; i >= 0; i--)
    {
        int ch_idx = word[i] - 'a';
        curr = trie[curr].children[ch_idx];

        // If the path doesn't exist, return the best index found so far
        if (curr == -1)
        {
            return result_idx;
        }
        result_idx = trie[curr].idx;
    }
    return result_idx;
}

vector<int> stringIndices(vector<string> &wordsContainer, vector<string> &wordsQuery)
{
    // FIX: Clear the vector so memory from previous testcases doesn't accumulate
    trie.clear();

    int root = getNode(0);

    for (int i = 0; i < wordsContainer.size(); i++)
    {
        if (wordsContainer[trie[root].idx].length() > wordsContainer[i].length())
        {
            trie[root].idx = i;
        }
        insertTrie(root, i, wordsContainer);
    }

    vector<int> result;
    result.reserve(wordsQuery.size()); // Pre-allocate for speed

    for (const string &word : wordsQuery)
    { // FIX: Use const reference for query words too
        result.push_back(searchTrie(root, word));
    }

    return result;
}
