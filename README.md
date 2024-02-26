# miniRT
MiniRT - Raytracing engine written in C

### Mandatory 구현 사진
<img width="1919" alt="image" src="https://github.com/seongmik-s-team/miniRT/assets/44383895/1a89d2a0-3dd4-4a7b-9af4-c7c70fb269bc">


## Coding Convention
- commit message 형식 : ex. [MERGE] temp commit
- issue 제목 형식 : ex. [BUG] leaks 발생 문제
- pull request 제목 형식 : ex. [BUGFIX] leaks 문제 해결
- 함수가 복잡하면 주석 달기
- 수식 관련은 무조건 주석

## Mandatory

- External functions
  - open, close, read, write, printf, malloc, free, perror, strerror, exit
  -  math library (-lm man man 3 math)

- 반드시 miniLibX를 사용해야 합니다. 운영 체제에서 사용 가능한 버전이나 소스에서 사용할 수 있습니다. 소스를 사용하는 경우 libft와 동일한 규칙을 적용해야 합니다.
- 창 관리는 반드시 부드러워야 합니다: 다른 창으로 전환, 최소화 등.
- 창의 해상도를 변경할 때 창의 내용은 변경되지 않고 적절하게 조정되어야 합니다.
- 최소한 이러한 3가지 간단한 기하 객체가 필요합니다: 평면, 구, 원기둥.
- 해당하는 경우 모든 가능한 교차점과 객체 내부를 올바르게 처리해야 합니다.
- 프로그램은 객체의 고유 속성을 조정할 수 있어야 합니다: 구의 지름 및 원기둥의 너비와 높이.
- 프로그램은 객체, 라이트 및 카메라에 이동 및 회전 변환을 적용할 수 있어야 합니다 (구와 회전할 수 없는 라이트는 제외).
- 라이트 관리: 스폿 밝기, 경직된 그림자, 분위기 조명 (객체가 완전히 어두워지지 않음). 앰비언트 및 디퓨즈 조명을 구현해야 합니다.
- 프로그램은 이미지를 창에 표시하고 다음 규칙을 준수해야 합니다:
  - ESC 키를 누르면 창을 닫고 프로그램이 깨끗하게 종료되어야 합니다.
  - 창 프레임의 빨간 십자가를 클릭하면 창을 닫고 프로그램이 깨끗하게 종료되어야 합니다.
  - miniLibX 이미지의 사용이 강력히 권장됩니다.
- 프로그램은 .rt 확장자를 가진 장면 설명 파일을 첫 번째 인수로 사용해야 합니다.
  - 각 요소 유형은 하나 이상의 줄 바꿈으로 분리할 수 있습니다.
  - 요소의 각 유형 정보는 하나 이상의 공백으로 분리할 수 있습니다.
  - 파일에서 요소의 각 유형은 임의의 순서로 설정할 수 있습니다.
  - 대문자로 정의된 요소는 장면에서 한 번만 선언할 수 있습니다.

- 각 요소의 첫 번째 정보는 유형 식별자입니다 (한 개 또는 두 개의 문자로 구성됨), 그 뒤로 각 객체에 대한 모든 구체적인 정보가 엄격한 순서로 나열됩니다. 예를 들어:

  - 앰비언트 조명:
A 0.2 255,255,255
  	- 식별자: A
  	- 앰비언트 조명 비율 [0.0,1.0] 범위: 0.2
  	- R,G,B 색상 [0-255] 범위: 255, 255, 255

  - 카메라:
C -50.0,0,20 0,0,1 70
  	- 식별자: C
  	- 시점의 x,y,z 좌표: -50.0,0,20
  	- 3차원 정규화 방향 벡터. 각 x,y,z 축에 대해 [-1,1] 범위: 0.0,0.0,1.0
  	- FOV: 수평 시야각 (도) [0,180] 범위: 70

  - 라이트:
L -40.0,50.0,0.0 0.6 10,0,255
  	- 식별자: L
  	- 광원의 x,y,z 좌표: -40.0,50.0,0.0
  	- 광원 밝기 비율 [0.0,1.0] 범위: 0.6
  	- (필수 부분에서 사용되지 않음) R,G,B 색상 [0-255] 범위: 10, 0, 255

  - 구:
sp 0.0,0.0,20.6 12.6 10,0,255
  	- 식별자: sp
  	- 구의 중심의 x,y,z 좌표: 0.0,0.0,20.6
  	- 구의 지름: 12.6
  	- R,G,B 색상 [0-255] 범위: 10, 0, 255

  - 평면:
pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225
  	- 식별자: pl
  	- 평면 상의 한 점의 x,y,z 좌표: 0.0,0.0,-10.0
  	- 3차원 정규화 법선 벡터. 각 x,y,z 축에 대해 [-1,1] 범위: 0.0,1.0,0.0
  	- R,G,B 색상 [0-255] 범위: 0,0,225

  - 원기둥:
cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
  	- 식별자: cy
  	- 원기둥 중심의 x,y,z 좌표: 50.0,0.0,20.6
  	- 원기둥의 축의 3차원 정규화 벡터. 각 x,y,z 축에 대해 [-1,1] 범위: 0.0,0.0,1.0
  	- 원기둥의 지름: 14.2
  	- 원기둥의 높이: 21.42
  	- R,G,B 색상 [0,255] 범위: 10, 0, 255
