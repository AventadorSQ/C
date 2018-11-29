package BankInfo.domain;

public class BankItem {
	private int number;//信用卡号
	private String name;//用户名称
	private double price;//邮政存储
	private double unit;//个人贷款
	//构造方法
	public BankItem(){
	}
	public BankItem(int number, String name,double price, double unit){
		super();
		this.number = number;
		this.name = name;
		this.price = price;
		this.unit = unit;
	}
	//get/set 方法
	public int getNumber(){
		return number;
	}
	public void setNumber(int number){
		this.number = number;
	}
	public String getName(){
		return name;
	}
	public void setName(int number){
		this.number = number;
	}
	public double getPrice(){
		return price;
	}
	public void setPrice(double price){
		this.price = price;		
	}
	public double getUnit(){
		return unit;
	}
	public void setUnit(double unit){
		this.unit = unit;
		
	}
}
