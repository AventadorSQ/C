//ͷ�ļ���������

//��ֹͷ�ļ��ظ�����
#pragma once

//����C++������
//�����C++����������C��׼���롣
#ifdef __cplusplus
extern "C"
{

#endif

//��һ�׽ӿ�

	//��ʼ������
	int socketcllient_init(void **handle);

	//������Ϣ
	int socketcllient_send(void *handle,void *buf,int len);

	//������Ϣ
	int socketcllient_recv(void *handle,void *buf,int *len);

	//�ͷ���Դ
	int socketcllient_destroy(void *handle);


	//�ڶ��׽ӿ�

	//��ʼ������
	int socketcllient_init2(void **handle);

	//������Ϣ
	int socketcllient_send2(void *handle, void *buf, int len);

	//������Ϣ
	int socketcllient_recv2(void *handle, void **buf, int *len);

	int socketcllient_free2(void **buf);
	//�ͷ���Դ
	int socketcllient_destroy2(void **handle);


#ifdef __cplusplus
}

#endif