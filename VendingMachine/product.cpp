# include<iostream>

# include<iomanip>

class Product{
    private:
            string productId;
            string name;
            double price;
            int quantity;
            bool available;
    public:
            Product(string Id,string name,double price, int qty){
                this->productId=Id;
                this->name=name;
                this->price=price;
                this->quantity=qty;
                this->available=true;
            }
            string getProductId(){
                return productId;
            }        
            string getName(){
                return name;
            }
            double getPrice(){
                return price;
            }
            int getQuantity(){
                return quantity;
            }
            bool isAvailable(){
                return available && quantity>0;
            }

            void setPrice(double price){
                this->price=price;
            }
            void setQuantity(int qty){
                this->quantity=qty;
            }
            void setAvailable(bool status){
                available=status;
            }
            void addQuantity(int amount){
                quantity+=amount;
            }
            bool removeQuantity(int amount){
                if(amount<=quantity){
                    quantity-=amount;
                    return true;
                }
                return false;
            }

            void displayInfo() {
                cout<<"Product"<<name<<" (ID: " << productId << ")" << endl;
                cout<<"Price : $"<< price <<endl;
                cout<< "Quantity"<<quantity<<endl;
                cout<< "Status" << (isAvailable()?"Available":"Not Available")<<endl;

            }

}