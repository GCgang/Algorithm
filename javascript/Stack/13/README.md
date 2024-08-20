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
