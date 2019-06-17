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

public abstract class Employee implements Payable
{
   private final String firstName;
   private final String lastName;
   private final String socialSecurityNumber;

   // constructor
   public Employee(String firstName, String lastName, 
      String socialSecurityNumber)
   {
      this.firstName = firstName;
      this.lastName = lastName;
      this.socialSecurityNumber = socialSecurityNumber;
   } 

   // return first name
   public String getFirstName()
   {
      return firstName;
   } 

   // return last name
   public String getLastName()
   {
      return lastName;
   } 

   // return social security number
   public String getSocialSecurityNumber()
   {
      return socialSecurityNumber;
   } 

   // return String representation of Employee object
   @Override
   public String toString()
   {
      return String.format("%s %s%nsocial security number: %s", 
         getFirstName(), getLastName(), getSocialSecurityNumber());
   }

   // Note: We do not implement Payable method getPaymentAmount here so 
   // this class must be declared abstract to avoid a compilation error.
} // end abstract class Employee
