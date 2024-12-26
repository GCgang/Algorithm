## 문제 (18.js)

두 개의 수로 특정 값 만들기

- n 개의 양의 정수로 이루어진 리스트 arr와 정수 target이 주어졌을 때,
  이 중에서 합이 target인 두 수가 arr에 있는지 찾고,
  있으면 true, 없으면 false를 반환하는 solution() 함수 작성하기

제약 조건

- n은 2 이상 10,000 이하의 자연수
- arr의 각 원소는 1 이상 10,000 이하의 자연수
- arr의 원소 중 중복되는 원소는 없다
- target은 1 이상 20,000 이하의 자연수

권장 시간 복잡도: `O(N+K)`

## 풀이

1. arr의 정수를 담을 `Set` 생성
2. target에서 arr의 정수를 뺀 값이 numSet에 있는지 확인
3. 있다면 target을 만들기 위한 수가 numSet에 있다는 것이므로 true 반환
4. 순회가 끝날동안 return되지 않으면 false 반환

## Reference

- [MDN Set](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Set)
- [MDN add](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Set/add)
- [MDN has](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Set/has)
