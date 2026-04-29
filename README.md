📡 TCP / UDP 통신 실습 (C Socket Programming)

📌 프로젝트 개요

이 프로젝트는 C 언어 기반 Socket Programming을 활용하여
TCP와 UDP 통신을 직접 구현하고, 두 프로토콜의 차이를 실습을 통해 분석하는 것을 목표로 한다.

🎯 실습 목표

TCP / UDP 동작 방식 이해
BSD Socket API 사용법 학습
Client-Server 구조 구현
신뢰성 vs 성능 Trade-off 분석

🧠 이론 정리

✅ TCP (Transmission Control Protocol)
연결 지향 (Connection-oriented)
신뢰성 보장 (재전송)
순서 보장
3-way handshake 사용

👉 사용 예: HTTP, FTP

✅ UDP (User Datagram Protocol)

비연결형 (Connectionless)
빠른 전송
신뢰성 없음
순서 보장 없음

👉 사용 예: 실시간 스트리밍, 게임, VoIP

🧪 실습 내용

1️⃣ TCP 통신 구현

📌 서버 동작 과정
socket();
bind();
listen();
accept();
read()/write();

📌 클라이언트 동작 과정
socket();
connect();
read()/write();

💡 핵심
연결 기반 통신
안정적인 데이터 전달

2️⃣ UDP 통신 구현 (Echo)

📌 동작 과정
socket();
sendto();
recvfrom();

💡 핵심
연결 과정 없음
빠르지만 데이터 손실 가능

⚙️ 실행 방법

📥 1. 컴파일

gcc tcpServer.c -o tcpServer
gcc tcpClient.c -o tcpClient
gcc echoServer.c -o echoServer
gcc echoClient.c -o echoClient

▶️ 2. TCP 실행

서버 실행

./tcpServer

클라이언트 실행

./tcpClient

▶️ 3. UDP 실행

서버 실행

./echoServer

클라이언트 실행

./echoClient

📊 결과 분석

항목	TCP	UDP
연결 방식	연결 지향	비연결
신뢰성	높음	낮음
속도	느림	빠름
순서 보장	O	X

🚀 느낀 점

TCP는 안정적인 대신 오버헤드 존재
UDP는 빠르지만 신뢰성 부족
실제 서비스에서는 요구사항에 따라 선택 필요

📁 프로젝트 구조

TCP-UDP_test/

├── tcpServer.c

├── tcpClient.c

├── echoServer.c

├── echoClient.c

├── headerFiles.h

├── README.md

└── 과제.docx

🔧 개선 방향

멀티 클라이언트 처리 (fork / thread)
select / epoll 기반 확장
UDP 신뢰성 보완 (재전송 로직)
