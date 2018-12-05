//8-33
package cn.itcast.bankstore.service;

import java.util.ArrayList;
import cn.itcast.bankstore.dao.AdminDao;
import cn.itcast.bankstore.domain.BankItem;


/*
* 管理员服务类
*/
public class AdminService{

private AdminDao adminDao = new AdminDao();

//查询服务

public ArrayList<BankItem> queryBankItem() {

//调用Dao层的获取所有数据方法获取所有数据

ArrayList<BankItem> data = adminDao.queryAllData();

//返回数据

return data;
}
//添加服务

public boolean addBankItem(String number, String name, String price,

		String unit) {

//调用Dao层的获取所有数据方法获取所有数据

ArrayList<BankItem> data = queryBankItem();

//使用输入的编号与所有数据对比

for (int i = 0; i < data.size(); i++) {

BankItem bankItem = data.get(i);

//如果存在重复编号数据, 则添加不成功

if(number.equals(bankItem.getNumber())){

return false;
}
}
//如果没有重复编号,将数据封装为FruitItem对象

BankItem thisBankItem = new BankItem(number, name,

Double.parseDouble(price), unit);

//调用 Dao层的添加数据方法

adminDao.addBankItem(thisBankItem);

//在添加数据后, 返回添加成功

return true;

}


//修改服务

public boolean updateBankItem(String number, String name,

		String price, String unit) {

//调用 层的获取所有数据方法获取所有数据

ArrayList<BankItem> data= queryBankItem();

//使用输入的编号与所有数据对比

for (int i = 0; i < data.size(); i++) {

BankItem bankItem=data.get(i);

//如果存在相同编号数据, 则可以更新

if(number.equals(bankItem.getNumber())) {

//调用 Dao层的删除指定编号数据方法

adminDao.delBankItem(number);

//如果没有重复编号, 将数据封装为FruitItem对象

BankItem thisBankItem = new BankItem(number, name,

Double.parseDouble(price),unit);

//调用 Dao层的添加数据方法

adminDao.addBankItem(thisBankItem);

//在修改数据后, 返回添加成功

return true;
}
}
//如果不存在相同编号数据, 则不可以更新

return false;
}
//删除服务

public boolean delBankItem(String delNumber) {

//调用 Dao层的获取所有数据方法获取所有数据

ArrayList<BankItem> data = queryBankItem();

//使用输入的编号与所有数据对比

for (int i = 0; i < data.size();i++) {

BankItem bankItem = data.get(i);

//如果存在相同编号数据, 则可以删除

if(delNumber.equals(bankItem.getNumber())){

//调用 Dao层的删除指定编号数据方法

adminDao.delBankItem(delNumber);      

//在删除数据后, 返回添加成功

return true;
}
}
//如果不存在相同编号数据, 则不可以删除

return false;

}
}
