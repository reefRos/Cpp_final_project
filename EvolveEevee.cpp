#include "EvolveEevee.h"

//Default constructor
EvolveEevee::EvolveEevee() :SpecialType("Fire"), ItemToHold("Coin"), Eevee("Flary", "Flamethrower", "Flareon", 50, 70)
{
}

//Constructor
EvolveEevee::EvolveEevee(const string ItemToHold, const string Nickname, const string SpecialTrait, const string PokemonName, int HP, int Level)
{
	this->SetPokemonName(PokemonName);
	this->SetHP(HP);
	this->SetLevel(Level);
	this->setNickName(Nickname);
	this->setSpecialTrait(SpecialTrait);
	this->setSpecialType();
	this->setItemToHold(ItemToHold);
}

//Distructor
EvolveEevee::~EvolveEevee()
{
}

//Get's the possible types for the Pokemon and let's the user pick a specific type
void EvolveEevee::setSpecialType() throw(exception)
{
	int idx = 0;
	int choice;
	cout << "Choose a special type for Eevee: " << endl;
	while (idx < this->PossibleTypes.size())
	{
		cout << idx + 1 << ") " << this->PossibleTypes[idx] << endl;
		idx++;
	}
	cin >> choice;
	if (choice<1 || choice>this->PossibleTypes.size())throw exception("Your choice must be a valid number");
	this->SpecialType = PossibleTypes[choice - 1];
}

//Checks if the string entered is valid and sets it as the 
void EvolveEevee::setItemToHold(const string ItemToHold) throw(exception)
{
	validateString(ItemToHold);
	this->ItemToHold = ItemToHold;
}

//Prints the Pokemon's information
void EvolveEevee::PokeInfo(ostream& out)
{
	out << *this << endl <<  "Nickname: " << this->NickName << endl << "Special trait: " << this->SpecialTrait << endl << "Special type: " << this->SpecialType << endl << this->PokemonName << " is holding " << this->ItemToHold << endl;
}
