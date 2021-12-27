#include "Type.h"


//Default constructor
Type::Type() :TypeName("Electric")
{
	this->setSpecialAttack(1, "n/a");
	this->Weakness = NULL;
}

//Constructor
Type::Type(int Damage, const string Sname, const string PokemonName, int HP, int Level)
{
	this->SetPokemonName(PokemonName);
	this->SetHP(HP);
	this->SetLevel(Level);
	this->setSpecialAttack(Damage, Sname);
	this->setTypeName();
	this->Weakness = NULL;
}

//Copy constructor
Type::Type(const Type& t)
{
	this->SetPokemonName(t.PokemonName);
	this->SetHP(t.HP);
	this->SetLevel(t.Level);
	this->setSpecialAttack(t.S_attack.Damage, t.S_attack.AttackName);
	this->TypeName = t.TypeName;
	this->Weakness = t.Weakness;
}

//Get's the possible types for the Pokemon and let's the user pick a specific type
void Type::setTypeName()
{
	int idx = 0;
	int choice;
	cout << endl << "Press the number of your wanted Pokemon's type: " << endl;
	while (idx < this->PossibleTypes.size())
	{
		cout << idx + 1 << ") " << this->PossibleTypes[idx] << endl;
		idx++;
	}
	cin >> choice;
	if (choice<1 || choice>this->PossibleTypes.size())throw exception("Your choice must be a valid number");
	this->TypeName = PossibleTypes[choice - 1];
}

//Sets the Pokemon's special attack
void Type::setSpecialAttack(int Damage, const string Sname)
{
	this->S_attack.Damage = Damage;
	this->S_attack.AttackName = Sname;
}

//Gets another Pokemon and sets it as the used Pokemon's weakness
void Type::setWeakness(Type* weakness)
{
	this->Weakness = weakness;
}

//Replaces the current special attack
void Type::ReplaceSpecialAttack()
{
	int newdmg;
	string newName;
	cout << endl << "Enter new special attack name: ";
	CLR_BFR
		getline(cin, newName);
	cout << "Enter new damage value: ";
	cin >> newdmg;

	setSpecialAttack(newdmg, newName);
	cout << endl << "special attack has been replaced" << endl;
}

//Gets another Pokemon and checks who will win in a battle by having a higher attack's damage
void Type::WhoWillWin(Type* pokemon)
{
	if (this->S_attack.Damage < pokemon->S_attack.Damage)
		cout << this->PokemonName << " won't beat " << pokemon->PokemonName << endl;
	if (this->S_attack.Damage == pokemon->S_attack.Damage)
		cout << "It's a tie" << endl;
	if (this->S_attack.Damage > pokemon->S_attack.Damage)
		cout << this->PokemonName << " will beat " << pokemon->PokemonName << endl;
}

//Checks if the Pokemons are equal
bool Type::operator==(const Type* p)
{
	if (this == p)
		return true;
	else
		return false;
}

//Prints the information of the Pokemon
void Type::PokeInfo(ostream& out)
{
	out << *this << endl << "Pokemon's type: " << this->TypeName << endl << "Special attack and damage: " << this->S_attack.AttackName << ", " << this->S_attack.Damage << endl;
}


