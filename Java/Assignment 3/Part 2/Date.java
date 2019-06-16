public class Date
{
  private int day;
  private int month;
  private int year;
  
  public Date(int day, int month, int year)
  {
    this.day = day;
    this.month = month;
    this.year = year;
  }
  
  //sets
  public void setDay(int day)
  {
    this.day = day;
  }
  
  public void setMonth(int month)
  {
    this.month = month;
  }
  
  public void setYear(int year)
  {
    this.year = year;
  }
  
  //gets
  public int getDay()
  {
    return day;
  }
  
  public int getMonth()
  {
    return month;
  }
  
  public int getYear()
  {
    return year;
  }
  
  public int daysSinceJan1()
  {
    int daysSince = day;
    int tempMonth = month;                       //used to determine total number of days
    while(tempMonth != 0)
    {
      switch (tempMonth)
      {
        case 12:
          break;                                   //skip December
        case 11:                                   //November has 30 days
          daysSince += 30;
          break;
        case 10:                                   //October has 30 days
          daysSince += 30;
          break;
        case 9:                                    //September has 31 days
          daysSince += 31;
          break;
        case 8:                                    
          daysSince += 31;                         //August has 31 days
          break;
        case 7:
          daysSince += 31;                         //July has 31 days
          tempMonth--;
          break;
        case 6:
          daysSince += 30;                         //June has 30 days
          break;
        case 5:
          daysSince += 31;                         //May has 31 days
          break;
        case 4: 
          daysSince += 30;                         //April has 30 days
          break;
        case 3:
          daysSince += 31;                         //March has 31 days
          break;
        case 2:
          daysSince += 28;                         //Februrary has 28 days
          break;
        case 1:
          break;                                   //skip January
      }
      tempMonth--;
    }
    if((year % 4 == 0) && (year % 100 != 0))         //check for leap year
    {
      daysSince ++;
    }
    return daysSince;
  }
}
