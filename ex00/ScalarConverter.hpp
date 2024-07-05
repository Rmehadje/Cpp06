/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:25:33 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/05 17:41:19 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <cstdlib>
#include <iostream>

class ScalarConverter{
	private:
		char			c;
		int			i;
		float			f;
		double		d;
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &og);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &cp);
		void		HandleInf();
		void		HandleNInf();
		void		HandleNan();
		void		Error(std::string error);
		int		Checker(std::string argv);
};