package BankInfo.domain;

public class BankItem {
	private int number;//���ÿ���
	private String name;//�û�����
	private double price;//�����洢
	private double unit;//���˴���
	//���췽��
	public BankItem(){
	}
	public BankItem(int number, String name,double price, double unit){
		super();
		this.number = number;
		this.name = name;
		this.price = price;
		this.unit = unit;
	}
	//get/set ����
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
