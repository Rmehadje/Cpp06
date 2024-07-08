/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:13:28 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/08 13:44:20 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &cp){
	*this = cp;
}

Serializer &Serializer::operator=(const Serializer &og){
	return *this;
}

Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data *ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deseralize(uintptr_t raw){
	return reinterpret_cast<Data *>(raw);
}

Serializer&	Serializer::getInstance(){
	static Serializer instance;
	return instance;	
}