//8-30
package cn.itcast.bankstore.domain;

public class BankItem {
	private String number;//信用卡号
	private String name;//用户名称
	private double price;//邮政存储
	private String unit;//个人贷款
	//构造方法
	public BankItem(){
	}
	public BankItem(String number, String name,double price, String unit){
		super();
		this.number = number;
		this.name = name;
		this.price = price;
		this.unit = unit;
	}
	//get/set 方法
	public String getNumber(){
		return number;
	}
	public void setNumber(String number){
		this.number = number;
	}
	public String getName(){
		return name;
	}
	public void setName(String name){
		this.name = name;
	}
	public double getPrice(){
		return price;
	}
	public void setPrice(double price){
		this.price = price;		
	}
	public String getUnit(){
		return unit;
	}
	public void setUnit(String unit){
		this.unit = unit;
		
	}
}
