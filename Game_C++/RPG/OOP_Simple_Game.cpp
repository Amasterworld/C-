// OOP_Simple_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <string_view> // std::string_view requires C++17
#include <array>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <random>

// Generate a random number between min and max (inclusive)
// Assumes std::srand() has already been called
// Assumes max - min <= RAND_MAX

int getRandomNumber(int min, int max)
{
	static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) }; // static used for efficiency, so we only calculate this value once
	// evenly distribute the random number across our range
	return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}


class Creature {

protected:
	std::string name{};
	char symbol{};
	int health{};
	int damage{};
	int gold{};
public:

	//constructor
	Creature(std::string_view name, char symbol, int health, int damage, int gold) : name(name), symbol(symbol), health(health), damage(damage),gold(gold) {
		//std::cout << name << " is created" << std::endl;
	}
	~Creature(){}

	//function
	const std::string& getName() const {
		return name;
	}
			
	const char& getSymbol() const {
		return symbol;
	}
	
	const int& getGold() const {
		return gold;
	}

	const int& getHealth() const {
		return health;
	}
	
	const int& getDamage() const {
		return damage;
	}

	void addGold(int value_gold) {
		gold += value_gold;
	}
	
	void reduceHealth(int reduce_health) {
		health -= reduce_health;
	}

	bool isDead() {
		return health <= 0;
	}
	
};



class Player : public Creature {
	
private:
	int player_level{ 1 };
public:
	Player(std::string_view player_name) : Creature(player_name, '@', 20, 5, 0) {
		
	}

	void levelUp() {
		player_level++;
		std::cout << "Congratulations, you are now level " << player_level << std::endl;
		damage++;		
	}
	// getter
	const int& getPlayerLevel() const {
		return player_level;
	}

	bool hasWon() {
		if (player_level >= 20) return true;
		else return false;
	}

};



class Monster : public Creature {
public:
	
	enum class Type { dragon, orc, slime, max_type };

private:
	//create a table to contain  an elements for each monster.  Monster attributes are predefined (not random). -->use lookup table
	static const Creature& getDefaultCreature(Type type){
		static const std::array<Creature, static_cast<std::size_t>(Type::max_type)> monsterData{ // create a static array of Creature with size of max_type
			// normally array<int, 3> = {1,2,3}, max_type is not a constant, so we need to use static_cast<std::size_t>(Type::max_type) to converit to + integer number
		  { { "dragon", 'D', 20, 4, 100 },
			{ "orc", 'o', 4, 2, 25 },
			{ "slime", 's', 1, 1, 10 } }
		};

		return monsterData[static_cast<std::size_t>(type)]; // now for example the type is orc, we need to conver to integer number 1, monterData.at(1) return { "orc", 'o', 4, 2, 25 },
		// or return monsterData.at(static_cast<std::size_t>(type))
	}
public:
	// delegating constructor
	Monster(Type type) : Creature(getDefaultCreature(type)){}

	static Monster getRandomMonster()
	{
		int num{ getRandomNumber(0, static_cast<int>(Type::max_type) - 1) };
		return Monster{ static_cast<Type>(num) };
	}
};

void attackingPlayer(Monster& m, Player& p) {
	std::cout << "you are fighting with " << m.getName() << std::endl;
	char choice{};
	do {
		std::cout << "(R)un or (F)ight" << std::endl;
		std::cin >> choice;
		std::cin.ignore(32767, '\n'); // ignore the char excep y and n
	} while (choice != 'R' && choice != 'F');
	
	if (choice == 'R') {
		// the player has 50% to escape
		if (getRandomNumber(0, 1) == 1) {
			std::cout << "Congrat escaped" << std::endl;
			return;
		}
		else {
			std::cout << "you are suffering free attack from monter because of your coward " << std::endl;
			
			p.reduceHealth(m.getDamage());
			while (m.isDead() == false && p.isDead() == false) {
				std::cout<< "Your current Health is " << p.getHealth() << std::endl;
				
				// counter attack
				std::cout << "You hit the " << m.getName() << " with the damage " << p.getDamage() << std::endl;
				m.reduceHealth(p.getDamage());
				if (m.isDead()) {
					//player increase lv and loot gold
					std::cout << "You killed the " << m.getName() << std::endl;
					p.addGold(m.getGold());
					p.levelUp();
					break;

				}
				else {
					p.reduceHealth(m.getDamage());
				}
			}
		}
	}
	else if (choice == 'F') {
		while (m.isDead() == false || p.isDead() == false) {
			std::cout << "Your current Health is " << p.getHealth() << std::endl;
			
			// player attack
			m.reduceHealth(p.getDamage());
			if (m.isDead()) {
				//player increase lv and loot gold
				p.addGold(m.getGold());
				p.levelUp();
				break;
			}
			else {
				p.reduceHealth(m.getDamage());
			}

			// counter attack
			p.reduceHealth(m.getDamage());
			if (p.isDead()) {
				std::cout<<" You are dead"<<std::endl;
				std::cout << " Your currtent gold is "<<p.getGold() << std::endl;
				break;
			}
		}
	}
		
	
}


int main(){
	
	std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
	std::rand(); // get rid of first result
	std::cout << "Enter your name: ";
	std::string player_name;
	std::cin >> player_name;
	std::cout << "Welcome, " << player_name << std::endl;
	Player p(player_name);

	std::cout << "You are " << p.getName() << ", have " << p.getHealth() << " health and are carrying " << p.getGold() << " gold." << std::endl;

	//std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
	//std::rand(); // get rid of first result

	while(p.isDead() == false && p.hasWon() == false){
		//std::cout << "you has won ? " << p.hasWon() << std::endl;
		Monster m{ Monster::getRandomMonster() };
		std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
		attackingPlayer(m, p);
		
	}
	
	if (p.hasWon()) {
		std::cout << "you won the game with the current gold is " << p.getGold() << std::endl;
	}
	return 0;



	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

