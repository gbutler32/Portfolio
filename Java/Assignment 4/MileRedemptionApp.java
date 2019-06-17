/*CSCI 470    Assignment 8   Fall 2018
 * 
 * Developer: Gary Butler
 * 
 * Section: 1
 * 
 * Due Date/Time: 11/30/18 11:59pm
 * 
 * Purpose: This program takes a list of destinations from an input file and determines how many destinations a client
 * can travel in economy or first class
 */

import java.util.Scanner;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;


public class MileRedemptionApp
{
  public static void main(String[] args) throws IOException
  {
    ArrayList<Destination> places = new ArrayList<Destination>();
    String[] names = new String[9];
    String[] result = new String[9];
    int miles;
    int month;
    int nullCount=0;
    boolean again = true;
    char check;
    
    String fileName;
    
    Scanner input = new Scanner(System.in); 
    
    System.out.print("Please enter the name of the file: ");
    fileName = input.nextLine();
   
    Scanner fileScanner = new Scanner(new File(fileName));
   
    places = readDestinations(fileScanner);
      
    MileRedeemer Redeem = new MileRedeemer(places);
    
    names = Redeem.getCityNames();
    
    System.out.println("List of destionations your client can travel to:");
    for(int a =0; a<=8;a++)
    {
      System.out.println(names[a]);
    }
    
    while(again == true)
    {
    
    System.out.println("Please enter your client's accumulated Frequest Flyer Miles: ");
    miles = input.nextInt();
    
    System.out.println("Please enter your client's month of departure (1-12)");
    month = input.nextInt();
    
    Redeem = new MileRedeemer(miles,places);
 
    result = Redeem.redeemMiles(miles,month);
    
    System.out.println("Your client's Frequent Flyer Miles can be used to redeem the following tickets:\n");
    for(int a = 0; a <= 8; a++)
    {
      if(result[a] != null)
      {
        System.out.println(result[a]);
      }
      else
      {
        nullCount++;
      }
    }
    if(nullCount==9)
    {
      System.out.println("*** Your client has not accumulated enough Frequent Flyer Miles ***\n");
    }
    
    System.out.println("Your Client's remaining Frequent Flyer Miles: " + MileRedeemer.getRemaningMiles()+"\n");
    
    System.out.println("Do you want to continue (y/n)?");
    check = input.next().charAt(0);
    if(check == 'y' || check == 'Y')
    {
      again = true;
    }
    else
    {
      again = false;
    }
    }
    System.out.println("-------------------------------------------------------------------------");
    System.out.println("THANK YOU FOR USING THE JAVA AIRLINES FREQUENT FLYER MILES REDEMPTION APP");
    System.out.println("-------------------------------------------------------------------------");
    input.close();
  }

  public static ArrayList<Destination> readDestinations(Scanner fileScanner) throws IOException      //reads an input file and formats the input into a destination object
  {
    ArrayList<Destination> elem = new ArrayList<Destination>();
    
    String inputLine;
    String[] destinfo = new String[5];
    String[] months = new String[2];
    int miles;
    int econMiles;
    int firstClass;
    int start;
    int end;
    
    while(fileScanner.hasNext())
    {
      inputLine = fileScanner.nextLine();
      destinfo = inputLine.split(";");
      miles = Integer.parseInt(destinfo[1]);
      econMiles = Integer.parseInt(destinfo[2]);
      firstClass = Integer.parseInt(destinfo[3]);
      
      months = destinfo[4].split("-");
      start = Integer.parseInt(months[0]);
      end = Integer.parseInt(months[1]);
      
      Destination temp = new Destination(destinfo[0],miles,econMiles,firstClass,start,end);
      elem.add(temp);
    }
    
    return elem;
  }
  
  
  
  
  
  
}
