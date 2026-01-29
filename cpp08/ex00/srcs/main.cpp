#include "../includes/easyfind.hpp"

int main(void)
{
	std::cout << "--- TEST CONST CONTAINERS---" << std::endl << std::endl;
	std::vector<int> vec;
	std::list<int> lst;
	std::deque<int> deque;
	for (int i = 0; i <= 300; ++i)
	{
		vec.push_back(i);
		lst.push_back(i);
		deque.push_back(i);
	}
	const std::vector<int> constvec(vec);
	const std::list<int> constlist(lst);
	const std::deque<int> constdeque(deque);
	try
	{
		std::vector<int>::const_iterator resvec = easyfind(constvec, 200);
		std::cout << "Value found in const vector container: " << *resvec << std::endl << std::endl;
		std::list<int>::const_iterator reslst = easyfind(constlist, 300);
		std::cout << "Value found in const list container: " << *reslst << std::endl << std::endl;
		std::deque<int>::const_iterator resdeque = easyfind(constdeque, 100);
		std::cout << "Value found in const deque container: " << *resdeque << std::endl << std::endl;
		std::vector<int>::const_iterator wrongres = easyfind(constvec, 400);
		std::cout << "Value found in const vector container: " << *wrongres << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	std::cout << "--- TEST NORMAL CONTAINERS ---" << std::endl << std::endl;
	try
	{
		std::vector<int>::iterator resvec = easyfind(vec, 200);
		std::cout << "Value found in vector container: " << *resvec << std::endl << std::endl;
		std::list<int>::iterator reslst = easyfind(lst, 300);
		std::cout << "Value found in list container: " << *reslst << std::endl << std::endl;
		std::deque<int>::iterator resdeque = easyfind(deque, 100);
		std::cout << "Value found in deque container: " << *resdeque << std::endl << std::endl;
		std::vector<int>::iterator wrongres = easyfind(vec, -1);
		std::cout << "Value found in vector container: " << *wrongres << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
