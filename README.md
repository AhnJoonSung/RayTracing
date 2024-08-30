# MiniRT

 MiniRT는 C언어로 작성한 Ray Tracing 3D 렌더링 프로그램입니다. 

벡터 및 행렬 연산을 구현하여 3D 공간의 기하학적 계산을 처리하며, 

평면, 원, 구, 원기둥과 같은 다양한 3D 오브젝트를 렌더링할 수 있습니다. 

Phong 모델과 Lambert 모델을 기반으로 
Specular 반사, Ambient 조명, 난반사, 그림자와 같은 조명 효과를 지원합니다. 

또한 카메라의 이동 및 회전, fov 조절 기능을 통해 다양한 시점에서 장면을 바라볼 수 있습니다. 

사용자는 텍스트 기반의 구성 파일을 통해 장면을 구성할 수 있습니다.

---

## 실행결과 예시 이미지
<img width="1919" alt="image" src="https://github.com/seongmik-s-team/miniRT/assets/44383895/1a89d2a0-3dd4-4a7b-9af4-c7c70fb269bc">

<img width="1522" alt="image" src="https://github.com/user-attachments/assets/9f3f82b8-addb-49f5-9384-c63647ea1c94">


---

## 실행 방법

1. **레포지토리 클론**

   먼저, MiniRT 레포지토리를 로컬 머신에 클론합니다:

   ```bash
   git clone <repository_url>
   ```

   `<repository_url>`은 실제 레포지토리 URL로 대체합니다.

2. **프로그램 빌드**

   클론한 디렉토리로 이동한 후, `make` 명령어를 사용하여 프로그램을 빌드합니다:

   ```bash
   cd <repository_directory>
   make
   ```

   `<repository_directory>`는 클론한 레포지토리 디렉토리 이름으로 대체합니다.

3. **프로그램 실행**

   빌드가 완료된 후, 다음 명령어로 MiniRT를 실행할 수 있습니다:

   ```bash
   ./miniRT *.rt
   ```

   `*.rt`는 장면 구성 파일 경로로 대체합니다.

---

## 구성 파일
구성 파일은 다음과 같은 규칙으로 작성하여야 합니다. 
- 각 요소 유형은 하나 이상의 줄 바꿈으로 분리할 수 있습니다.
- 요소의 각 유형 정보는 하나 이상의 공백으로 분리할 수 있습니다.
- 파일에서 요소의 각 유형은 임의의 순서로 설정할 수 있습니다.

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

### 예시 구성 파일
```
A 0.2 255,255,255
C 0,0,0 0,0,1 100
L 0,20,0 1.0 25,55,95
cy 0,0,-10 0,1,0 20 25 10,255,255
```
