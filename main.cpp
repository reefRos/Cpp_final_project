#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Eevee.h"
#include "EvolveEevee.h"
#include "Pokedex.h"
#include "Pokemon.h"
#include "Type.h"

#define CLR_BFR fseek(stdin, 0, SEEK_SET);
using namespace std;


void AddPokemonToArr(Type* type, Eevee* eevee, EvolveEevee* Evolve, Pokedex* p)
{
	int choice, Dmg, HP, Level;
	string name, nickname, specialAttackName, specialTrait, itemToHold;
	do
	{
		cout << endl << "---------------------------" << endl;
		cout << endl << "Which kind of Pokemon would you like to add?" << endl;
		cout << "1) Normal type" << endl;
		cout << "2) Eevee type" << endl;
		cout << "3) Evolved Eevee type" << endl;
		cin >> choice;

		if (choice < 1 || choice>3)
			cout << "Unvalid number, please try again" << endl;
	} while (choice < 1 && choice>3);

	switch (choice)
	{
	case 1:
		cout << endl << "Press 1 to create your own Pokemon or any other number to create a default Pokemon ";
		cin >> choice;
		if (choice == 1)
		{
			
			cout << endl << "Enter the Pokemon's name: ";
			CLR_BFR
				getline(cin, name);
			cout << "Enter Pokemon's HP: ";
			cin >> HP;
			cout << "Enter Pokemon's level: ";
			cin >> Level;
			cout << "Enter Pokemon's special attack name: ";
			CLR_BFR
				getline(cin, specialAttackName);
			cout << "Enter Pokemon's special attack damage: ";
			cin >> Dmg;
			try
			{
				type = new Type(Dmg, specialAttackName, name, HP, Level);
				cout << endl << name << " Has been added to your Pokedex " << endl;
			}
			catch (exception exp)
			{
				cout << "ERROR PUTTING VALUES!" << endl;
				exit(0);
			}
		}
		if (choice != 1)
		{
			type = new Type();
			cout << endl << "Pikachu has been added to your Pokedex " << endl;
		}
		*p += *type;
		return;

	case 2:
		cout << endl << "Press 1 to create your own Eevee or any other number to create a default Pokemon ";
		cin >> choice;
		if (choice == 1)
		{
			cout << endl << "Enter Eevee's name: ";
			CLR_BFR
				getline(cin, name);
			cout << "Enter Eevee's HP: ";
			cin >> HP;
			cout << "Enter Eevee's level: ";
			cin >> Level;
			cout << "Enter Eevee's special trait: ";
			CLR_BFR
				getline(cin, specialTrait);
			cout << "Enter Eevee's nickname: ";
			getline(cin, nickname);
			try
			{
				eevee = new Eevee(nickname, specialTrait, name, HP, Level);
				cout << endl << name << " has been added to your Pokedex " << endl;
			}
			catch (exception exp)
			{
				cout << "ERROR PUTTING VALUES!" << endl;
				exit(0);
			}
		}
		if (choice != 1)
		{
			eevee = new Eevee();
			cout << endl << "Eevee has been added to your Pokedex " << endl;
		}
		*p += *eevee;
		return;
	case 3:
		cout << endl << "Press 1 to create your own Pokemon or any other number to create a default Pokemon ";
		cin >> choice;
		if (choice == 1)
		{
			cout << endl << "Enter Pokemon's name: ";
			CLR_BFR
				getline(cin, name);
			cout << "Enter Pokemon's HP: ";
			cin >> HP;
			cout << "Enter Pokemon's level: ";
			cin >> Level;
			cout << "Enter Pokemon's special trait: ";
			CLR_BFR
				getline(cin, specialTrait);
			cout << "Enter Eevee's nickname: ";
			getline(cin, nickname);
			cout << "Enter item that " << name << " holds: ";
			getline(cin, itemToHold);
			try
			{
				Evolve = new EvolveEevee(itemToHold, nickname, specialTrait, name, HP, Level);
				cout << endl << name << " has been added to your Pokedex " << endl;
			}
			catch (exception exp)
			{
				cout << "ERROR PUTTING VALUES!" << endl;
				exit(0);
			}
		}
		if (choice != 1)
		{
			Evolve = new EvolveEevee();
			cout << endl << "Flareon has been added to your Pokedex " << endl;
		}
		*p += *Evolve;
		return;
	}
}


void main()
{
	Pokedex* pokedex = new Pokedex();
	int amount, choice = 0;
	string trainer, p_name, PokemonToRelease;
	Eevee* eevee = NULL;
	EvolveEevee* evolve = NULL;
	Type* type = NULL;
	cout << "---------Welcome to your Pokedex!---------" << endl;
	cout << endl << "Please enter your name: ";
	getline(cin, trainer);
	pokedex->setTrainerName(trainer);
	cout << endl << "How many Pokemon's would you like to add to the pokedex? ";
	cin >> amount;
	for (int i = 0; i < amount; i++)
		AddPokemonToArr(type, eevee, evolve, pokedex);

	do
	{
		cout << endl << "---------------------------" << endl;
		cout << endl << "Choose an option: " << endl;
		cout << "1) Actions for specific Pokemon" << endl;
		cout << "2) Add Pokemon to Pokedex " << endl;
		cout << "3) Release a Pokemon " << endl;
		cout << "4) Print Pokedex " << endl;
		cout << "5) Exit " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			do
			{
				cout << endl << "---------------------------" << endl;
				cout << endl << "Enter the Pokemon's name you would like to use: ";
				CLR_BFR
					getline(cin, p_name);
				if (pokedex->PokeSearch(p_name) == NULL)
				{
					cout << "Couldn't find Pokemon's name";
					break;
				}

				if (strcmp(typeid(*(pokedex->PokeSearch(p_name))).name(), "class Type") == 0)
				{
					Type* ChosenPokemon = dynamic_cast<Type*>(pokedex->PokeSearch(p_name));
					cout << endl << "Please choose an option:" << endl;
					cout << "1) Replace special attack" << endl;
					cout << "2) Check who will in a battle" << endl;
					cout << "3) Add a weakness" << endl;
					cout << "0) Back to main menu" << endl;
					cin >> choice;

					switch (choice)
					{
					case 1:
						ChosenPokemon->ReplaceSpecialAttack();
						break;

					case 2:
						cout << endl << "Choose a Pokemon to battle with: ";
						CLR_BFR
							getline(cin, p_name);
						if (pokedex->PokeSearch(p_name))
						{
							if (strcmp(typeid(pokedex->PokeSearch(p_name)).name(), "class Type")==0)
								cout << "You must choose a normal type of Pokemon to compete with" << endl;
							else
							{
								Type* BattlePokemon = dynamic_cast<Type*>(pokedex->PokeSearch(p_name));
								if (ChosenPokemon == BattlePokemon)
									cout << "The Pokemon can't compete with itself" << endl;
								else
									ChosenPokemon->WhoWillWin(BattlePokemon);
							}
						}
						else
							cout << "Couldn't find the Pokemon" << endl;
						break;
					case 3:
						cout << endl << "Choose a Pokemon that " << ChosenPokemon->GetPokemonName() << " will be weak against: ";
						CLR_BFR
							getline(cin, p_name);
						if (pokedex->PokeSearch(p_name))
						{
							if (strcmp(typeid(*(pokedex->PokeSearch(p_name))).name(), "class Type"))
							{
								cout << "You must choose a normal type of Pokemon" << endl;
								break;
							}

							else
							{
								Type* WeakPokemon = dynamic_cast<Type*>(pokedex->PokeSearch(p_name));
								if (ChosenPokemon == WeakPokemon)
								{
									cout << "The Pokemon can't be weak to itself" << endl;
									break;
								}
								else
								{
									ChosenPokemon->setWeakness(WeakPokemon);
									cout << endl << ChosenPokemon->GetPokemonName() << " is now weak against " << WeakPokemon->GetPokemonName() << endl;
									break;
								}
							}
						}
						else
							cout << "Couldn't find the Pokemon" << endl;
						break;
					case 0:
						break;
					}
				}
				else if (strcmp(typeid(*(pokedex->PokeSearch(p_name))).name(), "class Eevee") == 0)
				{
					Eevee* ChosenPokemon = dynamic_cast<Eevee*>(pokedex->PokeSearch(p_name));
					cout << endl << "---------------------------" << endl;
					cout << endl << "Please choose an option:" << endl;
					cout << "1) Change Eevee's nickname" << endl;
					cout << "2) Train Eevee" << endl;
					cout << "0) Back to main menu" << endl;
					cin >> choice;

					switch (choice)
					{
					case 1:
						ChosenPokemon->ChangeNickName();
						cout << "Nickname has been changed" << endl;
						break;
					case 2:
						try
						{
							ChosenPokemon->TrainEevee();
						}
						catch (exception exp)
						{
							cout << "ERROR IN TRAIN EEVEE";
							exit(0);
						}
						break;
					case 0:
						break;
					}
				}
				else if (strcmp(typeid(*(pokedex->PokeSearch(p_name))).name(), "class EvolveEevee") == 0)
				{
					EvolveEevee* ChosenPokemon = dynamic_cast<EvolveEevee*>(pokedex->PokeSearch(p_name));
					cout << endl << "---------------------------" << endl;
					cout << endl << "Please choose an option:" << endl;
					cout << "1) Change special type" << endl;
					cout << "0) Back to main menu" << endl;
					cin >> choice;

					switch (choice)
					{
					case 1:
						try
						{
							ChosenPokemon->setSpecialType();
							cout << endl << "Special type has been replaced" << endl;
						}
						catch (exception exp)
						{
							cout << "ERROR IN SETTING SPECIAL TYPE";
							exit(0);
						}
						break;
					case 0:
						break;
					}
				}
			} while (choice != 0);
			break;
		case 2:
			AddPokemonToArr(type, eevee, evolve, pokedex);
			break;
		case 3:
			cout << endl << "Which Pokemon would you like to release? ";
			cin >> PokemonToRelease;
			if (pokedex->PokeSearch(PokemonToRelease))
			{
				*pokedex -= *pokedex->PokeSearch(PokemonToRelease);
				cout << PokemonToRelease << " was released " << endl;
			}
			else
				cout << "No such Pokemon exists " << endl;
			break;

		case 4:
			cout << *pokedex;
			break;
		case 5:
			cout << endl <<pokedex->getTrainerName()<< ", Thank you for using Pokedex! Hope to see you again soon! " << endl;
			delete pokedex;
			exit(0);

		}

	} while (choice != 5);




}

