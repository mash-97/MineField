import java.sql.*;
import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;

public class Person
{
	public int id;
	public String gender;
	public String name;
	public String fatherName;
	public String motherName;
	public String dateOfBirth;
	public String address;
	public Photo photo;
	public boolean saved_into_database;
	
	public void display()
	{
		Helper.sop("Person : "+this);
		Helper.sop("ID: "+this.id);
		Helper.sop("Name: "+this.name);
		Helper.sop("Gender: "+this.gender);
		Helper.sop("Father name: "+this.fatherName);
		Helper.sop("Mother name: "+this.motherName);
		Helper.sop("Date of Birth: "+this.dateOfBirth);
		Helper.sop("Address: "+this.address);
		
	}
	public Person(String name, String gender, String fatherName, String motherName, String dateOfBirth, String address, Photo photo)
	{
		this.id = 0;
		this.gender = Helper.namify(gender);
		this.name = Helper.namify(name);
		this.fatherName = Helper.namify(fatherName);
		this.motherName = Helper.namify(motherName);
		this.dateOfBirth = Helper.datify(dateOfBirth);
		this.address = address;
		this.photo = photo;
		this.saved_into_database = false;
	}
	
	public boolean isValid()
	{
		Helper.sop("Checking validity for person: "+this);
		this.display();
		if(!Helper.checkNameLength(this.name))
		{
			Helper.sop("Check failed at Name length! Person: "+this);
			return false;
		}
		if(!( this.gender.compareTo("Male")== 0 || this.gender.compareTo("Other")==0 || this.gender.compareTo("Female") == 0))
		{
			Helper.sop("Check failed at Gender check! Person: "+this);
			return false;
		}
		if(!Helper.checkNameLength(this.fatherName))
		{
			Helper.sop("Check failed at Father Name check! Person: "+this);
			return false;
		}
		if(!Helper.checkNameLength(this.motherName))
		{
			Helper.sop("Check failed at Mother Name check! Person: "+this);
			return false;
		}
		if(!Helper.checkDateString(this.dateOfBirth))
		{
			Helper.sop("Check failed at date check! Person: "+this);
			return false;
		}
		if(this.saved_into_database==true && this.id<=0) return false;
		if(this.photo!=null && this.photo.isValid()==false)
		{
			Helper.sop("Check failed at Photo check! Person: "+this);
			return false;
		}
		Helper.sop("Check Passed! Person: "+this);
		return true;
	}
	// ************************** For Persons Table ***************************//
	public final static String PERSON_TABLE_NAME = "Persons";
	public final static String cnID = "id";
	public final static String cnNAME = "name";
	public final static String cnFATHER_NAME = "fatherName";
	public final static String cnMOTHER_NAME = "motherName";
	public final static String cnGENDER = "gender";
	public final static String cnDATE_OF_BIRTH = "dateOfBirth";
	public final static String cnADDRESS = "address";
	public final static String cnPHOTO_ID = "photoId";
	
	
						//			INSERT_QUERY			//
	private static String PERSON_INSERT_QUERY_PATTERN = "insert into Persons"+
											   "(name, gender, fatherName, motherName, dateOfBirth, address, photoId) "+
											   "values(?, ?, ?, ?, ?, ?, ?);";
	
	public static boolean insertThePersonIntoTheDatabase(Person person, User dbuser) 
	throws Exception, SQLException
	{
		Helper.sop("Inside the Person.java from insertThePersonIntoTheDatabase():: for person: "+person);
		Connection connection = MRMDatabase.getDataBaseConnection(dbuser);
		
		// Inserting the person via prepared statement.
			// First inserting the photo
		if(person.photo!=null && person.photo.saved_into_database == false)
		{
			if(!(Photo.insertThePhotoIntoTheDatabase(person.photo, dbuser) && Photo.saveThePhoto(person.photo, dbuser)))
			{
				Helper.sop("Couldn't insert the information about the photo into the database or save the photo:: For Photo: "+person.photo);
				Helper.sop("So setting the photoId to 0!");
				person.photo.photoId = 0;
			}
		}
		if(person.photo.isValid()==false) person.photo.photoId = 0;
		
		
		Helper.sop("Inserting the person: "+person+"...");
		PreparedStatement statement = connection.prepareStatement(Person.PERSON_INSERT_QUERY_PATTERN, Statement.RETURN_GENERATED_KEYS);

		statement.setString(1, person.name);
		statement.setString(2, person.gender);
		statement.setString(3, person.fatherName);
		statement.setString(4, person.motherName);
		statement.setString(5, person.dateOfBirth);
		statement.setString(6, person.address);
		statement.setInt(7, person.photo.photoId);
		try
		{
			statement.executeUpdate();
		}
		catch(Exception e)
		{
			Helper.sop("Exception: "+e);
			Helper.sop("Could not insert the person: "+person+" into the database!");
			return false;
		}
		Helper.sop("Inserted:: person: "+person);
		Helper.sop("Trying to get the id for the person: "+person);
		// Executing query for GET_ID_QUERY via prepared statement and ResultSet r is set for catching the result.
		ResultSet r = statement.getGeneratedKeys();
		
		if(r.next())
		{
			person.id = r.getInt(1);
			Helper.sop("Fetched Person Id: "+person.id+" :: For person: "+person);
		}
		connection.close();
		
		Helper.sop("Returning from the insertThePersonIntoTheDatabase():: for person: "+person);
		return true;
	}
	
	
	public static Person parsePersonFromDatabaseViaId(int id, User dbuser)
	throws Exception, SQLException
	{
		Connection connection = MRMDatabase.getDataBaseConnection(dbuser);
		Statement statement = connection.createStatement();
		ResultSet r = statement.executeQuery("select name, gender, fatherName, motherName, dateOfBirth, address, photoId "+
											"from Persons where id = "+id+";");
		if(r.next()==false)
		{
			Helper.sop("No person with id: "+id+" found in the database");
			return null;
		}
		
		Person person = new Person(r.getString("name"), r.getString("gender"), r.getString("fatherName"),
								   r.getString("motherName"), r.getString("dateOfBirth"), r.getString("address"), null);
		
		try{person.photo = Photo.getPhotoById(Integer.parseInt(r.getString("photoId")), dbuser);}
		catch(Exception e)
		{
			Helper.sop("In Person.java from parsePersonFromDatabaseViaId():: Exception: "+e);
			Helper.sop("The Person won't have any photo, so is null");
		}
		
		connection.close();
		return person;
	}
	

	public static void main(String [] args)
	throws Exception, SQLException
	{
		User dbuser = new User("tash", "tash");
		Photo photo = new Photo("/home/mash/Pictures/Screenshot from 2019-03-06 01-49-57.png");
		Person bridegroom = new Person("bridegroom bridegroom", "male", "hasht hlkd", "juue juue", "11-3-2000", "dhaka", photo);
		
		Person.insertThePersonIntoTheDatabase(bridegroom, dbuser);
	}
}
