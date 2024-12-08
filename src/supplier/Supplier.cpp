#include "./Supplier.h"
#include "../organization/Organization.h"

Supplier::Supplier(const std::string &name) : name(name) {}

const std::string &Supplier::getName() const
{
    return name;
}

void Supplier::subscribeToOrganization(Organization *org)
{
    if (!isSubscribed)
    {
        isSubscribed = true;
        org->addSupplier(shared_from_this());
        std::cout << name << " has subscribed to the organization for notifications." << std::endl;
    }
}
// Check if the supplier is subscribed
bool Supplier::isSupplierSubscribed() const
{
    return isSubscribed;
}
