#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Pokemon.h"
using namespace std;

class Eevee :public Pokemon
{
protected:
	string NickName;
	string SpecialTrait;

public:
	Eevee();
	Eevee(const string NickName, const string SpecialTrait, const string PokeName, int HP, int Level);
	Eevee(const Eevee& e);
	~Eevee();
	string getNickName() { return NickName; }
	string getSpecialTrait() { return SpecialTrait; }
	void setNickName(const string NickName) throw(exception);
	void setSpecialTrait(const string SpecialTrait) throw(exception);
	void ChangeNickName();
	void TrainEevee() throw(exception);
	void Pokemon::PokeInfo(ostream& out);
	bool operator==(const Eevee* p);
};