// Author: Jakub Pawlina
// Algorithm: Caesar Cipher

#include <bits/stdc++.h>

std::string caesar_cipher(std::string message, int shift)
{
	for (uint32_t i = 0; i < message.length(); ++i)
	{
		const short alphabet = ((int)'z' - (int)'a' + 1);
		if (message[i] >= 'a' && message[i] <= 'z')
		{
			message[i] = (int)'a' + ((message[i] - (int)'a' + alphabet + (shift % alphabet)) % alphabet);
		}
		else if (message[i] >= 'A' && message[i] <= 'Z')
		{
			message[i] = (int)'A' + ((message[i] - (int)'A' + alphabet + (shift % alphabet)) % alphabet);
		}
	}

	return message;
}

int32_t main()
{
	int shift; std::cin >> shift;
	std::cin.ignore();
	std::string message; std::getline(std::cin, message);

	std::string result = caesar_cipher(message, shift);

	std::cout << result << '\n';

	return 0;
}
