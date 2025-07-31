#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  
using namespace std;

int main() {
    string Admin, Admin_Password, Customer, Customer_Password;

    const string admin = "Owner";
    const string admin_password = "OwnersPassword";  

    const string customer = "Buyyer";
    const string customer_Password = "BuyyersPassword";

    vector<string> productNames = {"Laptop", "Smartphone", "Shoes", "Shirt", "Watch"};
    vector<string> productCategories = {"Electronics", "Electronics", "Footwear", "Clothing", "Accessories"};
    vector<double> productPrices = {999.99, 599.99, 49.99, 19.99, 129.99};

    vector<string> cart;

    int choice;

    cout << "Welcome To Our Ecommerce Store:" << endl;
    cout << "Enter Login Choice:" << endl;
    cout << "Choice 1: As Admin, Choice 2: As Customer" << endl;

    bool loggedIn = false;
    bool tryBothLogin = true;

    while (tryBothLogin) {
        cin >> choice;

        if (choice == 1 && !loggedIn) {  
            cout << "Enter Admin Id: ";
            cin >> Admin;

            cout << "Enter Password: ";
            cin >> Admin_Password;

            if (admin == Admin && admin_password == Admin_Password) {
                cout << "Login Successful as an Admin!" << endl;
                loggedIn = true;

                int adminChoice;
                do {
                    cout << "\nAdmin Dashboard - Ecommerce Store" << endl;
                    cout << "1. View All Products" << endl;
                    cout << "2. Add New Product" << endl;
                    cout << "3. Update Product Information" << endl;
                    cout << "4. Delete Product" << endl;
                    cout << "5. Log Out" << endl;
                    cout << "Please select an option (1-5): ";
                    cin >> adminChoice;

                    switch (adminChoice) {
                        case 1:
                            for (int i = 0; i < productNames.size(); ++i) {
                                cout << "Product Name: " << productNames[i]
                                     << ", Category: " << productCategories[i]
                                     << ", Price: $" << productPrices[i] << endl;
                            }
                            break;
                        case 2:
                            {
                                string name, category;
                                double price;
                                cout << "Enter product name: ";
                                cin >> name;
                                cout << "Enter product category: ";
                                cin >> category;
                                cout << "Enter product price: ";
                                cin >> price;
                                productNames.push_back(name);
                                productCategories.push_back(category);
                                productPrices.push_back(price);
                                cout << "Product '" << name << "' added successfully!" << endl;
                            }
                            break;
                        case 3:
                            {
                                string name;
                                cout << "Enter the name of the product to update: ";
                                cin >> name;
                                bool found = false;
                                for (int i = 0; i < productNames.size(); ++i) {
                                    if (productNames[i] == name) {
                                        cout << "Updating product '" << name << "'..." << endl;
                                        cout << "Enter new product category: ";
                                        cin >> productCategories[i];
                                        cout << "Enter new product price: ";
                                        cin >> productPrices[i];
                                        cout << "Product updated successfully!" << endl;
                                        found = true;
                                        break;
                                    }
                                }
                                if (!found) {
                                    cout << "Product not found!" << endl;
                                }
                            }
                            break;
                        case 4:
                            {
                                string name;
                                cout << "Enter the name of the product to delete: ";
                                cin >> name;
                                bool found = false;
                                for (int i = 0; i < productNames.size(); ++i) {
                                    if (productNames[i] == name) {
                                        productNames.erase(productNames.begin() + i);
                                        productCategories.erase(productCategories.begin() + i);
                                        productPrices.erase(productPrices.begin() + i);
                                        cout << "Product '" << name << "' deleted successfully!" << endl;
                                        found = true;
                                        break;
                                    }
                                }
                                if (!found) {
                                    cout << "Product not found!" << endl;
                                }
                            }
                            break;
                        case 5:
                            cout << "Logging out..." << endl;
                            loggedIn = false;
                            break;
                        default:
                            cout << "Invalid choice! Please select a valid option (1-4, 12)." << endl;
                            break;
                    }
                } while (adminChoice != 5);

                cout << "Would you like to try logging in as a customer? (Press 'y' to continue or any other key to exit): ";
                char tryAsCustomer;
                cin >> tryAsCustomer;
                if (tryAsCustomer == 'y' || tryAsCustomer == 'Y') {
                    loggedIn = false;
                    tryBothLogin = true;
                    continue;  
                } else {
                    tryBothLogin = false;
                    break;
                }
            } else {
                cout << "Invalid Admin ID or Password. Would you like to try logging in as a customer instead? (Press 'y' to continue or any other key to exit): ";
                char tryAsCustomer;
                cin >> tryAsCustomer;
                if (tryAsCustomer == 'y' || tryAsCustomer == 'Y') {
                    loggedIn = false;
                    tryBothLogin = true;
                    continue;  
                } else {
                    tryBothLogin = false;
                    break;
                }
            }
        } 
        else if (choice == 2 && !loggedIn) {  
            cout << "Enter Customer Id: ";
            cin >> Customer;

            cout << "Enter Password: ";
            cin >> Customer_Password;

            if (Customer == customer && Customer_Password == customer_Password) {
                cout << "Login Successful as a Customer!" << endl;
                loggedIn = true;

                int customerChoice;
                do {
                    cout << "\nCustomer Dashboard - Ecommerce Store" << endl;
                    cout << "1. View All Products" << endl;
                    cout << "2. View Product Details" << endl;
                    cout << "3. Add Product to Cart" << endl;
                    cout << "4. View Cart" << endl;
                    cout << "5. Remove Product from Cart" << endl;
                    cout << "9. Log Out" << endl;
                    cout << "Please select an option (1-5, 9): ";
                    cin >> customerChoice;

                    switch (customerChoice) {
                        case 1:
                            for (int i = 0; i < productNames.size(); ++i) {
                                cout << "Product Name: " << productNames[i]
                                     << ", Category: " << productCategories[i]
                                     << ", Price: $" << productPrices[i] << endl;
                            }
                            break;
                        case 2:
                            {
                                string productName;
                                cout << "Enter product name to view details: ";
                                cin >> productName;
                                bool found = false;
                                for (int i = 0; i < productNames.size(); ++i) {
                                    if (productNames[i] == productName) {
                                        cout << "Product Name: " << productNames[i]
                                             << ", Category: " << productCategories[i]
                                             << ", Price: $" << productPrices[i] << endl;
                                        found = true;
                                        break;
                                    }
                                }
                                if (!found) {
                                    cout << "Product not found!" << endl;
                                }
                            }
                            break;
                        case 3:
                            {
                                string productName;
                                cout << "Enter product name to add to cart: ";
                                cin >> productName;

                                bool found = false;
                                for (int i = 0; i < productNames.size(); ++i) {
                                    if (productNames[i] == productName) {
                                        found = true;
                                        break;
                                    }
                                }

                                if (found) {
                                    cart.push_back(productName);
                                    cout << "Product '" << productName << "' added to cart!" << endl;
                                } else {
                                    cout << "Product '" << productName << "' not found in the store!" << endl;
                                }
                            }
                            break;
                        case 4:
                            if (cart.empty()) {
                                cout << "Your cart is empty!" << endl;
                            } else {
                                for (int i = 0; i < cart.size(); ++i) {
                                    cout << cart[i] << endl;
                                }
                            }
                            break;
                        case 5:
                            {
                                string productName;
                                cout << "Enter product name to remove from cart: ";
                                cin >> productName;
                                auto it = find(cart.begin(), cart.end(), productName);
                                if (it != cart.end()) {
                                    cart.erase(it);
                                    cout << "Product '" << productName << "' removed from cart!" << endl;
                                } else {
                                    cout << "Product not found in cart!" << endl;
                                }
                            }
                            break;
                        case 9:
                            cout << "Logging out..." << endl;
                            loggedIn = false;
                            break;
                        default:
                            cout << "Invalid choice! Please select a valid option (1-5, 9)." << endl;
                            break;
                    }
                } while (customerChoice != 9);

                cout << "Would you like to try logging in as an admin? (Press 'y' to continue or any other key to exit): ";
                char tryAsAdmin;
                cin >> tryAsAdmin;
                if (tryAsAdmin == 'y' || tryAsAdmin == 'Y') {
                    loggedIn = false;
                    tryBothLogin = true;
                    continue;  
                } else {
                    tryBothLogin = false;
                    break;
                }
            } else {
                cout << "Invalid Customer ID or Password. Would you like to try logging in as an admin instead? (Press 'y' to continue or any other key to exit): ";
                char tryAsAdmin;
                cin >> tryAsAdmin;
                if (tryAsAdmin == 'y' || tryAsAdmin == 'Y') {
                    loggedIn = false;
                    tryBothLogin = true;
                    continue;  
                } else {
                    tryBothLogin = false;
                    break;
                }
            }
        } else {
            cout << "Invalid choice! Please select either 1 for Admin or 2 for Customer." << endl;
        }
    }

    return 0;
}
