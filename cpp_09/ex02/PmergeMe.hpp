#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <set>
# include <queue>
# include <vector>
# include <ctime>
# include <exception>

template<typename T>
class   PmergeMe
{
public:
    typedef typename T<int>::container_type::
    PmergeMe(std::vector<int> _sequence);
    PmergeMe(const PmergeMe &other);
    ~PmergeMe();

    PmergeMe    &operator=(const PmergeMe &other);

    std::priority_queue::const_iterator begin(PmergeMe<std::priority_queue<int> > mergeQueue);
    // std::multiset::const_iterator       begin(PmergeMe<std::multiset<int> > mergeSet);
    // std::priority_queue::const_iterator end(PmergeMe<std::priority_queue<int> > mergeQueue);
    // std::multiset::const_iterator       end(PmergeMe<std::multiset<int> > mergeSet);

    void    sort_sequence();

    size_t  getSize();
    int     getSequenceElement(size_t i);
    int     getSortedElement(size_t i);
    float   getSortingTime();

private:
    std::vector<int>            sequence;
    T                           sorted_sequence;
    float                       sorting_time;

    void    addElement(std::multiset<int> &sorted_sequence, size_t i);
    void    addElement(std::priority_queue<int> &sorted_sequence, size_t i);

    PmergeMe();
};

# include "PmergeMe.tpp"

#endif
