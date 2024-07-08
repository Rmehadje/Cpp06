/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:12:35 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/08 13:43:01 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main (){
	Serializer &ser = Serializer::getInstance();
	Data *ptr;
	Data p;
	uintptr_t	seri;
	
	p.content = "HELLO";

	seri = ser.serialize(&p);
	std::cout << seri << std::endl;
	ptr = ser.deseralize(seri);
	std::cout << ptr->content << std::endl;
}