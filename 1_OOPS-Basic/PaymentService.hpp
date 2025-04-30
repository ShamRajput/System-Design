#ifndef PAYMENT_SERVICE_HXX
#define PAYMENT_SERVICE_HXX

#include <string>
#include <memory>
#include <unordered_map>
#include "PaymentMethod.hpp"

class PaymentService
{
    private:
        std::unordered_map<std::string,std::unique_ptr<PaymentMethod>> ps;
    public:
    void addPaymentMethod(const std::string& type, std::unique_ptr<PaymentMethod>&& method );
    void makePayment(const std::string& type);

};

#endif

