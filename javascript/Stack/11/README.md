## 문제 (11.js)

[짝지어 제거하기](https://school.programmers.co.kr/learn/courses/30/lessons/12973)

권장 시간 복잡도: `O(N)`

## 풀이

1. 문자열을 순회하며 현재 문자와 스택의 맨위 문자가 같은지 같지 않은지 확인
2. 같으면 pop
3. 같지 않으면 스택에 문자 push
4. 스택이 비어 있으면 짝지어 제거 성공(1) 그렇지 않으면 0 반환

## Reference

- [MDN for...of](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/for...of)
- [MDN Array.prototype.push()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/push)
- [MDN Array.prototype.pop()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/pop)
