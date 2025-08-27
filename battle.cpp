#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// ------------------- Weapon Class -------------------
class Weapon {
protected:
    string name;
    int damage;
    int accuracy; // percentage

public:
    Weapon(string n, int d, int a) : name(n), damage(d), accuracy(a) {}

    virtual ~Weapon() {}

    string getName() const { return name; }
    int getDamage() const { return damage; }

    // Determines if the attack hits
    bool hits() const {
        int roll = rand() % 100 + 1; // 1-100
        return roll <= accuracy;
    }
};

// ------------------- Character Class -------------------
class Character {
protected:
    string name;
    int health;
    vector<Weapon*> weapons;

public:
    Character(string n) : name(n), health(100) {}
    virtual ~Character() {
        for (auto w : weapons) delete w;
    }

    string getName() const { return name; }
    int getHealth() const { return health; }
    bool isAlive() const { return health > 0; }

    void addWeapon(Weapon* w) { weapons.push_back(w); }
    vector<Weapon*>& getWeapons() { return weapons; }

    void takeDamage(int dmg) {
        health -= dmg;
        if (health < 0) health = 0;
    }
};

// ------------------- Optimus Prime -------------------
class OptimusPrime : public Character {
public:
    OptimusPrime() : Character("Optimus Prime") {
        addWeapon(new Weapon("Ion Rifle", 6, 100));
        addWeapon(new Weapon("Energon Swords", 12, 80));
        addWeapon(new Weapon("Shoulder Cannon", 45, 25));
    }
};

// ------------------- Megatron -------------------
class Megatron : public Character {
public:
    Megatron() : Character("Megatron") {
        addWeapon(new Weapon("Fusion Cannon", 9, 90));
        addWeapon(new Weapon("Fusion Sword", 18, 70));
        addWeapon(new Weapon("Tank Mode", 60, 15));
    }
};

// ------------------- Fight Simulation -------------------
int main() {
    srand(time(0));
    OptimusPrime optimus;
    Megatron megatron;

    cout << "🔥 The Battle for Cybertron Begins! 🔥\n";
    cout << optimus.getName() << " vs " << megatron.getName() << "\n\n";

    while (optimus.isAlive() && megatron.isAlive()) {
        // ------------------- Optimus Turn -------------------
        cout << "\n" << optimus.getName() << "'s turn. Choose a weapon:\n";
        int i = 1;
        for (auto w : optimus.getWeapons()) {
            cout << i++ << ". " << w->getName() << " (Damage: " << w->getDamage() << ")\n";
        }

        int choice;
        cin >> choice;
        if (choice < 1 || choice > optimus.getWeapons().size()) {
            cout << "❌ Invalid choice, Optimus misses his turn!\n";
        } else {
            Weapon* weapon = optimus.getWeapons()[choice - 1];
            cout << optimus.getName() << " attacks with " << weapon->getName() << "...\n";

            if (weapon->hits()) {
                megatron.takeDamage(weapon->getDamage());
                cout << "✅ Hit! " << megatron.getName() << " takes " << weapon->getDamage()
                     << " damage.\n";
            } else {
                cout << "❌ Missed!\n";
            }
        }

        if (!megatron.isAlive()) break;

        // ------------------- Megatron Turn -------------------
        cout << "\n" << megatron.getName() << "'s turn. Choose a weapon:\n";
        i = 1;
        for (auto w : megatron.getWeapons()) {
            cout << i++ << ". " << w->getName() << " (Damage: " << w->getDamage() << ")\n";
        }

        cin >> choice;
        if (choice < 1 || choice > megatron.getWeapons().size()) {
            cout << "❌ Invalid choice, Megatron misses his turn!\n";
        } else {
            Weapon* weapon = megatron.getWeapons()[choice - 1];
            cout << megatron.getName() << " attacks with " << weapon->getName() << "...\n";

            if (weapon->hits()) {
                optimus.takeDamage(weapon->getDamage());
                cout << "✅ Hit! " << optimus.getName() << " takes " << weapon->getDamage()
                     << " damage.\n";
            } else {
                cout << "❌ Missed!\n";
            }
        }

        // ------------------- Show Health After Round -------------------
        cout << "\n--- Status After This Round ---\n";
        cout << optimus.getName() << " Health: " << optimus.getHealth() << "\n";
        cout << megatron.getName() << " Health: " << megatron.getHealth() << "\n";
        cout << "--------------------------------\n";
    }

    // ------------------- Winner -------------------
    cout << "\n⚡ The fight is over! ⚡\n";
    if (optimus.isAlive() && !megatron.isAlive())
        cout << "🏆 " << optimus.getName() << " wins with " << optimus.getHealth() << " health left!\n";
    else if (megatron.isAlive() && !optimus.isAlive())
        cout << "🏆 " << megatron.getName() << " wins with " << megatron.getHealth() << " health left!\n";
    else
        cout << "🤝 It's a draw! Both fighters are down.\n";

    return 0;
}
