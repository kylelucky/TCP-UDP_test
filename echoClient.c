// UDP 에코 클라이언트 프로그램
#include "headerFiles.h"  // 필요한 헤더 파일 포함
#define SERVER_PORT 12345  // 서버 포트 번호 정의

int main(int argc, char* argv[]) {
    int s;                     // 소켓 디스크립터
    int len;                   // 에코될 문자열의 길이
    char* servName;            // 서버 이름
    struct sockaddr_in servAddr;  // 서버 소켓 주소
    char* message = "2017124192 정찬우";  // 전송할 메시지
    char buffer[256 + 1];      // 데이터 버퍼

    if (argc != 2) {
        printf("Error: Server IP address required!\n");
        exit(1);
    }
    servName = argv[1];

    // 서버 소켓 주소 초기화
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, servName, &servAddr.sin_addr.s_addr);

    // 소켓 생성
    if ((s = socket(PF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Error: socket failed!");
        exit(1);
    }

    // 메시지 전송
    len = sendto(s, message, strlen(message), 0,
                 (struct sockaddr*)&servAddr, sizeof(servAddr));

    // 에코 메시지 수신
    recvfrom(s, buffer, len, 0, NULL, NULL);
    buffer[len] = '\0';

    // 수신한 에코 메시지 출력
    printf("Echo string received: %s\n", buffer);

    // 소켓 종료
    close(s);

    return 0;
}

