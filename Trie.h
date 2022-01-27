#pragma once

#ifndef TrieTree
#define TrieTree


#include <iostream>
#include <string>
#include <list>
using namespace std;

const int ALPHABET_SIZE = 26;



// ��������� ����� ������ 
struct TrieNode
{
	TrieNode* children[ALPHABET_SIZE];



	// isEndOfWord - true, ���� ���� �������� ������ �����
	bool isEndOfWord;
	

	char toLetter(int ind)
	{
		if (ind >= ALPHABET_SIZE || ind < 0)
			return '?';
		return 'a' + ind;
	}


	TrieNode* fromLetter(char l)
	{
		if (l < 'a' || l > 'z')
			return nullptr;
		return children[l - 'a'];
	}

	bool hasChildren()
	{
		for (char c = 'a'; c <= 'z'; c++)
			if (fromLetter(c))
				return true;
		return false;
	}
	
	
};

// ���������� ����� ���� � ������� ������
TrieNode* getNewNode(void);

// �������
void insert(TrieNode*, string);

bool isEmpty(TrieNode*);



#endif

