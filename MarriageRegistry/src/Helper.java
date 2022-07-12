import java.io.*;
import java.text.DecimalFormat;

public class Helper
{
	public final static int NAME_LENGTH = 45;
	public static void sop(String string)
	{
		System.out.println(string+"\n\n");
	}
	
	public static boolean exist(String file_name)
	{
		File file = new File(file_name);
		
		return file.exists() ? true : false;
	}
	
	public static boolean copyFile(String sourceFile, String targetFile) throws IOException
	{
		sop("Trying to copy:: sourceFile: "+sourceFile+", targetFile: "+targetFile);
		
		if(!exist(sourceFile))
		{
			sop("The sourceFile file: "+sourceFile+" doesn't exist!");
			return false;
		}
		else if(exist(targetFile))
		{
			sop("The targetFile file: "+targetFile+" alreay exists!");
			return false;
		}
		
		// Create an Input Stream
		BufferedInputStream input = new BufferedInputStream(new FileInputStream(sourceFile));
		
		// Create an Output Stream
		BufferedOutputStream output = new BufferedOutputStream(new FileOutputStream(targetFile));
		
		int r;
		while((r = input.read())!=-1) output.write((byte)r);
		
		input.close();
		output.close();
		
		sop("File copied Successfull:: from "+sourceFile+" to "+targetFile);
		return true;
	}
	
	public static boolean checkNameLength(String name)
	{
		return (name.length()<=3 || name.length()>Helper.NAME_LENGTH) ? false : true;
	}
	
	public static String namify(String string_object)
	{
		String [] tokens = string_object.split("[^A-Za-z0-9]");
		
		String result = "";
		for(int i=0; i<tokens.length; i++) 
		if(tokens[i].length()!=0)
		{
			tokens[i] = tokens[i].toLowerCase();
			char [] cs = tokens[i].toCharArray();
			cs[0] = (char)((int)'A'-(int)'a'+(int)cs[0]);
			if(i!=tokens.length-1) result += new String(cs)+" ";
			else result += new String(cs);
		}
		return result;
	}
	
	public static String datify(String string)
	{
		String [] tokens = string.split("[^0-9]");
		String result = "";
		int i, icount = 0;
		for(i=0; i<tokens.length && icount<3; i++)
		if(tokens[i].length()!=0){
			icount++;
			if(icount<=2) result += tokens[i]+"-";
			else result += tokens[i];
		}
		Helper.sop("Datified: "+result);
		return result;
	}
	
	public static boolean checkDateString(String date)
	{
		if(date.length()<8 || date.length()>10) return false; 
		String [] tokens  = date.split("-");
		
		if(tokens.length != 3) return false;
		
		int day;
		int month;
		int year;
		int i = 0;
		int count = 0;
		String d="", m="", y="";
		
		for(i=0; i<tokens.length; i++)
		if(tokens[i].length()!=0)
		{
			count++;
			d = tokens[i];
			break;
		}
		for(i+=1; i<tokens.length; i++)
		if(tokens[i].length()!=0)
		{
			count++;
			m = tokens[i];
			break;
		}
		for(i+=1; i<tokens.length; i++)
		if(tokens[i].length()!=0)
		{
			count++;
			y = tokens[i];
			break;
		}
		
		if(count!=3) return false;
			
		try
		{
			day = Integer.parseInt(d);
			month = Integer.parseInt(m);
			year = Integer.parseInt(y);
		}
		catch(Exception e)
		{return false;}
		
		if(day<1 || day>31 || month<1 || month>12 || year<0) return false;
		return true;
	}
	
	public static double roundd(double dnumber, int lplace)
	{
		if(lplace<1) return dnumber;
		String f = "#";
		for(int i=1; i<lplace; i++) f+="#";
	//	sop(f);
		DecimalFormat df = new DecimalFormat("#."+f);
		return new Double(df.format(dnumber));
	}
	
	public static double sToD(String dnumber, int lplace)
	{
		if(dnumber.length()==0 || dnumber=="" || dnumber == null) return 0.0;
		return roundd(new Double(dnumber), lplace);
	}
	
	public static String dToS(double dnumber, int lplace)
	{
		return ""+roundd(dnumber, lplace);
	}
}
