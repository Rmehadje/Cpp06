/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:32:45 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/09 10:51:11 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>


class Base{
	public:
	virtual	~Base();
};

void		identify(Base* p);
void		identify(Base& p);
Base		*generate();
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *make_a();
Base *make_b();
Base *make_c();