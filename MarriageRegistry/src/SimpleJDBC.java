import java.sql.*;
//import com.mysql.jdbc.Driver;

public class SimpleJDBC
{
	public static void main(String [] args) throws SQLException, ClassNotFoundException
	{
		// Load the JDBC driver
		Class.forName("com.mysql.jdbc.Driver");
		System.out.println("Driver loaded");
		
		// Establish a connection
		Connection connection = DriverManager.getConnection("jdbc:mysql://localhost/MarriageRegistryManagement", "tash", "tash");
		//Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/ebookshop?allowPublicKeyRetrieval=true&useSSL=false&serverTimezone=UTC", "tash", "tash");
		System.out.println("Database connected");
		
		// Create a statement
		Statement statement = connection.createStatement();
		
		// Execute a statement
		statement.executeUpdate("insert into Persons(name, gender, fatherName, motherName, dateOfBirth, address)"
		+" values('Mashiur Rahman', 'male', 'Nurul Amin', 'Masuma Sultana', '21-2-1997', 'Dhaka, Gazipur')");
		
		//~ // Iterate through the resultSet
		//~ while(resultSet.next())
			//~ System.out.println("CourseID: "+resultSet.getString("courseId")+", Title: "+resultSet.getString("title"));
		
		//~ ResultSet resultSet2 = statement.executeQuery("select * from Student;");
		//~ // Iterate through the resultSet2
		//~ while(resultSet2 .next())
			//~ System.out.println("Name: "+resultSet2.getString("firstName")+" "+resultSet2.getString("lastName"));
			
		// Close the connection
		connection.close();
	}
}
