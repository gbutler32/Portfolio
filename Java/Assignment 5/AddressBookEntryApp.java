/*CSCI 470    Assignment 5   Fall 2018
 * 
 * Developer: Gary Butler
 * 
 * Section: 1
 * 
 * Due Date/Time: 10/15/18 11:59pm
 * 
 * Purpose: This program displays a prompt to show list of saved people's info and allows entry of another person.
 */

import java.util.Scanner;

public class AddressBookEntryApp
{
  public static void main(String[] args)
  {
    Scanner choice = new Scanner(System.in);
    Scanner input = new Scanner(System.in);
    int menuNum;
    boolean menu = true;
    boolean again = false;
    AddressBookEntry newEntry = new AddressBookEntry();
    String name = "";
    String email = "";
    String phone = "";
    
    System.out.println("Welcome to the Address Book Application\n");
    
    
    
    while(menu == true)
    { 
      menuNum = 0;
      again = false;
    System.out.println("1 - List entries\n2 - Add entry\n3 - Exit\n");
    System.out.println("Enter Menu Number");
    
    menuNum = choice.nextInt();
    
    System.out.println();
    
    if(menuNum == 1)              //get entries
    {
        System.out.println(AddressBookIO.getEntriesString());
        menuNum =0;
    }
    else if(menuNum == 2)              //enter new entry
    {
      while(again == false)
      {
      System.out.println("Enter Name: ");
      name = input.nextLine();
      
      again = Validator.validateName(name);
      if(again == false)
      {
        System.out.println("Not a valid name " + name + ", please try again: ");
      }
      }
      again = false;
      
      while(again == false)
      {
      System.out.println("Enter email Address: ");
      email = input.nextLine();
      
      again = Validator.validateEmail(email);
      if(again == false)
      {
        System.out.println("Not a valid email, please try again: ");
      }
      }
      again = false;
      
      while(again == false)
      {
      System.out.println("Enter Phone Number: ");
      phone = input.nextLine();
      
      again = Validator.validateCellNumber(phone);
      if(again == false)
      {
        System.out.println("Not a valid phone number, please try again: ");
      }
      }
      newEntry = new AddressBookEntry(name,email,phone);
      AddressBookIO.saveEntry(newEntry);
      
      System.out.println("This entry has been saved.\n");
      
      menuNum =0;
    }
    else if(menuNum == 3)              //exit
    {
        menu = false;
        menuNum =0;
    }
    else
    {
        System.out.println("Enter Menu Number");
        menuNum = choice.nextInt();
        System.out.println();
    }
    }
  }
  
}
