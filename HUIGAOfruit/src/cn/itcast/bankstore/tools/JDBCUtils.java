//9-4
package cn.itcast.bankstore.tools;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
/*
 * ������
 */
public class JDBCUtils {
	//�������������������ݿ�����
	public static Connection getConnection() throws SQLException,ClassNotFoundException{
	String dirver = "com.mysql.jdbc.Driver";
	String url = "jdbc:mysql://localhost:3306/banksystem";
	String username = "root";
	String password = "990113";

	Class.forName (dirver);
	Connection conn = DriverManager.getConnection (url, username,password);
	return conn;
	}

	//�ر����ݿ����ӣ��ͷ���Դ
	public static void release (Statement stmt, Connection conn) {
	if(stmt != null) {
	try {
	    stmt.close() ;
	} catch (SQLException e) {
	  e.printStackTrace() ;
	}
	stmt = null;
	}
	if (conn != null) {
	try {
	   conn.close() ;
	} catch (SQLException e) {
	  e.printStackTrace() ;
	}
	conn = null;
    }
}
	
	public static void release (ResultSet rs, Statement stmt, Connection conn)
	{
		if (rs != null) {
	    try {
	        rs.close() ;
	    } catch  (SQLException e) {
	    e.printStackTrace() ;
	    }
	    rs = null;
	}
	release (stmt, conn) ;
  }
//public static void main(String[] args) {
//	try {
//		Connection coon = JDBCUtils.getConnection();
//		System.out.println(coon);
//	} catch (ClassNotFoundException | SQLException e) {
//		// TODO Auto-generated catch block
//		e.printStackTrace();
//	}
//}
}



