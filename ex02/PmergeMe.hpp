/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:38:14 by mrafik            #+#    #+#             */
/*   Updated: 2023/05/13 17:50:33 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <sys/time.h>
#include <vector>
#include <deque>
#include <set>
#include <cctype>

class PmergeMe
{
	private:
		int					_size;
		bool				_sorted;
		std::vector<int>	_vector;
		std::deque<int>		_deque;
		double				_deltaTimeVector;
		double				_deltaTimeDeque;
	public:
		PmergeMe(void);
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe& obj);
		virtual ~PmergeMe(void);

		double	getVectorDeltaTime(void) const;
		double	getDequeDeltaTime(void) const;

		PmergeMe&	operator=(const PmergeMe& obj);


		std::vector<int>	parseArgsVector(int argc, char **argv);
		std::deque<int>		parseArgsDeque(int argc, char **argv);

		void				verifyDuplicates(void);

		void				printBeforeAfter(void);
		void				printTime(std::string vectorDeque) const;

		template <typename T>
		void				mergeInsertSort(T& container);
	
		double				getTime(void);
		double				deltaTime(long long time);

        class invalidArgumentError : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: invalid arguments");
				}
		};

		class duplicatesError : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: duplicates data");
				}
		};
};