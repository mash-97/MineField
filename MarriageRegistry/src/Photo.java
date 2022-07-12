import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

public class Photo
{
	public static String DEFAULT_IMAGE_FILE_SOURCE = "/home/mash/Pictures/Screenshot from 2019-03-06 01-49-57.png";
	public int photoId;
	public String photoSource;
	public boolean saved_into_database;
	
	Photo(String photoSource)
	{
		this.photoId = 0;
		this.photoSource = photoSource;
		this.saved_into_database = false;
	}
	
	public boolean isValid()
	{
		return ((this.saved_into_database==true &&  this.photoId==0) || this.photoSource == null || this.photoSource.length()==0) ? false : true;
	}
	
	// ***************************  For Photos Table  ***********************************//
	public final static String PHOTO_TABLE_NAME = "Photos";
	
	public final static String cnID = "id";
	public final static String cnPHOTO_SOURCE = "photoSource";
	
	
	
	private static String PHOTO_INSERT_QUERY_PATTERN =  "insert into Photos(photoSource) values(?)";
	
	
	public static String PHOTO_SEARCH_BY_ID_QUERY_PATTERN = "select photoSource from Photos where id = ?;";

	//~ private static String PHOTO_GET_LAST_ID  = "select LAST_INSERT_ID() from Photos;";
	// ****************************************************************************//
	private static String IMAGE_STORE_PATH = "/home/mash/Progus/Javas/ProjectOp/MarriageRegistry/src/Images";
	
	public static boolean insertThePhotoIntoTheDatabase(Photo photo, User dbuser) 
	throws Exception, SQLException
	{
		Helper.sop("Inside Photo.java from insertThePhotoIntoTheDatabase():: for photo: "+photo);
		
		Connection db_connection = MRMDatabase.getDataBaseConnection(dbuser);
		PreparedStatement statement = db_connection.prepareStatement(Photo.PHOTO_INSERT_QUERY_PATTERN, Statement.RETURN_GENERATED_KEYS);
		try
		{
			statement.setString(1, photo.photoSource);
			statement.executeUpdate();
		}
		catch(Exception e)
		{
			Helper.sop("Exception: "+e);
			Helper.sop("Could not save the photo: "+photo+" into the database!");
			return false;
		}
		
		Helper.sop("Fetching ID for Photo: "+photo+"...");
		ResultSet r = statement.getGeneratedKeys();
		
		if(r.next())
		{
			photo.photoId = r.getInt(1);
			Helper.sop("PhotoID fetched: "+photo.photoId);
		}
		photo.saved_into_database = true;
		db_connection.close();
		
		Helper.sop("Returning from the  insertThePhotoIntoTheDatabase().");
		return true;
	}
	
	public static boolean saveThePhoto(Photo photo, User dbuser)	
	throws Exception, SQLException
	{
		Helper.sop("Saving the photo: "+photo);
		if(photo.isValid()==false) return false;
		
		String target_file = IMAGE_STORE_PATH+"/"+photo.photoId;
		if(!Helper.copyFile(photo.photoSource, target_file)) return false;
		photo.photoSource = target_file;
		
		Helper.sop("After saving the photo: "+photo);
		return true;
	}
	
	public static Photo getPhotoById(int id, User dbuser)
	throws Exception, SQLException
	{
		Connection connection = MRMDatabase.getDataBaseConnection(dbuser);
		PreparedStatement statement = connection.prepareStatement(Photo.PHOTO_SEARCH_BY_ID_QUERY_PATTERN);
		statement.setString(1, Integer.toString(id));
		ResultSet r = statement.executeQuery();
		Photo photo = new Photo("");
		if(r.next())
		{
			photo.photoSource = r.getString("photoSource");
			photo.photoId = id;
		}
		connection.close();
		return photo;
	}
	
}
