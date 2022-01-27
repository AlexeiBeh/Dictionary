#include <iostream>
#include <list>
#include <string>
#include "Trie.h"
using namespace std;

list<string> scanTree(const string& path, TrieNode* node)
{
	if (!node)
		return list<string>();

	list<string> paths;

	if (!node->hasChildren())
	{
		paths.push_back(path);
		return paths;
	}

	else
	{
		for (char c = 'a'; c <= 'z'; c++)
		{
			auto v = scanTree(path + c, node->fromLetter(c));
			paths.insert(paths.end(), v.begin(), v.end());
		}
		


		
	}
	
	// вывести список строк
	// по всей видимости не совсем правильно
	//copy(paths.begin(), paths.end(), ostream_iterator<string>(cout, " "));

	return paths;
}

list<string> getVariants(string prefix, TrieNode* root)
{
	auto p = prefix;
	auto curr = root;
	
	while (!p.empty())
	{
		auto newNode = curr->fromLetter(p.at(0));
		
		// обнуляем первый элемент строки Р
		p.erase(0,1);

		if (!newNode)
		{
			return list<string>();

		}
			
	}
	return scanTree(prefix, curr);
}

int main()
{
	TrieNode* NewTrie = getNewNode();
	
	insert(NewTrie, "cut");
	insert(NewTrie, "cat");

	getVariants("c", NewTrie);

	return 0;
}
















/*
#include <iostream>
#include "Trie.h"
#include <list>
#include <string>

const unsigned int alphabetSize = 'z' - 'a' + 1;

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	
	
	TrieNode* NewTrie = getNewNode();
	
	insert(NewTrie, "fce");
	insert(NewTrie, "fcd");
	//insert(NewTrie, "cut");

	
	int choise;
	string addword;
	string searchWord;

	do
	{
		cout << "Выберете действие..." << endl << "1	- Добавить словa в словарь" << endl << "2	- Найти слово по первым буквам" << endl << "3	- Завершения программы" << endl;
		cin >> choise;

		do
		{

			if (choise != 1 && choise != 2 && choise != 3)
			{
				cout << "Выбирете пункт меню" << endl;
			}

		} while (choise != 1 && choise != 2 && choise != 3);
		switch (choise)
		{
		case 1:
		{
			cout << "ВНИМАНИЕ! ИСПОЛЬЗУЕТСЯ ТОЛЬКО АНГЛИЙСКИЙ АЛФАВИТ И строчные БУКВЫ!" << endl;
			cout << "Введите слова для добавления в словарь по одному" << endl << "Для выхода из меню добавления слов в словарь введите '-exit'" << endl;
			do
			{
				// очищаем строку
				addword.clear();
				
				cin >> addword;
				
				// добавляем в дерево
				if (addword != "-exit")
				{ 
					insert(NewTrie, addword);
					cout << "Слово добавлено" << endl;
				}
			} while (addword != "-exit");
			break;
		}
		case 2:
		{
			cout << "ВНИМАНИЕ! ИСПОЛЬЗУЕТСЯ ТОЛЬКО АНГЛИЙСКИЙ АЛФАВИТ И строчные БУКВЫ!" << endl;
			cout << "Введите часть слова для поиска по словарю" << endl << "Для выхода из меню добавления слов в словарь введите '-exit'" << endl;

			do
			{
				searchWord.clear();
				cin >> searchWord;
				if (searchWord != "-exit")
					searchEndPart(NewTrie, searchWord);

			} while (addword != "-exit");
			break;
		}

		default:
			break;
		}
	} while (choise != 3);
	
		return 0;

	



}*/