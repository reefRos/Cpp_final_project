#include <iostream>
#include <string>
#include "Pokemon.h"
using namespace std;

//Default constructor
Pokemon::Pokemon() : Level(1), HP(10), PokemonName("Pikachu")
{
}

//Constructor
Pokemon::Pokemon(const string PokemonName, int HP, int Level)
{
	this->SetPokemonName(PokemonName);
	this->SetHP(HP);
	this->SetLevel(Level);
}

//Distructor
Pokemon::~Pokemon()
{
}

//Checks if the entered string doesn't have number in it
void Pokemon::validateString(const string s)
{
	if (s.empty())
	{
		throw exception("Name can't be NULL");
		exit(0);
	}
	else {
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				throw exception("Name can't have a number in it");
				return;
			}
		}
		return;
	}
}

//Checks if the name entered is valid and sets it as the Pokemon's name
void Pokemon::SetPokemonName(const string Name) throw(exception)
{
	validateString(Name);
	this->PokemonName = Name;
}

//Checks if the number entered is not 0 or lower and sets it as the Pokemon's HP
void Pokemon::SetHP(int HP) throw(exception)
{
	if (HP <= 0)throw exception("Your Pokemon is fainted");
	else
		this->HP = HP;
}

//Checks if the number entered is not 0 or lower and sets it as the Pokemon's level
void Pokemon::SetLevel(int Level) throw(exception)
{
	if (Level <= 0)throw exception("Level can't be lower than 1");
	else
		this->Level = Level;
}

//Checks if the Pokemons are equal
bool Pokemon::operator==(const Pokemon* p)
{
	if ((this->Level == p->Level) && (this->PokemonName == p->PokemonName) && (this->HP == p->HP))
		return true;
	else
		return false;
}

//Prints the information of the Pokemon
ostream& operator<<(ostream& out, const Pokemon& P)
{
	out << endl << "Pokemon's name: " << P.PokemonName << endl << "HP: " << P.HP << endl << "Level: " << P.Level;
	return out;
}
