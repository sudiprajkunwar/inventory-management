#include "./GlobalSupplier.h"
#include "../organization/Organization.h"

GlobalSupplier::GlobalSupplier(const std::string &name) : Supplier(name) {}

void GlobalSupplier::notifyRestock(const std::string &productId, int quantity)
{
    std::cout << "Global Supplier: Restocking product " << productId << " with quantity " << quantity << std::endl;
}

void GlobalSupplier::subscribeToOrganization(Organization *org)
{
    // Implement subscription logic here, for now just a message
    std::cout << name << " has subscribed to the organization for notifications." << std::endl;
    // Similar to LocalSupplier, in a real implementation, you would add the supplier to a list of subscribers.
}
