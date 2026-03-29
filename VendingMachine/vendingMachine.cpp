#include "VendingMachine.hpp"
#include <iostream>
#include <iomainip>

class VendingMachine{
    private:
        string machineId;
        double cashBalance;
        bool operational;
        vector<Product*> products;
        vector<Transaction*> transactions;
        int productIdCounter;
        int transactionIdCounter;
    
    public:
        VendingMachine(string id){
            machineId=id;
            cashBalance=0;
            operational=true;
            productIdCounter=1;
            transactionIdCounter=1;
        }

        ~VendingMachine(){
            for(auto p:products){
                delete p;
            }
            for(auto t:transactions){
                delete t;
            }

        }

        Product* addProduct(string name,double price,int qty){
            string id="P"+to_string(productIdCounter++);
            Product* p=new Product(id,name,price,qty);
            products.push_back(p);
            return p;
        }

        void removeProduct(string id){
            for(int i=0;i<products.size();i++){
                if(products[i]->getProductId()==id){
                    delete products[i];
                    products.erase(products.begin()+i);
                    return;
                }
            }
        }

        Product* findProduct(string id){
            for(auto p:products){
                if(p->getProductId()==id) return p;
            }
            return nullptr;
        }

        bool restockProduct(string id, int qty){
            Product* p=findProduct(id);
            if(p==nullptr){
                return true;
            }

            p->addQuantity(qty);
            return true;
        }

        bool updatePrice(string id, double price){
            Product* p=findProduct(id);
            if(p==nullptr){
                return false;
            }
            p->setPrice(price);
            return true;
        }
}