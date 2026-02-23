#ifndef ENEMY_CPP
#define ENEMY_CPP
#include "Enemy.h"
#include <iostream>
#include <string>
using namespace std;

Enemy::Enemy(string name, int challenge): Planet(name, challenge){}

string Enemy::GetType(){
    string enemy = "enemy";
    return enemy;
}

#endif