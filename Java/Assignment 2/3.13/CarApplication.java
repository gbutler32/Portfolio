/*CSCI 470    Assignment 1(3.13)   Fall 2018
 * 
 * Developer: Gary Butler
 * 
 * Section: 1
 * 
 * Due Date/Time: 9/14/18 11:59pm
 * 
 * Purpose: This program uses 'get' and 'set' methods to display two cars information and applies a 5% and 7% 
 * discount and displays the price after.
 */
class CarApplication
{
  public static void main(String[] args)
  {
    Car a = new Car("Camry","1999",5000);
    Car b = new Car("Ferrari","2018",5000000);
    double temp = 0;							//temp value for discount price calculation
    
    System.out.println("Car a's info:");
    System.out.println("Type: " + a.getType());
    System.out.println("Year: " + a.getYear());
    System.out.println("Price: $" + a.getPrice());
    
    System.out.println("\nCar b's info:");
    System.out.println("Type: " + b.getType());
    System.out.println("Year: " + b.getYear());
    System.out.println("Price: $" + b.getPrice());
    
    b.setPrice(-100);							//test negative price input
    System.out.println("\nAfter setting car b's price to -100, b's price is: $" + b.getPrice());
    
    temp = a.getPrice() * .05;
    a.setPrice(a.getPrice() - temp);
    System.out.println("\nAfter giving car a 5% discount: " + a.getPrice());
    
    temp = b.getPrice() * .07;
    b.setPrice(b.getPrice() - temp);
    System.out.println("After giving car b 7% discount: " + b.getPrice());
  }
}
