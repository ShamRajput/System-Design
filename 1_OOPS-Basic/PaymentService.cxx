#include "PaymentService.hpp"

void PaymentService::addPaymentMethod(const std::string &type, std::unique_ptr<PaymentMethod>&& method)
{
    if(auto itr =ps.find(type); itr==ps.end()) {
        ps[type] = std::move(method);
    }
}

void PaymentService::makePayment(const std::string &type)
{
    if(auto itr =ps.find(type); itr!=ps.end()) {
        itr->second->pay();
    }
}
