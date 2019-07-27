import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class swingevent extends JFrame implements ActionListener{
    JTextField t1,t2,t3,t4,t5,t;
    JLabel l1,l2,l3,l4,l5,l,l6;
    JButton b;
    float y;
    public swingevent(){
        setLayout(new GridLayout(7,2));
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        t = new JTextField(8);
        t1 = new JTextField(8);
        t2 = new JTextField(8);
        t3 = new JTextField(8);
        t4 = new JTextField(8);
        t5 = new JTextField(8);
        l = new JLabel("Enter your name");
        l1 = new JLabel("Enter mark");
        l2 = new JLabel("Enter mark");
        l3 = new JLabel("Enter mark");
        l4 = new JLabel("Enter mark");
        l5 = new JLabel("Enter mark");
        l6 = new JLabel("    ");
        b = new JButton("Calculate");
        add(l);
        add(t);
        add(l1);
        add(t1);
        add(l2);
        add(t2); 
        add(l3);
        add(t3);
        add(l4);
        add(t4);
        add(l5);
        add(t5);
        add(b);
        add(l6);
        
        try{
            t1.setText("");
            t2.setText("");
            t3.setText("");
            t4.setText("");
            t5.setText("");
            b.addActionListener(this);
        }
        catch(NumberFormatException e){
            System.out.println("Parameter not correct");
        }
       
        setTitle("Average mark");
        setVisible(true);
        this.pack();
        }
    public static void main(String args[])
    {
        new swingevent();
    } 
    public void actionPerformed(ActionEvent e){
        int x = Integer.parseInt(t1.getText());
        x = x + Integer.parseInt(t2.getText());
        x = x + Integer.parseInt(t3.getText());
        x = x + Integer.parseInt(t4.getText());
        x = x + Integer.parseInt(t5.getText());
        y = x/5;
        l6.setText(String.valueOf(y));
        JOptionPane.showMessageDialog(null, "You clicked me!");

    }
} 