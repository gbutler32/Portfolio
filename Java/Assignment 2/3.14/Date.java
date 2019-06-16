public class Date
{
  private int month;
  private int day;
  private int year;
  
  public Date(int month, int day, int year)
  {
    this.month = month;
    this.day = day;
    this.year = year;
  }
  
  //gets
  public int getMonth()
  {
    return month;
  }
  
  public int getDay()
  {
    return day;
  }
  
  public int getYear()
  {
    return year;
  }
  
  //sets
  public String setMonth(int inMonth)
  {
    if(inMonth > 12 || inMonth < 1)
    {
      return "Incorrect month";
    }
    else
    {
      month = inMonth;
      return "Month set";
    }
  }
  
  public String setDay(int inDay)
  {
    if(inDay > 31 || inDay < 0)
    {
      return "Incorrect day";
    }
    else
    {
    day=inDay;
    return "Day set";
    }
  }
  
  public String setYear(int inYear)
  {
    if(inYear < 0)
    {
      return "Incorrect year";
    }
    else
    {
    year = inYear;
    return "Year set";
    }
  }
  
  //Display formatted date
  public String displayDate()
  {
    return (month + "/" + day + "/" + year);
  }
}
