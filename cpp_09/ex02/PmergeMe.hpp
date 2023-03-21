#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <set>
# include <queue>
# include <vector>
# include <time.h>

class   PmergeMe
{
public:
    PmergeMe(std::vector<int> _sequence);
    PmergeMe(const PmergeMe &other);
    ~PmergeMe();

    PmergeMe    &operator=(const PmergeMe &other);

    void    fillSet();
    void    fillQueue();
    void    printResults();

private:
    std::vector<int>            sequence;
    std::multiset<int>          m_set;
    float                       time_set;
    std::priority_queue<int>    p_queue;
    float                       time_queue;

    PmergeMe();
};


#endif
