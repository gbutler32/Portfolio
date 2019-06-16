/*CSCI 470    Assignment 3(Part 2)   Fall 2018
 * 
 * Developer: Gary Butler
 * 
 * Section: 1
 * 
 * Due Date/Time: 9/21/18 11:59pm
 * 
 * Purpose: This program takes an entered date and determines the number of days since Jan 1st
 */

import java.util.Scanner;

public class DateDemo
{
  public static void main(String[] args)
  {
    Scanner scan = new Scanner(System.in);
    int day;
    int month;
    int year;
    System.out.println("Enter a day: ");
    day = scan.nextInt();
    System.out.println("Enter a month: ");
    month = scan.nextInt();
    System.out.println("Enter a year: ");
    year = scan.nextInt();
    
    Date test = new Date(day,month,year);
    
    System.out.println("Days since Jan 1st: " + test.daysSinceJan1());
  }
}
