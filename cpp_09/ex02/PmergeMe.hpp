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

/* ------------------- iterator -------------------- */

    std::multiset<int>::const_iterator  begin(const PmergeMe<std::multiset<int> > &mergeSet) const;
    std::multiset<int>::const_iterator  end(const PmergeMe<std::multiset<int> > &mergeSet) const;

/* --------------------- member functions --------------------- */

    void    sort_sequence();

/* --------------------- getter --------------------- */

    const T                 &getSortedSequence(const PmergeMe<std::multiset<int> > &mergeSet) const;
    size_t                  getSize() const;
    const std::vector<int>  &getSequence() const;
    float                   getSortingTime() const;


private:
    PmergeMe();

    std::vector<int>    sequence;
    T                   sorted_sequence;
    float               sorting_time;

/* --------------------- "setter" --------------------- */

    void    addElement(std::multiset<int> &sorted_sequence, size_t i);
    void    addElement(std::priority_queue<int> &sorted_sequence, size_t i);

};

# include "PmergeMe.tpp"

#endif
