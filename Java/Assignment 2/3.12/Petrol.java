/*CSCI 470    Assignment 1(3.12)   Fall 2018
 * 
 * Developer: Gary Butler
 * 
 * Section: 1
 * 
 * Due Date/Time: 9/14/18 11:59pm
 * 
 * Purpose: This program uses 'get' and 'set' methods to display a gas station's information including the location,
 * the type of gas offered, the number of gallons to be purchased, the price per gallon, a discount to be applied,
 * and the total price with all of these factors applied.
 */
import java.util.Scanner;

public class Petrol
{
  public static void main(String[] args)
  {
    String testLocation = "";   //All varibles are used to test the get and set methods
    String testType = "";       //
    int testQuantity = 0;       //
    int testPrice = 0;          //
    double testDiscount = 0;    //
    
    Scanner scan = new Scanner(System.in);
    
    //Input values to be tested
    //
    System.out.println("Enter the following: ");
    System.out.println("Location : ");
    testLocation = scan.nextLine();
    System.out.println("Petrol type : ");
    testType = scan.nextLine();
    System.out.println("Quantity of petrol : ");
    testQuantity = scan.nextInt();
    System.out.println("Price of petrol per gallon:");
    testPrice = scan.nextInt();
    System.out.println("Discount:");
    testDiscount = scan.nextDouble();
    
    PetrolPurchase test = new PetrolPurchase(testLocation,testType,testQuantity,testPrice,testDiscount); //PetrolPurchase constructor built from input
    
    //print info
    //
    System.out.println("Location: " + test.getLocation());
    System.out.println("Type: " + test.getType());
    System.out.println("Quantity: " + test.getQuantity() + " gallons");
    System.out.println("Price: $"+ test.getPrice());
    System.out.println("Discount: $" + test.getDiscount());
    System.out.println("Purchase Ammount: $" + test.getPurchaseAmmount());
    
    //update info from input
    //
    System.out.println("Please update the following: ");
    //location
    System.out.println("Location : ");
    scan.nextLine();
    testLocation = scan.nextLine();
    test.setLocation(testLocation);
    //type
    System.out.println("Petrol type : ");
    testType = scan.nextLine();
    test.setType(testType);
    //quantity
    System.out.println("Quantity of petrol : ");
    testQuantity = scan.nextInt();
    test.setQuantity(testQuantity);
    //price
    System.out.println("Price of petrol per gallon:");
    testPrice = scan.nextInt();
    test.setPrice(testPrice);
    //discount
    System.out.println("Discount:");
    testDiscount = scan.nextDouble();
    test.setDiscount(testDiscount);
    
    //Display updated info
    //
    System.out.println("New Info: ");
    System.out.println("Location: " + test.getLocation());
    System.out.println("Type: " + test.getType());
    System.out.println("Quantity: " + test.getQuantity() + " gallons");
    System.out.println("Price: $"+ test.getPrice());
    System.out.println("Discount: $" + test.getDiscount());
    System.out.println("Purchase Ammount: $" + test.getPurchaseAmmount());
  }
}
