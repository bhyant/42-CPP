#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe() : _timeVector(0), _timeDeque(0)
{
}

PmergeMe::PmergeMe(const PmergeMe& src) : _vector(src._vector), _deque(src._deque), _timeVector(src._timeVector), _timeDeque(src._timeDeque)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
    if (this != &src)
    {
        _vector = src._vector;
        _deque = src._deque;
        _timeVector = src._timeVector;
        _timeDeque = src._timeDeque;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::parseInput(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        if (arg.empty())
            throw std::runtime_error("Error");
        for (size_t j = 0; j < arg.length(); ++j)
        {
            if (arg[j] == '+')
                continue;
            if (arg[j] < '0' || arg[j] > '9')
                throw std::runtime_error("Error");
        }

        long val = std::atol(arg.c_str());
        if (val < 0 || val > 2147483647)
            throw std::runtime_error("Error");

        _vector.push_back(static_cast<int>(val));
        _deque.push_back(static_cast<int>(val));
    }
}

void PmergeMe::printSequence(const std::string& prefix, const std::vector<int>& seq) const
{
    std::cout << prefix;
    size_t limit = seq.size();
    bool truncated = false;

    if (limit > 5)
    {
        limit = 5;
        truncated = true;
    }

    for (size_t i = 0; i < limit; ++i)
        std::cout << seq[i] << " ";

    if (truncated)
        std::cout << "[...]";
    std::cout << std::endl;
}

int PmergeMe::generateJacobsthal(int n) const
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return generateJacobsthal(n - 1) + 2 * generateJacobsthal(n - 2);
}

std::vector<int> PmergeMe::buildJacobsthalSequence(int size) const
{
    std::vector<int> sequence;
    int index = 3;

    while (true)
    {
        int jacob = generateJacobsthal(index);
        sequence.push_back(jacob);
        if (jacob > size)
            break;
        index++;
    }
    return sequence;
}

void PmergeMe::sortVector(std::vector<int>& arr)
{
    if (arr.size() < 2)
        return;

    bool hasStraggler = false;
    int straggler = 0;

    if (arr.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = arr.back();
        arr.pop_back();
    }

    std::vector< std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    std::vector<int> mainChain;
    std::vector<int> pending;

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainChain.push_back(pairs[i].first);
        pending.push_back(pairs[i].second);
    }

    sortVector(mainChain);

    std::vector<int> jacobSeq = buildJacobsthalSequence(pending.size());
    std::vector<int> insertionOrder;
    int lastJacob = 1;

    for (size_t i = 0; i < jacobSeq.size(); ++i)
    {
        int currentJacob = jacobSeq[i];
        int start = std::min(currentJacob, static_cast<int>(pending.size()));

        for (int j = start; j > lastJacob; --j)
            insertionOrder.push_back(j - 1);
        lastJacob = currentJacob;
    }

    for (size_t i = 0; i < insertionOrder.size(); ++i)
    {
        int idx = insertionOrder[i];
        int target = pending[idx];
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), target);
        mainChain.insert(it, target);
    }

    if (hasStraggler)
    {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }

    arr = mainChain;
}

void PmergeMe::sortDeque(std::deque<int>& arr)
{
    if (arr.size() < 2)
        return;

    bool hasStraggler = false;
    int straggler = 0;

    if (arr.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = arr.back();
        arr.pop_back();
    }

    std::deque< std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    std::deque<int> mainChain;
    std::deque<int> pending;

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainChain.push_back(pairs[i].first);
        pending.push_back(pairs[i].second);
    }

    sortDeque(mainChain);

    std::vector<int> jacobSeq = buildJacobsthalSequence(pending.size());
    std::vector<int> insertionOrder;
    int lastJacob = 1;

    for (size_t i = 0; i < jacobSeq.size(); ++i)
    {
        int currentJacob = jacobSeq[i];
        int start = std::min(currentJacob, static_cast<int>(pending.size()));

        for (int j = start; j > lastJacob; --j)
            insertionOrder.push_back(j - 1);
        lastJacob = currentJacob;
    }

    for (size_t i = 0; i < insertionOrder.size(); ++i)
    {
        int idx = insertionOrder[i];
        int target = pending[idx];
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), target);
        mainChain.insert(it, target);
    }

    if (hasStraggler)
    {
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }

    arr = mainChain;
}

void PmergeMe::execute(int argc, char **argv)
{
    try
    {
        parseInput(argc, argv);

        printSequence("Before: ", _vector);

        struct timeval start;
        struct timeval end;

        gettimeofday(&start, NULL);
        sortVector(_vector);
        gettimeofday(&end, NULL);
        _timeVector = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

        gettimeofday(&start, NULL);
        sortDeque(_deque);
        gettimeofday(&end, NULL);
        _timeDeque = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

        printSequence("After: ", _vector);

        std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << _timeVector << " us" << std::endl;
        std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << _timeDeque << " us" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error" << std::endl;
    }
}
