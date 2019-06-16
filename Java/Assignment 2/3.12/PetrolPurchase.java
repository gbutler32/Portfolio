public class PetrolPurchase
{
  private String location;
  private String type;
  private int quantity;
  private int price;
  private double discount;
  private double purchase;
  
  public PetrolPurchase(String location, String type, int quantity, int price, double discount)
  {
    this.location = location;
    this.type = type;
    this.quantity = quantity;
    this.price = price;
    this.discount = discount;
  }
  
  //gets
  public String getLocation()
  {
    return location;
  }
  
  public String getType()
  {
    return type;
  }
  
  public int getQuantity()
  {
    return quantity;
  }
  
  public int getPrice()
  {
    return price;
  }
  
  public double getDiscount()
  {
    return discount;
  }
  
  //sets
  public void setLocation(String inLocation)
  {
    location = inLocation;
  }
  
  public void setType(String inType)
  {
    type = inType;
  }
  
  public void setQuantity(int inQuantity)
  {
    quantity = inQuantity;
  }
  
  public void setPrice(int inPrice)
  {
    price = inPrice;
  }
  
  public void setDiscount(double inDiscount)
  {
    discount = inDiscount;
  }
  
  //Calcuate total transaction ammount
  public double getPurchaseAmmount()
  {
    purchase = (quantity * price) - discount;
    return purchase;
  }
}
