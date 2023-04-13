//
// Created by Dominik on 09.03.2023.
//

#ifndef COMPILATION_THEORY_AND_COMPILERS_NOT_SUPPORTED_TOKEN_VALUE_FOR_TOKEN_CONSTRUCTOR_H
#define COMPILATION_THEORY_AND_COMPILERS_NOT_SUPPORTED_TOKEN_VALUE_FOR_TOKEN_CONSTRUCTOR_H

#include <exception>
#include <string>

class WrongInputAlphabet: public std::exception {
	public:
		explicit WrongInputAlphabet(const std::string& in) {
			this->message += "Error occurred while trying to scan next token: " + in + '\n';
		}
	public:
		const char* what () const noexcept override {
			return message.c_str();
		}
	private:
		std::string message = "Provided character is not supported by this model!\n"
							  "Additional info: ";
};


#endif	//	COMPILATION_THEORY_AND_COMPILERS_NOT_SUPPORTED_TOKEN_VALUE_FOR_TOKEN_CONSTRUCTOR_H
