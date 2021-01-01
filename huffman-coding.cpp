// Author: Jakub Pawlina
// Algorithm: Huffman Coding

#include <bits/stdc++.h>

struct Node
{
	char letter;
	int frequency;
	Node* left;
	Node* right;
};

struct node_comparator
{
	bool operator()(Node* left, Node* right)
	{
		return left->frequency > right->frequency;
	}
};

Node* create_node(char letter, int frequency, Node* left, Node* right)
{
	Node* node = new Node();

	node->letter = letter;
	node->frequency = frequency;
	node->left = left;
	node->right = right;

	return node;
}

void get_codes(Node* root, std::string code, std::map <char, std::string> &huffman_codes)
{
	if (root == NULL) return;
	if (!root->left && !root->right) huffman_codes[root->letter] = code;

	get_codes(root->left, code + "0", huffman_codes);
	get_codes(root->right, code + "1", huffman_codes);
}

std::map <char, std::string> build_huffman_tree(std::map <char, int> frequencies)
{
	std::priority_queue <Node*, std::vector <Node*>, node_comparator> queue;

	for (std::map <char, int>::iterator i = frequencies.begin(); i != frequencies.end(); ++i)
	{
		queue.push(create_node(i->first, i->second, NULL, NULL));
	}

	while (queue.size() != 1)
	{
		Node *left = queue.top(); queue.pop();
		Node *right = queue.top(); queue.pop();

		int group_frequency = left->frequency + right->frequency;

		queue.push(create_node('\0', group_frequency, left, right));
	}

	Node* root = queue.top();

	std::map <char, std::string> huffman_codes;
	get_codes(root, "", huffman_codes);

	return huffman_codes;
}

std::string encode_huffman(std::string decoded, std::map <char, int> &frequencies)
{
	std::map <char, std::string> codes = build_huffman_tree(frequencies);

	std::string result = "";
	for (size_t i = 0; i < decoded.size(); ++i)
	{
		result += codes[decoded[i]];
	}

	return result;
}

std::string decode_huffman(std::string encoded, std::map <char, int> &frequencies)
{
	std::map <char, std::string> codes = build_huffman_tree(frequencies);

	std::map <std::string, char> decodes;
	for (std::map <char, std::string>::iterator i = codes.begin(); i != codes.end(); ++i)
	{
		decodes[i->second] = i->first;
	}

	std::string result = "";
	std::string current = "";

	while (!encoded.empty())
	{
		current += encoded[0];
		encoded.erase(0, 1);
		std::map <std::string, char>::iterator position = decodes.find(current);
		if (position != decodes.end())
		{
			result += position->second;
			current = "";
		}
	}

	return result;
}

void encoding()
{
	std::map <char, int> frequencies;

	std::string input;
	std::cin >> input;

	for (size_t i = 0; i < input.size(); ++i)
	{
		++frequencies[input[i]];
	}

	if (frequencies.size() == 1)
	{
		for (size_t i = 0; i < input.size(); ++i)
		{
			std::cout << 0;
		}
		std::cout << '\n';
		return;
	}

	std::cout << encode_huffman(input, frequencies) << '\n';
}

void decoding()
{
	std::map <char, int> frequencies;

	int letters_number;
	std::cin >> letters_number;

	if (letters_number == 1)
	{
		char letter;
		std::cin >> letter;
		int frequency;
		std::cin >> frequency;

		std::string encoded;
		std::cin >> encoded;
		for (size_t i = 0; i < encoded.size(); ++i)
		{
			if (encoded[i] == '0') std::cout << letter;
		}
		std::cout << '\n';
		return;
	}

	for (int i = 0; i < letters_number; ++i)
	{
		char letter;
		std::cin >> letter;
		int letter_frequency;
		std::cin >> letter_frequency;
		frequencies[letter] = letter_frequency;
	}

	std::string encoded;
	std::cin >> encoded;

	std::cout << decode_huffman(encoded, frequencies) << '\n';
}

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::string operation_type;
	std::cin >> operation_type;

	if (operation_type == "ENCODE") encoding();
	else if (operation_type == "DECODE") decoding();

	return 0;
}
