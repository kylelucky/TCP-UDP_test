// TCP 에코 서버 프로그램
#include "headerFiles.h"  // 필요한 헤더 파일 포함
#define SERVER_PORT 12345  // 서버 포트 번호 정의

int main(void) {
    int ls, s;                          // 리슨 소켓과 통신 소켓 디스크립터
    int len = 0;                        // 송신 및 수신할 바이트 수
    char buffer[256];                   // 데이터 버퍼
    struct sockaddr_in servAddr;        // 서버 소켓 주소
    struct sockaddr_in clntAddr;        // 클라이언트 소켓 주소
    int clntAddrLen = sizeof(clntAddr); // 클라이언트 주소 길이

    // 서버 소켓 주소 초기화
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(SERVER_PORT);
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    // 리슨 소켓 생성
    if ((ls = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error: Listen socket creation failed!");
        exit(1);
    }

    // 소켓 바인딩
    if (bind(ls, (struct sockaddr*)&servAddr, sizeof(servAddr)) < 0) {
        perror("Error: Binding failed!");
        close(ls);
        exit(1);
    }

    // 연결 대기 설정
    if (listen(ls, 16) < 0) {
        perror("Error: Listening failed!");
        close(ls);
        exit(1);
    }

    printf("TCP 서버가 시작되었습니다. 클라이언트의 연결을 기다리는 중...\n");

    for (;;) {
        // 클라이언트 연결 수락
        if ((s = accept(ls, (struct sockaddr*)&clntAddr, &clntAddrLen)) < 0) {
            perror("Error: Accepting connection failed!");
            continue;
        }

        // 클라이언트로부터 데이터 수신
        len = recv(s, buffer, sizeof(buffer) - 1, 0);
        if (len > 0) {
            buffer[len] = '\0';  // 수신한 문자열을 null로 종료

            // 특정 메시지 확인 후 출력
            if (strcmp(buffer, "2017124192 정찬우") == 0) {
                printf("특정 메시지 수신: %s\n", buffer);
            } else {
                printf("일반 메시지 수신: %s\n", buffer);
            }

            // 에코 메시지 송신
            send(s, buffer, len, 0);
        }

        // 소켓 종료
        close(s);
    }

    close(ls);
    return 0;
}

