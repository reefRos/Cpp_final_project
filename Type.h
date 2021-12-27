#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Pokemon.h"
using namespace std;

typedef struct SpecialAttack
{
	string AttackName;
	int Damage;
};

class Type : public Pokemon
{
private:
	string TypeName;
	SpecialAttack S_attack;
	Type* Weakness;

public:
	Type();
	Type(int Damage, const string Sname, const string Pokename, int HP, int Level);
	Type(const Type& t);
	~Type() { delete Weakness; };
	string getTypeName() { return TypeName; }
	Pokemon* getWeakness() { return Weakness; }
	SpecialAttack getSpecialAttack() { return S_attack; }
	void setTypeName()throw(exception);
	void setSpecialAttack(int Damage, const string Sname);
	void setWeakness(Type* pokemons);
	void ReplaceSpecialAttack();
	void WhoWillWin(Type* pokemon);
	void Pokemon::PokeInfo(ostream& out);
	bool operator==(const Type* p);
};
