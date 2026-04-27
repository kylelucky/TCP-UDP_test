// UDP 에코 서버 프로그램
#include "headerFiles.h"  // 필요한 헤더 파일 포함
#define SERVER_PORT 12345  // 서버 포트 번호 정의

int main(void) {
    int s;                        // 소켓 디스크립터
    int len;                      // 에코될 문자열의 길이
    char buffer[256];             // 데이터 버퍼
    struct sockaddr_in servAddr;  // 서버(로컬) 소켓 주소
    struct sockaddr_in clntAddr;  // 클라이언트(원격) 소켓 주소
    int clntAddrLen = sizeof(clntAddr);  // 클라이언트 소켓 주소의 길이

    // 서버 소켓 주소 초기화
    memset(&servAddr, 0, sizeof(servAddr));  // 메모리 할당
    servAddr.sin_family = AF_INET;           // 주소 패밀리
    servAddr.sin_port = htons(SERVER_PORT);  // 포트 번호 설정
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);  // IP 주소 설정

    // 소켓 생성
    if ((s = socket(PF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Error: socket failed!");
        exit(1);
    }

    // 소켓 바인딩
    if (bind(s, (struct sockaddr*)&servAddr, sizeof(servAddr)) < 0) {
        perror("Error: bind failed!");
        exit(1);
    }

    printf("UDP 서버가 시작되었습니다. 클라이언트 메시지를 기다리는 중...\n");

    for (;;) {
        // 문자열 수신
        len = recvfrom(s, buffer, sizeof(buffer) - 1, 0, (struct sockaddr*)&clntAddr, &clntAddrLen);
        if (len > 0) {
            buffer[len] = '\0';  // 수신한 문자열을 null로 종료

            // 특정 메시지 확인 후 출력
            if (strcmp(buffer, "2017124192 정찬우") == 0) {
                printf("특정 메시지 수신: %s\n", buffer);
            } else {
                printf("일반 메시지 수신: %s\n", buffer);
            }
        }

        // 메시지 에코 (클라이언트에게 전송)
        sendto(s, buffer, len, 0, (struct sockaddr*)&clntAddr, clntAddrLen);
    }

    // 소켓 종료
    close(s);

    return 0;
}

