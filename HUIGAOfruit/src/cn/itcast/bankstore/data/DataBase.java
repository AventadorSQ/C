//8-31
package cn.itcast.bankstore.data;
import java.util.ArrayList;
import cn.itcast.bankstore.domain.BankItem;

public class DataBase {
	public static ArrayList<BankItem> data = new ArrayList<BankItem>();
	static{
		data.add(new BankItem("6217997916","Àî°×",5000000000.0,"5000000000.0"));
	}
}
