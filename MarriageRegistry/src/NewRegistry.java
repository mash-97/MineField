import javax.swing.GroupLayout.*;
import javax.swing.LayoutStyle.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.sql.*;

public class NewRegistry extends JPanel {
	private User dbuser = new User("tash", "tash");
	private PersonsEntryPanel bridegroomPersonalPanel = new PersonsEntryPanel("Bridegroom");
	private PersonsEntryPanel bridePersonalPanel = 		new PersonsEntryPanel("Bride");
	private PersonsEntryPanel wakilPersonalPanel = 		new PersonsEntryPanel("Wakil");
	private PersonsEntryPanel witness1PersonalPanel = 	new PersonsEntryPanel("Witness no. 1");
	private PersonsEntryPanel witness2PersonalPanel = 	new PersonsEntryPanel("Witness no. 2");
	private MarriageStatusPanel msp = new MarriageStatusPanel();
	
	private MarriageRegistry M;
	private Person bridegroom;
	private Person bride;
	private Person wakil;
	private Person witness1;
	private Person witness2;
	private MarriageStatus MS;
	
	private CardLayout personsCardLayout = new CardLayout(40, 30);
	private JPanel pclPanel = new JPanel(personsCardLayout);
	private int countLayout = 1;
	private final int Total_Layout =6;
	/**
	 * Create the panel.
	 */
	public NewRegistry() 
	throws Exception
	{
		setLayout(new BorderLayout(0, 0));
		
		pclPanel.add(bridegroomPersonalPanel, "1");
		pclPanel.add(bridePersonalPanel, "2");
		pclPanel.add(wakilPersonalPanel, "3");
		pclPanel.add(witness1PersonalPanel, "4");
		pclPanel.add(witness2PersonalPanel, "5");
		pclPanel.add(msp, "6");
		this.add(pclPanel, BorderLayout.CENTER);
		
		JLabel lblNewRegistry = new JLabel("New Registry");
		lblNewRegistry.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewRegistry.setForeground(new Color(102, 102, 153));
		lblNewRegistry.setFont(new Font("Footlight MT Light", Font.BOLD, 40));
		add(lblNewRegistry, BorderLayout.NORTH);
		
		
		JPanel panel = new JPanel();
		add(panel, BorderLayout.SOUTH);
		
		JButton buttonNext = new JButton("Next");
		buttonNext.addActionListener((e)->
			{
				try{listen(1);}
				catch(Exception ee){}
			}
		);
		buttonNext.setForeground(new Color(0, 204, 0));
		buttonNext.setFont(new Font("Arial", Font.BOLD, 20));
		
		JButton buttonPrevious = new JButton("Previous");
		buttonPrevious.addActionListener((e)->
			{
				try{listen(0);}
				catch(Exception ex){}
			}
		);
		buttonPrevious.setForeground(new Color(0, 204, 0));
		buttonPrevious.setFont(new Font("Arial", Font.BOLD, 20));
		GroupLayout gl_panel = new GroupLayout(panel);
		gl_panel.setHorizontalGroup(
			gl_panel.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_panel.createSequentialGroup()
					.addGap(214)
					.addComponent(buttonPrevious, GroupLayout.PREFERRED_SIZE, 151, GroupLayout.PREFERRED_SIZE)
					.addPreferredGap(ComponentPlacement.RELATED, 624, Short.MAX_VALUE)
					.addComponent(buttonNext, GroupLayout.PREFERRED_SIZE, 151, GroupLayout.PREFERRED_SIZE)
					.addGap(187))
		);
		gl_panel.setVerticalGroup(
			gl_panel.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_panel.createSequentialGroup()
					.addContainerGap()
					.addGroup(gl_panel.createParallelGroup(Alignment.BASELINE)
						.addComponent(buttonPrevious, GroupLayout.PREFERRED_SIZE, 49, GroupLayout.PREFERRED_SIZE)
						.addComponent(buttonNext, GroupLayout.DEFAULT_SIZE, 49, Short.MAX_VALUE))
					.addContainerGap())
		);
		gl_panel.setAutoCreateContainerGaps(true);
		panel.setLayout(gl_panel);
	}
	
	
		
	private void listen(int l)
	throws Exception, SQLException
	{
		if(countLayout == 1)
		{
			System.out.println("case: 1 :: "+countLayout);
			if(l==1)
			{
				countLayout+=1;
				personsCardLayout.next(pclPanel);
			}
					
		}
				
		else if(countLayout>=2 && countLayout<=5)
		{
			System.out.println("case: 2<= x <= 6 :: "+countLayout);
			if(l==1)
			{
				countLayout+=1;
				personsCardLayout.next(pclPanel);
			}
			else
			{
				countLayout-=1;
				personsCardLayout.previous(pclPanel);
			}
					
		}
		else if(countLayout==6)
		{
			if(l!=1)
			{
				countLayout-=1;
				personsCardLayout.previous(pclPanel);
			}
			else
			{
				System.out.println("case: 6: "+countLayout);
				
				int value = JOptionPane.showOptionDialog(this, "Confirm to save the data", "Save The Marriage", 
					JOptionPane.DEFAULT_OPTION, JOptionPane.PLAIN_MESSAGE, null, new Object[]{"Decline", "Confirm"}, 
						0);
				Helper.sop("value: "+value);
				
				if(value == 1)
				{
					if(!saveTheMarriageRegistry()) 
						JOptionPane.showMessageDialog(this, "The Marriage Registry Coudn't Save!!!\nMake sure data inputs were correct.");
					else
					{
						JOptionPane.showMessageDialog(this, "The Marriage Registry saved successfull!\nId is: "+this.M.id);
						this.initializeFields();
						this.countLayout = 1;
						personsCardLayout.first(pclPanel);
					}
				}
				else	Helper.sop("Declined From Confirmation Of Saving Data!");
			}
			
		}
	}
	
	private void collectData()
	{
		this.bridegroom = this.bridegroomPersonalPanel.getPerson();
		Helper.sop("Bridegroom data collected: "+this.bridegroom);
		
		this.bride      = this.bridePersonalPanel.getPerson();
		Helper.sop("Bridegroom data collected: "+this.bride);
		
		this.wakil      = this.wakilPersonalPanel.getPerson();
		Helper.sop("Wakil data collected: "+this.wakil);
		
		this.witness1   = this.witness1PersonalPanel.getPerson();
		Helper.sop("Witness1 data collected: "+this.witness1);
		
		this.witness2   = this.witness2PersonalPanel.getPerson();
		Helper.sop("Witness2 data collected: "+this.witness2);
		
		this.MS         = this.msp.getMarriageStatus();
		Helper.sop("Status data collected: "+this.MS);
		
		this.M = new MarriageRegistry(MS, bridegroom, bride, wakil, witness1, witness2);
		Helper.sop("Registry data collected: "+this.M);
		
		Helper.sop("Data Collected From The Panels.");
	}
	
	private boolean saveTheMarriageRegistry()
	throws Exception
	{
		Helper.sop("Trying to collect data from the panels...");
		collectData();
		if(!this.M.isValid())
		{
			Helper.sop("Data provided in the panels are invalid!!!\n"+
						"Returning false from  saveTheMarriageRegistry() for M.isValid(): ");
			return false;
		}
		if(!MarriageRegistry.insertTheMarriageRegistryIntoTheDatabase(this.M, this.dbuser))
		{
			Helper.sop("Couldn't insert the data in the database!!!\n"+
						"Returning false from saveTheMarriageRegistry() for insertTheMRITdatabase: ");
			return false;
		}
		Helper.sop("Returning true from saveTheMarriageRegistry(): "+this);
		return true;
	}
	public void initializeFields()
	{
		this.bridegroomPersonalPanel.initializeFields();
		this.bridePersonalPanel.initializeFields();
		this.wakilPersonalPanel.initializeFields();
		this.witness1PersonalPanel.initializeFields();
		this.witness2PersonalPanel.initializeFields();
		this.msp.initializeFields();
	}
}
