#pragma once
#include <ostream>

class Card {
public:
    virtual ~Card() = 0;

    virtual int value() const = 0;

    virtual void print(std::ostream& os) const = 0;

    virtual bool operator<(const Card& other) const {
        return this->value() < other.value();
    }

    virtual bool operator==(const Card& other) const{
        return this->value() == other.value();
    }

    friend std::ostream& operator<<(std::ostream& os, const Card& card) {
        card.print(os);
        return os;
    }
};