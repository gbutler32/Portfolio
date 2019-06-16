public class Account
{
  
  private String name;
  private double balance;
  private String error = "Withdrawl ammount exceeds balance";
  
  public Account(String name, double balance)
  {
    this.name =name;
    
    if(balance > 0.0)
    {
      this.balance = balance;
    }
  }
  
  public void deposit(double depositAmount)
  {
    if(depositAmount > 0.0)
      balance =balance + depositAmount;
  }
  
  public double getBalance()
  {
    return balance;
  }
  
  public void setName(String name)
  {
    this.name = name;
  }
  
  public String getName()
  {
    return name;
  }
  
  public String withdraw(double request)
  {
    if(request > balance)
    {
      return error;
    }
    else
    {
      balance -= request;
      return ("New balance: "+getBalance());
    }
    }
}
