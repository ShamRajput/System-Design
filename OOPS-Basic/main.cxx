
#include <iostream>
#include <string>
#include <memory>
#include "PaymentService.hpp"
#include "CreditCard.hpp"
#include  "DebitCard.hpp"


using namespace std;
int main() {

     unique_ptr<PaymentService> ps = make_unique<PaymentService>();
     ps->addPaymentMethod("CreditCard",make_unique<CreditCard>("Shamkumar",12345678));
     ps->addPaymentMethod("DebitCard",make_unique<DebitCard>("Shamkumar",1234));   
     ps->makePayment("CreditCard");
     ps->makePayment("DebitCard");

    return 0;
}