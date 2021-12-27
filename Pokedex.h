#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Pokedex.h"
#include "Eevee.h"
#include "Type.h"
#include "EvolveEevee.h"
using namespace std;

class Pokedex
{
private:
	vector<Pokemon*>PokeArr;
	string Trainer;

public:
	Pokedex();
	Pokedex(const string T);
	Pokedex(const Pokedex& P);
	~Pokedex();
	string getTrainerName() { return Trainer; };
	void setTrainerName(const string Trainer);
	void operator+=(Pokemon& p);
	void operator-=(Pokemon& p);
	Pokemon* PokeSearch(const string PokeName);
	friend ostream& operator<<(ostream& out, Pokedex& p);
};