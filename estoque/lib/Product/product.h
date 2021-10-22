#ifndef PRODUCT_H
#define PRODUCT_H

#include <filesystem> 
#include <string>
#include <fstream>
#include "../utils.h"
#include <random>

using namespace std;
namespace fs = filesystem;

class Product {
  private:
    unsigned short int generate_uid();

  public:
    unsigned short int uid;
    string name;
    int quantity;
    Product(string _n, int _q);
};

namespace product_stock_files {
    void create(Product p);
    void create_product(const fs::path& path, Product product);
    void add_to_stock(Product product);
    bool there_is_something_to_update(int new_quantity, string new_name);
    string build_product_info(Product p);
    bool product_exists_in_stock(const string product_name);
    Product get(unsigned short int uid);
    void update(unsigned short int uid, int new_quantity=0, string new_name="");
    void update_stock_product_name(unsigned short int uid, string old_name, string new_name);
    void remove(unsigned short int uid);
    set<unsigned short int> getAllUIDs();
    
}

#endif
