// Author: Jakub Pawlin
// Algorithm: Reverse Polish Notation (computing)

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

int32_t main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::string input;

	std::stack <long double> numbers;

	while (std::cin >> input && input != "=")
	{
		if (input == "+")
		{
			long double number1 = numbers.top();
			numbers.pop();
			long double number2 =  numbers.top();
			numbers.pop();
			numbers.push(number1 + number2);
		}
		else if (input == "-")
		{
			long double number1 = numbers.top();
			numbers.pop();
			long double number2 =  numbers.top();
			numbers.pop();
			numbers.push(number2 - number1);
		}
		else if (input == "*")
		{
			long double number1 = numbers.top();
			numbers.pop();
			long double number2 =  numbers.top();
			numbers.pop();
			numbers.push(number1 * number2);
		}
		else if (input == "/")
		{
			long double number1 = numbers.top();
			numbers.pop();
			long double number2 =  numbers.top();
			numbers.pop();
			numbers.push(number2 / number1);
		}
		else
		{
			long double number = std::stold(input);
			numbers.push(number);
		}
	}

	std::cout << numbers.top() << '\n';

	return 0;
}
