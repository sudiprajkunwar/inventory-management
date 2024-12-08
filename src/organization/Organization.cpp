#include "./Organization.h"

// Add a new product to the inventory
void Organization::addProduct(const Product &product)
{
    products.push_back(product);
    std::cout << "Product added: " << product.getProductName() << "\n";
}

// Remove a product by productID
void Organization::removeProductById(const std::string &productId)
{
    for (auto it = products.begin(); it != products.end(); ++it)
    {
        if (it->getProductId() == productId)
        {
            std::cout << "Product removed: " << it->getProductName() << "\n";
            products.erase(it);
            return;
        }
    }

    // If product was not found
    std::cout << "Product with ID " << productId << " not found.\n";
}

// Search for a product by productID
Product *Organization::searchProductById(const std::string &productId)
{
    for (auto &product : products)
    {
        if (product.getProductId() == productId)
        {
            return &product;
        }
    }
    return nullptr;
}

// Display the entire inventory
void Organization::displayInventory() const
{
    if (products.empty())
    {
        std::cout << "Inventory is empty.\n";
        return;
    }

    std::cout << "\nInventory List:\n";
    std::cout << "---------------------------------------------\n";
    for (const auto &product : products)
    {
        std::cout << "ID: " << product.getProductId() << "\n";
        std::cout << "Name: " << product.getProductName() << "\n";
        std::cout << "Category: " << product.getCategory() << "\n";
        std::cout << "Stock Level: " << product.getStockLevel() << "\n";
        std::cout << "Reorder Threshold: " << product.getReorderThreshold() << "\n";
        std::cout << "Price: $" << product.getPrice() << "\n";
        std::cout << "---------------------------------------------\n";
    }
}

void Organization::addSupplier(std::shared_ptr<Supplier> supplier)
{
    suppliers.push_back(supplier);
}

void Organization::notifySuppliers(const std::string &productID, int quantity)
{
    for (auto &supplier : suppliers)
    {
        if (supplier->isSupplierSubscribed())
        {
            supplier->notifyRestock(productID, quantity);
        }
    }
}

void Organization::sellProduct(const std::string &productId, int quantity)
{
    Product *product = searchProductById(productId);
    if (!product)
    {
        std::cout << "Product with ID " << productId << " not found.\n";
        return;
    }

    if (product->getStockLevel() < quantity)
    {
        std::cout << "Insufficient stock for product " << productId << ".\n";
        return;
    }

    product->updateStockLevel(quantity);
    std::cout << "Sold " << quantity << " units of product " << product->getProductName() << ". Remaining stock: " << product->getStockLevel() << "\n";

    // Check if stock is below the threshold and notify suppliers if needed
    if (product->getStockLevel() < product->getReorderThreshold())
    {
        int restockQuantity = product->getReorderThreshold() - product->getStockLevel();
        notifySuppliers(productId, restockQuantity);
    }
}
