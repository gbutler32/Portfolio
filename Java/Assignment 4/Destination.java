/*CSCI 470    Assignment 4   Fall 2018
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

public class Destination implements Comparable
{
  private String name;
  private int miles;
  private int econMiles;
  private int firstClass;
  private int ffStart;
  private int ffEnd;
  
  public Destination(String name, int miles, int econMiles, int firstClass, int ffStart, int ffEnd)
  {
    this.name = name;
    this.miles = miles;
    this.econMiles = econMiles;
    this.firstClass = firstClass;
    this.ffStart = ffStart;
    this.ffEnd = ffEnd;
  }
  
  //gets
  public String getName()
  {
    return name;
  }
  
  public int getMiles()
  {
    return miles;
  }
  
  public int getEconMiles()
  {
    return econMiles;
  }
  
  public int getFirstClass()
  {
    return firstClass;
  }
  
  public int getFFStart()
  {
    return ffStart;
  }
  
  public int getFFEnd()
  {
    return ffEnd;
  }
  
  //sets
  public void setName(String inName)
  {
    name = inName;
  }
  
  public void setMiles(int inMiles)
  {
    miles = inMiles;
  }
  public void setEconMiles(int inEconMiles)
  {
    econMiles = inEconMiles;
  }
  
  public void setFirstClass(int inFirstClass)
  {
    firstClass = inFirstClass;
  }
  
  public void setFFStart(int inFFStart)
  {
    ffStart = inFFStart;
  }
  
  public void setFFEnd(int inFFEnd)
  {
    ffEnd = inFFEnd;
  }
  
  @Override                                             //sorting fuction based on miles
  public int compareTo(Object o)
  {
    Destination i = (Destination)o;
    if(this.getMiles() < i.getMiles())
    {
      return -1;
    }
    else if(this.getMiles() > i.getMiles())
    {
      return 0;
    }
    else
      return 0;
  }
}
