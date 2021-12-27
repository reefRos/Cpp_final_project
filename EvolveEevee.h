#pragma once
#include <iostream>
#include <string>
#include "Eevee.h"
using namespace std;

class EvolveEevee :public Eevee
{
private:
	string SpecialType;
	string ItemToHold;

public:
	EvolveEevee();
	EvolveEevee(const string ItemToHold, const string Nickname, const string Specialtrait, const string Pokename, int HP, int Level);
	~EvolveEevee();
	string getSpecialType() { return SpecialType; };
	string getItemToHold() { return ItemToHold; };
	void setSpecialType() throw(exception);
	void setItemToHold(const string ItemToHold) throw(exception);
	void Pokemon::PokeInfo(ostream& out);
};