/*CSCI 470    Assignment 6   Fall 2018
 * 
 * Developer: Gary Butler
 * 
 * Section: 1
 * 
 * Due Date/Time: 10/19/18 11:59pm
 * 
 * Purpose: This program creates objects that impliment the payable class and outputs them. If the class if of the
 * type "BasePlusCommissionEmployee" the base salary is increased by 10%
 */

public class SalariedEmployee extends Employee 
{
   private double weeklySalary;

   // constructor
   public SalariedEmployee(String firstName, String lastName, 
      String socialSecurityNumber, double weeklySalary)
   {
      super(firstName, lastName, socialSecurityNumber); 

      if (weeklySalary < 0.0)
         throw new IllegalArgumentException(
            "Weekly salary must be >= 0.0");

      this.weeklySalary = weeklySalary;
   } 

   // set salary
   public void setWeeklySalary(double weeklySalary)
   {
      if (weeklySalary < 0.0)
         throw new IllegalArgumentException(
            "Weekly salary must be >= 0.0");

      this.weeklySalary = weeklySalary;
   } 

   // return salary
   public double getWeeklySalary()
   {
      return weeklySalary;
   } 

   // calculate earnings; implement interface Payable method that was
   // abstract in superclass Employee                                
   @Override                                                         
   public double getPaymentAmount()                                  
   {                                                                 
      return getWeeklySalary();                                      
   } 

   // return String representation of SalariedEmployee object   
   @Override                                                    
   public String toString()                                     
   {                                                            
      return String.format("salaried employee: %s%n%s: $%,.2f",
         super.toString(), "weekly salary", getWeeklySalary());
   } 
} // end class SalariedEmployee
