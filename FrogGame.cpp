// FrogGame.cpp : Defines the entry point for the console application.
//https://codereview.stackexchange.com/questions/78625/convert-an-array-to-a-binary-tree

#include "stdafx.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;



class btree
{
	struct node
	{
		string value;
		node* left;
		node*right;
	};

public:
	vector<string> allMoves;

	btree()
	{
		root = new node;
		root->left = new node;
		root->right = new node;
	}

	void fill(node* currentNode, int index, vector<string> container)
	{
		string value = container.at(index);
		if (container.size() > 2 * index + 1)
		{
			currentNode->left = new node;
			

		}
		if (container.size() > 2 * index + 2)
		{

		}
	}

	void genareteRoot(int N)
	{
		root = new node;
		root->value = string(N, '>') + '_' + string(N, '<');
	}

	string getRoot()
	{
		return root->value;
	}

	//void insert(struct node* current, string value);

	void possibleMoves(stack<string> moves)
	{

		if (!moves.empty())
		{
			string current = moves.top();
			//output.push_back(current);
			this->allMoves.push_back(current);
			moves.pop();

			string save = current;

			string temp;

			size_t freeSpace = current.find('_');

			//FREE SPACE AT THE END
			if (current.find('_') == current.length() - 1)
			{
				// move a left frog ahead 1 space
				if (current.at(freeSpace - 1) == '>')
				{
					temp = current.replace(freeSpace - 1, 1, "_");
					temp = current.replace(freeSpace, 1, ">");
					cout << "Found and replaced the current string: " << save << "  with: " << temp << endl;
					moves.push(temp);
					current = save;
				}

				//move left frog ahead 2 spaces
				if (current.at(freeSpace - 2) == '>')
				{
					temp = current.replace(freeSpace - 2, 1, "_");
					temp = current.replace(freeSpace, 1, ">");
					cout << "Found and replaced the current string: " << save << "  with: " << temp << endl;
					moves.push(temp);
					current = save;
				}

			}
			// FREE SPACE AT THE BEGGINING
			else if (current.find('_') == 0)
			{
				//move right frog 1 space
				if (current.at(freeSpace + 1) == '<')
				{
					temp = current.replace(freeSpace + 1, 1, "_");
					temp = current.replace(freeSpace, 1, "<");
					cout << "Found and replaced the current string: " << save << "  with: " << temp << endl;
					moves.push(temp);
					current = save;
				}

				//move right frog 2 spaces 
				if (current.at(freeSpace + 2) == '<')
				{
					temp = current.replace(freeSpace + 2, 1, "_");
					temp = current.replace(freeSpace, 1, "<");
					cout << "Found and replaced the current string: " << save << "  with: " << temp << endl;
					moves.push(temp);
					current = save;
				}
			}

			//FREE SPACE AT THE END - 1
			else if ((current.find('_') == (current.length() - 2)) && (current.length() != 3))
			{
				//move right frog 1 space
				if (current.at(freeSpace + 1) == '<' && (current.length() != 3))
				{
					temp = current.replace(freeSpace + 1, 1, "_");
					temp = current.replace(freeSpace, 1, "<");
					cout << "Found and replaced the current string: " << save << "  with: " << temp << endl;
					moves.push(temp);
					current = save;
				}

				if (current.at(freeSpace - 1) == '>')
				{
					temp = current.replace(freeSpace - 1, 1, "_");
					temp = current.replace(freeSpace, 1, ">");
					cout << "Found and replaced the current string: " << save << "  with: " << temp << endl;
					moves.push(temp);
					current = save;
				}

				//move left frog ahead 2 spaces
				if (current.at(freeSpace - 2) == '>')
				{
					temp = current.replace(freeSpace - 2, 1, "_");
					temp = current.replace(freeSpace, 1, ">");
					cout << "Found and replaced the current string: " << save << "  with: " << temp << endl;
					moves.push(temp);
					current = save;
				}
			}

			// FREE SPACE AT THE START + 1
			else if (current.find('_') == 1 && (current.length() != 3))
			{
				if (current.at(freeSpace - 1) == '>')
				{
					temp = current.replace(freeSpace - 1, 1, "_");
					temp = current.replace(freeSpace, 1, ">");
					cout << "Found and replaced the current string: " << save << "  with: " << temp << endl;
					moves.push(temp);
					current = save;
				}

				//move right frog 1 space
				if (current.at(freeSpace + 1) == '<')
				{
					temp = current.replace(freeSpace + 1, 1, "_");
					temp = current.replace(freeSpace, 1, "<");
					cout << "Found and replaced the current string: " << save << "  with: " << temp << endl;
					moves.push(temp);
					current = save;
				}

				//move right frog 2 spaces 
				if (current.at(freeSpace + 2) == '<')
				{
					temp = current.replace(freeSpace + 2, 1, "_");
					temp = current.replace(freeSpace, 1, "<");
					cout << "Found and replaced the current string: " << save << "  with: " << temp << endl;
					moves.push(temp);
					current = save;
				}
			}

			else if (current.length() == 3)
			{
				if (current.at(freeSpace - 1) == '>')
				{
					temp = current.replace(freeSpace - 1, 1, "_");
					temp = current.replace(freeSpace, 1, ">");
					cout << "Found and replaced the current string: " << save << "  with: " << temp << endl;
					moves.push(temp);
					current = save;
				}

				if (current.at(freeSpace + 1) == '<')
				{
					temp = current.replace(freeSpace + 1, 1, "_");
					temp = current.replace(freeSpace, 1, "<");
					cout << "Found and replaced the current string: " << save << "  with: " << temp << endl;
					moves.push(temp);
					current = save;
				}
			}

			// FREE SPACE SOMEWHERE AT THE MIDDLE
			else
			{
				if (current.at(freeSpace - 1) == '>')
				{
					temp = current.replace(freeSpace - 1, 1, "_");
					temp = current.replace(freeSpace, 1, ">");
					cout << "Found and replaced the current string: " << save << "  with: " << temp << endl;
					moves.push(temp);
					current = save;
				}

				if (current.at(freeSpace - 2) == '>')
				{
					temp = current.replace(freeSpace - 2, 1, "_");
					temp = current.replace(freeSpace, 1, ">");
					cout << "Found and replaced the current string: " << save << "  with: " << temp << endl;
					moves.push(temp);
					current = save;
				}

				//move right frog 1 space
				if (current.at(freeSpace + 1) == '<')
				{
					temp = current.replace(freeSpace + 1, 1, "_");
					temp = current.replace(freeSpace, 1, "<");
					cout << "Found and replaced the current string: " << save << "  with: " << temp << endl;
					moves.push(temp);
					current = save;
				}

				//move right frog 2 spaces 
				if (current.at(freeSpace + 2) == '<')
				{
					temp = current.replace(freeSpace + 2, 1, "_");
					temp = current.replace(freeSpace, 1, "<");
					cout << "Found and replaced the current string: " << save << "  with: " << temp << endl;
					moves.push(temp);
					current = save;
				}
			}
			possibleMoves(moves);
		}
	}

private:
	node* root;

};

int main()
{
	cout << "Enter the number of the frogs" << endl;
	
	// The number of the fogs
	int N;
	cin >> N;

	string finalGoal = string(N, '<') + '_' + string(N, '>');




	btree mytree;

	
	mytree.genareteRoot(N);

	string root = mytree.getRoot();

	stack<string> mystack;
	mystack.push(root);

	mytree.possibleMoves(mystack);

	for (int i = 0; i < mytree.allMoves.size(); i++)
	{
		cout << mytree.allMoves[i] << endl;
	}
	
    return 0;
}

