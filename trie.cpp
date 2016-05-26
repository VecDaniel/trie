#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define INT_TO_CHAR(c) (char)((int) c+(int)'a')
#define DICTIONARY_SIZE 10
typedef struct trie trie_node;
struct trie
{
	trie_node* children[ALPHABET_SIZE];
	bool isLeaf;
};

trie_node* newNode()
{
	trie_node* node = new trie_node;
	//trie_node* node = (trie_node*) malloc(sizeof(trie_node));
	for (int i = 0; i<ALPHABET_SIZE; i++)
	{
		node->children[i] = NULL;
	}
	node->isLeaf = false;
	return node;
}
void insert(trie_node* root, string word)
{
	trie_node* current = root;
	for (int i = 0; i< word.length(); i++)
	{
		int index = CHAR_TO_INDEX(word[i]);
		if (!current->children[index])
			current->children[index] = newNode();
		current = current->children[index];
	}
	current->isLeaf = true;
	return;
}

bool search(trie_node* root, string word)
{
	trie_node* current = root;
	for (int i = 0; i< word.length(); i++)
	{
		int index = CHAR_TO_INDEX(word[i]);
		if (!current->children[index])
			return false;
		current = current->children[index];
	}
	return true;
}
void makeTree(trie_node*root, string word[], int size)
{
	for (int i = 0; i<size; i++)
		insert(root, word[i]);
}
bool isEmpty(trie_node*root)
{
	int i = 0;
	while (i < DICTIONARY_SIZE)
	{
		if (root->children[i])
			return false;
		i++;
	}
	return true;
}

void printTrie(trie_node*root, string current = "")
{
	int i = 0;
	for (i = 0; i < ALPHABET_SIZE; i++)
	{
		if (root->children[i])
		{
			current = current + INT_TO_CHAR(i); // adaug litera pe care am gasit-o
			if (root->children[i]->isLeaf == true)
			{
				cout << current << "\n";
				//printTrie(root->children[i],current);
			}
			printTrie(root->children[i], current);
			// elimin litera pentru a pregati sirul pentru alte eventuale
			// variante ale literei curente
			current = current.substr(0, current.length() - 1);
		}
	}
}



void validateWord(string &word)
{
	for (int i = 0; i < word.length(); i++)
	{
		if ((word[i] >= 'A' && word[i] <= 'Z'))
			word[i] = tolower(word[i]);

		if(!(word[i]>='a' && word[i]<='z'))
		{
			cout << "\nWrong input.Word must contain only letters.\nReintroduce : ";
			cin >> word;
			validateWord(word);
		}
	}
}
void validateOption(int &opt, int left, int right)
{
	while (opt<left || opt>right)
	{
		cout << "\nReintroduce your option.It must be between : " << left << " - " << right;
		cout << "\nEnter option : ";
		cin >> opt;
	}
}

// Driver
int main()
{	
	/*
	int manage;
	cout << "\n1. Search in a given Trie tree.";
	cout << "\n2. Manage a Trie tree(insert words/search words/print all words).";
	cout << "\n\tChoose option : "; cin >> manage;
	validateOption(manage, 1, 2);
	switch (manage)
	{
		case 1:
		{
			int option2 = 1;
			string search_word;
			string dictionary[] = { "tabac","tabara","copie","copil","caine","pisica","catedra","laptop","profesor","profiterol" };
			trie_node*root = newNode();
			makeTree(root, dictionary, DICTIONARY_SIZE);
		
			do {
				cout << "\nEnter the word you want to search : "; cin >> search_word;
				validateWord(search_word);
				if (search(root, search_word))
					cout << "Word \"" << search_word << "\" was found in the Trie tree !";
				else
					cout << "Word \"" << search_word << "\" was not found in the Trie tree !";
			
				cout << "\n\nWhat will you like to do now ?";
				cout << "\n\t1.Search another word.";
				cout << "\n\t2.Return to the main program.";
				cout << "\n\tYour choice : "; cin >> option2; validateOption(option2, 1, 2);
			} while (option2 == 1);
			break;
		}
		case 2:
		{
			int option3 = 1;
			string insert_word;
			string search_word;
			trie_node*root = newNode();
			cout << "\nEnter the word you want to introduce in the Trie tree : "; cin >> insert_word; validateWord(insert_word);
			insert(root, insert_word);
		}
	}


	
	
	return 0;
	*/
	trie_node*test = newNode();
	insert(test, "car");

	insert(test, "carnaval");
	if (isEmpty(test))
	{
		cout << "Nicio valoare";
	}
	else
	{
		printTrie(test);
	}
	return 0;
}
