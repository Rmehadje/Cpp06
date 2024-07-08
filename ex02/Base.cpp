/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:59:58 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/08 16:24:41 by rmehadje         ###   ########.fr       */
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

void		*Base::generate(){
	Base *(*f[3])() = {make_a, make_b, make_c};
	srand(time(0));
	return f[rand() % 3];
}

void	Base::identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void		Base::identify(Base &p){}
