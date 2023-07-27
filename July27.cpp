#include<iostream>
using namespace std;

struct Product
{
    string name;
    double price;
    int quantity;
    Product *prevProduct;
    Product *nextProduct;
};

class ShoppingCart
{
public:
    Product *firstProduct = NULL, *lastProduct = NULL;
    Product *currentProduct, *newProduct;

    void addProduct(string name, double price, int quantity)
    {
        newProduct = new Product;
        newProduct->name = name;
        newProduct->price = price;
        newProduct->quantity = quantity;
        newProduct->prevProduct = lastProduct;
        newProduct->nextProduct = NULL;

        if(lastProduct != NULL)
        {
          lastProduct->nextProduct = newProduct;
        }

        else
        {
            firstProduct = newProduct;
        }

        lastProduct = newProduct;
    }

    void display()
    {
        currentProduct = firstProduct;
        while(currentProduct != NULL)
        {
            cout<<"Product Name : "<<currentProduct->name<<endl;
            cout<<"Price : "<<currentProduct->price<<endl;
            cout<<"Added Quantity : "<<currentProduct->quantity<<endl<<endl;

            currentProduct = currentProduct->nextProduct;
        }
    }

    void calculation()
    {
        double sum = 0;

        currentProduct = firstProduct;
        while(currentProduct != NULL)
        {
            sum += currentProduct->price * currentProduct->quantity;
            currentProduct = currentProduct->nextProduct;
        }

        cout<<"Total Bill of the items added to the cart : "<<sum<<endl<<endl;
    }
};

int main()
{
    ShoppingCart sc;

    sc.addProduct("Black Sunglass", 2120.90, 1);
    sc.addProduct("Swiss Watch", 10500, 1);
    sc.addProduct("Baseus Vacuum Cleaner", 2990, 2);
    sc.display();
    sc.calculation();

    return 0;
}
