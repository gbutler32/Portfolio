/*CSCI 470    Assignment 7(12.8)   Fall 2018
 * 
 * Developer: Gary Butler
 * 
 * Section: 1
 * 
 * Due Date/Time: 11/7/18 11:59pm
 * 
 * Purpose: This program uses a GUI to display two check boxes, two text input fields, and three buttons
 */

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.GridLayout;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JCheckBox;
import javax.swing.JButton;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import javax.swing.JOptionPane;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

public class GUI1 extends JFrame
{
  
  private final JCheckBox snapToGrid;    //check box declaration
  private final JCheckBox showGrid;
  
  private final JTextField xInput;       //text field declaration
  private final JTextField yInput;
  private final JLabel x;
  private final JLabel y;
  
  private final JButton ok;               //button declaration
  private final JButton cancel;
  private final JButton help;
  
  private final GridLayout layout1;       //two layouts to display a two 2x2 sections and one 3x3 section
  private final GridLayout layout2;
  
  private final JPanel left;              //three panels for the checkboxes, textfields, and buttons
  private final JPanel center;
  private final JPanel right;
  
  GUI1()
  {  
    super("Allign");                      //set the window header
    
    left = new JPanel();                 //panel declaration
    center = new JPanel();
    right = new JPanel();
    
    layout1 = new GridLayout(1,2,5,5);     //set grid pattern for checkboxes
    setLayout(layout1);
    
    snapToGrid = new JCheckBox("Snap To Grid\n");  //declare and add snapToGrid checkbox
    left.add(snapToGrid);
    
    showGrid = new JCheckBox("Show Grid\n");       //delcare and add showGrid checkbox
    left.add(showGrid);
    
    layout2 = new GridLayout(1,2,5,5);          //second grid pattern for text input fields
    setLayout(layout2);
    
    x = new JLabel("X:");                      //declare and add two text fields with lables
    center.add(x);
    xInput = new JTextField("         ");
    center.add(xInput);
    
    y = new JLabel("Y:");
    center.add(y);
    yInput = new JTextField("         ");
    center.add(yInput);
    
    ok = new JButton("Ok");                     //delcare button display strings
    right.add(ok);
    cancel = new JButton("Cancel");
    right.add(cancel);
    help = new JButton("Help");
    right.add(help);
    
    add(left,BorderLayout.LINE_START);            //add panels to main JFrame
    add(center,BorderLayout.CENTER);
    add(right,BorderLayout.LINE_END);
    
    TextFieldHandler tHandle = new TextFieldHandler();  //delcare listeners for text input
    xInput.addActionListener(tHandle);
    yInput.addActionListener(tHandle);
    
    ButtonHandler handler = new ButtonHandler();       //declare listeners for buttons
    ok.addActionListener(handler);
    cancel.addActionListener(handler);
    help.addActionListener(handler);
    
    CheckBoxHandler cHandle = new CheckBoxHandler();    //delcare listeners for check boxes
    snapToGrid.addItemListener(cHandle);
    showGrid.addItemListener(cHandle);
    
  }
  private class TextFieldHandler implements ActionListener   //allow a popup window for entered string to be output
  {
    @Override
    public void actionPerformed(ActionEvent event)
    {
      String output = "";
      
      if(event.getSource() == xInput)
      {
        output = ("xInput: " + event.getActionCommand());
      }
      
      if(event.getSource() == yInput)
      {
        output = ("yInput: " + event.getActionCommand());
      }
      
      JOptionPane.showMessageDialog(null,output);
    }
  }
  private class ButtonHandler implements ActionListener   //allow a popup window for each button pressed
  {
    @Override
    public void actionPerformed(ActionEvent event)
    {
      String output;
      
      output = ("You pressed: "+event.getActionCommand());
      
      JOptionPane.showMessageDialog(null,output);
    }
  }
  
  private class CheckBoxHandler implements ItemListener    //allow a popup window for each checkbox checked
  {
    @Override
    public void itemStateChanged(ItemEvent event)
    {
      String output = "";
      if(snapToGrid.isSelected())
      {
        output = ("snapToGrid checked");
        JOptionPane.showMessageDialog(null,output);
      }
      else if(showGrid.isSelected())
      {
        output = ("showGrid checked");
        JOptionPane.showMessageDialog(null,output);
      }
    }
  }
}
