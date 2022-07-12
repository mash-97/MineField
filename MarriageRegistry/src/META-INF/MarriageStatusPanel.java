import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MarriageStatusPanel extends JPanel
{
	public JTextField dower_amount_field = new JTextField();
	public JTextField place_name_field = new JTextField();
	
	public JComboBox dayCB;
	public JComboBox monthCB;
	public JTextField year_field = new JTextField();
	
	public int amount_of_dower;
	public String place_name;
	public String date;
	
	public void produceInputInstance()
	{
		if(this.dower_amount_field.getText().length()>=1) this.amount_of_dower = Integer.parseInt(this.dower_amount_field.getText());
		if(this.place_name_field.getText().length()>=1) this.place_name = this.place_name_field.getText();
		this.date = this.dayCB.getItemAt(this.dayCB.getSelectedIndex())+"-"+this.monthCB.getItemAt(this.monthCB.getSelectedIndex())+"-"+this.year_field.getText();
		
		/********        Debug output 		*********/
		/********        Debug output 		*********/
		/********        Debug output 		*********/
		System.out.println("From MarraigeStatusPanel.java\n#Inside produceStatusResult() instance method:: Object: "+this);
		System.out.println("Amount of Dower: "+this.amount_of_dower);
		System.out.println("Place Name: "+this.place_name);
		System.out.println("Date: "+this.date);
	}
	
	public MarriageStatusPanel()
	{
		super(new GridLayout(3, 2, 30, 30));
		
		this.add(new JLabel("Date"));
		
		JPanel dtb_panel = new JPanel(new GridLayout(1, 7, 30, 100));
		dtb_panel.add(new JLabel("Day: "));
		String days[] = new String[31];
		for(int i=1; i<=31; i++) days[i-1] = Integer.toString(i);
		dayCB = new JComboBox(days);
		dtb_panel.add(dayCB);
		
		dtb_panel.add(new JLabel("Month: "));
		String months[] = new String[12];
		for(int i=1; i<=12; i++) months[i-1] = Integer.toString(i);
		monthCB = new JComboBox(months);
		dtb_panel.add(monthCB);
		
		dtb_panel.add(new JLabel("Year: "));
		dtb_panel.add(year_field);
		
		this.add(dtb_panel);
		
		this.add(new JLabel("Amount of Dower: "));
		this.add(dower_amount_field);
		
		this.add(new JLabel("Place Name: "));
		this.add(place_name_field);
	}
	
	public static void main(String [] a)
	{
		JFrame f = new JFrame("Personal Panel");
		f.setSize(750, 300);
		f.setLocationRelativeTo(null);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.add(new MarriageStatusPanel());
		f.setVisible(true);
	}
}
