package 窗口Test;
import java.awt.*;
public class 窗口1
{
	public static void main(String[] args)
	{
		Frame f = new Frame("你好！窗体");
		f.setSize(500, 400);//窗口的大小
		f.setLocation(300, 200);//窗口在屏幕所处的坐标
		f.setVisible(true);//设置窗体可见
	}
}
