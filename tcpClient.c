// TCP 에코 클라이언트 프로그램
#include "headerFiles.h"  // 필요한 헤더 파일 포함
#define SERVER_PORT 12345  // 서버 포트 번호 정의

int main(int argc, char* argv[]) {
    int s;                     // 소켓 디스크립터
    struct sockaddr_in servAddr;  // 서버 소켓 주소
    char* message = "2017124192 정찬우";  // 전송할 메시지
    char buffer[256];          // 데이터 버퍼
    int len;

    if (argc != 2) {
        printf("Usage: %s <Server IP>\n", argv[0]);
        return 1;
    }

    // 서버 소켓 주소 초기화
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, argv[1], &servAddr.sin_addr);

    // 소켓 생성
    if ((s = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error: Socket creation failed!");
        return 1;
    }

    // 서버에 연결
    if (connect(s, (struct sockaddr*)&servAddr, sizeof(servAddr)) < 0) {
        perror("Error: Connection failed!");
        close(s);
        return 1;
    }

    // 메시지 전송
    send(s, message, strlen(message), 0);

    // 에코 메시지 수신
    len = recv(s, buffer, sizeof(buffer) - 1, 0);
    if (len > 0) {
        buffer[len] = '\0';
        printf("에코 메시지 수신: %s\n", buffer);
    }

    // 소켓 종료
    close(s);

    return 0;
}

