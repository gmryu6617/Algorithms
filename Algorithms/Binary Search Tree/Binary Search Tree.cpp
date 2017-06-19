#include <iostream>
#include <chrono>
#include <memory>

using namespace std;
using namespace chrono;

struct NODE
{
	int key;
	shared_ptr<NODE> left;
	shared_ptr<NODE> right;
};

class BST
{
public:
	BST() { m_root = nullptr; };
	~BST() {};

	shared_ptr<NODE>& Search(shared_ptr<NODE>& root, int data)
	{
		if (root == nullptr) return root;

		if (data < root->key) return Search(root->left, data);
		else if (data > root->key) return Search(root->right, data);
		else return root;
	}

	void Insert(shared_ptr<NODE>& root, int data)
	{
		if (root == nullptr) {
			shared_ptr<NODE> newNode = make_shared<NODE>();
			newNode->key = data;
			newNode->left = newNode->right = nullptr;
			root = newNode;
		}

		if (data < root->key) return Insert(root->left, data);
		else if (data > root->key) return Insert(root->right, data);
	}

	void Delete(shared_ptr<NODE>& root, int data)
	{
		if (root == nullptr) return;

		if (data < root->key) return Delete(root->left, data);
		else if (data > root->key) return Delete(root->right, data);
		else {
			if (root->left == nullptr && root->right == nullptr) root = nullptr;
			else if (root->left == nullptr) root = root->right;
			else if (root->right == nullptr) root = root->left;
			else {
				shared_ptr<NODE> tmp = root->right;
				shared_ptr<NODE> tmp_p;

				while (tmp->left != nullptr) {
					tmp_p = tmp;
					tmp = tmp->left;
				}

				root->key = tmp->key;

				if (tmp->right == nullptr) tmp = nullptr;
				else {
					tmp_p = tmp->right;
					tmp = nullptr;
				}
			}
		}
	}

public:
	shared_ptr<NODE> m_root;
};

int main()
{
	BST bst;
	int random;

	for (int i = 0; i < 10'000'000; ++i) {
		random = (rand() % 1'000) * 10'000 + rand() % 10'000;
		bst.Insert(bst.m_root, random);
	}

	cout << "11. Binary Search Tree" << endl;

	cout << "Start!" << endl;
	auto start = high_resolution_clock::now();

	cout << bst.Search(bst.m_root, 4'999'999) << endl;

	cout << "Finish!" << endl;
	auto finish = high_resolution_clock::now();
	auto duration = finish - start;

	cout << "Search Elapsed Time: " << duration_cast<milliseconds>(duration).count() << "(ms)" << endl;

	cout << "Start!" << endl;
	start = high_resolution_clock::now();

	bst.Delete(bst.m_root, 4'999'999);
	cout << bst.Search(bst.m_root, 4'999'999) << endl;

	cout << "Finish!" << endl;
	finish = high_resolution_clock::now();
	duration = finish - start;

	cout << "Delete Elapsed Time: " << duration_cast<milliseconds>(duration).count() << "(ms)" << endl;

	cout << "Start!" << endl;
	start = high_resolution_clock::now();

	bst.Insert(bst.m_root, 4'999'999);
	cout << bst.Search(bst.m_root, 4'999'999) << endl;

	cout << "Finish!" << endl;
	finish = high_resolution_clock::now();
	duration = finish - start;

	cout << "Insert Elapsed Time: " << duration_cast<milliseconds>(duration).count() << "(ms)" << endl;

	return 0;
}