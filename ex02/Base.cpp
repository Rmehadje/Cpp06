/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:59:58 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/09 10:57:25 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(){}


Base	*make_a(){
	return new A();
}
Base	*make_b(){
	return new B();
}
Base	*make_c(){
	return new C();
}

Base		*generate(){
	Base *(*f[3])() = {make_a, make_b, make_c};
	srand(static_cast<unsigned int>(time(0)));
	return f[rand() % 3]();
}

void	identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else{
		std::cout << "Not found." << std::endl;
	}
}

void		identify(Base &p){
	try{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch(std::exception &e){
		try{
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
			}
		catch(std::exception &e){
			try{
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch(std::exception &e)
			{
				std::cout << "not found" << std::endl;
			}
		}
	}
}
