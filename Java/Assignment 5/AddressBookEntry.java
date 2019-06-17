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

public class AddressBookEntry
{
  private String name;
  private String email;
  private String cellNumber;
  
  public AddressBookEntry(String name, String email, String cellNumber)
  {
    this.name = name;
    this.email = email;
    this.cellNumber = cellNumber;
  }
  
  public AddressBookEntry(){}
  
  //gets
  public String getName()
  {
    return name;
  }
  
  public String getEmail()
  {
    return email;
  }
  
  public String getCellNumber()
  {
    return cellNumber;
  }
  
  //sets
  public void setName(String name)
  {
    this.name = name;
  }
  
  public void setEmail(String email)
  {
    this.email = email;
  }
  
  public void setCellNumber(String cellNumber)
  {
    this.cellNumber = cellNumber;
  }
}
