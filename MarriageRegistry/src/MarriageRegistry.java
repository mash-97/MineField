import java.sql.*;
import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;



public class MarriageRegistry
{
	public int id;
	public MarriageStatus marriageStatusInfo;
	public Person bridegroom;		
	public Person bride;			
	public Person wakil;			
	public Person witness1; 		
	public Person witness2;					
	public boolean saved_into_database;
	
	public MarriageRegistry(MarriageStatus marriageStatusInfo, 
							Person bridegroom, 	Person bride, 
							Person wakil, Person witness1, Person witness2)
	{
		this.id = 0;
		this.marriageStatusInfo = marriageStatusInfo;
		this.bridegroom = bridegroom;
		this.bride = bride;
		this.wakil = wakil;
		this.witness1 = witness1;
		this.witness2 = witness2;
		this.saved_into_database = false;
	}
	
	public boolean isValid()
	{
		if(this.saved_into_database == true && this.id <=0) return false;
		if(!this.marriageStatusInfo.isValid()) return false;
		if(!this.bridegroom.isValid()) return false;
		if(!this.bride.isValid()) return false;
		if(!this.wakil.isValid()) return false;
		if(!this.witness1.isValid()) return false;
		if(!this.witness2.isValid()) return false;
		return true;
	}
	// ***************************  For MarriageRegistries Table **************//
						
	public final static String MR_TABLE_NAME = "MarriageRegistries";
	public final static String cnID = "id";
	public final static String cnDATE = "date";
	public final static String cnPLACE = "place";
	public final static String cnAMOUNT_OF_DOWER = "amountOfDower";
	public final static String cnDATE_OF_CONTRACT = "dateOfContract";
	public final static String cnBRIDEGROOM_ID = "bridegroomId";
	public final static String cnBRIDE_ID = "brideId";
	public final static String cnWAKIL_ID = "wakilId";
	public final static String cnWITNESS1_ID = "witness1Id";
	public final static String cnWITNESS2_ID = "witness2Id";
	
	public final static String pnBRIDEGROOM = "Bridegroom";
	public final static String pnBRIDE = "Bride";
	public final static String pnWAKIL = "Wakil";
	public final static String pnWITNESS1 = "Witness1";
	public final static String pnWITNESS2 = "Witness2";
	
	
						//			INSERT_QUERY			//
	public static String MR_INSERT_QUERY_PATTERN =     "insert into MarriageRegistries"+
								       "(date, place, dateOfContract, amountOfDower, "+
								       "bridegroomId, brideId, wakilId, witness1Id, witness2Id) "+
								       "values(?, ?, ?, ?, ?, ?, ?, ?, ?);";
								       // Total 9 ? 
	//****************************************************************************************************************//
	public static String makeSearchByNameCommand(String Person_Type, String name)
	{
		if(Person_Type == MarriageRegistry.pnBRIDEGROOM)
			return "select Persons.name from MarriageRegistries, Persons where MarriageRegistries.bridegroomId = Persons.id and Persons.name = "+name;
		return "select Persons.name from MarriageRegistries, Persons where MarriageRegistries.bride = Persons.id and Persons.name = "+name;
	}
		
	
	private static ArrayList<MarriageRegistry> produceMRListfromResultSet(ResultSet result_set, User dbuser)
	throws Exception, SQLException
	{
		ArrayList<MarriageRegistry> MRs = new ArrayList<MarriageRegistry>();
		ResultSet r = result_set;
		while(r.next())
		{
			MarriageStatus ms = new MarriageStatus(r.getString("date"), r.getString("place"), r.getString("dateOfContract"), Helper.sToD(r.getString("amountOfDower"), 2));
			Person bridegroom = Person.parsePersonFromDatabaseViaId(Integer.parseInt(r.getString("bridegroomId")), dbuser);
			Person bride = Person.parsePersonFromDatabaseViaId(Integer.parseInt(r.getString("brideId")), dbuser);
			Person wakil = Person.parsePersonFromDatabaseViaId(Integer.parseInt(r.getString("wakilId")), dbuser);
			Person witness1 = Person.parsePersonFromDatabaseViaId(Integer.parseInt(r.getString("witness1Id")), dbuser);
			Person witness2 = Person.parsePersonFromDatabaseViaId(Integer.parseInt(r.getString("witness2Id")), dbuser);
			
			MarriageRegistry mr = new MarriageRegistry(ms, bridegroom, bride, wakil, witness1, witness2);
			mr.saved_into_database = true;
			
			MRs.add(mr);
		}
		return MRs;
	}
	
	
	public static ArrayList<MarriageRegistry> searchMRbyTheQuery(String Query, User dbuser)
	throws Exception, SQLException
	{
		Connection connection = MRMDatabase.getDataBaseConnection(dbuser);
		Statement statement = connection.createStatement();
		ResultSet result_set = statement.executeQuery(Query);
		return produceMRListfromResultSet(result_set, dbuser);
	}
	
	
	
	public static MarriageRegistry parseMRFromDatabaseViaId(int id, User dbuser)
	throws Exception, SQLException
	{
		Connection connection = MRMDatabase.getDataBaseConnection(dbuser);
		Statement statement = connection.createStatement();
		ResultSet r = statement.executeQuery("select date, place, dateOfContract, amountOfDower, "+
											"bridegroomId, brideId, wakilId, witness1Id, witness2Id "+
											"from MarriageRegistries where id = "+id+";");
		if(!r.next())
		{
			Helper.sop("No MR with the id: "+id+" found in the database!");
			return null;
		}
		
		MarriageStatus ms = new MarriageStatus(r.getString("date"), r.getString("place"), r.getString("dateOfContract"), Helper.sToD(r.getString("amountOfDower"), 2));
		Person bridegroom = Person.parsePersonFromDatabaseViaId(Integer.parseInt(r.getString("bridegroomId")), dbuser);
		Person bride = Person.parsePersonFromDatabaseViaId(Integer.parseInt(r.getString("brideId")), dbuser);
		Person wakil = Person.parsePersonFromDatabaseViaId(Integer.parseInt(r.getString("wakilId")), dbuser);
		Person witness1 = Person.parsePersonFromDatabaseViaId(Integer.parseInt(r.getString("witness1Id")), dbuser);
		Person witness2 = Person.parsePersonFromDatabaseViaId(Integer.parseInt(r.getString("witness2Id")), dbuser);
		
		MarriageRegistry mr = new MarriageRegistry(ms, bridegroom, bride, wakil, witness1, witness2);
		mr.saved_into_database = true;
		
		connection.close();
		return mr;
	}
	
	public static void main(String [] args) 
	throws Exception, SQLException
	{
		User dbuser = new User("tash", "tash");
		Photo photo = new Photo("/home/mash/Pictures/Screenshot from 2019-03-06 01-49-57.png");
		Person bridegroom = new Person("bridegroom bridegroom", "male", "hasht hlkd", "juue juue", "11-3-2000", "dhaka", photo);
		Person bride = new Person("bride bride", "female", "hasht hlkd", "juue juue", "11-3-2000", "dhaka", photo);
		Person wakil = new Person("wakil wakil", "male", "hasht hlkd", "juue juue", "11-3-2000", "dhaka", photo);
		Person witness1 = new Person("witness1 witness1", "male", "hasht hlkd", "juue juue", "11-3-2000", "dhaka", photo);
		Person witness2 = new Person("witness2 witness2", "male", "hasht hlkd", "juue juue", "11-3-2000", "dhaka", photo);
		
		MarriageStatus ms = new MarriageStatus("1-1-2000", "dhaka", "1-1-2000", 34343.234);
		
		MarriageRegistry mr = new MarriageRegistry(ms, bridegroom, bride, wakil, witness1, witness2);
		
		if(!MarriageRegistry.insertTheMarriageRegistryIntoTheDatabase(mr, dbuser)) Helper.sop("Unsuccessfull! ;!");
		else Helper.sop("YOoooHOOOO!");
	}
		
	public static boolean insertTheMarriageRegistryIntoTheDatabase(MarriageRegistry marriage_registry, User dbuser) 
	throws Exception, SQLException
	{
		if( !(Person.insertThePersonIntoTheDatabase(marriage_registry.bridegroom, dbuser) && 
		Person.insertThePersonIntoTheDatabase(marriage_registry.bride, dbuser) &&
		Person.insertThePersonIntoTheDatabase(marriage_registry.wakil, dbuser) &&
		Person.insertThePersonIntoTheDatabase(marriage_registry.witness1, dbuser) &&
		Person.insertThePersonIntoTheDatabase(marriage_registry.witness2, dbuser)) )
					return false;
		
		Connection connection = MRMDatabase.getDataBaseConnection(dbuser);
		PreparedStatement statement = connection.prepareStatement(MarriageRegistry.MR_INSERT_QUERY_PATTERN
																	, Statement.RETURN_GENERATED_KEYS);

		statement.setString(1, marriage_registry.marriageStatusInfo.date);				
		statement.setString(2, marriage_registry.marriageStatusInfo.place);
		statement.setString(3, marriage_registry.marriageStatusInfo.dateOfContract);	
		statement.setDouble(4, Helper.roundd(marriage_registry.marriageStatusInfo.amountOfDower, 2) );
		statement.setInt(5, marriage_registry.bridegroom.id);	
		statement.setInt(6, marriage_registry.bride.id);
		statement.setInt(7, marriage_registry.wakil.id);			
		statement.setInt(8, marriage_registry.witness1.id);
		statement.setInt(9, marriage_registry.witness2.id);

		try
		{
			statement.executeUpdate();
		}
		catch(Exception e)
		{
			Helper.sop("Exception: "+e);
			Helper.sop("Could not insert the marriage registry: "+marriage_registry+" into the database!");
			return false;
		}
		
		ResultSet result = statement.getGeneratedKeys();
		if(result.next())
		{
			marriage_registry.id = result.getInt(1);
			marriage_registry.saved_into_database = true;
		}
		connection.close();
		return true;
	}
}
