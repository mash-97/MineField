import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MainWindow {

	private JFrame frame;
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MainWindow window = new MainWindow();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public MainWindow() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setTitle("Nikah Registry");
		frame.setSize(300, 300);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(new GridLayout(5, 1, 5, 5));
		
		frame.add(Box.createHorizontalStrut(32));
		JPanel nP = new JPanel();
		nP.setPreferredSize(new Dimension(40, 40));
		JButton btnNewButton = new JButton("New Registry");
		btnNewButton.addActionListener((e)->
		{
			new NewRegistry();
		});
		nP.add(btnNewButton);
		frame.getContentPane().add(nP);
		
		JPanel sP = new JPanel();
		sP.setPreferredSize(new Dimension(40, 40));
		JButton btnSearch = new JButton("Search");
		btnSearch.addActionListener((e)->
		{
			
		});
		sP.add(btnSearch);
		frame.getContentPane().add(sP);
		
		JPanel eP = new JPanel();
		eP.setPreferredSize(new Dimension(40, 40));
		JButton btnExit = new JButton("Exit");
		eP.add(btnExit);
		frame.getContentPane().add(eP); 
		
		btnExit.addActionListener((e)->
		{
			frame.setVisible(false);
			frame.dispose();
		});
		
		frame.add(Box.createHorizontalStrut(32));
	}
}
