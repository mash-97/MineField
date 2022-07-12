import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class NewRegistry extends JFrame {

	private PersonPanel bridegroomPersonalPanel = new PersonPanel("Bridegroom");
	private PersonPanel bridePersonalPanel = new PersonPanel("Bride");
	private PersonPanel wakilPersonalPanel = new PersonPanel("Wakil");
	private PersonPanel witness1PersonalPanel = new PersonPanel("Witness no. 1");
	private PersonPanel witness2PersonalPanel = new PersonPanel("Witness no. 2");
	private MarriageStatusPanel msp = new MarriageStatusPanel();
	
	private MarriageRegistry M;
	private Person bridegroom;
	private Person bride;
	private Person wakil;
	private Person witness1;
	private Person witness2;
	
	private CardLayout personsCardLayout = new CardLayout(40, 30);
	private JPanel pclPanel = new JPanel(personsCardLayout);
	private int countLayout = 1;
	private final int Total_Layout =6;
	
	private JButton nextButton = new JButton("Next");
	private JButton previousButton = new JButton("Previous");

	
	private String date;
	
	private boolean isTheDataValidToSave()
	{
		this.bridegroom = this.bridegroomPersonalPanel.parsePersonFromPersonPanel();
		this.bride      = this.bridePersonalPanel.parsePersonFromPersonPanel();
		this.wakil      = this.wakilPersonalPanel.parsePersonFromPersonPanel();
		this.witness1   = this.witness1PersonalPanel.parsePersonFromPersonPanel();
		this.witness2   = this.witness2PersonalPanel.parsePersonFromPersonPanel();
		this.msp.produceInputInstance();
		
		//if(this.bridegroom.isValid() && this.bride.isValid() && this.wakil.isValid() && this.witness1.isValid() && this.witness2.isValid() &&
			//this.msp.amount_of_dower>=1 && this.msp.place_name.length()>=0 && this.msp.date.length()>=8) return true;
		return false;
	}
	
	private void saveTheMarriageRegistry()
	{
		if(isTheDataValidToSave())
		{
			try{
				User u = new User("tash", "tash");
				Person.insertThePersonIntoTheDatabase(bridegroom, u);
				Person.insertThePersonIntoTheDatabase(bride, u);
				Person.insertThePersonIntoTheDatabase(wakil, u);
				Person.insertThePersonIntoTheDatabase(witness1, u);
				Person.insertThePersonIntoTheDatabase(witness2, u);
			}
			catch(Exception ex){}
			
			M = new MarriageRegistry(this.date, msp.place_name_field.getText(), null, Integer.parseInt(msp.dower_amount_field.getText()),  
				bridegroom, bride, wakil, witness1, witness2);
			
			try
			{
				if(MarriageRegistry.insertTheMarriageRegistryIntoTheDatabase(M))
				JOptionPane.showMessageDialog(null, "Saved!");
			}
			catch(Exception ex){}
		}
	}
			
	private void listen(int l)
	{
		switch(countLayout)
			{
				case 1:
				
					if(l==1)
					{
						countLayout+=1;
						personsCardLayout.next(pclPanel);
					}
					
					System.out.println("case: 1: "+countLayout);
					
				break;
				
				case 2:
				
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
					
					System.out.println("case: 2: "+countLayout);
					
				break;
				
				case 3:
					
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
					
					System.out.println("case: 3: "+countLayout);
					
				break;
				
				case 4:
					
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
					
					System.out.println("case: 4: "+countLayout);
					
				break;
				case 5:
					
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
					
					System.out.println("case: 5: "+countLayout);
					
				break;
				case 6:
					if(l!=1)
					{
						countLayout-=1;
						personsCardLayout.previous(pclPanel);
					}
					else
					{
						int value = JOptionPane.showOptionDialog(this, "Confirm to save the data", "Save The Marriage", 
							JOptionPane.DEFAULT_OPTION, JOptionPane.PLAIN_MESSAGE, null, new Object[]{"Decline", "Confirm"}, 
								"Decline");
						
						if(value == 1) saveTheMarriageRegistry();
					}
					
					System.out.println("case: 6: "+countLayout);
					
				break;
			}
	}
	
	/**
	 * Create the frame.
	 */
	public NewRegistry() {
		super("New Marriage Registry");
		this.setSize(1000, 500);
		this.setLocationRelativeTo(null);
		//this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setLayout(new BorderLayout(10, 20));
		
		pclPanel.add(bridegroomPersonalPanel, "1");
		pclPanel.add(bridePersonalPanel, "2");
		pclPanel.add(wakilPersonalPanel, "3");
		pclPanel.add(witness1PersonalPanel, "4");
		pclPanel.add(witness2PersonalPanel, "5");
		pclPanel.add(msp, "6");
		
		this.add(pclPanel, BorderLayout.CENTER);
		
		
		JPanel bottomPanel = new JPanel(new GridLayout(1, 2, 30, 10));
		nextButton.setPreferredSize(new Dimension(10, 30));
		previousButton.setPreferredSize(new Dimension(10, 30));
		
		bottomPanel.add(previousButton, BorderLayout.WEST);
		bottomPanel.add(nextButton, BorderLayout.EAST);
		
		
		this.add(bottomPanel, BorderLayout.SOUTH);
		
		
		nextButton.addActionListener((e)->
		{
			listen(1);
		});	
		previousButton.addActionListener((e)->
		{
			listen(2);
		});
		this.setVisible(true);
	}
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					NewRegistry frame = new NewRegistry();
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}


}
