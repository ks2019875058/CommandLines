Date
기본옵션시 모두 출력
-y 연도출력
-m 달 출력
-h 시간출력


Pwd 현재 작업중인 디렉토리 구현

Echo명령어 구현

Cat 명령어 구현
기본옵션시 파일을 읽어옴
Cat -n 줄바꿈 입력시 번호를 추가해서 줄의 개수을 알 수 있게함
Cat -c 문자의 총 개수를 알 수 있게함
Cat -f 특정문자 옵션 적용시 어떤 문자가 몇번 나왔는지 알려준다.

Mv 기본옵션 적용시 바꾸는 걸 물어보지않고 파일이름이 바뀜
./mv -o 옵션적용시 바꾸는 걸 확인하는 알림이 뜨게 구현

Ls 기본옵션 파일명만 뜨게 구현
Ls -a 숨겨진파일도 보여주게 구현
Ls -i inode 값도 보여준다.

Mkdir 파일명
파일명에 해당하는 디렉토리를 새로 만드는 것을 구현

Rm 파일 삭제를 구현
Rm -o 옵션으로 삭제를 하는지 물어보고
Y나 Y가 입력되면 삭제하고 나머지가 입력되면 삭제를 안하게 구현

Cmp
파일내용을 캐릭터로 하나씩불러와서 비교함
같을 시 동일하다고 출력
다를 시 다르다고 출력

"rmdir"
디렉토리 삭제를 구현삭제 성공시 알림


Diff 구현
다르면 몇번째줄이 어떻게 다른지 출력

Clear 구현

Find 구현
같은 이름의 파일명이 있을 시 찾았다고 알려준다.

Ln 구현
./ln 기본옵션 실행시 inode값이 같은 하드링크생성

Ln-s 옵션적용시
소프트링크가 생성

Head 명령어 구현
기본옵션 적용시 파일의 위에서부터 10줄만 읽어온다
./head -o 숫자
위에서부터 숫자까지의 줄을 읽어온다.

Tail 명령어 구현
기본옵션시 파일을 읽어와서 뒤에서 10줄출력
./tail -o 숫자
뒤에서부터 숫자에 해당되는 줄까지 출력

Chmod 구현

cp 구현

![image](https://github.com/ks2019875058/CommandLines/assets/48702199/c54619eb-5b97-435a-af9a-e2d519490b79)
