## 문제 (09.js)

10진수를 2진수로 변환하기

- 10진수를 입력받아 2진수로 변환해 반환하는 solution()함수를 구현하세요

제약 조건

- decimal은 1 이상 10억 미만의 자연수

권장 시간 복잡도: `O(logN)`

## 풀이

1. 10진수를 2로 나눈 나머지를 stack에 push
2. 몫이 0이 아니라면 나머지를 버리고 1번 수행
3. 모든 과정이 끝나고 stack에 저장한 수를 뒤부터 순서대로 붙여서 반환

## Reference

- [MDN Array.prototype.push()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/push)
- [MDN Array.prototype.pop()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/pop)
- [MDN Math.floor()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Math/floor)
- [Array.prototype.join()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/join)
