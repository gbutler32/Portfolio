/*CSCI 470    Assignment 8   Fall 2018
 * 
 * Developer: Gary Butler
 * 
 * Section: 1
 * 
 * Due Date/Time: 11/7/18 11:59pm
 * 
 * Purpose: This program uses a GUI to display a list of destinations from an input file and determine how many destinations a client
 * can travel in economy or first class
 */
import javax.swing.JFrame;

public class GUI
{
  public static void main(String[] args)
  {
    Test test = new Test();                          //create GUI object
    test.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);   //allow the window to close
    test.setSize(400,400);                                 //set default window size
    test.setVisible(true);                                 //allow the window to appear
  }
}
