// 9-5 -> 8-32
/*package cn.itcast.bankstore.dao;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;

import cn.itcast.bankstore.domain.BankItem;
//import cn.itcast.bankstore.tools.JDBCUtils;

public class AdminDao {

      //获取所有数据

      public ArrayList<BankItem> queryAllData() { 
    	  Connection conn = null;
      Statement stmt = null;
    	  ResultSet rs = null;

    	  ArrayList<BankItem> list = new ArrayList<BankItem>();

    	  try {

    	       //获取数据的连接
    	        conn=JDBCUtils. getConnection() ;
    	       //获得Statement对象
    	        stmt = conn. createStatement() ;// 发送SQL语句
    	        String  sql =  "SELECT * FROM fruit";
    	        rs= stmt. executeQuery (sql) ;
    	        //处理结果集

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
      
//添加数据
    public void addBankItem (BankItem bankItem) {

          Connection conn= null;
          Statement stmt  = null;
          ResultSet rs = null;
          try {
        	  
              //获取数据的连接
              conn  = JDBCUtils. getConnection() ;//获得Statement对象
              stmt = conn.createStatement() ;//发送SQL语句
              
              String sql = "INSERT INTO personinfo (信用卡号, 用户名称, 储蓄存款, 个人贷款)"
              + "VALUES(" +  bankItem. getNumber() + ",'"
              + bankItem.  getName() + "','" + bankItem. getPrice()
              +"','"  + bankItem. getUnit()+ "')";
              int num = stmt. executeUpdate(sql) ;
              if (num >0) {
            	 System.out.println("插入数据成功！");
             }
         } catch (Exception e) {
        	 e.printStackTrace();   
         } finally {
        	  JDBCUtils. release (rs, stmt ,conn) ;
          }
    }
        	  //刪除数据
        	  public void delBankItem (String delNumber) {
        	  Connection conn = null;
        	  Statement stmt = null;
        	  ResultSet rs = null;
        	  try {
        	  //荻得数据的连接
        	  conn = JDBCUtils.getConnection() ;//狹得Statement対象
        	  stmt = conn. createStatement() ;//发送SQl珸吾句
        	  String sql = "DELETE FROM personinfo WHERE number=" + delNumber;
        	  int num = stmt. executeUpdate(sql) ;
        	  if  (num > 0){
        	  System. out.println ("刪除数据成功! ");
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


