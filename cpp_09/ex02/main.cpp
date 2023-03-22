#include "PmergeMe.hpp"
#include <sstream>

bool                isInputCorrect(int argc, char** argv);
bool                isNumber(std::string arg);
std::vector<int>    fillSequence(int argc, char **argv);
void                printResults(PmergeMe<std::multiset<int> > &mergeSet, PmergeMe<std::priority_queue<int> > &mergeQueue);

int main(int argc, char** argv)
{
    std::vector<int>    sequence;

    if (!isInputCorrect(argc, argv))
        return (1);
    sequence = fillSequence(argc, argv);
    PmergeMe<std::multiset<int> >        mergeSet(sequence);
    PmergeMe<std::priority_queue<int> >  mergeQueue(sequence);
    mergeSet.sort_sequence();
    mergeQueue.sort_sequence();
    printResults(mergeSet, mergeQueue);
    return (0);
}

void    printResults(PmergeMe<std::multiset<int> > &mergeSet, PmergeMe<std::priority_queue<int> > &mergeQueue)
{
    std::multiset<int>::const_iterator  it_set;

    std::cout << "Before:";
    for (size_t i = 0; i < mergeSet.getSize(); i++)
        std::cout << " " << mergeSet.getSequenceElement(i);
    std::cout << std::endl;

    std::cout << "After: ";
    mergeQueue.getSize(); // for debugging

    std::multiset<int>::const_iterator it;
    for (it = mergeSet.begin(mergeSet); it != mergeSet.end(mergeSet); it++)
        std::cout << " " << *it;
    std::cout << std::endl;

    std::cout << "Time to process a range of " <<  mergeSet.getSize() << " elements "\
                << "with std::multiset:       " << mergeSet.getSortingTime() << " us" << std::endl;
    std::cout << "Time to process a range of " <<  mergeQueue.getSize() << " elements "\
                <<"with std::priority_queue: " << mergeQueue.getSortingTime() << " us" << std::endl;

}


std::vector<int>    fillSequence(int argc, char **argv)
{
    std::vector<int>    sequence;
    std::stringstream   magical_converter_stream;
    unsigned int        next_int;

    for (int i = 1; i < argc; i++)
    {
        magical_converter_stream << argv[i];
        magical_converter_stream >> next_int;
        magical_converter_stream.clear();
        sequence.push_back(next_int);
    }
    return (sequence);
}


bool    isInputCorrect(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Not enough arguments" << std::endl;
        return (false);
    }
    if (argc > 3010)
    {
        std::cout << "Too many arguments" << std::endl;
        return (false);
    }
    for (int i = 1; i < argc; i++)
    {
        if (!isNumber(argv[i]))
            return (false);
    }
    return (true);
}

bool    isNumber(std::string arg)
{
    for (unsigned long i = 0; i < arg.length(); i++)
    {
        if (!std::isdigit(arg.at(i)))
        {
            std::cout << "Error: wrong input" << std::endl;
            return (false);
        }
    }
    return (true);
}