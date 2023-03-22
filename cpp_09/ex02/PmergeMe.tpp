#ifndef PMERGEME_TPP
# define PMERGEME_TPP

# include <set>
# include <queue>

template<typename T>
PmergeMe<T>::PmergeMe() {}

template<typename T>
PmergeMe<T>::PmergeMe(std::vector<int> _sequence) \
: sequence(_sequence), sorting_time(0) {}

template<typename T>
PmergeMe<T>::PmergeMe(const PmergeMe &other) {*this = other;}

template<typename T>
PmergeMe<T>::~PmergeMe() {}

template<typename T>
PmergeMe<T>    &PmergeMe<T>::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->sequence = other.sequence;
        this->sorted_sequence = other.sorted_sequence;
        this->sorting_time = other.sorting_time;
    }
    return (*this);
}

template<typename T>
void    PmergeMe<T>::sort_sequence()
{
    clock_t start_time;
    clock_t end_time;
    clock_t time_taken;

    start_time = clock();
    for (size_t i = 0; i < this->sequence.size(); i++)
    {
        this->addElement(sorted_sequence, i);
    }
    end_time = clock();
    time_taken = end_time - start_time;
    this->sorting_time = ((float)time_taken)/CLOCKS_PER_SEC;
}

std::priority_queue::const_iterator begin(PmergeMe<std::priority_queue<int> > mergeQueue) {return (mergeQueue.sorted_sequence.begin());}
// std::multiset::const_iterator       begin(PmergeMe<std::multiset<int> > mergeSet) {return (mergeSet.sorted_sequence.begin());}
// std::priority_queue::const_iterator end(PmergeMe<std::priority_queue<int> > mergeQueue) {return (mergeQueue.sorted_sequence.end());}
// std::multiset::const_iterator       end(PmergeMe<std::multiset<int> > mergeSet) {return (mergeSet.sorted_sequence.end());}

template<typename T>
void    PmergeMe<T>::addElement(std::multiset<int> &sorted_sequence, size_t i)
{
    sorted_sequence.insert(this->sequence.at(i));
}

template<typename T>
void    PmergeMe<T>::addElement(std::priority_queue<int> &sorted_sequence, size_t i)
{
    sorted_sequence.push(this->sequence.at(i));
}

template<typename T>
size_t  PmergeMe<T>::getSize() {return (this->sequence.size());}

template<typename T>
int PmergeMe<T>::getSequenceElement(size_t i) {return (this->sequence.at(i));}

template<typename T>
int PmergeMe<T>::getSortedElement(size_t pos)
{
    std::multiset<int>::const_iterator it = this->begin();
    for (size_t i = 0; i <= pos; i++)
        it++;
    return (*it);
}

template<typename T>
float PmergeMe<T>::getSortingTime() {return (this->sorting_time);}

// template<typename T>
// void    PmergeMe<T>::printResults()
// {
//     std::multiset<int>::const_iterator  it_set;

//     std::cout << "Before:";
//     for (size_t i = 0; i < this->sequence.size(); i++)
//         std::cout << " " << this->sequence.at(i);
//     std::cout << std::endl;

//     std::cout << "After: ";
//     for (it_set = this->m_set.begin(); it_set != this->m_set.end(); it_set++)
//         std::cout << " " << *it_set;
//     std::cout << std::endl;

//     std::cout << "Time to process a range of " <<  this->sequence.size() << " elements "\
//                 << "with std::multiset:       " << this->time_set << " us" << std::endl;
//     std::cout << "Time to process a range of " <<  this->sequence.size() << " elements "\
//                 <<"with std::priority_queue: " << this->time_queue << " us" << std::endl;
// }

#endif
