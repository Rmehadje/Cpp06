/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:13:28 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/08 13:16:57 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Seriealizer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &cp){
	*this = cp;
}

Serializer &Serializer::operator=(const Serializer &og){
	return *this;
}

Serializer::~Serializer(){}

uintptr_t Serializer::seralize(Data *ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data Serializer::deseralize(Uintptr_t raw){
	return reinterpret_cast<Data *>(raw);
}