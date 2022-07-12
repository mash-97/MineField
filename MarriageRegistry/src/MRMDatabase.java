import java.sql.*;
import java.util.List;
import java.util.Arrays;

public class MRMDatabase
{
	protected static String MRMDATABASE_CONNECTION_STRING = "jdbc:mysql://localhost/MarriageRegistryManagement";
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	public static Connection getDataBaseConnection(User dbuser) throws Exception
	{
		Helper.sop("Trying get Marriage Registry Database Connection: using username: "+dbuser.username);
	
		Connection connection = DriverManager.getConnection(MRMDATABASE_CONNECTION_STRING, dbuser.username, dbuser.password);
	
		if(connection != null) Helper.sop("Successfully connected to the Marriage Registry Database: using username: "+dbuser.username);
		return connection;
	}
	
}
	
