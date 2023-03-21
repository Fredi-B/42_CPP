#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int> _sequence) \
: sequence(_sequence), time_set(0), time_queue(0) {}

PmergeMe::PmergeMe(const PmergeMe &other) {*this = other;}

PmergeMe::~PmergeMe() {}

PmergeMe    &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->sequence = other.sequence;
        this->m_set = other.m_set;
        this->p_queue = other.p_queue;
        this->time_set = other.time_set;
        this->time_queue = other.time_queue;
    }
    return (*this);
}

void    PmergeMe::fillSet()
{
    clock_t start_time;
    clock_t end_time;
    clock_t time_taken;

    start_time = clock();
    for (size_t i = 0; i < this->sequence.size(); i++)
    {
        this->m_set.insert(this->sequence.at(i));
    }
    end_time = clock();
    time_taken = end_time - start_time;
    this->time_set = ((float)time_taken)/CLOCKS_PER_SEC;
}

void    PmergeMe::fillQueue()
{
    clock_t start_time;
    clock_t end_time;
    clock_t time_taken;

    start_time = clock();
    for (size_t i = 0; i < this->sequence.size(); i++)
    {
        this->p_queue.push(this->sequence.at(i));
    }
    end_time = clock();
    time_taken = end_time - start_time;
    this->time_queue = ((float)time_taken)/CLOCKS_PER_SEC;
}

void    PmergeMe::printResults()
{
    std::cout << "Before: ";
    //loop through sequence, print it
    //for ()
}