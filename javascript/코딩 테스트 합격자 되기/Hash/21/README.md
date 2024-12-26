## 문제 (21.js)

- [할인 행사](https://school.programmers.co.kr/learn/courses/30/lessons/131127)
  권장 시간 복잡도: `O(N)`

## 풀이

1. 전체 할인 제품을 순회하며 10일치 할인 제품을 추출한다
2. 원하는 품목과 수량을 저장할 Map을 선언한다
3. 10일치 할인 제품을 순회하며 원하는 품목과 수량이 일치하는지 확인한다.
4. 원하는 품목의 수량이 모두 0인지 확인한다
5. 맞다면 count를 증가시킨다

## Reference

- [for...of](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Statements/for...of)
- [Object.values()](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Object/values)
- [Map](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Map)
- [Array.prototype.slice()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/slice)
