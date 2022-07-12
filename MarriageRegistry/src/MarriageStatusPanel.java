import javax.swing.JPanel;
import javax.swing.JLabel;
import java.awt.Font;
import java.awt.Color;
import javax.swing.SwingConstants;
import javax.swing.JComboBox;
import javax.swing.JTextField;
import javax.swing.DefaultComboBoxModel;

public class MarriageStatusPanel extends JPanel
{
	private JTextField txtfPlace;
	private JTextField txtfAmountOfDower;
	private JTextField txtfYear;
	
	private JComboBox comboBoxDay;
	private JComboBox comboBoxMonth;
	
	public MarriageStatus getMarriageStatus()
	{
		Helper.sop("Inside marriage status panel's getMarriageStatus()");
		String date = this.comboBoxDay.getItemAt(this.comboBoxDay.getSelectedIndex())+"-"+
					  this.comboBoxMonth.getItemAt(this.comboBoxMonth.getSelectedIndex())+"-"+
					  this.txtfYear.getText();
		 
		double amountOfDower = Helper.sToD(this.txtfAmountOfDower.getText(), 2);
		Helper.sop("amountOfDower: "+amountOfDower);	 
		String place = this.txtfPlace.getText();

		return new MarriageStatus(date, place, "", amountOfDower);
	}
	/**
	 * Create the panel.
	 */
	public MarriageStatusPanel() {
		setLayout(null);
		int field_label_size = 18;
		int txtf_size = 15;
		
		JLabel label = new JLabel("Marriage Status");
		label.setHorizontalAlignment(SwingConstants.CENTER);
		label.setForeground(new Color(51, 51, 0));
		label.setFont(new Font("SansSerif", Font.BOLD, 28));
		label.setBounds(260, 13, 500, 55);
		add(label);
		
		comboBoxDay = new JComboBox();
		comboBoxDay.setModel(new DefaultComboBoxModel(new String[] {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"}));
		comboBoxDay.setFont(new Font("Arial", Font.PLAIN, txtf_size));
		comboBoxDay.setBounds(291, 108, 42, 41);
		add(comboBoxDay);
		
		JLabel label_1 = new JLabel("Day: ");
		label_1.setFont(new Font("Yu Gothic UI", Font.PLAIN, field_label_size));
		label_1.setBounds(237, 103, 67, 44);
		add(label_1);
		
		JLabel label_2 = new JLabel("Month: ");
		label_2.setFont(new Font("Yu Gothic UI", Font.PLAIN, field_label_size));
		label_2.setBounds(366, 103, 85, 41);
		add(label_2);
		
		comboBoxMonth = new JComboBox();
		comboBoxMonth.setModel(new DefaultComboBoxModel(new String[] {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"}));
		comboBoxMonth.setFont(new Font("Arial", Font.PLAIN, txtf_size));
		comboBoxMonth.setBounds(451, 106, 67, 44);
		add(comboBoxMonth);
		
		JLabel label_3 = new JLabel("Year: ");
		label_3.setFont(new Font("Yu Gothic UI", Font.PLAIN, field_label_size));
		label_3.setBounds(535, 103, 58, 41);
		add(label_3);
		
		txtfYear = new JTextField();
		txtfYear.setFont(new Font("Arial", Font.PLAIN, txtf_size));
		txtfYear.setColumns(10);
		txtfYear.setBounds(605, 108, 76, 41);
		add(txtfYear);
		
		JLabel lblDate = new JLabel("Date: ");
		lblDate.setHorizontalAlignment(SwingConstants.LEFT);
		lblDate.setFont(new Font("Yu Gothic UI", Font.BOLD, field_label_size));
		lblDate.setBounds(43, 108, 182, 41);
		add(lblDate);
		
		JLabel lblPlaceName = new JLabel("Place Name:  ");
		lblPlaceName.setHorizontalAlignment(SwingConstants.LEFT);
		lblPlaceName.setFont(new Font("Yu Gothic UI", Font.BOLD, field_label_size));
		lblPlaceName.setBounds(43, 205, 182, 41);
		add(lblPlaceName);
		
		txtfPlace = new JTextField();
		txtfPlace.setText(" gazipur, Dhaka");
		txtfPlace.setFont(new Font("Arial", Font.PLAIN, txtf_size));
		txtfPlace.setColumns(10);
		txtfPlace.setBounds(237, 205, 444, 41);
		add(txtfPlace);
		
		JLabel lblAmountOfDower = new JLabel("Amount of Dower: ");
		lblAmountOfDower.setHorizontalAlignment(SwingConstants.LEFT);
		lblAmountOfDower.setFont(new Font("Yu Gothic UI", Font.BOLD, field_label_size));
		lblAmountOfDower.setBounds(332, 294, 261, 41);
		add(lblAmountOfDower);
		
		txtfAmountOfDower = new JTextField();
		txtfAmountOfDower.setFont(new Font("Arial", Font.PLAIN, txtf_size));
		txtfAmountOfDower.setColumns(10);
		txtfAmountOfDower.setBounds(237, 349, 378, 41);
		add(txtfAmountOfDower);
		
		JLabel lblTk = new JLabel("TK");
		lblTk.setHorizontalAlignment(SwingConstants.LEFT);
		lblTk.setFont(new Font("Yu Gothic UI", Font.BOLD, field_label_size));
		lblTk.setBounds(627, 349, 182, 41);
		add(lblTk);

	}
	public void initializeFields()
	{
		this.txtfPlace.setText("");
		this.txtfAmountOfDower.setText("");
		this.txtfYear.setText("");
	}
}
