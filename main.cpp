#include <fstream>  //file handling
#include <iostream> //input output
#include <limits>
#include <vector>
using namespace std;

class Product {
public:
  int pcode;
  float price;
  float dis;
  string pname;

  Product() {}
  Product(int code, const string &name, float pr, float discount)
      : pcode(code), price(pr), dis(discount), pname(name) {}

  void display() const {
    cout << "Product Code: " << pcode << ", Name: " << pname
         << ", Price: " << price << ", Discount: " << dis << "%" << endl;
  }
};

class Database {
private:
  string filename;

public:
  Database(const string &fname) : filename(fname) {}

  bool addProduct(const Product &product) {
    fstream data(filename, ios::app | ios::out);
    if (!data) {
      cerr << "Error: Could not open database file." << endl;
      return false;
    }
    data << product.pcode << " " << product.pname << " " << product.price << " "
         << product.dis << endl;
    data.close();
    return true;
  }

  bool getProduct(int pcode, Product &product) {
    fstream data(filename, ios::in);
    if (!data) {
      cerr << "Error: Could not open database file." << endl;
      return false;
    }
    int code;
    string name;
    float price, discount;
    while (data >> code >> name >> price >> discount) {
      if (code == pcode) {
        product = Product(code, name, price, discount);
        data.close();
        return true;
      }
    }
    data.close();
    return false;
  }

  bool updateProduct(const Product &product) {
    fstream data(filename, ios::in);
    fstream temp("temp.txt", ios::out);
    if (!data || !temp) {
      cerr << "Error: Could not open database file." << endl;
      return false;
    }
    int code;
    string name;
    float price, discount;
    bool updated = false;
    while (data >> code >> name >> price >> discount) {
      if (code == product.pcode) {
        temp << product.pcode << " " << product.pname << " " << product.price
             << " " << product.dis << endl;
        updated = true;
      } else {
        temp << code << " " << name << " " << price << " " << discount << endl;
      }
    }
    data.close();
    temp.close();
    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
    return updated;
  }

  bool deleteProduct(int pcode) {
    fstream data(filename, ios::in);
    fstream temp("temp.txt", ios::out);
    if (!data || !temp) {
      cerr << "Error: Could not open database file." << endl;
      return false;
    }
    int code;
    string name;
    float price, discount;
    bool deleted = false;
    while (data >> code >> name >> price >> discount) {
      if (code == pcode) {
        deleted = true;
      } else {
        temp << code << " " << name << " " << price << " " << discount << endl;
      }
    }
    data.close();
    temp.close();
    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
    return deleted;
  }

  void listProducts() const {
    fstream data(filename, ios::in);
    if (!data) {
      cerr << "Error: Could not open database file." << endl;
      return;
    }
    cout << "\n\n_______________________________________________\n";
    cout << "ProNo\t\tName\t\tPrice\n";
    cout << "\n_______________________________________________\n";
    int code;
    string name;
    float price, discount;
    while (data >> code >> name >> price >> discount) {
      cout << code << "\t\t" << name << "\t\t" << price << "\n";
    }
    data.close();
  }
};

class Shopping {
private:
  Database db;

public:
  Shopping(const string &dbFile) : db(dbFile) {}

  void menu() {
    int choice;
    string email;
    string password;

    do {
      cout << "\t\t\t\t_____________________________________\n";
      cout << "\t\t\t\t                                     \n";
      cout << "\t\t\t\t         Supermarket Main Menu       \n";
      cout << "\t\t\t\t                                     \n";
      cout << "\t\t\t\t_____________________________________\n";
      cout << "\t\t\t\t                                     \n";
      cout << "\t\t\t\t|    1) Administrator               |\n";
      cout << "\t\t\t\t|                                   |\n";
      cout << "\t\t\t\t|    2) Buyer                       |\n";
      cout << "\t\t\t\t|                                   |\n";
      cout << "\t\t\t\t|    3) Exit                        |\n";
      cout << "\t\t\t\t|                                   |\n";
      cout << "\n\t\t\t Please select : ";
      cin >> choice;

      switch (choice) {
      case 1:
        cout << "\t\t\t Please Login \n";

        cout << "\t\t\t Enter Email : ";
        cin >> email;
        cout << "\t\t\t Enter Password : ";
        cin >> password;

        if (email == "admin" && password == "admin") {
          administrator();
        } else {
          cout << "Invalid email/password\n";
        }
        break;

      case 2:
        buyer();
        break;

      case 3:
        exit(0);

      default:
        cout << "Please select from the given options\n";
      }
    } while (choice != 3);
  }

  void administrator() {
    int choice;

    do {
      cout << "\n\n\n\t\t\t Administrator menu";
      cout << "\n\t\t\t____________________________";
      cout << "\n\t\t\t 1) Add the product";
      cout << "\n\t\t\t____________________________";
      cout << "\n\t\t\t 2) Modify the product";
      cout << "\n\t\t\t____________________________";
      cout << "\n\t\t\t 3) Delete the product";
      cout << "\n\t\t\t____________________________";
      cout << "\n\t\t\t 4) Back to main menu";
      cout << "\n\t\t\t____________________________";

      cout << "\n\n\t Please enter your choice: ";
      cin >> choice;

      switch (choice) {
      case 1:
        add();
        break;
      case 2:
        edit();
        break;
      case 3:
        rem();
        break;
      case 4:
        return;
      default:
        cout << "Invalid choice!\n";
      }
    } while (choice != 4);
  }

  void buyer() {
    int choice;
    do {
      cout << "\t\t\t  Buyer  \n";
      cout << "\t\t\t__________  \n";
      cout << "                  \n";
      cout << "\t\t\t 1) Buy Product  \n";
      cout << "                  \n";
      cout << "\t\t\t 2) Go Back  \n";
      cout << "\t\t\t  Enter your choice : ";
      cin >> choice;

      switch (choice) {
      case 1:
        receipt();
        break;
      case 2:
        return;
      default:
        cout << "Invalid choice!\n";
      }
    } while (choice != 2);
  }

  void add() {
    int pcode;
    string pname;
    float price, dis;

    cout << "\n\n\n\t\t Add new product";
    cout << "\n\t Product code of the product: ";
    cin >> pcode;
    cout << "\n\t Name of the product: ";
    cin >> pname;
    cout << "\n\t Price of the product: ";
    cin >> price;
    cout << "\n\t Discount on product: ";
    cin >> dis;

    Product product(pcode, pname, price, dis);
    if (db.addProduct(product)) {
      cout << "\n\n\t\t Record inserted!\n";
    } else {
      cout << "\n\n\t\t Could not insert record.\n";
    }
  }

  void edit() {
    int pcode;
    cout << "\n\n\t\t Modify the record";
    cout << "\n\t\t Product code: ";
    cin >> pcode;

    Product product;
    if (db.getProduct(pcode, product)) {
      cout << "\n\t\t Product new code: ";
      cin >> product.pcode;
      cout << "\n\t\t Name of the product: ";
      cin >> product.pname;
      cout << "\n\t\t Price: ";
      cin >> product.price;
      cout << "\n\t\t Discount: ";
      cin >> product.dis;

      if (db.updateProduct(product)) {
        cout << "\n\n\t\t Record updated!\n";
      } else {
        cout << "\n\n\t\t Could not update record.\n";
      }
    } else {
      cout << "\n\n Record not found!\n";
    }
  }

  void rem() {
    int pcode;
    cout << "\n\n\t Delete Product";
    cout << "\n\n\t Product code: ";
    cin >> pcode;

    if (db.deleteProduct(pcode)) {
      cout << "\n\n\t Product deleted successfully\n";
    } else {
      cout << "\n\n Record not found!\n";
    }
  }

  void receipt() {
    vector<int> productCodes;
    vector<int> quantities;
    char choice;
    float total = 0;

    db.listProducts();

    cout << "\n______________________________________\n";
    cout << "\n                                     \n";
    cout << "\n        Please place the order       \n";
    cout << "\n                                     \n";
    cout << "\n______________________________________\n";
    do {
      int pcode, qty;
      cout << "\n\nEnter Product code : ";
      cin >> pcode;
      cout << "\n\nEnter the product quantity : ";
      cin >> qty;

      for (size_t i = 0; i < productCodes.size(); ++i) {
        if (productCodes[i] == pcode) {
          cout << "\n\n Duplicate product code. Please try again!\n";
          goto skip;
        }
      }

      productCodes.push_back(pcode);
      quantities.push_back(qty);

      cout << "\n\n Do you want to buy another product? If yes, press y else "
              "n: ";
      cin >> choice;

    skip:
      continue;
    } while (choice == 'y');

    cout << "\n\n\t\t________________________RECEIPT________________________\n";
    cout << "\nProduct No\t Product Name\t Product "
            "quantity\tprice\tAmount\tAmount with discount\n";

    for (size_t i = 0; i < productCodes.size(); ++i) {
      Product product;
      if (db.getProduct(productCodes[i], product)) {
        float amount = product.price * quantities[i];
        float discountAmount = amount - (amount * product.dis / 100);
        total += discountAmount;
        cout << "\n"
             << product.pcode << "\t\t" << product.pname << "\t\t"
             << quantities[i] << "\t\t" << product.price << "\t" << amount
             << "\t\t" << discountAmount;
      }
    }

    cout << "\n\n__________________________________________________";
    cout << "\n \t Total Amount \t:\t\t " << total << endl;
  }
};

int main() {
  Shopping s("database.txt");
  s.menu();
  return 0;
}
