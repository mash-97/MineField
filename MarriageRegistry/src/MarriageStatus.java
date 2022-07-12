public class MarriageStatus
{
	public String date;
	public String place;
	public String dateOfContract;
	public double amountOfDower;
	
	public MarriageStatus(String date, String place, String dateOfContract, double amountOfDower)
	{
		this.date = Helper.datify(date);
		this.place = place;
		this.dateOfContract = dateOfContract;
		this.amountOfDower = Helper.roundd(amountOfDower, 2);
	}
	
	public boolean isValid()
	{
		Helper.sop("this.date: "+this.date);
		Helper.sop("this.amountOfDower: "+this.amountOfDower);
		Helper.sop("checkDateString: "+Helper.checkDateString(this.date));
		
		if(Helper.checkDateString(this.date) && this.amountOfDower >= 0.0) return true;
		Helper.sop("Returning false from isValid() in MarriageStatus.java for MarriageStatus: "+this);
		return false;
	}
}
