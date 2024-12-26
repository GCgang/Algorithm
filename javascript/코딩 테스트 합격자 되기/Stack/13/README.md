## 문제 (13.js)

[크레인 인형 뽑기 게임](https://school.programmers.co.kr/learn/courses/30/lessons/64061)

권장 시간 복잡도: `O(M * N)`

## 풀이

1. moves 배열을 순회하며 어느열에서 인형을 찾을지 정하기
2. board를 순회하며 인형이 있는지 확인
3. 인형이 있다면 스택에 넣고 인형이 있던 board 자리는 0으로 초기화
4. 인형을 담은 통(스택)의 길이가 2개보다 크면 가장 위에 있는 두개를 비교해서 바구니에서 인형을 두개 빼고 결과값을 2 증가시킴
5. moves 만큼 반복 후 결과 값 반환

## Reference

- [MDN Array.prototype.push()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/push)
- [MDN Array.prototype.pop()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/pop)


## 문제 (13-1.js)

[크레인 인형 뽑기 게임](https://school.programmers.co.kr/learn/courses/30/lessons/64061)

권장 시간 복잡도: `O(N^2 + M)`

## 풀이

1. 각 열에 대한 스택 생성
2. board를 역순으로 탐색하며, 각 열의 인형을 lanes에 추가
3. moves를 순회하며, 각 열에서 인형을 뽑아 bucket에 추가
4. 해당 열에 인형이 있는 경우 lanes에서 인형을 뺌
5. 바구니에 인형이 있고, 가장 위에 있는 인형과 같은 경우 바구니에 있는 인형을 빼고 결과값을 2 증가 시킴
6. 바구니에 인형이 없거나, 가장 위에 있는 인형과 다른 경우 바구니에 인형을 넣음

## Reference

- [MDN for...of](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/for...of)
- [MDN Array.prototype.push()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/push)
- [MDN Array.prototype.pop()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/pop)
-[Array.prototype.map()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/map)