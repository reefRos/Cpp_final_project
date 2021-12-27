#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define CLR_BFR fseek(stdin, 0, SEEK_SET);

class Pokemon
{
protected:
	string PokemonName;
	int HP;
	int Level;
	vector<string>PossibleTypes = {"Fire","Water","Ground","Electric","Ice"};

public:
	Pokemon();
	Pokemon(const string PokemonName, int HP, int Level);
	virtual ~Pokemon();
	string GetPokemonName() const { return PokemonName; };
	int GetHP() { return HP; };
	int GetLevel() { return Level; };
	void SetPokemonName(const string Name)throw(exception);
	void SetHP(int HP)throw(exception);
	void SetLevel(int Level)throw(exception);
	virtual void validateString(const string s);
	virtual void PokeInfo(ostream& out) = 0;
	friend ostream& operator<<(ostream& out, const Pokemon& P);
	virtual bool operator==(const Pokemon* p);
};