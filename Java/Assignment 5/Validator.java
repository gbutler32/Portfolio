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

public class Validator
{ 
  public static Boolean validateName(String inName)               //check for an empty name, no space, and a period in a name
  {
    Boolean correct = true;
    if(inName.isEmpty())
    {
      correct = false;
      return correct;
    }
      if(inName.contains(" "))
      {
        
      }
      else
        {
          correct = false;
          return correct;
        }
      if(inName.contains("."))
      {
        if(Character.isLetter(inName.charAt(inName.indexOf(".")-1)))
        {
          
        }
        else
        {
          correct = false;
          return correct;
        }
      }
    
    return correct;
  }
  
  public static Boolean validateEmail(String inEmail)            //checks for an empty string, an @ symbol, and the string ".com" in an email address
  {
    Boolean correct = true;
    String com = ".com";
    if(inEmail.isEmpty())
    {
      correct = false;
      return correct;
    }
    if(inEmail.indexOf('@') != -1)
    {
      if(inEmail.indexOf('@') != 0)
      {
        if(inEmail.indexOf('.') != -1)
        {
          if(inEmail.regionMatches(inEmail.indexOf('.'),com, 0, 2))
          {
            correct = true;
          }
          else
          {
            return false;
          }
        }
        else
          {
            correct = false;
          }
      }
      else
          {
            return false;
          }
    }
    else
    {
      return false;
    }
    return correct;
  }
  
  public static Boolean validateCellNumber(String inCellNumber)            //checks for a phone number with () formatting or not
  {
    Boolean correct = true; 
    
    if(inCellNumber.isEmpty())
    {
      correct = false;
      return correct;
    }
    
    if(inCellNumber.charAt(0) == '(')
    {
      if(inCellNumber.charAt(4) != ')')
      {
        System.out.println("no space");
        return false;
      }
      if(inCellNumber.length() != 14)
      {
        System.out.println("wrong length(14)");
        return false;
      }
    }
    
    if(Character.isDigit(inCellNumber.charAt(0)))
    {
      if(inCellNumber.length() != 12)
      {
        System.out.println("wrong length(12)");
        return false;
      }
    }
    
    return correct;
  }
}
