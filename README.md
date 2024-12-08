Thank you for pointing that out. Here's an updated version of the `README.md` to reflect that the `main.cpp` file is located outside the `src/` directory:

---

# Inventory Management System (C++)

## Overview

This project is an **Inventory Management System** developed in **C++** to help manage products and suppliers for a retail organization. The system provides the following features:

- **Product Management**: Add, remove, and update products in the inventory.
- **Supplier Notification**: Notifies suppliers when a product’s stock falls below a defined threshold.
- **Inventory Reporting**: Generates a report showing all products and those that need restocking.
- **Supplier Types**: Supports different types of suppliers such as local and global suppliers.

### Key Concepts Used:

- **Composition**: The `Organization` class contains a collection of `Product` objects, managing them via composition.
- **Abstract Classes and Inheritance**: The `Supplier` class is abstract, and concrete classes like `LocalSupplier` and `GlobalSupplier` extend it.
- **Notification System**: The system alerts suppliers when products need restocking.

## Features

- **Product Class**: Handles product details like productID, name, category, price, stock level, and reorder threshold.
- **Organization Class**: Manages a collection of products and subscribers (suppliers). It can update product stock levels and notify suppliers if restocking is needed.
- **Supplier Classes**: `LocalSupplier` and `GlobalSupplier` are derived from the abstract `Supplier` class. They subscribe to the `Organization` class and get notified when restocking is required.
- **Inventory Report**: Generates a list of all products and products that need restocking, including quantities that need to be replenished.

## Requirements

To build and run this system, you'll need:

- **C++ Compiler** (such as GCC or MSVC)
- **C++ Standard Library** (for features like `std::vector`, `std::shared_ptr`, etc.)

## File Structure

```
/InventoryManagementSystem
│
├── src/
│   ├── product/
│   │   ├── Product.h
│   │   └── Product.cpp
│   ├── supplier/
│   │   ├── Supplier.h
│   │   ├── LocalSupplier.h
│   │   ├── LocalSupplier.cpp
│   │   ├── GlobalSupplier.h
│   │   └── GlobalSupplier.cpp
│   ├── organization/
│   │   ├── Organization.h
│   │   └── Organization.cpp
│
├── main.cpp
├── README.md
└── Makefile (optional, for building the project)
```

- **Product.h/cpp**: Defines and implements the `Product` class.
- **Supplier.h/cpp**: Defines the abstract `Supplier` class and concrete supplier classes.
- **Organization.h/cpp**: Implements the `Organization` class, which manages the inventory and notifications.
- **main.cpp**: The entry point of the program, located outside the `src/` folder.

## Compilation and Running

1. **Clone the repository** (if you haven’t already):

   ```bash
   git clone <repository-url>
   cd InventoryManagementSystem
   ```

2. **Building the project**:

   You can use a simple Makefile or manually compile the C++ files using `g++`.

   - **Using `g++` manually**:
   
     In your terminal, run the following command from the project root:

     ```bash
     g++ -std=c++17 main.cpp src/organization/Organization.cpp src/supplier/LocalSupplier.cpp src/supplier/GlobalSupplier.cpp src/product/Product.cpp -o inventory_system
     ```

   - **Using a Makefile**:
   
     If you have a Makefile, you can use it to compile the project:

     ```bash
     make
     ```

3. **Running the program**:

   After compilation, run the generated executable:

   ```bash
   ./inventory_system
   ```

## How to Use

1. **Add Products**: You can add products to the inventory by calling `addProduct()` on the `Organization` object.
   
   Example: 
   ```cpp
   org.addProduct(Product("P001", "Laptop", "Electronics", 1200.50, 50, 10));
   ```

2. **Update Stock Levels**: Use `updateStockLevel()` to update the stock of a product. If the stock falls below the reorder threshold, suppliers will be notified.
   
   Example: 
   ```cpp
   org.updateStockLevel("P001", 5);  // Update stock of Laptop to 5
   ```

3. **Generate Inventory Report**: Call `generateReport()` to print an inventory report, showing all products and those needing restocking.
   
   Example:
   ```cpp
   org.generateReport();  // Generate and print the inventory report
   ```

4. **Add Suppliers**: You can subscribe suppliers to the organization to receive notifications when restocking is required.
   
   Example:
   ```cpp
   std::shared_ptr<LocalSupplier> localSupplier = std::make_shared<LocalSupplier>("Local Supplier");
   org.addSupplier(localSupplier);
   ```

5. **Subscription Logic**: Suppliers will be notified when a product's stock level goes below the threshold set by the `reorderThreshold`.

   Example:
   ```cpp
   localSupplier->subscribeToOrganization(&org);
   ```

## Example Output

Upon updating the stock level and generating a report, the following could be displayed:

```
Stock level for product Laptop updated to 5
Local Supplier has been notified to restock Product: P001, Quantity Needed: 5
Global Supplier has been notified to restock Product: P001, Quantity Needed: 5

===== Inventory Report =====
All Products:
Product Name: Laptop, Category: Electronics, Price: 1200.50, Stock Level: 5
Product Name: Smartphone, Category: Electronics, Price: 800.75, Stock Level: 30
Product Name: Coffee Maker, Category: Home Appliances, Price: 150.25, Stock Level: 15

Products that need restocking:
Product: Laptop, Quantity Needed: 5
```

## Conclusion

This system is a simple, yet effective inventory management solution that allows for adding products, updating stock, notifying suppliers when restocking is needed, and generating reports. You can extend it further by adding more features like handling product categories, advanced notifications, or integrating with a database for persistent storage.

---

Feel free to modify and expand the system as needed!
