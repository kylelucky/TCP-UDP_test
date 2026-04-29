📡 TCP / UDP 통신 실습 보고서
📌 프로젝트 개요

이 프로젝트는 네트워크 프로그래밍의 핵심 개념인 TCP (Transmission Control Protocol)와 UDP (User Datagram Protocol)의 동작 방식을 이해하고, 직접 소켓 프로그래밍을 통해 통신을 구현하는 것을 목표로 한다.

🎯 실습 목표
TCP와 UDP의 구조적 차이 이해
소켓(Socket) 기반 통신 방식 학습
Client-Server 모델 구현 경험
신뢰성 vs 속도 트레이드오프 분석
🧠 이론 정리
✅ TCP (Transmission Control Protocol)
연결 지향형 (Connection-oriented)
데이터 신뢰성 보장 (손실 시 재전송)
순서 보장
흐름 제어 및 혼잡 제어 지원

👉 사용 예: 웹(HTTP), 파일 전송(FTP)

✅ UDP (User Datagram Protocol)
비연결형 (Connectionless)
빠른 전송 (오버헤드 적음)
신뢰성 없음 (패킷 손실 가능)
순서 보장 없음

👉 사용 예: 스트리밍, 실시간 게임, VoIP

🧪 실습 내용
1️⃣ UDP 통신 구현
📌 특징
서버와 클라이언트 간 연결 과정 없음
데이터그램 단위로 전송
⚙️ 구현 방식
socket() 생성
sendto() / recvfrom() 사용
IP와 포트를 직접 지정
💡 핵심 포인트
빠르지만 데이터 손실 가능성 존재
단순 구조
2️⃣ TCP 통신 구현
📌 특징
연결 기반 통신
안정적인 데이터 전달
⚙️ 구현 방식

서버

socket() 생성
bind()
listen()
accept()

클라이언트

socket() 생성
connect()
💡 핵심 포인트
3-way handshake 기반 연결
데이터 순서 보장
⚙️ 실행 방법
📥 1. 저장소 클론
git clone https://github.com/your-repo/tcp-udp-practice.git
cd tcp-udp-practice
▶️ 2. UDP 실행
서버 실행
python udp_server.py
클라이언트 실행
python udp_client.py
▶️ 3. TCP 실행
서버 실행
python tcp_server.py
클라이언트 실행
python tcp_client.py
📊 결과 및 분석
항목	TCP	UDP
연결 방식	연결 지향	비연결
신뢰성	높음	낮음
속도	느림	빠름
순서 보장	O	X
🔍 실습 결과 요약
TCP는 안정적인 데이터 전송이 가능하지만, 연결 설정 과정으로 인해 지연 발생
UDP는 빠른 전송이 가능하지만, 데이터 손실 가능성 존재
실시간 서비스에서는 UDP가, 정확성이 중요한 서비스에서는 TCP가 적합
🚀 느낀 점 (중요 포인트)
단순히 프로토콜 개념을 아는 것과 실제 구현은 큰 차이가 있음
소켓 통신을 통해 네트워크 계층 구조에 대한 이해도가 향상됨
TCP/UDP 선택은 서비스 요구사항(신뢰성 vs 속도)에 따라 결정되어야 함
📁 프로젝트 구조
.
├── headerFiles.h
├── tcp_server.c
├── tcp_client.c
├── udp_server.c
├── udp_client.c
└── README.md
📌 추가 개선 방향
멀티 클라이언트 처리 (멀티스레드 / 비동기)
패킷 손실 시 재전송 로직 (UDP 보완)
GUI 기반 테스트 환경 구축
