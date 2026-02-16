#include "../includes/MutantStack.hpp"
#include <iostream>

int main(void)
{
	std::cout << "--- Test Iterator ---" << std::endl;
	MutantStack<int> mstack;
	for (unsigned int i = 0; i <= 10; i++)
		mstack.push(i * 10);
	std::cout << "Size: " << mstack.size() << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		// *it = 42;
		it++;
	}
	std::cout << std::endl << "--- Test Reverse_iterator ---" << std::endl;
	MutantStack<int>::reverse_iterator reverse_it = mstack.rbegin();
	MutantStack<int>::reverse_iterator reverse_ite = mstack.rend();
	while (reverse_it != reverse_ite)
	{
		std::cout << *reverse_it << std::endl;
		reverse_it++;
	}
	std::cout << std::endl << "--- Test Const_iterator ---" << std::endl;
	const MutantStack<int> const_mstack = mstack;
	MutantStack<int>::const_iterator const_it = const_mstack.begin();
	MutantStack<int>::const_iterator const_ite = const_mstack.end();
	while (const_it != const_ite)
	{
		std::cout << *const_it << std::endl;
		// *const_it = 42;
		const_it++;
	}
	return 0;
}

// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }
