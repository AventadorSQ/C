//8-35
package cn.itcast.bankstore.controller;

import cn.itcast.bankstore.view.AbstractMainFrame;

/**

* �����������

*/

@SuppressWarnings("serial")

public class MainFrameController extends AbstractMainFrame {

@Override

public void showAdminDialog() {

//�ڸ÷����д�������Ա���沢��ʾ

//thisΪ������(������) true:����Ϊģ̬����չʾ

new AdminDialogController(this, true).setVisible(true);
}
}


