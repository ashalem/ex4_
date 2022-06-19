

#include <stdbool.h>
#include <string>
#include <iostream>

#include "Player.h"
#include "../Exception.h"

bool Player::isValidName(std::string name){

    int name_length = name.length();
    if(name_length > 15){
        return 0;
    }

    for (int chr = 0; chr < name_length; chr++){
        if(!std::isalpha(name[chr])){
            return 0;
        }
    }

    return 1;
}

Player::Player(std::string name) :
    m_name(name),
    m_maxHp(defaultMaxHp),
    m_force(defaultForce),
    m_HP(defaultMaxHp),
    m_level(startingLevel),
    m_coins(startingCoins) {

        if(!(isValidName(name))){
            throw InvalidNameInput(std::string("Invalid name input of the player."));
        }
    }

void Player::levelUp() {
    if (this->m_level < maxLevel) {
        this->m_level++;
    }
}

int Player::getLevel() const {
    return this->m_level;
}

void Player::buff(const int buffPoints) {
    //assert(buffPoints > 0);
    if (buffPoints <= 0) {
        return;
    }
    this->m_force += buffPoints;
}

void Player::debuff(const int buffPoints) {
    //assert(buffPoints > 0);
    if (buffPoints <= 0) {
        return;
    }
    this->m_force -= buffPoints;
    this->m_force = this->m_force > 0? this->m_force : 0;
}

void Player::heal(const int healPoints) {
    //assert(healPoints > 0);
    if (healPoints <= 0) {
        return;
    }

    this->m_HP += healPoints;
    this->m_HP = this->m_HP < this->m_maxHp ? this->m_HP : this->m_maxHp;
}

void Player::damage(const int damagePoints) {
    //assert(damagePoints > 0);
    if (damagePoints <= 0) {
        return;
    }

    this->m_HP -= damagePoints;
    this->m_HP = this->m_HP > 0 ? this->m_HP : 0;
}

void Player::knockOut() {
    this->m_HP = 0;
}

bool Player::isKnockedOut() const {
    return this->m_HP == 0;
}

void Player::addCoins(const int coinsToAdd) {
    //assert(coinsToAdd > 0);
    if (coinsToAdd <= 0) {
        return;
    }

    this->m_coins += coinsToAdd;
}

bool Player::pay(const int coinsToPay) {
    //assert(coinsToPay > 0);
    if (coinsToPay <= 0) {
        return true;
    }

    if (this->m_coins < coinsToPay) {
        return false;
    }

    this->m_coins -= coinsToPay;
    return true;
}

int Player::getAttackStrength() const {
    return this->m_force + this->m_level;
}

std::ostream& operator<<(std::ostream& os, const Player& player) {
    player.printClassPlayerDetails(os);
    return os;
}

std::string Player::getName() const {
    return this-> m_name;
}

int Player::getHp() const {
    return this->m_HP;
}

int Player::getCoins() const {
    return this->m_coins;
}

int Player::getForce() const {
    return this->m_force;
}
