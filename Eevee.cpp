#include "Eevee.h"

//Default constructor
Eevee::Eevee() :NickName("Cutie"), SpecialTrait("Flying"), Pokemon("Eevee", 10, 1)
{
}

//Constructor
Eevee::Eevee(const string NickName, const string SpecialTrait, const string PokemonName, int HP, int Level)
{
	this->SetPokemonName(PokemonName);
	this->SetHP(HP);
	this->SetLevel(Level);
	this->setNickName(NickName);
	this->setSpecialTrait(SpecialTrait);
}

//Copy constructor
Eevee::Eevee(const Eevee& e)
{
	this->SetPokemonName(e.PokemonName);
	this->SetHP(e.HP);
	this->SetLevel(e.Level);
	this->setNickName(e.NickName);
	this->setSpecialTrait(e.SpecialTrait);
}

//Distructor
Eevee::~Eevee()
{
}

//Checks if the nickname entered is valid and sets it as Eevee's nickname
void Eevee::setNickName(const string NickName) throw(exception)
{
	Pokemon::validateString(NickName);
	this->NickName = NickName;
}

//Checks if the string entered is valid and sets it as Eevee's special trait
void Eevee::setSpecialTrait(const string SpecialTrait) throw(exception)
{
	Pokemon::validateString(SpecialTrait);
	this->SpecialTrait = SpecialTrait;
}

//Changes Eevee's nickname
void Eevee::ChangeNickName()
{
	string tmp;
	cout<<endl << "Please enter the new nickname: ";
	CLR_BFR
		getline(cin, tmp);
	setNickName(tmp);
}

//Training Eevee and raises it's level
void Eevee::TrainEevee() throw(exception)
{
	int AddLevel;
	cout<<endl << "For how many levels would you like to train " << this->PokemonName << "? ";
	cin >> AddLevel;
	if (AddLevel < 0)
		throw exception("Level cannot be a negative numebr");
	this->Level += AddLevel;
	cout << "The new level is: " << this->Level << endl;
}

//Checks if the Pokemons are equal
bool Eevee::operator==(const Eevee* p)
{
	if (this == p)
		return true;
	else
		return false;
}

//Prints Eevee's information
void Eevee::PokeInfo(ostream& out)
{
	out << *this << endl << "Nickname: " << this->NickName << endl << "Special Trait: " << this->SpecialTrait << endl;
}
