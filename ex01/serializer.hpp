/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Seriealizer.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:35:40 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/08 13:12:02 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <cstdlib>
#include <stdint.h>
#include "Data.hpp"

struct data;

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer &cp);
		Serializer &operator=(const Serializer &og);
	public:
		~Serializer();
		static uintptr_t	serialize(data *ptr);
		static Data *deseralize(uintptr_t raw);
};