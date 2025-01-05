## 문제 (29.js)

- [다단계 칫솔 판매](https://school.programmers.co.kr/learn/courses/30/lessons/77486)
  권장 시간 복잡도: `O(N*M)`

## 풀이

1. 판매자의 추천자(상위 노드)를 찾는다.
2. 판매자가 판매한 총 금액을 구한다.
3. 판매자의 추천자(상위 노드)로 이동하며 이익을 분배 한다.
4. 배열의 모든 노드에 대해 해당하는 이익을 배열로 반환한다.

## Reference

- [MDN Math.floor()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Math/floor)
- [MDN Array.prototype.map()](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Array/map)
