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
    PmergeMe(std::vector<int> _sequence);
    PmergeMe(const PmergeMe &other);
    ~PmergeMe();

    PmergeMe    &operator=(const PmergeMe &other);

    std::multiset<int>::const_iterator  &begin(const PmergeMe<std::multiset<int> > &mergeSet) const;
    std::multiset<int>::const_iterator  &end(const PmergeMe<std::multiset<int> > &mergeSet) const;

    void    sort_sequence();
    T       &getSortedSequence(const PmergeMe<std::multiset<int> > &mergeSet) const;
    size_t  getSize();
    int     getSequenceElement(size_t i);
    int     getSortedElement(PmergeMe<std::multiset<int> > &mergeSet, size_t pos);
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
