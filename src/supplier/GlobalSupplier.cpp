#include "./GlobalSupplier.h"
#include "../organization/Organization.h"

GlobalSupplier::GlobalSupplier(const std::string &name) : Supplier(name) {}

void GlobalSupplier::notifyRestock(const std::string &productId, int quantity)
{
    std::cout << "Notification => Global Supplier: Restocking product " << productId << " with quantity " << quantity << std::endl;
}

void GlobalSupplier::subscribeToOrganization(Organization *org)
{
    Supplier::subscribeToOrganization(org);
    std::cout << name << " has subscribed to the organization for notifications." << std::endl;

}
