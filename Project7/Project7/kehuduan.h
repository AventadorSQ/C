//头文件函数声明

//防止头文件重复包含
#pragma once

//兼容C++编译器
//如果是C++编译器，按C标准编译。
#ifdef __cplusplus
extern "C"
{

#endif

//第一套接口

	//初始化环境
	int socketcllient_init(void **handle);

	//发送信息
	int socketcllient_send(void *handle,void *buf,int len);

	//接受信息
	int socketcllient_recv(void *handle,void *buf,int *len);

	//释放资源
	int socketcllient_destroy(void *handle);


	//第二套接口

	//初始化环境
	int socketcllient_init2(void **handle);

	//发送信息
	int socketcllient_send2(void *handle, void *buf, int len);

	//接受信息
	int socketcllient_recv2(void *handle, void **buf, int *len);

	int socketcllient_free2(void **buf);
	//释放资源
	int socketcllient_destroy2(void **handle);


#ifdef __cplusplus
}

#endif