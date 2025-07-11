# 🔧 기술 참고 자료

## USB와 UART

- USB는 PC와 주변기기 간 연결에 범용적으로 활용되는 통신 표준으로, 수 Mbps ~ Gbps 속도로 통신

- UART는 MCU 등 간단한 장치 간 직렬 통신을 위한 프로토콜로, 일반적으로 TX, RX의 2선 시리얼 핀을 통해 통신 수행

    - 통신 속도는 일반적으로 수백 bps ~ 수 Mbps

- USB와 UART는 본질적으로 다른 통신 방식이지만 일반적으로 MCU 보드 내에는 USB to UART 변환 칩이 내장되어 있으며, PC에 연결시 USB로 연결되지만 내부적으로는 UART 통신을 흉내내는 방식으로 동작

    - 이때 PC OS는 이를 가상 COM 포트(Virtual COM Port, VCP)로 인식함

- 현재 사용할 Elecrwo DIS08070H의 경우에는 CH340C라는 USB to UART 변환용 칩을 통해 PC와 통신 수행


### 애초에 COM 포트라는게 뭐야?

- COM 포트(Communication Port)란 PC가 외부 장치와 직렬 통신하기 위해 논리적으로 부여하는 포트 번호를 의미

- 원래 COM 포트는 논리적 포트 번호가 아니라 실제 메인보드에 붙어있는 물리 직렬 포트를 구분하는 번호였음

- 여기에는 컴퓨터 통신의 역사적 배경에 대해 조금 알 필요가 있는데, 옛날에는 D-Sub 같은 9핀이나 RS-232 같은 25핀 직렬 포트 등 별의 별 요상망측한 포트들이 메인보드에 더덕더덕 붙어있었고, 이 포트들이 직렬(Serial) 통신을 위한 포트들이였음

- 온갖 기업들이 끼어들어서 자기들 표준이라면서 이것저것 붙여대니까(특히 Apple같은 넘들은 최근까지도 USB 대신 자기들 표준 사용함) 도저히 안되겠다 싶어서 하나의 표준 위원회를 정하여 전역적으로 사용 가능한 표준 직렬 통신 버스(Universal Serial Bus)를 개발함

- 그래도 COM 포트의 개념 자체는 사라지지 않고, 현재는 가상 COM 포트라는 논리적 개념으로 남아있음


## Python 가상 환경(Virtual Environment)

- 버전 별 하위 호환성이 크게 떨어지는 Python 프로젝트의 특성 상 프로젝트 별로 동일한 패키지나 Python을 사용하더라도 다른 버전을 사용한다면 시스템 전체에 설치 시 충돌이 발생할 가능성이 큼

- Python 가상 환경은 Python 언어 자체에 포함된 공식 기능으로, 시스템 전체에 영향을 주지 않고 프로젝트마다 독립적인 Python 실행 환경을 만들어주는 기술

    - 각 프로젝트가 서로 다른 Python 버전이나 패키지를 사용해도 충돌 없이 동작하도록 함

    - Python 3.3 이전에는 `virtualenv`라는 외부 패키지를 이용하여 따로 추가하는 기능이였으며, 이후 Python 커뮤니티에서 워낙 필수적인 기능이니 표준 라이브러리에 추가하자는 합의가 이루어져 현재는 `venv`라는 이름으로 표준 라이브러리에 추가됨

- ESP-IDF는 C 기반의 펌웨어를 빌드하는 프레임워크이나, 빌드, 플래싱, 모니터링 및 설정 등을 제어하는 주요 도구들은 Python 스크립트로 구현되어 있음

    - 기본적으로 Python 가상 환경에서 동작하도록 구현되었으며, ESP-IDF 설치 시, 기본적으로 Python 가상 환경이 생성된 후, 해당 가상 환경 내에서 동작함


## FreeRTOS

- FreeRTOS(Free Real-Time Operating System)는 임베디드 시스템을 위한 가벼운 실시간 운영체제로, MCU 안에서 여러 작업(Task)을 동시에 처리하고, 효율적인 시간 분할 제어를 제공함

- ESP32 내부에서도 FreeRTOS가 항상 기본으로 동작함

    - 멀티태스킹 관리: 여러 Task(함수 블록)를 동시에 실행 가능(논리적 병렬)

    - 스케줄링: 우선순위 기반으로 Task 실행 순서 자동 제어

    - 동기화 지원: 세마포어, 뮤텍스, 큐 등으로 Task 간 안전한 데이터 공유

    - 시간 제어: `vTaskDelay()`(CPU를 블로킹하지 않는 비동기 지연) 등을 지원

    - 기타 ISR, 메모리 관리 기능 제공 등

- 기본 구조 흐름

    1. 전원 ON

    2. 부트로더 실행

    3. FreeRTOS 커널 초기화

    4. `app_main()`을 기본 Task로 생성

    5. 개발자가 추가한 Task들 생성

    6. FreeRTOS가 모든 Task를 스케줄링하며 동작 유지


-  베어메탈 MCU 개발과의 차이

    - 베어메탈 MCU는 일반적으로 무한 루프를 통해 모든 동작을 처리하며, 인터럽트 처리 복잡도가 높고 멀티코어 활용이 불가능

    - FreeRTOS를 통해 개발하는 MCU는 여러 Task를 분리하여 구조적 개발이 가능하며, ISR을 정의하여 인터럽트를 처리하고, 멀티코어를 Task를 통해 효율적으로 활용할 수 있음


## 메모리 종류별 역할

- Flash: 프로그램(펌웨어) 저장 공간으로, OTA 시 새로운 펌웨어도 이 공간에 저장됨

- SRAM: MCU 내부 고속 메모리로, 스택, 전역 변수, 임시 데이터 등을 처리하는 데에 사용

- ROM: 부트로더, 하드웨어 초기화 코드 등 고정 프로그램 저장 장소로, 사용자가 변경 불가능

- PSRAM: 추가 확장 메모리로, GUI 버퍼, 이미지 데이터, LVGL 메모리 풀 등에 활용

- 현재 사용 중인 HMI의 Flash 4MB가 매우 넉넉한 것은 아니므로, 펌웨어의 크기를 관리하는 것이 중요함

    - Flash를 `app0`, `app1`의 듀얼 파티션 구조로 설계하여 OTA를 구현할 수 있음

    - 대용량 이미지나 리소스는 TF카드에 저장하고 Flash는 코드와 필수 리소스만 담아야할 것
