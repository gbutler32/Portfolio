public class USMoney
{
  private int dollars;
  private int cents;
  
  public USMoney(int dollars, int cents)
  {
    this.setDollars(dollars);
    this.setCents(cents);
  }
  
  //gets
  public int getDollars()
  {
    return dollars;
  }
  
  public int getCents()
  {
    return cents;
  }
  
  //sets
  public void setDollars(int inDollars)
  {
    dollars = inDollars;
  }
  
  public void setCents(int inCents)
  {
    if(inCents >= 100)              //add a dollar and subtract 100 cents
    {
      dollars++;
      inCents -= 100;
      cents = inCents;
    }
    else if(inCents < 0)            //check for negative input
    {
      cents = 0;
    }
    else
    {
      cents = inCents;
    }
  }
  
  public USMoney plus(USMoney in)
  {
    int tmpDollars;                                   //temp varibles to hold sums
    int tmpCents;                                     //
    
    tmpDollars = this.getDollars() + in.getDollars(); //temp dollars = calling objects dollars + parameters dollars
    tmpCents = this.getCents() + in.getCents();       //temp cents = calling objects cents + parameters cents
    
    USMoney temp = new USMoney(tmpDollars,tmpCents);  //new object declared with the sums
    return temp;
  }
}
