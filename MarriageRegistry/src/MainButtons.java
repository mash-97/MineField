import javax.swing.JPanel;
import java.awt.GridLayout;
import javax.swing.JButton;
import java.awt.Font;
import java.awt.Color;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class MainButtons extends JPanel {

	/**
	 * Create the panel.
	 */
	public MainButtons(JPanel bpanel, MainWindow main) 
	
	{
		setLayout(null);
		
		JButton btnNewRegistry = new JButton("New Registry");
		//btnNewRegistry.setBackground(new Color(102, 51, 51));
		btnNewRegistry.setFont(new Font("Arial", Font.BOLD, 20));
		btnNewRegistry.setBounds(31, 60, 10, 10);
		add(btnNewRegistry);
		
		// New Registry Button Action
		btnNewRegistry.addActionListener((e)-> 
		{
			try{bpanel.add(new NewRegistry(), BorderLayout.CENTER);}
			catch(Exception ee)
			{
				Helper.sop("Inside MainButtons.java on btnNewRegistry. Exception: "+ee);
			}
		});
		
		JButton btnSearch = new JButton("Search");
		btnSearch.setFont(new Font("Arial", Font.BOLD, 20));
		//btnSearch.setBackground(new Color(102, 51, 51));
		btnSearch.setBounds(31, 132, 39, 29);
		add(btnSearch);
		
		// Search Button Action
		btnSearch.addActionListener((e)->
		{
		
		});
		
		JButton btnExit = new JButton("Exit");
		btnExit.setFont(new Font("Arial", Font.BOLD, 20));
		//btnExit.setBackground(new Color(102, 51, 51));
		btnExit.setBounds(31, 204, 39, 29);
		add(btnExit);
		
		// Exit Button Action
		btnExit.addActionListener((e)->
		{
			main.setVisible(false);
			main.dispose();
		});

	}

}
