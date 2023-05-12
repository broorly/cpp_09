/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:38:11 by mrafik            #+#    #+#             */
/*   Updated: 2023/05/12 21:18:55 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _size(0), _sorted(0)
{
	return ;
}

PmergeMe::PmergeMe(int argc, char **argv) : _size(argc - 1), _sorted(0)
{
	_vector = parseArgsVector(argc,argv);
	_deque = parseArgsDeque(argc,argv);
	printBeforeAfter();
	double tBegin = getTime();
	mergeInsertSort(_vector);
	_deltaTimeVector = deltaTime(tBegin);

	tBegin = getTime();
	mergeInsertSort(_deque);
	_deltaTimeDeque = deltaTime(tBegin);

	_sorted = true;
	printBeforeAfter();

	printTime("vector");
	printTime("deque");
	return;
}
PmergeMe::PmergeMe(const PmergeMe& obj)
{
	*this = obj;
	return;
}

PmergeMe::~PmergeMe(void)
{
	return;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& Pmer)
{
	if (this != &Pmer)
	{
		this->_size = Pmer._size;
		this->_sorted = Pmer._sorted;
		this->_vector = Pmer._vector;
		this->_deque = Pmer._deque;
		this->_deltaTimeVector = Pmer._deltaTimeVector;
		this->_deltaTimeDeque = Pmer._deltaTimeDeque;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const PmergeMe& Pmer)
{
	out << "Vector delta time: " << Pmer.getVectorDeltaTime() << std::endl
		<< "Deque delta time: " << Pmer.getDequeDeltaTime();
	return out;
}

double	PmergeMe::getVectorDeltaTime(void) const
{
	return (this->_deltaTimeVector);
}

double	PmergeMe::getDequeDeltaTime(void) const
{
	return (this->_deltaTimeDeque);
}

std::vector<int> PmergeMe::parseArgsVector(int argc, char **argv)
{
	std::vector<int>	args;
	int value;
	std::string arg;
	for (int i = 1; i < argc; ++i)
	{
		arg = argv[i];
		value = atoi(arg.c_str());
		if (value < 0)
			throw invalidArgumentError();
		args.push_back(value);
	}
	return (args);
}

std::deque<int> PmergeMe::parseArgsDeque(int argc, char **argv)
{
	std::deque<int>	args;
	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		int value = atoi(arg.c_str());
		if (value < 0)
			throw invalidArgumentError();
		args.push_back(value);
	}
	return (args);
}

void PmergeMe::verifyDuplicates(void)
{
	std::set<int> numSet;
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); ++it) {
		int num = *it;
		if (numSet.find(num) != numSet.end())
			throw duplicatesError();
		numSet.insert(num);
	}
}

template <typename T>
void	PmergeMe::mergeInsertSort(T& container)
{
	int d = 16;
	int size = container.size();
	if (size < 2)
		return ;
	if (size < d)
	{
		for (typename T::iterator i = container.begin(); i != container.end(); ++i)
		{
			typename T::iterator j = i;
			while (j != container.begin() && *(j - 1) > *j)
			{
				std::swap(*j, *(j - 1));
				--j;
			}
		}
		return ;
	}
	typename T::iterator middle = container.begin() + size / 2;
	T up(container.begin(), middle);
	T down(middle, container.end());
	mergeInsertSort(up);
	mergeInsertSort(down);
	typename T::iterator i = up.begin();
	typename T::iterator j = down.begin();
	typename T::iterator all = container.begin();
	while (i != up.end() && j != down.end())
	{
		if (*i < *j)
		{
			*all = *i;
			++i;
		}
		else
		{
			*all = *j;
			++j;
		}
		++all;
	}
	while (i != up.end())
	{
		*all = *i;
		++i;
		++all;
	}
	while (j != down.end())
	{
		*all = *j;
		++j;
		++all;
	}
}

double	PmergeMe::getTime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

double	PmergeMe::deltaTime(long long time)
{
	if (time > 0)
		return (getTime() - time);
	return (0);
}

void	PmergeMe::printBeforeAfter(void)
{
	if (_sorted == false)
		std::cout << "Before: ";
	else
		std::cout << "After:  ";
	std::vector<int>::iterator it = _vector.begin();
	std::vector<int>::iterator ite = _vector.end();
	while (it != ite)
	{
		std::cout << " " << *it;
		++it;
	}
	std::cout << std::endl;
}

void	PmergeMe::printTime(std::string vectorDeque) const
{
	double delta;
	if (vectorDeque == "vector")
		delta = _deltaTimeVector;
	else if (vectorDeque == "deque")
		delta = _deltaTimeDeque;
	else{
		std::cout<<"ERROR type of countainer!!\n";
		return;
	}
	std::cout 
		<< "Time to process a range of " << _size 
		<< " elements with std::" << vectorDeque << ": " << delta * 1000 << " us" << std::endl;
}
