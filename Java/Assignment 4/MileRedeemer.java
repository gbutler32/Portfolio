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

import java.util.ArrayList;

public class MileRedeemer
{
 
  private static int remainingMiles;
  private int ffmiles;
  private static ArrayList<Destination> destinations = new ArrayList<Destination>();
  
  public MileRedeemer(int ffmiles,ArrayList<Destination> destinations)               //constructor
  {
    this.ffmiles = ffmiles;
    this.destinations = destinations;
  }
  
  public MileRedeemer(ArrayList<Destination> destinations)                           //constructor
  {
    this.destinations = destinations;
  }
  //input info and turn into a Destination object
  
  public static ArrayList<Destination> getDestinations()
  {
    return destinations;
  }
  
  //return city names
  public static String[] getCityNames()                                          //takes the destination names and returns an array of strings with just the names
  {
    destinations = getDestinations();
    
   String[] names = new String[destinations.size()*2];
   for(int i = 0; i != destinations.size(); i++)
   {
     names[i] = destinations.get(i).getName();
   }
     return names;
  }
  
  public String[] redeemMiles(int miles, int month)                              //takes inputed number of frequent flyer miles and the desired month and outputs
  {                                                                              //all destinations that can be redeemed and the seating class availible
    int start;
    int end;
    String[] finalDestinations = new String[18];
    ArrayList<Destination> list = getDestinations();
    

    for(int a = 0; a != 9; a++)
    {
      start = list.get(a).getFFStart();
      end = list.get(a).getFFEnd();
                                                           
      if(month>= start && month <= end)     //use frequent flyer
      {
        if((miles - list.get(a).getEconMiles()>0))
        {
          miles = miles- list.get(a).getEconMiles();
          finalDestinations[a] = list.get(a).getName();
                                                        System.out.println(list.get(a).getName()+" econ");
        } 
      }
      else                                 //use normal miles
      {
        if((miles - list.get(a).getMiles()>0))
        {
          miles = miles - list.get(a).getMiles();
          finalDestinations[a] = list.get(a).getName();
                                                        System.out.println(list.get(a).getName()+" normal");
        }
      }
    }
    for(int b =0; b != 9; b++)              //check for first class
    {
      if(finalDestinations[b] != null)
      {
      if((miles - list.get(b).getFirstClass() >0))
      {
        miles = miles- list.get(b).getFirstClass();
        finalDestinations[b+8] = "First class";
      }
      }
    }
    
    
    for(int c = 0; c <= 9; c++)                                       //place the formatted output in an array to be passed
    {
      if(finalDestinations[c] != null)
      {
        if(finalDestinations[c+8] != null)
        {
          finalDestinations[c] = "* A trip to " + finalDestinations[c] + " in " + finalDestinations[c+8];
        }
        else
        {
          finalDestinations[c] = "* A trip to " + finalDestinations[c] +" in Economy Clss";
        }
      }
   }
    remainingMiles = miles;
    
    return finalDestinations;
  }
  
  public static int getRemaningMiles()                               //returns remaining miles
  {
    return remainingMiles;
  }
}
