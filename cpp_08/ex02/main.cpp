#include "MutantStack.hpp"
#include <iostream>
#include <list>

int	main(void)
{
	std::cout << std::endl << "-------------pdf test---------------" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << std::endl << "-------------compare with list---------------" << std::endl;

	std::list<int> llist;

	llist.push_back(5);
	llist.push_back(17);

	std::cout << llist.back() << std::endl;
	llist.pop_back();
	std::cout << llist.size() << std::endl;

	llist.push_back(3);
	llist.push_back(5);
	llist.push_back(737);
	llist.push_back(0);

	std::list<int>::iterator it_list = llist.begin();
	std::list<int>::iterator ite_list = llist.end();
	++it_list;
	--it_list;
	while (it_list != ite_list)
	{
		std::cout << *it_list << std::endl;
		++it_list;
	}
	std::list<int> l(llist);

	std::cout << std::endl << "-------------string test---------------" << std::endl;

	MutantStack<std::string> mstring;

	mstring.push("five");
	mstring.push("seventeen");

	std::cout << mstring.top() << std::endl;
	mstring.pop();
	std::cout << mstring.size() << std::endl;

	mstring.push("three");
	mstring.push("five");
	mstring.push("737");
	mstring.push("zero");

	MutantStack<std::string>::iterator it_string = mstring.begin();
	MutantStack<std::string>::iterator ite_string = mstring.end();
	++it_string;
	--it_string;
	while (it_string != ite_string)
	{
		std::cout << *it_string << std::endl;
		++it_string;
	}
	std::stack<std::string> st(mstring);

	return (0);
}
