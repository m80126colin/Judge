#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

string preorder(string in, string post)
{
	if (in.size() <= 1)
		return in;
	int pivot, len, left, right;
	len = in.size();
	for (pivot = 0; pivot < len; pivot++)
		if (in[pivot] == post[len - 1])
			break;
	left = pivot;
	right = len - pivot - 1;
	return post[len - 1] + preorder(in.substr(0, left), post.substr(0, left)) + preorder(in.substr(pivot + 1, right), post.substr(pivot, right));
}

int main()
{
	string in, post;
	while (cin >> in >> post)
		cout << preorder(in, post) << endl;
}