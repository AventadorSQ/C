// 9-5 -> 8-32
/*package cn.itcast.bankstore.dao;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;

import cn.itcast.bankstore.domain.BankItem;
//import cn.itcast.bankstore.tools.JDBCUtils;

public class AdminDao {

      //��ȡ��������

      public ArrayList<BankItem> queryAllData() { 
    	  Connection conn = null;
      Statement stmt = null;
    	  ResultSet rs = null;

    	  ArrayList<BankItem> list = new ArrayList<BankItem>();

    	  try {

    	       //��ȡ���ݵ�����
    	        conn=JDBCUtils. getConnection() ;
    	       //���Statement����
    	        stmt = conn. createStatement() ;// ����SQL���
    	        String  sql =  "SELECT * FROM fruit";
    	        rs= stmt. executeQuery (sql) ;
    	        //��������

    	   while (rs.next()) {

    		   BankItem bankItem = new BankItem() ;
    		   bankItem.setNumber (rs.getString ("number")) ;
    		   bankItem.setName (rs.getString ("name") ) ;
    		   bankItem.setPrice (rs.getDouble ("price")) ;
    		   bankItem.setUnit (rs.getString ("unit")) ;
    	        list.add (bankItem) ;
    	        }
    	        return list;
      } catch (Exception e) {

          e.printStackTrace() ;
      }finally {
          JDBCUtils.release (rs, stmt, conn);
      }
          return null ;
 }
      
//�������
    public void addBankItem (BankItem bankItem) {

          Connection conn= null;
          Statement stmt  = null;
          ResultSet rs = null;
          try {
        	  
              //��ȡ���ݵ�����
              conn  = JDBCUtils. getConnection() ;//���Statement����
              stmt = conn.createStatement() ;//����SQL���
              
              String sql = "INSERT INTO personinfo (���ÿ���, �û�����, ������, ���˴���)"
              + "VALUES(" +  bankItem. getNumber() + ",'"
              + bankItem.  getName() + "','" + bankItem. getPrice()
              +"','"  + bankItem. getUnit()+ "')";
              int num = stmt. executeUpdate(sql) ;
              if (num >0) {
            	 System.out.println("�������ݳɹ���");
             }
         } catch (Exception e) {
        	 e.printStackTrace();   
         } finally {
        	  JDBCUtils. release (rs, stmt ,conn) ;
          }
    }
        	  //�h������
        	  public void delBankItem (String delNumber) {
        	  Connection conn = null;
        	  Statement stmt = null;
        	  ResultSet rs = null;
        	  try {
        	  //ݶ�����ݵ�����
        	  conn = JDBCUtils.getConnection() ;//�M��Statement����
        	  stmt = conn. createStatement() ;//����SQl�@���
        	  String sql = "DELETE FROM personinfo WHERE number=" + delNumber;
        	  int num = stmt. executeUpdate(sql) ;
        	  if  (num > 0){
        	  System. out.println ("�h�����ݳɹ�! ");
        	  }
        } catch (Exception e) {
        	  e.printStackTrace() ;
        } finally {
        	  JDBCUtils.release (rs, stmt, conn) ;
        }
  
             
     }
 }


*/





package cn.itcast.bankstore.dao;
import java.util.ArrayList;
import cn.itcast.bankstore.data.DataBase;
import cn.itcast.bankstore.domain.BankItem;

public class AdminDao{
	public ArrayList<BankItem>queryAllData(){
		return DataBase.data;
	}
	public void addBankItem(BankItem bankItem){
		DataBase.data.add(bankItem);
	}
	public void delBankItem(String delNumber){
		for(int i = 0; i < DataBase.data.size(); i++){
			BankItem thisBankItem = DataBase.data.get(i);
			if(thisBankItem.getNumber().equals(delNumber)){
				DataBase.data.remove(i);
			}
			
		}
		
	}
	
}


