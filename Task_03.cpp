#include<iostream>
using namespace std;

class Product{
protected:
    string productId,name;
    double price;

public:
    Product(string id,string n,double p){
        productId=id;
        name=n;
        price=p;
    }

    void displayProductInfo(){
        cout<<"Product ID: "<<productId<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Price: "<<price<<endl;
    }

    double applyDiscount(){
        return price-(price*0.10);
    }
};

class Electronics:public Product{
    string brand,powerConsumption;
    int warrantyMonths;

public:
    Electronics(string id,string n,double p,string b,int w,string power):Product(id,n,p){
        brand=b;
        warrantyMonths=w;
        powerConsumption=power;
    }

    void displayElectronicsInfo(){
        displayProductInfo();
        cout<<"Brand: "<<brand<<endl;
        cout<<"Warranty: "<<warrantyMonths<<" Months"<<endl;
        cout<<"Power Consumption: "<<powerConsumption<<endl;
        cout<<"Discounted Price: "<<applyDiscount()<<endl;
    }
};

class Clothing:public Product{
    string size,color,material;

public:
    Clothing(string id,string n,double p,string s,string c,string m):Product(id,n,p){
        size=s;
        color=c;
        material=m;
    }

    void displayClothingInfo(){
        displayProductInfo();
        cout<<"Size: "<<size<<endl;
        cout<<"Color: "<<color<<endl;
        cout<<"Material: "<<material<<endl;
        cout<<"Discounted Price: "<<applyDiscount()<<endl;
    }
};

class Grocery:public Product{
    string expiryDate;
    double weight;
    bool isOrganic;

public:
    Grocery(string id,string n,double p,string e,double w,bool o):Product(id,n,p){
        expiryDate=e;
        weight=w;
        isOrganic=o;
    }

    void displayGroceryInfo(){
        displayProductInfo();
        cout<<"Expiry Date: "<<expiryDate<<endl;
        cout<<"Weight: "<<weight<<" kg"<<endl;
        cout<<"Organic: "<<(isOrganic?"Yes":"No")<<endl;
        cout<<"Discounted Price: "<<applyDiscount()<<endl;
    }
};

int main(){

    Electronics e1("E101","Laptop",150000,"HP",12,"65W");
    Electronics e2("E102","Mobile",80000,"Samsung",24,"25W");

    Clothing c1("C101","Shirt",2500,"Medium","Black","Cotton");
    Clothing c2("C102","Jeans",4000,"Large","Blue","Denim");

    Grocery g1("G101","Milk",300,"25-12-2026",1,true);
    Grocery g2("G102","Rice",500,"30-06-2027",2,false);

    cout<<"===== ELECTRONICS ====="<<endl;
    e1.displayElectronicsInfo();
    cout<<endl;
    e2.displayElectronicsInfo();

    cout<<"\n===== CLOTHING ====="<<endl;
    c1.displayClothingInfo();
    cout<<endl;
    c2.displayClothingInfo();

    cout<<"\n===== GROCERY ====="<<endl;
    g1.displayGroceryInfo();
    cout<<endl;
    g2.displayGroceryInfo();

    return 0;
}