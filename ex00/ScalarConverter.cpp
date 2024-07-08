/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:57:06 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/08 12:05:40 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
	std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &og){
	*this = og;
}

ScalarConverter::~ScalarConverter(){}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &cp){
	return *this;
}

ScalarConverter&	ScalarConverter::getInstance(){
	static ScalarConverter instance;
	return instance;	
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

int		ScalarConverter::Checker(std::string str){
	int	flag = 0;
	int	fflag = 0;
	if (str.empty())
		return (Error("no input found"), 0);
	if (str == "inf" || str == "+inf")
		return (HandleInf(), 0);
	if (str == "-inf")
		return (HandleNInf(), 0);
	if (str == "nan" || str == "nanf")
		return (HandleNan(), 0);
	if (str.length() == 1)
	{
		if (!std::isdigit(str[0]))
			return 1;
	}
	for (int i = 0; i < str.length(); i++){
		if (str[i] == '-'){
			if (i != 0)
				return (Error(str), 0);
			i++;
		}
		if (!std::isdigit(str[i])){
			if (str[i] != '.' && str[i] != 'f')
				return (Error(str), 0);
			else{
				if (str[i] == '.'){
					if (i == (str.length() - 1) || i == 0)
						return (Error(str), 0);
					else
						flag++;
				}
				if (str[i] == 'f'){
					if (i == str.length() - 1 && str[i - 1] != '.')
						fflag++;
					else
						return (Error(str), 0);
				}
			}
			if (flag > 1 || fflag > 1)
				return (Error(str), 0);		
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



void	ScalarConverter::converter(std::string str){
	if(!Checker(str))
		return ;
	toChar(str);
	toInt(str);
	toFloat(str);
	toDouble(str);
}
void	ScalarConverter::toInt(std::string str){
	int i;
	if (str.length() == 1 && !std::isdigit(str[0])){
		i = static_cast <int>(str[0]);
		std::cout << "Int: " << i << std::endl;
		return ;
	}
	if (str.find(".") != std::string::npos){
		double d = strtod(str.c_str(), NULL);
		i = static_cast<int>(d);
		std::cout << "Int: " << i << std::endl;
		return ;
	}
	if (str.find("f") != std::string::npos){
		double d = strtod(str.c_str(), NULL);
		i = static_cast<int>(d);
		std::cout << "Int: " << i << std::endl;
		return ;
	}
	i = std::atoi(str.c_str());
	std::cout << "Int: " << i << std::endl;
	return ; 
}

void	ScalarConverter::toFloat(std::string str){
	float f;
	if (str.length() == 1 && !std::isdigit(str[0])){
		f = static_cast <float>(str[0]);
		std::cout << std::fixed << std::setprecision(2) << "Float: " << f << "f" << std::endl;
		return ;
	}
	if (str.find(".") != std::string::npos){
		double d = strtod(str.c_str(), NULL);
		f = static_cast<float>(d);
		std::cout << std::fixed << std::setprecision(2) << "Float: " << f << "f" << std::endl;
		return ;
	}
	if (str.find("f") != std::string::npos){
		double d = strtod(str.c_str(), NULL);
		f = static_cast<float>(d);
		std::cout << std::fixed << std::setprecision(2) << "Float: " << f << "f" << std::endl;
		return ;
	}
	f = std::atoi(str.c_str());
	std::cout << std::fixed << std::setprecision(2) << "Float: " << f << "f" << std::endl;
	return ; 
}

void	ScalarConverter::toDouble(std::string str){
	double d;
	if (str.length() == 1 && !std::isdigit(str[0])){
		d = static_cast <double>(str[0]);
		std::cout << std::fixed << std::setprecision(2) << "Double: " << d << std::endl;
		return ;
	}
	if (str.find(".") != std::string::npos){
		d = strtod(str.c_str(), NULL);
		std::cout << std::fixed << std::setprecision(2) << "Double: " << d << std::endl;
		return ;
	}
	if (str.find("f") != std::string::npos){
		d = strtod(str.c_str(), NULL);
		std::cout << std::fixed << std::setprecision(2) << "Double: " << d << std::endl;
		return ;
	}
	d = std::atoi(str.c_str());
	std::cout << std::fixed << std::setprecision(2) << "Double: " << d << std::endl;
	return ; 
}
