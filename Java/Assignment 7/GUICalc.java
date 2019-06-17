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
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.GridLayout;
import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JOptionPane;
import java.awt.BorderLayout;

public class GUICalc extends JFrame
{
  private final JButton seven;   //button declaration
  private final JButton eight;
  private final JButton nine;
  private final JButton slash;
  private final JButton four;
  private final JButton five;
  private final JButton six;
  private final JButton star;
  private final JButton one;
  private final JButton two;
  private final JButton three;
  private final JButton dash;
  private final JButton zero;
  private final JButton dot;
  private final JButton equal;
  private final JButton plus;
  
  private final JPanel top;     //text input panel declaration
  private final JPanel body;    //button input panel declaration
  
  private final JTextField input; //text input line declaration
  
  GUICalc()
  {
    super("Calculator");          //window header
    
    top = new JPanel();
    body = new JPanel();
    
    
    input = new JTextField(16);   //blank text field
    top.add(input);
    
    seven = new JButton("7");     //button display character declaration
    eight = new JButton("8");
    nine = new JButton("9");
    slash = new JButton("/");
    four = new JButton("4");
    five = new JButton("5");
    six = new JButton("6");
    star = new JButton("*");
    one = new JButton("1");
    two = new JButton("2");
    three = new JButton("3");
    dash = new JButton("-");
    zero = new JButton("0");
    dot = new JButton(".");
    equal = new JButton("=");
    plus = new JButton("+");
    
    body.add(seven);              //add buttons to the main panel
    body.add(eight);
    body.add(nine);
    body.add(slash);
    body.add(four);
    body.add(five);
    body.add(six);
    body.add(star);
    body.add(one);
    body.add(two);
    body.add(three);
    body.add(dash);
    body.add(zero);
    body.add(dot);
    body.add(equal);
    body.add(plus);
    
    add(top,BorderLayout.PAGE_START);        //add panels to main JFrame
    add(body,BorderLayout.CENTER);
    
    TextFieldHandler tHandle = new TextFieldHandler();    //listener for text field
    ButtonHandler handler = new ButtonHandler();          //listener for each button
    
    input.addActionListener(tHandle);                     //attach a listener to each button and text field
    seven.addActionListener(handler);
    eight.addActionListener(handler);
    nine.addActionListener(handler);
    slash.addActionListener(handler);
    four.addActionListener(handler);
    five.addActionListener(handler);
    six.addActionListener(handler);
    star.addActionListener(handler);
    one.addActionListener(handler);
    two.addActionListener(handler);
    three.addActionListener(handler);
    dash.addActionListener(handler);
    zero.addActionListener(handler);
    dot.addActionListener(handler);
    equal.addActionListener(handler);
    plus.addActionListener(handler);
  }
  private class TextFieldHandler implements ActionListener    //allow a popup window when text is entered and return is pressed
  {
    @Override
    public void actionPerformed(ActionEvent event)
    {
      String output;
      
      output = ("input: "+event.getActionCommand());
      
      JOptionPane.showMessageDialog(null,output);
    }
  }
  private class ButtonHandler implements ActionListener     //allow a popup window on each button press
  {
    @Override
    public void actionPerformed(ActionEvent event)
    {
      String output;
      
      output = ("You pressed: "+event.getActionCommand());
      
      JOptionPane.showMessageDialog(null,output);
    }
  }
}
