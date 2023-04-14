/**
 * @file 	token.cpp
 * @version 0.027
 * @author 	Dominik Breksa, dominikbreksa@gmail.com
 * @date 	08.03.2023
 * @brief	Source file relating to Token class.
 * @see		token.h
**/


#include "../../../headers/model/token/token.h"


template class Token<std::string>;
template class Token<char>;
template class Token<int>;
template class Token<double>;


template<typename T>
Token<T>::Token(BaseToken::Codes type, ValueType val, std::size_t line, std::size_t column): BaseToken(type, line, column), value(std::move(val)) {}

template<>
Token<std::string>::operator std::string() const {
	std::string code_str = BaseToken::convertCodesToString(this->getCode());
	return "(code:" + code_str + ", value:" + this->value + ", line:" + std::to_string(this->getLine()) + ", col:" + std::to_string(this->getColumn()) + ")";
}
template<>
Token<char>::operator std::string() const {
	std::string code_str = BaseToken::convertCodesToString(this->getCode());
	return "(code:" + code_str + ", value:" + this->value + ", line:" + std::to_string(this->getLine()) + ", col:" + std::to_string(this->getColumn()) + ")";
}
template<>
Token<int>::operator std::string() const {
	std::string code_str = BaseToken::convertCodesToString(this->getCode());
	return "(code:" + code_str + ", value:" + std::to_string(this->value) + ", line:" + std::to_string(this->getLine()) + ", col:" + std::to_string(this->getColumn()) + ")";
}
template<>
Token<double>::operator std::string() const {
	std::string code_str = BaseToken::convertCodesToString(this->getCode());
	return "(code:" + code_str + ", value:" + std::to_string(this->value) + ", line:" + std::to_string(this->getLine()) + ", col:" + std::to_string(this->getColumn()) + ")";
}

template<typename T>
T Token<T>::getValue() const {
	return this->value;
}
template<typename T>
std::string Token<T>::print() const {
	return std::string(*this);
}
template<>
std::string Token<std::string>::printHTML() const {
	return "<pra style=\"color: " + this->getColour() +"\">" + this->value + "</pra>";
}
template<>
std::string Token<char>::printHTML() const {
	return "<pra style=\"color: " + this->getColour() +"\">" + this->value + "</pra>";
}
template<>
std::string Token<int>::printHTML() const {
	return "<pra style=\"color: " + this->getColour() +"\">" + std::to_string(this->value) + "</pra>";
}
template<>
std::string Token<double>::printHTML() const {
	return "<pra style=\"color: " + this->getColour() +"\">" + std::to_string(this->value) + "</pra>";
}