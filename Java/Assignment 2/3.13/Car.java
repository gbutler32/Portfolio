public class Car
{
  private String type;
  private String year;
  private double price;
  
  public Car(String type, String year, double price)
  {
    this.type = type;
    this.year = year;
    this.price = price;
  }
  
  //gets
  public String getType()
  {
    return type;
  }
  
  public String getYear()
  {
    return year;
  }
  
  public double getPrice()
  {
    return price;
  }
  
  //sets
  public void setType(String inType)
  {
    type = inType;
  }
  
  public void setYear(String inYear)
  {
   year = inYear;
  }
  
  public void setPrice(double inPrice)
  {
    if(inPrice < 0)
    {
      price = price;
    }
    else
    {
    price = inPrice;
    }
	
  }
}
