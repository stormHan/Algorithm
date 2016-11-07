#include "main.h"

struct Trie_node
{
	bool exist;
	Trie_node* next[26];
	int count;
};

Trie_node* createTrie()
{
	Trie_node* root = new Trie_node();
	root->count = 0;
	root->exist = false;
	memset(root->next, 0, sizeof(root->next));

	return root;
}

void deleteTrie(Trie_node* root)
{
	for (int i = 0; i < 26; ++i)
	{
		if (root->next[i] != NULL)
			deleteTrie(root->next[i]);
	}
	delete root;
}

void insert(Trie_node* root, string word)
{
	int nb = word.size();
	if (nb == 0) return;

	Trie_node* pt = root;
	root->count++;
	for (int i = 0; i < nb; ++i)
	{
		int p = word[i] - 'a';
		if (pt->next[p] == NULL)
		{
			Trie_node* tt = new Trie_node();
			tt->count = 1;
			memset(tt, NULL, sizeof(tt->next));
			if (i == nb - 1)
				tt->exist = true;
			else
				tt->exist = false;
			pt->next[p] = tt;
		}
		else
		{
			pt->next[p]->count++;
			if (i == nb - 1)
				pt->next[p]->exist = true;
		}
		pt = pt->next[p];
	}
	return;
}

int find(Trie_node* root, string word)
{
	int nb = word.size();
	if (nb == 0) return 0;

	Trie_node* pt = root;
	for (int i = 0; i < word.size(); ++i)
	{
		int p = word[i] - 'a';
		if (pt->next[p] == NULL) return 0;
		if (i == nb - 1) return pt->next[p]->count;
		else
			pt = pt->next[p];
	}

}

int Trie_main()
{
	int N, M;
	vector<string> words;
	vector<string> searches;

	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; ++i)
	{
		string temp;
		getline(cin, temp);
		words.push_back(temp);
	}
	scanf("%d", &M);
	getchar();
	for (int i = 0; i < M; ++i)
	{
		string temp;
		getline(cin, temp);
		searches.push_back(temp);
	}


	Trie_node* root = createTrie();
	for (int i = 0; i < words.size(); ++i)
	{
		insert(root, words[i]);
	}
	for (int i = 0; i < searches.size(); ++i)
	{
		printf("%d\n", find(root, searches[i]));
	}
	deleteTrie(root);

	return 0;
}