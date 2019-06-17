/*CSCI 470    Assignment 7(12.9)   Fall 2018
 * 
 * Developer: Gary Butler
 * 
 * Section: 1
 * 
 * Due Date/Time: 11/7/18 11:59pm
 * 
 * Purpose: This program uses a GUI to display a dummy calculator that displays entered text and what button was pressed
 */
import javax.swing.JFrame;

public class GUICalcTest
{
  public static void main(String[] args)
  {
    GUICalc test = new GUICalc();                          //create GUI object
    test.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);   //allow the window to close
    test.setSize(210,200);                                 //set default window size
    test.setVisible(true);                                 //allow the window to appear
  }
}
