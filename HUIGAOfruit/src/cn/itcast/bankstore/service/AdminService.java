//8-33
package cn.itcast.bankstore.service;

import java.util.ArrayList;
import cn.itcast.bankstore.dao.AdminDao;
import cn.itcast.bankstore.domain.BankItem;


/*
* ����Ա������
*/
public class AdminService{

private AdminDao adminDao = new AdminDao();

//��ѯ����

public ArrayList<BankItem> queryBankItem() {

//����Dao��Ļ�ȡ�������ݷ�����ȡ��������

ArrayList<BankItem> data = adminDao.queryAllData();

//��������

return data;
}
//��ӷ���

public boolean addBankItem(String number, String name, String price,

		String unit) {

//����Dao��Ļ�ȡ�������ݷ�����ȡ��������

ArrayList<BankItem> data = queryBankItem();

//ʹ������ı�����������ݶԱ�

for (int i = 0; i < data.size(); i++) {

BankItem bankItem = data.get(i);

//��������ظ��������, ����Ӳ��ɹ�

if(number.equals(bankItem.getNumber())){

return false;
}
}
//���û���ظ����,�����ݷ�װΪFruitItem����

BankItem thisBankItem = new BankItem(number, name,

Double.parseDouble(price), unit);

//���� Dao���������ݷ���

adminDao.addBankItem(thisBankItem);

//��������ݺ�, ������ӳɹ�

return true;

}


//�޸ķ���

public boolean updateBankItem(String number, String name,

		String price, String unit) {

//���� ��Ļ�ȡ�������ݷ�����ȡ��������

ArrayList<BankItem> data= queryBankItem();

//ʹ������ı�����������ݶԱ�

for (int i = 0; i < data.size(); i++) {

BankItem bankItem=data.get(i);

//���������ͬ�������, ����Ը���

if(number.equals(bankItem.getNumber())) {

//���� Dao���ɾ��ָ��������ݷ���

adminDao.delBankItem(number);

//���û���ظ����, �����ݷ�װΪFruitItem����

BankItem thisBankItem = new BankItem(number, name,

Double.parseDouble(price),unit);

//���� Dao���������ݷ���

adminDao.addBankItem(thisBankItem);

//���޸����ݺ�, ������ӳɹ�

return true;
}
}
//�����������ͬ�������, �򲻿��Ը���

return false;
}
//ɾ������

public boolean delBankItem(String delNumber) {

//���� Dao��Ļ�ȡ�������ݷ�����ȡ��������

ArrayList<BankItem> data = queryBankItem();

//ʹ������ı�����������ݶԱ�

for (int i = 0; i < data.size();i++) {

BankItem bankItem = data.get(i);

//���������ͬ�������, �����ɾ��

if(delNumber.equals(bankItem.getNumber())){

//���� Dao���ɾ��ָ��������ݷ���

adminDao.delBankItem(delNumber);      

//��ɾ�����ݺ�, ������ӳɹ�

return true;
}
}
//�����������ͬ�������, �򲻿���ɾ��

return false;

}
}
