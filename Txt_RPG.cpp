// Text_RPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::map; using std::copy;



class Character {
    //class created to store the values of the players character
public:
    string Class;
    float health;
    float attack;
    float armor;
   

 

};
class enemy {
    /*enemy class created with the type, health, armor and attack are initialised*/
public:
    
        string type;
        int health;
        int armor; 
        int attack;

 
    
};

int main()
{
    int player;
    string name;
    enemy ecreate;

    /* allows user to input a name*/
    Character create;
    cout << "Choose a character: \n" << "1: Wizard\n" << "2: Thief\n" << "3: Knight\n";
    cin >> player;
    cout << "What is your name?: ";
    cin >> name;

    /* If statments to help the user determine there class in which it creates values that where initialised in the character class*/
    if (player == 1) {
        
        create.Class = "Wizard";
        create.health = 20;
        create.attack = 35;
        create.armor = 5;

    }
    if (player == 2) {
        
        create.Class = "Knight";
        create.health = 30;
        create.attack = 10;
        create.armor = 30;

    }
    if (player == 3) {

        create.Class = "Thief";
        create.health = 20;
        create.attack = 50;
        create.armor = 5;

    }
    /* Dictionary used to keep track of the characters stats. Generally as the game goes on this will be constantly changing*/
    map<string,int> Player1 = 
    {
        {"health", create.health},
        {"attack", create.attack},
        {"armor",  create.armor}


    };
        
/* Lists out the stats of the character that has just been created*/
    cout << "Name: " << name << endl;
    cout << "health: " << create.health << endl;
    cout << "attack: " << create.attack << endl;
    cout << "armor: " << create.armor << endl;
    cout << "class: " << create.Class << endl;

    cout << "Story begins as "<< name << " a young " << create.Class << " sets off to travel the world in search of conquest and glory! \n " << "As they leave their hometown homeland they encounter a slime \n" ; 
   
    ecreate.health = 100;
    ecreate.armor = 10;
    ecreate.attack = 13;
  
    /* This creates a slime dictionary to help keep track of the values of the enemies created */
    map<string, int> slime = {

        {"health", ecreate.health},
        {"attack", ecreate.attack},
        {"armor",  ecreate.armor}

    };
    
    /* This while loop is going to be treated as a battle instance. As long as all the characters have health the while loop will continue*/
    
    while (create.health != 0){
        string choice;

        cout << "Do you attack y/n? \n";
        cin >> choice;
       // player has a choice of attacking. Once attacking the program takes into consideration armor and attack values previously made to determine how much health is lost"
        if (choice == "n") {
            create.health = create.health - ecreate.attack + create.armor;
            cout << "HEALTH: " << create.health << "SLIMES HEALTH: " << ecreate.health; //displays health for both parties as game continues
            cout << "The slime throws slime on you\n";
           
            // end the game when the layer is at less than 0 health
            if (create.health <= 0) {
                
                cout << "You weren't ready to leave the villiage and you died \n" << "============ GAME OVER ==============";
                break;
            }

        }
        else {
            ecreate.health = ecreate.health - create.attack + ecreate.armor;
            cout << "You attack the slime \n";
            cout << "HEALTH: " << create.health << "\n" << "SLIMES HEALTH: " << ecreate.health << endl;
           
            // ends the game if slime dies (only monster in the game so it makes sense)
            if (ecreate.health <= 0) {
                cout << "you beat it!!!\n" << "============ YOU WIN ==============";

                break;
            }
        }
        
    }
  
    
    
}


/* At the end of the day I am happy with the results, however, there are alot of changes that can be done. There is a lot of repetetive code as well un-needed function and methods being used. This was a fun project all in all and i might expand on it later*/
// I was also concidering about adding a fuction that writes the tet letter by letter for a cool effect