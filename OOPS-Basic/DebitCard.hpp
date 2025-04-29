#ifndef DEBITCARD_HXX
#define DEBITCARD_HXX

#include <string>
#include <iostream>
#include "Card.hpp"
#include "PaymentMethod.hpp"


class DebitCard :public Card,public PaymentMethod
{
public:
   DebitCard(const std::string& inName, const size_t& inNumber );
   void pay() override;
};
#endif

