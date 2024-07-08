/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:32:45 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/08 15:15:53 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>


class Base{
	public:
	virtual	~Base();
	void		*generate();
	void		identify(Base* p);
	void		identify(Base& p);
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *make_a();
Base *make_b();
Base *make_c();