#pragma once

# include <iostream>
# include <vector>
# include <deque>
# include <string>
# include <sys/time.h>
# include <cstdlib>
# include <stdexcept>
# include <algorithm>

class PmergeMe
{
private:
    std::vector<int> _vector;
    std::deque<int> _deque;
    double _timeVector;
    double _timeDeque;

    void parseInput(int argc, char **argv);
    void printSequence(const std::string& prefix, const std::vector<int>& seq) const;
    int generateJacobsthal(int n) const;
    std::vector<int> buildJacobsthalSequence(int size) const;

    void sortVector(std::vector<int>& arr);
    void sortDeque(std::deque<int>& arr);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& src);
    PmergeMe& operator=(const PmergeMe& src);
    ~PmergeMe();

    void execute(int argc, char **argv);
};
