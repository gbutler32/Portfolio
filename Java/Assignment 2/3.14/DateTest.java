/*CSCI 470    Assignment 1(3.14)   Fall 2018
 * 
 * Developer: Gary Butler
 * 
 * Section: 1
 * 
 * Due Date/Time: 9/14/18 11:59pm
 * 
 * Purpose: This program displays a formatted date (dd/mm/yyy) and rejects incorrect dates
 */

import java.util.Scanner;

public class DateTest
{
  public static void main(String[] args)
  {
    Date test = new Date(9,8,2018);
    
    System.out.println("After running displayDate(): " + test.displayDate());
    
    System.out.println("\nAfter trying to set month to 13: " + test.setMonth(13));		//testing incorrect date input
    System.out.println("After trying to set day to 32: " + test.setDay(32));			//
    System.out.println("After tring to set year to -1: " + test.setYear(-1));			//
    
    System.out.println("\nAfter trying to set month to 12: " + test.setMonth(12));		//testing correct date input
    System.out.println("After trying to set day to 31: " + test.setDay(31));			//
    System.out.println("After tring to set year to 1999: " + test.setYear(1999));		//
    
    System.out.println("\nAfter running displayDate() again: " + test.displayDate());	
  }
}
