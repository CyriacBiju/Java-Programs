import java.applet.*;
import java.awt.*;
import java.awt.Event;


public class helloApplet extends Applet{

    TextField t1,t2;
    public void init() {
        t1 = new TextField(8);
        t2 = new TextField(8);
        add(t1);
        add(t2);
        t1.setText("0");
        t2.setText("0");
    }
    public void paint(Graphics g){
        g.drawString("Enter the 2 numbers",5,50);
        int x,y,z;
        String s1 = new String();
        String s2 = new String();
        String s = new String();
        s1 = t1.getText();
        s2 = t2.getText();
        x = Integer.parseInt(s1);
        y = Integer.parseInt(s2);
        z = x + y;
        s = "The sum is:" + String.valueOf(z);
        g.drawString(s,10,100);

    
    }
    public boolean action(Event event, Object object)
    {
        repaint();
        return true;
    }
}