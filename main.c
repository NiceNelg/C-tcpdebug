#include <arpa/inet.h>
#include <unistd.h>
#define MAXLINE 2048
int main() {
    //������շ���buff
	char sendline[MAXLINE];
	char revline[MAXLINE];
	char command[50];
 	//�����׽��ֱ��
	int socketfd;
	
	//�����������ַ�ṹ�����
	struct sockaddr_in sockaddr;
 	//��ȡ��������ַ�Ͷ˿�
	char *serverIp = "127.0.0.1";
	unsigned int serverPort = 9908;
	//�����������ַ�Ͷ˿�
	char serverIp[15];
	unsigned int serverPort;
 	//���÷�������ַ
	printf("Set Server IP\n");
	fgets(serverIp, 15, stdin);
 	//���ö˿�
	printf("Set Server port\n");
	scanf("%d", &serverPort);
	
	socketfd = socket( AF_INET, SOCK_STREAM, 0 );
	//�����׽���
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
 	//��ʼ������
	memset( &sockaddr, 0, sizeof(sockaddr) );
	memset(&sockaddr, 0, sizeof(sockaddr));
	sockaddr.sin_family = AF_INET;
	//��������ֵת���������ֽ���
	sockaddr.sin_port = htons( serverPort );
	inet_pton( AF_INET, serverIp, &sockaddr.sin_addr );
	//��������ֵת���������ֽ���(�����ö˿���ת���ɷ���tcpЭ�����ֵ)
	sockaddr.sin_port = htons(serverPort);
	//�����õķ�������ַת���ɷ���tpcЭ�����ֵ
	inet_pton(AF_INET, serverIp, &sockaddr.sin_addr);
 	//���ӷ�����
	if( (connect( socketfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr) )) < 0 ) {
		printf( "connect error %s\nerrorno: %d\n", strerror(errno), errno );
	if( (connect(socketfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr))) < 0 ) {
		printf("connect error %s\nerrorno: %d\n", strerror(errno), errno);
		exit(0);
	}
 	while(1) {
		//��ȡ����
		fgets(command, 50, stdin);
		//ɸѡ����
		switch() {
		
		}
		//��������
		fgets(sendline, MAXLINE, stdin);
 		//��������
		if(send(socketfd, sendline, strlen(sendline), 0) < 0) {
			printf("send data error:%s\nerrno:%d\n", strerror(errno), errno);
			exit(0);
		}
 		//��ӡ����
		if(recv(socketfd, revline, strlen(revline), 0) < 0) {
			printf("revice data error:%s\nerrno:%d\n", strerror(errno), errno);
			exit(0);
		} else {
			printf("revice data: %x", revline);
		}
	}
 	//�ر�����
	close(socketfd);
	printf("exit\n");
	return 0;
}
