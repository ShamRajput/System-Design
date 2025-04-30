#ifndef CREDITCARD_HXX
#define CREDITCARD_HXX

#include <string>
#include <iostream>
#include "Card.hpp"
#include "PaymentMethod.hpp"


class CreditCard :public Card,public PaymentMethod
{
public:
    CreditCard(const std::string& inName, const size_t& inNumber );
    void pay() override;
};
#endif

