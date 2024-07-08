/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:25:19 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/08 10:47:32 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char* argv[])
{
  if (2 == argc) {
    ScalarConverter& convert = ScalarConverter::getInstance();
    try {
      convert.converter(argv[1]);
    }
    catch (const std::invalid_argument& e) {
      std::cerr << "Program recieved " << e.what() << std::endl;
    }
  }
  else {
    std::cerr << "Usage: ./scalarconverter [argument]" << std::endl;
  }
  return EXIT_SUCCESS;
}
