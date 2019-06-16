/*CSCI 470    Assignment 3(Part 1)   Fall 2018
 * 
 * Developer: Gary Butler
 * 
 * Section: 1
 * 
 * Due Date/Time: 9/21/18 11:59pm
 * 
 * Purpose: This program takes two objects of money, formats the cents to match conventional couting, and adds two
 * objects.
 */
public class USMoneyDemo
{
  public static void main(String[] args)
  {
    USMoney a = new USMoney(50,170);
    USMoney b = new USMoney(20,50);
    USMoney add = new USMoney(0,0);
    
    System.out.println("USMoney object a (instantiated with 50 dollars and 170 cents):\nDollars: " + a.getDollars() +"\nCents: " + a.getCents());
    System.out.println("USMoney object b (instantiated with 20 dollars and 50 cents):\nDollars: " + b.getDollars() +"\nCents: " + b.getCents());
    System.out.println("After adding a and b:\n");
    add = a.plus(b);
    System.out.println("USMoney object add:\nDollars: " + add.getDollars() +"\nCents: " + add.getCents());
  }
}
