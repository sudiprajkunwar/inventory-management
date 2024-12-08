#include "./LocalSupplier.h"
#include "../organization/Organization.h"

LocalSupplier::LocalSupplier(const std::string &name) : Supplier(name) {}

void LocalSupplier::notifyRestock(const std::string &productId, int quantity)
{
    std::cout << "Local Supplier: Restocking product " << productId << " with quantity " << quantity << std::endl;
}

void LocalSupplier::subscribeToOrganization(Organization *org)
{

    // isSubscribed = true;
    // Implement subscription logic here, for now just a message
    std::cout << name << " has subscribed to the organization for notifications." << std::endl;
    // In a real scenario, you could add the supplier to a list of subscribers in the organization.
}
