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
        supplier->notifyRestock(productID, quantity);
    }
}

void Organization::updateStockLevel(const std::string &productID, int newStock)
{
    for (auto &product : products)
    {
        if (product.getProductId() == productID)
        {
            product.updateStockLevel(newStock);
            std::cout << "Stock level for product " << product.getProductName() << " updated to " << product.getStockLevel() << std::endl;

            if (product.needsRestock())
            {
                int quantityNeeded = product.getReorderThreshold() - product.getStockLevel();
                for (auto &supplier : suppliers)
                {
                    supplier->notifyRestock(product.getProductId(), quantityNeeded);
                }
            }
            return;
        }
    }
    std::cout << "Product with ID " << productID << " not found." << std::endl;
}

void Organization::generateReport() const
{
    std::cout << "===== Inventory Report =====\n";

    // 1. List of all products with their details
    std::cout << "\nAll Products:\n";
    for (const auto &product : products)
    {
        std::cout << "Product Name: " << product.getProductName()
                  << ", Category: " << product.getCategory()
                  << ", Price: " << product.getPrice()
                  << ", Stock Level: " << product.getStockLevel() << "\n";
    }

    // 2. List of products that need restocking
    for (const auto &product : products)
    {
        if (product.needsRestock())
        {
            std::cout << "\nProducts that need restocking:\n";
            int quantityNeeded = product.getReorderThreshold() - product.getStockLevel();
            std::cout << "Product: " << product.getProductName()
                      << ", Quantity Needed: " << quantityNeeded << "\n";
        }
    }

    // List all suppliers
    std::cout << "\nSuppliers:" << std::endl;
    if (suppliers.empty())
    {
        std::cout << "No suppliers added." << std::endl;
    }
    else
    {
        for (const auto &supplier : suppliers)
        {
            std::cout << supplier->getName() << std::endl;
        }
    }
}