/**
 *  @judge ZeroJudge
 *  @id d526
 *  @tag Binary search tree
 */
#include <stdio.h>
#include <iostream>
using namespace std;

class BST
{
public:
	struct node
	{
		int key;
		node *left, *right;
		node()
		{
			key = 0;
			left = right = NULL;
		}
		node(int k)
		{
			key = k;
			left = right = NULL;
		}
		void clear()
		{
			if (left != NULL) left -> clear();
			if (right != NULL) right -> clear();
			delete this;
			return ;
		}
		void create(int k)
		{
			if (key > k)
			{
				if (left == NULL)
					left = new node(k);
				else left -> create(k);
			}
			else if (key < k)
			{
				if (right == NULL)
					right = new node(k);
				else right -> create(k);
			}
			return ;
		}
		void inorder()
		{
			printf("%d ", key);
			if (left != NULL) left -> inorder();
			if (right != NULL) right -> inorder();
			return ;
		}
	} *root;
	BST()
	{
		root = NULL;
	}
	~BST()
	{
		if (root != NULL)
			root -> clear();
		root = NULL;
	}
	void clear()
	{
		if (root != NULL)
			root -> clear();
		root = NULL;
	}
	void insert(int k)
	{
		if (root != NULL)
			root -> create(k);
		else root = new node(k);
		return ;
	}
	void print()
	{
		if (root != NULL)
			root -> inorder();
		puts("");
	}
};

BST bst;
int n;

int main()
{
	int tmp;
	while (scanf("%d", &n) != EOF)
	{
		bst.clear();
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &tmp);
			bst.insert(tmp);
		}
		bst.print();
	}
}