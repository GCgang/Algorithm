## 문제 (07.js)

[방문 길이](https://school.programmers.co.kr/learn/courses/30/lessons/49994)

권장 시간 복잡도: `O(N)`

## 풀이
1. 주어진 명령어로 움직이며 좌표평면을 벗어나는지 확인
2. 벗어나지 않는다면 A에서 B로 간 경우 B에서 A로 간 경우를 추가(총 겨로의 개수는 방향서이 없음)
3. 좌표를 이동했으므로 업데이트
4. 겹치는 좌표는 처리하지 않기 위해 Set으로 저장 했으므로 방문한 방향이 들어있는 Set의 size / 2를 하여 방문 길이를 반환

- [MDN Set](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Set)
- [MDN for...of](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/for...of)
- [MDN switch](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/switch)
