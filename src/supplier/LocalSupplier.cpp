#include "./LocalSupplier.h"
#include "../organization/Organization.h"

LocalSupplier::LocalSupplier(const std::string &name) : Supplier(name) {}

void LocalSupplier::notifyRestock(const std::string &productId, int quantity)
{
    std::cout << "Notification => Local Supplier: Restocking product " << productId << " with quantity " << quantity << std::endl;
}

void LocalSupplier::subscribeToOrganization(Organization *org)
{
    Supplier::subscribeToOrganization(org);
    std::cout << name << " has subscribed to the organization for notifications." << std::endl;

}
