public class User
{
	private static int user_count = 0;
	public String username;
	public String password;
	
	User(String username, String password)
	{
		user_count+=1;
		this.username = username;
		this.password = password;
		Helper.sop("New User object is created:"+user_count+": username: "+this.username);
	}
}
