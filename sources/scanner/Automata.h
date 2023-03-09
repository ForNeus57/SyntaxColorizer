//
// Created by Dominik on 08.03.2023.
//

#ifndef COMPILATION_THEORY_AND_COMPILERS_AUTOMATA_H
#define COMPILATION_THEORY_AND_COMPILERS_AUTOMATA_H

#define STATE_NUMBER 256

#include <array>		//	std:array<...>
#include <cstddef>		// 	std::size_t

#include "Token.h"

/**
 *
 */
class State {
public:
	State();
	State(char i);
public:
	int getNumber();
public:

private:
	static std::size_t count;
	std::size_t number;
	bool is_accepting;
};

/**
 * @param	current_state_number	-
 * @param	token_table				-
 */
class Automata {
public:
	Automata();
public:
	void changeState(char in);
	State getCurrentState();
	bool isInAcceptingState();
	std::size_t translateInputToAutomataTable(char in);
private:

public:
	const static std::size_t STARTING_STATE_NUMBER = 0;
private:
	std::size_t current_state_number;
	static std::array<Token, CODE_TYPE_SIZE> token_table = {
			{

			}
	};
	static std::array<char, CODE_TYPE_SIZE> input_to_state_number_converter;
	/**
	 *	The schema for this automata table:
	 *	State_number	|	Input '+'	|	Input '-'	|	Input '*'	|	Input '/'	|	Input '('	|	Input '('	|	Input 'Number'	|	Input 'character'
	 *	----------------|---------------|---------------|---------------|---------------|---------------|---------------|-------------------|--------------------
	 *	0 - Start		|	2		 	|				|				|				|				|				|					|
	 *	1 - Error		|	1			|	1			|	1			|	1			|	1			|	1			|	1				|	1
	 *	2 - Success '+'	|				|				|				|				|				|				|					|
	 *	3 - Success '-' |				|				|				|				|				|				|					|
	 */
	const std::array<std::array<std::size_t, STATE_NUMBER>, CODE_TYPE_SIZE> automata_table = {
		{
			{0,	0,	0,	0,	0,	0,	0,	0},
			{},
		}
	};
};


#endif //COMPILATION_THEORY_AND_COMPILERS_AUTOMATA_H
