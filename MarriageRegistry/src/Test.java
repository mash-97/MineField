import java.util.*;
import java.text.DecimalFormat;
public class Test
{
	public static void sop(String string)
	{
		System.out.println(string);
	}
	public static String ss;
	
	public static String displayCharArray(String s)
	{
		char [] cs = s.toCharArray();
		cs[5] = '-';
		return new String(cs);
	}
	public static void main(String [] args)
	{
		String s = "";
		
		if(s=="") sop(""+Helper.sToD("", 2));
	}
}
