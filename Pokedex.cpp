#include "Pokedex.h"

//Default constructor
Pokedex::Pokedex() :Trainer("Unknown")
{
}

//Constructor
Pokedex::Pokedex(const string T)
{
	this->setTrainerName(T);
}

//Copy contructor
Pokedex::Pokedex(const Pokedex& P)
{
	this->setTrainerName(P.Trainer);
}

//Distrcutor
Pokedex::~Pokedex()
{
}

//Gets a string and sets it as the trainer's(the user) name
void Pokedex::setTrainerName(const string Trainer)
{
	this->Trainer = Trainer;
}

//Adds a Pokemon to the vector
void Pokedex::operator+=(Pokemon& p)
{
	if (strcmp(typeid(p).name(), "class Type")==0)
	{
		Type* tmp = dynamic_cast<Type*>(&p);
		this->PokeArr.push_back(&p);
	}
	if (strcmp(typeid(p).name(), "class Eevee")==0)
	{
		Eevee* tmp = dynamic_cast<Eevee*>(&p);
		this->PokeArr.push_back(&p);
	}

	if (strcmp(typeid(p).name(), "class EvolveEevee")==0)
	{
		EvolveEevee* tmp = dynamic_cast<EvolveEevee*>(&p);
		this->PokeArr.push_back(&p);
	}
}

//Erase a Pokemon from the vector
void Pokedex::operator-=(Pokemon& p)
{
	vector<Pokemon*>::iterator index;
	for (index = PokeArr.begin(); index != PokeArr.end(); index++)
	{
		if (*index == &p)
		{
			PokeArr.erase(index);
			return;
		}
	}
}

//Gets a Pokemon's name and checks if it exists in the vector
Pokemon* Pokedex::PokeSearch(const string PokeName)
{
	vector<Pokemon*>::iterator index;
	for (index = PokeArr.begin(); index != PokeArr.end(); index++)
	{
		if ((*index)->GetPokemonName() == PokeName)
			return *index;
	}
	return NULL;
}

//Prints the Pokedex
ostream& operator<<(ostream& out, Pokedex& p)
{
	if (p.PokeArr.empty())
	{
		cout << "Your pokedex is empty";
		return out;
	}
	else
	{
		for (int i = 0; i < p.PokeArr.size(); i++)
			p.PokeArr[i]->PokeInfo(out);
	}
}
