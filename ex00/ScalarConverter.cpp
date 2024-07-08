/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:57:06 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/08 10:10:00 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
	this->c = '\0';
	this->i = 0;
	this->f = 0.0f;
	this->d = 0.0;
}

ScalarConverter::ScalarConverter(const ScalarConverter &og){
	*this = og;
}

ScalarConverter::~ScalarConverter(){}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &cp){
	return *this;
}


void		ScalarConverter::Error(std::string error){
	std::cerr << "Wrong input: " << error << std::endl;
}

void		ScalarConverter::HandleInf(){
	std::cout << "Char: impossible" << std::endl;
	std::cout << "Int: impossible" << std::endl;
	std::cout << "Float: inff" << std::endl;
	std::cout << "Char: inf" << std::endl;
}
void		ScalarConverter::HandleNInf(){
	std::cout << "Char: impossible" << std::endl;
	std::cout << "Int: impossible" << std::endl;
	std::cout << "Float: -inff" << std::endl;
	std::cout << "Char: -inf" << std::endl;
}
void		ScalarConverter::HandleNan(){
	std::cout << "Char: impossible" << std::endl;
	std::cout << "Int: impossible" << std::endl;
	std::cout << "Float: nanf" << std::endl;
	std::cout << "Char: nan" << std::endl;	
}

int		ScalarConverter::Checker(std::string argv){
	int	flag = 0;
	int	fflag = 0;
	if (argv.empty())
		return (Error("no input found"), 0);
	if (argv == "inf" || argv == "+inf")
		return (HandleInf(), 0);
	if (argv == "-inf")
		return (HandleNInf(), 0);
	if (argv == "nan" || argv == "nanf")
		return (HandleNan(), 0);
	if (argv.length() == 1)
	{
		if (!std::isdigit(argv[0]))
			return 1;
	}
	for (int i = 0; i < argv.length(); i++){
		if (argv[i] == '-'){
			if (i != 0)
				return (Error(argv), 0);
			i++;
		}
		if (!std::isdigit(argv[i])){
			if (argv[i] == '.' && argv[i] != 'f')
				return (Error(argv), 0);
			else{
				if (argv[i] == '.'){
					if (i == (argv.length() - 1) || i == 0)
						return (Error(argv), 0);
					else
						flag++;
				}
				if (argv[i] == 'f'){
					if (i == argv.length() - 1 && argv[i - 1] == '.')
						fflag++;
					else
						return (Error(argv), 0);
				}
			}
			if (flag > 1 || fflag > 1)
				return (Error(argv), 0);		
		}
	}
	return 1;
}


void	ScalarConverter::toChar(std::string str){
	char c;
	if (str.length() == 1 && !std::isdigit(str[0])){
		c = static_cast <char>((int)str[0]);
		std::cout << "Char: " << c << std::endl;
		return ;
	}
	if (str.find(".") != std::string::npos){
		double d = strtod(str.c_str(), NULL);
		if (d < 32 || d > 127){
			std::cout << "Char: Non Displayable" << std::endl;
			return ;
		}
		c = static_cast<char>(d);
		std::cout << "Char: " << c << std::endl;
		return ;
	}
	if (str.find("f") != std::string::npos){
		double d = strtod(str.c_str(), NULL);
		if (d < 32 || d > 127){
			std::cout << "Char: Non Displayable" << std::endl;
			return ;
		}
		c = static_cast<char>(d);
		std::cout << "Char: " << c << std::endl;
		return ;
	}
	int j = std::atoi(str.c_str());
	if (j < 32 || j > 127){
		std::cout << "Char: Non Displayable" << std::endl;
		return ;
	}
	c = static_cast<char>(j);
	std::cout << "Char: " << c << std::endl;
	return ; 
}
