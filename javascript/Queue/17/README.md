## 문제 (17.js)

[카드 뭉치](https://school.programmers.co.kr/learn/courses/30/lessons/159994)

권장 시간 복잡도: `O(N + M)`

## 풀이

1. Queue 생성
2. goal의 문자열을 순회
3. cards1 front와 일치하면 answer에 넣고 pop
4. cards2 front와 일치하면 answer에 넣고 pop
5. 다른경우 만들 수 없으므로 break
6. answer와 goal을 ' ' 로 join 하여 같으면 Yes 반환 다르면 No 반환

## Reference

- [MDN Array.prototype.join()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/join)
- [MDN Array.prototype.push()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/push)
