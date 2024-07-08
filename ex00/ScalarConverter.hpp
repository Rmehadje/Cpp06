/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:25:33 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/08 10:47:11 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <cstdlib>
#include <iostream>

class ScalarConverter{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &og);
		ScalarConverter &operator=(const ScalarConverter &cp);
	public:
		~ScalarConverter();
		static ScalarConverter&		getInstance();
		void		HandleInf();
		void		HandleNInf();
		void		HandleNan();
		void		Error(std::string error);
		int		Checker(std::string argv);
		void		converter(std::string str);
		void		toChar(std::string str);
		void		toInt(std::string str);
};