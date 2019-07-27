import java.awt.*;
import java.awt.event.*;


public class awtevent extends Frame implements ActionListener{
    TextField t1,t2,t3,t4,t5,t;
    Label l1,l2,l3,l4,l5,l,l6;
    Button b;
    
    float y;
    public awtevent(){
        setLayout(new GridLayout(7,2));
        t = new TextField(8);
        t1 = new TextField(8);
        t2 = new TextField(8);
        t3 = new TextField(8);
        t4 = new TextField(8);
        t5 = new TextField(8);
        l = new Label("Enter your name");
        l1 = new Label("Enter mark");
        l2 = new Label("Enter mark");
        l3 = new Label("Enter mark");
        l4 = new Label("Enter mark");
        l5 = new Label("Enter mark");
        l6 = new Label("    ");
        b = new Button("Calculate");
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
        setSize(500, 500);
        setTitle("Average mark");
        setVisible(true);
    }
    public static void main(String args[])
    {
        new awtevent();
    } 
    public void actionPerformed(ActionEvent e){
        int x = Integer.parseInt(t1.getText());
        x = x + Integer.parseInt(t2.getText());
        x = x + Integer.parseInt(t3.getText());
        x = x + Integer.parseInt(t4.getText());
        x = x + Integer.parseInt(t5.getText());
        y = x/5;
        l6.setAlignment(Label.CENTER);
        l6.setText(String.valueOf(y));
        
    }
   
    
}