#include<iostream>
#include<string>

using namespace std;

class Hero
{
private:
    int health;
public:
    char *name;
    char level;

    Hero(int health){
        this -> health  = health;
    }

    Hero(int health, char level){
        this -> level = level ;
        this -> health = health;
    }

    Hero(Hero& temp){
        char *ch = new char[(temp.name).strlen + 1];
        strcpy(ch, temp.name)
    }

    int getHealth(){
        return health;
    }

    char getLevel(){
        return level;
    }

    void setHealth(int h){
        health = h;
    }

    void setLevel(char ch){
        level = ch;
    }

    void setName(char name[]){
        strcpy(this -> name, name);
    }


};

int main(){
    string str = "hello";
    int n = str.length();
    cout<<n;













    // // static allocation
    // Hero a;
    // a.setHealth(80);
    // a.setLevel('B');
    // cout <<"Health is " << a.level << endl;
    // cout << "level is " << a.getHealth() << endl;

    // // dynamically
    // Hero *b = new Hero;
    // b -> setLevel('A');
    // b -> setHealth(80);
    // cout <<"Health is " << (*b).level << endl;
    // cout << "level is " << (*b).getHealth() << endl;








    // // creation of object
    // Hero ramesh;
    // cout<< "Size of Ramesh is " << sizeof(ramesh) << endl;

    // cout << "Ramesh health is " << ramesh.getHealth() << endl;
    // //use setter
    // ramesh.setHealth(70);
    // ramesh.level = 'A';

    // cout << "health is: " << ramesh.getHealth() << endl;
    // cout << "Level is: " << ramesh.level << endl;
    
}