import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class PersonPanel extends JPanel
{
	public static String Bridegroom = "Bridegroom";
	public static String Bride = "Bride";
	public static String Wakil = "Wakil";
	public static String Witness = "Witness";
	
	public JTextField name_field = new JTextField();
	public JTextField father_name_field = new JTextField();
	public JTextField mother_name_field = new JTextField();
	public JTextField address_field = new JTextField();
	//public JTextField gender_field = new JTextField();
	
	public JComboBox genderCB;
	public JComboBox dayCB;
	public JComboBox monthCB;
	public JTextField year_field = new JTextField();
	
	
	public PersonPanel(String person_type_name)
	{
		super(new BorderLayout());
		
		JLabel details_type_label = new JLabel(person_type_name+" Details");
		details_type_label.setHorizontalAlignment(JLabel.CENTER);
		details_type_label.setPreferredSize(new Dimension(50, 50));
		details_type_label.setFont(new Font("TimesRoman", Font.BOLD, 20));
		
		this.add(details_type_label, BorderLayout.NORTH);
		
		JPanel input_panel = new JPanel(new GridLayout(6, 2, 20, 20));
		
		input_panel.add(new JLabel("Name: "));
		input_panel.add(name_field);
		
		input_panel.add(new JLabel("Gender: "));
		String genders[] = {"male", "female", "other"};
		genderCB = new JComboBox(genders);
		input_panel.add(genderCB);
		
		input_panel.add(new JLabel("Father's Name: "));
		input_panel.add(father_name_field);
		
		input_panel.add(new JLabel("Mother's Name: "));
		input_panel.add(mother_name_field);
		
		input_panel.add(new JLabel("Date of Birth: "));
		JPanel dtb_panel = new JPanel(new GridLayout(1, 7, 20, 10));
		
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
		
		input_panel.add(dtb_panel);
		
		input_panel.add(new JLabel("Address: "));
		input_panel.add(address_field);
		
		this.add(input_panel, BorderLayout.CENTER);
		
	}
	
	public Person parsePersonFromPersonPanel()
	{
		String date = this.dayCB.getItemAt(this.dayCB.getSelectedIndex())+"-"+this.monthCB.getItemAt(this.monthCB.getSelectedIndex())+
			"-"+this.year_field.getText();
		String gender = (String) this.genderCB.getItemAt(this.genderCB.getSelectedIndex());
		Person person = new Person(StringOperations.namify(this.name_field.getText()), gender, 
				StringOperations.namify(this.father_name_field.getText()), 
				StringOperations.namify(this.mother_name_field.getText()), date, this.address_field.getText());
		return person;
	}
	
	public static void main(String [] a)
	{
		JFrame f = new JFrame("Personal Panel");
		f.setSize(750, 300);
		f.setLocationRelativeTo(null);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.add(new PersonPanel("Birde"));
		f.setVisible(true);
	}
}
		
	
	
