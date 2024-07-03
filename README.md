# Supermarket Management System

This Supermarket Management System is a console-based application developed in C++. It provides essential functionalities for managing inventory in a supermarket, including adding, modifying, deleting, and listing products, as well as handling purchase transactions and generating receipts.

## Features

- **Product Management**: Add, modify, delete, and list products.
- **Purchase Handling**: Buy products and generate receipts with discount calculations.
- **Data Persistence**: Efficient file handling ensures data is stored and retrieved across sessions.
- **User Interface**: Intuitive, menu-driven console interface for easy navigation.
- **Error Handling**: Robust input validation and error management to ensure reliability.

## Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/manajigari-harshitha/Database_Management_Project.git
   ```
2. Navigate to the project directory:
   ```sh
   cd Database_Management_Project
   ```
3. Compile the program:
   ```sh
   g++ main.cpp -o supermarket
   ```
4. Run the program:
   ```sh
   ./supermarket
   ```

## Usage

- **Administrator Menu**:
  - Add Product
  - Modify Product
  - Delete Product
  - View Product List

- **Buyer Menu**:
  - Buy Products
  - View Receipt

## Code Structure

The project consists of a single file, `main.cpp`, which includes:
- **Product Class**: Handles product details and displays information.
- **Database Class**: Manages product data storage, retrieval, updating, and deletion using file handling.
- **Shopping Class**: Implements the main menu, administrator, and buyer functionalities.

## Example Code

Here's a snippet demonstrating how to add a product:

```cpp
#include <iostream>
#include <fstream>
#include <string>

class Product {
public:
    int productID;
    std::string productName;
    float price;
    int quantity;

    void addProduct() {
        std::cout << "Enter Product ID: ";
        std::cin >> productID;
        std::cout << "Enter Product Name: ";
        std::cin >> productName;
        std::cout << "Enter Price: ";
        std::cin >> price;
        std::cout << "Enter Quantity: ";
        std::cin >> quantity;
    }

    void displayProduct() {
        std::cout << "Product ID: " << productID << "\n"
                  << "Product Name: " << productName << "\n"
                  << "Price: " << price << "\n"
                  << "Quantity: " << quantity << "\n";
    }
};
```

## Future Enhancements

- **Graphical User Interface**: Transition to a GUI for enhanced user experience.
- **Database Integration**: Use a relational database like MySQL or SQLite for better scalability and performance.
- **Advanced Features**:
  - Sales analytics and reporting
  - Enhanced inventory management
  - User authentication and role-based access control

## Contributions

Contributions are welcome! Please fork this repository and submit pull requests for any enhancements or bug fixes.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact

For any inquiries, please contact [manajigariharshitha@gmail.com](mailto:manajigariharshitha@gmail.com).

