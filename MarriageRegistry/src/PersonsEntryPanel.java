import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import java.awt.Font;
import java.awt.Color;
import javax.swing.JTextField;
import javax.swing.JComboBox;
import javax.swing.DefaultComboBoxModel;

public class PersonsEntryPanel extends JPanel
{
	private JTextField txtfName;
	private JTextField txtfFatherName;
	private JTextField txtfMotherName;
	private JTextField txtfAddress;
	private JTextField txtfYear;
	
	public JComboBox comboBoxGender;
	public JComboBox comboBoxDay;
	public JComboBox comboBoxMonth;
	
	public Person getPerson()
	{
		String gender = (String) this.comboBoxGender.getItemAt(this.comboBoxGender.getSelectedIndex());
		String birth_date = this.comboBoxDay.getItemAt(this.comboBoxDay.getSelectedIndex())+"-"+
					  this.comboBoxMonth.getItemAt(this.comboBoxMonth.getSelectedIndex())+"-"+
					  this.txtfYear.getText();
					  
		String name = this.txtfName.getText();
		String father_name = this.txtfFatherName.getText();
		String mother_name = this.txtfMotherName.getText();
		String address = this.txtfAddress.getText();

		Photo photo = new Photo(Photo.DEFAULT_IMAGE_FILE_SOURCE);
		Person person = new Person(name, gender, father_name, mother_name, birth_date, address, photo);
		return person;
	}
	
	/**
	 * Create the panel.
	 */
	public PersonsEntryPanel(String name) {
		setLayout(null);
		
		int field_label_size = 18;
		int txtf_size = 15;
		
		JLabel lblPersonsDetails = new JLabel(name+"'s Details");
		lblPersonsDetails.setForeground(new Color(51, 51, 0));
		lblPersonsDetails.setFont(new Font("SansSerif", Font.BOLD, 28));
		lblPersonsDetails.setHorizontalAlignment(SwingConstants.CENTER);
		lblPersonsDetails.setBounds(260, 13, 500, 55);
		add(lblPersonsDetails);
		
		JLabel lblName = new JLabel("Name: ");
		lblName.setHorizontalAlignment(SwingConstants.LEFT);
		lblName.setFont(new Font("Yu Gothic UI", Font.BOLD, field_label_size));
		lblName.setBounds(42, 122, 190, 41);
		add(lblName);
		
		JLabel lblFatherName = new JLabel("Father's Name: ");
		lblFatherName.setHorizontalAlignment(SwingConstants.LEFT);
		lblFatherName.setFont(new Font("Yu Gothic UI", Font.BOLD, field_label_size));
		lblFatherName.setBounds(42, 176, 182, 41);
		add(lblFatherName);
		
		JLabel lblMotherName = new JLabel("Mother's Name: ");
		lblMotherName.setHorizontalAlignment(SwingConstants.LEFT);
		lblMotherName.setFont(new Font("Yu Gothic UI", Font.BOLD, field_label_size));
		lblMotherName.setBounds(42, 230, 182, 41);
		add(lblMotherName);
		
		JLabel lblGender = new JLabel("Gender: ");
		lblGender.setHorizontalAlignment(SwingConstants.LEFT);
		lblGender.setFont(new Font("Yu Gothic UI", Font.BOLD, field_label_size));
		lblGender.setBounds(42, 284, 182, 41);
		add(lblGender);
		
		JLabel lblBirthDate = new JLabel("Birth Date: ");
		lblBirthDate.setHorizontalAlignment(SwingConstants.LEFT);
		lblBirthDate.setFont(new Font("Yu Gothic UI", Font.BOLD, field_label_size));
		lblBirthDate.setBounds(42, 338, 182, 41);
		add(lblBirthDate);
		
		JLabel lblAddress = new JLabel("Address: ");
		lblAddress.setHorizontalAlignment(SwingConstants.LEFT);
		lblAddress.setFont(new Font("Yu Gothic UI", Font.BOLD, field_label_size));
		lblAddress.setBounds(42, 392, 182, 41);
		add(lblAddress);
		
		txtfName = new JTextField();
		txtfName.setText(" person's name");
		txtfName.setFont(new Font("Arial", Font.PLAIN, txtf_size));
		txtfName.setBounds(236, 122, 285, 41);
		add(txtfName);
		txtfName.setColumns(10);
		
		txtfFatherName = new JTextField();
		txtfFatherName.setText(" father's name");
		txtfFatherName.setFont(new Font("Arial", Font.PLAIN, txtf_size));
		txtfFatherName.setColumns(10);
		txtfFatherName.setBounds(236, 176, 285, 41);
		add(txtfFatherName);
		
		txtfMotherName = new JTextField();
		txtfMotherName.setFont(new Font("Arial", Font.PLAIN, txtf_size));
		txtfMotherName.setText(" mother's name");
		txtfMotherName.setColumns(10);
		txtfMotherName.setBounds(236, 230, 285, 41);
		add(txtfMotherName);
		
		txtfAddress = new JTextField();
		txtfAddress.setText(" gazipur, Dhaka");
		txtfAddress.setFont(new Font("Arial", Font.PLAIN, txtf_size));
		txtfAddress.setColumns(10);
		txtfAddress.setBounds(236, 397, 444, 41);
		add(txtfAddress);
		
		JLabel lblDay = new JLabel("Day: ");
		lblDay.setFont(new Font("Yu Gothic UI", Font.PLAIN, field_label_size));
		lblDay.setBounds(236, 338, 69, 44);
		add(lblDay);
		
		comboBoxDay = new JComboBox();
		comboBoxDay.setFont(new Font("Arial", Font.PLAIN, txtf_size));
		comboBoxDay.setModel(new DefaultComboBoxModel(new String[] {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"}));
		comboBoxDay.setBounds(290, 343, 48, 41);
		add(comboBoxDay);
		
		JLabel lblMonth = new JLabel("Month: ");
		lblMonth.setFont(new Font("Yu Gothic UI", Font.PLAIN, field_label_size));
		lblMonth.setBounds(365, 338, 90, 41);
		add(lblMonth);
		
		comboBoxMonth = new JComboBox();
		comboBoxMonth.setFont(new Font("Arial", Font.PLAIN, txtf_size));
		comboBoxMonth.setModel(new DefaultComboBoxModel(new String[] {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"}));
		comboBoxMonth.setBounds(450, 341, 67, 44);
		add(comboBoxMonth);
		
		JLabel labelYear = new JLabel("Year: ");
		labelYear.setFont(new Font("Yu Gothic UI", Font.PLAIN, field_label_size));
		labelYear.setBounds(534, 338, 62, 41);
		add(labelYear);
		
		txtfYear = new JTextField();
		txtfYear.setFont(new Font("Arial", Font.PLAIN, txtf_size));
		txtfYear.setBounds(604, 343, 76, 41);
		add(txtfYear);
		txtfYear.setColumns(10);
		
		comboBoxGender = new JComboBox();
		comboBoxGender.setFont(new Font("Arial", Font.PLAIN, field_label_size));
		comboBoxGender.setModel(new DefaultComboBoxModel(new String[] {"male", "female", "other"}));
		comboBoxGender.setBounds(236, 284, 285, 44);
		add(comboBoxGender);
		
		JLabel lblPersonsImage = new JLabel("image");
		lblPersonsImage.setBackground(new Color(0, 51, 51));
		lblPersonsImage.setFont(new Font("Arial", Font.PLAIN, field_label_size));
		lblPersonsImage.setHorizontalAlignment(SwingConstants.CENTER);
		lblPersonsImage.setBounds(637, 123, 182, 147);
		add(lblPersonsImage);
	}
	
	public void initializeFields()
	{
		this.txtfName.setText("");
		this.txtfFatherName.setText("");
		this.txtfMotherName.setText("");
		this.txtfYear.setText("");
		this.txtfAddress.setText("");
	}
}       
