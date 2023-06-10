# 시스템 프로그래밍 기말 프로젝트
### 2019775022 박상원
<hr>

* rev 명령어 / 해당 ^c 전까지 입력 받은 문자열을 뒤집어서 출력하는 명령어 -h(명령어 사용 메뉴얼) 옵션 구현 (2개)

![image](https://github.com/wonindev/SYSP/assets/100292629/1c46a566-b0cc-4e0d-b55e-d813c7959a02)

<hr>

* yes 명령어 / yes 만 올 경우 y를 ^c 전까지 무한으로 출력, yes 뒤에 다른 문자열이 올 경우 해당 문자열을 ^c 전까지 무한으로 출력, -h 옵션(명령어 사용 메뉴얼) 구현(2개)

![image](https://github.com/wonindev/SYSP/assets/100292629/fd94a1d7-624e-43cc-9c00-50fb0ae098b8)
![image](https://github.com/wonindev/SYSP/assets/100292629/5d3b2e16-73b2-494d-97d5-cf990af5d6fb)
![image](https://github.com/wonindev/SYSP/assets/100292629/77d3ed2f-4a7f-4588-8b0f-23b790b22cce)

<hr>

* pwd 명령어 / 현재 작업 중인 디렉토리 경로 표시(1개)
![image](https://github.com/wonindev/SYSP/assets/100292629/d6aa5a6e-c679-4aac-9e64-43da91abb181)

<hr>

* mkdir 명령어 / 디렉토리를 생성하는 명령어, -m(폴더에 권한 부여 옵션) 디폴트는 777 구현(2개)

![image](https://github.com/wonindev/SYSP/assets/100292629/296eac70-730a-43cd-8d98-8e174c1c892d)


* ls- al을 통해 권한이 다른 것을 확인
![image](https://github.com/wonindev/SYSP/assets/100292629/c5d6f4aa-9124-4de2-a02c-8c97e2ed5e93)

<hr>
* rmdir 명령어 / 디렉토리를 삭제하는 명령어 만약 폴더 안에 파일이 들어있다면 삭제 불가(1개)

![image](https://github.com/wonindev/SYSP/assets/100292629/e498dd11-0d5a-4e20-9dda-ca1742ecf3a0)

<hr>

* clear 명령어 / 터미널의 모든 내용을 삭제하는 명령어(1개)

![image](https://github.com/wonindev/SYSP/assets/100292629/1fbc5fa5-d79b-41f2-bf54-8d1072c0f4ba)
![image](https://github.com/wonindev/SYSP/assets/100292629/9d0d5dd8-e044-413c-be87-7c5346d47686)

<hr>

* echo 명령어 / echo 명령어는 주어진 인자나 텍스트를 출력하는 데 사용하는 명령어로 이스케이프 문자가 있을 경우 "" 로 인자를 전달한다. -n(마지막 개행을 출력하지 않는다) -e(이스케이프 문자를 이스케이프 문자로 인식)
 -E(이스케이프 문자를 ""로 묶어서 인식) -h (명령어 사용 메뉴얼) (5개)
 


![image](https://github.com/wonindev/SYSP/assets/100292629/5fa459cd-4435-4e17-b1a0-1795c4406611)

-n 옵션

![image](https://github.com/wonindev/SYSP/assets/100292629/1515215e-20d2-4c79-aa00-d709c354c096)

-e 옵션

<br>

![image](https://github.com/wonindev/SYSP/assets/100292629/cf6308d1-3627-49ef-9208-0d32c0f09fa9)

-E 옵션

![image](https://github.com/wonindev/SYSP/assets/100292629/ebdeb157-c97f-4d43-880f-a8e4e3dd2f84)

-h 옵션

![image](https://github.com/wonindev/SYSP/assets/100292629/313014a7-9173-4f96-9a36-8238692645de)


<hr>

* uname 명령어 / 사용자의 시스템 정보를 출력하는 데 사용되는 명령어 -a(모든 정보 출력) -s(커널 이름 출력) -n(호스트 이름 출력) -r(커널 릴리스 정보 출력) -v(커널 버전 출력) -m(하드웨어 출력) -h(명령어 사용 메뉴얼) (8)

uname

![image](https://github.com/wonindev/SYSP/assets/100292629/4521647a-86c4-408e-907c-0f3af15bb6fa)

-a

![image](https://github.com/wonindev/SYSP/assets/100292629/4102c38a-792f-4a2d-af67-ac20cd7444f9)

-s

![image](https://github.com/wonindev/SYSP/assets/100292629/2002be91-a578-46e7-b4d2-21a88c51e086)

-n

![image](https://github.com/wonindev/SYSP/assets/100292629/12188408-ddf5-4064-ab1e-fcfefa55d991)

-r

![image](https://github.com/wonindev/SYSP/assets/100292629/bb64db87-d922-499a-a353-ebcf1f9ce0a2)

-v

![image](https://github.com/wonindev/SYSP/assets/100292629/70f99771-1ff3-47ac-9ec6-fd92784f75e6)

-m

![image](https://github.com/wonindev/SYSP/assets/100292629/2dad5542-c5a5-446c-9f0c-3ba249c5865d)

-h

![image](https://github.com/wonindev/SYSP/assets/100292629/ddff5813-b25f-4080-bc7e-bf5236b45ed5)

<hr>

* head 명령어 / 주어진 파일의 앞 부분을 출력하는 데 사용되는 명령어로 디폴트는 앞 10개를 출력한다  -n(입력한 정수 라인만큼 출력) -c(입력한 정수 바이트만큼 출력) -h(명령어 사용 메뉴얼) (4개)

Default

<br>

![image](https://github.com/wonindev/SYSP/assets/100292629/b6c44cdc-5c97-490c-8af0-b3b261c38371)

-n

![image](https://github.com/wonindev/SYSP/assets/100292629/edea0839-21f5-4d28-ae07-dfbfa513cf84)

-c

![image](https://github.com/wonindev/SYSP/assets/100292629/9f00f066-9af5-4b2e-91af-7f4685fbdfac)

-h

![image](https://github.com/wonindev/SYSP/assets/100292629/7a5f153c-0a37-4d35-a051-26e108d809f1)

<hr>

* tail 명령어 / 주어진 파일의 뒤 부분을 출력하는 데 사용되는 명령어로 디폴트는 뒤에 라인 10개를 출력한다  -n(입력한 정수 라인만큼 출력) -c(입력한 정수 바이트만큼 출력) -q(파일 이름을 출력하지 않는다) -v(파일 이름을 출력한다) -h(명령어 사용 메뉴얼) (4개)


Default

![image](https://github.com/wonindev/SYSP/assets/100292629/845fc676-f6b6-400a-9e56-7ce91c301406)


-n

![image](https://github.com/wonindev/SYSP/assets/100292629/45ce42c2-e791-467d-a161-35d3d53f815d)

-c

![image](https://github.com/wonindev/SYSP/assets/100292629/2a22e1bd-9bf4-4ec5-ad16-438fdf1f8fa3)

-q

![image](https://github.com/wonindev/SYSP/assets/100292629/9b60bd16-1c60-4006-ab05-19b0e35c8750)

-v

![image](https://github.com/wonindev/SYSP/assets/100292629/4400898d-13bc-4cab-a15f-a3d9f5d4cc79)

-h 

![image](https://github.com/wonindev/SYSP/assets/100292629/31042449-5e5d-46da-97f2-faed40d826a0)






























