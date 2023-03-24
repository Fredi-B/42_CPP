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

/* --------------------- member functions --------------------- */

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

/* ------------------- iterator -------------------- */

template<typename T>
std::multiset<int>::const_iterator  PmergeMe<T>::begin(const PmergeMe<std::multiset<int> > &mergeSet) const
{
    return (mergeSet.getSortedSequence(mergeSet).begin());
}

template<typename T>
std::multiset<int>::const_iterator  PmergeMe<T>::end(const PmergeMe<std::multiset<int> > &mergeSet) const
{
    return (mergeSet.getSortedSequence(mergeSet).end());
}

/* --------------------- "setter" --------------------- */

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

/* --------------------- getter --------------------- */

template<typename T>
const T    &PmergeMe<T>::getSortedSequence(const PmergeMe<std::multiset<int> > &mergeSet) const {return (mergeSet.sorted_sequence);}

template<typename T>
size_t  PmergeMe<T>::getSize() const {return (this->sequence.size());}

template<typename T>
const std::vector<int> &PmergeMe<T>::getSequence() const {return (this->sequence);}

template<typename T>
float PmergeMe<T>::getSortingTime() const {return (this->sorting_time);}

#endif
