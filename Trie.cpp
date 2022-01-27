#include <iostream>
#include "Trie.h"


using namespace std;


// ¬озвращет новый узел с пустыми детьми
TrieNode* getNewNode(void)
{
    // ¬ыдел€ем пам€ть по новый узел
    struct TrieNode* pNode = new TrieNode;

    // устанавливаем флаг конца слова в false
    pNode->isEndOfWord = false;

    // инициализируем детей нулевым уазателем
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}


// ¬ставл€ет ключ в дерево, если его нет, 
// иначе если ключ €влетс€ префксом узла дерева 
// помечает вкачестве литового т.е. конец слова
void insert(TrieNode* root, string key)
{
    TrieNode* node = root;



    for (int i = 0; i < key.length(); i++)
    {
        // вычисл€ем индекс в алфите через смещение отнситьельно первой буквы
        int index = key[i] - 'a';

        // если указатель пустрой, т.е. детей с таким префиксом нет
        // создаем новый узел
        if (!node->children[index])
        {

            // создаем ноду
            node->children[index] = getNewNode();
        }



        // если есть така€ нода идем дальше
        node = node->children[index];

    }

    // помечаем последний узлел как лист, т.е. конец слова
    node->isEndOfWord = true;
}

// ¬охвращает true если root имеет лист, иначе false 
bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}


